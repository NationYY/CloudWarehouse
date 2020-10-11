// �ۺ���.cpp : �������̨Ӧ�ó������ڵ㡣
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
		if(!inDetailExcel.Load("�����ϸ��.xls"))
		{
			THROW_ERROR(L"�����ϸ�� ����ʧ��");
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
				if(strTitle == L"OMS����")
					danHao = c;
				else if(strTitle == L"�Ƿ���Ʒ")
					isGood = c;
				else if(strTitle == L"����")
					cnt = c;
			}
			if(danHao == -1 || isGood == -1 || cnt == -1)
			{
				THROW_ERROR(L"�����ϸ�� �б���δ�ҵ�");
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
					if(_strGood == L"��Ʒ")
						it->second.good += _cnt;
					else if(_strGood == L"��Ʒ")
						it->second.bad += _cnt;
				}
				else
				{
					if(_strGood == L"��Ʒ")
						mapInData[_strDanHao].good += _cnt;
					else if(_strGood == L"��Ʒ")
						mapInData[_strDanHao].bad += _cnt;
				}
			}
		}
	}
	map<wstring, wstring> mapChange;
	{
		BasicExcel changeExcel;
		if(!changeExcel.Load("�����˻���.xls"))
		{
			THROW_ERROR(L"�����˻��� ����ʧ��");
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
				if(strTitle == L"OMS����")
					danHao = c;
				else if(strTitle == L"״̬")
					zhuangtai = c;
			}
			if(danHao == -1 || zhuangtai == -1)
			{
				THROW_ERROR(L"�����˻��� �б���δ�ҵ�");
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
	wcout<<L"�������ۺ�����"<<endl;
	wcin>>fileName;
	fileName += L".xls";
	wcout<<L"�������ۺ󵥷�ҳ����"<<endl;
	wcin>>pageName;
	wcout<<L"�������ۺ�OMS����������" << endl;
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
					else if(strTitle == L"��Ʒ")
					{
						bZhengPinColFix = true;
						zhengPinCol = c;
					}
					else if(strTitle == L"��Ʒ")
					{
						bCanpinColFix = true;
						canPinCol = c;
					}
					else if(strTitle == L"�˶Ա�ע")
					{
						bBeiZhuColFix = true;
						beiZhuCol = c;
					}
				}
			}
			if(colNumber == -1)
			{
				wchar_t szBuffer[128] = { 0 };
				wsprintfW(szBuffer, L"�ۺ��б���δ�ҵ�");
				THROW_ERROR(szBuffer);
			}
			if(!bZhengPinColFix)
				shouhouSheet->Cell(0, maxCols)->SetWString(L"��Ʒ");
			if(!bCanpinColFix)
				shouhouSheet->Cell(0, maxCols+1)->SetWString(L"��Ʒ");
			if(!bBeiZhuColFix)
				shouhouSheet->Cell(0, maxCols+2)->SetWString(L"�˶Ա�ע");

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
						shouhouSheet->Cell(r, beiZhuCol)->SetWString(L"�ֿ��޴˵�");
					}
					else
					{
						if(itChange->second == L"��ȡ��")
							shouhouSheet->Cell(r, beiZhuCol)->SetWString(L"��ȡ��");
					}
				}

			}
		}
		else
		{
			THROW_ERROR(L"��ȡ�ۺ�ʧ��");
		}
		shouhouExcel.Save();
	}
	return 0;
}

