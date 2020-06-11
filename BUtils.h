#pragma once
#include <Windows.h>
#include <string>
#include <ctime>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>

typedef unsigned long long filesize_t;

#pragma region DateTimeUtils
namespace datetime_utils
{
	HRESULT parseDateTime(const std::wstring& datetimeStr, tm &tm);
	HRESULT parseDateTime(const std::wstring& datetimeStr, time_t& tt);
	HRESULT parseDateTime(const std::wstring& datetimeStr, FILETIME &fileDateTime);
	std::wstring format(const std::time_t t, const std::wstring& fmt);
	std::wstring filetimeToStr(FILETIME ft);
}
#pragma endregion

namespace string_utils
{
	void split(const std::wstring& str, std::vector<std::wstring> & container, wchar_t delim = ',');
	std::wstring intToWStr(int value);
	int wstrToInt(std::wstring value);
}

namespace path_utils
{
	std::wstring sysTempPath();

}