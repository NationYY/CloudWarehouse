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
	wstring strShouJianRen;
	wstring strShouJianRenDianHua;
	wstring strShouJianRedDiZhi;
	wstring strBeiZhu;
	std::map<std::wstring, int> mapGoodsInfo;
};
std::map<wstring, SWeightInfo> mapWeighInfo;
void LoadConfig()
{
	mapWeighInfo.clear();
	for(int i = 0; i < 200; ++i)
	{
		SWeightInfo info;
		wchar_t szBuffer[128] = { 0 };
		wsprintfW(szBuffer, L"name%d", i + 1);
		GetPrivateProfileString(L"weight_info", szBuffer, L"", info.szName, 128, L"./config.ini");
		if(info.szName == L"")
		{
			wsprintfW(szBuffer, L"finish cnt %d", i + 1);
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
}

int _tmain(int argc, _TCHAR* argv[])
{
	std::wcout.imbue(std::locale("chs")); 
	LoadConfig();

	std::map<wstring, SDingDanInfo> mapDingDanInfo;
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
			std::map<std::wstring, int>::iterator _it = it->second.mapGoodsInfo.find(strHuoPinMingCheng);
			if(_it == it->second.mapGoodsInfo.end())
				it->second.mapGoodsInfo[strHuoPinMingCheng] = nHuoPinCnt;
			else
				_it->second += nHuoPinCnt;
		}
	}

	{
		DeleteFile(L"./结果.xls");
		BasicExcel excel;
		excel.AddWorksheet(L"sheet1");
		BasicExcelWorksheet* sheet = excel.GetWorksheet(L"sheet1");
		if(sheet)
		{
			sheet->Cell(0, 0)->SetWString(L"货品名称");
			sheet->Cell(0, 1)->SetWString(L"物流编号");
			sheet->Cell(0, 2)->SetWString(L"收件人");
			sheet->Cell(0, 3)->SetWString(L"收件人地址");
			sheet->Cell(0, 4)->SetWString(L"收件人手机号");
			sheet->Cell(0, 5)->SetWString(L"重量");
			sheet->Cell(0, 6)->SetWString(L"箱数");
			sheet->Cell(0, 7)->SetWString(L"客服备注");
			int rowIndex = 1;
			std::map<wstring, SDingDanInfo>::iterator itB = mapDingDanInfo.begin();
			std::map<wstring, SDingDanInfo>::iterator itE = mapDingDanInfo.end();
			while(itB != itE)
			{
				wstring szName;
				double dZhongLiang = 0.0;
				bool bZhengXiang = true;
				int nXiangShu = 0;
				std::map<std::wstring, int>::iterator itGB = itB->second.mapGoodsInfo.begin();
				std::map<std::wstring, int>::iterator itGE = itB->second.mapGoodsInfo.end();
				while(itGB != itGE)
				{
					if(itGB !=  itB->second.mapGoodsInfo.begin())
						szName = szName + L";";
					wchar_t szBuffer[128] = {0};
					wsprintf(szBuffer, L"%s@%d", itGB->first.c_str(), itGB->second);
					szName = szName + szBuffer;

					std::map<wstring, SWeightInfo>::iterator itZL = mapWeighInfo.find(itGB->first);
reCheckWeight:
					if(itZL != mapWeighInfo.end())
					{
						if(itGB->second % itZL->second.pieceCnt == 0)
						{
							int nPieces = itGB->second/itZL->second.pieceCnt;
							nXiangShu += nPieces;
							dZhongLiang += nPieces*itZL->second.pieceWeight;
						}
						else
						{
							int nLastCnt = itGB->second % itZL->second.pieceCnt;
							if(itZL->second.eachWeight < 0.01)
							{
								wchar_t szBuffer[128] = { 0 };
								wsprintf(szBuffer, L"[%s] 缺少单瓶重量数据,请补充", itZL->first.c_str());
								THROW_ERROR(szBuffer);
								LoadConfig();
								itZL = mapWeighInfo.find(itGB->first);
								goto reCheckWeight;
							}
							else
							{
								int nPieces = itGB->second/itZL->second.pieceCnt;
								dZhongLiang += ((nLastCnt*itZL->second.eachWeight)+(nPieces*itZL->second.pieceWeight));
							}
							bZhengXiang = false;
						}
					}
					else
					{
						wchar_t szBuffer[128] = { 0 };
						wsprintf(szBuffer, L"[%s] 缺少重量数据, 请补充", itGB->first.c_str());
						THROW_ERROR(szBuffer);
						LoadConfig();
						itZL = mapWeighInfo.find(itGB->first);
						goto reCheckWeight;
					}
					++itGB;
				}
				sheet->Cell(rowIndex, 0)->SetWString(szName.c_str());
				sheet->Cell(rowIndex, 1)->SetWString(itB->first.c_str());
				sheet->Cell(rowIndex, 2)->SetWString(itB->second.strShouJianRen.c_str());
				sheet->Cell(rowIndex, 3)->SetWString(itB->second.strShouJianRedDiZhi.c_str());
				sheet->Cell(rowIndex, 4)->SetWString(itB->second.strShouJianRenDianHua.c_str());
				int nZhongLiang = (int)ceil(dZhongLiang);
				sheet->Cell(rowIndex, 5)->SetInteger(nZhongLiang);

				if(bZhengXiang)
					sheet->Cell(rowIndex, 6)->SetInteger(nXiangShu);
				else
					sheet->Cell(rowIndex, 6)->SetInteger(0);
				sheet->Cell(rowIndex, 7)->SetWString(itB->second.strBeiZhu.c_str());
				rowIndex++;
				++itB;
			}
		}
		excel.SaveAs("./结果.xls");
	}
	return 0;
}

