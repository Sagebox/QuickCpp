// This file copyright(c) 2021 Rob Nelson, All Rights Reserved.    E-mail rob@projectsagebox.com for more information.
//

// --------------------------------------------------------------------------------------------------------------
// PRELIMINARY VERSION.  This file has been brought into the Sagebox project from the original sources and has 
// not yet been commented for Sagebox, or properly formatted (I used tabs and am converting to spaces).
// --------------------------------------------------------------------------------------------------------------
//
// ****** UNDER CONSTRUCTION ******
//
// This file is still under construction and may not yet include specifics, awaiting proper testing and integration into Sagebox.
//

//#pragma once
#if !defined(_CSageString_H_)
#define _CSageString_H_
//#pragma warning( disable : 4996) 
#include <Windows.h>
#include <string>

namespace Sage
{
class CString;
class CStringW;
using CStr = CString;
using CStrW = CStringW;
class CString
{
	class CStringW;
public:
    struct csFloatType
    {
        const char * sFloatStyle;
    };

private:
    // Since Init() is in the interface, this can be changed to set a different default style for all CString() usage.
    static constexpr const char * kDefaultFloatStyle = "%g";
    static constexpr const int kDefaultStackSize = 300;
	int m_iMaxSize		= kDefaultStackSize; 
	int m_iMinAllocSize	= 1024;
	int m_iAllocSize;
	char * s;
	char sStatic[kDefaultStackSize+1];
    char sFloatStyle[10];   // String for the float style, to override the default
                            // This allows the caller to set how floating-point values are output. 
	char * sAlloc;
	int iPlace;
    bool m_bInvalid = false;    // Gets set to true on memory allocation errors.  Use isValid() to check
    bool bDefaultFloatStyle;
    void SetFloatStyle(csFloatType csStyle);
	void _AddString(char * sString); 
	void _AddString(wchar_t * sString); 
	void StartString(char * sString); 
	void StartString(wchar_t * sString); 
	void StartString(int iValue); 
	void StartString(char cValue); 
	void StartString(unsigned int uiValue); 
	void AddNumber(int x); 
	void AddNumber(unsigned int x); 
	void AddChar(char x); 
    void AddDouble(double x2);
    int GetNextAllocSize(int iMemNeeded,int iBlockSize);

public:
	char * Return(int x);

    // CString::fs() -- Set the floating-point output style. 
    //
    // This can be used via streaming, i.e. CString() << "This is a number " << fs("%.10f") << MyNumber; 
    // It can be used anywhere or anytime with the current CString(), but does not take effect for numbers preceding the 
    // fs() call. 
    //
    // Note: When using the default style, 0 is represented as "0" and trailing 0's are removed.
    // Setting the float style, this no longer occurs to support the new style.  This also means that setting the style
    // to the same string as the default style will also disable the post-formatting.
    //
    // Use fs() to restore the default style. 
    //
    CString & fs(const char * sStyle = nullptr) { SetFloatStyle({sStyle}); return *this; }


    // GetDefaultFloatStyle() -- returns the default floating-point style for CString floating-point output.
    // Use CString::fs() to set the floating-point style. 
    //
    const char * GetDefaultFloatStyle() { return kDefaultFloatStyle; };

//    __forceinline CString & FloatStyle(const char * sStyle) { return _fsX(sStyle); } // Inlined so we don't do a double call

