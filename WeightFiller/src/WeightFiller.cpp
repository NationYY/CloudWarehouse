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
#include <shlwapi.h>

using namespace YCompoundFiles;
using namespace YExcel;
using namespace std;
#define THROW_ERROR(info) std::wcout<<info<<std::endl; system("pause");

#define SHEET_CELL_STRING(sheet, r, c, strOut) _pStr = sheet->Cell(r, c)->GetWString();\
if(_pStr)\
	strOut = _pStr;

#define SHEET_CELL_INT(sheet, r, c, nInt) nInt = sheet->Cell(r, c)->GetInteger();

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
	wstring strDaYinBeiZhu;
	std::map<std::wstring, int> mapGoodsInfo;
	wstring strZhuanJianZhuYi;
	SDingDanInfo()
	{
		strWuLiuDanHao = strShouJianRen = strShouJianRenDianHua = strShouJianRedDiZhi = strBeiZhu = strDaYinBeiZhu = strZhuanJianZhuYi = L"";
		dWeight = 0.0;
		nBoxCnt = nHuoPinShuLiang = 0;
	}
};

struct SWeightInfo
{
	wchar_t szName[128];
	int pieceCnt;
	double pieceWeight;
	double eachWeight;
	bool isPieceBox;
	wchar_t szShortName[128];
	SWeightInfo()
	{
		memset(this, 0, sizeof(SWeightInfo));
	}
};
std::map<wstring, SWeightInfo> mapWeighInfo;
std::map<wstring, wstring> mapPingTaiInfo;
std::map<wstring, wstring> mapDianPuInfo;
void LoadConfig();
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


