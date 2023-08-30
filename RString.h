// Copyright 2002 ManuSoft
// https://www.manusoft.com
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef _RSTRING_H_INCLUDED_
#define _RSTRING_H_INCLUDED_

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers
#include <Afx.h>

class RString : public CString
{
protected:
	operator CString& () { return *this; }
	operator const CString& () const { return *this; }
public:
	void* operator new(size_t cbAlloc) { return ::operator new(cbAlloc); }
	void operator delete(void* pvMem) { ::operator delete(pvMem); }
	void* operator new[](size_t cbAlloc) { return ::operator new(cbAlloc); }
	void operator delete[](void* pvMem) { ::operator delete(pvMem); }

		RString() {}
	RString(const int nResourceId) { LoadString(nResourceId); }
	RString(const unsigned int nResourceId) { LoadString(nResourceId); }
	RString(const CString& stringSrc) : CString(stringSrc) {}

	RString(const RString& stringSrc) : CString(stringSrc) {}
	RString(TCHAR ch, int nRepeat = 1) : CString(ch, nRepeat) {}
	RString(LPCSTR lpsz) : CString(lpsz) {}
	RString(LPCWSTR lpsz) : CString(lpsz) {}
	RString(LPCSTR lpch, int nLength) : CString(lpch, nLength) {}
#if( _MFC_VER >= 0x0600 )
	RString(LPCWSTR lpch, int nLength) : CString(lpch, nLength) {}
#endif
	RString(const unsigned char* psz) : CString(psz) {}
	virtual ~RString() {}

	int GetLength() const { return CString::GetLength(); }
	BOOL IsEmpty() const { return CString::IsEmpty(); }
	void Empty() { CString::Empty(); }
	TCHAR GetAt(int nIndex) const { return CString::GetAt(nIndex); }
	TCHAR operator[](int nIndex) const { return CString::operator[](nIndex); }
	void SetAt(int nIndex, TCHAR ch) { CString::SetAt(nIndex, ch); }
	operator LPCTSTR() const { return CString::operator LPCTSTR(); }

#pragma warning(push)
#pragma warning(disable:4172)
	const RString& operator=(const CString& stringSrc) { return CString::operator=(stringSrc); }
	const RString& operator=(const RString& stringSrc) { return CString::operator=(stringSrc); }
	const RString& operator=(TCHAR ch) { return CString::operator=(ch); }
#ifdef _UNICODE
	const RString& operator=(char ch) { return CString::operator=(ch); }
#endif
	const RString& operator=(LPCSTR lpsz) { return CString::operator=(lpsz); }
	const RString& operator=(LPCWSTR lpsz) { return CString::operator=(lpsz); }
	const RString& operator=(const unsigned char* psz) { return CString::operator=(psz); }
	const RString& operator+=(const CString& string) { return CString::operator+=(string); }
	const RString& operator+=(const RString& string) { return CString::operator+=(string); }
	const RString& operator+=(TCHAR ch) { return CString::operator+=(ch); }
#ifdef _UNICODE
	const RString& operator+=(char ch) { return CString::operator+=(ch); }
#endif
	const RString& operator+=(LPCTSTR lpsz) { return CString::operator+=(lpsz); }
#pragma warning(pop)

	friend RString AFXAPI operator+(const RString& string1, const RString& string2) { return operator+((CString&)string1, (CString&)string2); }
	friend RString AFXAPI operator+(const RString& string, TCHAR ch) { return operator+((CString&)string, ch); }
	friend RString AFXAPI operator+(TCHAR ch, const RString& string) { return operator+(ch, (CString&)string); }
#ifdef _UNICODE
	friend RString AFXAPI operator+(const RString& string, char ch) { return operator+((CString&)string, ch); }
	friend RString AFXAPI operator+(char ch, const RString& string) { return operator+(ch, (CString&)string); }
#endif
	friend RString AFXAPI operator+(const RString& string, LPCTSTR lpsz) { return operator+((CString&)string, lpsz); }
	friend RString AFXAPI operator+(LPCTSTR lpsz, const RString& string) { return operator+(lpsz, (CString&)string); }

