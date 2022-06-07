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

//! ���� ��������� ���������
/*!
  ��� ������������ ������ ���� �������������� ���
  COM � gRPC
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

// ����� ���������
enum class EventHints
{
	None = -1,		// ������� ���� ���������� �����-�� ������������� ����
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

// ���� �������
enum class EventTypes
{
	Log,		// ��������
	Print,		// ����� �������
	Hint,		// ���� ���������
	Command		// ���� ������� UI
};

//! ������� ����� ��������� �������
/*!
  ����� ������������ ��� �������� �� ������� ���������
  ������ � ��������. ����� �� ���� �����������, ��� ��� 
  ������� ���������� ������ �� ������. � �������������
  ������ ����� ��������� ������� ��� ������������ � ���������
  �����������. � �������� �������� ����� ���������� ������
  CPlainRastrEventSourcegRPC � CPlainRastrOriginalEventSource.
*/
class CPlainRastrEventSource
{
	std::ofstream LogFile_;
	std::filesystem::path LogFilePath_;
public:
	virtual ~CPlainRastrEventSource();
	//! ����� � ��������
	/*!
		����� � �������� ������ Message �� �������� status.
		��� �������� � UI ����� ������� Table, Column, UIform (��� �����)
		� Index ��. StageId �� ������������, �, ��������, ��� ������.
		��������� Table � UIform ��������� ������� ��� �����, � �������
		����� ������� ������, ��������� � Message. ��������� �� ������������
		� ������� �� ����������.

		\param status  ���� ��������� � ���������
		\param Message  ������, ������� ������ ���� �������� � ��������
		\param StageId  ������������� ������ ��������� (�� ������������), �� ����
		�������� ��� �������������
		\param Table ��������� ��� ������� ��, � ������� ����� ��������� Message
		\param Column ��������� ��� ���� � ������� Table
		\param UIform ��� ����� �����������, � ������� ����� ��������� Message
		\param Index ������ � ��

		������� ����� ��������� ����� � DebugLog(), ���� �� �������� : DebugLogActive().
		����� ��� �������� - ��� ������������ CPlainRastrEventSource ��������� ������� �����.

	*/
	virtual void Log(LogMessageTypes status,
					 std::string_view Message,
					 long StageId,
					 std::string_view Table = {},
					 std::string_view Column = {},
					 std::string_view UIform = {},
					 long Index = 0);												
	
	//! ����� ������ � �������
	/*! �������������� ��� �������� � ������� ��� ������ ����������,
		������� ��� ������� ���� ��������� �������.
		\param Message ������ ��� ������ � �������
	*/ 
	virtual void Print(std::string_view Message) {};								

	//! ��������� �������
	/*! ��������� ������� �� ��������� ��. ������ FChangeData.
		\param Hint ��� ���������
		\param Table ������� �� � ������� ��������� ���������
		\param Column ���� �� � �������� ��������� ���������
		\param Index ������ � ��
	*/
	virtual void Event(EventHints Hint, std::string_view Table, std::string_view Column, long Index) {};

	//! ������� �������
	virtual void Stop(bool stop = true) {};											

	//! �������� ������� �������� �������
	virtual bool HasToStop() const { return false; }								

	//! ������� �������� ����������� ��������
	virtual void StopProcessing(bool StopProcessing = true) {}						

	//! �������� ������� �������� ����������� ��������
	virtual bool HasToStopProcessing() const { return false; }						

	//! ����� � ���������� ��������
	/*! �� ��������� ���������� �������� ���������. ��� ���� �����
		�� �������������� ���������� ������ ���� � ����� ���������
		�������� DebugLogToFile(). ���� ���������� �������� �������,
		(���� ������, DebugLogActive() ���������� true) 
		������ Message ����� ������ � ���� ����.
		������ �� ����� ������ � ��������, �� ��������� �������� �����
		���������� � ���������� ��������.
		\param Message ������ ��� ������ � ���������� ��������
	*/
	virtual void DebugLog(std::string_view Message);								

