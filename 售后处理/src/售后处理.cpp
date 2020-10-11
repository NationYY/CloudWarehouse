// 售后处理.cpp : 定义控制台应用程序的入口点。
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

std::string WString2String(const wchar_t* wchar)
{
	char * _char;
	int len = WideCharToMultiByte(CP_ACP, 0, wchar, wcslen(wchar), NULL, 0, NULL, NULL);
	_char = new char[len + 1];
	WideCharToMultiByte(CP_ACP, 0, wchar, wcslen(wchar), _char, len, NULL, NULL);
	_char[len] = '\0';
	std::string value = _char;
	delete[] _char;
	return value;
}

struct sInData
{
	int good;
	int bad;
	sInData()
	{
		memset(this, 0, sizeof(sInData));
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	std::wcout.imbue(std::locale("chs"));
	std::wcin.imbue(std::locale("chs"));
	map<wstring, sInData> mapInData;
	{
		BasicExcel inDetailExcel;
		if(!inDetailExcel.Load("入库明细账.xls"))
		{
			THROW_ERROR(L"入库明细账 加载失败");
		}
		BasicExcelWorksheet* inDetailSheet = inDetailExcel.GetWorksheet(L"Sheet1");
		if(inDetailSheet)
		{
			size_t maxRows = inDetailSheet->GetTotalRows();
			size_t maxCols = inDetailSheet->GetTotalCols();

			int danHao = -1;
			int isGood = -1;
			int cnt = -1;
			for(size_t c = 0; c < maxCols; ++c)
			{
				BasicExcelCell* cell = inDetailSheet->Cell(0, c);

				std::wstring strTitle = cell->GetWString();
				if(strTitle == L"OMS单号")
					danHao = c;
				else if(strTitle == L"是否正品")
					isGood = c;
				else if(strTitle == L"数量")
					cnt = c;
			}
			if(danHao == -1 || isGood == -1 || cnt == -1)
			{
				THROW_ERROR(L"入库明细账 有标题未找到");
			}
			for(size_t r = 1; r < maxRows; ++r)
			{
				const wchar_t* _pStr = NULL;
				wstring _strDanHao;
				wstring _strGood;
				int _cnt;
				SHEET_CELL_STRING(inDetailSheet, r, danHao, _strDanHao);
				SHEET_CELL_STRING(inDetailSheet, r, isGood, _strGood);
				SHEET_CELL_INT(inDetailSheet, r, cnt, _cnt);
				map<wstring, sInData>::iterator it = mapInData.find(_strDanHao);
				if(it != mapInData.end())
				{
					if(_strGood == L"正品")
						it->second.good += _cnt;
					else if(_strGood == L"残品")
						it->second.bad += _cnt;
				}
				else
				{
					if(_strGood == L"正品")
						mapInData[_strDanHao].good += _cnt;
					else if(_strGood == L"残品")
						mapInData[_strDanHao].bad += _cnt;
				}
			}
		}
	}
	map<wstring, wstring> mapChange;
	{
		BasicExcel changeExcel;
		if(!changeExcel.Load("销售退换单.xls"))
		{
			THROW_ERROR(L"销售退换单 加载失败");
		}
		BasicExcelWorksheet* changeSheet = changeExcel.GetWorksheet(L"Sheet1");
		if(changeSheet)
		{
			size_t maxRows = changeSheet->GetTotalRows();
			size_t maxCols = changeSheet->GetTotalCols();

			int danHao = -1;
			int zhuangtai = -1;
			for(size_t c = 0; c < maxCols; ++c)
			{
				BasicExcelCell* cell = changeSheet->Cell(0, c);
				std::wstring strTitle = cell->GetWString();
				if(strTitle == L"OMS单号")
					danHao = c;
				else if(strTitle == L"状态")
					zhuangtai = c;
			}
			if(danHao == -1 || zhuangtai == -1)
			{
				THROW_ERROR(L"销售退换单 有标题未找到");
			}
			for(size_t r = 1; r < maxRows; ++r)
			{
				const wchar_t* _pStr = NULL;
				wstring _strDanHao;
				wstring _zhuangtai;
				SHEET_CELL_STRING(changeSheet, r, danHao, _strDanHao);
				SHEET_CELL_STRING(changeSheet, r, zhuangtai, _zhuangtai);
				mapChange[_strDanHao] = _zhuangtai;
			}
		}
	}
	wstring fileName;
	wstring pageName;
	wstring coleName;
	wcout<<L"请输入售后单名称"<<endl;
	wcin>>fileName;
	fileName += L".xls";
	wcout<<L"请输入售后单分页名称"<<endl;
	wcin>>pageName;
	wcout<<L"请输入售后单OMS单号列名称" << endl;
	wcin>>coleName;
	string _fileName = WString2String(fileName.c_str());
	
	{
		BasicExcel shouhouExcel;
		shouhouExcel.Load(_fileName.c_str());
		int zhengPinCol;
		int canPinCol;
		int beiZhuCol;
		BasicExcelWorksheet* shouhouSheet = shouhouExcel.GetWorksheet(pageName.c_str());
		if(shouhouSheet)
		{
			size_t maxRows = shouhouSheet->GetTotalRows();
			size_t maxCols = shouhouSheet->GetTotalCols();
			zhengPinCol = maxCols;
			canPinCol = maxCols + 1;
			beiZhuCol = maxCols + 2;
			//load tile
			int colNumber = -1;
			bool bZhengPinColFix = false;
			bool bCanpinColFix = false;
			bool bBeiZhuColFix = false;
			for(size_t c = 0; c < maxCols; ++c)
			{
				BasicExcelCell* cell = shouhouSheet->Cell(0, c);
				const wchar_t* _titile = cell->GetWString();
				if(_titile)
				{
					std::wstring strTitle = _titile;

					if(strTitle == coleName)
						colNumber = c;
					else if(strTitle == L"正品")
					{
						bZhengPinColFix = true;
						zhengPinCol = c;
					}
					else if(strTitle == L"残品")
					{
						bCanpinColFix = true;
						canPinCol = c;
					}
					else if(strTitle == L"核对备注")
					{
						bBeiZhuColFix = true;
						beiZhuCol = c;
					}
				}
			}
			if(colNumber == -1)
			{
				wchar_t szBuffer[128] = { 0 };
				wsprintfW(szBuffer, L"售后单有标题未找到");
				THROW_ERROR(szBuffer);
			}
			if(!bZhengPinColFix)
				shouhouSheet->Cell(0, maxCols)->SetWString(L"正品");
			if(!bCanpinColFix)
				shouhouSheet->Cell(0, maxCols+1)->SetWString(L"残品");
			if(!bBeiZhuColFix)
				shouhouSheet->Cell(0, maxCols+2)->SetWString(L"核对备注");

			for(size_t r = 1; r < maxRows; ++r)
			{
				const wchar_t* _pStr = NULL;
				wstring danhao;
				SHEET_CELL_STRING(shouhouSheet, r, colNumber, danhao);
				if(danhao != L"")
				{
					map<wstring, sInData>::iterator itIn = mapInData.find(danhao);
					if(itIn != mapInData.end())
					{
						shouhouSheet->Cell(r, zhengPinCol)->SetInteger(itIn->second.good);
						shouhouSheet->Cell(r, canPinCol)->SetInteger(itIn->second.bad);
						continue;
					}
					map<wstring, wstring>::iterator itChange = mapChange.find(danhao);
					if(itChange == mapChange.end())
					{
						shouhouSheet->Cell(r, beiZhuCol)->SetWString(L"仓库无此单");
					}
					else
					{
						if(itChange->second == L"已取消")
							shouhouSheet->Cell(r, beiZhuCol)->SetWString(L"已取消");
					}
				}

			}
		}
		else
		{
			THROW_ERROR(L"读取售后单失败");
		}
		shouhouExcel.Save();
	}
	return 0;
}

