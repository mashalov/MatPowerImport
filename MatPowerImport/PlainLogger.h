#pragma once
#include <list>
#include <algorithm>
#include <atomic>
#include <fstream>
#include <filesystem>
#include "SafeQueue.hpp"
#include "fmt/core.h"
#include "fmt/format.h"
#include "fmt/chrono.h"
#include "stringutils.h"

//! Типы сообщений протокола
/*!
  Все перечисления должны быть продублированы для
  COM и gRPC
*/
enum class LogMessageTypes
{
	SystemError,
	Failed,
	Error,
	Warning,
	Message,
	Info,
	OpenStage,
	CloseStage,
	EnterDefault,
	Reset,
	None,
};

// Хинты изменений
enum class EventHints
{
	None = -1,		// Кажется Леша использует какой-то отрицательный хинт
	ChangeAll = 0,
	ChangeColumn = 1,
	ChangeRow = 2,
	ChangeData = 3,
	AddRow = 4,
	DeleteRow = 5,
	InsertRow = 6,
	ChangeTable = 7,
	BeforeRowDelete = 8,
	DeleteTable = 9,
	ChangeColor = 10,
	AddTable = 11,
};

enum class CommandHints
{
	OpenTable = 0,
	OpenFile = 1,
	SaveFile = 2,
	CommandPath = 3,
	LoadForm = 4,
	Name = 5,
	FileName = 6,
	Date = 7,
	Input = 8,
	SetForm = 9,
	SetProp = 10,
	CSVImport = 11,
	CSCExport = 12,
	OpenFolder = 13,
	FormTable = 14,
	SaveFormProps = 15,
	RefreshDifferences = 17,
	OpenTable2 = 18,
	OpenChart = 19,
	OpenSubst = 20,
	ClearLog = 21,
	TableByFormName = 22,
	OpenGraphics = 23,
	Progress = 24,
	ContextTable = 25,
	LoadFile = 26,
	OpenNotifications = 27,
	ChangeSubstServerStatus = 28,
	OpenChartPtr = 29,
	OpenShuntDialog = 30,
	OpenFOSDialog = 31,
	OpenModel = 32,
	OpenCIMGrid = 33
};

// Типы событий
enum class EventTypes
{
	Log,		// протокол
	Print,		// вывод скрипта
	Hint,		// хинт изменения
	Command		// хинт команды UI
};

//! Базовый класс источника событий
/*!
  Класс используется для передачи во внешний интерфейс
  команд и запросов. Класс по сути абстрактный, так как 
  базовая реализация ничего не делает. В наследованном
  классе нужно перекрыть функции для согласования с требуемым
  интерфейсом. В качестве примеров можно посмотреть классы
  CPlainRastrEventSourcegRPC и CPlainRastrOriginalEventSource.
*/
class CPlainRastrEventSource
{
	std::ofstream LogFile_;
	std::filesystem::path LogFilePath_;
public:
	virtual ~CPlainRastrEventSource();
	//! Вывод в протокол
	/*!
		Вывод в протокол строки Message со статусом status.
		Для перехода в UI можно указать Table, Column, UIform (имя формы)
		и Index БД. StageId не используется, и, возможно, его уберут.
		Параметры Table и UIform описывают таблицу или форму, в которых
		можно увидеть данные, описанные в Message. Приоритет не предусмотрен
		и зависит от реализации.

		\param status  Типы сообщений в протоколе
		\param Message  Строка, которая должна быть выведена в протокол
		\param StageId  Идентификатор стадии протокола (не используется), но пока
		оставлен для совместимости
		\param Table Системное имя таблицы БД, к которой имеет отношение Message
		\param Column Системное имя поля в таблице Table
		\param UIform Имя формы отображения, к которой имеет отношение Message
		\param Index Индекс в БД

		Функция также дублирует вывод в DebugLog(), если он доступен : DebugLogActive().
		Чтобы это работало - при наследовании CPlainRastrEventSource вызывайте базовый класс.

	*/
	virtual void Log(LogMessageTypes status,
					 std::string_view Message,
					 long StageId,
					 std::string_view Table = {},
					 std::string_view Column = {},
					 std::string_view UIform = {},
					 long Index = 0);												
	
	//! Вывод строки в консоль
	/*! Предполагается что протокол и консоль это разные назначения,
		поэтому для консоли есть отдельная функция.
		\param Message Строка для вывода в консоль
	*/ 
	virtual void Print(std::string_view Message) {};								

