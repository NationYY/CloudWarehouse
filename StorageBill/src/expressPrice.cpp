#include "stdafx.h"
#include "expressPrice.h"
//------------------------------------快递价格--------------------------------------//
std::map< std::wstring, std::list<sExpressPriceInfo> > g_taiFuShangMaoBSPrice;
std::map< std::wstring, std::list<sExpressPriceInfo> > g_yiMaiKeJiBSPrice;
std::map< std::wstring, std::list<sExpressPriceInfo> > g_qiYiJiangYuanBSPrice;
std::map< std::wstring, std::list<sExpressPriceInfo> > g_xinMaBangBSPrice;
std::map< std::wstring, std::list<sExpressPriceInfo> > g_miYaBSPrice;
std::map< std::wstring, std::list<sExpressPriceInfo> > g_kunLunShanYTPrice;
std::map< std::wstring, std::list<sExpressPriceInfo> > g_yongChuangYaoHuiKDPrice;
std::map< std::wstring, std::list<sExpressPriceInfo> > g_laFengQingKDPrice;
std::map< std::wstring, std::list<sExpressPriceInfo> > g_zhiShanBSKDPrice;
std::map< std::wstring, std::list<sExpressPriceInfo> > g_zhiShanQTKDPrice;
//----------------------------------------------------------------------------------//

//------------------------------------顺丰价格--------------------------------------//
//永创耀辉
std::vector< std::list<sExpressPriceInfo> > g_yongChuangYaoHuiSFPrice;
//弥雅
std::vector< std::list<sExpressPriceInfo> > g_miYaSFPrice;
//七一酱园
std::vector< std::list<sExpressPriceInfo> > g_qiYiJiangYuanSFPrice;
//----------------------------------------------------------------------------------//


//------------------------------------快运价格--------------------------------------//
//永创耀辉
std::map< std::wstring, sLargeExpressPriceInfo > g_yongChuangYaoHuiZTKYPrice;
//新马帮
std::map< std::wstring, sLargeExpressPriceInfo > g_xinMaBangZTKYPrice;
//颐麦科技
std::map< std::wstring, sLargeExpressPriceInfo > g_yiMaiKeJiZTKYPrice;
//弥雅
std::map< std::wstring, sLargeExpressPriceInfo > g_miYaZTKYPrice;
//七一酱园
std::map< std::wstring, sLargeExpressPriceInfo > g_qiYiJiangYuanZTKYPrice;
//----------------------------------------------------------------------------------//


//----------------------------------成本核算价格用---------------------------------//
std::map< std::wstring, sLargeExpressPriceInfo > g_chengBenZTKYPrice;

//----------------------------------多多买菜---------------------------------------//
std::map< std::wstring, sDuoDuoMaiCaiPriceInfo > g_duoDuoMaiCaiPrice;

