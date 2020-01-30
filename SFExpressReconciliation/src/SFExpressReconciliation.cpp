// SFExpressReconciliation.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "typedefine.h"
#include "BasicExcel.hpp"
#include "func_common.h"
#include <stdio.h>
#include <io.h>
#include <direct.h>
#include "shlwapi.h"
using namespace YCompoundFiles;
using namespace YExcel;
#define THROW_ERROR(info) std::wcout<<info<<std::endl; system("pause"); return 0;
#define SHEET_CELL(sheet, r, c, strOut) _pStr = sheet->Cell(r, c)->GetWString();\
	if(_pStr)\
		strOut = _pStr;
#define TOTAL_FILE_PATH L"./测试数据/销售出库单" + g_strYM + L".xls"
#define DETAIL_FILE_PATH L"./测试数据/销售出库明细" + g_strYM + L".xls"
#define SF_FILE_PATH L"./测试数据/顺丰账单" + g_strYM + L".xls"
#define IN_STORAGE_PATH L"./测试数据/入库明细账" + g_strYM + L".xls"


std::map< std::wstring, std::list<sSalesInfo> > g_mapAllSalesInfo;
std::map< std::wstring, sSalesInfo* > g_mapTempSalesInfo;
std::map<std::wstring, sSFAuthData> g_mapSFAuthData;
std::map< std::wstring, std::set<std::wstring> > g_mapYCNeedSFHandle;
std::map< std::wstring, std::map<std::wstring, sInStorageInfo> > g_mapInStorageInfo;
BasicExcel g_sfExcel;
BasicExcel g_recordExcel;
size_t g_sfHandleCol = -1;
const wchar_t* g_arrWorksheetName[] ={L"顺丰重量差异订单", L"顺丰云仓未处理单号"};
int g_arrRecordRowIndex[] ={0, 0};
std::wstring g_strYM;
const wchar_t* g_arrHuoZhuName[] = {L"魔合科技N", L"永创耀辉", L"弥雅食器"};



bool ParseALLData();
bool CreateHuoZhuFile();
bool Handle_MoHeKeJi();
bool Handle_YongChuangYaoHui();
bool Handle_MiYaShiQi();
bool LoadSFData();
bool CompareWithSFData(std::wstring strHuoZhu, std::list<sSalesInfo>& listInfo);

int _tmain(int argc, _TCHAR* argv[])
{
	wcout.imbue(locale("chs"));
	if(!ParseALLData())
		return 0;
	if(!CreateHuoZhuFile())
		return 0;
	Sleep(2000);
	if(!LoadSFData())
		return 0;
	if(!Handle_MoHeKeJi())
		return 0;
	if(!Handle_YongChuangYaoHui())
		return 0;
	if(!Handle_MiYaShiQi())
		return 0;
	wstring filePath = L"./Export_" + g_strYM + L"/" + L"compare_record.xls";
	string _filePath = CFuncCommon::WString2String(filePath.c_str());
	g_recordExcel.SaveAs(_filePath.c_str());
	g_sfExcel.Save();
	std::cout<<"处理完成!"<<std::endl;
	system("pause");
	return 0;
}