	//! Генерация события
	/*! Генерация события об изменении БД. Аналог FChangeData.
		\param Hint Тип изменения
		\param Table Таблица БД к которой относятся изменения
		\param Column Поле БД к которому относятся изменения
		\param Index Индекс в БД
	*/
	virtual void Event(EventHints Hint, std::string_view Table, std::string_view Column, long Index) {};

	//! Останов сервиса
	virtual void Stop(bool stop = true) {};											

	//! Проверка запроса останова сервиса
	virtual bool HasToStop() const { return false; }								

	//! Команда останова длительного процесса
	virtual void StopProcessing(bool StopProcessing = true) {}						

	//! Проверка запроса останова длительного процесса
	virtual bool HasToStopProcessing() const { return false; }						

	//! Вывод в отладочный протокол
	/*! По умолчанию отладочный протокол неактивен. Для того чтобы
		им вопользоваться необходимо задать путь к файлу протокола
		функцией DebugLogToFile(). Если отладочный протокол активен,
		(файл открыт, DebugLogActive() возвращает true) 
		строка Message будет выдана в этот файл.
		Строка не будет выдана в протокол, но сообщения протокол будут
		выводиться в отладочный протокол.
		\param Message Строка для записи в отладочный протокол
	*/
	virtual void DebugLog(std::string_view Message);								

	//! Задать путь к отладочному протоколу
	/*! Открывает файл отладочного протокола для вывода 
		с помощью DebugLog(). Если файл открыт, 
		DebugLogFilePath() возвращает путь к нему, а
		DebugLogActive() возвращает true.
		\param Path путь к файлу или каталогу. Если в Path
		есть имя файла, будет предпринята попытка его открыть
		на запись. Все данные в существующем файле будут стерты.
		Если в Path нет имени файла, то будет предпринята попытка
		создать файл с именем, состоящим из Prefix и времени 
		создания файла. В качестве расширения будет использован
		Extension.
		\param Prefix Префикс для имени файла, если в Path задан путь
		к каталогу. Имя файла генерируется по следующему паттерну:
		\code {Prefix}_{:%Y-%m-%d_%H-%M-%S}_{C} \endcode
		то есть имя конкатенируется из префикса, даты/времени и 
		счетчика {C}, если при создании файла окажется, что файл
		с таким именем уже существует. Счетчик увеличивается до тех
		пор, пока есть файлы с совпадающим именем.
		\param Extension Расширение файла отладочного протокола,
		если в Path задан путь к каталогу и требуется сгенерировать
		имя файла.
	*/
	void DebugLogToFile(const std::filesystem::path& Path, 
		std::string_view Prefix = {},
		std::string_view Extension = ".log");

	//! Закрыть отладочный протокол
	/*! Закрывает файл отладочного протокола. После выполнения
		этой функции ведение отладочного протокола прекращается
		до следующего открытия файла функцией DebugLogToFile().
		Если отладочный протокол закрыт, DebugLog() не имеет эффекта.
	*/
	void DebugLogCloseFile();														

	//! Проверить открыт ли отладочный протокол
	/*!
		Возвращает статус активности отладочного протокола.
		\return true если файл отладочного протокола открыт, 
				false в противном случае
	*/
	bool DebugLogActive() const { return LogFile_.is_open(); }						

	//! Путь к файлу отладочного протокола
	/*! Возвращает путь к файлу отладочного протокола.
		\return Путь к файлу отладочного протокола
	*/
	const std::filesystem::path& DebugLogFilePath() const { return LogFilePath_; }	
};

// описание адреса в БД, для которого
// выдается событие
struct CommunicationEventDBPointer
{
	std::string Table_;				// таблица хинта
	std::string Column_;			// столбец хинта
	long Index_;				// индекс хинта
	CommunicationEventDBPointer(
		std::string_view Table = {},
		std::string_view Column = {},
		long Index = 0) :
		Table_(Table),
		Column_(Column),
		Index_(Index) {}
};

// событие, которое уходит от сервера
struct CommunicationEvent : CommunicationEventDBPointer
{
	// перечисление типов событий 
	// (все события передаются в одном канале и
	// мы хотим их различать)
	EventTypes Type_;

	LogMessageTypes MessageType_;	// типы сообщений протокола
	EventHints Hint_;				// хинт
	std::string Message_;			// сообщение в протокол или вывод скрипта
	std::string UIform_;			// имя формы UI
	CommandHints Command_;