	__forceinline CString & operator << (std::string & x)		{ _AddString((char *) x.c_str()); return((CString &) *this); }
//	__forceinline CString & operator << (char * x)			    { AddString(x); return((CString &) *this); }
	__forceinline CString & operator << (const char * x)		{ _AddString((char *) x); return((CString &) *this); }
	__forceinline CString & operator << (wchar_t * x)			{ _AddString(x); return((CString &) *this); }
	__forceinline CString & operator << (const wchar_t * x)	    { _AddString((wchar_t *) x); return((CString &) *this); }
	__forceinline CString & operator << (char x)				{ AddChar(x); return((CString &) *this); }
	__forceinline CString & operator << (int x)				    { AddNumber(x); return((CString &) *this); }
	__forceinline CString & operator << (long x)				{ AddNumber((int) x); return((CString &) *this); }
	__forceinline CString & operator << (unsigned int x)		{ AddNumber((int) x); return((CString &) *this); }
	__forceinline CString & operator << (DWORD x)				{ AddNumber((unsigned int) x); return((CString &) *this); }
	__forceinline CString & operator << (double x2)			    { AddDouble(x2); return((CString &) *this); }
	__forceinline CString & operator << (csFloatType csft)	    { SetFloatStyle(csft); return *this; }

	__forceinline CString & operator >> (std::string & x)		{ StartString((char *) x.c_str()); return((CString &) *this); }
	__forceinline CString & operator >> (char * x)			    { StartString(x); return((CString &) *this); }
	__forceinline CString & operator >> (const char * x)		{ StartString((char *) x); return((CString &) *this); }
	__forceinline CString & operator >> (wchar_t * x)			{ StartString(x); return((CString &) *this); }
	__forceinline CString & operator >> (const wchar_t * x)	    { StartString((wchar_t *) x); return((CString &) *this); }
	__forceinline CString & operator >> (char x)				{ StartString(x); return((CString &) *this); }
	__forceinline CString & operator >> (int x)				    { StartString(x); return((CString &) *this); }
	__forceinline CString & operator >> (long x)				{ StartString((int) x); return((CString &) *this); }
	__forceinline CString & operator >> (unsigned int x)		{ StartString((int) x); return((CString &) *this); }
	__forceinline CString & operator >> (DWORD x)				{ StartString((unsigned int) x); return((CString &) *this); }
	__forceinline CString & operator >> (double x2)			    { iPlace = 0; AddDouble(x2); return((CString &) *this); }

	char * operator * () { return (char *) s; };
	const char * str() { return s; };
	char * c_str() { return s; };
	const char * cc_str() { return (const char *)  s; };
	char * GetBuffer() { return s; };
	bool isEmpty(){ return  s && *s ? false : true; };\

    /// <summary>
    /// Returns whether CString object is valid or not.  If a memory allocation error occurs, the string will be reset to 
    /// a stack-based string set to 300 bytes in length.
    /// This can be used after requesting memory for the string to determine if the string is still valid.
    /// </summary>
    /// <returns></returns>
    __forceinline bool isValid(){ return !m_bInvalid; }

	char * operator * (int x) { return(Return(x)); }
//	char * operator * (float x) { return(Return((int) x)); }
//	CString & operator = (char * x)			{ if (x == s) return *this; ClearString(); return *this << x; }
	CString & operator = (const char * x)	{ if (x == s) return *this; ClearString(); return *this << x; }
	CString & operator = (std::string & x)	{	ClearString(); return *this << x; }
	CString & operator = (const CString & x)		{	ClearString(); return *this << x; }
	CString & operator = (int x)			{	ClearString(); return *this << x; }
	CString & operator = (char x)			{	ClearString(); return *this << x; }
	CString & operator = (unsigned int x)	{	ClearString(); return *this << x; }
	CString & operator = (DWORD x)			{	ClearString(); return *this << x; }

	operator const char * () const { return (const char *) s; }
	operator char * () const { return (char *) s; }
	