bool ParseALLData()
{
	std::cout<<"请输入对账年月:"<<std::endl;
	std::wcin>>g_strYM;
	std::wstring strTotalFileName = TOTAL_FILE_PATH;
	std::wstring strDetailFileName = DETAIL_FILE_PATH;
	std::wstring strInStorageFileName = IN_STORAGE_PATH;
	BasicExcel totalExcel;
	BasicExcel inStorageExcel;
	BasicExcel detailExcel;
	std::string _strTotalFileName = CFuncCommon::WString2String(strTotalFileName.c_str());
	totalExcel.Load(_strTotalFileName.c_str());
	BasicExcelWorksheet* totalSheet = totalExcel.GetWorksheet(L"Sheet1");
	if(totalSheet)
	{
		size_t maxRows = totalSheet->GetTotalRows();
		size_t maxCols = totalSheet->GetTotalCols();

		int nHuoZhu = -1;
		int nShouJianRen = -1;
		int nWuLiuGongSi = -1;
		int nWuLiuDanHao = -1;
		int nShouJianRenDiZhi = -1;
		int nZhongLiang = -1;
		int nFaHuoShijian = -1;

		for(size_t c = 0; c < maxCols; ++c)
		{
			BasicExcelCell* cell = totalSheet->Cell(0, c);
			std::wstring strTitle = cell->GetWString();
			if(strTitle == L"货主")
				nHuoZhu = c;
			else if(strTitle == L"收件人")
				nShouJianRen = c;
			else if(strTitle == L"物流公司")
				nWuLiuGongSi = c;
			else if(strTitle == L"物流单号")
				nWuLiuDanHao = c;
			else if(strTitle == L"收件人地址")
				nShouJianRenDiZhi = c;
			else if(strTitle == L"实际重量")
				nZhongLiang = c;
			else if(strTitle == L"发货时间")
				nFaHuoShijian = c;
		}
		if(nHuoZhu == -1 || nShouJianRen == -1 || nWuLiuGongSi == -1 || nWuLiuDanHao == -1 || nShouJianRenDiZhi == -1 || nZhongLiang == -1 || nFaHuoShijian == -1)
		{
			THROW_ERROR(L"销售出库单 有标题未找到");
		}
		for(size_t r = 1; r < maxRows; ++r)
		{
			sSalesInfo _data;
			const wchar_t* _pStr = NULL;
			SHEET_CELL(totalSheet, r, nHuoZhu, _data.strHuoZhu);
			SHEET_CELL(totalSheet, r, nShouJianRen, _data.strShouJianRen);
			SHEET_CELL(totalSheet, r, nWuLiuGongSi, _data.strWuLiuGongSi);
			SHEET_CELL(totalSheet, r, nWuLiuDanHao, _data.strWuLiuDanHao);
			SHEET_CELL(totalSheet, r, nShouJianRenDiZhi, _data.strShouJianRenDiZhi);
			double dTemp = totalSheet->Cell(r, nZhongLiang)->GetDouble();
			dTemp += 0.05;
			if(_data.strWuLiuGongSi == L"顺丰热敏")
				g_mapYCNeedSFHandle[_data.strHuoZhu].insert(_data.strWuLiuDanHao);
			_data.strZhongLiang = CFuncCommon::Double2WString(dTemp+DOUBLE_PRECISION, 2);
			SHEET_CELL(totalSheet, r, nFaHuoShijian, _data.strFaHuoShijian);
			g_mapAllSalesInfo[_data.strHuoZhu].push_back(_data);
			std::list<sSalesInfo>::iterator it = --g_mapAllSalesInfo[_data.strHuoZhu].end();
			g_mapTempSalesInfo[_data.strWuLiuDanHao] = &(*it);
		}
	}

	std::string _strDetailFileName = CFuncCommon::WString2String(strDetailFileName.c_str());
	detailExcel.Load(_strDetailFileName.c_str());
	BasicExcelWorksheet* detailSheet = detailExcel.GetWorksheet(L"Sheet1");
	if(detailSheet)
	{
		size_t maxRows = detailSheet->GetTotalRows();
		size_t maxCols = detailSheet->GetTotalCols();

		int nHuoPinMingCheng = -1;
		int nHuoPinZongShuLiang = -1;
		int nHuoPinShuLiang = -1;
		int nWuLiuDanHao = -1;
		int nSheng = -1;

		for(size_t c = 0; c < maxCols; ++c)
		{
			BasicExcelCell* cell = detailSheet->Cell(0, c);
			std::wstring strTitle = cell->GetWString();
			if(strTitle == L"货品名称")
				nHuoPinMingCheng = c;
			else if(strTitle == L"货品总数量")
				nHuoPinZongShuLiang = c;
			else if(strTitle == L"货品数量")
				nHuoPinShuLiang = c;
			else if(strTitle == L"物流编号")
				nWuLiuDanHao = c;
			else if(strTitle == L"省")
				nSheng = c;
		}
		if(nHuoPinMingCheng == -1 || nHuoPinZongShuLiang == -1 || nHuoPinShuLiang == -1 || nWuLiuDanHao == -1 || nSheng == -1)
		{
			THROW_ERROR(L"销售出库明细 有标题未找到");
		}
		for(size_t r = 1; r < maxRows; ++r)
		{
			std::wstring strWuLiuDanHao;
			const wchar_t* _pStr = NULL;
			SHEET_CELL(detailSheet, r, nWuLiuDanHao, strWuLiuDanHao);
			std::map< std::wstring, sSalesInfo* >::iterator it = g_mapTempSalesInfo.find(strWuLiuDanHao);
			if(it == g_mapTempSalesInfo.end())
			{
				wchar_t szBuffer[128] = {0};
				wsprintfW(szBuffer, L"销售出库明细 未找到单号%s", strWuLiuDanHao.c_str());
				THROW_ERROR(szBuffer);
			}
			double dZSL = detailSheet->Cell(r, nHuoPinZongShuLiang)->GetDouble();
			it->second->strHuoPinZongShuLiang = CFuncCommon::Double2WString(dZSL+DOUBLE_PRECISION, 0);
			SHEET_CELL(detailSheet, r, nSheng, it->second->strSheng);
			std::wstring strHuoPinMingCheng;
			SHEET_CELL(detailSheet, r, nHuoPinMingCheng, strHuoPinMingCheng);
			double dSL = detailSheet->Cell(r, nHuoPinShuLiang)->GetDouble();
			std::wstring strHuoPinShuLiang = CFuncCommon::Double2WString(dSL+DOUBLE_PRECISION, 0);
			if(it->second->strHuoPinMingXi == L"")
				it->second->strHuoPinMingXi = strHuoPinMingCheng + L"@" + strHuoPinShuLiang;
			else
				it->second->strHuoPinMingXi = it->second->strHuoPinMingXi + L";" + strHuoPinMingCheng + L"@" + strHuoPinShuLiang;
		}
	}
	g_mapTempSalesInfo.clear();

	std::string _strInStorageFileName = CFuncCommon::WString2String(strInStorageFileName.c_str());
	if(!inStorageExcel.Load(_strInStorageFileName.c_str()))
	{
		THROW_ERROR(L"入库明细账 加载失败");
	}
	BasicExcelWorksheet* inStorageSheet = inStorageExcel.GetWorksheet(L"Sheet1");
	if(inStorageSheet)
	{
		size_t maxRows = inStorageSheet->GetTotalRows();
		size_t maxCols = inStorageSheet->GetTotalCols();

		int nHuoZhu = -1;
		int nRuKuYuanYin = -1;
		int nShangJiaBianMa = -1;
		int nHuoPingBianMa = -1;
		int nHuoPinMingCheng = -1;
		int nShuLiang = -1;
		for(size_t c = 0; c < maxCols; ++c)
		{
			BasicExcelCell* cell = inStorageSheet->Cell(0, c);
			std::wstring strTitle = cell->GetWString();
			if(strTitle == L"货主")
				nHuoZhu = c;
			else if(strTitle == L"入库原因")
				nRuKuYuanYin = c;
			else if(strTitle == L"商家编码")
				nShangJiaBianMa = c;
			else if(strTitle == L"货品编号")
				nHuoPingBianMa = c;
			else if(strTitle == L"货品名称")
				nHuoPinMingCheng = c;
			else if(strTitle == L"数量")
				nShuLiang = c;
		}
		if(nHuoZhu == -1 || nRuKuYuanYin == -1 || nShangJiaBianMa == -1 || nHuoPingBianMa == -1 || nHuoPinMingCheng == -1 || nShuLiang == -1)
		{
			THROW_ERROR(L"入库明细账 有标题未找到");
		}
		for(size_t r = 1; r < maxRows; ++r)
		{
			sInStorageInfo info;
			const wchar_t* _pStr = NULL;
			SHEET_CELL(inStorageSheet, r, nHuoZhu, info.strHuoZhu);
			std::wstring strRuKuYuanYin;
			SHEET_CELL(inStorageSheet, r, nRuKuYuanYin, strRuKuYuanYin);
			if(strRuKuYuanYin != L"其它入库" && strRuKuYuanYin != L"采购入库")
				continue;	
			SHEET_CELL(inStorageSheet, r, nShangJiaBianMa, info.strShangJiaBianMa);
			SHEET_CELL(inStorageSheet, r, nHuoPingBianMa, info.strHuoPinBianMa);
			SHEET_CELL(inStorageSheet, r, nHuoPinMingCheng, info.strHuoPinMingCheng);
			info.nCnt = inStorageSheet->Cell(r, nShuLiang)->GetInteger();
			std::wstring strKey = info.strShangJiaBianMa+info.strHuoPinBianMa;
			std::map< std::wstring, std::map<std::wstring, sInStorageInfo> >::iterator itHuoZhu = g_mapInStorageInfo.find(info.strHuoZhu);
			if(itHuoZhu == g_mapInStorageInfo.end())
				g_mapInStorageInfo[info.strHuoZhu][strKey] = info;
			else
			{
				std::map<std::wstring, sInStorageInfo>::iterator itInfo = itHuoZhu->second.find(strKey);
				if(itInfo == itHuoZhu->second.end())
					itHuoZhu->second[strKey] = info;
				else
					itInfo->second.nCnt += info.nCnt;
			}
		}
	}
	return true;
}