	// конструктор для очереди сообщений
	// с минимальным набором обязательных параметров
	CommunicationEvent(EventTypes Type,
		EventHints Hint,
		LogMessageTypes MessageType,
		std::string_view Message,
		std::string_view Table = {},
		std::string_view Column = {},
		std::string_view UIform = {},
		long Index = 0,
		CommandHints Command = CommandHints::Name) : 
		CommunicationEventDBPointer(Table, Column, Index),
		Type_(Type),
		MessageType_(MessageType),
		Hint_(Hint),
		Message_(Message),
		UIform_(UIform),
		Command_(Command) 
	{ }

	// пустой конструктор
	CommunicationEvent() : 
		CommunicationEventDBPointer(), 
		Type_(EventTypes::Log),
		MessageType_(LogMessageTypes::None) {}
};

// источник событий для gRPC-варианта
class CPlainRastrEventSourcegRPC : public CPlainRastrEventSource
{
public:
	using ComQueue = SafeQueue<CommunicationEvent>;			// очередь событий
protected:
	ComQueue queue_;
	std::atomic_bool stop_ = false;										// флаг останова сервиса для останова обработки очереди
public:
	bool HasToStop() const override { return stop_.load(); }
	void Stop(bool stop = true) override { stop_.store(stop); }
	void Event(EventHints Hint, std::string_view Table, std::string_view Column, long Index) override;
	void Log(LogMessageTypes status,
		std::string_view Message,
		long StageId,
		std::string_view Table = {},
		std::string_view Column = {},
		std::string_view UIform = {},
		long Index = 0) override;
	void Print(std::string_view Message) override;
	// извлечение из очереди очередного события
	// возвращает true, если есть event
	// возвращает false если обработка очереди завершена командой очереди SafeQueue::Finish
	bool ConsumeSync(CommunicationEvent& event)
	{
		return queue_.ConsumeSync(event);
	}
};

class CPlainLogger;

//! Стадия протокола
/*!
* Объект стадии протокола позволяет структурировать протокол в иерархическом виде. 
* Стадия имеет имя и идентификатор. Стадия может закрыть сама себя.
*/
class CPlainLoggerStage
{
protected:
	CPlainLogger& PlainLogger_;
	long StageId_;
	std::string StageName_;
	bool Hidden_ = false;
public:
	//! Возвращает идентификатор стадии
	long Id() const { return StageId_; }
	// ! Возвращает имя стадии, заданное при создании
	std::string_view Name() const { return StageName_; }
	// ! Конструктор
	/*!
	* \param PlainLogger Родительский логгер стадии
	* \param StageId Идентификатор стадии
	* \param Name Название стадии
	* \param Hidden Признак скрытой стадии
	*/
	CPlainLoggerStage(CPlainLogger& PlainLogger, long StageId, std::string_view Name, bool Hidden = false);
	//! Закрыть стадию, опционально с кодом завершения
	/*! Обычно стадия имеет статус с максимально серьезным уровнем 
	* среди всех сообщений в стадии. Но некто может захотеть задать
	* для стадии собственный независимый статус. Для этого 
	* предназначен ForcedStatus.
	* \param ForcedStatus Заданный статус стадии. Если не LogMessageTypes::None
	* задает статус стадии вне зависимости от её содержимого.
	*/
	//! Возвращает статус скрытой стадии 
	bool Hidden() const { return Hidden_; }
	//! Устанавливает статус скрытой стадии в доступный
	void Unhide() { Hidden_ = false; }
	void Close(LogMessageTypes ForcedStatus = LogMessageTypes::None);
	virtual ~CPlainLoggerStage() = default;
};

//! Стадия протокола с автоматическим закрытием
/*! Деструктор класса автоматически закрывает стадию. Класс
* удобен для работы в области видимости, в которой действует стадия.
* Применять можно двумя способами - получить ссылку от CPlainRastr::OpenStage()
* \code CAutoLogStage autostage{PlainRastrBase_.OpenStage("Расчет")};\endcode
* или получить std::unique_ptr от CPlainRastrBase::OpenAutoStage(). 
* \code auto autostage{PlainRastrBase_.OpenAutoStage("Расчет")};\endcode
* Второй вариант удобен когда неизвестно заранее нужно ли вообще 
* открывать стадию.
* \code
* std::unique_ptr<CAutoLogStaqe> stage;
* if(NeedStageOpen())
* 	stage = PlainRastrBase_.OpenAutoStage("Наконец-то");\endcode
* Автоматическую стадию также как и обычную можно закрыть с помошью Close().
*/
class CAutoLogStage : public CPlainLoggerStage
{
public:
	CAutoLogStage(CPlainLoggerStage& PlainLoggerStage) : CPlainLoggerStage(PlainLoggerStage) {}
	virtual ~CAutoLogStage();
};

