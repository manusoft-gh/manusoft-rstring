#include "pch.h"
#include "../RString.h"
#include "resource.h"

// run all tests; return total tests performed
size_t RunTests(size_t& failureCount)
{
	size_t testCount = 0;

	//Test 1
	++testCount;
	{
		if (RString(IDS_TEST1) != _T("Test string"))
			++failureCount;
	}

	//Test 2
	++testCount;
	{
		if (RString(IDS_TEST2) != _T("Format %u"))
			++failureCount;
	}

	//Test 3
	++testCount;
	{
		RString sTest3;
		sTest3.Format(RString(IDS_TEST2), 42u);
		if (sTest3 != _T("Format 42"))
			++failureCount;
	}

	//Test 4
	++testCount;
	{
		RString sTest4(_T("Hello"));
		RString sOther4(_T("hello"));
		if (sTest4.CompareNoCase(sOther4) != 0)
			++failureCount;
	}

	//Test 5
	++testCount;
	{
		RString sTest5(_T("Hello"));
		RString sOther5(_T("hello"));
		if (sTest5 == sOther5)
			++failureCount;
	}

	return testCount;
}
