#pragma once
#include <string>
#include <exception>
#include "stringutils.h"

#ifdef _MSC_VER
#include <Windows.h>
#endif

// � ���� ��������� ��� ��� ���������� ������ ������������� �� std::exception
// ����� �� �������� � catch � ����� ���������� what

// ������� ���������� � ����������
class CException : public std::runtime_error
{
public:
	template <typename... Args>
	CException(std::string_view Format, Args&&... args) : std::runtime_error(fmt::format(Format, args...)) {}
};

// ���������� ������ Cmyex
// Cmyex ���� �� ������������� ��� ����������
// ������� � ������ ���������� ��

// �� ��� � ������� �� ��� ��� ����� ��� �������
class CBadDBAccess : public std::runtime_error
{
protected:
	std::string Field_;		// ���� � ������� ������ ������ nam1, nam2
	std::string Table_;
	int Type_;				// ��� �� ����� ����� (���������� ��� ��� �� ���������� ��)
public:
	// ��������� ����������� �� std::exception ����� ��������� what()
	// ������ ���������� ������ ������������� ��������� � ������������
	// ��� ��� � ��� ���������� ��� ������ - ��������� �� �����
	// �� ���� ������ ����� ���� ����� � ������ �� �����,
	// �� ���� ��� �������� ���� ��� ����������� �� �������� - ������
	CBadDBAccess(int Type, std::string_view Field, std::string_view Table) :
		std::runtime_error(CBadDBAccess::GetWhat(Field, Table)),
		Field_(Field),
		Table_(Table),
		Type_(Type) { };

	// �������
	const char* Field() const { return Field_.c_str(); }
	const char* Table() const { return Table_.c_str(); }
	const int Type() const { return Type_; }

	// ������������ what ��� ������������
	static std::string GetWhat(std::string_view Field, std::string_view Table)
	{
		if (Field.empty())	// ���� ���� ������ - ����� ��� �������
			return fmt::format(szTableNotFound, Table);
		else // ���� ���� � ������� �� ������ - ����� ��� ���� � �������
			return fmt::format(szFieldInTableNotFound, Field, Table);
	}

	static constexpr const char* szTableNotFound = "�� ������� ������� \"{}\"";
	static constexpr const char* szFieldInTableNotFound = "�� ������� ���� \"{}\" � ������� \"{}\"";
};

// ��������� � ������ ���������� ���������� �� GetLastError
class CExceptionGLE : public CException
{
public:
	template <typename... Args>
	CExceptionGLE(std::string_view Format, Args&&... args) : CException(MessageFormat(fmt::format(Format, args...))) {}

	static std::string MessageFormat(std::string_view Message)
	{
		std::string message;
		int Code(errno);
#ifdef _MSC_VER
		const DWORD dwError{ ::GetLastError() };

		// �������� ������ �� code �������� � CP_ACP, ������� ��� ���������� � �������
		// ������� acp_decode
		// https://blogs.msmvps.com/gdicanio/2017/08/16/what-is-the-encoding-used-by-the-error_code-message-string/

		if (dwError != 0)
		{
			LPWSTR messageBuffer{ nullptr };
			const size_t size = FormatMessageW(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
				NULL, dwError, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPWSTR)&messageBuffer, 0, NULL);
			std::wstring wmessage(messageBuffer, size);
			LocalFree(messageBuffer);
			message = stringutils::acp_encode(stringutils::utf8_encode(wmessage));
		}
		else
		{
			const std::error_code code(Code, std::system_category());
			message = code.message();
		}
#else
		std::error_code code(Code, std::system_category());
		message = code.message();
#endif 
		stringutils::removecrlf(message);
		return fmt::format("{} ��������� ������ � {}: \"{}\"", Message, Code, message);
	}
};