enum class DebugLevels
{
	Full = 0,
	Light = 1,
	None = 2
};

//! Базовый класс логгера
class CPlainLogger
{
protected:
	// разрешение запрет вывода в протокол
	bool Enabled_ = true;
	// уровни вывода отладочного протокола
	DebugLevels DebugLevel_ = DebugLevels::Full;
	// логгер работает через источник событий. Всегда.
	CPlainRastrEventSource* EventSource_;
	// стек стадий
	std::list<CPlainLoggerStage> StageStack_;
	// возвращает идентификатор текущей стадии
	long StageId()
	{
		return StageStack_.empty() ? 0 : StageStack_.back().Id();
	}
	// показывает все вложенные скрытые стадии
	void ShowHiddenStages();
public:
	//! Конструктор
	/*! Логгер работает через источник событий.
	* \param EventSource Указатель на источник событий
	*/
	CPlainLogger(CPlainRastrEventSource* EventSource) : EventSource_(EventSource) {}

	//! Устанавливает блокировку вывода в протокол
	/*! \param Enable true - протокол заблокирован, false - разблокирован
	*/
	void Enable(bool Enable) { Enabled_ = Enable; }

	//! Возвращает признак разрешения вывода в протокол
	/*! \return true если вывод разрешен, false иначе. Если вывод запрещен
	в протокол сообщения не выводятся. На отладочный протокол, 
	выводимый с помощью Debug(), не влияет.
	*/
	bool Enabled() const { return Enabled_; }

	//! Установить уровень вывода в отладочный протокол
	void SetDebugLevel(DebugLevels DebugLevel) 
	{ 
		if (DebugLevel_ != DebugLevel)
		{
			// выводим в отладочный лог информацию об изменении уровня вывода
			Debug("Debug level changed from {} to {}", DebugLevel_, DebugLevel);
			DebugLevel_ = DebugLevel;
		}
	}
	//! Возвращает текущий уровень вывода в отладочный протокол
	/*!
	* \return Текущий уровень отладочного протокола
	*/
	DebugLevels DebugLevel() const { return DebugLevel_; }

	//! Проверка уровня отладочного протокола
	/*! Функцию удобно использовать для контроля уровня отладочного
	* протокола для того чтобы не вызывать Debug() c обработкой fmt только для
	* того чтобы в ней стало известно что на данном уровне DebugLevel 
	* сообщение не должно выводиться.
	* \param Level Уровень, который нужно проверить.
	* \return true, если вывод в отладочный протокол разрешен и уровень Levels 
	* больше, чем заданный в DebugLevel
	*/
	bool DebugLevel(DebugLevels Level) const { return DebugLevel_ != DebugLevels::None && Level >= DebugLevel_; }
	bool DebugLogActive() const { return EventSource_->DebugLogActive(); }
	virtual ~CPlainLogger() = default;


	//! Вывод строки в протокол со статусом
	/*! Выводит строку в протокол со статусом, не использует fmt.
	* Если протокол заблокирован Enable(), вывод не выполняется.
	* Если в протоколе были скрытые стадии - они будут показаны.
	* Функция является шорткатом к CPlainRastrEventSource::Log().
	* \param Status Статус сообщения
	* \param Message Сообщение
	*/
	void Log(LogMessageTypes Status, std::string_view Message)
	{
		ShowHiddenStages();
		if (Enabled())
			EventSource_->Log(Status, Message, StageId());
	}

	/*! Выводит строку в протокол со статусом в стиле fmt.
	* Если протокол заблокирован Enable(), вывод не выполняется.
	* Если в протоколе были скрытые стадии - они будут показаны.
	* Функция является шорткатом к CPlainRastrEventSource::Log().
	* \param Status Статус сообщения
	* \param Format форматная строка <a href="https://fmt.dev/latest/syntax.html">fmt::format</a>
	* \param args список значений для вывода в соответствии с Format
	*/
	template <typename... Args>
	void Log(LogMessageTypes Status, std::string_view Format, Args&&... args) 
	{
		ShowHiddenStages();
		if (Enabled())
			EventSource_->Log(Status, fmt::format(Format, args...), StageId());
	}