    /// <summary>
    /// Copies the character string into the current CString object.
    /// <para></para>&#160;&#160;&#160;
    /// Note: This function replaces the current data in the string with the incoming string.
    /// If more memory is needed it is created, but is not reduce from the current memory size.
    /// <para></para>&#160;&#160;&#160;
    /// See: AppendString() to add to the current memory string rather than replacing it. 
    /// <para></para>&#160;&#160;&#160;
    /// Note: When copying an entire string, you can simply assign the string to the string object, i.e. MyString = "Hello World"
    /// <para></para>
    /// Use iCount to set the maximum characters to count or the first end of string (0) encountered, whichever comes first. Omit iCount to stop on first 0. 
    /// </summary>
    /// <param name="sString">String to add onto the current CString Object</param>
    /// <param name="iCount">Count of charatcters to copy.  Omit or set to 0 to copy entire string.</param>
    /// <returns></returns>
    CString & CopyString(const char * sString,int iCount = 0); 
    
    /// <summary>
    /// Adds the character string to the current CString object.
    /// <para></para>&#160;&#160;&#160;
    /// If more memory is needed it is created automtically in blocks of 1024 bytes.
    /// <para></para>&#160;&#160;&#160;
    /// See: CopyString() to replace the CString object with a string (or just directly assign it).
    /// To append large amounts of data without constantly re-allocating memory, use AppendBlock().
    /// <para></para>
    /// Use iCount to set the maximum characters to count or the first end of string (0) encountered, whichever comes first. Omit iCount to stop on first 0. 
    /// </summary>
    /// <param name="sString">String to place into the current CString Object</param>
    /// <param name="iCount">Count of charatcters to copy.  Omit or set to 0 to copy entire string.</param>
    /// <returns></returns>
    CString & AppendString(const char * sString,int iCount = 0); 

    /// <summary>
    /// Adds the character string to the current CString object, allocating memory 
    /// to the nearest block size to reduce memory allocations.
    /// <para></para>-->This function is the same as AppendString() except that it allocates in specified blocks, rather than
    /// the default block size of 1024 bytes. 
    /// 
    /// <para></para>&#160;&#160;&#160;
    /// If more memory is needed it is created automtically.
    /// <para></para>&#160;&#160;&#160;
    /// See: CopyString() to replace the CString object with a string (or just directly assign it).
    /// To append large amounts of data without constantly re-allocating memory, use AppendBlock().
    /// <para></para>
    /// Use iCount to set the maximum characters to count or the first end of string (0) encountered, whichever comes first. Omit iCount to stop on first 0. 
    /// </summary>
    /// <param name="sString">String to place into the current CString Object</param>
    /// <param name="iCount">Count of charatcters to copy.  Omit or set to 0 to copy entire string.</param>
    /// <returns></returns>
    CString & AppendBlock(const char * sString,int iBlockSize,int iCount = 0);

    /// <summary>
    /// Sets the allocation block size when new memory is allocated. 
    /// <para></para>&#160;&#160;&#160;
    /// As new memory is allocated, it is allocated in blocks or chunks of the block size. 
    /// The default value is 1024 bytes, and may be set to any value greater than 0.
    /// </summary>
    /// <param name="iBlockSize">New Block Size</param>
    /// <returns>TRUE if block size was reset. FALSE if blocksize was rejected (i.e. less than 0 or too large)</returns>
    bool SetBlockSize(int iBlockSize);

    /// <summary>
    /// Returns current blocks size for new memory allocation.
    /// <para></para>&#160;&#160;&#160;
    /// As new memory is allocated, it is allocated in blocks or chunks of the block size. 
    /// The default value is 1024 bytes, and may be set to any value greater than 0.
    /// </summary>
    /// <returns>Current allocation block size</returns>
    int GetBlockSize(); 

    /// <summary>
    /// Re-evaluates the length of the string in memory.  This can be used when the char * array is modified directly to let CString() re-determine
    /// the length of the data.
    /// <para></para>&#160;&#160;&#160;
    /// This sets the length at the first 0 in the data.  It does not modify the size of memory. 
    /// </summary>
    /// <returns>Length of string in memory (i.e. first 0 encountered).  Returns 0 if length is 0 or if there is an error</returns>
    int ReCalc();

