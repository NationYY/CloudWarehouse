#pragma once
class CFuncCommon
{
public:
	CFuncCommon();
	~CFuncCommon();
	//static int EncodeConvert(char *from_charset, char *to_charset, char *inbuf, size_t inlen, char *outbuf, size_t outlen);
	static std::string Double2String(double value, int decimal);
	static std::wstring Double2WString(double value, int decimal);
	static bool CheckEqual(double a, double b);
	static char* ToString(unsigned __int64 number);
	static char* ToString(__int64 number);
	static char* ToString(int number);
	static char* ToString(unsigned int number);
	static double Round(double value, int decimal);
	static std::string FormatDateStr(__int64 time);
	static std::string FormatTimeStr(__int64 time);
	static void GetAllFileInDirectory(const char* szPath, std::set<std::string>& setFiles);
	static void GetAllWFileInDirectory(const wchar_t* szPath, std::set<std::wstring>& setFiles);
	static std::string LocaltimeToISO8601(time_t time);
	static time_t ISO8601ToTime(std::string& time);
	static char* GenUUID();
	static time_t ToTime(const char *sz);
	static int crc32(const unsigned char *buf, unsigned int size);

	static std::string WString2String(const wchar_t* wchar);
	static std::wstring String2WString(const char* cchar);

	static bool ParseKeyWStringInt(std::wstring src, map_key_wstring_val_int &out, const wchar_t* splitChar = L";", const wchar_t* assignChar = L"@");

	static void GetFiles(string path, vector<string>& files);
	static void Replace(std::wstring& strContent, std::wstring strReplace, std::wstring strDest);

public:
	static bool parse_pairs(std::wstring src, vec_wvals &out, const wchar_t * de = L";");
	static bool parse_key_val(std::wstring src, map_key_wstring_val_int &out, const wchar_t* assignChar = L"@");
	static void split(const std::wstring& s, const std::wstring& match, split_wstr_vec& out, bool removeEmpty = true, bool fullMatch = false);
};

