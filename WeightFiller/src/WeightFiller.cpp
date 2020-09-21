// WeightFiller.cpp : 定义控制台应用程序的入口点。
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

struct SWeightInfo
{
	wchar_t szName[128];
	int pieceCnt;
	double pieceWeight;
	double eachWeight;
	SWeightInfo()
	{
		memset(this, 0, sizeof(SWeightInfo));
	}
};

struct SDingDanInfo
{
	wstring strWuLiuDanHao;
	double dWeight;
	int nBoxCnt;
	int nHuoPinShuLiang;
	wstring strHuoPinMingXi;
	wstring strShouJianRen;
	wstring strShouJianRenDianHua;
	wstring strShouJianRedDiZhi;
	wstring strBeiZhu;
	std::map<std::wstring, int> mapGoodsInfo;
};

int _tmain(int argc, _TCHAR* argv[])
{
	std::map<wstring, SWeightInfo> mapWeighInfo;
	std::map<wstring, SDingDanInfo> mapDingDanInfo;
	for(int i=0; i<200; ++i)
	{
		SWeightInfo info;
		wchar_t szBuffer[128] = { 0 };
		wsprintfW(szBuffer, L"name%d", i+1);
		GetPrivateProfileString(L"weight_info", szBuffer, L"", info.szName, 128, L"./config.ini");
		if(info.szName == L"")
		{
			wsprintfW(szBuffer, L"finish cnt %d", i+1);
			THROW_ERROR(szBuffer);
			break;
		}
		int nDefault = 0;
		wsprintfW(szBuffer, L"piece_cnt%d", i + 1);
		info.pieceCnt = GetPrivateProfileIntW(L"weight_info", szBuffer, nDefault, L"./config.ini");
		wchar_t szPieceWeight[128] = { 0 };
		wchar_t szEachWeight[128] = { 0 };
		wsprintfW(szBuffer, L"piece_weight%d", i + 1);
		GetPrivateProfileString(L"weight_info", szBuffer, L"", szPieceWeight, 128, L"./config.ini");
		wsprintfW(szBuffer, L"each_weight%d", i + 1);
		GetPrivateProfileString(L"weight_info", szBuffer, L"", szEachWeight, 128, L"./config.ini");
		info.pieceWeight = _wtof(szPieceWeight);
		info.eachWeight = _wtof(szEachWeight);
		mapWeighInfo[info.szName] = info;
	}
	BasicExcel saleDetailExcel;
	if(!saleDetailExcel.Load("销售出库明细.xls"))
	{
		THROW_ERROR(L"销售出库明细 加载失败");
	}
	BasicExcelWorksheet* saleDetailSheet = saleDetailExcel.GetWorksheet(L"Sheet1");
	if(saleDetailSheet)
	{
		size_t maxRows = saleDetailSheet->GetTotalRows();
		size_t maxCols = saleDetailSheet->GetTotalCols();

		int nHuoPinMingCheng = -1;
		int nWuLiuBianHao = -1;
		int nHuoPinZongShuLiang = -1;
		int nHuoPinShuLiang = -1;
		int nShouJianRen = -1;
		int nShouJianRenShouJi = -1;
		int nShouJianRenDiZhi = -1;
		int nBeiZhu = -1;
		for(size_t c = 0; c < maxCols; ++c)
		{
			BasicExcelCell* cell = saleDetailSheet->Cell(0, c);

			std::wstring strTitle = cell->GetWString();
			if(strTitle == L"货品名称")
				nHuoPinMingCheng = c;
			else if(strTitle == L"物流编号")
				nWuLiuBianHao = c;
			else if(strTitle == L"货品总数量")
				nHuoPinZongShuLiang = c;
			else if(strTitle == L"货品数量")
				nHuoPinShuLiang = c;
			else if(strTitle == L"收件人")
				nShouJianRen = c;
			else if(strTitle == L"收件人地址")
				nShouJianRenDiZhi = c;
			else if(strTitle == L"收件人手机号")
				nShouJianRenShouJi = c;
			else if(strTitle == L"客服备注")
				nBeiZhu = c;
		}
		if(nHuoPinMingCheng == -1 || nWuLiuBianHao == -1 || nHuoPinZongShuLiang == -1 || nHuoPinShuLiang == -1 || nShouJianRen == -1
			|| nShouJianRenShouJi == -1 || nShouJianRenDiZhi == -1 || nBeiZhu == -1)
		{
			THROW_ERROR(L"销售出库明细 有标题未找到");
		}
		for(size_t r = 1; r < maxRows; ++r)
		{
			const wchar_t* _pStr = NULL;
			wstring strWuLiuDanHao;
			SHEET_CELL_STRING(saleDetailSheet, r, nWuLiuBianHao, strWuLiuDanHao);
			std::map<wstring, SDingDanInfo>::iterator it = mapDingDanInfo.find(strWuLiuDanHao);
			if(it == mapDingDanInfo.end())
			{
				SDingDanInfo tempInfo;
				tempInfo.strWuLiuDanHao = strWuLiuDanHao;
				mapDingDanInfo[strWuLiuDanHao] = tempInfo;
				it = mapDingDanInfo.find(strWuLiuDanHao);
			}
			SHEET_CELL_INT(saleDetailSheet, r, nHuoPinZongShuLiang, it->second.nHuoPinShuLiang);
			SHEET_CELL_STRING(saleDetailSheet, r, nShouJianRen, it->second.strShouJianRen);

			SHEET_CELL_STRING(saleDetailSheet, r, nShouJianRenDiZhi, it->second.strShouJianRedDiZhi);
			SHEET_CELL_STRING(saleDetailSheet, r, nShouJianRenShouJi, it->second.strShouJianRenDianHua);
			SHEET_CELL_STRING(saleDetailSheet, r, nBeiZhu, it->second.strBeiZhu);
			wstring strHuoPinMingCheng;
			int nHuoPinCnt;
			SHEET_CELL_STRING(saleDetailSheet, r, nHuoPinMingCheng, strHuoPinMingCheng);
			SHEET_CELL_INT(saleDetailSheet, r, nHuoPinShuLiang, nHuoPinCnt);
			it->second.mapGoodsInfo[strHuoPinMingCheng] = nHuoPinCnt;
		}
	}
	return 0;
}

