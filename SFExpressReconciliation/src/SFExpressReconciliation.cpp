// SFExpressReconciliation.cpp : �������̨Ӧ�ó������ڵ㡣
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
std::map< std::wstring, std::list<sSalesInfo> > g_mapAllSalesInfo;
std::map< std::wstring, sSalesInfo* > g_mapTempSalesInfo;
std::map<std::wstring, sSFAuthData> g_mapSFAuthData;
std::map< std::wstring, std::set<std::wstring> > g_mapYCNeedSFHandle;
BasicExcel g_sfExcel;
BasicExcel g_recordExcel;
size_t g_sfHandleCol = -1;
const wchar_t* g_arrWorksheetName[] ={L"˳���������충��", L"˳���Ʋ�δ������"};
int g_arrRecordRowIndex[] ={0, 0};
std::wstring g_strYM;
const wchar_t* g_arrHuoZhuName[] = {L"ħ�ϿƼ�N", L"����ҫ��", L"����ʳ��"};



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
	std::cout<<"�������!"<<std::endl;
	system("pause");
	return 0;
}

bool ParseALLData()
{
	std::cout<<"�������������:"<<std::endl;
	std::wcin>>g_strYM;
	std::wstring strTotalFileName = L"./��������/���۳��ⵥ" + g_strYM + L".xls";
	std::wstring strDetailFileName = L"./��������/���۳�����ϸ" + g_strYM + L".xls";
	BasicExcel totalExcel;
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
			if(strTitle == L"����")
				nHuoZhu = c;
			else if(strTitle == L"�ռ���")
				nShouJianRen = c;
			else if(strTitle == L"������˾")
				nWuLiuGongSi = c;
			else if(strTitle == L"��������")
				nWuLiuDanHao = c;
			else if(strTitle == L"�ռ��˵�ַ")
				nShouJianRenDiZhi = c;
			else if(strTitle == L"ʵ������")
				nZhongLiang = c;
			else if(strTitle == L"����ʱ��")
				nFaHuoShijian = c;
		}
		if(nHuoZhu == -1 || nShouJianRen == -1 || nWuLiuGongSi == -1 || nWuLiuDanHao == -1 || nShouJianRenDiZhi == -1 || nZhongLiang == -1 || nFaHuoShijian == -1)
		{
			THROW_ERROR(L"���۳��ⵥ �б���δ�ҵ�");
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
			if(_data.strWuLiuGongSi == L"˳������")
				g_mapYCNeedSFHandle[_data.strHuoZhu].insert(_data.strWuLiuDanHao);
			_data.strZhongLiang = CFuncCommon::Double2WString(dTemp+DOUBLE_PRECISION, 1);
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
			if(strTitle == L"��Ʒ����")
				nHuoPinMingCheng = c;
			else if(strTitle == L"��Ʒ������")
				nHuoPinZongShuLiang = c;
			else if(strTitle == L"��Ʒ����")
				nHuoPinShuLiang = c;
			else if(strTitle == L"�������")
				nWuLiuDanHao = c;
			else if(strTitle == L"ʡ")
				nSheng = c;
		}
		if(nHuoPinMingCheng == -1 || nHuoPinZongShuLiang == -1 || nHuoPinShuLiang == -1 || nWuLiuDanHao == -1 || nSheng == -1)
		{
			THROW_ERROR(L"���۳�����ϸ �б���δ�ҵ�");
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
				wsprintfW(szBuffer, L"���۳�����ϸ δ�ҵ�����%s", strWuLiuDanHao.c_str());
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
		wstring fileName = folderPath + L"/" + g_arrHuoZhuName[i] + L"_" + g_strYM + L"���˵�.xls";
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
		if(i == nHuoZhuCnt)
		{
			wcout << L"����δ����Ļ���:" << itB->first << std::endl;
			wcout << L"�Ƿ����? y:���� n:��ֹ" << std::endl;
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
		recordSheet->Cell(g_arrRecordRowIndex[0], 0)->SetWString(L"����");
		recordSheet->Cell(g_arrRecordRowIndex[0], 1)->SetWString(L"˳������");
		recordSheet->Cell(g_arrRecordRowIndex[0], 2)->SetWString(L"�Ʋ�����");
		g_arrRecordRowIndex[0]++;
	}
	return true;
}

