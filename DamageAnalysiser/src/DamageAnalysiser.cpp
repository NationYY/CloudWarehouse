// DamageAnalysiser.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <string>
#include <iostream>
#include "BasicExcel.hpp"
#include <iomanip>
#include "objbase.h"
#include <list>
#include <set>
#include <map>
#include <vector>
using namespace std;
using namespace YCompoundFiles;
using namespace YExcel;
#define THROW_ERROR(info) std::wcout<<info<<std::endl; system("pause");

#define SHEET_CELL_STRING(sheet, r, c, strOut) _pStr = sheet->Cell(r, c)->GetWString();\
if(_pStr)\
	strOut = _pStr;
typedef std::vector<std::wstring> split_wstr_vec;
typedef string::size_type(wstring::*find_t)(const wstring& delim, wstring::size_type offset) const;
void split(const wstring& s, const wstring& match, split_wstr_vec& out, bool removeEmpty = true, bool fullMatch = false)
{
	struct splite_wstr_inf
	{
		int start_index;
		int len;
	};

	const int MAX_SPLITE_STR_CNT = 4096;
	splite_wstr_inf ret_str_list[MAX_SPLITE_STR_CNT];

	int str_index = 0;

	wstring::size_type start = 0,           // starting position for searches
		skip = 1;            // positions to skip after a match
	find_t pfind = &wstring::find_first_of; // search algorithm for matches

	if(fullMatch)
	{
		// use the whole match string as a key
		// instead of individual characters
		// skip might be 0. see search loop comments
		skip = match.length();
		pfind = &wstring::find;
	}

	while(start != wstring::npos)
	{
		// get a complete range [start..end)
		string::size_type end = (s.*pfind)(match, start);

		// null strings always match in string::find, but
		// a skip of 0 causes infinite loops. pretend that
		// no tokens were found and extract the whole string
		if(skip == 0) end = wstring::npos;

		splite_wstr_inf& si = ret_str_list[str_index];
		si.start_index = start;
		si.len = end - start;

		//string token = s.substr(start, end - start); 
		//if(!(removeEmpty && token.empty()))

		if(!(removeEmpty && ((s[si.start_index] == '\0'))))
		{
			// extract the token and add it to the out list
			//out.push_back(token);
			splite_wstr_inf& si = ret_str_list[str_index++];
			si.start_index = start;
			si.len = end - start;

			if(str_index > MAX_SPLITE_STR_CNT)
			{
				int a = 0;
				int i = 1 / a;
				// 				const char* tr = "split too many item.";
				// 				throw exception(tr);
			}
		}

		// start the next range
		if((start = end) != wstring::npos) start += skip;
	}

	if(str_index > 0)
	{
		out.resize(str_index);
		const wchar_t *source = s.c_str();
		for(int i = 0; i < str_index; ++i)
		{
			splite_wstr_inf& si = ret_str_list[i];
			int len = si.len > 0 ? si.len : s.length() - si.start_index;
			out[i].assign(source + si.start_index, len);
		}
	}
}

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

typedef std::vector<std::wstring> vec_wvals;
bool parse_pairs(std::wstring src, vec_wvals &out, const wchar_t * de = L";")
{
	out.clear();
	if(src.size() == 0)
		return false;
	split(src.c_str(), de, out);
	if(!out.size())
		return false;
	return true;
}

struct SSaleInfo
{
	wstring strYanHuoYuan;
	set<wstring> setHuoPinMingXi;
	wstring strHuoPinMingXi;
};

struct SDamageInfo
{
	int damageCnt;
	int allCnt;
	SDamageInfo(): damageCnt(0), allCnt(0)
	{}
};