bool CreateHuoZhuFile()
{
	wstring folderPath = L"./Export_" + g_strYM;
	if(0 != _waccess(folderPath.c_str(), 0))
		_wmkdir(folderPath.c_str());
	int nHuoZhuCnt = sizeof(g_arrHuoZhuName)/sizeof(const wchar_t*);
	for(int i=0; i<nHuoZhuCnt; ++i)
	{
		wstring fileName = folderPath + L"/" + g_arrHuoZhuName[i] + L"_" + g_strYM + L"对账单.xls";
		::DeleteFileW(fileName.c_str());
	}
	wstring filePath = L"./Export_" + g_strYM + L"/" + L"compare_record.xls";
	::DeleteFileW(filePath.c_str());
	std::map< std::wstring, std::list<sSalesInfo> >::iterator itB = g_mapAllSalesInfo.begin();
	std::map< std::wstring, std::list<sSalesInfo> >::iterator itE = g_mapAllSalesInfo.end();
	while(itB != itE)
	{
		int i=0;
		for(; i<nHuoZhuCnt; ++i)
		{
			if(wcscmp(itB->first.c_str(), g_arrHuoZhuName[i]) == 0)
				break;
		}
		if(i == nHuoZhuCnt && itB->first != L"哈特能量")
		{
			wcout << L"存在未处理的货主:" << itB->first << std::endl;
			wcout << L"是否继续? y:继续 n:中止" << std::endl;
			wstring _cin;
			wcin >> _cin;
			if(_cin != L"Y" && _cin != L"y")
				return false;
		}
		++itB;
	}


	g_recordExcel.AddWorksheet(g_arrWorksheetName[0]);
	g_recordExcel.AddWorksheet(g_arrWorksheetName[1]);
	BasicExcelWorksheet* recordSheet = g_recordExcel.GetWorksheet(g_arrWorksheetName[0]);
	if(recordSheet)
	{
		recordSheet->Cell(g_arrRecordRowIndex[0], 0)->SetWString(L"单号");
		recordSheet->Cell(g_arrRecordRowIndex[0], 1)->SetWString(L"顺丰重量");
		recordSheet->Cell(g_arrRecordRowIndex[0], 2)->SetWString(L"云仓重量");
		g_arrRecordRowIndex[0]++;
	}
	return true;
}