	/*! Выводит строку в протокол со статусом в стиле fmt c привязкой к БД и UI
	* Если протокол заблокирован Enable(), вывод не выполняется.
	* Если в протоколе были скрытые стадии - они будут показаны.
	* Функция является шорткатом к CPlainRastrEventSource::Log().
	* \param Status Статус сообщения
	* \param Format форматная строка <a href="https://fmt.dev/latest/syntax.html">fmt::format</a>
	* \param args список значений для вывода в соответствии с Format
	* \param Index Индекс в БД
	* \param Table Таблица БД
	* \param Column Поле БД
	* \param UIform Форма UI
	*/
	template <typename... Args>
	void Log(LogMessageTypes Status, 
			 long Index, 
		     std::string_view Table, 
			 std::string_view Column, 
			 std::string_view UIform, 
			 std::string_view Format, 
			 Args&&... args)
	{
		ShowHiddenStages();
		if (Enabled())
			EventSource_->Log(Status, fmt::format(Format, args...), StageId(), Table, Column, UIform, Index);
	}

	//! Вывод строки в отладочный протокол 
	/*!
		Функция является шорткатом CPlainLogger::DebugLog(). 		
		DebugLevel() на функцию не влияет. Уровень отладки проверяется до вызова
		DebugLevel, чтобы сэкономить на подготовке fmt, если отладочные данные 
		для заданного уровня не нужны.
		\code
		if(PlainLogger_.DebugLevel(DebugLevels::Full)
			PlainLogger_.Debug("Сообщение отладки с максимальной детализацией {}", PlainLogger_.Enabled());
		\endcode

		\param Format форматная строка <a href="https://fmt.dev/latest/syntax.html">fmt::format</a>
		\param args список значений для вывода в соответствии с Format
	*/
	template <typename... Args>
	void Debug(std::string_view Format, Args&&... args)
	{
		EventSource_->DebugLog(fmt::format(Format, args...));
	}
		
	// вывод скрипта
	void Print(std::string_view Message)
	{
		EventSource_->Print(Message);
	}

	//! Открывает стадию протокола
	/*! Если в протоколе были скрытые стадии - они будут выданы в протокол
	* перед данной стадией, так как она считается видимой. Скрытые стадии 
	* могут создаваться CPlainRastr::OpenStage() при условии, 
	* что CPlainRastr::LogOutputLevel == LogOutputLevels::None
	* или CPlainLogger::HiddenStage().
	* \param StageName Назавание стадии
	* \return Объект стадии
	*/
	CPlainLoggerStage& OpenStage(std::string_view StageName)
	{
		// если открываем видимую стадию, проверяем
		// нет ли предыдущих скрытых стадий
		ShowHiddenStages();
		StageStack_.push_back({ *this, static_cast<long>(StageStack_.size() + 1), StageName });
		if (Enabled())
			EventSource_->Log(LogMessageTypes::OpenStage, StageName, StageId());
		return StageStack_.back();
	}

	//! Открывает скрытую стадию протокола
	/*! Скрытая стадия входит в стек стадий, но не отображается
	* в протоколе. Если внутри нее приходит любое событие или
	* открывается видимая стадия, то данная стадия и все предыдущие
	* скрытые будут выданы в протокол. Если никаких вышеперечисленных
	* событий не происходит - скрытая стадия закрывается в стеке 
	* без вывода в протокол со всеми скрытыми стадиями внутри нее.
	* \param StageName Назавание стадии
	* \return Объект стадии
	*/
	CPlainLoggerStage& HiddenStage(std::string_view StageName)
	{
		StageStack_.push_back({ *this, static_cast<long>(StageStack_.size() + 1), StageName, true });
		return StageStack_.back();
	}

	//! Открыть стадию протокола в стиле fmt
	/*! Функция позволяет задать форматирование для CPlainLogger::OpenStage().
	* \param Format форматная строка <a href="https://fmt.dev/latest/syntax.html">fmt::format</a>
	* \param args список значений для вывода в соответствии с Format
	* \return Объект стадии
	*/
	template <typename... Args>
	CPlainLoggerStage& OpenStage(std::string_view Format, Args&&... args)
	{
		return OpenStage(fmt::format(Format, args...));
	}