    /// <summary>
    /// Adds a character to the string in memory.  Reallocates memory if required to enlarge string.
    /// <para></para>&#160;&#160;&#160;
    /// note This is the same as using "MySrtring << cChar".
    /// </summary>
    /// <returns>Index to end of string after adding character</returns>
    __forceinline int AddChar(const char * cChar) { *this << cChar; return iPlace; };

	void Init();

	~CString()
	{
		if (sAlloc) free(sAlloc);
	}
	CString() 
	{ 
		Init();
	}
	CString(int iMem)
	{
		AllocateMem(iMem);
	}

	CString(const char * sString) 
	{
		Init();
		_AddString((char *) sString);  
	}
	CString(const wchar_t * sString)
	{
		Init();
		_AddString((wchar_t *) sString);
	}
	CString(const CString &p2);

    CString(CString && p2) noexcept;
  
    /// <summary>
    /// Returns pointer to start of char * memory.  Memory is not allocated until the string in memory is greater than 300 bytes (kDefaultStackSize). 
    /// <para></para>&#160;&#160;&#160;
    /// This returns the start of current memory, which may be allocated or still on the stack of the string size has not exceeded 300 bytes.
    /// <para></para>
    /// NOTE: This is the same as using *CString.  For example, with a CString named MyString *MyString returns the same value.  
    /// <para></para>
    /// --> Most functions that take a char * value can simply be passed the CString (i.e. simply 'MyString'). For printf("%s") use *MyString or GetPointer().
    /// </summary>
    /// <returns>Start of char * memory (either stack memory, or allocated memory of string has grown larger than 300 bytes</returns>
    __forceinline char * GetPointer() { return sAlloc ? sAlloc : s; }

    /// <summary>
    /// Returns the current pointer value, representing the end of the string.   This is a fast method to obtain the length. However, If the 
    /// string has been manupulated directly, this can be inaccurate.  
    /// <para></para>&#160;&#160;&#160;
    /// For simple uses to get the length of the string (the same as strlen()), use GetLength().  Use GetIndex() to return the current memory pointer.  If the CString()
    /// data has not been manipulated directly, this is the same as using GetLength() or strlen().  strlen(cstring) can also be used. 
    /// <para></para>
    /// For a dymanically calculated (i.e. rr-calculated) length, use GetLength() which is the same as performing strlen(), and will return the length of the string by calculating it directly.
    /// </summary>
    /// <returns>Index to next byte in memory (null-terminated part of string)</returns>
    __forceinline int GetIndex() { return iPlace; };

    /// <summary>
    /// Calculates the length of the string in memory, performing the same action as strlen().
    /// <para></para>&#160;&#160;&#160;
    /// This also calls ReCalc() to set the current pointer at the first encountered 0.  For uses that manupulate the string, and to return the current memory pointer, use GetIndex()
    /// <para></para>strlen() can be used directly, such as strlen(cstring).
    /// </summary>
    /// <returns>Length of fist continues, null-terminated string in memory (i.e. strlen())</returns>
    int GetLength();

	/// <summary>
	/// Returns the size of memory allocated.  The minimum size is 300 bytes.   Memory is only allocated when the size is over 300 bytes.  Otherwise, memory is on the stack (i.e. when the value is 300).
    /// See kDefaultStackSize in CString.h for minimum stack size. 
	/// </summary>
	/// <returns>size of memory allocated or 300 if no memory is allocated (i.e. the stack size)</returns>
	int getMemSize();

