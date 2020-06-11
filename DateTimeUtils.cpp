#include "stdafx.h"

#include <string>
#include <ctime>
#include <Windows.h>
#include "BUtils.h"

namespace datetime_utils
{

HRESULT parseDateTime(const std::wstring& datetimeStr, tm &tm)
{
   int year = 0, month = 0, day = 0, hour = 0, min = 0, sec = 0;
   int ret = swscanf_s(datetimeStr.c_str(), L"%4d.%2d.%2d. %2d:%2d", &year, &month, &day, &hour, &min, &sec);
   if ( ret == 5) 
   {
       tm.tm_year = year - 1900; /* years since 1900 */
       tm.tm_mon = month - 1 ;
       tm.tm_mday = day;
       tm.tm_hour = hour;
       tm.tm_min = min;
       tm.tm_sec = sec;
	   return S_OK;
   }
   else
   {
       return -3;
   }
}

HRESULT parseDateTime(const std::wstring& datetimeStr, time_t& tt)
{
	struct tm timeStruct;
	HRESULT res =  parseDateTime(datetimeStr, timeStruct);
    tt = mktime(&timeStruct);
    if ((tt == (time_t)-1)) 
    {
            return -2;
    }
	return S_OK;
}


HRESULT parseDateTime(const std::wstring& datetimeStr, FILETIME &fileDateTime)
{
	time_t tt;
	HRESULT res = parseDateTime(datetimeStr, tt);
	LONGLONG ll = Int32x32To64(tt, 10000000) + 116444736000000000;
	fileDateTime.dwLowDateTime = (DWORD) ll;
	fileDateTime.dwHighDateTime = ll >>32;
	return res;
}

bool convert(time_t tt, FILETIME &fileDateTime)
{
	LONGLONG ll = Int32x32To64(tt, 10000000) + 116444736000000000;
	fileDateTime.dwLowDateTime = (DWORD) ll;
	fileDateTime.dwHighDateTime = ll >>32;
	return true;
}


bool convert(tm timeStruct, time_t tt)
{
    tt = mktime(&timeStruct);
    if ((tt == (time_t)-1)) 
    {
            return false;
    }
	return true;
}

std::wstring format(const std::time_t t, const std::wstring& fmt)
{
    wchar_t wstr[100];
	tm timeStruct ;
	int err = localtime_s(&timeStruct, &t);
	if(err ==0)
	{
		if(std::wcsftime(wstr, 100, fmt.c_str(), &timeStruct)) 
		{
			return std::wstring(wstr);
		}
	}
	return std::wstring(L"");
}

std::wstring filetimeToStr(FILETIME ft)
{
	SYSTEMTIME st;
	wchar_t szLocalDate[255], szLocalTime[255];

	//   FileTimeToLocalFileTime( &ft, &ft );
	FileTimeToSystemTime( &ft, &st );
	GetDateFormat( LOCALE_USER_DEFAULT, DATE_SHORTDATE, &st, NULL,   szLocalDate, 255 );
	GetTimeFormat( LOCALE_USER_DEFAULT, 0, &st, NULL, szLocalTime, 255 );
	std::wstring localDate(szLocalDate );
	std::wstring localTime(szLocalTime );
	return localDate + L" " + localTime;
}

}