bool CreateExcel(BasicExcel& excel, std::list<sSalesInfo>& listSalesInfo, std::map<std::wstring, sInStorageInfo>& mapInStorageInfo)
{
	if(listSalesInfo.size() == 0)
		return false;
	excel.New(2);
	int nRecordRowIndex = 1;
	BasicExcelWorksheet* sheet = excel.GetWorksheet("Sheet1");
	if(sheet)
	{
		sheet->Cell(0, 0)->SetWString(L"收件人");
		sheet->Cell(0, 1)->SetWString(L"收件人地址");
		sheet->Cell(0, 2)->SetWString(L"省");
		sheet->Cell(0, 3)->SetWString(L"物流公司");
		sheet->Cell(0, 4)->SetWString(L"物流单号");
		sheet->Cell(0, 5)->SetWString(L"重量");
		sheet->Cell(0, 6)->SetWString(L"发货时间");
		sheet->Cell(0, 7)->SetWString(L"货品总数量");
		sheet->Cell(0, 8)->SetWString(L"货品明细");
		sheet->Cell(0, 9)->SetWString(L"计费重量");
		sheet->Cell(0, 10)->SetWString(L"物流费");
		sheet->Cell(0, 11)->SetWString(L"耗材费");
		sheet->Cell(0, 12)->SetWString(L"操作费");
		sheet->Cell(0, 13)->SetWString(L"增值费用");

		std::list<sSalesInfo>::iterator itB = listSalesInfo.begin();
		std::list<sSalesInfo>::iterator itE = listSalesInfo.end();
		while(itB != itE)
		{
			itB->nRow = nRecordRowIndex;
			sheet->Cell(nRecordRowIndex, 0)->SetWString(itB->strShouJianRen.c_str());
			sheet->Cell(nRecordRowIndex, 1)->SetWString(itB->strShouJianRenDiZhi.c_str());
			sheet->Cell(nRecordRowIndex, 2)->SetWString(itB->strSheng.c_str());
			sheet->Cell(nRecordRowIndex, 3)->SetWString(itB->strWuLiuGongSi.c_str());
			sheet->Cell(nRecordRowIndex, 4)->SetWString(itB->strWuLiuDanHao.c_str());
			sheet->Cell(nRecordRowIndex, 5)->SetWString(itB->strZhongLiang.c_str());
			sheet->Cell(nRecordRowIndex, 6)->SetWString(itB->strFaHuoShijian.c_str());
			sheet->Cell(nRecordRowIndex, 7)->SetWString(itB->strHuoPinZongShuLiang.c_str());
			sheet->Cell(nRecordRowIndex, 8)->SetWString(itB->strHuoPinMingXi.c_str());
			//待计算
			sheet->Cell(nRecordRowIndex, 9)->SetWString(L"0");
			sheet->Cell(nRecordRowIndex, 10)->SetWString(L"0");
			sheet->Cell(nRecordRowIndex, 11)->SetWString(L"0");
			sheet->Cell(nRecordRowIndex, 12)->SetWString(L"0");
			sheet->Cell(nRecordRowIndex, 13)->SetWString(L"0");
			nRecordRowIndex++;
			itB++;
		}
	}
	nRecordRowIndex = 1;
	sheet = excel.GetWorksheet("Sheet2");
	if(sheet)
	{
		sheet->Cell(0, 0)->SetWString(L"商家编码");
		sheet->Cell(0, 1)->SetWString(L"货品编号");
		sheet->Cell(0, 2)->SetWString(L"货品名称");
		sheet->Cell(0, 3)->SetWString(L"入库数量");
		sheet->Cell(0, 4)->SetWString(L"入库费用");

		std::map<std::wstring, sInStorageInfo>::iterator itB = mapInStorageInfo.begin();
		std::map<std::wstring, sInStorageInfo>::iterator itE = mapInStorageInfo.end();
		while(itB != itE)
		{
			itB->second.nRow = nRecordRowIndex;
			sheet->Cell(nRecordRowIndex, 0)->SetWString(itB->second.strShangJiaBianMa.c_str());
			sheet->Cell(nRecordRowIndex, 1)->SetWString(itB->second.strHuoPinBianMa.c_str());
			sheet->Cell(nRecordRowIndex, 2)->SetWString(itB->second.strHuoPinMingCheng.c_str());
			sheet->Cell(nRecordRowIndex, 3)->SetInteger(itB->second.nCnt);
			//待计算
			sheet->Cell(nRecordRowIndex, 4)->SetWString(L"0");
			nRecordRowIndex++;
			itB++;
		}
	}
	return true;
}