    /// <summary>
	/// Allocates memory for the CString object.  If the memory required is less than the current memory, memory is not reduced.
    /// <para></para>&#160;&#160;&#160;
    /// By default, 300 bytes is used for stack space, and memory is only allocated when the amount needed exceeds this value.  If Memory
    /// size requested is less than 300 bytes, the request is ignored.
    /// <para></para>
    /// By default, a 0x00 is placed at the beginning of the allocation.  if bResetMem = true, this does not occur so that memory may be used to add onto strings. If the 
    /// current string has not been used previously, the 0 is placed regardless.
	/// </summary>
	/// <param name="iMemSize">= Amount of memory requested (not including null-termination)</param>
	/// <param name="bResetMem">= when TRUE (default), sets a zero at the beginning of memory.  When FALSE, allocate mem acts as a reallocation for string additions, not resetting the memory.</param>
	/// <returns></returns>
	bool AllocateMem(int iMemSize,bool bResetMem = true);
	void ClearString()
	{
		iPlace = 0; 
		sStatic[0] = 0;
		if (sAlloc) *sAlloc = 0;
	}
  
	char * UnEmptyStr()  { return (*s) ? s : nullptr; }
	char * PureStr()  { return (*s) ? s : nullptr; }

    const char * printf(const char * Format,...);
// __Sandbox__Except__ deprecated (for now)
//
//#ifdef __Sandbox__Except__
    const char * __printf(const char * Format,...);
//#endif

};


class CStringW
{
public:
    struct csFloatType
    {
        const char * sFloatStyle;
    };
private:
    static constexpr const char * kDefaultFloatStyle = "%g";
    static constexpr int kDefaultStackSize = 300;
	int m_iMaxSize		= kDefaultStackSize; 
	int m_iMinAllocSize	= 1024;
	int m_iAllocSize;
	wchar_t * s;
	wchar_t sStatic[kDefaultStackSize+1];
    char sFloatStyle[10];   // String for the float style, to override the default

	wchar_t * sAlloc;
	int iPlace;
    bool bDefaultFloatStyle;
    void SetFloatStyle(csFloatType csStyle);

    bool m_bInvalid = false;    // Gets set to true on memory allocation errors.  Use isValid() to check
	void StartString(wchar_t * sString); 
	void StartString(char * sString); 
	void StartString(int iValue); 
	void StartString(char cValue); 
	void StartString(wchar_t cValue); 
	void StartString(unsigned int uiValue); 
	void _AddString(wchar_t * sString); 
	void _AddString(char * sString); 
	void AddNumber(int x); 
	void AddNumber(unsigned int x); 
    void AddChar(char x);
    void AddCharW(wchar_t x);
    void AddDouble(double x2);
  
public:
	wchar_t * Return(int x);

    // CStringW::fs() -- Set the floating-point output style. 
    //
    // This can be used via streaming, i.e. CStringW() << "This is a number " << fs("%.10f") << MyNumber; 
    // It can be used anywhere or anytime with the current CStringW(), but does not take effect for numbers preceding the 
    // fs() call. 
    //
    // Note: When using the default style, 0 is represented as "0" and trailing 0's are removed.
    // Setting the float style, this no longer occurs to support the new style.  This also means that setting the style
    // to the same string as the default style will also disable the post-formatting.
    //
    // Use fs() to restore the default style. 
    //
    // Note: fs() takes a char value, not wchar_t -- i.e. fs(".4f") works, but not fs(L".4f");
    //
    CStringW & fs(const char * sStyle = nullptr) { SetFloatStyle({sStyle}); return *this; }

	CStringW & operator << (std::string & x)	{ _AddString((wchar_t *) x.c_str()); return((CStringW &) *this); }
	CStringW & operator << (wchar_t * x)		{ _AddString(x); return((CStringW &) *this); }
	CStringW & operator << (const wchar_t * x)	{ _AddString((wchar_t *) x); return((CStringW &) *this); }
	CStringW & operator << (char * x)			{ _AddString(x); return((CStringW &) *this); }
	CStringW & operator << (const char * x)		{ _AddString((char *) x); return((CStringW &) *this); }
	CStringW & operator << (char x)				{ AddChar(x); return((CStringW &) *this); }
	CStringW & operator << (wchar_t x)			{ AddCharW(x); return((CStringW &) *this); }
	CStringW & operator << (int x)				{ AddNumber(x); return((CStringW &) *this); }
	CStringW & operator << (unsigned int x)		{ AddNumber((int) x); return((CStringW &) *this); }
	CStringW & operator << (DWORD x)			{ AddNumber((unsigned int) x); return((CStringW &) *this); }

