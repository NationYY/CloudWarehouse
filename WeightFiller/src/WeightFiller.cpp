// WeightFiller.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream> 
#include <fstream>
#include <stdio.h>
#include <string>
#include <windows.h>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	wchar_t a[128];
	GetPrivateProfileString(L"weight_info", L"name1", L"", a, 128, L"./config.ini");
	return 0;
}

