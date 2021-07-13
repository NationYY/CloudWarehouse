#pragma once
#include <string>
#include <map>
#include <set>
#include "BasicExcel.hpp"
using namespace YCompoundFiles;
using namespace YExcel;
using namespace std;

#define DOUBLE_PRECISION 0.00000001
typedef std::map<std::wstring, int> map_key_wstring_val_int;
typedef std::vector<std::wstring> vec_wvals;
typedef std::vector<std::wstring> split_wstr_vec;

struct sGoodsBaseInfo
{
	wstring chan_pin_ming;
	int xiang_gui;
	wstring zui_xiao_dan_wei;
	int ku_cun;
	int ban_shu_biao_zhun;
	double dan_jian_zhong_liang;
	double dan_jian_ti_ji;
	bool bPaoHuo;
}; 

struct sGoodsCangChuInfo
{
	wstring chan_pin_ming;
	int ku_cun;
	int ban_shu_biao_zhun;
};

struct sRuKuDetailInfo
{
	wstring chan_pin_ming;
	wstring dan_wei;
	int ru_ku_shu_liang;
	double zhong_liang;
	double ti_ji;
	wstring bei_zhu;
};

struct sRuKuBaseInfo
{
	int day;
	wstring lei_xing;
	list<sRuKuDetailInfo> detail_info;
	
};


struct sChuKuDetailInfo
{
	wstring chan_pin_ming;
	wstring dan_wei;
	int chu_ku_shu_liang;
	double zhong_liang;
	double ti_ji;
	int tie_biao;
	wstring bei_zhu;
};

struct sChuKuBaseInfo
{
	int day;
	wstring lei_xing;
	wstring bei_zhu;
	list<sChuKuDetailInfo> detail_info;
};

struct sZengZhiInfo
{
	int day;
	wstring lei_xing;
	int da_ka_ci_shu;
	int dai_ru_ku_ci_shu;
	int tie_biao_shu;
};