	//! ������ ���� � ����������� ���������
	/*! ��������� ���� ����������� ��������� ��� ������ 
		� ������� DebugLog(). ���� ���� ������, 
		DebugLogFilePath() ���������� ���� � ����, �
		DebugLogActive() ���������� true.
		\param Path ���� � ����� ��� ��������. ���� � Path
		���� ��� �����, ����� ����������� ������� ��� �������
		�� ������. ��� ������ � ������������ ����� ����� ������.
		���� � Path ��� ����� �����, �� ����� ����������� �������
		������� ���� � ������, ��������� �� Prefix � ������� 
		�������� �����. � �������� ���������� ����� �����������
		Extension.
		\param Prefix ������� ��� ����� �����, ���� � Path ����� ����
		� ��������. ��� ����� ������������ �� ���������� ��������:
		\code {Prefix}_{:%Y-%m-%d_%H-%M-%S}_{C} \endcode
		�� ���� ��� ��������������� �� ��������, ����/������� � 
		�������� {C}, ���� ��� �������� ����� ��������, ��� ����
		� ����� ������ ��� ����������. ������� ������������� �� ���
		���, ���� ���� ����� � ����������� ������.
		\param Extension ���������� ����� ����������� ���������,
		���� � Path ����� ���� � �������� � ��������� �������������
		��� �����.
	*/
	void DebugLogToFile(const std::filesystem::path& Path, 
		std::string_view Prefix = {},
		std::string_view Extension = ".log");

	//! ������� ���������� ��������
	/*! ��������� ���� ����������� ���������. ����� ����������
		���� ������� ������� ����������� ��������� ������������
		�� ���������� �������� ����� �������� DebugLogToFile().
		���� ���������� �������� ������, DebugLog() �� ����� �������.
	*/
	void DebugLogCloseFile();														

	//! ��������� ������ �� ���������� ��������
	/*!
		���������� ������ ���������� ����������� ���������.
		\return true ���� ���� ����������� ��������� ������, 
				false � ��������� ������
	*/
	bool DebugLogActive() const { return LogFile_.is_open(); }						

	//! ���� � ����� ����������� ���������
	/*! ���������� ���� � ����� ����������� ���������.
		\return ���� � ����� ����������� ���������
	*/
	const std::filesystem::path& DebugLogFilePath() const { return LogFilePath_; }	
};

// �������� ������ � ��, ��� ��������
// �������� �������
struct CommunicationEventDBPointer
{
	std::string Table_;				// ������� �����
	std::string Column_;			// ������� �����
	long Index_;				// ������ �����
	CommunicationEventDBPointer(
		std::string_view Table = {},
		std::string_view Column = {},
		long Index = 0) :
		Table_(Table),
		Column_(Column),
		Index_(Index) {}
};

// �������, ������� ������ �� �������
struct CommunicationEvent : CommunicationEventDBPointer
{
	// ������������ ����� ������� 
	// (��� ������� ���������� � ����� ������ �
	// �� ����� �� ���������)
	EventTypes Type_;

	LogMessageTypes MessageType_;	// ���� ��������� ���������
	EventHints Hint_;				// ����
	std::string Message_;			// ��������� � �������� ��� ����� �������
	std::string UIform_;			// ��� ����� UI
	CommandHints Command_;

	// ����������� ��� ������� ���������
	// � ����������� ������� ������������ ����������
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

	// ������ �����������
	CommunicationEvent() : 
		CommunicationEventDBPointer(), 
		Type_(EventTypes::Log),
		MessageType_(LogMessageTypes::None) {}
};

// �������� ������� ��� gRPC-��������
class CPlainRastrEventSourcegRPC : public CPlainRastrEventSource
{
public:
	using ComQueue = SafeQueue<CommunicationEvent>;			// ������� �������
protected:
	ComQueue queue_;
	std::atomic_bool stop_ = false;										// ���� �������� ������� ��� �������� ��������� �������
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
	// ���������� �� ������� ���������� �������
	// ���������� true, ���� ���� event
	// ���������� false ���� ��������� ������� ��������� �������� ������� SafeQueue::Finish
	bool ConsumeSync(CommunicationEvent& event)
	{
		return queue_.ConsumeSync(event);
	}
};

class CPlainLogger;

