// 库存周转分析.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream> 
#include <fstream>
#include <stdio.h>
#include <string>
#include <windows.h>
#include <map>
#include "BasicExcel.hpp"
#include <iomanip>
#include "objbase.h"
#include <list>
#include <set>
#include <vector>

using namespace YCompoundFiles;
using namespace YExcel;
using namespace std;
#define THROW_ERROR(info) std::wcout<<info<<std::endl; system("pause");

#define SHEET_CELL_STRING(sheet, r, c, strOut) _pStr = sheet->Cell(r, c)->GetWString();\
if(_pStr)\
	strOut = _pStr;

#define SHEET_CELL_INT(sheet, r, c, nInt) nInt = sheet->Cell(r, c)->GetInteger();

#define DOUBLE_PRECISION 0.00000001

std::wstring String2WString(const char* cchar)
{
	wchar_t *_wchar;
	int len = MultiByteToWideChar(CP_ACP, 0, cchar, strlen(cchar), NULL, 0);
	_wchar = new wchar_t[len + 1];
	MultiByteToWideChar(CP_ACP, 0, cchar, strlen(cchar), _wchar, len);
	_wchar[len] = '\0';
	std::wstring value = _wchar;
	delete[] _wchar;
	return value;
}

std::wstring Double2WString(double value, int decimal)
{
	char szBuff[64] ={0};
	if(decimal == 0)
		sprintf(szBuff, "%d", (int)value);
	else if(decimal == 1)
		sprintf(szBuff, "%.2f", value);
	else if(decimal == 2)
		sprintf(szBuff, "%.3f", value);
	else if(decimal == 3)
		sprintf(szBuff, "%.4f", value);
	else if(decimal == 4)
		sprintf(szBuff, "%.5f", value);
	else if(decimal == 5)
		sprintf(szBuff, "%.6f", value);
	else if(decimal == 6)
		sprintf(szBuff, "%.7f", value);
	else if(decimal == 7)
		sprintf(szBuff, "%.8f", value);
	else if(decimal == 8)
		sprintf(szBuff, "%.9f", value);
	else if(decimal == 9)
		sprintf(szBuff, "%.10f", value);
	if(decimal > 0)
	{
		szBuff[strlen(szBuff)-1] = '\0';
		/*int nPos = strlen(szBuff)-1;
		while(szBuff[nPos] == '0')
		{
			if(szBuff[nPos-1] == '.')
				break;
			szBuff[nPos] = '\0';
			nPos = strlen(szBuff)-1;
			if(szBuff[nPos] == '.')
			{
				szBuff[nPos] = '\0';
				break;
			}
		}*/
	}
	std::wstring retValue = String2WString(szBuff);
	return retValue;
}