	//! Открыть стадию протокола с привязкой к БД
	/*! Открывает стадию протокола с привязкой к источнику данных.
	* Если протокол заблокирован Enable(), вывод не выполняется.
	* Если в протоколе были скрытые стадии - они будут показаны.
	* \param Index Индекс в БД
	* \param Table Системное имя таблицы БД, к которой имеет отношение Message
	* \param Column Системное имя поля в таблице Table
	* \param UIform Имя формы отображения, к которой имеет отношение Message
	* \param Format форматная строка <a href="https://fmt.dev/latest/syntax.html">fmt::format</a>
	* \param args список значений для вывода в соответствии с Format
	* \return Объект стадии
	*/
	template <typename... Args>
	CPlainLoggerStage& OpenStage(long Index,
		std::string_view Table,
		std::string_view Column,
		std::string_view UIform,
		std::string_view Format,
		Args&&... args)
	{
		ShowHiddenStages();
		const std::string StageName{ fmt::format(Format, args...) };
		StageStack_.push_back({ *this, static_cast<long>(StageStack_.size() + 1), StageName });
		if(Enabled())
			EventSource_->Log(LogMessageTypes::OpenStage, StageName, StageId(), Table, Column, UIform, Index);
		return StageStack_.back();
	}

	//! Закрыть стадию по идентификатору с возможность
	/*! 
	* \param StageId Идентификатор закрываемой стадии. Если 0 - то закрывается верхняя стадия в стеке
	* \param EnforceCode Статус закрываемой стадии
	* \return true если стадия закрыта, false - если стадия со StageId не найдена.
	*/
	bool CloseStage(long StageId, LogMessageTypes EnforceCode = LogMessageTypes::None)
	{
		if (StageStack_.empty())
			return false;

		const auto ReportEnforcedStageClose = [this](LogMessageTypes EnforceCode)
		{
			const char* cszEnforceStageCloseStatus = "Получена команда закрыть стадию с заданным статусом, несмотря на уже выданные типы сообщений";
			// если указан код завершения стадии, выводим сообщение
			// о том что статус стадии установлен насильно
			if (Enabled() && EnforceCode != LogMessageTypes::None)
				EventSource_->Log(EnforceCode, cszEnforceStageCloseStatus, CPlainLogger::StageId());
		};

		// если Id стадии не указан, закрываем последнюю
		if (StageId == 0)
		{
			const auto& Deleted{ StageStack_.back() };
			ReportEnforcedStageClose(EnforceCode);
			
			if(Enabled())
				if (Deleted.Hidden())
				{
					// для скрытой стадии проверяем, есть ли насильный код, если есть
					// выводим сообщение с именем стадии  и насильным кодом
					if (EnforceCode != LogMessageTypes::None)
						EventSource_->Log(EnforceCode, Deleted.Name(), CPlainLogger::StageId());
				}
				else // при закрытии стадии код закрытия передаем в индексе
					EventSource_->Log(LogMessageTypes::CloseStage, {}, Deleted.Id(), {}, {}, {}, static_cast<long>(EnforceCode));
			StageStack_.pop_back();
			return true;
		}
		else
		{
			// если указан - ищем Id в стеке и закрываем все до него включительно
			auto idFound{ std::find_if(StageStack_.begin(), StageStack_.end(), [StageId](const CPlainLoggerStage& stage)
				{
					return stage.Id() == StageId;
				})
			};

			if (idFound != StageStack_.end())
			{
				ReportEnforcedStageClose(EnforceCode);
				while (!StageStack_.empty())
				{
					const auto& Deleted{ StageStack_.back() };
					const auto DeletedId{ Deleted.Id() };

					if (Enabled())
						if (Deleted.Hidden())
						{
							// для скрытой стадии проверяем, есть ли насильный код, если есть
							// выводим сообщение с именем стадии  и насильным кодом
							// причем делаем это только для стадии с запрошенным Id
							if (DeletedId == StageId && EnforceCode != LogMessageTypes::None)
								EventSource_->Log(EnforceCode, Deleted.Name(), CPlainLogger::StageId());
						}
						else // при закрытии стадии код закрытия передаем в индексе
							EventSource_->Log(LogMessageTypes::CloseStage, {}, DeletedId, {}, {}, {}, static_cast<long> (EnforceCode));

					StageStack_.pop_back();

					if (DeletedId == StageId)
						break;
				}
				return true;
			}
			else
				return false;
		}
	}

	//! Возвращает используемый CPlainRastrEventSource
	CPlainRastrEventSource* EventSource() { return EventSource_; }
};