bool Handle_MoHeKeJi()
{
	BasicExcel excel;
	if(!CreateExcel(excel, g_mapAllSalesInfo[L"魔合科技N"], g_mapInStorageInfo[L"魔合科技N"]))
		return false;
	wstring fileName = L"./Export_" + g_strYM + L"/" + L"魔合科技N_" + g_strYM + L"对账单.xls";
	string _file = CFuncCommon::WString2String(fileName.c_str());
	CompareWithSFData(L"魔合科技N", g_mapAllSalesInfo[L"魔合科技N"]);
	//计算相关费用
	//单独TH-043和单独TH-042按拆单价格
	{
		BasicExcelWorksheet* sheet = excel.GetWorksheet("Sheet1");
		if(sheet)
		{
			std::list<sSalesInfo>& listSales = g_mapAllSalesInfo[L"魔合科技N"];
			std::list<sSalesInfo>::iterator itB = listSales.begin();
			std::list<sSalesInfo>::iterator itE = listSales.end();
			while(itB != itE)
			{
				//sheet->Cell(0, 9)->SetWString(L"计费重量");
				//sheet->Cell(0, 10)->SetWString(L"打包费");
				//sheet->Cell(0, 11)->SetWString(L"耗材费");
				//sheet->Cell(0, 12)->SetWString(L"操作费");
				//sheet->Cell(0, 13)->SetWString(L"增值费用");
				wchar_t decimal = itB->strZhongLiang.at(itB->strZhongLiang.size()-1);
				if(decimal != L'0')
				{

				}
				++itB;
			}
		}
		
	}
	
	excel.SaveAs(_file.c_str());
	return true;
}