	friend bool AFXAPI operator==(const RString& s1, const RString& s2);
	friend bool AFXAPI operator==(const RString& s1, LPCTSTR s2);
	friend bool AFXAPI operator==(LPCTSTR s1, const RString& s2);
	friend bool AFXAPI operator==(const RString& s1, TCHAR c2);
	friend bool AFXAPI operator==(TCHAR c1, const RString& s2);
	friend bool AFXAPI operator!=(const RString& s1, const RString& s2);
	friend bool AFXAPI operator!=(const RString& s1, LPCTSTR s2);
	friend bool AFXAPI operator!=(LPCTSTR s1, const RString& s2);
	friend bool AFXAPI operator<(const RString& s1, const RString& s2);
	friend bool AFXAPI operator<(const RString& s1, LPCTSTR s2);
	friend bool AFXAPI operator<(LPCTSTR s1, const RString& s2);
	friend bool AFXAPI operator>(const RString& s1, const RString& s2);
	friend bool AFXAPI operator>(const RString& s1, LPCTSTR s2);
	friend bool AFXAPI operator>(LPCTSTR s1, const RString& s2);
	friend bool AFXAPI operator<=(const RString& s1, const RString& s2);
	friend bool AFXAPI operator<=(const RString& s1, LPCTSTR s2);
	friend bool AFXAPI operator<=(LPCTSTR s1, const RString& s2);
	friend bool AFXAPI operator>=(const RString& s1, const RString& s2);
	friend bool AFXAPI operator>=(const RString& s1, LPCTSTR s2);
	friend bool AFXAPI operator>=(LPCTSTR s1, const RString& s2);

	int Compare(LPCTSTR lpsz) const { return CString::Compare(lpsz); }
	int CompareNoCase(LPCTSTR lpsz) const { return CString::CompareNoCase(lpsz); }
	int Collate(LPCTSTR lpsz) const { return CString::Collate(lpsz); }
#if( _MFC_VER >= 0x0600 )
	int CollateNoCase(LPCTSTR lpsz) const { return CString::CollateNoCase(lpsz); }
#endif

	RString Mid(int nFirst, int nCount) const { return CString::Mid(nFirst, nCount); }
	RString Mid(int nFirst) const { return CString::Mid(nFirst); }
	RString Left(int nCount) const { return CString::Left(nCount); }
	RString Right(int nCount) const { return CString::Right(nCount); }
	RString SpanIncluding(LPCTSTR lpszCharSet) const { return CString::SpanIncluding(lpszCharSet); }
	RString SpanExcluding(LPCTSTR lpszCharSet) const { return CString::SpanExcluding(lpszCharSet); }

	void MakeUpper() { CString::MakeUpper(); }
	void MakeLower() { CString::MakeLower(); }
	void MakeReverse() { CString::MakeReverse(); }

	void TrimRight() { CString::TrimRight(); }
	void TrimLeft() { CString::TrimLeft(); }

#if( _MFC_VER >= 0x0600 )
	void TrimRight(TCHAR chTarget) { CString::TrimRight(chTarget); }
	void TrimRight(LPCTSTR lpszTargets) { CString::TrimRight(lpszTargets); }
	void TrimLeft(TCHAR chTarget) { CString::TrimLeft(chTarget); }
	void TrimLeft(LPCTSTR lpszTargets) { CString::TrimLeft(lpszTargets); }

	int Replace(TCHAR chOld, TCHAR chNew) { return CString::Replace(chOld, chNew); }
	int Replace(LPCTSTR lpszOld, LPCTSTR lpszNew) { return CString::Replace(lpszOld, lpszNew); }
	int Remove(TCHAR chRemove) { return CString::Remove(chRemove); }
	int Insert(int nIndex, TCHAR ch) { return CString::Insert(nIndex, ch); }
	int Insert(int nIndex, LPCTSTR pstr) { return CString::Insert(nIndex, pstr); }
	int Delete(int nIndex, int nCount = 1) { return CString::Delete(nIndex, nCount); }
#endif