	CStringW & operator >> (std::string & x)	{ StartString((wchar_t *) x.c_str()); return((CStringW &) *this); }
	CStringW & operator >> (wchar_t * x)		{ StartString(x); return((CStringW &) *this); }
	CStringW & operator >> (const wchar_t * x)	{ StartString((wchar_t *) x); return((CStringW &) *this); }
	CStringW & operator >> (char * x)			{ StartString(x); return((CStringW &) *this); }
	CStringW & operator >> (const char * x)		{ StartString((char *) x); return((CStringW &) *this); }
	CStringW & operator >> (char x)				{ StartString(x); return((CStringW &) *this); }
	CStringW & operator >> (wchar_t x)			{ StartString(x); return((CStringW &) *this); }
	CStringW & operator >> (int x)				{ StartString(x); return((CStringW &) *this); }
	CStringW & operator >> (unsigned int x)		{ StartString((int) x); return((CStringW &) *this); }
	CStringW & operator >> (DWORD x)			{ StartString((unsigned int) x); return((CStringW &) *this); }


//	CDevString & operator << (COLORREF x) { AddNumber((int) x); return((CDevString &) *this); }
	wchar_t * operator * () { return (wchar_t *) s; };

	CStringW & operator << (double x2) {  AddDouble(x2); return((CStringW &) *this); }
	CStringW & operator << (csFloatType csft)	{ SetFloatStyle(csft); return *this; }
	CStringW & operator >> (double x2) { iPlace = 0; AddDouble(x2); return((CStringW &) *this); }
	wchar_t * operator * (int x) { return(Return(x)); }
//	char * operator * (float x) { return(Return((int) x)); }
	CStringW & operator = (wchar_t * x)			{ if (x == s) return *this;	ClearString();	return *this << x; }
	CStringW & operator = (const wchar_t * x)	{ if (x == s) return *this;	ClearString();	return *this << (wchar_t *) x; }

	CStringW & operator = (char * x)			{  ClearString();	return *this << x; }
	CStringW & operator = (const char * x)		{  ClearString();	return *this << (char *) x; }
	CStringW & operator = (std::string & x)	    {	ClearString();	return *this << x; }
	CStringW & operator = (char x)			    {	ClearString();	return *this << x; }
	CStringW & operator = (wchar_t x)			{	ClearString();	return *this << x; }
	CStringW & operator = (int x)			    {	ClearString();	return *this << x; }
	CStringW & operator = (unsigned int x)	    {	ClearString();	return *this << x; }
	CStringW & operator = (DWORD x)			    {	ClearString();	return *this << x; }

	operator const wchar_t * () const { return (const wchar_t *) s; }
	operator wchar_t * () const { return (wchar_t *) s; }
	void Init();
	~CStringW()
	{
		if (sAlloc) free(sAlloc);
	}
	CStringW() 
	{ 
		Init();
	}
    CStringW(CStringW && p2) noexcept;

	CStringW(const wchar_t * sString) 
	{
		Init();
		_AddString((wchar_t *) sString);  
	}
		CStringW(const char * sString) 
	{
		Init();
		_AddString((char *) sString);  
	}

	CStringW(const CStringW &p2);

	int getMemSize()
	{
		return m_iAllocSize ? m_iAllocSize : m_iMaxSize;
	}
	bool AllocateMem(int iMemSize);
	void ClearString()
	{
		iPlace = 0; 
		sStatic[0] = 0;
		if (sAlloc) *sAlloc = 0;
	}
  
	wchar_t * UnEmptyStr()  { return (*s) ? s : nullptr; }
	bool isEmpty(){ return  s && *s ? false : true; };


};
}; // namespace Sage
#endif	// _CSageString_H_