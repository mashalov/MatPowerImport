#include "PlainLogger.h"
#include "Exceptions.h"
#include <iostream>

CPlainLoggerStage::CPlainLoggerStage(CPlainLogger& PlainLogger, 
									 long StageId,
									 std::string_view StageName,
									 bool Hidden) : 
									 PlainLogger_(PlainLogger), 
									 StageId_(StageId),
									 StageName_(StageName),
									 Hidden_(Hidden)
{ 
}

CAutoLogStage::~CAutoLogStage()
{
	Close();
}

void CPlainLoggerStage::Close(LogMessageTypes ForcedStatus)
{
	if(StageId_ != 0)
		PlainLogger_.CloseStage(StageId_, ForcedStatus);
	StageId_ = 0;
}

CPlainRastrEventSource::~CPlainRastrEventSource()
{
	DebugLogCloseFile();
}

void CPlainLogger::ShowHiddenStages()
{
	if (!Enabled())
		return;

	// ищем последнюю нескрытую стадию
	auto HiddenEndIt{ StageStack_.end() };

	for (auto it = StageStack_.rbegin(); it != StageStack_.rend(); it++)
		if (it->Hidden())
		{
			it->Unhide();
			HiddenEndIt = std::next(it).base();
		}
		else
			break;

	// открываем все стадии начиная с первой скрытой
	for (auto it = HiddenEndIt; it != StageStack_.end(); it++)
		EventSource_->Log(LogMessageTypes::OpenStage, it->Name(), it->Id());
}

void CPlainRastrEventSource::Log(LogMessageTypes status,
	std::string_view Message,
	long StageId,
	std::string_view Table,
	std::string_view Column,
	std::string_view UIform,
	long Index)
{
	SetConsoleOutputCP(CP_UTF8);
	std::cout << stringutils::acp_decode(Message) << std::endl;
	if (DebugLogActive() && LogMessageTypes::CloseStage != status)
		DebugLog(Message);
}

void CPlainRastrEventSource::DebugLog(std::string_view Message)
{
	if (DebugLogActive())
		LogFile_ << fmt::format("{:%Y.%m.%d:%H:%M:%S}", fmt::localtime(std::time(nullptr))) << " " << Message << std::endl;
}

void CPlainRastrEventSource::DebugLogCloseFile()
{
	if (DebugLogActive())
	{
		DebugLog("Closing file");
		LogFile_.close();
		LogFilePath_.clear();
	}
}

void CPlainRastrEventSource::DebugLogToFile(const std::filesystem::path& Path,
	std::string_view Prefix,
	std::string_view Extension)
{
	// включаем исключения
	LogFile_.exceptions(LogFile_.exceptions() | std::ios::failbit);

	std::filesystem::path ResultPath{ Path };
	if (!Path.has_filename())
	{
		// в пути нет имени, генерируем новое из префикса
		if (!std::filesystem::exists(Path))
			throw CException("Не найден путь {} для вывода протокола", Path.string());

		// формируем имя файла по времени создания
		const std::string newFileName{ fmt::format("{}_{:%Y-%m-%d_%H-%M-%S}", Prefix, fmt::localtime(std::time(nullptr))) };
		size_t counter(1);
		ResultPath = Path;
		ResultPath.append(newFileName).replace_extension(Extension);

		// проверяем есть ли файл с таким именем в каталоге
		while (std::filesystem::exists(ResultPath))
		{
			// если есть - добавляем к имени счетчик
			ResultPath = Path;
			std::string countedFileName = fmt::format("{}_{}", newFileName, counter++);
			ResultPath.append(countedFileName).replace_extension(Extension);
		}
	}
	
	try
	{
		DebugLogCloseFile();
		LogFile_.open(ResultPath);
#ifdef _MSC_VER
		OSVERSIONINFO osvi;
		ZeroMemory(&osvi, sizeof(OSVERSIONINFO));
		osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
		//GetVersionEx(&osvi);
		MEMORYSTATUSEX status;
		status.dwLength = sizeof(status);
		GlobalMemoryStatusEx(&status);

		std::string ComputerName;
		DWORD dwBufferSize{ 0 };
		if (!GetComputerNameEx(ComputerNameDnsFullyQualified, NULL, &dwBufferSize) && GetLastError() == ERROR_MORE_DATA)
		{
			ComputerName.resize(dwBufferSize + 1);
			if (!GetComputerNameExA(ComputerNameDnsFullyQualified, &ComputerName[0], &dwBufferSize))
				ComputerName = "Unknown !";
			else
				ComputerName = ComputerName.substr(0, dwBufferSize);
		}

		DebugLog(fmt::format("Log started on Windows {}.{}.{}, physical memory {} GB, server name \"{}\"", 
			osvi.dwMajorVersion, 
			osvi.dwMinorVersion, 
			osvi.dwBuildNumber,
			std::round(static_cast<double>(status.ullTotalPhys) / 1073741824.0),
			ComputerName));

		LogFilePath_ = ResultPath;
#endif
	}
	catch (const std::ios_base::failure& ex)
	{
		throw CException("Не удалось открыть файл протокола \"{}\" : Ошибка ofstream: \"{}\"", Path.string(), ex.what());
	}
}