	int Find(TCHAR ch) const { return CString::Find(ch); }
	int ReverseFind(TCHAR ch) const { return CString::ReverseFind(ch); }
#if( _MFC_VER >= 0x0600 )
	int Find(TCHAR ch, int nStart) const { return CString::Find(ch, nStart); }
#endif
	int FindOneOf(LPCTSTR lpszCharSet) const { return CString::FindOneOf(lpszCharSet); }
	int Find(LPCTSTR lpszSub) const { return CString::Find(lpszSub); }
#if( _MFC_VER >= 0x0600 )
	int Find(LPCTSTR lpszSub, int nStart) const { return CString::Find(lpszSub, nStart); }
#endif

	RString& AFX_CDECL Format(LPCTSTR lpszFormat, ...)
	{
		va_list marker;
		va_start(marker, lpszFormat);
		CString::FormatV(lpszFormat, marker);
		va_end(marker);
		return *this;
	}
	RString& AFX_CDECL Format(UINT nFormatID, ...)
	{
		RString sFormat(nFormatID);
		va_list marker;
		va_start(marker, nFormatID);
		CString::FormatV(sFormat, marker);
		va_end(marker);
		return *this;
	}
#if( _MFC_VER < 0x0600 )
protected:
	void FormatV(LPCTSTR lpszFormat, va_list argList) { CString::FormatV(lpszFormat, argList); }
public:
#else
	void FormatV(LPCTSTR lpszFormat, va_list argList) { CString::FormatV(lpszFormat, argList); }
#endif
	RString& AFX_CDECL FormatMessage(LPCTSTR lpszFormat, ...)
	{
		va_list argList;
		va_start(argList, lpszFormat);
		LPTSTR lpszTemp;

		if (::FormatMessage(FORMAT_MESSAGE_FROM_STRING | FORMAT_MESSAGE_ALLOCATE_BUFFER,
			lpszFormat,
			0,
			0,
			(LPTSTR)&lpszTemp,
			0,
			&argList) == 0 ||
			lpszTemp == NULL)
		{
			AfxThrowMemoryException();
		}
		*this = lpszTemp;
		LocalFree(lpszTemp);
		va_end(argList);
		return *this;
	}
	RString& AFX_CDECL FormatMessage(UINT nFormatID, ...)
	{
		CString strFormat;
		VERIFY(strFormat.LoadString(nFormatID) != 0);
		va_list argList;
		va_start(argList, nFormatID);
		LPTSTR lpszTemp;
		if (::FormatMessage(FORMAT_MESSAGE_FROM_STRING | FORMAT_MESSAGE_ALLOCATE_BUFFER,
			strFormat,
			0,
			0,
			(LPTSTR)&lpszTemp,
			0,
			&argList) == 0 ||
			lpszTemp == NULL)
		{
			AfxThrowMemoryException();
		}
		*this = lpszTemp;
		LocalFree(lpszTemp);
		va_end(argList);
		return *this;
	}

#if( _MFC_VER < 0x0600 )
#ifdef _DEBUG
	friend CDumpContext& AFXAPI operator<<(CDumpContext& dc, const CString& string) { return operator<<(dc, (const CString&)string); }
#endif
	friend CArchive& AFXAPI operator<<(CArchive& ar, const CString& string) { return operator<<(ar, (const CString&)string); }
	friend CArchive& AFXAPI operator>>(CArchive& ar, CString& string) { return operator>>(ar, (CString&)string); }
#endif