bool CreateExcel(BasicExcel& excel, std::list<sSalesInfo>& listInfo)
{
	if(listInfo.size() == 0)
		return false;
	excel.New(1);
	int nRecordRowIndex = 1;
	BasicExcelWorksheet* sheet = excel.GetWorksheet("Sheet1");
	if(sheet)
	{
		sheet->Cell(0, 0)->SetWString(L"�ռ���");
		sheet->Cell(0, 1)->SetWString(L"�ռ��˵�ַ");
		sheet->Cell(0, 2)->SetWString(L"ʡ");
		sheet->Cell(0, 3)->SetWString(L"������˾");
		sheet->Cell(0, 4)->SetWString(L"��������");
		sheet->Cell(0, 5)->SetWString(L"����");
		sheet->Cell(0, 6)->SetWString(L"����ʱ��");
		sheet->Cell(0, 7)->SetWString(L"��Ʒ������");
		sheet->Cell(0, 8)->SetWString(L"��Ʒ��ϸ");
		std::list<sSalesInfo>::iterator itB = listInfo.begin();
		std::list<sSalesInfo>::iterator itE = listInfo.end();
		while(itB != itE)
		{
			sheet->Cell(nRecordRowIndex, 0)->SetWString(itB->strShouJianRen.c_str());
			sheet->Cell(nRecordRowIndex, 1)->SetWString(itB->strShouJianRenDiZhi.c_str());
			sheet->Cell(nRecordRowIndex, 2)->SetWString(itB->strSheng.c_str());
			sheet->Cell(nRecordRowIndex, 3)->SetWString(itB->strWuLiuGongSi.c_str());
			sheet->Cell(nRecordRowIndex, 4)->SetWString(itB->strWuLiuDanHao.c_str());
			sheet->Cell(nRecordRowIndex, 5)->SetWString(itB->strZhongLiang.c_str());
			sheet->Cell(nRecordRowIndex, 6)->SetWString(itB->strFaHuoShijian.c_str());
			sheet->Cell(nRecordRowIndex, 7)->SetWString(itB->strHuoPinZongShuLiang.c_str());
			sheet->Cell(nRecordRowIndex, 8)->SetWString(itB->strHuoPinMingXi.c_str());
			nRecordRowIndex++;
			itB++;
		}
		return true;
	}
	return false;
}


bool Handle_MoHeKeJi()
{
	BasicExcel excel;
	if(!CreateExcel(excel, g_mapAllSalesInfo[L"ħ�ϿƼ�N"]))
		return false;
	wstring fileName = L"./Export_" + g_strYM + L"/" + L"ħ�ϿƼ�N_" + g_strYM + L"���˵�.xls";
	string _file = CFuncCommon::WString2String(fileName.c_str());
	excel.SaveAs(_file.c_str());
	CompareWithSFData(L"ħ�ϿƼ�N", g_mapAllSalesInfo[L"ħ�ϿƼ�N"]);
	return true;
}

bool Handle_YongChuangYaoHui()
{
	BasicExcel excel;
	if(!CreateExcel(excel, g_mapAllSalesInfo[L"����ҫ��"]))
		return false;
	wstring fileName = L"./Export_" + g_strYM + L"/" + L"����ҫ��_" + g_strYM + L"���˵�.xls";
	string _file = CFuncCommon::WString2String(fileName.c_str());
	excel.SaveAs(_file.c_str());
	CompareWithSFData(L"����ҫ��", g_mapAllSalesInfo[L"����ҫ��"]);
	return true;
}

bool Handle_MiYaShiQi()
{
	BasicExcel excel;
	if(!CreateExcel(excel, g_mapAllSalesInfo[L"����ʳ��"]))
		return false;
	wstring fileName = L"./Export_" + g_strYM + L"/" + L"����ʳ��_" + g_strYM + L"���˵�.xls";
	string _file = CFuncCommon::WString2String(fileName.c_str());
	excel.SaveAs(_file.c_str());
	CompareWithSFData(L"����ʳ��", g_mapAllSalesInfo[L"����ʳ��"]);
	return true;
}

bool LoadSFData()
{
	
	std::wstring strSFFileName = L"./��������/˳���˵�" + g_strYM + L".xls";
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
			if(strTitle == L"�˵�����")
				colNumber = c;
			else if(strTitle == L"�Ʒ�����")
				colWeight = c;
			else if(strTitle == L"��ֵ����")
				colVAServices = c;
			else if(strTitle == L"���˽��")
			{
				bFix = true;
				g_sfHandleCol = c;
			}
		}
		if(!bFix)
			sfSheet->Cell(0, maxCols)->SetWString(L"���˽��");
		for(size_t r = 1; r < maxRows; ++r)
		{
			sSFAuthData _data;
			const wchar_t* _pStr = NULL;
			SHEET_CELL(sfSheet, r, colNumber, _data.number);
			SHEET_CELL(sfSheet, r, colWeight, _data.weight);
			SHEET_CELL(sfSheet, r, colVAServices, _data.vaServices);
			_data.row = r;
			if(_data.vaServices == L"����")
			{
				sfSheet->Cell(r, g_sfHandleCol)->SetWString(L"1");
				continue;
			}
			_pStr = sfSheet->Cell(r, g_sfHandleCol)->GetWString();
			if(_pStr)
			{
				if(wcscmp(_pStr, L"1") == 0)
				{
					_data.bHandle = true;
					continue;
				}
			}
			g_mapSFAuthData[_data.number] = _data;
		}
	}
	else
	{
		THROW_ERROR(L"��ȡ˳���˵�ʧ��");
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