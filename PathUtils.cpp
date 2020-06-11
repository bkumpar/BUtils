#include "stdafx.h"
#include "BUtils.h"

namespace path_utils
{
	std::wstring sysTempPath()
	{
		wchar_t buffer[1024];
		GetTempPath( 1024, buffer);
		return std::wstring(buffer);
	}
}


