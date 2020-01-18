// SFExpressReconciliation.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "BasicExcel.hpp"
#include <list>
#include <set>
#include <iostream>
#include <sstream>
#include "shlwapi.h"
#define THROW(info) std::cout<<info<<std::endl; system("pause");
using namespace YCompoundFiles;
using namespace YExcel;
struct sSFAuthData
{
	wstring number;
	wstring weight;
	wstring vaServices;
	int row;
};

struct sYCExportData
{
	wstring number;
	double weight;
	int row;
};

int _tmain(int argc, _TCHAR* argv[])
{
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
		recordSheet->Cell(nRecordRowIndex++, 0)->SetWString(L"�������충��");
		recordSheet->Cell(nRecordRowIndex, 0)->SetWString(L"����");
		recordSheet->Cell(nRecordRowIndex, 1)->SetWString(L"˳������");
		recordSheet->Cell(nRecordRowIndex, 2)->SetWString(L"�Ʋ�����");
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
			if(strTitle == L"�˵�����")
				colNumber = c;
			else if(strTitle == L"�Ʒ�����")
				colWeight = c;
			else if(strTitle == L"��ֵ����")
				colVAServices = c;
			else if(strTitle == L"���˽��")
			{
				bFix = true;
				sfHandleCol = c;
			}
		}
		if(!bFix)
			sfSheet->Cell(0,maxCols)->SetWString(L"���˽��");

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
			if(_data.vaServices == L"����")
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
	ycExcel.Load("./�Ʋ�.xls");
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
			if(strTitle == L"��������")
				colNumber = c;
			else if(strTitle == L"ʵ������")
				colWeight = c;
			else if(strTitle == L"������˾")
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
				if(wcscmp(_pStr, L"˳������") != 0)
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
		recordSheet->Cell(nRecordRowIndex++, 0)->SetWString(L"�Ʋ�δ������");
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
	std::cout<<"�������!"<<std::endl;
	system("pause");
	return 0;
}

