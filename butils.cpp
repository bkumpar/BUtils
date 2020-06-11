// butils.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include "BUtils.h"
#include <Windows.h>

namespace dtu=datetime_utils;

bool test_parseDateTime1()
{
	std::wstring datetimeStr(L"2019.06.01. 21:33:59");
	tm timeStruct;
	if(S_OK == dtu::parseDateTime(datetimeStr, timeStruct))
	{
		return  (timeStruct.tm_year == 119)
			&& (timeStruct.tm_mon == 5)
			&& (timeStruct.tm_mday == 1)
			&& (timeStruct.tm_hour == 21)
			&& (timeStruct.tm_min == 33)
			&& (timeStruct.tm_sec == 59);
	}
	else
	{
		return false;
	}
}


bool test_parseDateTime2()
{
	std::wstring datetimeStr(L"2019.06.01. 21:33:59");
	time_t tt;
	HRESULT ret = dtu::parseDateTime( datetimeStr, tt);
	return  ret == S_OK;
}

bool test_parseDateTime3()
{
	std::wstring datetimeStr;
	FILETIME fileDateTime;
	HRESULT ret =  dtu::parseDateTime(datetimeStr, fileDateTime);
	return ret == S_OK;
}


bool test_format()
{
	std::wstring datetimeStr(L"2019.06.01. 21:33:59");
	time_t tt;
	HRESULT ret = dtu::parseDateTime( datetimeStr, tt);

	std::wstring fmt = L"%Y.%m.%d. %H:%M:%S";
	std::wstring timestr =  dtu::format(tt, fmt);
	return timestr==L"2019.06.01. 21:33:59";
}


filesize_t convertFileSize(DWORD nFileSizeHigh, DWORD nFileSizeLow)
{
	filesize_t fileSize;
	fileSize = nFileSizeHigh;
	fileSize <<= sizeof( nFileSizeHigh ) * 8; 
	fileSize |= nFileSizeLow;
	return fileSize;
}

int _tmain(int argc, _TCHAR* argv[])
{
	if(!test_parseDateTime1()) std::wcout << "test_parseDateTime1 FAILED." << std::endl;
	if(!test_parseDateTime2()) std::wcout << "test_parseDateTime2 FAILED." << std::endl;
	if(!test_format()) std::wcout << "test_format FAILED." << std::endl;
	return 0;
}