int _tmain(int argc, _TCHAR* argv[])
{
	std::wstring strPostSaleFileName = L"./销售退换单.xls";
	std::wstring strSaleDetailFileName = L"./销售出库明细.xls";
	std::wstring strSaleFileName = L"./销售出库单.xls";
	set<wstring> setDamageDingDanHao;
	set<wstring> setDamageYuanYin;
	map<wstring, SSaleInfo> mapSaleInfo;
	map<wstring, int> mapAllCntInfo;
	map<wstring, wstring> mapYuan2DingDan;
	//需要输出的
	map<wstring, int> mapYanHuoShuLiang; //每个人的验货数量
	map<wstring, int> mapDamagePerPerson; //每个人的破损单数
	map<wstring, SDamageInfo> mapDamageCntInfo;//每种发货品种的破损单数和总单数
	map< wstring, std::map<wstring, int> > mapDamageInfoPerson;//每个人破损的品种
	{
		BasicExcel saleExcel;
		std::string _strSaleFileName = WString2String(strSaleFileName.c_str());
		if(!saleExcel.Load(_strSaleFileName.c_str()))
		{
			THROW_ERROR(L"销售出库单 加载失败");
		}
		BasicExcelWorksheet* saleSheet = saleExcel.GetWorksheet(L"Sheet1");
		if(saleSheet)
		{
			size_t maxRows = saleSheet->GetTotalRows();
			size_t maxCols = saleSheet->GetTotalCols();

			int nHuoZhu = -1;
			int nDingDanBianHao = -1;
			int nYanHuoYuan = -1;
			int nYuanShiDanHao = -1;
			for(size_t c = 0; c < maxCols; ++c)
			{
				BasicExcelCell* cell = saleSheet->Cell(0, c);

				std::wstring strTitle = cell->GetWString();
				if(strTitle == L"货主")
					nHuoZhu = c;
				else if(strTitle == L"订单编号")
					nDingDanBianHao = c;
				else if(strTitle == L"验货员")
					nYanHuoYuan = c;
				else if(strTitle == L"原始单号")
					nYuanShiDanHao = c;
			}
			if(nHuoZhu == -1 || nDingDanBianHao == -1 || nYanHuoYuan == -1 || nYuanShiDanHao == -1)
			{
				THROW_ERROR(L"销售出库单 有标题未找到");
			}
			for(size_t r = 1; r < maxRows; ++r)
			{
				wstring strHuoZhu;
				wstring strDingDanBianHao;
				wstring strYanHuoYuan;
				wstring strYuanShiDanHao;
				const wchar_t* _pStr = NULL;
				SHEET_CELL_STRING(saleSheet, r, nHuoZhu, strHuoZhu);
				SHEET_CELL_STRING(saleSheet, r, nDingDanBianHao, strDingDanBianHao);
				SHEET_CELL_STRING(saleSheet, r, nYanHuoYuan, strYanHuoYuan);
				SHEET_CELL_STRING(saleSheet, r, nYuanShiDanHao, strYuanShiDanHao);
				if(strHuoZhu == L"永创耀辉")
				{
					SSaleInfo info;
					info.strYanHuoYuan = strYanHuoYuan;
					mapSaleInfo[strDingDanBianHao] = info;

					map<wstring, int>::iterator it = mapYanHuoShuLiang.find(strYanHuoYuan);
					if(it != mapYanHuoShuLiang.end())
						it->second++;
					else
						mapYanHuoShuLiang[strYanHuoYuan] = 1;
					vec_wvals vecYuanShiDanHao;
					if(parse_pairs(strYuanShiDanHao, vecYuanShiDanHao, L","))
					{
						for(int i=0; i<vecYuanShiDanHao.size(); ++i)
						{
							mapYuan2DingDan[vecYuanShiDanHao[i]] = strDingDanBianHao;
						}
					}
				}
			}
		}
	}
	{
		BasicExcel postSaleExcel;
		std::string _strPostSaleFileName = WString2String(strPostSaleFileName.c_str());
		if(!postSaleExcel.Load(_strPostSaleFileName.c_str()))
		{
			THROW_ERROR(L"销售退换单 加载失败");
		}
		BasicExcelWorksheet* postSaleSheet = postSaleExcel.GetWorksheet(L"Sheet1");
		if(postSaleSheet)
		{
			size_t maxRows = postSaleSheet->GetTotalRows();
			size_t maxCols = postSaleSheet->GetTotalCols();

			int nHuoZhu = -1;
			int nDingDanBianHao = -1;
			int nBeiZhu = -1;
			int nTuiHuanYuanYin = -1;
			int nZhuangTai = -1;
			for(size_t c = 0; c < maxCols; ++c)
			{
				BasicExcelCell* cell = postSaleSheet->Cell(0, c);
				std::wstring strTitle = cell->GetWString();
				if(strTitle == L"货主")
					nHuoZhu = c;
				else if(strTitle == L"订单编号")
					nDingDanBianHao = c;
				else if(strTitle == L"备注")
					nBeiZhu = c;
				else if(strTitle == L"退换原因")
					nTuiHuanYuanYin = c;
				else if(strTitle == L"状态")
					nZhuangTai = c;
			
			}
			if(nHuoZhu == -1 || nDingDanBianHao == -1 || nBeiZhu == -1 || nTuiHuanYuanYin == -1 || nZhuangTai == -1)
			{
				THROW_ERROR(L"销售退换单 有标题未找到");
			}
			for(size_t r = 1; r < maxRows; ++r)
			{
				wstring strHuoZhu;
				wstring strDingDanBianHao;
				wstring strBeiZhu;
				wstring strTuiHuanYuanYin;
				wstring strZhuangTai;
				const wchar_t* _pStr = NULL;
				SHEET_CELL_STRING(postSaleSheet, r, nHuoZhu, strHuoZhu);
				SHEET_CELL_STRING(postSaleSheet, r, nDingDanBianHao, strDingDanBianHao);
				SHEET_CELL_STRING(postSaleSheet, r, nBeiZhu, strBeiZhu);
				SHEET_CELL_STRING(postSaleSheet, r, nTuiHuanYuanYin, strTuiHuanYuanYin);
				SHEET_CELL_STRING(postSaleSheet, r, nZhuangTai, strZhuangTai);
			
				if(strZhuangTai != L"已取消" && (strBeiZhu.find(L"破") != wstring::npos || strBeiZhu.find(L"漏") != wstring::npos || strBeiZhu.find(L"损") != wstring::npos ||
					strTuiHuanYuanYin.find(L"破") != wstring::npos || strTuiHuanYuanYin.find(L"漏") != wstring::npos || strTuiHuanYuanYin.find(L"损") != wstring::npos) 
					&& strHuoZhu == L"永创耀辉")
				{
					bool bAdd = false;
					map<wstring, SSaleInfo>::iterator _itB = mapSaleInfo.find(strDingDanBianHao);
					if(_itB != mapSaleInfo.end())
					{
						setDamageDingDanHao.insert(strDingDanBianHao);
						bAdd = true;
					}
					else
					{
						vec_wvals vecDingDanBianHao;
						if(parse_pairs(strDingDanBianHao, vecDingDanBianHao, L"|"))
						{
							for(int i = 0; i < vecDingDanBianHao.size(); ++i)
							{
								map<wstring, wstring>::iterator it = mapYuan2DingDan.find(vecDingDanBianHao[i]);
								if(it != mapYuan2DingDan.end())
								{
									setDamageDingDanHao.insert(it->second);
									bAdd = true;
									break;
								}
							}
						}
					}
					if(bAdd)
					{
						if(strBeiZhu.find(L"破") != wstring::npos || strBeiZhu.find(L"漏") != wstring::npos || strBeiZhu.find(L"损") != wstring::npos)
							setDamageYuanYin.insert(strBeiZhu);
						if(strTuiHuanYuanYin.find(L"破") != wstring::npos || strTuiHuanYuanYin.find(L"漏") != wstring::npos || strTuiHuanYuanYin.find(L"损") != wstring::npos)
							setDamageYuanYin.insert(strTuiHuanYuanYin);
					}
				}
			}
		}
	}
	
	{
		BasicExcel saleDetailExcel;
		std::string _strSaleDetailFileName = WString2String(strSaleDetailFileName.c_str());
		if(!saleDetailExcel.Load(_strSaleDetailFileName.c_str()))
		{
			THROW_ERROR(L"销售出库明细 加载失败");
		}
		BasicExcelWorksheet* saleDetailSheet = saleDetailExcel.GetWorksheet(L"Sheet1");
		if(saleDetailSheet)
		{
			size_t maxRows = saleDetailSheet->GetTotalRows();
			size_t maxCols = saleDetailSheet->GetTotalCols();

			int nHuoPinMingCheng = -1;
			int nDingDanBianHao = -1;
			for(size_t c = 0; c < maxCols; ++c)
			{
				BasicExcelCell* cell = saleDetailSheet->Cell(0, c);

				std::wstring strTitle = cell->GetWString();
				if(strTitle == L"货品名称")
					nHuoPinMingCheng = c;
				else if(strTitle == L"订单编号")
					nDingDanBianHao = c;
			}
			if(nHuoPinMingCheng == -1 || nDingDanBianHao == -1)
			{
				THROW_ERROR(L"销售出库明细 有标题未找到");
			}
			for(size_t r = 1; r < maxRows; ++r)
			{
				wstring strHuoPinMingCheng;
				wstring strDingDanBianHao;
				const wchar_t* _pStr = NULL;
				SHEET_CELL_STRING(saleDetailSheet, r, nHuoPinMingCheng, strHuoPinMingCheng);
				SHEET_CELL_STRING(saleDetailSheet, r, nDingDanBianHao, strDingDanBianHao);
				map<wstring, SSaleInfo>::iterator it = mapSaleInfo.find(strDingDanBianHao);
				if(it != mapSaleInfo.end())
					it->second.setHuoPinMingXi.insert(strHuoPinMingCheng);
			}
			map<wstring, SSaleInfo>::iterator itB = mapSaleInfo.begin();
			map<wstring, SSaleInfo>::iterator itE = mapSaleInfo.end();
			while(itB != itE)
			{
				if(itB->second.setHuoPinMingXi.size() == 0)
				{
					wchar_t szBuffer[128] = { 0 };
					wsprintfW(szBuffer, L"订单货品明细为空[%s]", itB->first.c_str());
					THROW_ERROR(szBuffer);
				}
				set<wstring>::iterator itSB = itB->second.setHuoPinMingXi.begin();
				set<wstring>::iterator itSE = itB->second.setHuoPinMingXi.end();
				while(itSB != itSE)
				{
					itB->second.strHuoPinMingXi += *itSB;
					itB->second.strHuoPinMingXi += L"@";
					++itSB;
				}
				++itB;
			}
		}
	}
	//开始分析
	{
		set<wstring>::iterator itB = setDamageDingDanHao.begin();
		set<wstring>::iterator itE = setDamageDingDanHao.end();
		while(itB != itE)
		{
			map<wstring, SSaleInfo>::iterator _itB = mapSaleInfo.find(*itB);
			if(_itB != mapSaleInfo.end())
			{
				map<wstring, int>::iterator itAllCntInfo = mapAllCntInfo.find(_itB->second.strHuoPinMingXi);
				if(itAllCntInfo == mapAllCntInfo.end())
				{
					mapAllCntInfo[_itB->second.strHuoPinMingXi] = 0;
					map<wstring, SSaleInfo>::iterator itSaleInfoB = mapSaleInfo.begin();
					map<wstring, SSaleInfo>::iterator itSaleInfoE = mapSaleInfo.end();
					while(itSaleInfoB != itSaleInfoE)
					{
						if(itSaleInfoB->second.strHuoPinMingXi == _itB->second.strHuoPinMingXi)
							mapAllCntInfo[_itB->second.strHuoPinMingXi]++;
						++itSaleInfoB;
					}
					itAllCntInfo = mapAllCntInfo.find(_itB->second.strHuoPinMingXi);
				}
				map<wstring, SDamageInfo>::iterator itDamageCntInfo = mapDamageCntInfo.find(_itB->second.strHuoPinMingXi);
				if(itDamageCntInfo != mapDamageCntInfo.end())
					itDamageCntInfo->second.damageCnt++;
				else
				{
					mapDamageCntInfo[_itB->second.strHuoPinMingXi].allCnt = itAllCntInfo->second;
					mapDamageCntInfo[_itB->second.strHuoPinMingXi].damageCnt = 1;
				}
				map<wstring, int>::iterator itDamagePerPerson = mapDamagePerPerson.find(_itB->second.strYanHuoYuan);
				if(itDamagePerPerson != mapDamagePerPerson.end())
					itDamagePerPerson->second++;
				else
					mapDamagePerPerson[_itB->second.strYanHuoYuan] = 1;

				std::map<wstring, int>::iterator ___it = mapDamageInfoPerson[_itB->second.strYanHuoYuan].find(_itB->second.strHuoPinMingXi);
				if(___it ==  mapDamageInfoPerson[_itB->second.strYanHuoYuan].end())
					 mapDamageInfoPerson[_itB->second.strYanHuoYuan][_itB->second.strHuoPinMingXi] = 1;
				else
					___it->second++;
			}
			++itB;
		}
	}
	{
		BasicExcel excel;
		excel.AddWorksheet(L"汇总");
		//map<wstring, int>::iterator itB = mapYanHuoShuLiang.begin();
		//map<wstring, int>::iterator itE = mapYanHuoShuLiang.end();
		//while(itB != itE)
		//{
		//	excel.AddWorksheet(itB->first.c_str());
		//	++itB;
		//}
		BasicExcelWorksheet* sheet = excel.GetWorksheet(L"汇总");
		int rIndex = 0;
		sheet->Cell(rIndex++, 0)->SetWString(L"[打包概况]");
		map<wstring, int>::iterator itB = mapYanHuoShuLiang.begin();
		map<wstring, int>::iterator itE = mapYanHuoShuLiang.end();
		while(itB != itE)
		{
			
			sheet->Cell(rIndex, 0)->SetWString(itB->first.c_str());
			sheet->Cell(rIndex, 1)->SetWString(L"打包单数:");
			sheet->Cell(rIndex, 2)->SetInteger(itB->second);
			sheet->Cell(rIndex, 3)->SetWString(L"破损单数:");
			int nP = 0;
			map<wstring, int>::iterator itP = mapDamagePerPerson.find(itB->first);
			if(itP == mapDamagePerPerson.end())
			{
				sheet->Cell(rIndex, 4)->SetInteger(0);
				nP = 0;
			}
			else
			{
				sheet->Cell(rIndex, 4)->SetInteger(itP->second);
				nP = itP->second;
			}
			sheet->Cell(rIndex, 5)->SetWString(L"破损率:");
			wchar_t out[32] = {0};
			swprintf(out, L"%.2f%%", (double(nP)/double(itB->second))*100);
			sheet->Cell(rIndex, 6)->SetWString(out);
			rIndex++;
			++itB;
		}

		sheet->Cell(rIndex++, 0)->SetWString(L"[破损品类统计]");
		map<wstring, SDamageInfo>::iterator itB1 = mapDamageCntInfo.begin();
		map<wstring, SDamageInfo>::iterator itE1 = mapDamageCntInfo.end();
		while(itB1 != itE1)
		{
			sheet->Cell(rIndex, 0)->SetWString(itB1->first.c_str());
			sheet->Cell(rIndex, 1)->SetWString(L"打包单数:");
			sheet->Cell(rIndex, 2)->SetInteger(itB1->second.allCnt);
			sheet->Cell(rIndex, 3)->SetWString(L"破损单数:");
			sheet->Cell(rIndex, 4)->SetInteger(itB1->second.damageCnt);
			sheet->Cell(rIndex, 5)->SetWString(L"破损率:");
			wchar_t out[32] = { 0 };
			swprintf(out, L"%.2f%%", (double(itB1->second.damageCnt)/double(itB1->second.allCnt))*100);
			sheet->Cell(rIndex, 6)->SetWString(out);
			rIndex++;
			++itB1;
		}
		sheet->Cell(rIndex++, 0)->SetWString(L"[每个人破损品类统计]");
		map< wstring, std::map<wstring, int> >::iterator itB2 = mapDamageInfoPerson.begin();
		map< wstring, std::map<wstring, int> >::iterator itE2 = mapDamageInfoPerson.end();
		while(itB2 != itE2)
		{
			wstring name = L"---";
			name += itB2->first;
			name += L"---";
			sheet->Cell(rIndex++, 0)->SetWString(name.c_str());
			std::map<wstring, int>::iterator itB3 = itB2->second.begin();
			std::map<wstring, int>::iterator itE3 = itB2->second.end();
			while(itB3 != itE3)
			{
				sheet->Cell(rIndex, 0)->SetWString(itB3->first.c_str());
				sheet->Cell(rIndex, 1)->SetInteger(itB3->second);
				rIndex++;
				++itB3;
			}
			++itB2;
		}
		excel.SaveAs("./破损分析.xls");
	}
	return 0;
}