//! ������ ���������
/*!
* ������ ������ ��������� ��������� ��������������� �������� � ������������� ����. 
* ������ ����� ��� � �������������. ������ ����� ������� ���� ����.
*/
class CPlainLoggerStage
{
protected:
	CPlainLogger& PlainLogger_;
	long StageId_;
	std::string StageName_;
	bool Hidden_ = false;
public:
	//! ���������� ������������� ������
	long Id() const { return StageId_; }
	// ! ���������� ��� ������, �������� ��� ��������
	std::string_view Name() const { return StageName_; }
	// ! �����������
	/*!
	* \param PlainLogger ������������ ������ ������
	* \param StageId ������������� ������
	* \param Name �������� ������
	* \param Hidden ������� ������� ������
	*/
	CPlainLoggerStage(CPlainLogger& PlainLogger, long StageId, std::string_view Name, bool Hidden = false);
	//! ������� ������, ����������� � ����� ����������
	/*! ������ ������ ����� ������ � ����������� ��������� ������� 
	* ����� ���� ��������� � ������. �� ����� ����� �������� ������
	* ��� ������ ����������� ����������� ������. ��� ����� 
	* ������������ ForcedStatus.
	* \param ForcedStatus �������� ������ ������. ���� �� LogMessageTypes::None
	* ������ ������ ������ ��� ����������� �� � �����������.
	*/
	//! ���������� ������ ������� ������ 
	bool Hidden() const { return Hidden_; }
	//! ������������� ������ ������� ������ � ���������
	void Unhide() { Hidden_ = false; }
	void Close(LogMessageTypes ForcedStatus = LogMessageTypes::None);
	virtual ~CPlainLoggerStage() = default;
};

