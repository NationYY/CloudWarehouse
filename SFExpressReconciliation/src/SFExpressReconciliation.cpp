// SFExpressReconciliation.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "BasicExcel.hpp"
#include <list>
#include <set>
#include <iostream>
#include <sstream>
#include "shlwapi.h"
#include "typedefine.h"
#define THROW(info) std::cout<<info<<std::endl; system("pause");
using namespace YCompoundFiles;
using namespace YExcel;


bool ParseALLData();


int _tmain(int argc, _TCHAR* argv[])
{
	ParseALLData();
	BasicExcel sfExcel;
	BasicExcel ycExcel;
	BasicExcel recordExcel;
	//step1. load sf data
	sfExcel.Load("./028JS02_0286795960-201912.xls");
	int nRecordRowIndex = 0;
	recordExcel.New(1);
	BasicExcelWorksheet* recordSheet = recordExcel.GetWorksheet("Sheet1");
	if(recordSheet)
	{
		recordSheet->Cell(nRecordRowIndex++, 0)->SetWString(L"重量差异订单");
		recordSheet->Cell(nRecordRowIndex, 0)->SetWString(L"单号");
		recordSheet->Cell(nRecordRowIndex, 1)->SetWString(L"顺丰重量");
		recordSheet->Cell(nRecordRowIndex, 2)->SetWString(L"云仓重量");
		nRecordRowIndex++;
	}
	std::set<std::wstring> setSFHandled;
	std::set<std::wstring> setYCNeedHandle;
	std::map<std::wstring, sYCExportData> mapYCExportData;
	std::map<std::wstring, sSFAuthData> mapSFAuthData;
	BasicExcelWorksheet* sfSheet = sfExcel.GetWorksheet(L"Sheet0");
	size_t sfHandleCol = -1;
	if(sfSheet)
	{
		size_t maxRows = sfSheet->GetTotalRows();
		size_t maxCols = sfSheet->GetTotalCols();
		sfHandleCol = maxCols;
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
				sfHandleCol = c;
			}
		}
		if(!bFix)
			sfSheet->Cell(0,maxCols)->SetWString(L"对账结果");

		for(size_t r = 1; r < maxRows; ++r)
		{
			sSFAuthData _data;
			const wchar_t* _pStr = NULL;
			BasicExcelCell* cell = sfSheet->Cell(r, colNumber);
			_pStr = cell->GetWString();
			if(_pStr)
				_data.number = _pStr;
			cell = sfSheet->Cell(r, colWeight);
			_pStr = cell->GetWString();
			if(_pStr)
				_data.weight = _pStr;
			cell = sfSheet->Cell(r, colVAServices);
			_pStr = cell->GetWString();
			if(_pStr)
				_data.vaServices = _pStr;
			_data.row = r;
			
			cell = sfSheet->Cell(r, sfHandleCol);
			_pStr = cell->GetWString();
			if(_pStr)
			{
				if(wcscmp(_pStr, L"1") == 0)
				{
					setSFHandled.insert(_data.number);
					continue;
				}
			}
			if(_data.vaServices == L"保价")
			{
				sfSheet->Cell(r, sfHandleCol)->SetWString(L"1");
				continue;
			}
			mapSFAuthData[_data.number] = _data;
		}
	}
	else
	{
		THROW("error load sf data");
	}
	//step2. load yc data
	ycExcel.Load("./云仓.xls");
	BasicExcelWorksheet* ycSheet = ycExcel.GetWorksheet(L"Sheet1");
	if(ycSheet)
	{
		size_t maxRows = ycSheet->GetTotalRows();
		size_t maxCols = ycSheet->GetTotalCols();
		int colNumber = -1;
		int colWeight = -1;
		int colCompany = -1;
		for(size_t c = 0; c < maxCols; ++c)
		{
			BasicExcelCell* cell = ycSheet->Cell(0, c);
			std::wstring strTitle = cell->GetWString();
			if(strTitle == L"物流单号")
				colNumber = c;
			else if(strTitle == L"实际重量")
				colWeight = c;
			else if(strTitle == L"物流公司")
				colCompany = c;
		}
		
		for(size_t r = 1; r < maxRows; ++r)
		{
			sYCExportData _data;
			const wchar_t* _pStr = NULL;
			BasicExcelCell* cell = ycSheet->Cell(r, colCompany);
			_pStr = cell->GetWString();
			if(_pStr)
			{
				if(wcscmp(_pStr, L"顺丰热敏") != 0)
					continue;
			}
			cell = ycSheet->Cell(r, colNumber);
			_pStr = cell->GetWString();
			if(_pStr)
				_data.number = _pStr;
			cell = ycSheet->Cell(r, colWeight);
			_data.weight = cell->GetDouble();
			_data.weight += 0.05;
			_data.row = r;
			std::set<std::wstring>::iterator itSFHandled = setSFHandled.find(_data.number);
			if(itSFHandled == setSFHandled.end())
			{
				mapYCExportData[_data.number] = _data;
				setYCNeedHandle.insert(_data.number);
			}
		}
	}
	else
	{
		THROW("error load yc data");
	}
	//step3. compare
	int errorCnt = 0;
	std::map<std::wstring, sYCExportData>::iterator itYCBegin = mapYCExportData.begin();
	std::map<std::wstring, sYCExportData>::iterator itYCEnd = mapYCExportData.end();
	while(itYCBegin != itYCEnd)
	{
		std::map<std::wstring, sSFAuthData>::iterator itSF = mapSFAuthData.find(itYCBegin->first);
		if(itSF != mapSFAuthData.end())
		{
			wistringstream iss(itSF->second.weight.c_str());
			double dSFWeight;
			double finalWeight;
			iss >> dSFWeight;
			int nWeight = (int)floor(itYCBegin->second.weight);
			double dOffset = itYCBegin->second.weight - nWeight;
			if(dOffset >= 0.5)
				finalWeight = nWeight + 1;
			else if(dOffset > 0.0)
				finalWeight = nWeight + 0.5;
			else
				finalWeight = itYCBegin->second.weight;

			if(finalWeight < dSFWeight)
			{
				recordSheet->Cell(nRecordRowIndex,0)->SetWString(itSF->first.c_str());
				recordSheet->Cell(nRecordRowIndex,1)->SetDouble(dSFWeight);
				recordSheet->Cell(nRecordRowIndex,2)->SetDouble(finalWeight);
				nRecordRowIndex++;
				sfSheet->Cell(itSF->second.row, sfHandleCol)->SetWString(L"0");
				errorCnt++;
			}
			else
			{
				sfSheet->Cell(itSF->second.row, sfHandleCol)->SetWString(L"1");
			}
			setYCNeedHandle.erase(itYCBegin->first);
		}
		++itYCBegin;
	}
	{
		recordSheet->Cell(nRecordRowIndex++, 0)->SetWString(L"云仓未处理单号");
		std::set<std::wstring>::iterator itB = setYCNeedHandle.begin();
		std::set<std::wstring>::iterator itE = setYCNeedHandle.end();
		while(itB != itE)
		{
			recordSheet->Cell(nRecordRowIndex++,0)->SetWString(itB->c_str());
			++itB;
		}
	}

	recordExcel.SaveAs("./compare_record.xls");
	sfExcel.Save();
	std::cout<<"处理完成!"<<std::endl;
	system("pause");
	return 0;
}

