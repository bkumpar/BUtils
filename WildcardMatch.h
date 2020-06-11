//////////////////////////////////////////////////////////////////////////
//    WildcardMatch
//        pszString    - Input string to match
//        pszMatch    - Match mask that may contain wildcards like ? and *
//    
//        A ? sign matches any character, except an empty string.
//        A * sign matches any string inclusive an empty string.
//        Characters are compared caseless.

#include "windows.h"
#include <string>

bool wildcardMatch(const TCHAR *pszString, const TCHAR *pszMatch);

bool wildcardMatch(const std::wstring & text, const std::wstring & matchExpresion);
