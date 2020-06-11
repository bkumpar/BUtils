#include "stdafx.h"
#include "BUtils.h"

namespace string_utils
{
	void split(const std::wstring& str, std::vector<std::wstring> & container, wchar_t delim)
	{
		std::wstringstream ss(str);
		std::wstring token;
		while (std::getline(ss, token, delim)) 
		{
			container.push_back(token);
		}
	}

	std::wstring intToWStr(int value)
	{
		 return std::to_wstring((long long)value);
	}

	int wstrToInt(std::wstring value)
	{
		return  std::stoi(value);
	}

}