bool Handle_YongChuangYaoHui()
{
	BasicExcel excel;
	if(!CreateExcel(excel, g_mapAllSalesInfo[L"永创耀辉"], g_mapInStorageInfo[L"永创耀辉N"]))
		return false;
	wstring fileName = L"./Export_" + g_strYM + L"/" + L"永创耀辉_" + g_strYM + L"对账单.xls";
	string _file = CFuncCommon::WString2String(fileName.c_str());
	CompareWithSFData(L"永创耀辉", g_mapAllSalesInfo[L"永创耀辉"]);

	//计算相关费用
	{
		BasicExcelWorksheet* sheet = excel.GetWorksheet("Sheet1");
		if(sheet)
		{
			std::list<sSalesInfo>& listSales = g_mapAllSalesInfo[L"永创耀辉"];
			std::list<sSalesInfo>::iterator itB = listSales.begin();
			std::list<sSalesInfo>::iterator itE = listSales.end();
			while(itB != itE)
			{
				//sheet->Cell(0, 10)->SetWString(L"物流费");
				//sheet->Cell(0, 11)->SetWString(L"耗材费");
				//sheet->Cell(0, 12)->SetWString(L"操作费");
				//sheet->Cell(0, 13)->SetWString(L"增值费用");
				int nWeight = 0;
				wchar_t decimal1 = itB->strZhongLiang.at(itB->strZhongLiang.size()-1);
				wchar_t decimal2 = itB->strZhongLiang.at(itB->strZhongLiang.size()-2);
				if(decimal1 != L'0' || decimal2 != L'0')
				{
					double nZhongLiang = _wtof(itB->strZhongLiang.c_str());
					nZhongLiang += 1;
					nZhongLiang += DOUBLE_PRECISION;
					nWeight = int(nZhongLiang);
					if(nWeight < 3)
						nWeight = 3;
					wchar_t szWeight[10] ={0};
					_itow_s(nWeight, szWeight, 10);
					sheet->Cell(itB->nRow, 9)->SetWString(szWeight);
				}
				else
				{
					nWeight = _wtoi(itB->strZhongLiang.c_str());
					if(nWeight < 3)
						nWeight = 3;
					wchar_t szWeight[10] ={0};
					_itow_s(nWeight, szWeight, 10);
					sheet->Cell(itB->nRow, 9)->SetWString(szWeight);
				}
				//计算物流费
				{
					if(itB->strWuLiuGongSi == L"顺丰热敏")
					{
					}
					else if(itB->strWuLiuGongSi == L"百世快运")
					{
					}
					else if(itB->strWuLiuGongSi == L"百世线下(分拨)")
					{
					}
					else
					{
						wchar_t szOut[120] ={0};
						_swprintf(szOut, L"[未知的物流方式] 货主=%s 单号=%s", itB->strHuoZhu.c_str(), itB->strWuLiuDanHao.c_str());
						wcout << szOut << std::endl;
					}
				}
				sheet->Cell(itB->nRow, 12)->SetWString(L"1.1");
				//计算保费
				{
					//sheet->Cell(itB->nRow, 13)->SetWString(L"1.1");
				}
				
				++itB;
			}
		}

	}
	excel.SaveAs(_file.c_str());

	return true;
}