void CreateExcel(wstring strWuLiuGongSi, std::map<wstring, SDingDanInfo>& mapDingDanInfo)
{
	std::map<wstring, int> mapAllCnt;
	BasicExcel excel;
	excel.AddWorksheet(L"sheet1");
	BasicExcelWorksheet* sheet = excel.GetWorksheet(L"sheet1");
	if(sheet)
	{
		sheet->Cell(0, 0)->SetWString(L"货品名称");
		sheet->Cell(0, 1)->SetWString(L"物流编号");
		sheet->Cell(0, 2)->SetWString(L"转件注意");
		sheet->Cell(0, 3)->SetWString(L"收件人");
		sheet->Cell(0, 4)->SetWString(L"收件人地址");
		sheet->Cell(0, 5)->SetWString(L"收件人手机号");
		sheet->Cell(0, 6)->SetWString(L"重量");
		sheet->Cell(0, 7)->SetWString(L"箱数");
		sheet->Cell(0, 8)->SetWString(L"不用管这列");
		sheet->Cell(0, 9)->SetWString(L"客服备注");
		int rowIndex = 1;
		std::map<wstring, SDingDanInfo>::iterator itB = mapDingDanInfo.begin();
		std::map<wstring, SDingDanInfo>::iterator itE = mapDingDanInfo.end();
		while(itB != itE)
		{
			wstring szName;
			wstring szBeiZhu;
			double dZhongLiang = 0.0;
			bool bZhengXiang = true;
			int nXiangShu = 0;
			std::map<std::wstring, int>::iterator itGB = itB->second.mapGoodsInfo.begin();
			std::map<std::wstring, int>::iterator itGE = itB->second.mapGoodsInfo.end();
			while(itGB != itGE)
			{
				if(itGB != itB->second.mapGoodsInfo.begin())
					szName = szName + L";";
				wchar_t szBuffer[128] = { 0 };
				wsprintf(szBuffer, L"%s@%d", itGB->first.c_str(), itGB->second);
				szName = szName + szBuffer;

				std::map<wstring, SWeightInfo>::iterator itZL = mapWeighInfo.find(itGB->first);
			reCheckWeight:
				if(itZL != mapWeighInfo.end())
				{
					if(!itZL->second.isPieceBox)
						bZhengXiang = false;
					if(itZL->second.pieceCnt != 0 && itGB->second % itZL->second.pieceCnt == 0)
					{
						int nPieces = itGB->second / itZL->second.pieceCnt;
						nXiangShu += nPieces;
						wchar_t szBuffer[128] = { 0 };
						if(strWuLiuGongSi == L"韵达")
						{
							wsprintf(szBuffer, L"i%s整%d", itZL->second.szShortName, nPieces);
							szBeiZhu += szBuffer;
							szBeiZhu += L"i";
						}
						else
						{
							wsprintf(szBuffer, L"%s整%d", itZL->second.szShortName, nPieces);
							szBeiZhu += szBuffer;
							szBeiZhu += L"|";
						}
						dZhongLiang += nPieces*itZL->second.pieceWeight;

						wsprintf(szBuffer, L"%s整件", itZL->second.szShortName);
						wstring __name = szBuffer;
						std::map<wstring, int>::iterator itAllCnt = mapAllCnt.find(__name);
						if(itAllCnt == mapAllCnt.end())
							mapAllCnt[__name] = nPieces;
						else
							itAllCnt->second += nPieces;
					}
					else
					{
						int nLastCnt = 0;
						if(itZL->second.pieceCnt != 0)
							nLastCnt = itGB->second % itZL->second.pieceCnt;
						else
							nLastCnt = itGB->second;
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
							int nPieces = 0;
							if(itZL->second.pieceCnt != 0)
								nPieces = itGB->second / itZL->second.pieceCnt;
							dZhongLiang += ((nLastCnt*itZL->second.eachWeight) + (nPieces*itZL->second.pieceWeight));
						}
						if(itZL->second.pieceCnt != 0 && itGB->second > itZL->second.pieceCnt)
						{
							int nPieces = itGB->second / itZL->second.pieceCnt;
							wchar_t szBuffer[128] = { 0 };
							if(strWuLiuGongSi == L"韵达")
							{
								wsprintf(szBuffer, L"i%s整%di%s散%d", itZL->second.szShortName, nPieces, itZL->second.szShortName, nLastCnt);
								szBeiZhu += szBuffer;
								szBeiZhu += L"i";
							}
							else
							{
								wsprintf(szBuffer, L"%s整%d|%s散%d", itZL->second.szShortName, nPieces, itZL->second.szShortName, nLastCnt);
								szBeiZhu += szBuffer;
								szBeiZhu += L"|";
							}
							

							wsprintf(szBuffer, L"%s整件", itZL->second.szShortName);
							wstring __name = szBuffer;
							std::map<wstring, int>::iterator itAllCnt = mapAllCnt.find(__name);
							if(itAllCnt == mapAllCnt.end())
								mapAllCnt[__name] = nPieces;
							else
								itAllCnt->second += nPieces;

							wsprintf(szBuffer, L"%s散%d", itZL->second.szShortName, nLastCnt);
							__name = szBuffer;
							itAllCnt = mapAllCnt.find(__name);
							if(itAllCnt == mapAllCnt.end())
								mapAllCnt[__name] = 1;
							else
								itAllCnt->second += 1;

						}
						else
						{
							wchar_t szBuffer[128] = { 0 };
							
							if(strWuLiuGongSi == L"韵达")
							{
								wsprintf(szBuffer, L"i%s散%d", itZL->second.szShortName, nLastCnt);
								szBeiZhu += szBuffer;
								szBeiZhu += L"i";
							}
							else
							{
								wsprintf(szBuffer, L"%s散%d", itZL->second.szShortName, nLastCnt);
								szBeiZhu += szBuffer;
								szBeiZhu += L"|";
							}

							wstring __name = szBuffer;
							std::map<wstring, int>::iterator itAllCnt = mapAllCnt.find(__name);
							if(itAllCnt == mapAllCnt.end())
								mapAllCnt[__name] = 1;
							else
								itAllCnt->second += 1;
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
			sheet->Cell(rowIndex, 0)->SetWString(szBeiZhu.c_str());
			sheet->Cell(rowIndex, 1)->SetWString(itB->first.c_str());
			sheet->Cell(rowIndex, 2)->SetWString(itB->second.strZhuanJianZhuYi.c_str());
			sheet->Cell(rowIndex, 3)->SetWString(itB->second.strShouJianRen.c_str());
			sheet->Cell(rowIndex, 4)->SetWString(itB->second.strShouJianRedDiZhi.c_str());
			sheet->Cell(rowIndex, 5)->SetWString(itB->second.strShouJianRenDianHua.c_str());
			int nZhongLiang = (int)ceil(dZhongLiang);
			sheet->Cell(rowIndex, 6)->SetInteger(nZhongLiang);

			if(bZhengXiang)
				sheet->Cell(rowIndex, 7)->SetInteger(nXiangShu);
			else
				sheet->Cell(rowIndex, 7)->SetInteger(0);
			sheet->Cell(rowIndex, 8)->SetWString(szName.c_str());
			wstring strBZ = itB->second.strBeiZhu;
			if(itB->second.strDaYinBeiZhu != L"")
			{
				if(strBZ != L"")
					strBZ += L"|";
				strBZ += itB->second.strDaYinBeiZhu;
			}
			sheet->Cell(rowIndex, 9)->SetWString(strBZ.c_str());
			rowIndex++;
			++itB;
		}
		wstring title = strWuLiuGongSi + L"货品汇总";
		sheet->Cell(rowIndex++, 0)->SetWString(title.c_str());
		std::map<wstring, int>::iterator __itB = mapAllCnt.begin();
		std::map<wstring, int>::iterator __itE = mapAllCnt.end();
		while(__itB != __itE)
		{
			sheet->Cell(rowIndex, 0)->SetWString(__itB->first.c_str());
			sheet->Cell(rowIndex, 1)->SetInteger(__itB->second);
			rowIndex++;
			++__itB;
		}
	}
	string cWL = WString2String(strWuLiuGongSi.c_str());
	cWL = "./结果-" + cWL+".xls";
	excel.SaveAs(cWL.c_str());
}

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


		wchar_t szPieceIsBox[128] = { 0 };
		wsprintfW(szBuffer, L"piece_is_box%d", i + 1);
		GetPrivateProfileString(L"weight_info", szBuffer, L"", szPieceIsBox, 128, L"./config.ini");
		if(wcscmp(szPieceIsBox, L"0") == 0)
			info.isPieceBox = false;
		else
			info.isPieceBox = true;

		wchar_t szShortName[128] = { 0 };
		wsprintfW(szBuffer, L"short_name%d", i + 1);
		GetPrivateProfileString(L"weight_info", szBuffer, L"", info.szShortName, 128, L"./config.ini");

		info.pieceWeight = _wtof(szPieceWeight);
		info.eachWeight = _wtof(szEachWeight);
		mapWeighInfo[info.szName] = info;
	}
	for(int i = 0; i < 50; ++i)
	{
		wchar_t szBuffer[128] = { 0 };
		wchar_t szInfo[256] = { 0 };
		wsprintfW(szBuffer, L"平台%d", i + 1);
		GetPrivateProfileString(L"base_info", szBuffer, L"", szInfo, 256, L"./config.ini");
		int nLen = wcslen(szInfo);
		if(nLen == 0)
			break;
		wchar_t szPingTai[128] = { 0 };
		wchar_t szMiaoShu[128] = { 0 };
		for(int i=0; i<nLen; ++i)
		{
			if(szInfo[i] == L';')
			{
				if(i == nLen-1)
					memcpy(szPingTai, szInfo, sizeof(wchar_t)*i);
				else
				{
					memcpy(szPingTai, szInfo, sizeof(wchar_t)*i);
					memcpy(szMiaoShu, szInfo+i+1, sizeof(wchar_t)*(nLen-i));
				}
				mapPingTaiInfo[szPingTai] = szMiaoShu;
			}
		}
	}
	for(int i = 0; i < 100; ++i)
	{
		wchar_t szBuffer[128] = { 0 };
		wchar_t szInfo[256] = { 0 };
		wsprintfW(szBuffer, L"店铺%d", i + 1);
		GetPrivateProfileString(L"base_info", szBuffer, L"", szInfo, 256, L"./config.ini");
		int nLen = wcslen(szInfo);
		if(nLen == 0)
			break;
		wchar_t szDianPu[128] = { 0 };
		wchar_t szPingTai[128] = { 0 };
		for(int i = 0; i < nLen; ++i)
		{
			if(szInfo[i] == L';')
			{
				if(i == nLen - 1)
					memcpy(szDianPu, szInfo, sizeof(wchar_t)*i);
				else
				{
					memcpy(szDianPu, szInfo, sizeof(wchar_t)*i);
					memcpy(szPingTai, szInfo + i + 1, sizeof(wchar_t)*(nLen - i));
				}
				mapDianPuInfo[szDianPu] = szPingTai;
			}
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	std::wcout.imbue(std::locale("chs")); 
	LoadConfig();
	std::map<wstring, SDingDanInfo> mapYDDingDanInfo;
	std::map<wstring, SDingDanInfo> mapZTDingDanInfo;
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
		int nWuLiuGongSi = -1;
		int nHuoPinZongShuLiang = -1;
		int nHuoPinShuLiang = -1;
		int nShouJianRen = -1;
		int nShouJianRenShouJi = -1;
		int nShouJianRenDiZhi = -1;
		int nBeiZhu = -1;
		int nDaYinBeiZhu = -1;
		int nDianPu = -1;
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
			else if(strTitle == L"打印备注")
				nDaYinBeiZhu = c;
			else if(strTitle == L"店铺")
				nDianPu = c;
			else if(strTitle == L"物流公司")
				nWuLiuGongSi = c;
		}
		if(nHuoPinMingCheng == -1 || nWuLiuBianHao == -1 || nHuoPinZongShuLiang == -1 || nHuoPinShuLiang == -1 || nShouJianRen == -1
			|| nShouJianRenShouJi == -1 || nShouJianRenDiZhi == -1 || nBeiZhu == -1 || nDaYinBeiZhu == -1 || nDianPu == -1 || nWuLiuGongSi == -1)
		{
			THROW_ERROR(L"销售出库明细 有标题未找到");
		}
		for(size_t r = 1; r < maxRows; ++r)
		{
			const wchar_t* _pStr = NULL;
			wstring strWuLiuDanHao;
			wstring strWuliuGongSi;
			SHEET_CELL_STRING(saleDetailSheet, r, nWuLiuGongSi, strWuliuGongSi);
			SHEET_CELL_STRING(saleDetailSheet, r, nWuLiuBianHao, strWuLiuDanHao);
			std::map<wstring, SDingDanInfo>::iterator it;
			if(strWuliuGongSi.find(L"中通") != wstring::npos)
			{
				it = mapZTDingDanInfo.find(strWuLiuDanHao);
				if(it == mapZTDingDanInfo.end())
				{
					SDingDanInfo tempInfo;
					tempInfo.strWuLiuDanHao = strWuLiuDanHao;
					mapZTDingDanInfo[strWuLiuDanHao] = tempInfo;
					it = mapZTDingDanInfo.find(strWuLiuDanHao);
				}
			}
			else if(strWuliuGongSi.find(L"韵达") != wstring::npos)
			{
				it = mapYDDingDanInfo.find(strWuLiuDanHao);
				if(it == mapYDDingDanInfo.end())
				{
					SDingDanInfo tempInfo;
					tempInfo.strWuLiuDanHao = strWuLiuDanHao;
					mapYDDingDanInfo[strWuLiuDanHao] = tempInfo;
					it = mapYDDingDanInfo.find(strWuLiuDanHao);
				}
			}
			else
			{
				THROW_ERROR(L"未知的物流公司");
			}
			wstring strDianPu;
			SHEET_CELL_STRING(saleDetailSheet, r, nDianPu, strDianPu);
			std::map<wstring, wstring>::iterator itDianPu = mapDianPuInfo.find(strDianPu);
			if(itDianPu == mapDianPuInfo.end())
			{
				wchar_t szBuffer[128] = { 0 };
				wsprintf(szBuffer, L"未找到店铺信息 [%s]", strDianPu.c_str());
				THROW_ERROR(szBuffer);
			}
			std::map<wstring, wstring>::iterator itPingTai = mapPingTaiInfo.find(itDianPu->second);
			if(itPingTai == mapPingTaiInfo.end())
			{
				wchar_t szBuffer[128] = { 0 };
				wsprintf(szBuffer, L"未找到平台信息 [%s]", itDianPu->second.c_str());
				THROW_ERROR(szBuffer);
			}
			it->second.strZhuanJianZhuYi = itPingTai->second;
			SHEET_CELL_INT(saleDetailSheet, r, nHuoPinZongShuLiang, it->second.nHuoPinShuLiang);
			SHEET_CELL_STRING(saleDetailSheet, r, nShouJianRen, it->second.strShouJianRen);

			SHEET_CELL_STRING(saleDetailSheet, r, nShouJianRenDiZhi, it->second.strShouJianRedDiZhi);
			SHEET_CELL_STRING(saleDetailSheet, r, nShouJianRenShouJi, it->second.strShouJianRenDianHua);
			SHEET_CELL_STRING(saleDetailSheet, r, nBeiZhu, it->second.strBeiZhu);
			SHEET_CELL_STRING(saleDetailSheet, r, nDaYinBeiZhu, it->second.strDaYinBeiZhu);
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
		DeleteFile(L"./结果-韵达.xls");
		DeleteFile(L"./结果-中通.xls");
		CreateExcel(L"韵达", mapYDDingDanInfo);
		CreateExcel(L"中通", mapZTDingDanInfo);
	}
	return 0;
}