int _tmain(int argc, _TCHAR* argv[])
{
	std::map< std::wstring, int > m_mapRuKu;
	std::map< int, std::map< std::wstring, int > > m_mapChuKu;
	std::wcout.imbue(std::locale("chs")); 
	std::wcout<<L"输入起始月份:";
	int nStart = 0;
	std::wcin>>nStart;
	if(nStart < 1 || nStart > 12)
	{
		THROW_ERROR(L"起始月份错误");
	}
	std::wcout<<L"输入结束月份:";
	int nEnd = 0;
	std::wcin>>nEnd;
	if(nEnd < 1 || nEnd > 12)
	{
		THROW_ERROR(L"起始月份错误");
	}
	if(nEnd < nStart)
	{
		THROW_ERROR(L"月份范围错误");
	}
	BasicExcel ruKuExcel;
	if(!ruKuExcel.Load("../入库数据.xls"))
	{
		THROW_ERROR(L"入库数据 加载失败");
	}
	BasicExcelWorksheet* ruKuSheet = ruKuExcel.GetWorksheet(L"Sheet1");
	if(ruKuSheet)
	{
		size_t maxRows = ruKuSheet->GetTotalRows();
		size_t maxCols = ruKuSheet->GetTotalCols();

		int nHuoPinMingCheng = -1;
		int nShuLiang = -1;
		
		for(size_t c = 0; c < maxCols; ++c)
		{
			BasicExcelCell* cell = ruKuSheet->Cell(0, c);

			std::wstring strTitle = cell->GetWString();
			if(strTitle == L"货品名称")
				nHuoPinMingCheng = c;
			else if(strTitle == L"数量")
				nShuLiang = c;
		}
		if(nHuoPinMingCheng == -1 || nShuLiang == -1)
		{
			THROW_ERROR(L"入库数据 有标题未找到");
		}
		for(size_t r = 1; r < maxRows; ++r)
		{
			const wchar_t* _pStr = NULL;
			wstring strHuoPinMingCheng;
			int shuLiang = 0;
			SHEET_CELL_STRING(ruKuSheet, r, nHuoPinMingCheng, strHuoPinMingCheng);
			SHEET_CELL_INT(ruKuSheet, r, nShuLiang, shuLiang);
			m_mapRuKu[strHuoPinMingCheng] = shuLiang;
		}
	}
	for(int i=nStart; i<= nEnd; ++i)
	{
		BasicExcel chuKuExcel;

		char szBuffer[128] = { 0 };
		sprintf(szBuffer, "../%d月出库数据.xls", i);
		if(!chuKuExcel.Load(szBuffer))
		{
			wchar_t szBuffer[128] = { 0 };
			wsprintf(szBuffer, L"%d月出库数据 加载失败", i);
			THROW_ERROR(szBuffer);
		}
		BasicExcelWorksheet* ruKuSheet = chuKuExcel.GetWorksheet(L"Sheet1");
		if(ruKuSheet)
		{
			size_t maxRows = ruKuSheet->GetTotalRows();
			size_t maxCols = ruKuSheet->GetTotalCols();

			int nHuoPinMingCheng = -1;
			int nShuLiang = -1;

			for(size_t c = 0; c < maxCols; ++c)
			{
				BasicExcelCell* cell = ruKuSheet->Cell(0, c);

				std::wstring strTitle = cell->GetWString();
				if(strTitle == L"货品名称")
					nHuoPinMingCheng = c;
				else if(strTitle == L"数量")
					nShuLiang = c;
			}
			if(nHuoPinMingCheng == -1 || nShuLiang == -1)
			{
				wchar_t szBuffer[128] = { 0 };
				wsprintf(szBuffer, L"%d月出库数据 有标题未找到", i);
				THROW_ERROR(szBuffer);
			}
			for(size_t r = 1; r < maxRows; ++r)
			{
				const wchar_t* _pStr = NULL;
				wstring strHuoPinMingCheng;
				int shuLiang = 0;
				SHEET_CELL_STRING(ruKuSheet, r, nHuoPinMingCheng, strHuoPinMingCheng);
				SHEET_CELL_INT(ruKuSheet, r, nShuLiang, shuLiang);
				m_mapChuKu[i][strHuoPinMingCheng] = shuLiang;
			}
		}
	}
	{
		BasicExcel excel;
		excel.AddWorksheet(L"sheet1");
		BasicExcelWorksheet* sheet = excel.GetWorksheet(L"sheet1");
		if(sheet)
		{
			sheet->Cell(0, 0)->SetWString(L"货品名称");
			sheet->Cell(0, 1)->SetWString(L"总入库数量");
			sheet->Cell(0, 2)->SetWString(L"本周期月均出库数量");
			sheet->Cell(0, 3)->SetWString(L"剩余库存清零预计时间(月)");
			int nColBegin = 4;
			int nAddInex = 0;
			for(int i=nStart; i<=nEnd; ++i)
			{
				wchar_t szBuffer[128] = { 0 };
				wsprintf(szBuffer, L"%d月出库数量", i);
				sheet->Cell(0, nColBegin+nAddInex)->SetWString(szBuffer);
				nAddInex++;
			}
			int rowIndex = 1;
			std::map< std::wstring, int >::iterator itRKB = m_mapRuKu.begin();
			std::map< std::wstring, int >::iterator itRKE = m_mapRuKu.end();
			while(itRKB != itRKE)
			{
				sheet->Cell(rowIndex, 0)->SetWString(itRKB->first.c_str());
				sheet->Cell(rowIndex, 1)->SetInteger(itRKB->second);
				int nYF = 0;
				int nCKSL = 0;
				std::map< int, std::map< std::wstring, int > >::iterator itYB = m_mapChuKu.begin();
				std::map< int, std::map< std::wstring, int > >::iterator itYE = m_mapChuKu.end();
				while(itYB != itYE)
				{
					std::map< std::wstring, int >::iterator itCKB = itYB->second.find(itRKB->first);
					if(itCKB != itYB->second.end())
					{
						sheet->Cell(rowIndex, itYB->first-nStart+nColBegin)->SetInteger(itCKB->second);
						nYF++;
						nCKSL += itCKB->second;
					}
					++itYB;
				}
				if(nCKSL > 0)
				{
					int cnt = nCKSL / nYF;
					sheet->Cell(rowIndex, 2)->SetInteger(cnt);
					if(itRKB->second > nCKSL)
					{
						double dLastYF = double(itRKB->second - nCKSL) / double(cnt);
						sheet->Cell(rowIndex, 3)->SetWString(Double2WString(dLastYF + DOUBLE_PRECISION, 1).c_str());
					}
					else
					{
						sheet->Cell(rowIndex, 3)->SetWString(L"0");
					}
				}
				else
				{
					sheet->Cell(rowIndex, 2)->SetInteger(0);
					sheet->Cell(rowIndex, 3)->SetWString(L"0");
				}
				++itRKB;
				rowIndex++;
			}
		}
		char szBuffer[128] = { 0 };
		sprintf(szBuffer, "%d-%d月库存分析.xls", nStart, nEnd);
		excel.SaveAs(szBuffer);
	}
	return 0;
}