//! ������ ��������� � �������������� ���������
/*! ���������� ������ ������������� ��������� ������. �����
* ������ ��� ������ � ������� ���������, � ������� ��������� ������.
* ��������� ����� ����� ��������� - �������� ������ �� CPlainRastr::OpenStage()
* \code CAutoLogStage autostage{PlainRastrBase_.OpenStage("������")};\endcode
* ��� �������� std::unique_ptr �� CPlainRastrBase::OpenAutoStage(). 
* \code auto autostage{PlainRastrBase_.OpenAutoStage("������")};\endcode
* ������ ������� ������ ����� ���������� ������� ����� �� ������ 
* ��������� ������.
* \code
* std::unique_ptr<CAutoLogStaqe> stage;
* if(NeedStageOpen())
* 	stage = PlainRastrBase_.OpenAutoStage("�������-��");\endcode
* �������������� ������ ����� ��� � ������� ����� ������� � ������� Close().
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

//! ������� ����� �������
class CPlainLogger
{
protected:
	// ���������� ������ ������ � ��������
	bool Enabled_ = true;
	// ������ ������ ����������� ���������
	DebugLevels DebugLevel_ = DebugLevels::Full;
	// ������ �������� ����� �������� �������. ������.
	CPlainRastrEventSource* EventSource_;
	// ���� ������
	std::list<CPlainLoggerStage> StageStack_;
	// ���������� ������������� ������� ������
	long StageId()
	{
		return StageStack_.empty() ? 0 : StageStack_.back().Id();
	}
	// ���������� ��� ��������� ������� ������
	void ShowHiddenStages();
public:
	//! �����������
	/*! ������ �������� ����� �������� �������.
	* \param EventSource ��������� �� �������� �������
	*/
	CPlainLogger(CPlainRastrEventSource* EventSource) : EventSource_(EventSource) {}

	//! ������������� ���������� ������ � ��������
	/*! \param Enable true - �������� ������������, false - �������������
	*/
	void Enable(bool Enable) { Enabled_ = Enable; }

	//! ���������� ������� ���������� ������ � ��������
	/*! \return true ���� ����� ��������, false �����. ���� ����� ��������
	� �������� ��������� �� ���������. �� ���������� ��������, 
	��������� � ������� Debug(), �� ������.
	*/
	bool Enabled() const { return Enabled_; }

	//! ���������� ������� ������ � ���������� ��������
	void SetDebugLevel(DebugLevels DebugLevel) 
	{ 
		if (DebugLevel_ != DebugLevel)
		{
			// ������� � ���������� ��� ���������� �� ��������� ������ ������
			Debug("Debug level changed from {} to {}", DebugLevel_, DebugLevel);
			DebugLevel_ = DebugLevel;
		}
	}
	//! ���������� ������� ������� ������ � ���������� ��������
	/*!
	* \return ������� ������� ����������� ���������
	*/
	DebugLevels DebugLevel() const { return DebugLevel_; }

	//! �������� ������ ����������� ���������
	/*! ������� ������ ������������ ��� �������� ������ �����������
	* ��������� ��� ���� ����� �� �������� Debug() c ���������� fmt ������ ���
	* ���� ����� � ��� ����� �������� ��� �� ������ ������ DebugLevel 
	* ��������� �� ������ ����������.
	* \param Level �������, ������� ����� ���������.
	* \return true, ���� ����� � ���������� �������� �������� � ������� Levels 
	* ������, ��� �������� � DebugLevel
	*/
	bool DebugLevel(DebugLevels Level) const { return DebugLevel_ != DebugLevels::None && Level >= DebugLevel_; }
	bool DebugLogActive() const { return EventSource_->DebugLogActive(); }
	virtual ~CPlainLogger() = default;


	//! ����� ������ � �������� �� ��������
	/*! ������� ������ � �������� �� ��������, �� ���������� fmt.
	* ���� �������� ������������ Enable(), ����� �� �����������.
	* ���� � ��������� ���� ������� ������ - ��� ����� ��������.
	* ������� �������� ��������� � CPlainRastrEventSource::Log().
	* \param Status ������ ���������
	* \param Message ���������
	*/
	void Log(LogMessageTypes Status, std::string_view Message)
	{
		ShowHiddenStages();
		if (Enabled())
			EventSource_->Log(Status, Message, StageId());
	}

	/*! ������� ������ � �������� �� �������� � ����� fmt.
	* ���� �������� ������������ Enable(), ����� �� �����������.
	* ���� � ��������� ���� ������� ������ - ��� ����� ��������.
	* ������� �������� ��������� � CPlainRastrEventSource::Log().
	* \param Status ������ ���������
	* \param Format ��������� ������ <a href="https://fmt.dev/latest/syntax.html">fmt::format</a>
	* \param args ������ �������� ��� ������ � ������������ � Format
	*/
	template <typename... Args>
	void Log(LogMessageTypes Status, std::string_view Format, Args&&... args) 
	{
		ShowHiddenStages();
		if (Enabled())
			EventSource_->Log(Status, fmt::format(Format, args...), StageId());
	}

	/*! ������� ������ � �������� �� �������� � ����� fmt c ��������� � �� � UI
	* ���� �������� ������������ Enable(), ����� �� �����������.
	* ���� � ��������� ���� ������� ������ - ��� ����� ��������.
	* ������� �������� ��������� � CPlainRastrEventSource::Log().
	* \param Status ������ ���������
	* \param Format ��������� ������ <a href="https://fmt.dev/latest/syntax.html">fmt::format</a>
	* \param args ������ �������� ��� ������ � ������������ � Format
	* \param Index ������ � ��
	* \param Table ������� ��
	* \param Column ���� ��
	* \param UIform ����� UI
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

	//! ����� ������ � ���������� �������� 
	/*!
		������� �������� ��������� CPlainLogger::DebugLog(). 		
		DebugLevel() �� ������� �� ������. ������� ������� ����������� �� ������
		DebugLevel, ����� ���������� �� ���������� fmt, ���� ���������� ������ 
		��� ��������� ������ �� �����.
		\code
		if(PlainLogger_.DebugLevel(DebugLevels::Full)
			PlainLogger_.Debug("��������� ������� � ������������ ������������ {}", PlainLogger_.Enabled());
		\endcode

		\param Format ��������� ������ <a href="https://fmt.dev/latest/syntax.html">fmt::format</a>
		\param args ������ �������� ��� ������ � ������������ � Format
	*/
	template <typename... Args>
	void Debug(std::string_view Format, Args&&... args)
	{
		EventSource_->DebugLog(fmt::format(Format, args...));
	}
		
	// ����� �������
	void Print(std::string_view Message)
	{
		EventSource_->Print(Message);
	}

	//! ��������� ������ ���������
	/*! ���� � ��������� ���� ������� ������ - ��� ����� ������ � ��������
	* ����� ������ �������, ��� ��� ��� ��������� �������. ������� ������ 
	* ����� ����������� CPlainRastr::OpenStage() ��� �������, 
	* ��� CPlainRastr::LogOutputLevel == LogOutputLevels::None
	* ��� CPlainLogger::HiddenStage().
	* \param StageName ��������� ������
	* \return ������ ������
	*/
	CPlainLoggerStage& OpenStage(std::string_view StageName)
	{
		// ���� ��������� ������� ������, ���������
		// ��� �� ���������� ������� ������
		ShowHiddenStages();
		StageStack_.push_back({ *this, static_cast<long>(StageStack_.size() + 1), StageName });
		if (Enabled())
			EventSource_->Log(LogMessageTypes::OpenStage, StageName, StageId());
		return StageStack_.back();
	}

	//! ��������� ������� ������ ���������
	/*! ������� ������ ������ � ���� ������, �� �� ������������
	* � ���������. ���� ������ ��� �������� ����� ������� ���
	* ����������� ������� ������, �� ������ ������ � ��� ����������
	* ������� ����� ������ � ��������. ���� ������� �����������������
	* ������� �� ���������� - ������� ������ ����������� � ����� 
	* ��� ������ � �������� �� ����� �������� �������� ������ ���.
	* \param StageName ��������� ������
	* \return ������ ������
	*/
	CPlainLoggerStage& HiddenStage(std::string_view StageName)
	{
		StageStack_.push_back({ *this, static_cast<long>(StageStack_.size() + 1), StageName, true });
		return StageStack_.back();
	}

	//! ������� ������ ��������� � ����� fmt
	/*! ������� ��������� ������ �������������� ��� CPlainLogger::OpenStage().
	* \param Format ��������� ������ <a href="https://fmt.dev/latest/syntax.html">fmt::format</a>
	* \param args ������ �������� ��� ������ � ������������ � Format
	* \return ������ ������
	*/
	template <typename... Args>
	CPlainLoggerStage& OpenStage(std::string_view Format, Args&&... args)
	{
		return OpenStage(fmt::format(Format, args...));
	}

	//! ������� ������ ��������� � ��������� � ��
	/*! ��������� ������ ��������� � ��������� � ��������� ������.
	* ���� �������� ������������ Enable(), ����� �� �����������.
	* ���� � ��������� ���� ������� ������ - ��� ����� ��������.
	* \param Index ������ � ��
	* \param Table ��������� ��� ������� ��, � ������� ����� ��������� Message
	* \param Column ��������� ��� ���� � ������� Table
	* \param UIform ��� ����� �����������, � ������� ����� ��������� Message
	* \param Format ��������� ������ <a href="https://fmt.dev/latest/syntax.html">fmt::format</a>
	* \param args ������ �������� ��� ������ � ������������ � Format
	* \return ������ ������
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

	//! ������� ������ �� �������������� � �����������
	/*! 
	* \param StageId ������������� ����������� ������. ���� 0 - �� ����������� ������� ������ � �����
	* \param EnforceCode ������ ����������� ������
	* \return true ���� ������ �������, false - ���� ������ �� StageId �� �������.
	*/
	bool CloseStage(long StageId, LogMessageTypes EnforceCode = LogMessageTypes::None)
	{
		if (StageStack_.empty())
			return false;

		const auto ReportEnforcedStageClose = [this](LogMessageTypes EnforceCode)
		{
			const char* cszEnforceStageCloseStatus = "�������� ������� ������� ������ � �������� ��������, �������� �� ��� �������� ���� ���������";
			// ���� ������ ��� ���������� ������, ������� ���������
			// � ��� ��� ������ ������ ���������� ��������
			if (Enabled() && EnforceCode != LogMessageTypes::None)
				EventSource_->Log(EnforceCode, cszEnforceStageCloseStatus, CPlainLogger::StageId());
		};

		// ���� Id ������ �� ������, ��������� ���������
		if (StageId == 0)
		{
			const auto& Deleted{ StageStack_.back() };
			ReportEnforcedStageClose(EnforceCode);
			
			if(Enabled())
				if (Deleted.Hidden())
				{
					// ��� ������� ������ ���������, ���� �� ��������� ���, ���� ����
					// ������� ��������� � ������ ������  � ��������� �����
					if (EnforceCode != LogMessageTypes::None)
						EventSource_->Log(EnforceCode, Deleted.Name(), CPlainLogger::StageId());
				}
				else // ��� �������� ������ ��� �������� �������� � �������
					EventSource_->Log(LogMessageTypes::CloseStage, {}, Deleted.Id(), {}, {}, {}, static_cast<long>(EnforceCode));
			StageStack_.pop_back();
			return true;
		}
		else
		{
			// ���� ������ - ���� Id � ����� � ��������� ��� �� ���� ������������
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
							// ��� ������� ������ ���������, ���� �� ��������� ���, ���� ����
							// ������� ��������� � ������ ������  � ��������� �����
							// ������ ������ ��� ������ ��� ������ � ����������� Id
							if (DeletedId == StageId && EnforceCode != LogMessageTypes::None)
								EventSource_->Log(EnforceCode, Deleted.Name(), CPlainLogger::StageId());
						}
						else // ��� �������� ������ ��� �������� �������� � �������
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

	//! ���������� ������������ CPlainRastrEventSource
	CPlainRastrEventSource* EventSource() { return EventSource_; }
};