bool Handle_MiYaShiQi()
{
	BasicExcel excel;
	if(!CreateExcel(excel, g_mapAllSalesInfo[L"弥雅食器"], g_mapInStorageInfo[L"弥雅食器"]))
		return false;
	wstring fileName = L"./Export_" + g_strYM + L"/" + L"弥雅食器_" + g_strYM + L"对账单.xls";
	string _file = CFuncCommon::WString2String(fileName.c_str());
	excel.SaveAs(_file.c_str());
	CompareWithSFData(L"弥雅食器", g_mapAllSalesInfo[L"弥雅食器"]);
	return true;
}

bool LoadSFData()
{
	std::wstring strSFFileName = SF_FILE_PATH;
	std::string _strSFFileName = CFuncCommon::WString2String(strSFFileName.c_str());
	g_sfExcel.Load(_strSFFileName.c_str());
	BasicExcelWorksheet* sfSheet = g_sfExcel.GetWorksheet(L"Sheet0");

	if(sfSheet)
	{
		size_t maxRows = sfSheet->GetTotalRows();
		size_t maxCols = sfSheet->GetTotalCols();
		g_sfHandleCol = maxCols;
		//load tile
		int colNumber = -1;
		int colWeight = -1;
		int colVAServices = -1;
		bool bFix = false;
		for(size_t c = 0; c < maxCols; ++c)
		{
			BasicExcelCell* cell = sfSheet->Cell(0, c);
			std::wstring strTitle = cell->GetWString();
			if(strTitle == L"运单号码")
				colNumber = c;
			else if(strTitle == L"计费重量")
				colWeight = c;
			else if(strTitle == L"增值费用")
				colVAServices = c;
			else if(strTitle == L"对账结果")
			{
				bFix = true;
				g_sfHandleCol = c;
			}
		}
		if(!bFix)
			sfSheet->Cell(0, maxCols)->SetWString(L"对账结果");
		for(size_t r = 1; r < maxRows; ++r)
		{
			sSFAuthData _data;
			const wchar_t* _pStr = NULL;
			SHEET_CELL(sfSheet, r, colNumber, _data.number);
			SHEET_CELL(sfSheet, r, colWeight, _data.weight);
			SHEET_CELL(sfSheet, r, colVAServices, _data.vaServices);
			_data.row = r;
			if(_data.vaServices == L"保价")
			{
				sfSheet->Cell(r, g_sfHandleCol)->SetWString(L"1");
				continue;
			}
			_pStr = sfSheet->Cell(r, g_sfHandleCol)->GetWString();
			if(_pStr)
			{
				if(wcscmp(_pStr, L"1") == 0)
					_data.bHandle = true;
			}
			g_mapSFAuthData[_data.number] = _data;
		}
	}
	else
	{
		THROW_ERROR(L"读取顺丰账单失败");
	}
	g_sfExcel.Save();
	return true;
}

