#include "stdafx.h"
#include "expressPrice.h"
//------------------------------------快递价格--------------------------------------//
std::map< std::wstring, std::list<sExpressPriceInfo> > g_taiFuShangMaoBSPrice;
std::map< std::wstring, std::list<sExpressPriceInfo> > g_yiMaiKeJiBSPrice;
std::map< std::wstring, std::list<sExpressPriceInfo> > g_qiYiJiangYuanBSPrice;
std::map< std::wstring, std::list<sExpressPriceInfo> > g_xinMaBangBSPrice;
std::map< std::wstring, std::list<sExpressPriceInfo> > g_miYaBSPrice;
std::map< std::wstring, std::list<sExpressPriceInfo> > g_kunLunShanYTPrice;
//----------------------------------------------------------------------------------//

//------------------------------------顺丰价格--------------------------------------//
//永创耀辉
std::vector< std::list<sExpressPriceInfo> > g_yongChuangYaoHuiSFPrice;
//----------------------------------------------------------------------------------//


//------------------------------------快运价格--------------------------------------//
//永创耀辉
std::vector< std::list<sExpressPriceInfo> > g_yongChuangYaoHuiZTKYPrice;
//----------------------------------------------------------------------------------//

void PrepareExpressPrice()
{
	g_yongChuangYaoHuiSFPrice.resize(4);
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
		g_kunLunShanYTPrice[L"新疆维吾尔自治区"].push_back({ 0, 0, 1, 15.5, 13.5 });
		g_kunLunShanYTPrice[L"西藏自治区"].push_back({ 0, 0, 1, 17.5, 17.5 });
	}

	//永创耀辉中通快运
	{
		g_yongChuangYaoHuiZTKYPrice
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
		g_kunLunShanYTPrice[L"新疆维吾尔自治区"].push_back({ 0, 0, 1, 15.5, 13.5 });
		g_kunLunShanYTPrice[L"西藏自治区"].push_back({ 0, 0, 1, 17.5, 17.5 });
		
	}
}

//----------------------------------------------------------------------------------//