bool ParseALLData()
{
	std::cout<<"请输入对账年月:"<<std::endl;
	std::string strYM;
	std::cin>>strYM;
	std::string strTotalFileName = "销售出库单" + strYM + ".xls";
	std::string strDetailFileName = "销售出库明细" + strYM + ".xls";
	BasicExcel totalExcel;
	BasicExcel detailExcel;
	totalExcel.Load(strTotalFileName.c_str());
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
			THROW("发货销售表 有标题未找到");
		}
		for(size_t r = 1; r < maxRows; ++r)
		{
			sSalesInfo _data;
			const wchar_t* _pStr = NULL;
			_pStr = totalSheet->Cell(r, nHuoZhu)->GetWString();
			g_mapAllSalesInfo[_pStr->]
		}

		for(size_t r = 1; r < maxRows; ++r)
		{
			sYCExportData _data;
			const wchar_t* _pStr = NULL;
			BasicExcelCell* cell = totalSheet->Cell(r, colCompany);
			_pStr = cell->GetWString();
			if(_pStr)
			{
				if(wcscmp(_pStr, L"顺丰热敏") != 0)
					continue;
			}
			cell = totalSheet->Cell(r, colNumber);
			_pStr = cell->GetWString();
			if(_pStr)
				_data.number = _pStr;
			cell = totalSheet->Cell(r, colWeight);
			_data.weight = cell->GetDouble();
			_data.weight += 0.05;
			_data.row = r;
			std::set<std::wstring>::iterator itSFHandled = setSFHandled.find(_data.number);
			if(itSFHandled == setSFHandled.end())
			{
				mapYCExportData[_data.number] = _data;
				setYCNeedHandle.insert(_data.number);
			}
		}
	}
	detailExcel.Load(strDetailFileName.c_str());
}