void PrepareExpressPrice()
{
	
	//最小重量 最大重量  首重	首重费用	续重费用
	//泰福商贸
	{
		//0-3公斤 一口价
		g_taiFuShangMaoBSPrice[L"四川省"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"重庆"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"云南省"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"贵州省"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"陕西省"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"江苏省"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"浙江省"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"上海"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"安徽省"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"河南省"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"湖北省"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"福建省"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"北京"].push_back({ 0, 3, 3, 4.2, 0 });
		g_taiFuShangMaoBSPrice[L"天津"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"广东省"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"广西壮族自治区"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"河北省"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"湖南省"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"江西省"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"山西省"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"山东省"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"甘肃省"].push_back({ 0, 3, 3, 4.2, 0 });
		g_taiFuShangMaoBSPrice[L"宁夏回族自治区"].push_back({ 0, 3, 3, 4.2, 0 });
		g_taiFuShangMaoBSPrice[L"青海省"].push_back({ 0, 3, 3, 4.2, 0 });
		g_taiFuShangMaoBSPrice[L"黑龙江省"].push_back({ 0, 3, 3, 4.2, 0 });
		g_taiFuShangMaoBSPrice[L"吉林省"].push_back({ 0, 3, 3, 4.2, 0 });
		g_taiFuShangMaoBSPrice[L"辽宁省"].push_back({ 0, 3, 3, 4.2, 0 });
		//3公斤以上
		g_taiFuShangMaoBSPrice[L"四川省"].push_back({ 3, 0, 1, 3.8, 1.2 });
		g_taiFuShangMaoBSPrice[L"重庆"].push_back({ 3, 0, 1, 3.8, 1.7 });
		g_taiFuShangMaoBSPrice[L"云南省"].push_back({ 3, 0, 1, 3.8, 1.7 });
		g_taiFuShangMaoBSPrice[L"贵州省"].push_back({ 3, 0, 1, 3.8, 1.7 });
		g_taiFuShangMaoBSPrice[L"陕西省"].push_back({ 3, 0, 1, 3.8, 1.7 });
		g_taiFuShangMaoBSPrice[L"江苏省"].push_back({ 3, 0, 1, 3.8, 1.7 });
		g_taiFuShangMaoBSPrice[L"浙江省"].push_back({ 3, 0, 1, 3.8, 1.7 });
		g_taiFuShangMaoBSPrice[L"上海"].push_back({ 3, 0, 1, 3.8, 2 });
		g_taiFuShangMaoBSPrice[L"安徽省"].push_back({ 3, 0, 1, 3.8, 1.7 });
		g_taiFuShangMaoBSPrice[L"河南省"].push_back({ 3, 0, 1, 3.8, 1.7 });
		g_taiFuShangMaoBSPrice[L"湖北省"].push_back({ 3, 0, 1, 3.8, 1.7 });
		g_taiFuShangMaoBSPrice[L"福建省"].push_back({ 3, 0, 1, 3.8, 1.7 });
		g_taiFuShangMaoBSPrice[L"北京"].push_back({ 3, 0, 1, 4.2, 2 });
		g_taiFuShangMaoBSPrice[L"天津"].push_back({ 3, 0, 1, 3.8, 1.7 });
		g_taiFuShangMaoBSPrice[L"广东省"].push_back({ 3, 0, 1, 3.8, 1.7 });
		g_taiFuShangMaoBSPrice[L"广西壮族自治区"].push_back({ 3, 0, 1, 3.8, 1.7 });
		g_taiFuShangMaoBSPrice[L"河北省"].push_back({ 3, 0, 1, 3.8, 1.7 });
		g_taiFuShangMaoBSPrice[L"湖南省"].push_back({ 3, 0, 1, 3.8, 1.7 });
		g_taiFuShangMaoBSPrice[L"江西省"].push_back({ 3, 0, 1, 3.8, 1.7 });
		g_taiFuShangMaoBSPrice[L"山西省"].push_back({ 3, 0, 1, 3.8, 1.7 });
		g_taiFuShangMaoBSPrice[L"山东省"].push_back({ 3, 0, 1, 3.8, 1.7 });
		g_taiFuShangMaoBSPrice[L"甘肃省"].push_back({ 3, 0, 1, 4.2, 2.2 });
		g_taiFuShangMaoBSPrice[L"宁夏回族自治区"].push_back({ 3, 0, 1, 4.2, 2.4 });
		g_taiFuShangMaoBSPrice[L"青海省"].push_back({ 3, 0, 1, 4.2, 2.4 });
		g_taiFuShangMaoBSPrice[L"黑龙江省"].push_back({ 3, 0, 1, 4.2, 2.5 });
		g_taiFuShangMaoBSPrice[L"吉林省"].push_back({ 3, 0, 1, 4.2, 2.2 });
		g_taiFuShangMaoBSPrice[L"辽宁省"].push_back({ 3, 0, 1, 4.2, 1.7 });
	}
	//颐麦科技
	{
		//0-3公斤 一口价
		g_yiMaiKeJiBSPrice[L"上海"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"北京"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"河南省"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"江苏省"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"浙江省"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"安徽省"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"山东省"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"天津"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"河北省"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"湖南省"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"湖北省"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"山西省"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"陕西省"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"江西省"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"广东省"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"福建省"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"广西壮族自治区"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"四川省"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"重庆"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"云南省"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"贵州省"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"甘肃省"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"宁夏回族自治区"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"青海省"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"黑龙江省"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"吉林省"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"辽宁省"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"内蒙古自治区"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"海南省"].push_back({ 0, 3, 3, 3.4, 0 });
		//
		g_yiMaiKeJiBSPrice[L"新疆维吾尔自治区"].push_back({ 0, 0, 1, 15.5, 13.5 });
		g_yiMaiKeJiBSPrice[L"西藏自治区"].push_back({ 0, 0, 1, 17.5, 17.5 });
		//3公斤以上
		g_yiMaiKeJiBSPrice[L"上海"].push_back({ 3, 0, 3, 5, 1.5 });
		g_yiMaiKeJiBSPrice[L"北京"].push_back({ 3, 0, 3, 5, 1.5 });
		g_yiMaiKeJiBSPrice[L"河南省"].push_back({ 3, 0, 3, 5, 1.3 });
		g_yiMaiKeJiBSPrice[L"江苏省"].push_back({ 3, 0, 3, 5, 1.3 });
		g_yiMaiKeJiBSPrice[L"浙江省"].push_back({ 3, 0, 3, 5, 1.3 });
		g_yiMaiKeJiBSPrice[L"安徽省"].push_back({ 3, 0, 3, 5, 1.3 });
		g_yiMaiKeJiBSPrice[L"山东省"].push_back({ 3, 0, 3, 5, 1.3 });
		g_yiMaiKeJiBSPrice[L"天津"].push_back({ 3, 0, 3, 5, 1.3 });
		g_yiMaiKeJiBSPrice[L"河北省"].push_back({ 3, 0, 3, 5, 1.3 });
		g_yiMaiKeJiBSPrice[L"湖南省"].push_back({ 3, 0, 3, 5, 1.3 });
		g_yiMaiKeJiBSPrice[L"湖北省"].push_back({ 3, 0, 3, 5, 1.3 });
		g_yiMaiKeJiBSPrice[L"山西省"].push_back({ 3, 0, 3, 5, 1.3 });
		g_yiMaiKeJiBSPrice[L"陕西省"].push_back({ 3, 0, 3, 5, 1.3 });
		g_yiMaiKeJiBSPrice[L"江西省"].push_back({ 3, 0, 3, 5, 1.3 });
		g_yiMaiKeJiBSPrice[L"广东省"].push_back({ 3, 0, 3, 5, 1.3 });
		g_yiMaiKeJiBSPrice[L"福建省"].push_back({ 3, 0, 3, 5, 1.3 });
		g_yiMaiKeJiBSPrice[L"广西壮族自治区"].push_back({ 3, 0, 3, 5, 1.3 });
		g_yiMaiKeJiBSPrice[L"四川省"].push_back({ 3, 0, 3, 5, 1 });
		g_yiMaiKeJiBSPrice[L"重庆"].push_back({ 3, 0, 3, 5, 1.2 });
		g_yiMaiKeJiBSPrice[L"云南省"].push_back({ 3, 0, 3, 5, 1.2 });
		g_yiMaiKeJiBSPrice[L"贵州省"].push_back({ 3, 0, 3, 5, 1.2 });
		g_yiMaiKeJiBSPrice[L"甘肃省"].push_back({ 3, 0, 3, 5, 1.8 });
		g_yiMaiKeJiBSPrice[L"宁夏回族自治区"].push_back({ 3, 0, 3, 5, 1.8 });
		g_yiMaiKeJiBSPrice[L"青海省"].push_back({ 3, 0, 3, 5, 1.8 });
		g_yiMaiKeJiBSPrice[L"黑龙江省"].push_back({ 3, 0, 3, 5, 2 });
		g_yiMaiKeJiBSPrice[L"吉林省"].push_back({ 3, 0, 3, 5, 2 });
		g_yiMaiKeJiBSPrice[L"辽宁省"].push_back({ 3, 0, 3, 5, 2 });
		g_yiMaiKeJiBSPrice[L"内蒙古自治区"].push_back({ 3, 0, 3, 6.5, 5.5 });
		g_yiMaiKeJiBSPrice[L"海南省"].push_back({ 3, 0, 3, 5, 4 });
	}
	//七一酱园
	{
		//0-3公斤 一口价
		g_qiYiJiangYuanBSPrice[L"四川省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_qiYiJiangYuanBSPrice[L"重庆"].push_back({ 0, 3, 3, 3.5, 0 });
		g_qiYiJiangYuanBSPrice[L"云南省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_qiYiJiangYuanBSPrice[L"贵州省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_qiYiJiangYuanBSPrice[L"陕西省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_qiYiJiangYuanBSPrice[L"江苏省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_qiYiJiangYuanBSPrice[L"浙江省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_qiYiJiangYuanBSPrice[L"上海"].push_back({ 0, 3, 3, 3.5, 0 });
		g_qiYiJiangYuanBSPrice[L"安徽省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_qiYiJiangYuanBSPrice[L"河南省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_qiYiJiangYuanBSPrice[L"湖北省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_qiYiJiangYuanBSPrice[L"福建省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_qiYiJiangYuanBSPrice[L"北京"].push_back({ 0, 3, 3, 3.5, 0 });
		g_qiYiJiangYuanBSPrice[L"天津"].push_back({ 0, 3, 3, 3.5, 0 });
		g_qiYiJiangYuanBSPrice[L"广东省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_qiYiJiangYuanBSPrice[L"广西壮族自治区"].push_back({ 0, 3, 3, 3.5, 0 });
		g_qiYiJiangYuanBSPrice[L"河北省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_qiYiJiangYuanBSPrice[L"湖南省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_qiYiJiangYuanBSPrice[L"江西省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_qiYiJiangYuanBSPrice[L"山西省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_qiYiJiangYuanBSPrice[L"山东省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_qiYiJiangYuanBSPrice[L"甘肃省"].push_back({ 0, 3, 3, 4.5, 0 });
		g_qiYiJiangYuanBSPrice[L"宁夏回族自治区"].push_back({ 0, 3, 3, 4.5, 0 });
		g_qiYiJiangYuanBSPrice[L"青海省"].push_back({ 0, 3, 3, 4.5, 0 });
		g_qiYiJiangYuanBSPrice[L"黑龙江省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_qiYiJiangYuanBSPrice[L"吉林省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_qiYiJiangYuanBSPrice[L"辽宁省"].push_back({ 0, 3, 3, 3.5, 0 });
		//
		g_qiYiJiangYuanBSPrice[L"内蒙古自治区"].push_back({ 0, 0, 1, 9, 5 });
		g_qiYiJiangYuanBSPrice[L"海南省"].push_back({ 0, 0, 1, 9, 5 });
		g_qiYiJiangYuanBSPrice[L"新疆维吾尔自治区"].push_back({ 0, 0, 1, 15, 13 });
		g_qiYiJiangYuanBSPrice[L"西藏自治区"].push_back({ 0, 0, 1, 17, 17 });
		//3-5公斤
		g_qiYiJiangYuanBSPrice[L"四川省"].push_back({ 3, 5, 3, 4.5, 1.6 });
		g_qiYiJiangYuanBSPrice[L"重庆"].push_back({ 3, 5, 3, 4.5, 1.8 });
		g_qiYiJiangYuanBSPrice[L"云南省"].push_back({ 3, 5, 3, 4.5, 1.8 });
		g_qiYiJiangYuanBSPrice[L"贵州省"].push_back({ 3, 5, 3, 4.5, 1.8 });
		g_qiYiJiangYuanBSPrice[L"陕西省"].push_back({ 3, 5, 3, 4.5, 1.8 });
		g_qiYiJiangYuanBSPrice[L"江苏省"].push_back({ 3, 5, 3, 4.5, 1.8 });
		g_qiYiJiangYuanBSPrice[L"浙江省"].push_back({ 3, 5, 3, 4.5, 1.8 });
		g_qiYiJiangYuanBSPrice[L"上海"].push_back({ 3, 5, 3, 4.5, 1.8 });
		g_qiYiJiangYuanBSPrice[L"安徽省"].push_back({ 3, 5, 3, 4.5, 1.8 });
		g_qiYiJiangYuanBSPrice[L"河南省"].push_back({ 3, 5, 3, 4.5, 1.8 });
		g_qiYiJiangYuanBSPrice[L"湖北省"].push_back({ 3, 5, 3, 4.5, 1.8 });
		g_qiYiJiangYuanBSPrice[L"福建省"].push_back({ 3, 5, 3, 4.5, 1.8 });
		g_qiYiJiangYuanBSPrice[L"北京"].push_back({ 3, 5, 3, 4.5, 1.8 });
		g_qiYiJiangYuanBSPrice[L"天津"].push_back({ 3, 5, 3, 4.5, 1.8 });
		g_qiYiJiangYuanBSPrice[L"广东省"].push_back({ 3, 5, 3, 4.5, 1.8 });
		g_qiYiJiangYuanBSPrice[L"广西壮族自治区"].push_back({ 3, 5, 3, 4.5, 1.8 });
		g_qiYiJiangYuanBSPrice[L"河北省"].push_back({ 3, 5, 3, 4.5, 1.8 });
		g_qiYiJiangYuanBSPrice[L"湖南省"].push_back({ 3, 5, 3, 4.5, 1.8 });
		g_qiYiJiangYuanBSPrice[L"江西省"].push_back({ 3, 5, 3, 4.5, 1.8 });
		g_qiYiJiangYuanBSPrice[L"山西省"].push_back({ 3, 5, 3, 4.5, 1.8 });
		g_qiYiJiangYuanBSPrice[L"山东省"].push_back({ 3, 5, 3, 4.5, 1.8 });
		g_qiYiJiangYuanBSPrice[L"甘肃省"].push_back({ 3, 5, 3, 4.5, 2.5 });
		g_qiYiJiangYuanBSPrice[L"宁夏回族自治区"].push_back({ 3, 5, 3, 4.5, 2.5 });
		g_qiYiJiangYuanBSPrice[L"青海省"].push_back({ 3, 5, 3, 4.5, 2.5 });
		g_qiYiJiangYuanBSPrice[L"黑龙江省"].push_back({ 3, 5, 3, 4.5, 2.5 });
		g_qiYiJiangYuanBSPrice[L"吉林省"].push_back({ 3, 5, 3, 4.5, 2.5 });
		g_qiYiJiangYuanBSPrice[L"辽宁省"].push_back({ 3, 5, 3, 4.5, 2.5 });
		//5公斤以上
		g_qiYiJiangYuanBSPrice[L"四川省"].push_back({ 5, 0, 1, 4.2, 1.6 });
		g_qiYiJiangYuanBSPrice[L"重庆"].push_back({ 5, 0, 1, 4.2, 1.8 });
		g_qiYiJiangYuanBSPrice[L"云南省"].push_back({ 5, 0, 1, 4.2, 3.2 });
		g_qiYiJiangYuanBSPrice[L"贵州省"].push_back({ 5, 0, 1, 4.2, 3.2 });
		g_qiYiJiangYuanBSPrice[L"陕西省"].push_back({ 5, 0, 1, 4.2, 3.2 });
		g_qiYiJiangYuanBSPrice[L"江苏省"].push_back({ 5, 0, 1, 4.2, 3.2 });
		g_qiYiJiangYuanBSPrice[L"浙江省"].push_back({ 5, 0, 1, 4.2, 3.2 });
		g_qiYiJiangYuanBSPrice[L"上海"].push_back({ 5, 0, 1, 4.2, 3.2 });
		g_qiYiJiangYuanBSPrice[L"安徽省"].push_back({ 5, 0, 1, 4.2, 3.2 });
		g_qiYiJiangYuanBSPrice[L"河南省"].push_back({ 5, 0, 1, 4.2, 3.2 });
		g_qiYiJiangYuanBSPrice[L"湖北省"].push_back({ 5, 0, 1, 4.2, 3.2 });
		g_qiYiJiangYuanBSPrice[L"福建省"].push_back({ 5, 0, 1, 4.2, 3.2 });
		g_qiYiJiangYuanBSPrice[L"北京"].push_back({ 5, 0, 1, 4.2, 3.2 });
		g_qiYiJiangYuanBSPrice[L"天津"].push_back({ 5, 0, 1, 4.2, 3.2 });
		g_qiYiJiangYuanBSPrice[L"广东省"].push_back({ 5, 0, 1, 4.2, 3.2 });
		g_qiYiJiangYuanBSPrice[L"广西壮族自治区"].push_back({ 5, 0, 1, 4.2, 3.2 });
		g_qiYiJiangYuanBSPrice[L"河北省"].push_back({ 5, 0, 1, 4.2, 3.2 });
		g_qiYiJiangYuanBSPrice[L"湖南省"].push_back({ 5, 0, 1, 4.2, 3.2 });
		g_qiYiJiangYuanBSPrice[L"江西省"].push_back({ 5, 0, 1, 4.2, 3.2 });
		g_qiYiJiangYuanBSPrice[L"山西省"].push_back({ 5, 0, 1, 4.2, 3.2 });
		g_qiYiJiangYuanBSPrice[L"山东省"].push_back({ 5, 0, 1, 4.2, 3.2 });
		g_qiYiJiangYuanBSPrice[L"甘肃省"].push_back({ 5, 0, 1, 4.2, 5.2 });
		g_qiYiJiangYuanBSPrice[L"宁夏回族自治区"].push_back({ 5, 0, 1, 4.2, 5.2 });
		g_qiYiJiangYuanBSPrice[L"青海省"].push_back({ 5, 0, 1, 4.2, 5.2 });
		g_qiYiJiangYuanBSPrice[L"黑龙江省"].push_back({ 5, 0, 1, 4.2, 6.2 });
		g_qiYiJiangYuanBSPrice[L"吉林省"].push_back({ 5, 0, 1, 4.2, 6.2 });
		g_qiYiJiangYuanBSPrice[L"辽宁省"].push_back({ 5, 0, 1, 4.2, 6.2 });
	}
	//新马帮
	{
		//0-3公斤 一口价
		g_xinMaBangBSPrice[L"上海"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"北京"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"河南省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"江苏省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"浙江省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"安徽省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"山东省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"天津"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"河北省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"湖南省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"湖北省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"山西省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"陕西省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"江西省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"广东省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"福建省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"广西壮族自治区"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"四川省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"重庆"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"云南省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"贵州省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"甘肃省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"宁夏回族自治区"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"青海省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"黑龙江省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"吉林省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"辽宁省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"海南省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"内蒙古自治区"].push_back({ 0, 3, 3, 3.5, 0 });
		//
		g_xinMaBangBSPrice[L"新疆维吾尔自治区"].push_back({ 0, 0, 1, 15.5, 14 });
		g_xinMaBangBSPrice[L"西藏自治区"].push_back({ 0, 0, 1, 17.5, 18 });
		//3-5公斤 一口价
		g_xinMaBangBSPrice[L"上海"].push_back({ 3, 5, 3, 4.3, 0 });
		g_xinMaBangBSPrice[L"北京"].push_back({ 3, 5, 3, 4.3, 0 });
		g_xinMaBangBSPrice[L"河南省"].push_back({ 3, 5, 3, 4.3, 0 });
		g_xinMaBangBSPrice[L"江苏省"].push_back({ 3, 5, 3, 4.3, 0 });
		g_xinMaBangBSPrice[L"浙江省"].push_back({ 3, 5, 3, 4.3, 0 });
		g_xinMaBangBSPrice[L"安徽省"].push_back({ 3, 5, 3, 4.3, 0 });
		g_xinMaBangBSPrice[L"山东省"].push_back({ 3, 5, 3, 4.3, 0 });
		g_xinMaBangBSPrice[L"天津"].push_back({ 3, 5, 3, 4.3, 0 });
		g_xinMaBangBSPrice[L"河北省"].push_back({ 3, 5, 3, 4.3, 0 });
		g_xinMaBangBSPrice[L"湖南省"].push_back({ 3, 5, 3, 4.3, 0 });
		g_xinMaBangBSPrice[L"湖北省"].push_back({ 3, 5, 3, 4.3, 0 });
		g_xinMaBangBSPrice[L"山西省"].push_back({ 3, 5, 3, 4.3, 0 });
		g_xinMaBangBSPrice[L"陕西省"].push_back({ 3, 5, 3, 4.3, 0 });
		g_xinMaBangBSPrice[L"江西省"].push_back({ 3, 5, 3, 4.3, 0 });
		g_xinMaBangBSPrice[L"广东省"].push_back({ 3, 5, 3, 4.3, 0 });
		g_xinMaBangBSPrice[L"福建省"].push_back({ 3, 5, 3, 4.3, 0 });
		g_xinMaBangBSPrice[L"广西壮族自治区"].push_back({ 3, 5, 3, 4.3, 0 });
		g_xinMaBangBSPrice[L"四川省"].push_back({ 3, 5, 3, 4.3, 0 });
		g_xinMaBangBSPrice[L"重庆"].push_back({ 3, 5, 3, 4.3, 0 });
		g_xinMaBangBSPrice[L"云南省"].push_back({ 3, 5, 3, 4.3, 0 });
		g_xinMaBangBSPrice[L"贵州省"].push_back({ 3, 5, 3, 4.3, 0 });
		g_xinMaBangBSPrice[L"甘肃省"].push_back({ 3, 5, 3, 4.5, 0 });
		g_xinMaBangBSPrice[L"宁夏回族自治区"].push_back({ 3, 5, 3, 4.5, 0 });
		g_xinMaBangBSPrice[L"青海省"].push_back({ 3, 5, 3, 4.5, 0 });
		g_xinMaBangBSPrice[L"黑龙江省"].push_back({ 3, 5, 3, 4.5, 0 });
		g_xinMaBangBSPrice[L"吉林省"].push_back({ 3, 5, 3, 4.5, 0 });
		g_xinMaBangBSPrice[L"辽宁省"].push_back({ 3, 5, 3, 4.5, 0 });
		g_xinMaBangBSPrice[L"海南省"].push_back({ 3, 5, 3, 5.3, 0 });
		g_xinMaBangBSPrice[L"内蒙古自治区"].push_back({ 3, 5, 3, 5.3, 0 });
		//5公斤以上
		g_xinMaBangBSPrice[L"上海"].push_back({ 5, 0, 3, 5, 1.4 });
		g_xinMaBangBSPrice[L"北京"].push_back({ 5, 0, 3, 5, 1.4 });
		g_xinMaBangBSPrice[L"河南省"].push_back({ 5, 0, 3, 5, 1.2 });
		g_xinMaBangBSPrice[L"江苏省"].push_back({ 5, 0, 3, 5, 1.2 });
		g_xinMaBangBSPrice[L"浙江省"].push_back({ 5, 0, 3, 5, 1.2 });
		g_xinMaBangBSPrice[L"安徽省"].push_back({ 5, 0, 3, 5, 1.2 });
		g_xinMaBangBSPrice[L"山东省"].push_back({ 5, 0, 3, 5, 1.2 });
		g_xinMaBangBSPrice[L"天津"].push_back({ 5, 0, 3, 5, 1.2 });
		g_xinMaBangBSPrice[L"河北省"].push_back({ 5, 0, 3, 5, 1.2 });
		g_xinMaBangBSPrice[L"湖南省"].push_back({ 5, 0, 3, 5, 1.2 });
		g_xinMaBangBSPrice[L"湖北省"].push_back({ 5, 0, 3, 5, 1.2 });
		g_xinMaBangBSPrice[L"山西省"].push_back({ 5, 0, 3, 5, 1.2 });
		g_xinMaBangBSPrice[L"陕西省"].push_back({ 5, 0, 3, 5, 1.2 });
		g_xinMaBangBSPrice[L"江西省"].push_back({ 5, 0, 3, 5, 1.2 });
		g_xinMaBangBSPrice[L"广东省"].push_back({ 5, 0, 3, 5, 1.2 });
		g_xinMaBangBSPrice[L"福建省"].push_back({ 5, 0, 3, 5, 1.2 });
		g_xinMaBangBSPrice[L"广西壮族自治区"].push_back({ 5, 0, 3, 5, 1.2 });
		g_xinMaBangBSPrice[L"四川省"].push_back({ 5, 0, 3, 5, 0.8 });
		g_xinMaBangBSPrice[L"重庆"].push_back({ 5, 0, 3, 5, 1.2 });
		g_xinMaBangBSPrice[L"云南省"].push_back({ 5, 0, 3, 5, 1.2 });
		g_xinMaBangBSPrice[L"贵州省"].push_back({ 5, 0, 3, 5, 1.2 });
		g_xinMaBangBSPrice[L"甘肃省"].push_back({ 5, 0, 3, 5, 1.8 });
		g_xinMaBangBSPrice[L"宁夏回族自治区"].push_back({ 5, 0, 3, 5, 1.8 });
		g_xinMaBangBSPrice[L"青海省"].push_back({ 5, 0, 3, 5, 1.8 });
		g_xinMaBangBSPrice[L"黑龙江省"].push_back({ 5, 0, 3, 5, 2 });
		g_xinMaBangBSPrice[L"吉林省"].push_back({ 5, 0, 3, 5, 2 });
		g_xinMaBangBSPrice[L"辽宁省"].push_back({ 5, 0, 3, 5, 2 });
		g_xinMaBangBSPrice[L"海南省"].push_back({ 5, 0, 3, 5, 3.7 });
		g_xinMaBangBSPrice[L"内蒙古自治区"].push_back({ 5, 0, 3, 7, 5.7 });
	}
	//永创耀辉顺丰
	{
		g_yongChuangYaoHuiSFPrice.resize(4);
		g_yongChuangYaoHuiSFPrice[0].push_back({ 0, 1, 1, 10, 0 });
		g_yongChuangYaoHuiSFPrice[0].push_back({ 1, 2, 2, 12.5, 0 });
		g_yongChuangYaoHuiSFPrice[0].push_back({ 2, 3, 3, 15, 0 });
		g_yongChuangYaoHuiSFPrice[0].push_back({ 3, 0, 1, 9, 4.2 });

		g_yongChuangYaoHuiSFPrice[1].push_back({ 0, 1, 1, 11, 0 });
		g_yongChuangYaoHuiSFPrice[1].push_back({ 1, 2, 2, 14, 0 });
		g_yongChuangYaoHuiSFPrice[1].push_back({ 2, 3, 3, 16, 0 });
		g_yongChuangYaoHuiSFPrice[1].push_back({ 3, 0, 1, 10, 4.5 });

		g_yongChuangYaoHuiSFPrice[2].push_back({ 0, 1, 1, 11, 0 });
		g_yongChuangYaoHuiSFPrice[2].push_back({ 1, 2, 2, 15, 0 });
		g_yongChuangYaoHuiSFPrice[2].push_back({ 2, 3, 3, 18.5, 0 });
		g_yongChuangYaoHuiSFPrice[2].push_back({ 3, 0, 1, 10, 5.5 });

		g_yongChuangYaoHuiSFPrice[3].push_back({ 0, 1, 1, 14, 0 });
		g_yongChuangYaoHuiSFPrice[3].push_back({ 1, 2, 2, 21.5, 0 });
		g_yongChuangYaoHuiSFPrice[3].push_back({ 2, 3, 3, 30, 0 });
		g_yongChuangYaoHuiSFPrice[3].push_back({ 3, 0, 1, 13, 9.5 });
	}
	//弥雅百世
	{
		//3公斤起
		g_miYaBSPrice[L"四川省"].push_back({ 0, 0, 3, 4.2, 1 });
		g_miYaBSPrice[L"重庆"].push_back({ 0, 0, 3, 4.2, 1 });
		g_miYaBSPrice[L"云南省"].push_back({ 0, 0, 3, 4.2, 2 });
		g_miYaBSPrice[L"贵州省"].push_back({ 0, 0, 3, 4.2, 2 });
		g_miYaBSPrice[L"陕西省"].push_back({ 0, 0, 3, 4.2, 2 });
		g_miYaBSPrice[L"江苏省"].push_back({ 0, 0, 3, 4.2, 2 });
		g_miYaBSPrice[L"浙江省"].push_back({ 0, 0, 3, 4.2, 2 });
		g_miYaBSPrice[L"上海"].push_back({ 0, 0, 3, 4.2, 2 });
		g_miYaBSPrice[L"安徽省"].push_back({ 0, 0, 3, 4.2, 2 });
		g_miYaBSPrice[L"河南省"].push_back({ 0, 0, 3, 4.2, 2 });
		g_miYaBSPrice[L"湖北省"].push_back({ 0, 0, 3, 4.2, 2 });
		g_miYaBSPrice[L"福建省"].push_back({ 0, 0, 3, 4.2, 2 });
		g_miYaBSPrice[L"北京"].push_back({ 0, 0, 3, 4.2, 3.5 });
		g_miYaBSPrice[L"天津"].push_back({ 0, 0, 3, 4.2, 2 });
		g_miYaBSPrice[L"广东省"].push_back({ 0, 0, 3, 4.2, 2 });
		g_miYaBSPrice[L"广西壮族自治区"].push_back({ 0, 0, 3, 4.2, 2 });
		g_miYaBSPrice[L"河北省"].push_back({ 0, 0, 3, 4.2, 2 });
		g_miYaBSPrice[L"湖南省"].push_back({ 0, 0, 3, 4.2, 2 });
		g_miYaBSPrice[L"江西省"].push_back({ 0, 0, 3, 4.2, 2 });
		g_miYaBSPrice[L"山西省"].push_back({ 0, 0, 3, 4.2, 3.5 });
		g_miYaBSPrice[L"山东省"].push_back({ 0, 0, 3, 4.2, 2 });
		g_miYaBSPrice[L"甘肃省"].push_back({ 0, 0, 3, 4.2, 3.5 });
		g_miYaBSPrice[L"宁夏回族自治区"].push_back({ 0, 0, 3, 4.2, 6 });
		g_miYaBSPrice[L"青海省"].push_back({ 0, 0, 3, 4.2, 6 });
		g_miYaBSPrice[L"黑龙江省"].push_back({ 0, 0, 3, 4.2, 3.5 });
		g_miYaBSPrice[L"吉林省"].push_back({ 0, 0, 3, 4.2, 3.5 });
		g_miYaBSPrice[L"辽宁省"].push_back({ 0, 0, 3, 4.2, 3.5 });
		g_miYaBSPrice[L"海南省"].push_back({ 0, 0, 3, 8, 6 });
		//
		g_miYaBSPrice[L"内蒙古自治区"].push_back({ 0, 0, 1, 8, 6 });
		g_miYaBSPrice[L"新疆维吾尔自治区"].push_back({ 0, 0, 1, 8, 6 });
		g_miYaBSPrice[L"西藏自治区"].push_back({ 0, 0, 1, 8, 6 });
	}
	//昆仑山圆通
	{
		//
		g_kunLunShanYTPrice[L"上海"].push_back({ 0, 3, 3, 3.5, 0 });
		g_kunLunShanYTPrice[L"北京"].push_back({ 0, 3, 3, 3.5, 0 });
		g_kunLunShanYTPrice[L"河南省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_kunLunShanYTPrice[L"江苏省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_kunLunShanYTPrice[L"浙江省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_kunLunShanYTPrice[L"安徽省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_kunLunShanYTPrice[L"山东省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_kunLunShanYTPrice[L"天津"].push_back({ 0, 3, 3, 3.5, 0 });
		g_kunLunShanYTPrice[L"河北省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_kunLunShanYTPrice[L"湖南省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_kunLunShanYTPrice[L"湖北省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_kunLunShanYTPrice[L"山西省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_kunLunShanYTPrice[L"陕西省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_kunLunShanYTPrice[L"江西省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_kunLunShanYTPrice[L"广东省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_kunLunShanYTPrice[L"福建省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_kunLunShanYTPrice[L"广西壮族自治区"].push_back({ 0, 3, 3, 3.5, 0 });
		g_kunLunShanYTPrice[L"四川省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_kunLunShanYTPrice[L"重庆"].push_back({ 0, 3, 3, 3.5, 0 });
		g_kunLunShanYTPrice[L"云南省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_kunLunShanYTPrice[L"贵州省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_kunLunShanYTPrice[L"甘肃省"].push_back({ 0, 3, 3, 4, 0 });
		g_kunLunShanYTPrice[L"宁夏回族自治区"].push_back({ 0, 3, 3, 4, 0 });
		g_kunLunShanYTPrice[L"青海省"].push_back({ 0, 3, 3, 4, 0 });
		g_kunLunShanYTPrice[L"黑龙江省"].push_back({ 0, 3, 3, 4, 0 });
		g_kunLunShanYTPrice[L"吉林省"].push_back({ 0, 3, 3, 4, 0 });
		g_kunLunShanYTPrice[L"辽宁省"].push_back({ 0, 3, 3, 4, 0 });
		g_kunLunShanYTPrice[L"内蒙古自治区"].push_back({ 0, 3, 3, 4.5, 0 });
		g_kunLunShanYTPrice[L"海南省"].push_back({ 0, 3, 3, 4.5, 0 });
		//3-5一口价
		g_kunLunShanYTPrice[L"上海"].push_back({ 3, 5, 3, 3.75, 0 });
		g_kunLunShanYTPrice[L"北京"].push_back({ 3, 5, 3, 3.75, 0 });
		g_kunLunShanYTPrice[L"河南省"].push_back({ 3, 5, 3, 3.75, 0 });
		g_kunLunShanYTPrice[L"江苏省"].push_back({ 3, 5, 3, 3.75, 0 });
		g_kunLunShanYTPrice[L"浙江省"].push_back({ 3, 5, 3, 3.75, 0 });
		g_kunLunShanYTPrice[L"安徽省"].push_back({ 3, 5, 3, 3.75, 0 });
		g_kunLunShanYTPrice[L"山东省"].push_back({ 3, 5, 3, 3.75, 0 });
		g_kunLunShanYTPrice[L"天津"].push_back({ 3, 5, 3, 3.75, 0 });
		g_kunLunShanYTPrice[L"河北省"].push_back({ 3, 5, 3, 3.75, 0 });
		g_kunLunShanYTPrice[L"湖南省"].push_back({ 3, 5, 3, 3.75, 0 });
		g_kunLunShanYTPrice[L"湖北省"].push_back({ 3, 5, 3, 3.75, 0 });
		g_kunLunShanYTPrice[L"山西省"].push_back({ 3, 5, 3, 3.75, 0 });
		g_kunLunShanYTPrice[L"陕西省"].push_back({ 3, 5, 3, 3.75, 0 });
		g_kunLunShanYTPrice[L"江西省"].push_back({ 3, 5, 3, 3.75, 0 });
		g_kunLunShanYTPrice[L"广东省"].push_back({ 3, 5, 3, 3.75, 0 });
		g_kunLunShanYTPrice[L"福建省"].push_back({ 3, 5, 3, 3.75, 0 });
		g_kunLunShanYTPrice[L"广西壮族自治区"].push_back({ 3, 5, 3, 3.75, 0 });
		g_kunLunShanYTPrice[L"四川省"].push_back({ 3, 5, 3, 3.75, 0 });
		g_kunLunShanYTPrice[L"重庆"].push_back({ 3, 5, 3, 3.75, 0 });
		g_kunLunShanYTPrice[L"云南省"].push_back({ 3, 5, 3, 3.75, 0 });
		g_kunLunShanYTPrice[L"贵州省"].push_back({ 3, 5, 3, 3.75, 0 });
		g_kunLunShanYTPrice[L"甘肃省"].push_back({ 3, 5, 3, 3.95, 0 });
		g_kunLunShanYTPrice[L"宁夏回族自治区"].push_back({ 3, 5, 3, 3.95, 0 });
		g_kunLunShanYTPrice[L"青海省"].push_back({ 3, 5, 3, 3.95, 0 });
		g_kunLunShanYTPrice[L"黑龙江省"].push_back({ 3, 5, 3, 3.95, 0 });
		g_kunLunShanYTPrice[L"吉林省"].push_back({ 3, 5, 3, 3.95, 0 });
		g_kunLunShanYTPrice[L"辽宁省"].push_back({ 3, 5, 3, 3.95, 0 });
		g_kunLunShanYTPrice[L"内蒙古自治区"].push_back({ 3, 5, 3, 4.25, 0 });
		g_kunLunShanYTPrice[L"海南省"].push_back({ 3, 5, 3, 4.25, 0 });
		//5以上
		g_kunLunShanYTPrice[L"上海"].push_back({ 5, 0, 3, 4.5, 1.2 });
		g_kunLunShanYTPrice[L"北京"].push_back({ 5, 0, 3, 4.5, 1.2 });
		g_kunLunShanYTPrice[L"河南省"].push_back({ 5, 0, 3, 4.5, 1 });
		g_kunLunShanYTPrice[L"江苏省"].push_back({ 5, 0, 3, 4.5, 1 });
		g_kunLunShanYTPrice[L"浙江省"].push_back({ 5, 0, 3, 4.5, 1 });
		g_kunLunShanYTPrice[L"安徽省"].push_back({ 5, 0, 3, 4.5, 1 });
		g_kunLunShanYTPrice[L"山东省"].push_back({ 5, 0, 3, 4.5, 1 });
		g_kunLunShanYTPrice[L"天津"].push_back({ 5, 0, 3, 4.5, 1 });
		g_kunLunShanYTPrice[L"河北省"].push_back({ 5, 0, 3, 4.5, 1 });
		g_kunLunShanYTPrice[L"湖南省"].push_back({ 5, 0, 3, 4.5, 1 });
		g_kunLunShanYTPrice[L"湖北省"].push_back({ 5, 0, 3, 4.5, 1 });
		g_kunLunShanYTPrice[L"山西省"].push_back({ 5, 0, 3, 4.5, 1 });
		g_kunLunShanYTPrice[L"陕西省"].push_back({ 5, 0, 3, 4.5, 1 });
		g_kunLunShanYTPrice[L"江西省"].push_back({ 5, 0, 3, 4.5, 1 });
		g_kunLunShanYTPrice[L"广东省"].push_back({ 5, 0, 3, 4.5, 1 });
		g_kunLunShanYTPrice[L"福建省"].push_back({ 5, 0, 3, 4.5, 1 });
		g_kunLunShanYTPrice[L"广西壮族自治区"].push_back({ 5, 0, 3, 4.5, 1 });
		g_kunLunShanYTPrice[L"四川省"].push_back({ 5, 0, 3, 4.5, 0.6 });
		g_kunLunShanYTPrice[L"重庆"].push_back({ 5, 0, 3, 4.5, 1 });
		g_kunLunShanYTPrice[L"云南省"].push_back({ 5, 0, 3, 4.5, 1 });
		g_kunLunShanYTPrice[L"贵州省"].push_back({ 5, 0, 3, 4.5, 1 });
		g_kunLunShanYTPrice[L"甘肃省"].push_back({ 5, 0, 3, 4.5, 1.6 });
		g_kunLunShanYTPrice[L"宁夏回族自治区"].push_back({ 5, 0, 3, 4.5, 1.6 });
		g_kunLunShanYTPrice[L"青海省"].push_back({ 5, 0, 3, 4.5, 1.6 });
		g_kunLunShanYTPrice[L"黑龙江省"].push_back({ 5, 0, 3, 4.5, 1.8 });
		g_kunLunShanYTPrice[L"吉林省"].push_back({ 5, 0, 3, 4.5, 1.8 });
		g_kunLunShanYTPrice[L"辽宁省"].push_back({ 5, 0, 3, 4.5, 1.8 });
		g_kunLunShanYTPrice[L"内蒙古自治区"].push_back({ 5, 0, 3, 6, 5 });
		g_kunLunShanYTPrice[L"海南省"].push_back({ 5, 0, 3, 4.5, 3.5 });
		//
		g_kunLunShanYTPrice[L"新疆维吾尔自治区"].push_back({ 0, 0, 26, 80, 3 });
		g_kunLunShanYTPrice[L"西藏自治区"].push_back({ 0, 0, 15, 60, 4 });
	}
	//中通快运成本
	{
		g_chengBenZTKYPrice[L"上海"] = { 25, 1.1 };
		g_chengBenZTKYPrice[L"北京"] = { 23, 1.1 };
		g_chengBenZTKYPrice[L"河南省"] = { 23, 1.1 };
		g_chengBenZTKYPrice[L"江苏省"] = { 23, 1.1 };
		g_chengBenZTKYPrice[L"浙江省"] = { 23, 1.1 };
		g_chengBenZTKYPrice[L"安徽省"] = { 23, 1.1 };
		g_chengBenZTKYPrice[L"山东省"] = { 23, 1.1 };
		g_chengBenZTKYPrice[L"天津"] = { 25, 1.1 };
		g_chengBenZTKYPrice[L"河北省"] = { 23, 1.1 };
		g_chengBenZTKYPrice[L"湖南省"] = { 23, 1.1 };
		g_chengBenZTKYPrice[L"湖北省"] = { 23, 1.1 };
		g_chengBenZTKYPrice[L"山西省"] = { 23, 1.1 };
		g_chengBenZTKYPrice[L"陕西省"] = { 23, 1.1 };
		g_chengBenZTKYPrice[L"江西省"] = { 23, 1.1 };
		g_chengBenZTKYPrice[L"广东省"] = { 23, 1.1 };
		g_chengBenZTKYPrice[L"福建省"] = { 23, 1.1 };
		g_chengBenZTKYPrice[L"广西壮族自治区"] = { 23, 1.1 };
		g_chengBenZTKYPrice[L"四川省"] = { 20, 0.8 };
		g_chengBenZTKYPrice[L"阿坝藏族羌族自治州"] = { 50, 1.5 };
		g_chengBenZTKYPrice[L"攀枝花市"] = { 20, 1 };

		g_chengBenZTKYPrice[L"重庆"] = { 23, 1 };
		g_chengBenZTKYPrice[L"云南省"] = { 30, 1.1 };
		g_chengBenZTKYPrice[L"贵州省"] = { 23, 1.2 };
		g_chengBenZTKYPrice[L"甘肃省"] = { 33, 1.6 };
		g_chengBenZTKYPrice[L"宁夏回族自治区"] = { 40, 1.5 };
		g_chengBenZTKYPrice[L"青海省"] = { 25, 2.6 };
		g_chengBenZTKYPrice[L"黑龙江省"] = { 35, 1.5 };
		g_chengBenZTKYPrice[L"吉林省"] = { 35, 1.5 };
		g_chengBenZTKYPrice[L"辽宁省"] = { 35, 1.5 };
		g_chengBenZTKYPrice[L"内蒙古自治区"] = { 40, 1.5 };
		g_chengBenZTKYPrice[L"海南省"] = { 40, 2.5 };
		g_chengBenZTKYPrice[L"新疆维吾尔自治区"] = { 50, 3 };
		g_chengBenZTKYPrice[L"西藏自治区"] = { 70, 3 };
	}
	//永创耀辉中通快运
	{
		g_yongChuangYaoHuiZTKYPrice[L"上海"] = {27.5, 1.3};
		g_yongChuangYaoHuiZTKYPrice[L"北京"] = {27.5, 1.3};
		g_yongChuangYaoHuiZTKYPrice[L"河南省"] = {27.5, 1.3};
		g_yongChuangYaoHuiZTKYPrice[L"江苏省"] = {27.5, 1.3};
		g_yongChuangYaoHuiZTKYPrice[L"浙江省"] = {27.5, 1.3};
		g_yongChuangYaoHuiZTKYPrice[L"安徽省"] = {27.5, 1.3};
		g_yongChuangYaoHuiZTKYPrice[L"山东省"] = {27.5, 1.3};
		g_yongChuangYaoHuiZTKYPrice[L"天津"] = {27.5, 1.3};
		g_yongChuangYaoHuiZTKYPrice[L"河北省"] = {27.5, 1.3};
		g_yongChuangYaoHuiZTKYPrice[L"湖南省"] = {27.5, 1.3};
		g_yongChuangYaoHuiZTKYPrice[L"湖北省"] = {27.5, 1.3};
		g_yongChuangYaoHuiZTKYPrice[L"山西省"] = {27.5, 1.3};
		g_yongChuangYaoHuiZTKYPrice[L"陕西省"] = {27.5, 1.3};
		g_yongChuangYaoHuiZTKYPrice[L"江西省"] = {27.5, 1.3};
		g_yongChuangYaoHuiZTKYPrice[L"广东省"] = {27.5, 1.3};
		g_yongChuangYaoHuiZTKYPrice[L"福建省"] = {27.5, 1.3};
		g_yongChuangYaoHuiZTKYPrice[L"广西壮族自治区"] = {27.5, 1.3};
		g_yongChuangYaoHuiZTKYPrice[L"四川省"] = {22.5, 1};
		g_yongChuangYaoHuiZTKYPrice[L"甘孜藏族自治州"] = {50, 1.5};
		g_yongChuangYaoHuiZTKYPrice[L"阿坝藏族羌族自治州"] = {50, 1.5};
		g_yongChuangYaoHuiZTKYPrice[L"凉山彝族自治州"] = {50, 1.5};
		g_yongChuangYaoHuiZTKYPrice[L"重庆"] = {27.5, 1.2};
		g_yongChuangYaoHuiZTKYPrice[L"云南省"] = {33, 1.4};
		g_yongChuangYaoHuiZTKYPrice[L"贵州省"] = {27.5, 1.4};
		g_yongChuangYaoHuiZTKYPrice[L"甘肃省"] = {35, 3};
		g_yongChuangYaoHuiZTKYPrice[L"宁夏回族自治区"] = {42.5, 2.8};
		g_yongChuangYaoHuiZTKYPrice[L"青海省"] = {42.5, 2.8};
		g_yongChuangYaoHuiZTKYPrice[L"黑龙江省"] = {37, 1.4};
		g_yongChuangYaoHuiZTKYPrice[L"吉林省"] = {37, 1.4};
		g_yongChuangYaoHuiZTKYPrice[L"辽宁省"] = {37, 1.4};
		g_yongChuangYaoHuiZTKYPrice[L"内蒙古自治区"] = {72.5, 3};
		g_yongChuangYaoHuiZTKYPrice[L"海南省"] = {42, 2.7};
		g_yongChuangYaoHuiZTKYPrice[L"新疆维吾尔自治区"] = {82.5, 3.2};
		g_yongChuangYaoHuiZTKYPrice[L"西藏自治区"] = {75, 4.2};
	}
	//永创耀辉快递价格
	{
		//0-1公斤 一口价
		g_yongChuangYaoHuiKDPrice[L"上海"].push_back({ 0, 1, 1, 2.5, 0, 1.3 });
		g_yongChuangYaoHuiKDPrice[L"北京"].push_back({ 0, 1, 1, 2.5, 0, 1.3 });
		g_yongChuangYaoHuiKDPrice[L"河南省"].push_back({ 0, 1, 1, 2.5, 0, 1.3 });
		g_yongChuangYaoHuiKDPrice[L"江苏省"].push_back({ 0, 1, 1, 2.5, 0, 1.3 });
		g_yongChuangYaoHuiKDPrice[L"浙江省"].push_back({ 0, 1, 1, 2.5, 0, 1.3 });
		g_yongChuangYaoHuiKDPrice[L"安徽省"].push_back({ 0, 1, 1, 2.5, 0, 1.3 });
		g_yongChuangYaoHuiKDPrice[L"山东省"].push_back({ 0, 1, 1, 2.5, 0, 1.3 });
		g_yongChuangYaoHuiKDPrice[L"天津"].push_back({ 0, 1, 1, 2.5, 0, 1.3 });
		g_yongChuangYaoHuiKDPrice[L"河北省"].push_back({ 0, 1, 1, 2.5, 0, 1.3 });
		g_yongChuangYaoHuiKDPrice[L"湖南省"].push_back({ 0, 1, 1, 2.5, 0, 1.3 });
		g_yongChuangYaoHuiKDPrice[L"湖北省"].push_back({ 0, 1, 1, 2.5, 0, 1.3 });
		g_yongChuangYaoHuiKDPrice[L"山西省"].push_back({ 0, 1, 1, 2.5, 0, 1.3 });
		g_yongChuangYaoHuiKDPrice[L"陕西省"].push_back({ 0, 1, 1, 2.5, 0, 1.3 });
		g_yongChuangYaoHuiKDPrice[L"江西省"].push_back({ 0, 1, 1, 2.5, 0, 1.3 });
		g_yongChuangYaoHuiKDPrice[L"广东省"].push_back({ 0, 1, 1, 2.5, 0, 1.3 });
		g_yongChuangYaoHuiKDPrice[L"福建省"].push_back({ 0, 1, 1, 2.5, 0, 1.3 });
		g_yongChuangYaoHuiKDPrice[L"广西壮族自治区"].push_back({ 0, 1, 1, 2.5, 0, 1.3 });
		g_yongChuangYaoHuiKDPrice[L"四川省"].push_back({ 0, 1, 1, 2.5, 0, 1.3 });
		g_yongChuangYaoHuiKDPrice[L"重庆"].push_back({ 0, 1, 1, 2.5, 0, 1.3 });
		g_yongChuangYaoHuiKDPrice[L"云南省"].push_back({ 0, 1, 1, 2.5, 0, 1.3 });
		g_yongChuangYaoHuiKDPrice[L"贵州省"].push_back({ 0, 1, 1, 2.5, 0, 1.3 });
		g_yongChuangYaoHuiKDPrice[L"黑龙江省"].push_back({ 0, 1, 1, 2.5, 0, 1.3 });
		g_yongChuangYaoHuiKDPrice[L"吉林省"].push_back({ 0, 1, 1, 2.5, 0, 1.3 });
		g_yongChuangYaoHuiKDPrice[L"辽宁省"].push_back({ 0, 1, 1, 2.5, 0, 1.3 });
		//1公斤以上
		g_yongChuangYaoHuiKDPrice[L"上海"].push_back({ 1, 0, 3, 3, 0.9, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"北京"].push_back({ 1, 0, 3, 3, 0.9, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"河南省"].push_back({ 1, 0, 3, 3, 0.9, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"江苏省"].push_back({ 1, 0, 3, 3, 0.9, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"浙江省"].push_back({ 1, 0, 3, 3, 0.9, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"安徽省"].push_back({ 1, 0, 3, 3, 0.9, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"山东省"].push_back({ 1, 0, 3, 3, 0.9, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"天津"].push_back({ 1, 0, 3, 3, 0.9, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"河北省"].push_back({ 1, 0, 3, 3, 0.9, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"湖南省"].push_back({ 1, 0, 3, 3, 0.9, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"湖北省"].push_back({ 1, 0, 3, 3, 0.9, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"山西省"].push_back({ 1, 0, 3, 3, 0.9, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"陕西省"].push_back({ 1, 0, 3, 3, 0.9, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"江西省"].push_back({ 1, 0, 3, 3, 0.9, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"广东省"].push_back({ 1, 0, 3, 3, 0.9, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"福建省"].push_back({ 1, 0, 3, 3, 0.9, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"广西壮族自治区"].push_back({ 1, 0, 3, 3, 0.9, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"四川省"].push_back({ 1, 0, 3, 3, 0.7, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"重庆"].push_back({ 1, 0, 3, 3, 0.7, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"云南省"].push_back({ 1, 0, 3, 3, 0.9, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"贵州省"].push_back({ 1, 0, 3, 3, 0.9, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"黑龙江省"].push_back({ 1, 0, 3, 3, 1.5, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"吉林省"].push_back({ 1, 0, 3, 3, 1.5, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"辽宁省"].push_back({ 1, 0, 3, 3, 1.5, 1.3, 0.8 });


		g_yongChuangYaoHuiKDPrice[L"宁夏回族自治区"].push_back({ 0, 0, 1, 6, 4, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"青海省"].push_back({ 0, 0, 1, 6, 4, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"海南省"].push_back({ 0, 0, 1, 6, 4, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"新疆维吾尔自治区"].push_back({ 0, 0, 1, 8, 6, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"西藏自治区"].push_back({ 0, 0, 1, 8, 6, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"内蒙古自治区"].push_back({ 0, 0, 1, 6, 5, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"甘肃省"].push_back({ 0, 0, 1, 5, 4, 1.3, 0.8 });
	}
	//辣风芹快递价格
	{
		g_laFengQingKDPrice[L"四川省"].push_back({ 0, 0, 3, 2.7, 1 });
		g_laFengQingKDPrice[L"重庆"].push_back({ 0, 0, 3, 2.7, 1 });
		g_laFengQingKDPrice[L"云南省"].push_back({ 0, 0, 3, 2.7, 1.5 });
		g_laFengQingKDPrice[L"贵州省"].push_back({ 0, 0, 3, 2.7, 1.5 });
		g_laFengQingKDPrice[L"陕西省"].push_back({ 0, 0, 3, 2.7, 1.5 });
		g_laFengQingKDPrice[L"江苏省"].push_back({ 0, 0, 3, 2.7, 1.5 });
		g_laFengQingKDPrice[L"浙江省"].push_back({ 0, 0, 3, 2.7, 1.5 });
		g_laFengQingKDPrice[L"上海"].push_back({ 0, 0, 3, 2.7, 1.5 });
		g_laFengQingKDPrice[L"安徽省"].push_back({ 0, 0, 3, 2.7, 1.5 });
		g_laFengQingKDPrice[L"河南省"].push_back({ 0, 0, 3, 2.7, 1.5 });
		g_laFengQingKDPrice[L"湖北省"].push_back({ 0, 0, 3, 2.7, 1.5 });
		g_laFengQingKDPrice[L"福建省"].push_back({ 0, 0, 3, 2.7, 1.5 });
		g_laFengQingKDPrice[L"天津"].push_back({ 0, 0, 3, 2.7, 1.5 });
		g_laFengQingKDPrice[L"广东省"].push_back({ 0, 0, 3, 2.7, 1.5 });
		g_laFengQingKDPrice[L"广西壮族自治区"].push_back({ 0, 0, 3, 2.7, 1.5 });
		g_laFengQingKDPrice[L"河北省"].push_back({ 0, 0, 3, 2.7, 1.5 });
		g_laFengQingKDPrice[L"湖南省"].push_back({ 0, 0, 3, 2.7, 1.5 });
		g_laFengQingKDPrice[L"江西省"].push_back({ 0, 0, 3, 2.7, 1.5 });
		g_laFengQingKDPrice[L"山东省"].push_back({ 0, 0, 3, 2.7, 1.5 });
		g_laFengQingKDPrice[L"山西省"].push_back({ 0, 0, 3, 2.7, 1.5 });
		g_laFengQingKDPrice[L"北京"].push_back({ 0, 0, 3, 2.7, 1.5 });
		g_laFengQingKDPrice[L"黑龙江省"].push_back({ 0, 0, 3, 2.7, 1.5 });
		g_laFengQingKDPrice[L"吉林省"].push_back({ 0, 0, 3, 2.7, 1.5 });
		g_laFengQingKDPrice[L"辽宁省"].push_back({ 0, 0, 3, 2.7, 1.5 });
		g_laFengQingKDPrice[L"宁夏回族自治区"].push_back({ 0, 0, 3, 3.1, 2.5 });
		g_laFengQingKDPrice[L"青海省"].push_back({ 0, 0, 3, 3.1, 2.5 });
		g_laFengQingKDPrice[L"海南省"].push_back({ 0, 0, 3, 3.1, 2.5 });
		g_laFengQingKDPrice[L"甘肃省"].push_back({ 0, 0, 3, 3.1, 2.5 });
		g_laFengQingKDPrice[L"内蒙古自治区"].push_back({ 0, 0, 3, 3.1, 2.5 });
		//
		g_laFengQingKDPrice[L"新疆维吾尔自治区"].push_back({ 0, 0, 1, 7, 7 });
		g_laFengQingKDPrice[L"西藏自治区"].push_back({ 0, 0, 1, 12, 12 });
	}
	//至善电商百世快递
	{
		//1公斤
		g_zhiShanBSKDPrice[L"四川省"].push_back({ 0, 1, 1, 2.8, 0 });
		g_zhiShanBSKDPrice[L"重庆"].push_back({ 0, 1, 1, 2.8, 0 });
		g_zhiShanBSKDPrice[L"云南省"].push_back({ 0, 1, 1, 2.8, 0 });
		g_zhiShanBSKDPrice[L"贵州省"].push_back({ 0, 1, 1, 2.8, 0 });
		g_zhiShanBSKDPrice[L"陕西省"].push_back({ 0, 1, 1, 2.8, 0 });
		g_zhiShanBSKDPrice[L"江苏省"].push_back({ 0, 1, 1, 2.8, 0 });
		g_zhiShanBSKDPrice[L"浙江省"].push_back({ 0, 1, 1, 2.8, 0 });
		g_zhiShanBSKDPrice[L"上海"].push_back({ 0, 1, 1, 2.8, 0 });
		g_zhiShanBSKDPrice[L"安徽省"].push_back({ 0, 1, 1, 2.8, 0 });
		g_zhiShanBSKDPrice[L"河南省"].push_back({ 0, 1, 1, 2.8, 0 });
		g_zhiShanBSKDPrice[L"湖北省"].push_back({ 0, 1, 1, 2.8, 0 });
		g_zhiShanBSKDPrice[L"福建省"].push_back({ 0, 1, 1, 2.8, 0 });
		g_zhiShanBSKDPrice[L"天津"].push_back({ 0, 1, 1, 2.8, 0 });
		g_zhiShanBSKDPrice[L"广东省"].push_back({ 0, 1, 1, 2.8, 0 });
		g_zhiShanBSKDPrice[L"广西壮族自治区"].push_back({ 0, 1, 1, 2.8, 0 });
		g_zhiShanBSKDPrice[L"河北省"].push_back({ 0, 1, 1, 2.8, 0 });
		g_zhiShanBSKDPrice[L"湖南省"].push_back({ 0, 1, 1, 2.8, 0 });
		g_zhiShanBSKDPrice[L"江西省"].push_back({ 0, 1, 1, 2.8, 0 });
		g_zhiShanBSKDPrice[L"山东省"].push_back({ 0, 1, 1, 2.8, 0 });
		g_zhiShanBSKDPrice[L"山西省"].push_back({ 0, 1, 1, 2.8, 0 });
		g_zhiShanBSKDPrice[L"北京"].push_back({ 0, 1, 1, 2.8, 0 });
		g_zhiShanBSKDPrice[L"黑龙江省"].push_back({ 0, 1, 1, 3.8, 0 });
		g_zhiShanBSKDPrice[L"吉林省"].push_back({ 0, 1, 1, 3.8, 0 });
		g_zhiShanBSKDPrice[L"辽宁省"].push_back({ 0, 1, 1, 3.8, 0 });
		//1-3公斤
		g_zhiShanBSKDPrice[L"四川省"].push_back({ 1, 3, 3, 3.2, 0 });
		g_zhiShanBSKDPrice[L"重庆"].push_back({ 1, 3, 3, 3.2, 0 });
		g_zhiShanBSKDPrice[L"云南省"].push_back({ 1, 3, 3, 3.2, 0 });
		g_zhiShanBSKDPrice[L"贵州省"].push_back({ 1, 3, 3, 3.2, 0 });
		g_zhiShanBSKDPrice[L"陕西省"].push_back({ 1, 3, 3, 3.2, 0 });
		g_zhiShanBSKDPrice[L"江苏省"].push_back({ 1, 3, 3, 3.2, 0 });
		g_zhiShanBSKDPrice[L"浙江省"].push_back({ 1, 3, 3, 3.2, 0 });
		g_zhiShanBSKDPrice[L"上海"].push_back({ 1, 3, 3, 3.2, 0 });
		g_zhiShanBSKDPrice[L"安徽省"].push_back({ 1, 3, 3, 3.2, 0 });
		g_zhiShanBSKDPrice[L"河南省"].push_back({ 1, 3, 3, 3.2, 0 });
		g_zhiShanBSKDPrice[L"湖北省"].push_back({ 1, 3, 3, 3.2, 0 });
		g_zhiShanBSKDPrice[L"福建省"].push_back({ 1, 3, 3, 3.2, 0 });
		g_zhiShanBSKDPrice[L"天津"].push_back({ 1, 3, 3, 3.2, 0 });
		g_zhiShanBSKDPrice[L"广东省"].push_back({ 1, 3, 3, 3.2, 0 });
		g_zhiShanBSKDPrice[L"广西壮族自治区"].push_back({ 1, 3, 3, 3.2, 0 });
		g_zhiShanBSKDPrice[L"河北省"].push_back({ 1, 3, 3, 3.2, 0 });
		g_zhiShanBSKDPrice[L"湖南省"].push_back({ 1, 3, 3, 3.2, 0 });
		g_zhiShanBSKDPrice[L"江西省"].push_back({ 1, 3, 3, 3.2, 0 });
		g_zhiShanBSKDPrice[L"山东省"].push_back({ 1, 3, 3, 3.2, 0 });
		g_zhiShanBSKDPrice[L"山西省"].push_back({ 1, 3, 3, 3.2, 0 });
		g_zhiShanBSKDPrice[L"北京"].push_back({ 1, 3, 3, 3.2, 0 });
		g_zhiShanBSKDPrice[L"黑龙江省"].push_back({ 1, 3, 3, 4.2, 0 });
		g_zhiShanBSKDPrice[L"吉林省"].push_back({ 1, 3, 3, 4.2, 0 });
		g_zhiShanBSKDPrice[L"辽宁省"].push_back({ 1, 3, 3, 4.2, 0 });
		//3公斤以上
		g_zhiShanBSKDPrice[L"四川省"].push_back({ 3, 0, 3, 3, 1 });
		g_zhiShanBSKDPrice[L"重庆"].push_back({ 3, 0, 3, 3, 1.3 });
		g_zhiShanBSKDPrice[L"云南省"].push_back({ 3, 0, 3, 3, 1.3 });
		g_zhiShanBSKDPrice[L"贵州省"].push_back({ 3, 0, 3, 3, 1.3 });
		g_zhiShanBSKDPrice[L"陕西省"].push_back({ 3, 0, 3, 3, 1.3 });
		g_zhiShanBSKDPrice[L"江苏省"].push_back({ 3, 0, 3, 3, 1.3 });
		g_zhiShanBSKDPrice[L"浙江省"].push_back({ 3, 0, 3, 3, 1.3 });
		g_zhiShanBSKDPrice[L"上海"].push_back({ 3, 0, 3, 3, 1.3 });
		g_zhiShanBSKDPrice[L"安徽省"].push_back({ 3, 0, 3, 3, 1.3 });
		g_zhiShanBSKDPrice[L"河南省"].push_back({ 3, 0, 3, 3, 1.3 });
		g_zhiShanBSKDPrice[L"湖北省"].push_back({ 3, 0, 3, 3, 1.3 });
		g_zhiShanBSKDPrice[L"福建省"].push_back({ 3, 0, 3, 3, 1.3 });
		g_zhiShanBSKDPrice[L"天津"].push_back({ 3, 0, 3, 3, 1.3 });
		g_zhiShanBSKDPrice[L"广东省"].push_back({ 3, 0, 3, 3, 1.3 });
		g_zhiShanBSKDPrice[L"广西壮族自治区"].push_back({ 3, 0, 3, 3, 1.3 });
		g_zhiShanBSKDPrice[L"河北省"].push_back({ 3, 0, 3, 3, 1.3 });
		g_zhiShanBSKDPrice[L"湖南省"].push_back({ 3, 0, 3, 3, 1.3 });
		g_zhiShanBSKDPrice[L"江西省"].push_back({ 3, 0, 3, 3, 1.3 });
		g_zhiShanBSKDPrice[L"山东省"].push_back({ 3, 0, 3, 3, 1.3 });
		g_zhiShanBSKDPrice[L"山西省"].push_back({ 3, 0, 3, 3, 1.3 });
		g_zhiShanBSKDPrice[L"北京"].push_back({ 3, 0, 3, 3, 1.3 });
		g_zhiShanBSKDPrice[L"黑龙江省"].push_back({ 3, 0, 3, 5, 2 });
		g_zhiShanBSKDPrice[L"吉林省"].push_back({ 3, 0, 3, 5, 2 });
		g_zhiShanBSKDPrice[L"辽宁省"].push_back({ 3, 0, 3, 5, 2 });

		g_zhiShanBSKDPrice[L"宁夏回族自治区"].push_back({ 0, 0, 1, 7, 5 });
		g_zhiShanBSKDPrice[L"青海省"].push_back({ 0, 0, 1, 7, 5 });
		g_zhiShanBSKDPrice[L"海南省"].push_back({ 0, 0, 1, 7, 5 });
		g_zhiShanBSKDPrice[L"甘肃省"].push_back({ 0, 0, 1, 6, 5 });
		g_zhiShanBSKDPrice[L"内蒙古自治区"].push_back({ 0, 0, 1, 7, 6 });
		g_zhiShanBSKDPrice[L"新疆维吾尔自治区"].push_back({ 0, 0, 1, 9, 7 });
		g_zhiShanBSKDPrice[L"西藏自治区"].push_back({ 0, 0, 1, 9, 7 });
	}
	//至善电商其他快递
	{
		
		//1公斤
		g_zhiShanQTKDPrice[L"四川省"].push_back({ 0, 1, 1, 3.2, 0 });
		g_zhiShanQTKDPrice[L"重庆"].push_back({ 0, 1, 1, 3.2, 0 });
		g_zhiShanQTKDPrice[L"云南省"].push_back({ 0, 1, 1, 3.2, 0 });
		g_zhiShanQTKDPrice[L"贵州省"].push_back({ 0, 1, 1, 3.2, 0 });
		g_zhiShanQTKDPrice[L"陕西省"].push_back({ 0, 1, 1, 3.2, 0 });
		g_zhiShanQTKDPrice[L"江苏省"].push_back({ 0, 1, 1, 3.2, 0 });
		g_zhiShanQTKDPrice[L"浙江省"].push_back({ 0, 1, 1, 3.2, 0 });
		
		g_zhiShanQTKDPrice[L"安徽省"].push_back({ 0, 1, 1, 3.2, 0 });
		g_zhiShanQTKDPrice[L"河南省"].push_back({ 0, 1, 1, 3.2, 0 });
		g_zhiShanQTKDPrice[L"湖北省"].push_back({ 0, 1, 1, 3.2, 0 });
		g_zhiShanQTKDPrice[L"福建省"].push_back({ 0, 1, 1, 3.2, 0 });
		g_zhiShanQTKDPrice[L"天津"].push_back({ 0, 1, 1, 3.2, 0 });
		g_zhiShanQTKDPrice[L"广东省"].push_back({ 0, 1, 1, 3.2, 0 });
		g_zhiShanQTKDPrice[L"广西壮族自治区"].push_back({ 0, 1, 1, 3.2, 0 });
		g_zhiShanQTKDPrice[L"河北省"].push_back({ 0, 1, 1, 3.2, 0 });
		g_zhiShanQTKDPrice[L"湖南省"].push_back({ 0, 1, 1, 3.2, 0 });
		g_zhiShanQTKDPrice[L"江西省"].push_back({ 0, 1, 1, 3.2, 0 });
		g_zhiShanQTKDPrice[L"山东省"].push_back({ 0, 1, 1, 3.2, 0 });
		g_zhiShanQTKDPrice[L"山西省"].push_back({ 0, 1, 1, 3.2, 0 });

		g_zhiShanQTKDPrice[L"黑龙江省"].push_back({ 0, 1, 1, 3.2, 0 });
		g_zhiShanQTKDPrice[L"吉林省"].push_back({ 0, 1, 1, 3.2, 0 });
		g_zhiShanQTKDPrice[L"辽宁省"].push_back({ 0, 1, 1, 3.2, 0 });
		g_zhiShanQTKDPrice[L"宁夏回族自治区"].push_back({ 0, 1, 1, 3.2, 0 });
		g_zhiShanQTKDPrice[L"青海省"].push_back({ 0, 1, 1, 3.2, 0 });
		g_zhiShanQTKDPrice[L"甘肃省"].push_back({ 0, 1, 1, 3.2, 0 });

		g_zhiShanQTKDPrice[L"北京"].push_back({ 0, 1, 1, 4, 0 });
		g_zhiShanQTKDPrice[L"上海"].push_back({ 0, 1, 1, 3.8, 0 });
		//3kg
		g_zhiShanQTKDPrice[L"四川省"].push_back({ 1, 3, 3, 3.7, 0 });
		g_zhiShanQTKDPrice[L"重庆"].push_back({ 1, 3, 3, 3.7, 0 });
		g_zhiShanQTKDPrice[L"云南省"].push_back({ 1, 3, 3, 3.7, 0 });
		g_zhiShanQTKDPrice[L"贵州省"].push_back({ 1, 3, 3, 3.7, 0 });
		g_zhiShanQTKDPrice[L"陕西省"].push_back({ 1, 3, 3, 3.7, 0 });
		g_zhiShanQTKDPrice[L"江苏省"].push_back({ 1, 3, 3, 3.7, 0 });
		g_zhiShanQTKDPrice[L"浙江省"].push_back({ 1, 3, 3, 3.7, 0 });

		g_zhiShanQTKDPrice[L"安徽省"].push_back({ 1, 3, 3, 3.7, 0 });
		g_zhiShanQTKDPrice[L"河南省"].push_back({ 1, 3, 3, 3.7, 0 });
		g_zhiShanQTKDPrice[L"湖北省"].push_back({ 1, 3, 3, 3.7, 0 });
		g_zhiShanQTKDPrice[L"福建省"].push_back({ 1, 3, 3, 3.7, 0 });
		g_zhiShanQTKDPrice[L"天津"].push_back({ 1, 3, 3, 3.7, 0 });
		g_zhiShanQTKDPrice[L"广东省"].push_back({ 1, 3, 3, 3.7, 0 });
		g_zhiShanQTKDPrice[L"广西壮族自治区"].push_back({ 1, 3, 3, 3.7, 0 });
		g_zhiShanQTKDPrice[L"河北省"].push_back({ 1, 3, 3, 3.7, 0 });
		g_zhiShanQTKDPrice[L"湖南省"].push_back({ 1, 3, 3, 3.7, 0 });
		g_zhiShanQTKDPrice[L"江西省"].push_back({ 1, 3, 3, 3.7, 0 });
		g_zhiShanQTKDPrice[L"山东省"].push_back({ 1, 3, 3, 3.7, 0 });
		g_zhiShanQTKDPrice[L"山西省"].push_back({ 1, 3, 3, 3.7, 0 });

		g_zhiShanQTKDPrice[L"黑龙江省"].push_back({ 1, 3, 3, 3.7, 0 });
		g_zhiShanQTKDPrice[L"吉林省"].push_back({ 1, 3, 3, 3.7, 0 });
		g_zhiShanQTKDPrice[L"辽宁省"].push_back({ 1, 3, 3, 3.7, 0 });
		g_zhiShanQTKDPrice[L"宁夏回族自治区"].push_back({ 1, 3, 3, 3.7, 0 });
		g_zhiShanQTKDPrice[L"青海省"].push_back({ 1, 3, 3, 3.7, 0 });
		g_zhiShanQTKDPrice[L"甘肃省"].push_back({ 1, 3, 3, 3.7, 0 });

		g_zhiShanQTKDPrice[L"上海"].push_back({ 1, 3, 3, 4.3, 0 });
		g_zhiShanQTKDPrice[L"北京"].push_back({ 1, 3, 3, 4.5, 0 });
		//3-5kg
		g_zhiShanQTKDPrice[L"四川省"].push_back({ 3, 5, 5, 6, 0 });
		g_zhiShanQTKDPrice[L"重庆"].push_back({ 3, 5, 5, 6, 0 });
		g_zhiShanQTKDPrice[L"云南省"].push_back({ 3, 5, 5, 6, 0 });
		g_zhiShanQTKDPrice[L"贵州省"].push_back({ 3, 5, 5, 6, 0 });
		g_zhiShanQTKDPrice[L"陕西省"].push_back({ 3, 5, 5, 6, 0 });
		g_zhiShanQTKDPrice[L"江苏省"].push_back({ 3, 5, 5, 6, 0 });
		g_zhiShanQTKDPrice[L"浙江省"].push_back({ 3, 5, 5, 6, 0 });

		g_zhiShanQTKDPrice[L"安徽省"].push_back({ 3, 5, 5, 6, 0 });
		g_zhiShanQTKDPrice[L"河南省"].push_back({ 3, 5, 5, 6, 0 });
		g_zhiShanQTKDPrice[L"湖北省"].push_back({ 3, 5, 5, 6, 0 });
		g_zhiShanQTKDPrice[L"福建省"].push_back({ 3, 5, 5, 6, 0 });
		g_zhiShanQTKDPrice[L"天津"].push_back({ 3, 5, 5, 6, 0 });
		g_zhiShanQTKDPrice[L"广东省"].push_back({ 3, 5, 5, 6, 0 });
		g_zhiShanQTKDPrice[L"广西壮族自治区"].push_back({ 3, 5, 5, 6, 0 });
		g_zhiShanQTKDPrice[L"河北省"].push_back({ 3, 5, 5, 6, 0 });
		g_zhiShanQTKDPrice[L"湖南省"].push_back({ 3, 5, 5, 6, 0 });
		g_zhiShanQTKDPrice[L"江西省"].push_back({ 3, 5, 5, 6, 0 });
		g_zhiShanQTKDPrice[L"山东省"].push_back({ 3, 5, 5, 6, 0 });
		g_zhiShanQTKDPrice[L"山西省"].push_back({ 3, 5, 5, 6, 0 });

		g_zhiShanQTKDPrice[L"黑龙江省"].push_back({ 3, 5, 5, 6.5, 0 });
		g_zhiShanQTKDPrice[L"吉林省"].push_back({ 3, 5, 5, 6.5, 0 });
		g_zhiShanQTKDPrice[L"辽宁省"].push_back({ 3, 5, 5, 6.5, 0 });
		g_zhiShanQTKDPrice[L"宁夏回族自治区"].push_back({ 3, 5, 5, 6.5, 0 });
		g_zhiShanQTKDPrice[L"青海省"].push_back({ 3, 5, 5, 6.5, 0 });
		g_zhiShanQTKDPrice[L"甘肃省"].push_back({ 3, 5, 5, 6.5, 0 });

		g_zhiShanQTKDPrice[L"上海"].push_back({ 3, 5, 5, 6, 0 });
		g_zhiShanQTKDPrice[L"北京"].push_back({ 3, 5, 5, 6.5, 0 });
		//5kg以上
		g_zhiShanQTKDPrice[L"四川省"].push_back({ 5, 0, 1, 4.7, 1.3 });
		g_zhiShanQTKDPrice[L"重庆"].push_back({ 5, 0, 1, 4.7, 1.3 });
		g_zhiShanQTKDPrice[L"云南省"].push_back({ 5, 0, 1, 5.5, 1.8 });
		g_zhiShanQTKDPrice[L"贵州省"].push_back({ 5, 0, 1, 5.5, 1.8 });
		g_zhiShanQTKDPrice[L"陕西省"].push_back({ 5, 0, 1, 5.5, 1.8 });
		g_zhiShanQTKDPrice[L"江苏省"].push_back({ 5, 0, 1, 5.5, 1.8 });
		g_zhiShanQTKDPrice[L"浙江省"].push_back({ 5, 0, 1, 5.5, 1.8 });

		g_zhiShanQTKDPrice[L"安徽省"].push_back({ 5, 0, 1, 5.5, 1.8 });
		g_zhiShanQTKDPrice[L"河南省"].push_back({ 5, 0, 1, 5.5, 1.8 });
		g_zhiShanQTKDPrice[L"湖北省"].push_back({ 5, 0, 1, 5.5, 1.8 });
		g_zhiShanQTKDPrice[L"福建省"].push_back({ 5, 0, 1, 5.5, 1.8 });
		g_zhiShanQTKDPrice[L"天津"].push_back({ 5, 0, 1, 5.5, 1.8 });
		g_zhiShanQTKDPrice[L"广东省"].push_back({ 5, 0, 1, 5.5, 1.8 });
		g_zhiShanQTKDPrice[L"广西壮族自治区"].push_back({ 5, 0, 1, 5.5, 1.8 });
		g_zhiShanQTKDPrice[L"河北省"].push_back({ 5, 0, 1, 5.5, 1.8 });
		g_zhiShanQTKDPrice[L"湖南省"].push_back({ 5, 0, 1, 5.5, 1.8 });
		g_zhiShanQTKDPrice[L"江西省"].push_back({ 5, 0, 1, 5.5, 1.8 });
		g_zhiShanQTKDPrice[L"山东省"].push_back({ 5, 0, 1, 5.5, 1.8 });
		g_zhiShanQTKDPrice[L"山西省"].push_back({ 5, 0, 1, 5.5, 1.8 });

		g_zhiShanQTKDPrice[L"黑龙江省"].push_back({ 5, 0, 1, 7, 3.8 });
		g_zhiShanQTKDPrice[L"吉林省"].push_back({ 5, 0, 1, 7, 3.8 });
		g_zhiShanQTKDPrice[L"辽宁省"].push_back({ 5, 0, 1, 7, 3.8 });
		g_zhiShanQTKDPrice[L"宁夏回族自治区"].push_back({ 5, 0, 1, 7, 3.8 });
		g_zhiShanQTKDPrice[L"青海省"].push_back({ 5, 0, 1, 7, 3.8 });
		g_zhiShanQTKDPrice[L"甘肃省"].push_back({ 5, 0, 1, 7, 3.8 });

		g_zhiShanQTKDPrice[L"上海"].push_back({ 5, 0, 1, 5.5, 2.2 });
		g_zhiShanQTKDPrice[L"北京"].push_back({ 5, 0, 1, 6, 2.7 });


		g_zhiShanQTKDPrice[L"海南省"].push_back({ 0, 0, 1, 10, 5.7 });
		g_zhiShanQTKDPrice[L"内蒙古自治区"].push_back({ 0, 0, 1, 10, 5.7 });
		g_zhiShanQTKDPrice[L"新疆维吾尔自治区"].push_back({ 0, 0, 1, 11, 7.5 });
		g_zhiShanQTKDPrice[L"西藏自治区"].push_back({ 0, 0, 1, 11, 7.5 });

	}

	//新马帮中通快运
	{
		g_xinMaBangZTKYPrice[L"上海"] = { 27, 1.3 };
		g_xinMaBangZTKYPrice[L"北京"] = { 27, 1.3 };
		g_xinMaBangZTKYPrice[L"河南省"] = { 27, 1.3 };
		g_xinMaBangZTKYPrice[L"江苏省"] = { 27, 1.3 };
		g_xinMaBangZTKYPrice[L"浙江省"] = { 27, 1.3 };
		g_xinMaBangZTKYPrice[L"安徽省"] = { 27, 1.3 };
		g_xinMaBangZTKYPrice[L"山东省"] = { 27, 1.3 };
		g_xinMaBangZTKYPrice[L"天津"] = { 27, 1.3 };
		g_xinMaBangZTKYPrice[L"河北省"] = { 27, 1.3 };
		g_xinMaBangZTKYPrice[L"湖南省"] = { 27, 1.3 };
		g_xinMaBangZTKYPrice[L"湖北省"] = { 27, 1.3 };
		g_xinMaBangZTKYPrice[L"山西省"] = { 27, 1.3 };
		g_xinMaBangZTKYPrice[L"陕西省"] = { 27, 1.3 };
		g_xinMaBangZTKYPrice[L"江西省"] = { 27, 1.3 };
		g_xinMaBangZTKYPrice[L"广东省"] = { 27, 1.3 };
		g_xinMaBangZTKYPrice[L"福建省"] = { 27, 1.3 };
		g_xinMaBangZTKYPrice[L"广西壮族自治区"] = { 27, 1.3 };
		g_xinMaBangZTKYPrice[L"四川省"] = { 23, 1.1 };
		g_xinMaBangZTKYPrice[L"甘孜藏族自治州"] = { 52, 1.5 };
		g_xinMaBangZTKYPrice[L"阿坝藏族羌族自治州"] = { 52, 1.5 };
		g_xinMaBangZTKYPrice[L"凉山彝族自治州"] = { 52, 1.5 };
		g_xinMaBangZTKYPrice[L"重庆"] = { 27, 1.2 };
		g_xinMaBangZTKYPrice[L"云南省"] = { 27, 1.4 };
		g_xinMaBangZTKYPrice[L"贵州省"] = { 27, 1.4 };
		g_xinMaBangZTKYPrice[L"甘肃省"] = { 35, 3 };
		g_xinMaBangZTKYPrice[L"宁夏回族自治区"] = { 45, 2.8 };
		g_xinMaBangZTKYPrice[L"青海省"] = { 45, 2.8 };
		g_xinMaBangZTKYPrice[L"黑龙江省"] = { 37, 1.6 };
		g_xinMaBangZTKYPrice[L"吉林省"] = { 37, 1.6 };
		g_xinMaBangZTKYPrice[L"辽宁省"] = { 37, 1.6 };
		g_xinMaBangZTKYPrice[L"内蒙古自治区"] = { 75, 3 };
		g_xinMaBangZTKYPrice[L"海南省"] = { 42, 2.7 };
		g_xinMaBangZTKYPrice[L"新疆维吾尔自治区"] = { 85, 3.2 };
		g_xinMaBangZTKYPrice[L"西藏自治区"] = { 75, 4.2 };
	}
	//颐麦科技中通快运
	{
		g_yiMaiKeJiZTKYPrice[L"四川省"] = { 25, 1.1 };
		g_yiMaiKeJiZTKYPrice[L"甘孜藏族自治州"] = { 25, 1.5 };
		g_yiMaiKeJiZTKYPrice[L"阿坝藏族羌族自治州"] = { 25, 1.5 };
		g_yiMaiKeJiZTKYPrice[L"凉山彝族自治州"] = { 25, 1.5 };
		g_yiMaiKeJiZTKYPrice[L"上海"] = { 28, 1.5 };
		g_yiMaiKeJiZTKYPrice[L"北京"] = { 28, 1.5 };
		g_yiMaiKeJiZTKYPrice[L"河南省"] = { 28, 1.5 };
		g_yiMaiKeJiZTKYPrice[L"江苏省"] = { 28, 1.5 };
		g_yiMaiKeJiZTKYPrice[L"浙江省"] = { 28, 1.5 };
		g_yiMaiKeJiZTKYPrice[L"安徽省"] = { 28, 1.5 };
		g_yiMaiKeJiZTKYPrice[L"山东省"] = { 28, 1.5 };
		g_yiMaiKeJiZTKYPrice[L"天津"] = { 28, 1.5 };
		g_yiMaiKeJiZTKYPrice[L"河北省"] = { 28, 1.5 };
		g_yiMaiKeJiZTKYPrice[L"湖南省"] = { 28, 1.5 };
		g_yiMaiKeJiZTKYPrice[L"湖北省"] = { 28, 1.5 };
		g_yiMaiKeJiZTKYPrice[L"山西省"] = { 28, 1.5 };
		g_yiMaiKeJiZTKYPrice[L"陕西省"] = { 28, 1.5 };
		g_yiMaiKeJiZTKYPrice[L"江西省"] = { 28, 1.5 };
		g_yiMaiKeJiZTKYPrice[L"广东省"] = { 28, 1.5 };
		g_yiMaiKeJiZTKYPrice[L"福建省"] = { 28, 1.5 };
		g_yiMaiKeJiZTKYPrice[L"广西壮族自治区"] = { 28, 1.5 };
		g_yiMaiKeJiZTKYPrice[L"重庆"] = { 28, 1.3 };
		g_yiMaiKeJiZTKYPrice[L"云南省"] = { 28, 1.5 };
		g_yiMaiKeJiZTKYPrice[L"贵州省"] = { 28, 1.5 };
		g_yiMaiKeJiZTKYPrice[L"甘肃省"] = { 28, 3 };
		g_yiMaiKeJiZTKYPrice[L"青海省"] = { 75, 3 };
		g_yiMaiKeJiZTKYPrice[L"黑龙江省"] = { 28, 1.8 };
		g_yiMaiKeJiZTKYPrice[L"吉林省"] = { 28, 1.8 };
		g_yiMaiKeJiZTKYPrice[L"辽宁省"] = { 28, 1.8 };
		g_yiMaiKeJiZTKYPrice[L"海南省"] = { 28, 3 };
		g_yiMaiKeJiZTKYPrice[L"新疆维吾尔自治区"] = { 85, 3.5 };
		g_yiMaiKeJiZTKYPrice[L"西藏自治区"] = { 65, 4.5 };
		g_yiMaiKeJiZTKYPrice[L"宁夏回族自治区"] = { 54, 3 };
		g_yiMaiKeJiZTKYPrice[L"内蒙古自治区"] = { 75, 3.5 };
	}
	//弥雅中通快运
	{
		g_miYaZTKYPrice[L"上海"] = { 27.5, 1.3 };
		g_miYaZTKYPrice[L"北京"] = { 27.5, 1.3 };
		g_miYaZTKYPrice[L"河南省"] = { 27.5, 1.3 };
		g_miYaZTKYPrice[L"江苏省"] = { 27.5, 1.3 };
		g_miYaZTKYPrice[L"浙江省"] = { 27.5, 1.3 };
		g_miYaZTKYPrice[L"安徽省"] = { 27.5, 1.3 };
		g_miYaZTKYPrice[L"山东省"] = { 27.5, 1.3 };
		g_miYaZTKYPrice[L"天津"] = { 27.5, 1.3 };
		g_miYaZTKYPrice[L"河北省"] = { 27.5, 1.3 };
		g_miYaZTKYPrice[L"湖南省"] = { 27.5, 1.3 };
		g_miYaZTKYPrice[L"湖北省"] = { 27.5, 1.3 };
		g_miYaZTKYPrice[L"山西省"] = { 27.5, 1.3 };
		g_miYaZTKYPrice[L"陕西省"] = { 27.5, 1.3 };
		g_miYaZTKYPrice[L"江西省"] = { 27.5, 1.3 };
		g_miYaZTKYPrice[L"广东省"] = { 27.5, 1.3 };
		g_miYaZTKYPrice[L"福建省"] = { 27.5, 1.3 };
		g_miYaZTKYPrice[L"广西壮族自治区"] = { 27.5, 1.3 };
		g_miYaZTKYPrice[L"四川省"] = { 22.5, 1 };
		g_miYaZTKYPrice[L"甘孜藏族自治州"] = { 50, 1.6 };
		g_miYaZTKYPrice[L"阿坝藏族羌族自治州"] = { 50, 1.6 };
		g_miYaZTKYPrice[L"凉山彝族自治州"] = { 50, 1.6 };
		g_miYaZTKYPrice[L"重庆"] = { 27.5, 1.2 };
		g_miYaZTKYPrice[L"云南省"] = { 32, 1.4 };
		g_miYaZTKYPrice[L"贵州省"] = { 27.5, 1.4 };
		g_miYaZTKYPrice[L"甘肃省"] = { 35, 3 };
		g_miYaZTKYPrice[L"宁夏回族自治区"] = { 42.5, 2.8 };
		g_miYaZTKYPrice[L"青海省"] = { 42.5, 2.8 };
		g_miYaZTKYPrice[L"黑龙江省"] = { 37, 1.7 };
		g_miYaZTKYPrice[L"吉林省"] = { 37, 1.7 };
		g_miYaZTKYPrice[L"辽宁省"] = { 37, 1.7 };
		g_miYaZTKYPrice[L"内蒙古自治区"] = { 72.5, 3 };
		g_miYaZTKYPrice[L"海南省"] = { 42, 2.7 };
		g_miYaZTKYPrice[L"新疆维吾尔自治区"] = { 82.5, 3.2 };
		g_miYaZTKYPrice[L"西藏自治区"] = { 72, 4.2 };
	}
	//七一酱园中通快运
	{

		g_qiYiJiangYuanZTKYPrice[L"上海"] = { 27.5, 1.3 };
		g_qiYiJiangYuanZTKYPrice[L"北京"] = { 27.5, 1.3 };
		g_qiYiJiangYuanZTKYPrice[L"河南省"] = { 27.5, 1.3 };
		g_qiYiJiangYuanZTKYPrice[L"江苏省"] = { 27.5, 1.3 };
		g_qiYiJiangYuanZTKYPrice[L"浙江省"] = { 27.5, 1.3 };
		g_qiYiJiangYuanZTKYPrice[L"安徽省"] = { 27.5, 1.3 };
		g_qiYiJiangYuanZTKYPrice[L"山东省"] = { 27.5, 1.3 };
		g_qiYiJiangYuanZTKYPrice[L"天津"] = { 27.5, 1.3 };
		g_qiYiJiangYuanZTKYPrice[L"河北省"] = { 27.5, 1.3 };
		g_qiYiJiangYuanZTKYPrice[L"湖南省"] = { 27.5, 1.3 };
		g_qiYiJiangYuanZTKYPrice[L"湖北省"] = { 27.5, 1.3 };
		g_qiYiJiangYuanZTKYPrice[L"山西省"] = { 27.5, 1.3 };
		g_qiYiJiangYuanZTKYPrice[L"陕西省"] = { 27.5, 1.3 };
		g_qiYiJiangYuanZTKYPrice[L"江西省"] = { 27.5, 1.3 };
		g_qiYiJiangYuanZTKYPrice[L"广东省"] = { 27.5, 1.3 };
		g_qiYiJiangYuanZTKYPrice[L"福建省"] = { 27.5, 1.3 };
		g_qiYiJiangYuanZTKYPrice[L"广西壮族自治区"] = { 27.5, 1.3 };
		g_qiYiJiangYuanZTKYPrice[L"四川省"] = { 22.5, 1 };
		g_qiYiJiangYuanZTKYPrice[L"甘孜藏族自治州"] = { 50, 1.6 };
		g_qiYiJiangYuanZTKYPrice[L"阿坝藏族羌族自治州"] = { 50, 1.6 };
		g_qiYiJiangYuanZTKYPrice[L"凉山彝族自治州"] = { 50, 1.6 };
		g_qiYiJiangYuanZTKYPrice[L"重庆"] = { 27.5, 1.2 };
		g_qiYiJiangYuanZTKYPrice[L"云南省"] = { 32, 1.4 };
		g_qiYiJiangYuanZTKYPrice[L"贵州省"] = { 27.5, 1.4 };
		g_qiYiJiangYuanZTKYPrice[L"甘肃省"] = { 35, 3 };
		g_qiYiJiangYuanZTKYPrice[L"宁夏回族自治区"] = { 42.5, 2.8 };
		g_qiYiJiangYuanZTKYPrice[L"青海省"] = { 42.5, 2.8 };
		g_qiYiJiangYuanZTKYPrice[L"黑龙江省"] = { 37, 1.7 };
		g_qiYiJiangYuanZTKYPrice[L"吉林省"] = { 37, 1.7 };
		g_qiYiJiangYuanZTKYPrice[L"辽宁省"] = { 37, 1.7 };
		g_qiYiJiangYuanZTKYPrice[L"内蒙古自治区"] = { 72.5, 3 };
		g_qiYiJiangYuanZTKYPrice[L"海南省"] = { 42, 2.7 };
		g_qiYiJiangYuanZTKYPrice[L"新疆维吾尔自治区"] = { 82.5, 3.2 };
		g_qiYiJiangYuanZTKYPrice[L"西藏自治区"] = { 72, 4.2 };
	}
	
	//弥雅顺丰
	{
		g_miYaSFPrice.resize(4);
		g_miYaSFPrice[0].push_back({ 0, 1, 1, 10, 0 });
		g_miYaSFPrice[0].push_back({ 1, 2, 2, 12.5, 0 });
		g_miYaSFPrice[0].push_back({ 2, 3, 3, 15, 0 });
		g_miYaSFPrice[0].push_back({ 3, 0, 1, 9, 4.2 });

		g_miYaSFPrice[1].push_back({ 0, 1, 1, 11, 0 });
		g_miYaSFPrice[1].push_back({ 1, 2, 2, 14, 0 });
		g_miYaSFPrice[1].push_back({ 2, 3, 3, 16, 0 });
		g_miYaSFPrice[1].push_back({ 3, 0, 1, 10, 4.5 });

		g_miYaSFPrice[2].push_back({ 0, 1, 1, 11, 0 });
		g_miYaSFPrice[2].push_back({ 1, 2, 2, 15, 0 });
		g_miYaSFPrice[2].push_back({ 2, 3, 3, 18.5, 0 });
		g_miYaSFPrice[2].push_back({ 3, 0, 1, 10, 5.5 });

		g_miYaSFPrice[3].push_back({ 0, 1, 1, 14, 0 });
		g_miYaSFPrice[3].push_back({ 1, 2, 2, 21.5, 0 });
		g_miYaSFPrice[3].push_back({ 2, 3, 3, 30, 0 });
		g_miYaSFPrice[3].push_back({ 3, 0, 1, 13, 9.5 });
	}
	//七一酱园顺丰
	{
		g_qiYiJiangYuanSFPrice.resize(4);
		g_qiYiJiangYuanSFPrice[0].push_back({ 0, 1, 1, 10, 0 });
		g_qiYiJiangYuanSFPrice[0].push_back({ 1, 2, 2, 12.5, 0 });
		g_qiYiJiangYuanSFPrice[0].push_back({ 2, 3, 3, 15, 0 });
		g_qiYiJiangYuanSFPrice[0].push_back({ 3, 0, 1, 9, 4.2 });

		g_qiYiJiangYuanSFPrice[1].push_back({ 0, 1, 1, 11, 0 });
		g_qiYiJiangYuanSFPrice[1].push_back({ 1, 2, 2, 14, 0 });
		g_qiYiJiangYuanSFPrice[1].push_back({ 2, 3, 3, 16, 0 });
		g_qiYiJiangYuanSFPrice[1].push_back({ 3, 0, 1, 10, 4.5 });

		g_qiYiJiangYuanSFPrice[2].push_back({ 0, 1, 1, 11, 0 });
		g_qiYiJiangYuanSFPrice[2].push_back({ 1, 2, 2, 15, 0 });
		g_qiYiJiangYuanSFPrice[2].push_back({ 2, 3, 3, 18.5, 0 });
		g_qiYiJiangYuanSFPrice[2].push_back({ 3, 0, 1, 10, 5.5 });

		g_qiYiJiangYuanSFPrice[3].push_back({ 0, 1, 1, 14, 0 });
		g_qiYiJiangYuanSFPrice[3].push_back({ 1, 2, 2, 21.5, 0 });
		g_qiYiJiangYuanSFPrice[3].push_back({ 2, 3, 3, 30, 0 });
		g_qiYiJiangYuanSFPrice[3].push_back({ 3, 0, 1, 13, 9.5 });
	}
	//多多买菜
	{
		g_duoDuoMaiCaiPrice[L"聚象_多多买菜"].strPinPai = L"聚象";
		g_duoDuoMaiCaiPrice[L"聚象_多多买菜"].biaoZhunPrice.zxPaoHuo = 15;
		g_duoDuoMaiCaiPrice[L"聚象_多多买菜"].biaoZhunPrice.zxZhongHuo = 25;
		g_duoDuoMaiCaiPrice[L"聚象_多多买菜"].biaoZhunPrice.tieBiao = 0.2;
		g_duoDuoMaiCaiPrice[L"聚象_多多买菜"].biaoZhunPrice.fhTiJi = 40;
		g_duoDuoMaiCaiPrice[L"聚象_多多买菜"].biaoZhunPrice.fhZhongLiang = 0.2;
		g_duoDuoMaiCaiPrice[L"聚象_多多买菜"].biaoZhunPrice.qiBu = 60;

		g_duoDuoMaiCaiPrice[L"聚象_多多买菜"].BuDanPrice.zxPaoHuo = 30;
		g_duoDuoMaiCaiPrice[L"聚象_多多买菜"].BuDanPrice.zxZhongHuo = 50;
		g_duoDuoMaiCaiPrice[L"聚象_多多买菜"].BuDanPrice.tieBiao = 0.2;
		g_duoDuoMaiCaiPrice[L"聚象_多多买菜"].BuDanPrice.fhTiJi = 80;
		g_duoDuoMaiCaiPrice[L"聚象_多多买菜"].BuDanPrice.fhZhongLiang = 0.4;
		g_duoDuoMaiCaiPrice[L"聚象_多多买菜"].BuDanPrice.qiBu = 150;


		g_duoDuoMaiCaiPrice[L"星仔岛_多多买菜"].strPinPai = L"星仔岛";
		g_duoDuoMaiCaiPrice[L"星仔岛_多多买菜"].tuiHuoMianFei = 30;
		g_duoDuoMaiCaiPrice[L"星仔岛_多多买菜"].biaoZhunPrice.zxPaoHuo = 15;
		g_duoDuoMaiCaiPrice[L"星仔岛_多多买菜"].biaoZhunPrice.zxZhongHuo = 25;
		g_duoDuoMaiCaiPrice[L"星仔岛_多多买菜"].biaoZhunPrice.tieBiao = 0.2;
		g_duoDuoMaiCaiPrice[L"星仔岛_多多买菜"].biaoZhunPrice.fhTiJi = 35;
		g_duoDuoMaiCaiPrice[L"星仔岛_多多买菜"].biaoZhunPrice.fhZhongLiang = 0.18;
		g_duoDuoMaiCaiPrice[L"星仔岛_多多买菜"].biaoZhunPrice.qiBu = 50;

		g_duoDuoMaiCaiPrice[L"星仔岛_多多买菜"].BuDanPrice.zxPaoHuo = 30;
		g_duoDuoMaiCaiPrice[L"星仔岛_多多买菜"].BuDanPrice.zxZhongHuo = 50;
		g_duoDuoMaiCaiPrice[L"星仔岛_多多买菜"].BuDanPrice.tieBiao = 0.2;
		g_duoDuoMaiCaiPrice[L"星仔岛_多多买菜"].BuDanPrice.fhTiJi = 70;
		g_duoDuoMaiCaiPrice[L"星仔岛_多多买菜"].BuDanPrice.fhZhongLiang = 0.35;
		g_duoDuoMaiCaiPrice[L"星仔岛_多多买菜"].BuDanPrice.qiBu = 150;


		g_duoDuoMaiCaiPrice[L"百知_多多买菜"].strPinPai = L"百知";
		g_duoDuoMaiCaiPrice[L"百知_多多买菜"].tuiHuoMianFei = 30;
		g_duoDuoMaiCaiPrice[L"百知_多多买菜"].biaoZhunPrice.zxPaoHuo = 7;
		g_duoDuoMaiCaiPrice[L"百知_多多买菜"].biaoZhunPrice.zxZhongHuo = 25;
		g_duoDuoMaiCaiPrice[L"百知_多多买菜"].biaoZhunPrice.tieBiao = 0.2;
		g_duoDuoMaiCaiPrice[L"百知_多多买菜"].biaoZhunPrice.fhTiJi = 30;
		g_duoDuoMaiCaiPrice[L"百知_多多买菜"].biaoZhunPrice.fhZhongLiang = 0.15;
		g_duoDuoMaiCaiPrice[L"百知_多多买菜"].biaoZhunPrice.qiBu = 50;

		g_duoDuoMaiCaiPrice[L"百知_多多买菜"].BuDanPrice.zxPaoHuo = 14;
		g_duoDuoMaiCaiPrice[L"百知_多多买菜"].BuDanPrice.zxZhongHuo = 50;
		g_duoDuoMaiCaiPrice[L"百知_多多买菜"].BuDanPrice.tieBiao = 0.2;
		g_duoDuoMaiCaiPrice[L"百知_多多买菜"].BuDanPrice.fhTiJi = 60;
		g_duoDuoMaiCaiPrice[L"百知_多多买菜"].BuDanPrice.fhZhongLiang = 0.3;
		g_duoDuoMaiCaiPrice[L"百知_多多买菜"].BuDanPrice.qiBu = 100;

		g_duoDuoMaiCaiPrice[L"蜂献_多多买菜"].strPinPai = L"蜂献";
		g_duoDuoMaiCaiPrice[L"蜂献_多多买菜"].tuiHuoMianFei = 30;
		g_duoDuoMaiCaiPrice[L"蜂献_多多买菜"].biaoZhunPrice.zxPaoHuo = 15;
		g_duoDuoMaiCaiPrice[L"蜂献_多多买菜"].biaoZhunPrice.zxZhongHuo = 25;
		g_duoDuoMaiCaiPrice[L"蜂献_多多买菜"].biaoZhunPrice.tieBiao = 0.2;
		g_duoDuoMaiCaiPrice[L"蜂献_多多买菜"].biaoZhunPrice.fhTiJi = 40;
		g_duoDuoMaiCaiPrice[L"蜂献_多多买菜"].biaoZhunPrice.fhZhongLiang = 0.13;
		g_duoDuoMaiCaiPrice[L"蜂献_多多买菜"].biaoZhunPrice.qiBu = 50;

		g_duoDuoMaiCaiPrice[L"蜂献_多多买菜"].BuDanPrice.zxPaoHuo = 30;
		g_duoDuoMaiCaiPrice[L"蜂献_多多买菜"].BuDanPrice.zxZhongHuo = 50;
		g_duoDuoMaiCaiPrice[L"蜂献_多多买菜"].BuDanPrice.tieBiao = 0.2;
		g_duoDuoMaiCaiPrice[L"蜂献_多多买菜"].BuDanPrice.fhTiJi = 80;
		g_duoDuoMaiCaiPrice[L"蜂献_多多买菜"].BuDanPrice.fhZhongLiang = 0.26;
		g_duoDuoMaiCaiPrice[L"蜂献_多多买菜"].BuDanPrice.qiBu = 100;
	}
}

//----------------------------------------------------------------------------------//