	BOOL LoadString(UINT nID) { return CString::LoadString(nID); }

#ifndef _UNICODE
	void AnsiToOem() { CString::AnsiToOem(); }
	void OemToAnsi() { CString::OemToAnsi(); }
#endif

#if( _MFC_VER >= 0x0600 )
#ifndef _AFX_NO_BSTR_SUPPORT
	BSTR AllocSysString() const { return CString::AllocSysString(); }
	BSTR SetSysString(BSTR* pbstr) const { return CString::SetSysString(pbstr); }
#endif
#endif
	LPTSTR GetBuffer(int nMinBufLength) { return CString::GetBuffer(nMinBufLength); }
	void ReleaseBuffer(int nNewLength = -1) { CString::ReleaseBuffer(nNewLength); }
	LPTSTR GetBufferSetLength(int nNewLength) { return CString::GetBufferSetLength(nNewLength); }
	void FreeExtra() { CString::FreeExtra(); }
	LPTSTR LockBuffer() { return CString::LockBuffer(); }
	void UnlockBuffer() { CString::UnlockBuffer(); }

	int GetAllocLength() const { return CString::GetAllocLength(); }
};

#if( _MFC_VER < 0x0600 )
#pragma warning(push)
#pragma warning(disable : 4800)
#endif
bool AFXAPI operator==(const RString& s1, const RString& s2)
{
	return operator==((const CString&)s1, (const CString&)s2);
}

bool AFXAPI operator==(const RString& s1, LPCTSTR s2)
{
	return operator==((const CString&)s1, s2);
}

bool AFXAPI operator==(LPCTSTR s1, const RString& s2)
{
	return operator==(s1, (const CString&)s2);
}

bool AFXAPI operator==(const RString& s1, TCHAR c2)
{
	return (s1[0] == c2);
}

bool AFXAPI operator==(TCHAR c1, const RString& s2)
{
	return (c1 == s2[0]);
}

bool AFXAPI operator!=(const RString& s1, const RString& s2)
{
	return operator!=((const CString&)s1, (const CString&)s2);
}

bool AFXAPI operator!=(const RString& s1, LPCTSTR s2)
{
	return operator!=((const CString&)s1, s2);
}

bool AFXAPI operator!=(LPCTSTR s1, const RString& s2)
{
	return operator!=(s1, (const CString&)s2);
}

bool AFXAPI operator!=(const RString& s1, TCHAR c2)
{
	return (s1[0] != c2);
}

bool AFXAPI operator!=(TCHAR c1, const RString& s2)
{
	return (c1 != s2[0]);
}

bool AFXAPI operator<(const RString& s1, const RString& s2)
{
	return operator<((const CString&)s1, (const CString&)s2);
}

bool AFXAPI operator<(const RString& s1, LPCTSTR s2)
{
	return operator<((const CString&)s1, s2);
}

bool AFXAPI operator<(LPCTSTR s1, const RString& s2)
{
	return operator<(s1, (const CString&)s2);
}

bool AFXAPI operator>(const RString& s1, const RString& s2)
{
	return operator>((const CString&)s1, (const CString&)s2);
}

bool AFXAPI operator>(const RString& s1, LPCTSTR s2)
{
	return operator>((const CString&)s1, s2);
}

bool AFXAPI operator>(LPCTSTR s1, const RString& s2)
{
	return operator>(s1, (const CString&)s2);
}

bool AFXAPI operator<=(const RString& s1, const RString& s2)
{
	return operator<=((const CString&)s1, (const CString&)s2);
}

bool AFXAPI operator<=(const RString& s1, LPCTSTR s2)
{
	return operator<=((const CString&)s1, s2);
}

bool AFXAPI operator<=(LPCTSTR s1, const RString& s2)
{
	return operator<=(s1, (const CString&)s2);
}

bool AFXAPI operator>=(const RString& s1, const RString& s2)
{
	return operator>=((const CString&)s1, (const CString&)s2);
}

bool AFXAPI operator>=(const RString& s1, LPCTSTR s2)
{
	return operator>=((const CString&)s1, s2);
}

bool AFXAPI operator>=(LPCTSTR s1, const RString& s2)
{
	return operator>=(s1, (const CString&)s2);
}
#if( _MFC_VER < 0x0600 )
#pragma warning(pop)
#endif

#endif //_RSTRING_H_INCLUDED_