bool CompareWithSFData(std::wstring strHuoZhu, std::list<sSalesInfo>& listInfo)
{
	BasicExcelWorksheet* recordSheet = g_recordExcel.GetWorksheet(g_arrWorksheetName[0]);
	if(recordSheet == NULL)
		return false;
	BasicExcelWorksheet* sfSheet = g_sfExcel.GetWorksheet(L"Sheet0");
	if(sfSheet == NULL)
		return false;
	std::list<sSalesInfo>::iterator itYCBegin = listInfo.begin();
	std::list<sSalesInfo>::iterator itYCEnd = listInfo.end();
	while(itYCBegin != itYCEnd)
	{
		std::map<std::wstring, sSFAuthData>::iterator itSF = g_mapSFAuthData.find(itYCBegin->strWuLiuDanHao);
		if(itSF != g_mapSFAuthData.end())
		{
			if(!itSF->second.bHandle)
			{
				wistringstream iss1(itSF->second.weight.c_str());
				wistringstream iss2(itYCBegin->strZhongLiang.c_str());
				double dSFWeight;
				double dYCWeight;
				double finalWeight;
				iss1 >> dSFWeight;
				iss2 >> dYCWeight;
				int nWeight = (int)floor(dYCWeight);
				double dOffset = dYCWeight - nWeight;
				if(dOffset >= 0.5)
					finalWeight = nWeight + 1;
				else if(dOffset > 0.0)
					finalWeight = nWeight + 0.5;
				else
					finalWeight = dYCWeight;
				if(finalWeight < dSFWeight)
				{
					recordSheet->Cell(g_arrRecordRowIndex[0], 0)->SetWString(itSF->first.c_str());
					recordSheet->Cell(g_arrRecordRowIndex[0], 1)->SetDouble(dSFWeight);
					recordSheet->Cell(g_arrRecordRowIndex[0], 2)->SetDouble(finalWeight);
					g_arrRecordRowIndex[0]++;
					sfSheet->Cell(itSF->second.row, g_sfHandleCol)->SetWString(L"0");
				}
				else
				{
					itSF->second.bHandle = true;
					sfSheet->Cell(itSF->second.row, g_sfHandleCol)->SetWString(L"1");
				}
			}
			g_mapYCNeedSFHandle[strHuoZhu].erase(itYCBegin->strWuLiuDanHao);
		}
		++itYCBegin;
	}

	{
		BasicExcelWorksheet* recordSheet = g_recordExcel.GetWorksheet(g_arrWorksheetName[1]);
		std::set<std::wstring>::iterator itB = g_mapYCNeedSFHandle[strHuoZhu].begin();
		std::set<std::wstring>::iterator itE = g_mapYCNeedSFHandle[strHuoZhu].end();
		while(itB != itE)
		{
			recordSheet->Cell(g_arrRecordRowIndex[1]++, 0)->SetWString(itB->c_str());
			++itB;
		}
	}

	return true;
}