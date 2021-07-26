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
std::map< std::wstring, std::list<sExpressPriceInfo> > g_weiFuKangYDKDPrice;
std::map< std::wstring, std::list<sExpressPriceInfo> > g_jingXinGeYDKDPrice;
std::map< std::wstring, std::list<sExpressPriceInfo> > g_quLvShouNaKDPrice;
std::map< std::wstring, std::list<sExpressPriceInfo> > g_shuoGuoLiuXiangKDPrice;
std::map< std::wstring, std::list<sExpressPriceInfo> > g_xingXingShaoNvKDPrice;
std::map< std::wstring, std::list<sExpressPriceInfo> > g_tuNiangNiangKDPrice;
std::map< std::wstring, std::list<sExpressPriceInfo> > g_chuJianNingMengChaKDPrice;
std::map< std::wstring, std::list<sExpressPriceInfo> > g_xiaoBaiXiongKDPrice;
std::map< std::wstring, std::list<sExpressPriceInfo> > g_tuKaDuoGeKDPrice;
std::map< std::wstring, std::list<sExpressPriceInfo> > g_aiWeiErKDPrice;
//----------------------------------------------------------------------------------//

//------------------------------------顺丰价格--------------------------------------//
//永创耀辉
std::vector< std::list<sExpressPriceInfo> > g_yongChuangYaoHuiSFPrice;
//弥雅
std::vector< std::list<sExpressPriceInfo> > g_miYaSFPrice;
//七一酱园
std::vector< std::list<sExpressPriceInfo> > g_qiYiJiangYuanSFPrice;
//颐麦科技
std::vector< std::list<sExpressPriceInfo> > g_yiMaiKeJiSFPrice;
//趣旅收纳
std::vector< std::list<sExpressPriceInfo> > g_quLvShouNaSFPrice;
//硕果流香
std::vector< std::list<sExpressPriceInfo> > g_shuoGuoLiuXiangSFPrice;
//至善电商
std::vector< std::list<sExpressPriceInfo> > g_zhiShanSFPrice;
//----------------------------------------------------------------------------------//


//------------------------------------快运价格--------------------------------------//
//永创耀辉
std::map< std::wstring, std::list<sLargeExpressPriceInfo> > g_yongChuangYaoHuiZTKYPrice;
//新马帮
std::map< std::wstring, std::list<sLargeExpressPriceInfo> > g_xinMaBangZTKYPrice;
//颐麦科技
std::map< std::wstring, std::list<sLargeExpressPriceInfo> > g_yiMaiKeJiZTKYPrice;
//弥雅
std::map< std::wstring, std::list<sLargeExpressPriceInfo> > g_miYaZTKYPrice;
//七一酱园
std::map< std::wstring, std::list<sLargeExpressPriceInfo> > g_qiYiJiangYuanZTKYPrice;
//至善电商
std::map< std::wstring, std::list<sLargeExpressPriceInfo> > g_zhiShanZTKYPrice;
//维敷康
std::map< std::wstring, std::list<sLargeExpressPriceInfo> > g_weiFuKangZTKYPrice;
//----------------------------------------------------------------------------------//


//----------------------------------成本核算价格用---------------------------------//
std::map< std::wstring, std::list<sLargeExpressPriceInfo> > g_chengBenZTKYPrice;

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
		/*g_yongChuangYaoHuiSFPrice.resize(4);
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
		g_yongChuangYaoHuiSFPrice[3].push_back({ 3, 0, 1, 13, 9.5 });*/

		g_yongChuangYaoHuiSFPrice.resize(2);
		g_yongChuangYaoHuiSFPrice[0].push_back({ 0, 3, 3, 8, 0 });
		g_yongChuangYaoHuiSFPrice[0].push_back({ 3, 0, 3, 8, 1.4 });

		g_yongChuangYaoHuiSFPrice[1].push_back({ 0, 3, 3, 10, 0 });
		g_yongChuangYaoHuiSFPrice[1].push_back({ 3, 0, 3, 10, 3 });
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
		//12公斤
		g_chengBenZTKYPrice[L"吉林省"].push_back({ 0, 12, 12, 35, 0 });
		g_chengBenZTKYPrice[L"辽宁省"].push_back({ 0, 12, 12, 35, 0 });
		g_chengBenZTKYPrice[L"黑龙江省"].push_back({ 0, 12, 12, 35, 0 });
		g_chengBenZTKYPrice[L"河南省"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"湖北省"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"湖南省"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"上海"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"安徽省"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"山东省"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"江苏省"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"江西省"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"浙江省"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"内蒙古自治区"].push_back({ 0, 12, 12, 40, 0 });
		g_chengBenZTKYPrice[L"北京"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"天津"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"山西省"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"河北省"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"广西壮族自治区"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"广东省"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"福建省"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"宁夏回族自治区"].push_back({ 0, 12, 12, 40, 0 });
		g_chengBenZTKYPrice[L"新疆维吾尔自治区"].push_back({ 0, 12, 12, 55, 0 });
		g_chengBenZTKYPrice[L"甘肃省"].push_back({ 0, 12, 12, 40, 0 });
		g_chengBenZTKYPrice[L"陕西省"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"青海省"].push_back({ 0, 12, 12, 50, 0 });
		g_chengBenZTKYPrice[L"云南省"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"乐山市"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"内江市"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"凉山彝族自治州"].push_back({ 0, 12, 12, 40, 0 });
		g_chengBenZTKYPrice[L"南充市"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"宜宾市"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"巴中市"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"广元市"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"广安市"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"德阳市"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"成都市"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"攀枝花市"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"泸州市"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"甘孜藏族自治州"].push_back({ 0, 12, 12, 40, 0 });
		g_chengBenZTKYPrice[L"眉山市"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"绵阳市"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"自贡市"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"资阳市"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"达州市"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"遂宁市"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"阿坝藏族羌族自治州"].push_back({ 0, 12, 12, 40, 0 });
		g_chengBenZTKYPrice[L"雅安市"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"西藏自治区"].push_back({ 0, 12, 12, 70, 0 });
		g_chengBenZTKYPrice[L"贵州省"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"重庆"].push_back({ 0, 12, 12, 16, 0 });
		//13-20公斤
		g_chengBenZTKYPrice[L"吉林省"].push_back({ 12, 20, 20, 40, 0 });
		g_chengBenZTKYPrice[L"辽宁省"].push_back({ 12, 20, 20, 40, 0 });
		g_chengBenZTKYPrice[L"黑龙江省"].push_back({ 12, 20, 20, 40, 0 });
		g_chengBenZTKYPrice[L"河南省"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"湖北省"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"湖南省"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"上海"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"安徽省"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"山东省"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"江苏省"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"江西省"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"浙江省"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"内蒙古自治区"].push_back({ 12, 20, 20, 50, 0 });
		g_chengBenZTKYPrice[L"北京"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"天津"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"山西省"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"河北省"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"广西壮族自治区"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"广东省"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"福建省"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"宁夏回族自治区"].push_back({ 12, 20, 20, 50, 0 });
		g_chengBenZTKYPrice[L"新疆维吾尔自治区"].push_back({ 12, 20, 20, 55, 0 });
		g_chengBenZTKYPrice[L"甘肃省"].push_back({ 12, 20, 20, 50, 0 });
		g_chengBenZTKYPrice[L"陕西省"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"青海省"].push_back({ 12, 20, 20, 55, 0 });
		g_chengBenZTKYPrice[L"云南省"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"乐山市"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"内江市"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"凉山彝族自治州"].push_back({ 12, 20, 20, 50, 0 });
		g_chengBenZTKYPrice[L"南充市"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"宜宾市"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"巴中市"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"广元市"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"广安市"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"德阳市"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"成都市"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"攀枝花市"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"泸州市"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"甘孜藏族自治州"].push_back({ 12, 20, 20, 50, 0 });
		g_chengBenZTKYPrice[L"眉山市"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"绵阳市"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"自贡市"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"资阳市"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"达州市"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"遂宁市"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"阿坝藏族羌族自治州"].push_back({ 12, 20, 20, 50, 0 });
		g_chengBenZTKYPrice[L"雅安市"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"西藏自治区"].push_back({ 12, 20, 20, 80, 0 });
		g_chengBenZTKYPrice[L"贵州省"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"重庆"].push_back({ 12, 20, 20, 19, 0 });
		//20公斤以上
		g_chengBenZTKYPrice[L"吉林省"].push_back({ 20, 0, 20, 40, 1.5 });
		g_chengBenZTKYPrice[L"辽宁省"].push_back({ 20, 0, 20, 40, 1.5 });
		g_chengBenZTKYPrice[L"黑龙江省"].push_back({ 20, 0, 20, 40, 1.5 });
		g_chengBenZTKYPrice[L"河南省"].push_back({ 20, 0, 20, 19, 1.1 });
		g_chengBenZTKYPrice[L"湖北省"].push_back({ 20, 0, 20, 19, 1.1 });
		g_chengBenZTKYPrice[L"湖南省"].push_back({ 20, 0, 20, 19, 1.1 });
		g_chengBenZTKYPrice[L"上海"].push_back({ 20, 0, 20, 19, 1.1 });
		g_chengBenZTKYPrice[L"安徽省"].push_back({ 20, 0, 20, 19, 1.1 });
		g_chengBenZTKYPrice[L"山东省"].push_back({ 20, 0, 20, 19, 1.1 });
		g_chengBenZTKYPrice[L"江苏省"].push_back({ 20, 0, 20, 19, 1.1 });
		g_chengBenZTKYPrice[L"江西省"].push_back({ 20, 0, 20, 19, 1.1 });
		g_chengBenZTKYPrice[L"浙江省"].push_back({ 20, 0, 20, 19, 1.1 });
		g_chengBenZTKYPrice[L"内蒙古自治区"].push_back({ 20, 0, 20, 50, 1.50 });
		g_chengBenZTKYPrice[L"北京"].push_back({ 20, 0, 20, 19, 1.1 });
		g_chengBenZTKYPrice[L"天津"].push_back({ 20, 0, 20, 19, 1.1 });
		g_chengBenZTKYPrice[L"山西省"].push_back({ 20, 0, 20, 19, 1.1 });
		g_chengBenZTKYPrice[L"河北省"].push_back({ 20, 0, 20, 19, 1.1 });
		g_chengBenZTKYPrice[L"广西壮族自治区"].push_back({ 20, 0, 20, 19, 1.1 });
		g_chengBenZTKYPrice[L"广东省"].push_back({ 20, 0, 20, 19, 1.1 });
		g_chengBenZTKYPrice[L"福建省"].push_back({ 20, 0, 20, 19, 1.1 });
		g_chengBenZTKYPrice[L"宁夏回族自治区"].push_back({ 20, 0, 20, 50, 1.5 });
		g_chengBenZTKYPrice[L"新疆维吾尔自治区"].push_back({ 20, 0, 20, 55, 3 });
		g_chengBenZTKYPrice[L"甘肃省"].push_back({ 20, 0, 20, 50, 1.6 });
		g_chengBenZTKYPrice[L"陕西省"].push_back({ 20, 0, 20, 19, 1.1 });
		g_chengBenZTKYPrice[L"青海省"].push_back({ 20, 0, 20, 55, 3 });

		g_chengBenZTKYPrice[L"云南省"].push_back({ 20, 0, 20, 19, 1.1 });

		g_chengBenZTKYPrice[L"乐山市"].push_back({ 20, 0, 20, 19, 0.8 });
		g_chengBenZTKYPrice[L"内江市"].push_back({ 20, 0, 20, 19, 0.8 });
		g_chengBenZTKYPrice[L"凉山彝族自治州"].push_back({ 20, 0, 20, 50, 1.50 });
		g_chengBenZTKYPrice[L"南充市"].push_back({ 20, 0, 20, 19, 0.8 });
		g_chengBenZTKYPrice[L"宜宾市"].push_back({ 20, 0, 20, 19, 0.8 });
		g_chengBenZTKYPrice[L"巴中市"].push_back({ 20, 0, 20, 19, 0.8 });
		g_chengBenZTKYPrice[L"广元市"].push_back({ 20, 0, 20, 19, 0.8 });
		g_chengBenZTKYPrice[L"广安市"].push_back({ 20, 0, 20, 19, 0.8 });
		g_chengBenZTKYPrice[L"德阳市"].push_back({ 20, 0, 20, 19, 0.8 });
		g_chengBenZTKYPrice[L"成都市"].push_back({ 20, 0, 20, 19, 0.8 });
		g_chengBenZTKYPrice[L"攀枝花市"].push_back({ 20, 0, 20, 19, 1.0 });
		g_chengBenZTKYPrice[L"泸州市"].push_back({ 20, 0, 20, 19, 0.8 });
		g_chengBenZTKYPrice[L"甘孜藏族自治州"].push_back({ 20, 0, 20, 50, 1.50 });
		g_chengBenZTKYPrice[L"眉山市"].push_back({ 20, 0, 20, 19, 0.8 });
		g_chengBenZTKYPrice[L"绵阳市"].push_back({ 20, 0, 20, 19, 0.8 });
		g_chengBenZTKYPrice[L"自贡市"].push_back({ 20, 0, 20, 19, 0.8 });
		g_chengBenZTKYPrice[L"资阳市"].push_back({ 20, 0, 20, 19, 0.8 });
		g_chengBenZTKYPrice[L"达州市"].push_back({ 20, 0, 20, 19, 0.8 });
		g_chengBenZTKYPrice[L"遂宁市"].push_back({ 20, 0, 20, 19, 0.8 });
		g_chengBenZTKYPrice[L"阿坝藏族羌族自治州"].push_back({ 20, 0, 20, 50, 1.50 });
		g_chengBenZTKYPrice[L"雅安市"].push_back({ 20, 0, 20, 19, 0.8 });
		g_chengBenZTKYPrice[L"西藏自治区"].push_back({ 20, 0, 20, 80, 3 });
		g_chengBenZTKYPrice[L"贵州省"].push_back({ 20, 0, 20, 19, 1.1 });
		g_chengBenZTKYPrice[L"重庆"].push_back({ 20, 0, 20, 19, 1.0 });
	}
	//永创耀辉中通快运
	{
		//12公斤
		g_yongChuangYaoHuiZTKYPrice[L"吉林省"].push_back({ 0, 12, 12, 40, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"辽宁省"].push_back({ 0, 12, 12, 40, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"黑龙江省"].push_back({ 0, 12, 12, 40, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"河南省"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"湖北省"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"湖南省"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"上海"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"安徽省"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"山东省"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"江苏省"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"江西省"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"浙江省"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"内蒙古自治区"].push_back({ 0, 12, 12, 45, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"北京"].push_back({ 0, 12, 12, 25, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"天津"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"山西省"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"河北省"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"广西壮族自治区"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"广东省"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"福建省"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"宁夏回族自治区"].push_back({ 0, 12, 12, 45, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"新疆维吾尔自治区"].push_back({ 0, 12, 12, 55, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"甘肃省"].push_back({ 0, 12, 12, 45, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"陕西省"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"青海省"].push_back({ 0, 12, 12, 50, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"云南省"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"乐山市"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"内江市"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"凉山彝族自治州"].push_back({ 0, 12, 12, 29, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"南充市"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"宜宾市"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"巴中市"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"广元市"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"广安市"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"德阳市"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"成都市"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"攀枝花市"].push_back({ 0, 12, 12, 29, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"泸州市"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"甘孜藏族自治州"].push_back({ 0, 12, 12, 29, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"眉山市"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"绵阳市"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"自贡市"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"资阳市"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"达州市"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"遂宁市"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"阿坝藏族羌族自治州"].push_back({ 0, 12, 12, 29, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"雅安市"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"西藏自治区"].push_back({ 0, 12, 12, 60, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"贵州省"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"重庆"].push_back({ 0, 12, 12, 19, 0 });
		//13-20公斤
		g_yongChuangYaoHuiZTKYPrice[L"吉林省"].push_back({ 12, 20, 20, 50, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"辽宁省"].push_back({ 12, 20, 20, 50, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"黑龙江省"].push_back({ 12, 20, 20, 50, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"河南省"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"湖北省"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"湖南省"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"上海"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"安徽省"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"山东省"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"江苏省"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"江西省"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"浙江省"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"内蒙古自治区"].push_back({ 12, 20, 20, 55, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"北京"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"天津"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"山西省"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"河北省"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"广西壮族自治区"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"广东省"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"福建省"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"宁夏回族自治区"].push_back({ 12, 20, 20, 55, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"新疆维吾尔自治区"].push_back({ 12, 20, 20, 60, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"甘肃省"].push_back({ 12, 20, 20, 55, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"陕西省"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"青海省"].push_back({ 12, 20, 20, 55, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"云南省"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"乐山市"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"内江市"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"凉山彝族自治州"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"南充市"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"宜宾市"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"巴中市"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"广元市"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"广安市"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"德阳市"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"成都市"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"攀枝花市"].push_back({ 12, 20, 20, 35, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"泸州市"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"甘孜藏族自治州"].push_back({ 12, 20, 20, 35, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"眉山市"].push_back({ 12, 20, 20, 30, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"绵阳市"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"自贡市"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"资阳市"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"达州市"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"遂宁市"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"阿坝藏族羌族自治州"].push_back({ 12, 20, 20, 35, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"雅安市"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"西藏自治区"].push_back({ 12, 20, 20, 70, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"贵州省"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"重庆"].push_back({ 12, 20, 20, 24, 0 });
		//20公斤以上
		g_yongChuangYaoHuiZTKYPrice[L"吉林省"].push_back({ 20, 0, 20, 50, 2.00 });
		g_yongChuangYaoHuiZTKYPrice[L"辽宁省"].push_back({ 20, 0, 20, 50, 2.00 });
		g_yongChuangYaoHuiZTKYPrice[L"黑龙江省"].push_back({ 20, 0, 20, 50, 2.00 });
		g_yongChuangYaoHuiZTKYPrice[L"河南省"].push_back({ 20, 0, 20, 24, 1.20 });
		g_yongChuangYaoHuiZTKYPrice[L"湖北省"].push_back({ 20, 0, 20, 24, 1.20 });
		g_yongChuangYaoHuiZTKYPrice[L"湖南省"].push_back({ 20, 0, 20, 24, 1.20 });
		g_yongChuangYaoHuiZTKYPrice[L"上海"].push_back({ 20, 0, 20, 24, 1.20 });
		g_yongChuangYaoHuiZTKYPrice[L"安徽省"].push_back({ 20, 0, 20, 24, 1.20 });
		g_yongChuangYaoHuiZTKYPrice[L"山东省"].push_back({ 20, 0, 20, 24, 1.20 });
		g_yongChuangYaoHuiZTKYPrice[L"江苏省"].push_back({ 20, 0, 20, 24, 1.20 });
		g_yongChuangYaoHuiZTKYPrice[L"江西省"].push_back({ 20, 0, 20, 24, 1.20 });
		g_yongChuangYaoHuiZTKYPrice[L"浙江省"].push_back({ 20, 0, 20, 24, 1.20 });
		g_yongChuangYaoHuiZTKYPrice[L"内蒙古自治区"].push_back({ 20, 0, 20, 55, 1.80 });
		g_yongChuangYaoHuiZTKYPrice[L"北京"].push_back({ 20, 0, 20, 24, 1.20 });
		g_yongChuangYaoHuiZTKYPrice[L"天津"].push_back({ 20, 0, 20, 24, 1.20 });
		g_yongChuangYaoHuiZTKYPrice[L"山西省"].push_back({ 20, 0, 20, 24, 1.20 });
		g_yongChuangYaoHuiZTKYPrice[L"河北省"].push_back({ 20, 0, 20, 24, 1.20 });
		g_yongChuangYaoHuiZTKYPrice[L"广西壮族自治区"].push_back({ 20, 0, 20, 24, 1.20 });
		g_yongChuangYaoHuiZTKYPrice[L"广东省"].push_back({ 20, 0, 20, 24, 1.20 });
		g_yongChuangYaoHuiZTKYPrice[L"福建省"].push_back({ 20, 0, 20, 24, 1.20 });
		g_yongChuangYaoHuiZTKYPrice[L"宁夏回族自治区"].push_back({ 20, 0, 20, 55, 2.00 });
		g_yongChuangYaoHuiZTKYPrice[L"新疆维吾尔自治区"].push_back({ 20, 0, 20, 60, 2.90 });
		g_yongChuangYaoHuiZTKYPrice[L"甘肃省"].push_back({ 20, 0, 20, 55, 2.00 });
		g_yongChuangYaoHuiZTKYPrice[L"陕西省"].push_back({ 20, 0, 20, 24, 1.20 });
		g_yongChuangYaoHuiZTKYPrice[L"青海省"].push_back({ 20, 0, 20, 55, 2.40 });
		g_yongChuangYaoHuiZTKYPrice[L"云南省"].push_back({ 20, 0, 20, 24, 1.20 });
		g_yongChuangYaoHuiZTKYPrice[L"乐山市"].push_back({ 20, 0, 20, 24, 0.80 });
		g_yongChuangYaoHuiZTKYPrice[L"内江市"].push_back({ 20, 0, 20, 24, 0.90 });
		g_yongChuangYaoHuiZTKYPrice[L"凉山彝族自治州"].push_back({ 20, 0, 20, 24, 1.20 });
		g_yongChuangYaoHuiZTKYPrice[L"南充市"].push_back({ 20, 0, 20, 24, 0.80 });
		g_yongChuangYaoHuiZTKYPrice[L"宜宾市"].push_back({ 20, 0, 20, 24, 0.90 });
		g_yongChuangYaoHuiZTKYPrice[L"巴中市"].push_back({ 20, 0, 20, 24, 0.90 });
		g_yongChuangYaoHuiZTKYPrice[L"广元市"].push_back({ 20, 0, 20, 24, 0.90 });
		g_yongChuangYaoHuiZTKYPrice[L"广安市"].push_back({ 20, 0, 20, 24, 0.90 });
		g_yongChuangYaoHuiZTKYPrice[L"德阳市"].push_back({ 20, 0, 20, 24, 0.80 });
		g_yongChuangYaoHuiZTKYPrice[L"成都市"].push_back({ 20, 0, 20, 24, 0.70 });
		g_yongChuangYaoHuiZTKYPrice[L"攀枝花市"].push_back({ 20, 0, 20, 35, 1.20 });
		g_yongChuangYaoHuiZTKYPrice[L"泸州市"].push_back({ 20, 0, 20, 24, 1.00 });
		g_yongChuangYaoHuiZTKYPrice[L"甘孜藏族自治州"].push_back({ 20, 0, 20, 35, 1.20 });
		g_yongChuangYaoHuiZTKYPrice[L"眉山市"].push_back({ 20, 0, 20, 30, 0.80 });
		g_yongChuangYaoHuiZTKYPrice[L"绵阳市"].push_back({ 20, 0, 20, 24, 0.80 });
		g_yongChuangYaoHuiZTKYPrice[L"自贡市"].push_back({ 20, 0, 20, 24, 0.90 });
		g_yongChuangYaoHuiZTKYPrice[L"资阳市"].push_back({ 20, 0, 20, 24, 0.80 });
		g_yongChuangYaoHuiZTKYPrice[L"达州市"].push_back({ 20, 0, 20, 24, 1.00 });
		g_yongChuangYaoHuiZTKYPrice[L"遂宁市"].push_back({ 20, 0, 20, 24, 0.80 });
		g_yongChuangYaoHuiZTKYPrice[L"阿坝藏族羌族自治州"].push_back({ 20, 0, 20, 35, 1.20 });
		g_yongChuangYaoHuiZTKYPrice[L"雅安市"].push_back({ 20, 0, 20, 24, 0.90 });
		g_yongChuangYaoHuiZTKYPrice[L"西藏自治区"].push_back({ 20, 0, 20, 70, 2.80 });
		g_yongChuangYaoHuiZTKYPrice[L"贵州省"].push_back({ 20, 0, 20, 24, 1.20 });
		g_yongChuangYaoHuiZTKYPrice[L"重庆"].push_back({ 20, 0, 20, 24, 1.00 });
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
	//维敷康韵达快递
	{
		//3公斤
		g_weiFuKangYDKDPrice[L"河南省"].push_back({ 0, 3, 3, 2.9, 0 });
		g_weiFuKangYDKDPrice[L"江苏省"].push_back({ 0, 3, 3, 2.9, 0 });
		g_weiFuKangYDKDPrice[L"浙江省"].push_back({ 0, 3, 3, 2.9, 0 });
		g_weiFuKangYDKDPrice[L"安徽省"].push_back({ 0, 3, 3, 2.9, 0 });
		g_weiFuKangYDKDPrice[L"山东省"].push_back({ 0, 3, 3, 2.9, 0 });
		g_weiFuKangYDKDPrice[L"天津"].push_back({ 0, 3, 3, 2.9, 0 });
		g_weiFuKangYDKDPrice[L"河北省"].push_back({ 0, 3, 3, 2.9, 0 });
		g_weiFuKangYDKDPrice[L"湖南省"].push_back({ 0, 3, 3, 2.9, 0 });
		g_weiFuKangYDKDPrice[L"湖北省"].push_back({ 0, 3, 3, 2.9, 0 });
		g_weiFuKangYDKDPrice[L"山西省"].push_back({ 0, 3, 3, 2.9, 0 });
		g_weiFuKangYDKDPrice[L"陕西省"].push_back({ 0, 3, 3, 2.9, 0 });
		g_weiFuKangYDKDPrice[L"江西省"].push_back({ 0, 3, 3, 2.9, 0 });
		g_weiFuKangYDKDPrice[L"广东省"].push_back({ 0, 3, 3, 2.9, 0 });
		g_weiFuKangYDKDPrice[L"福建省"].push_back({ 0, 3, 3, 2.9, 0 });
		g_weiFuKangYDKDPrice[L"广西壮族自治区"].push_back({ 0, 3, 3, 2.9, 0 });
		g_weiFuKangYDKDPrice[L"云南省"].push_back({ 0, 3, 3, 2.9, 0 });
		g_weiFuKangYDKDPrice[L"贵州省"].push_back({ 0, 3, 3, 2.9, 0 });
		g_weiFuKangYDKDPrice[L"重庆"].push_back({ 0, 3, 3, 2.9, 0 });

		g_weiFuKangYDKDPrice[L"四川省"].push_back({ 0, 3, 3, 2.8, 0 });

		g_weiFuKangYDKDPrice[L"黑龙江省"].push_back({ 0, 3, 3, 4, 0 });
		g_weiFuKangYDKDPrice[L"吉林省"].push_back({ 0, 3, 3, 4, 0 });
		g_weiFuKangYDKDPrice[L"辽宁省"].push_back({ 0, 3, 3, 4, 0 });
		
		g_weiFuKangYDKDPrice[L"深圳市"].push_back({ 0, 3, 3, 4, 0 });
		g_weiFuKangYDKDPrice[L"上海"].push_back({ 0, 3, 3, 4, 0 });
		g_weiFuKangYDKDPrice[L"北京"].push_back({ 0, 3, 3, 4, 0 });
		//3公斤以上
		g_weiFuKangYDKDPrice[L"河南省"].push_back({ 3, 0, 3, 4, 1.3 });
		g_weiFuKangYDKDPrice[L"江苏省"].push_back({ 3, 0, 3, 4, 1.3 });
		g_weiFuKangYDKDPrice[L"浙江省"].push_back({ 3, 0, 3, 4, 1.3 });
		g_weiFuKangYDKDPrice[L"安徽省"].push_back({ 3, 0, 3, 4, 1.3 });
		g_weiFuKangYDKDPrice[L"山东省"].push_back({ 3, 0, 3, 4, 1.3 });
		g_weiFuKangYDKDPrice[L"天津"].push_back({ 3, 0, 3, 4, 1.3 });
		g_weiFuKangYDKDPrice[L"河北省"].push_back({ 3, 0, 3, 4, 1.3 });
		g_weiFuKangYDKDPrice[L"湖南省"].push_back({ 3, 0, 3, 4, 1.3 });
		g_weiFuKangYDKDPrice[L"湖北省"].push_back({ 3, 0, 3, 4, 1.3 });
		g_weiFuKangYDKDPrice[L"山西省"].push_back({ 3, 0, 3, 4, 1.3 });
		g_weiFuKangYDKDPrice[L"陕西省"].push_back({ 3, 0, 3, 4, 1.3 });
		g_weiFuKangYDKDPrice[L"江西省"].push_back({ 3, 0, 3, 4, 1.3 });
		g_weiFuKangYDKDPrice[L"广东省"].push_back({ 3, 0, 3, 4, 1.3 });
		g_weiFuKangYDKDPrice[L"福建省"].push_back({ 3, 0, 3, 4, 1.3 });
		g_weiFuKangYDKDPrice[L"广西壮族自治区"].push_back({ 3, 0, 3, 4, 1.3 });
		g_weiFuKangYDKDPrice[L"云南省"].push_back({ 3, 0, 3, 4, 1.3 });
		g_weiFuKangYDKDPrice[L"贵州省"].push_back({ 3, 0, 3, 4, 1.3 });
		g_weiFuKangYDKDPrice[L"重庆"].push_back({ 3, 0, 3, 4, 1.3 });

		g_weiFuKangYDKDPrice[L"四川省"].push_back({ 3, 0, 3, 4, 1 });

		g_weiFuKangYDKDPrice[L"黑龙江省"].push_back({ 3, 0, 3, 5, 2.5 });
		g_weiFuKangYDKDPrice[L"吉林省"].push_back({ 3, 0, 3, 5, 2.5 });
		g_weiFuKangYDKDPrice[L"辽宁省"].push_back({ 3, 0, 3, 5, 2.5 });

		g_weiFuKangYDKDPrice[L"深圳市"].push_back({ 3, 0, 3, 4, 1.3 });
		g_weiFuKangYDKDPrice[L"上海"].push_back({ 3, 0, 3, 4, 1.3 });
		g_weiFuKangYDKDPrice[L"北京"].push_back({ 3, 0, 3, 4, 1.3 });
		//特殊区域
		g_weiFuKangYDKDPrice[L"新疆维吾尔自治区"].push_back({ 0, 0, 1, 16, 4 });
		g_weiFuKangYDKDPrice[L"西藏自治区"].push_back({ 0, 0, 1, 9, 7 });
		g_weiFuKangYDKDPrice[L"宁夏回族自治区"].push_back({ 0, 0, 1, 7, 5 });
		g_weiFuKangYDKDPrice[L"青海省"].push_back({ 0, 0, 1, 7, 5 });
		g_weiFuKangYDKDPrice[L"海南省"].push_back({ 0, 0, 1, 7, 5 });
		g_weiFuKangYDKDPrice[L"内蒙古自治区"].push_back({ 0, 0, 1, 8, 6 });
		g_weiFuKangYDKDPrice[L"甘肃省"].push_back({ 0, 0, 1, 6, 5 });
	}
	{
		g_weiFuKangZTKYPrice[L"安徽省"].push_back({ 0, 0, 20,  27,	1.3 });
		g_weiFuKangZTKYPrice[L"北京"].push_back({ 0, 0, 20,  27, 1.3 });
		g_weiFuKangZTKYPrice[L"福建省"].push_back({ 0, 0, 20,  27,	1.3 });
		g_weiFuKangZTKYPrice[L"甘肃省"].push_back({ 0, 0, 20,  37,	1.8 });
		g_weiFuKangZTKYPrice[L"广东省"].push_back({ 0, 0, 20,  27,	1.3 });
		g_weiFuKangZTKYPrice[L"广西壮族自治区"].push_back({ 0, 0, 20,  27,	1.3 });
		g_weiFuKangZTKYPrice[L"贵州省"].push_back({ 0, 0, 20,  27,	1.3 });
		g_weiFuKangZTKYPrice[L"海南省"].push_back({ 0, 0, 20,  44,	2.2 });
		g_weiFuKangZTKYPrice[L"河北省"].push_back({ 0, 0, 20,  27,	1.3 });
		g_weiFuKangZTKYPrice[L"河南省"].push_back({ 0, 0, 20,  27,	1.3 });
		g_weiFuKangZTKYPrice[L"黑龙江省"].push_back({ 0, 0, 20,  39, 1.7 });
		g_weiFuKangZTKYPrice[L"湖北省"].push_back({ 0, 0, 20,  27, 1.3 });
		g_weiFuKangZTKYPrice[L"湖南省"].push_back({ 0, 0, 20,  27, 1.3 });
		g_weiFuKangZTKYPrice[L"吉林省"].push_back({ 0, 0, 20,  39,	1.7 });
		g_weiFuKangZTKYPrice[L"江苏省"].push_back({ 0, 0, 20,  27,	1.3 });
		g_weiFuKangZTKYPrice[L"江西省"].push_back({ 0, 0, 20,  27,	1.3 });
		g_weiFuKangZTKYPrice[L"辽宁省"].push_back({ 0, 0, 20,  39,	1.7 });
		g_weiFuKangZTKYPrice[L"内蒙古自治区"].push_back({ 0, 0, 20,  44, 1.7 });
		g_weiFuKangZTKYPrice[L"宁夏回族自治区"].push_back({ 0, 0, 20,  44,	1.7 });
		g_weiFuKangZTKYPrice[L"青海省"].push_back({ 0, 0, 20,  44,	1.7 });
		g_weiFuKangZTKYPrice[L"山东省"].push_back({ 0, 0, 20,  27,	1.3 });
		g_weiFuKangZTKYPrice[L"山西省"].push_back({ 0, 0, 20,  27,	1.3 });
		g_weiFuKangZTKYPrice[L"陕西省"].push_back({ 0, 0, 20,  27,	1.3 });
		g_weiFuKangZTKYPrice[L"上海"].push_back({ 0, 0, 20,  29, 1.3 });
		g_weiFuKangZTKYPrice[L"天津"].push_back({ 0, 0, 20,  29, 1.3 });
		g_weiFuKangZTKYPrice[L"西藏自治区"].push_back({ 0, 0, 20,  74, 3.2 });
		g_weiFuKangZTKYPrice[L"新疆维吾尔自治区"].push_back({ 0, 0, 20,  54, 3.2 });
		g_weiFuKangZTKYPrice[L"云南省"].push_back({ 0, 0, 20,  34,	1.3 });
		g_weiFuKangZTKYPrice[L"浙江省"].push_back({ 0, 0, 20,  27,	1.3 });
		g_weiFuKangZTKYPrice[L"四川省"].push_back({ 0, 0, 20,  23, 1.1 });
		g_weiFuKangZTKYPrice[L"阿坝藏族羌族自治州"].push_back({ 0, 0, 20,  54,	1.7 });
		g_weiFuKangZTKYPrice[L"甘孜藏族自治州"].push_back({ 0, 0, 20,  54,	1.7 });
		g_weiFuKangZTKYPrice[L"凉山彝族自治州"].push_back({ 0, 0, 20,  54,	1.7 });
		g_weiFuKangZTKYPrice[L"泸州市"].push_back({ 0, 0, 20,  24,	1 });
		g_weiFuKangZTKYPrice[L"眉山市"].push_back({ 0, 0, 20,  24,	1 });
		g_weiFuKangZTKYPrice[L"绵阳市"].push_back({ 0, 0, 20,  24,	1 });
		g_weiFuKangZTKYPrice[L"南充市"].push_back({ 0, 0, 20,  24,	1 });
		g_weiFuKangZTKYPrice[L"内江市"].push_back({ 0, 0, 20,  24,	1 });
		g_weiFuKangZTKYPrice[L"攀枝花市"].push_back({ 0, 0, 20,  24, 1.2 });
		g_weiFuKangZTKYPrice[L"遂宁市"].push_back({ 0, 0, 20,  24,	1 });
		g_weiFuKangZTKYPrice[L"雅安市"].push_back({ 0, 0, 20,  24,	1 });
		g_weiFuKangZTKYPrice[L"宜宾市"].push_back({ 0, 0, 20,  24,	1 });
		g_weiFuKangZTKYPrice[L"资阳市"].push_back({ 0, 0, 20,  24,	1 });
		g_weiFuKangZTKYPrice[L"自贡市"].push_back({ 0, 0, 20,  24,	1 });
		g_weiFuKangZTKYPrice[L"重庆"].push_back({ 0, 0, 20,  27, 1.2 });
	}
		
	//新马帮中通快运
	{
		g_xinMaBangZTKYPrice[L"上海"].push_back({ 0, 0, 20,  27, 1.3 });
		g_xinMaBangZTKYPrice[L"北京"].push_back({ 0, 0, 20,  27, 1.3 });
		g_xinMaBangZTKYPrice[L"河南省"].push_back({ 0, 0, 20,  27, 1.3 });
		g_xinMaBangZTKYPrice[L"江苏省"].push_back({ 0, 0, 20,  27, 1.3 });
		g_xinMaBangZTKYPrice[L"浙江省"].push_back({ 0, 0, 20,  27, 1.3 });
		g_xinMaBangZTKYPrice[L"安徽省"].push_back({ 0, 0, 20,  27, 1.3 });
		g_xinMaBangZTKYPrice[L"山东省"].push_back({ 0, 0, 20,  27, 1.3 });
		g_xinMaBangZTKYPrice[L"天津"].push_back({ 0, 0, 20,  27, 1.3 });
		g_xinMaBangZTKYPrice[L"河北省"].push_back({ 0, 0, 20,  27, 1.3 });
		g_xinMaBangZTKYPrice[L"湖南省"].push_back({ 0, 0, 20,  27, 1.3 });
		g_xinMaBangZTKYPrice[L"湖北省"].push_back({ 0, 0, 20,  27, 1.3 });
		g_xinMaBangZTKYPrice[L"山西省"].push_back({ 0, 0, 20,  27, 1.3 });
		g_xinMaBangZTKYPrice[L"陕西省"].push_back({ 0, 0, 20,  27, 1.3 });
		g_xinMaBangZTKYPrice[L"江西省"].push_back({ 0, 0, 20,  27, 1.3 });
		g_xinMaBangZTKYPrice[L"广东省"].push_back({ 0, 0, 20,  27, 1.3 });
		g_xinMaBangZTKYPrice[L"福建省"].push_back({ 0, 0, 20,  27, 1.3 });
		g_xinMaBangZTKYPrice[L"广西壮族自治区"].push_back({ 0, 0, 20,  27, 1.3 });
		g_xinMaBangZTKYPrice[L"四川省"].push_back({ 0, 0, 20,  23, 1.1 });
		g_xinMaBangZTKYPrice[L"甘孜藏族自治州"].push_back({ 0, 0, 20,  52, 1.5 });
		g_xinMaBangZTKYPrice[L"阿坝藏族羌族自治州"].push_back({ 0, 0, 20,  52, 1.5 });
		g_xinMaBangZTKYPrice[L"凉山彝族自治州"].push_back({ 0, 0, 20,  52, 1.5 });
		g_xinMaBangZTKYPrice[L"重庆"].push_back({ 0, 0, 20,  27, 1.2 });
		g_xinMaBangZTKYPrice[L"云南省"].push_back({ 0, 0, 20,  27, 1.4 });
		g_xinMaBangZTKYPrice[L"贵州省"].push_back({ 0, 0, 20,  27, 1.4 });
		g_xinMaBangZTKYPrice[L"甘肃省"].push_back({ 0, 0, 20,  35, 3 });
		g_xinMaBangZTKYPrice[L"宁夏回族自治区"].push_back({ 0, 0, 20,  45, 2.8 });
		g_xinMaBangZTKYPrice[L"青海省"].push_back({ 0, 0, 20,  45, 2.8 });
		g_xinMaBangZTKYPrice[L"黑龙江省"].push_back({ 0, 0, 20,  37, 1.6 });
		g_xinMaBangZTKYPrice[L"吉林省"].push_back({ 0, 0, 20,  37, 1.6 });
		g_xinMaBangZTKYPrice[L"辽宁省"].push_back({ 0, 0, 20,  37, 1.6 });
		g_xinMaBangZTKYPrice[L"内蒙古自治区"].push_back({ 0, 0, 20,  75, 3 });
		g_xinMaBangZTKYPrice[L"海南省"].push_back({ 0, 0, 20,  42, 2.7 });
		g_xinMaBangZTKYPrice[L"新疆维吾尔自治区"].push_back({ 0, 0, 20,  85, 3.2 });
		g_xinMaBangZTKYPrice[L"西藏自治区"].push_back({ 0, 0, 20,  75, 4.2 });
	}
	//颐麦科技中通快运
	{
		g_yiMaiKeJiZTKYPrice[L"四川省"].push_back({ 0, 0, 20,  25, 1.1 });
		g_yiMaiKeJiZTKYPrice[L"甘孜藏族自治州"].push_back({ 0, 0, 20,  25, 1.5 });
		g_yiMaiKeJiZTKYPrice[L"阿坝藏族羌族自治州"].push_back({ 0, 0, 20,  25, 1.5 });
		g_yiMaiKeJiZTKYPrice[L"凉山彝族自治州"].push_back({ 0, 0, 20,  25, 1.5 });
		g_yiMaiKeJiZTKYPrice[L"上海"].push_back({ 0, 0, 20,  28, 1.5 });
		g_yiMaiKeJiZTKYPrice[L"北京"].push_back({ 0, 0, 20,  28, 1.5 });
		g_yiMaiKeJiZTKYPrice[L"河南省"].push_back({ 0, 0, 20,  28, 1.5 });
		g_yiMaiKeJiZTKYPrice[L"江苏省"].push_back({ 0, 0, 20,  28, 1.5 });
		g_yiMaiKeJiZTKYPrice[L"浙江省"].push_back({ 0, 0, 20,  28, 1.5 });
		g_yiMaiKeJiZTKYPrice[L"安徽省"].push_back({ 0, 0, 20,  28, 1.5 });
		g_yiMaiKeJiZTKYPrice[L"山东省"].push_back({ 0, 0, 20,  28, 1.5 });
		g_yiMaiKeJiZTKYPrice[L"天津"].push_back({ 0, 0, 20,  28, 1.5 });
		g_yiMaiKeJiZTKYPrice[L"河北省"].push_back({ 0, 0, 20,  28, 1.5 });
		g_yiMaiKeJiZTKYPrice[L"湖南省"].push_back({ 0, 0, 20,  28, 1.5 });
		g_yiMaiKeJiZTKYPrice[L"湖北省"].push_back({ 0, 0, 20,  28, 1.5 });
		g_yiMaiKeJiZTKYPrice[L"山西省"].push_back({ 0, 0, 20,  28, 1.5 });
		g_yiMaiKeJiZTKYPrice[L"陕西省"].push_back({ 0, 0, 20,  28, 1.5 });
		g_yiMaiKeJiZTKYPrice[L"江西省"].push_back({ 0, 0, 20,  28, 1.5 });
		g_yiMaiKeJiZTKYPrice[L"广东省"].push_back({ 0, 0, 20,  28, 1.5 });
		g_yiMaiKeJiZTKYPrice[L"福建省"].push_back({ 0, 0, 20,  28, 1.5 });
		g_yiMaiKeJiZTKYPrice[L"广西壮族自治区"].push_back({ 0, 0, 20,  28, 1.5 });
		g_yiMaiKeJiZTKYPrice[L"重庆"].push_back({ 0, 0, 20,  28, 1.3 });
		g_yiMaiKeJiZTKYPrice[L"云南省"].push_back({ 0, 0, 20,  28, 1.5 });
		g_yiMaiKeJiZTKYPrice[L"贵州省"].push_back({ 0, 0, 20,  28, 1.5 });
		g_yiMaiKeJiZTKYPrice[L"甘肃省"].push_back({ 0, 0, 20,  28, 3 });
		g_yiMaiKeJiZTKYPrice[L"青海省"].push_back({ 0, 0, 20,  75, 3 });
		g_yiMaiKeJiZTKYPrice[L"黑龙江省"].push_back({ 0, 0, 20,  28, 1.8 });
		g_yiMaiKeJiZTKYPrice[L"吉林省"].push_back({ 0, 0, 20,  28, 1.8 });
		g_yiMaiKeJiZTKYPrice[L"辽宁省"].push_back({ 0, 0, 20,  28, 1.8 });
		g_yiMaiKeJiZTKYPrice[L"海南省"].push_back({ 0, 0, 20,  28, 3 });
		g_yiMaiKeJiZTKYPrice[L"新疆维吾尔自治区"].push_back({ 0, 0, 20,  85, 3.5 });
		g_yiMaiKeJiZTKYPrice[L"西藏自治区"].push_back({ 0, 0, 20,  65, 4.5 });
		g_yiMaiKeJiZTKYPrice[L"宁夏回族自治区"].push_back({ 0, 0, 20,  54, 3 });
		g_yiMaiKeJiZTKYPrice[L"内蒙古自治区"].push_back({ 0, 0, 20,  75, 3.5 });
	}
	//弥雅中通快运
	{
		g_miYaZTKYPrice[L"上海"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_miYaZTKYPrice[L"北京"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_miYaZTKYPrice[L"河南省"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_miYaZTKYPrice[L"江苏省"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_miYaZTKYPrice[L"浙江省"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_miYaZTKYPrice[L"安徽省"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_miYaZTKYPrice[L"山东省"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_miYaZTKYPrice[L"天津"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_miYaZTKYPrice[L"河北省"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_miYaZTKYPrice[L"湖南省"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_miYaZTKYPrice[L"湖北省"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_miYaZTKYPrice[L"山西省"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_miYaZTKYPrice[L"陕西省"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_miYaZTKYPrice[L"江西省"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_miYaZTKYPrice[L"广东省"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_miYaZTKYPrice[L"福建省"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_miYaZTKYPrice[L"广西壮族自治区"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_miYaZTKYPrice[L"四川省"].push_back({ 0, 0, 20,  22.5, 1 });
		g_miYaZTKYPrice[L"甘孜藏族自治州"].push_back({ 0, 0, 20,  50, 1.6 });
		g_miYaZTKYPrice[L"阿坝藏族羌族自治州"].push_back({ 0, 0, 20,  50, 1.6 });
		g_miYaZTKYPrice[L"凉山彝族自治州"].push_back({ 0, 0, 20,  50, 1.6 });
		g_miYaZTKYPrice[L"重庆"].push_back({ 0, 0, 20,  27.5, 1.2 });
		g_miYaZTKYPrice[L"云南省"].push_back({ 0, 0, 20,  32, 1.4 });
		g_miYaZTKYPrice[L"贵州省"].push_back({ 0, 0, 20,  27.5, 1.4 });
		g_miYaZTKYPrice[L"甘肃省"].push_back({ 0, 0, 20,  35, 3 });
		g_miYaZTKYPrice[L"宁夏回族自治区"].push_back({ 0, 0, 20,  42.5, 2.8 });
		g_miYaZTKYPrice[L"青海省"].push_back({ 0, 0, 20,  42.5, 2.8 });
		g_miYaZTKYPrice[L"黑龙江省"].push_back({ 0, 0, 20,  37, 1.7 });
		g_miYaZTKYPrice[L"吉林省"].push_back({ 0, 0, 20,  37, 1.7 });
		g_miYaZTKYPrice[L"辽宁省"].push_back({ 0, 0, 20,  37, 1.7 });
		g_miYaZTKYPrice[L"内蒙古自治区"].push_back({ 0, 0, 20,  72.5, 3 });
		g_miYaZTKYPrice[L"海南省"].push_back({ 0, 0, 20,  42, 2.7 });
		g_miYaZTKYPrice[L"新疆维吾尔自治区"].push_back({ 0, 0, 20,  82.5, 3.2 });
		g_miYaZTKYPrice[L"西藏自治区"].push_back({ 0, 0, 20,  72, 4.2 });
	}
	//七一酱园中通快运
	{

		g_qiYiJiangYuanZTKYPrice[L"上海"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_qiYiJiangYuanZTKYPrice[L"北京"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_qiYiJiangYuanZTKYPrice[L"河南省"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_qiYiJiangYuanZTKYPrice[L"江苏省"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_qiYiJiangYuanZTKYPrice[L"浙江省"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_qiYiJiangYuanZTKYPrice[L"安徽省"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_qiYiJiangYuanZTKYPrice[L"山东省"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_qiYiJiangYuanZTKYPrice[L"天津"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_qiYiJiangYuanZTKYPrice[L"河北省"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_qiYiJiangYuanZTKYPrice[L"湖南省"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_qiYiJiangYuanZTKYPrice[L"湖北省"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_qiYiJiangYuanZTKYPrice[L"山西省"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_qiYiJiangYuanZTKYPrice[L"陕西省"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_qiYiJiangYuanZTKYPrice[L"江西省"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_qiYiJiangYuanZTKYPrice[L"广东省"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_qiYiJiangYuanZTKYPrice[L"福建省"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_qiYiJiangYuanZTKYPrice[L"广西壮族自治区"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_qiYiJiangYuanZTKYPrice[L"四川省"].push_back({ 0, 0, 20,  22.5, 1 });
		g_qiYiJiangYuanZTKYPrice[L"甘孜藏族自治州"].push_back({ 0, 0, 20,  50, 1.6 });
		g_qiYiJiangYuanZTKYPrice[L"阿坝藏族羌族自治州"].push_back({ 0, 0, 20,  50, 1.6 });
		g_qiYiJiangYuanZTKYPrice[L"凉山彝族自治州"].push_back({ 0, 0, 20,  50, 1.6 });
		g_qiYiJiangYuanZTKYPrice[L"重庆"].push_back({ 0, 0, 20,  27.5, 1.2 });
		g_qiYiJiangYuanZTKYPrice[L"云南省"].push_back({ 0, 0, 20,  32, 1.4 });
		g_qiYiJiangYuanZTKYPrice[L"贵州省"].push_back({ 0, 0, 20,  27.5, 1.4 });
		g_qiYiJiangYuanZTKYPrice[L"甘肃省"].push_back({ 0, 0, 20,  35, 3 });
		g_qiYiJiangYuanZTKYPrice[L"宁夏回族自治区"].push_back({ 0, 0, 20,  42.5, 2.8 });
		g_qiYiJiangYuanZTKYPrice[L"青海省"].push_back({ 0, 0, 20,  42.5, 2.8 });
		g_qiYiJiangYuanZTKYPrice[L"黑龙江省"].push_back({ 0, 0, 20,  37, 1.7 });
		g_qiYiJiangYuanZTKYPrice[L"吉林省"].push_back({ 0, 0, 20,  37, 1.7 });
		g_qiYiJiangYuanZTKYPrice[L"辽宁省"].push_back({ 0, 0, 20,  37, 1.7 });
		g_qiYiJiangYuanZTKYPrice[L"内蒙古自治区"].push_back({ 0, 0, 20,  72.5, 3 });
		g_qiYiJiangYuanZTKYPrice[L"海南省"].push_back({ 0, 0, 20,  42, 2.7 });
		g_qiYiJiangYuanZTKYPrice[L"新疆维吾尔自治区"].push_back({ 0, 0, 20,  82.5, 3.2 });
		g_qiYiJiangYuanZTKYPrice[L"西藏自治区"].push_back({ 0, 0, 20,  72, 4.2 });
	}
	//至善电商中通快运
	{
		g_zhiShanZTKYPrice[L"上海"].push_back({ 0, 0, 20,  27, 1.3 });
		g_zhiShanZTKYPrice[L"北京"].push_back({ 0, 0, 20,  27, 1.3 });
		g_zhiShanZTKYPrice[L"河南省"].push_back({ 0, 0, 20,  27, 1.3 });
		g_zhiShanZTKYPrice[L"江苏省"].push_back({ 0, 0, 20,  27, 1.3 });
		g_zhiShanZTKYPrice[L"浙江省"].push_back({ 0, 0, 20,  27, 1.3 });
		g_zhiShanZTKYPrice[L"安徽省"].push_back({ 0, 0, 20,  27, 1.3 });
		g_zhiShanZTKYPrice[L"山东省"].push_back({ 0, 0, 20,  27, 1.3 });
		g_zhiShanZTKYPrice[L"天津"].push_back({ 0, 0, 20,  27, 1.3 });
		g_zhiShanZTKYPrice[L"河北省"].push_back({ 0, 0, 20,  27, 1.3 });
		g_zhiShanZTKYPrice[L"湖南省"].push_back({ 0, 0, 20,  27, 1.3 });
		g_zhiShanZTKYPrice[L"湖北省"].push_back({ 0, 0, 20,  27, 1.3 });
		g_zhiShanZTKYPrice[L"山西省"].push_back({ 0, 0, 20,  27, 1.3 });
		g_zhiShanZTKYPrice[L"陕西省"].push_back({ 0, 0, 20,  27, 1.3 });
		g_zhiShanZTKYPrice[L"江西省"].push_back({ 0, 0, 20,  27, 1.3 });
		g_zhiShanZTKYPrice[L"广东省"].push_back({ 0, 0, 20,  27, 1.3 });
		g_zhiShanZTKYPrice[L"福建省"].push_back({ 0, 0, 20,  27, 1.3 });
		g_zhiShanZTKYPrice[L"广西壮族自治区"].push_back({ 0, 0, 20,  27, 1.3 });
		g_zhiShanZTKYPrice[L"四川省"].push_back({ 0, 0, 20,  22, 1 });
		g_zhiShanZTKYPrice[L"甘孜藏族自治州"].push_back({ 0, 0, 20,  50, 1.6 });
		g_zhiShanZTKYPrice[L"阿坝藏族羌族自治州"].push_back({ 0, 0, 20,  50, 1.6 });
		g_zhiShanZTKYPrice[L"凉山彝族自治州"].push_back({ 0, 0, 20,  50, 1.6 });
		g_zhiShanZTKYPrice[L"重庆"].push_back({ 0, 0, 20,  27, 1.2 });
		g_zhiShanZTKYPrice[L"云南省"].push_back({ 0, 0, 20,  32, 1.4 });
		g_zhiShanZTKYPrice[L"贵州省"].push_back({ 0, 0, 20,  27, 1.4 });
		g_zhiShanZTKYPrice[L"甘肃省"].push_back({ 0, 0, 20,  35, 3 });
		g_zhiShanZTKYPrice[L"宁夏回族自治区"].push_back({ 0, 0, 20,  42, 2.8 });
		g_zhiShanZTKYPrice[L"青海省"].push_back({ 0, 0, 20,  42, 2.8 });
		g_zhiShanZTKYPrice[L"黑龙江省"].push_back({ 0, 0, 20,  37, 1.7 });
		g_zhiShanZTKYPrice[L"吉林省"].push_back({ 0, 0, 20,  37, 1.7 });
		g_zhiShanZTKYPrice[L"辽宁省"].push_back({ 0, 0, 20,  37, 1.7 });
		g_zhiShanZTKYPrice[L"内蒙古自治区"].push_back({ 0, 0, 20,  72, 3 });
		g_zhiShanZTKYPrice[L"海南省"].push_back({ 0, 0, 20,  42, 2.7 });
		g_zhiShanZTKYPrice[L"新疆维吾尔自治区"].push_back({ 0, 0, 20,  82, 3.2 });
		g_zhiShanZTKYPrice[L"西藏自治区"].push_back({ 0, 0, 20,  72, 4.2 });
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
	//颐麦科技顺丰
	{
		g_yiMaiKeJiSFPrice.resize(4);
		g_yiMaiKeJiSFPrice[0].push_back({ 0, 1, 1, 10, 0 });
		g_yiMaiKeJiSFPrice[0].push_back({ 1, 2, 2, 12.5, 0 });
		g_yiMaiKeJiSFPrice[0].push_back({ 2, 3, 3, 15, 0 });
		g_yiMaiKeJiSFPrice[0].push_back({ 3, 0, 1, 9, 4.2 });

		g_yiMaiKeJiSFPrice[1].push_back({ 0, 1, 1, 11, 0 });
		g_yiMaiKeJiSFPrice[1].push_back({ 1, 2, 2, 14, 0 });
		g_yiMaiKeJiSFPrice[1].push_back({ 2, 3, 3, 16, 0 });
		g_yiMaiKeJiSFPrice[1].push_back({ 3, 0, 1, 10, 4.5 });

		g_yiMaiKeJiSFPrice[2].push_back({ 0, 1, 1, 11, 0 });
		g_yiMaiKeJiSFPrice[2].push_back({ 1, 2, 2, 15, 0 });
		g_yiMaiKeJiSFPrice[2].push_back({ 2, 3, 3, 18.5, 0 });
		g_yiMaiKeJiSFPrice[2].push_back({ 3, 0, 1, 10, 5.5 });

		g_yiMaiKeJiSFPrice[3].push_back({ 0, 1, 1, 14, 0 });
		g_yiMaiKeJiSFPrice[3].push_back({ 1, 2, 2, 21.5, 0 });
		g_yiMaiKeJiSFPrice[3].push_back({ 2, 3, 3, 30, 0 });
		g_yiMaiKeJiSFPrice[3].push_back({ 3, 0, 1, 13, 9.5 });
	}
	//旅收纳顺丰
	{
		g_quLvShouNaSFPrice.resize(4);
		g_quLvShouNaSFPrice[0].push_back({ 0, 1, 1, 10, 0 });
		g_quLvShouNaSFPrice[0].push_back({ 1, 2, 2, 12.5, 0 });
		g_quLvShouNaSFPrice[0].push_back({ 2, 3, 3, 15, 0 });
		g_quLvShouNaSFPrice[0].push_back({ 3, 0, 1, 9, 4.2 });

		g_quLvShouNaSFPrice[1].push_back({ 0, 1, 1, 11, 0 });
		g_quLvShouNaSFPrice[1].push_back({ 1, 2, 2, 14, 0 });
		g_quLvShouNaSFPrice[1].push_back({ 2, 3, 3, 16, 0 });
		g_quLvShouNaSFPrice[1].push_back({ 3, 0, 1, 10, 4.5 });

		g_quLvShouNaSFPrice[2].push_back({ 0, 1, 1, 11, 0 });
		g_quLvShouNaSFPrice[2].push_back({ 1, 2, 2, 15, 0 });
		g_quLvShouNaSFPrice[2].push_back({ 2, 3, 3, 18.5, 0 });
		g_quLvShouNaSFPrice[2].push_back({ 3, 0, 1, 10, 5.5 });

		g_quLvShouNaSFPrice[3].push_back({ 0, 1, 1, 14, 0 });
		g_quLvShouNaSFPrice[3].push_back({ 1, 2, 2, 21.5, 0 });
		g_quLvShouNaSFPrice[3].push_back({ 2, 3, 3, 30, 0 });
		g_quLvShouNaSFPrice[3].push_back({ 3, 0, 1, 13, 9.5 });
	}
	//至善电商顺丰
	{
		g_zhiShanSFPrice.resize(4);
		g_zhiShanSFPrice[0].push_back({ 0, 1, 1, 10, 0 });
		g_zhiShanSFPrice[0].push_back({ 1, 2, 2, 12.5, 0 });
		g_zhiShanSFPrice[0].push_back({ 2, 3, 3, 15, 0 });
		g_zhiShanSFPrice[0].push_back({ 3, 0, 1, 9, 4.2 });

		g_zhiShanSFPrice[1].push_back({ 0, 1, 1, 11, 0 });
		g_zhiShanSFPrice[1].push_back({ 1, 2, 2, 14, 0 });
		g_zhiShanSFPrice[1].push_back({ 2, 3, 3, 16, 0 });
		g_zhiShanSFPrice[1].push_back({ 3, 0, 1, 10, 4.5 });

		g_zhiShanSFPrice[2].push_back({ 0, 1, 1, 11, 0 });
		g_zhiShanSFPrice[2].push_back({ 1, 2, 2, 15, 0 });
		g_zhiShanSFPrice[2].push_back({ 2, 3, 3, 18.5, 0 });
		g_zhiShanSFPrice[2].push_back({ 3, 0, 1, 10, 5.5 });

		g_zhiShanSFPrice[3].push_back({ 0, 1, 1, 14, 0 });
		g_zhiShanSFPrice[3].push_back({ 1, 2, 2, 21.5, 0 });
		g_zhiShanSFPrice[3].push_back({ 2, 3, 3, 30, 0 });
		g_zhiShanSFPrice[3].push_back({ 3, 0, 1, 13, 9.5 });
		
	}
	//硕果流香顺丰
	{
		g_shuoGuoLiuXiangSFPrice.resize(4);
		g_shuoGuoLiuXiangSFPrice[0].push_back({ 0, 1, 1, 10, 0 });
		g_shuoGuoLiuXiangSFPrice[0].push_back({ 1, 2, 2, 12.5, 0 });
		g_shuoGuoLiuXiangSFPrice[0].push_back({ 2, 3, 3, 15, 0 });
		g_shuoGuoLiuXiangSFPrice[0].push_back({ 3, 0, 1, 9, 4.2 });

		g_shuoGuoLiuXiangSFPrice[1].push_back({ 0, 1, 1, 11, 0 });
		g_shuoGuoLiuXiangSFPrice[1].push_back({ 1, 2, 2, 14, 0 });
		g_shuoGuoLiuXiangSFPrice[1].push_back({ 2, 3, 3, 16, 0 });
		g_shuoGuoLiuXiangSFPrice[1].push_back({ 3, 0, 1, 10, 4.5 });

		g_shuoGuoLiuXiangSFPrice[2].push_back({ 0, 1, 1, 11, 0 });
		g_shuoGuoLiuXiangSFPrice[2].push_back({ 1, 2, 2, 15, 0 });
		g_shuoGuoLiuXiangSFPrice[2].push_back({ 2, 3, 3, 18.5, 0 });
		g_shuoGuoLiuXiangSFPrice[2].push_back({ 3, 0, 1, 10, 5.5 });

		g_shuoGuoLiuXiangSFPrice[3].push_back({ 0, 1, 1, 14, 0 });
		g_shuoGuoLiuXiangSFPrice[3].push_back({ 1, 2, 2, 21.5, 0 });
		g_shuoGuoLiuXiangSFPrice[3].push_back({ 2, 3, 3, 30, 0 });
		g_shuoGuoLiuXiangSFPrice[3].push_back({ 3, 0, 1, 13, 9.5 });
	}
	//静心阁韵达快递
	{
		//1公斤
		g_jingXinGeYDKDPrice[L"河南省"].push_back({ 0, 1, 1, 2, 0 });
		g_jingXinGeYDKDPrice[L"江苏省"].push_back({ 0, 1, 1, 2, 0 });
		g_jingXinGeYDKDPrice[L"浙江省"].push_back({ 0, 1, 1, 2, 0 });
		g_jingXinGeYDKDPrice[L"安徽省"].push_back({ 0, 1, 1, 2, 0 });
		g_jingXinGeYDKDPrice[L"山东省"].push_back({ 0, 1, 1, 2, 0 });
		g_jingXinGeYDKDPrice[L"天津"].push_back({ 0, 1, 1, 2, 0 });
		g_jingXinGeYDKDPrice[L"河北省"].push_back({ 0, 1, 1, 2, 0 });
		g_jingXinGeYDKDPrice[L"湖南省"].push_back({ 0, 1, 1, 2, 0 });
		g_jingXinGeYDKDPrice[L"湖北省"].push_back({ 0, 1, 1, 2, 0 });
		g_jingXinGeYDKDPrice[L"山西省"].push_back({ 0, 1, 1, 2, 0 });
		g_jingXinGeYDKDPrice[L"陕西省"].push_back({ 0, 1, 1, 2, 0 });
		g_jingXinGeYDKDPrice[L"江西省"].push_back({ 0, 1, 1, 2, 0 });
		g_jingXinGeYDKDPrice[L"广东省"].push_back({ 0, 1, 1, 2, 0 });
		g_jingXinGeYDKDPrice[L"福建省"].push_back({ 0, 1, 1, 2, 0 });
		g_jingXinGeYDKDPrice[L"广西壮族自治区"].push_back({ 0, 1, 1, 2, 0 });
		g_jingXinGeYDKDPrice[L"云南省"].push_back({ 0, 1, 1, 2, 0 });
		g_jingXinGeYDKDPrice[L"贵州省"].push_back({ 0, 1, 1, 2, 0 });
		
		g_jingXinGeYDKDPrice[L"四川省"].push_back({ 0, 1, 1, 2, 0 });
		g_jingXinGeYDKDPrice[L"重庆"].push_back({ 0, 1, 1, 2, 0 });

		g_jingXinGeYDKDPrice[L"黑龙江省"].push_back({ 0, 1, 1, 2, 0 });
		g_jingXinGeYDKDPrice[L"吉林省"].push_back({ 0, 1, 1, 2, 0 });
		g_jingXinGeYDKDPrice[L"辽宁省"].push_back({ 0, 1, 1, 2, 0 });

		g_jingXinGeYDKDPrice[L"深圳市"].push_back({ 0, 1, 1, 2.9, 0 });
		g_jingXinGeYDKDPrice[L"上海"].push_back({ 0, 1, 1, 2.9, 0 });
		g_jingXinGeYDKDPrice[L"北京"].push_back({ 0, 1, 1, 2.9, 0 });
		//2公斤
		g_jingXinGeYDKDPrice[L"河南省"].push_back({ 1, 2, 2, 2.3, 0 });
		g_jingXinGeYDKDPrice[L"江苏省"].push_back({ 1, 2, 2, 2.3, 0 });
		g_jingXinGeYDKDPrice[L"浙江省"].push_back({ 1, 2, 2, 2.3, 0 });
		g_jingXinGeYDKDPrice[L"安徽省"].push_back({ 1, 2, 2, 2.3, 0 });
		g_jingXinGeYDKDPrice[L"山东省"].push_back({ 1, 2, 2, 2.3, 0 });
		g_jingXinGeYDKDPrice[L"天津"].push_back({ 1, 2, 2, 2.3, 0 });
		g_jingXinGeYDKDPrice[L"河北省"].push_back({ 1, 2, 2, 2.3, 0 });
		g_jingXinGeYDKDPrice[L"湖南省"].push_back({ 1, 2, 2, 2.3, 0 });
		g_jingXinGeYDKDPrice[L"湖北省"].push_back({ 1, 2, 2, 2.3, 0 });
		g_jingXinGeYDKDPrice[L"山西省"].push_back({ 1, 2, 2, 2.3, 0 });
		g_jingXinGeYDKDPrice[L"陕西省"].push_back({ 1, 2, 2, 2.3, 0 });
		g_jingXinGeYDKDPrice[L"江西省"].push_back({ 1, 2, 2, 2.3, 0 });
		g_jingXinGeYDKDPrice[L"广东省"].push_back({ 1, 2, 2, 2.3, 0 });
		g_jingXinGeYDKDPrice[L"福建省"].push_back({ 1, 2, 2, 2.3, 0 });
		g_jingXinGeYDKDPrice[L"广西壮族自治区"].push_back({ 1, 2, 2, 2.3, 0 });
		g_jingXinGeYDKDPrice[L"云南省"].push_back({ 1, 2, 2, 2.3, 0 });
		g_jingXinGeYDKDPrice[L"贵州省"].push_back({ 1, 2, 2, 2.3, 0 });

		g_jingXinGeYDKDPrice[L"四川省"].push_back({ 1, 2, 2, 2.3, 0 });
		g_jingXinGeYDKDPrice[L"重庆"].push_back({ 1, 2, 2, 2.3, 0 });

		g_jingXinGeYDKDPrice[L"黑龙江省"].push_back({ 1, 2, 2, 2.4, 0 });
		g_jingXinGeYDKDPrice[L"吉林省"].push_back({ 1, 2, 2, 2.4, 0 });
		g_jingXinGeYDKDPrice[L"辽宁省"].push_back({ 1, 2, 2, 2.4, 0 });

		g_jingXinGeYDKDPrice[L"深圳市"].push_back({ 1, 2, 2, 3.2, 0 });
		g_jingXinGeYDKDPrice[L"上海"].push_back({ 1, 2, 2, 3.2, 0 });
		g_jingXinGeYDKDPrice[L"北京"].push_back({ 1, 2, 2, 3.2, 0 });
		//3公斤
		g_jingXinGeYDKDPrice[L"河南省"].push_back({ 2, 3, 3, 2.7, 0 });
		g_jingXinGeYDKDPrice[L"江苏省"].push_back({ 2, 3, 3, 2.7, 0 });
		g_jingXinGeYDKDPrice[L"浙江省"].push_back({ 2, 3, 3, 2.7, 0 });
		g_jingXinGeYDKDPrice[L"安徽省"].push_back({ 2, 3, 3, 2.7, 0 });
		g_jingXinGeYDKDPrice[L"山东省"].push_back({ 2, 3, 3, 2.7, 0 });
		g_jingXinGeYDKDPrice[L"天津"].push_back({ 2, 3, 3, 2.7, 0 });
		g_jingXinGeYDKDPrice[L"河北省"].push_back({ 2, 3, 3, 2.7, 0 });
		g_jingXinGeYDKDPrice[L"湖南省"].push_back({ 2, 3, 3, 2.7, 0 });
		g_jingXinGeYDKDPrice[L"湖北省"].push_back({ 2, 3, 3, 2.7, 0 });
		g_jingXinGeYDKDPrice[L"山西省"].push_back({ 2, 3, 3, 2.7, 0 });
		g_jingXinGeYDKDPrice[L"陕西省"].push_back({ 2, 3, 3, 2.7, 0 });
		g_jingXinGeYDKDPrice[L"江西省"].push_back({ 2, 3, 3, 2.7, 0 });
		g_jingXinGeYDKDPrice[L"广东省"].push_back({ 2, 3, 3, 2.7, 0 });
		g_jingXinGeYDKDPrice[L"福建省"].push_back({ 2, 3, 3, 2.7, 0 });
		g_jingXinGeYDKDPrice[L"广西壮族自治区"].push_back({ 2, 3, 3, 2.7, 0 });
		g_jingXinGeYDKDPrice[L"云南省"].push_back({ 2, 3, 3, 2.7, 0 });
		g_jingXinGeYDKDPrice[L"贵州省"].push_back({ 2, 3, 3, 2.7, 0 });

		g_jingXinGeYDKDPrice[L"四川省"].push_back({ 2, 3, 3, 2.7, 0 });
		g_jingXinGeYDKDPrice[L"重庆"].push_back({ 2, 3, 3, 2.7, 0 });

		g_jingXinGeYDKDPrice[L"黑龙江省"].push_back({ 2, 3, 3, 2.8, 0 });
		g_jingXinGeYDKDPrice[L"吉林省"].push_back({ 2, 3, 3, 2.8, 0 });
		g_jingXinGeYDKDPrice[L"辽宁省"].push_back({ 2, 3, 3, 2.8, 0 });

		g_jingXinGeYDKDPrice[L"深圳市"].push_back({ 2, 3, 3, 3.6, 0 });
		g_jingXinGeYDKDPrice[L"上海"].push_back({ 2, 3, 3, 3.6, 0 });
		g_jingXinGeYDKDPrice[L"北京"].push_back({ 2, 3, 3, 3.6, 0 });
		//3-5公斤
		g_jingXinGeYDKDPrice[L"河南省"].push_back({ 3, 5, 5, 4.1, 0 });
		g_jingXinGeYDKDPrice[L"江苏省"].push_back({ 3, 5, 5, 4.1, 0 });
		g_jingXinGeYDKDPrice[L"浙江省"].push_back({ 3, 5, 5, 4.1, 0 });
		g_jingXinGeYDKDPrice[L"安徽省"].push_back({ 3, 5, 5, 4.1, 0 });
		g_jingXinGeYDKDPrice[L"山东省"].push_back({ 3, 5, 5, 4.1, 0 });
		g_jingXinGeYDKDPrice[L"天津"].push_back({ 3, 5, 5, 4.1, 0 });
		g_jingXinGeYDKDPrice[L"河北省"].push_back({ 3, 5, 5, 4.1, 0 });
		g_jingXinGeYDKDPrice[L"湖南省"].push_back({ 3, 5, 5, 4.1, 0 });
		g_jingXinGeYDKDPrice[L"湖北省"].push_back({ 3, 5, 5, 4.1, 0 });
		g_jingXinGeYDKDPrice[L"山西省"].push_back({ 3, 5, 5, 4.1, 0 });
		g_jingXinGeYDKDPrice[L"陕西省"].push_back({ 3, 5, 5, 4.1, 0 });
		g_jingXinGeYDKDPrice[L"江西省"].push_back({ 3, 5, 5, 4.1, 0 });
		g_jingXinGeYDKDPrice[L"广东省"].push_back({ 3, 5, 5, 4.1, 0 });
		g_jingXinGeYDKDPrice[L"福建省"].push_back({ 3, 5, 5, 4.1, 0 });
		g_jingXinGeYDKDPrice[L"广西壮族自治区"].push_back({ 3, 5, 5, 4.1, 0 });
		g_jingXinGeYDKDPrice[L"云南省"].push_back({ 3, 5, 5, 4.1, 0 });
		g_jingXinGeYDKDPrice[L"贵州省"].push_back({ 3, 5, 5, 4.1, 0 });

		g_jingXinGeYDKDPrice[L"四川省"].push_back({ 3, 5, 5, 4.1, 0 });
		g_jingXinGeYDKDPrice[L"重庆"].push_back({ 3, 5, 5, 4.1, 0 });

		g_jingXinGeYDKDPrice[L"黑龙江省"].push_back({ 3, 5, 5, 4.2, 0 });
		g_jingXinGeYDKDPrice[L"吉林省"].push_back({ 3, 5, 5, 4.2, 0 });
		g_jingXinGeYDKDPrice[L"辽宁省"].push_back({ 3, 5, 5, 4.2, 0 });

		g_jingXinGeYDKDPrice[L"深圳市"].push_back({ 3, 5, 5, 5.9, 0 });
		g_jingXinGeYDKDPrice[L"上海"].push_back({ 3, 5, 5, 5.9, 0 });
		g_jingXinGeYDKDPrice[L"北京"].push_back({ 3, 5, 5, 5.9, 0 });
		//5公斤以上
		g_jingXinGeYDKDPrice[L"河南省"].push_back({ 5, 0, 1, 3.8, 1.2 });
		g_jingXinGeYDKDPrice[L"江苏省"].push_back({ 5, 0, 1, 3.8, 1.2 });
		g_jingXinGeYDKDPrice[L"浙江省"].push_back({ 5, 0, 1, 3.8, 1.2 });
		g_jingXinGeYDKDPrice[L"安徽省"].push_back({ 5, 0, 1, 3.8, 1.2 });
		g_jingXinGeYDKDPrice[L"山东省"].push_back({ 5, 0, 1, 3.8, 1.2 });
		g_jingXinGeYDKDPrice[L"天津"].push_back({ 5, 0, 1, 3.8, 1.2 });
		g_jingXinGeYDKDPrice[L"河北省"].push_back({ 5, 0, 1, 3.8, 1.2 });
		g_jingXinGeYDKDPrice[L"湖南省"].push_back({ 5, 0, 1, 3.8, 1.2 });
		g_jingXinGeYDKDPrice[L"湖北省"].push_back({ 5, 0, 1, 3.8, 1.2 });
		g_jingXinGeYDKDPrice[L"山西省"].push_back({ 5, 0, 1, 3.8, 1.2 });
		g_jingXinGeYDKDPrice[L"陕西省"].push_back({ 5, 0, 1, 3.8, 1.2 });
		g_jingXinGeYDKDPrice[L"江西省"].push_back({ 5, 0, 1, 3.8, 1.2 });
		g_jingXinGeYDKDPrice[L"广东省"].push_back({ 5, 0, 1, 3.8, 1.2 });
		g_jingXinGeYDKDPrice[L"福建省"].push_back({ 5, 0, 1, 3.8, 1.2 });
		g_jingXinGeYDKDPrice[L"广西壮族自治区"].push_back({ 5, 0, 1, 3.8, 1.2 });
		g_jingXinGeYDKDPrice[L"云南省"].push_back({ 5, 0, 1, 3.8, 1.2 });
		g_jingXinGeYDKDPrice[L"贵州省"].push_back({ 5, 0, 1, 3.8, 1.2 });

		g_jingXinGeYDKDPrice[L"四川省"].push_back({ 5, 0, 1, 3.8, 0.8 });
		g_jingXinGeYDKDPrice[L"重庆"].push_back({ 5, 0, 1, 3.8, 0.8 });

		g_jingXinGeYDKDPrice[L"黑龙江省"].push_back({ 5, 0, 1, 5.1, 2.5 });
		g_jingXinGeYDKDPrice[L"吉林省"].push_back({ 5, 0, 1, 5.1, 2.5 });
		g_jingXinGeYDKDPrice[L"辽宁省"].push_back({ 5, 0, 1, 5.1, 2.5 });

		g_jingXinGeYDKDPrice[L"深圳市"].push_back({ 5, 0, 1, 3.8, 1.2 });
		g_jingXinGeYDKDPrice[L"上海"].push_back({ 5, 0, 1, 3.8, 1.2 });
		g_jingXinGeYDKDPrice[L"北京"].push_back({ 5, 0, 1, 3.8, 1.2 });
		//特殊区域
		g_jingXinGeYDKDPrice[L"新疆维吾尔自治区"].push_back({ 0, 0, 1, 16, 4 });
		g_jingXinGeYDKDPrice[L"西藏自治区"].push_back({ 0, 0, 1, 9, 7 });
		g_jingXinGeYDKDPrice[L"宁夏回族自治区"].push_back({ 0, 0, 1, 7, 5 });
		g_jingXinGeYDKDPrice[L"青海省"].push_back({ 0, 0, 1, 7, 5 });
		g_jingXinGeYDKDPrice[L"海南省"].push_back({ 0, 0, 1, 7, 5 });
		g_jingXinGeYDKDPrice[L"内蒙古自治区"].push_back({ 0, 0, 1, 8, 6 });
		g_jingXinGeYDKDPrice[L"甘肃省"].push_back({ 0, 0, 1, 6, 5 });
	}
	//趣旅快递
	{
		//3kg
		g_quLvShouNaKDPrice[L"河南省"].push_back({ 0, 3, 3, 3, 0 });
		g_quLvShouNaKDPrice[L"江苏省"].push_back({ 0, 3, 3, 3, 0 });
		g_quLvShouNaKDPrice[L"浙江省"].push_back({ 0, 3, 3, 3, 0 });
		g_quLvShouNaKDPrice[L"安徽省"].push_back({ 0, 3, 3, 3, 0 });
		g_quLvShouNaKDPrice[L"山东省"].push_back({ 0, 3, 3, 3, 0 });
		g_quLvShouNaKDPrice[L"天津"].push_back({ 0, 3, 3, 3, 0 });
		g_quLvShouNaKDPrice[L"河北省"].push_back({ 0, 3, 3, 3, 0 });
		g_quLvShouNaKDPrice[L"湖南省"].push_back({ 0, 3, 3, 3, 0 });
		g_quLvShouNaKDPrice[L"湖北省"].push_back({ 0, 3, 3, 3, 0 });
		g_quLvShouNaKDPrice[L"山西省"].push_back({ 0, 3, 3, 3, 0 });
		g_quLvShouNaKDPrice[L"陕西省"].push_back({ 0, 3, 3, 3, 0 });
		g_quLvShouNaKDPrice[L"江西省"].push_back({ 0, 3, 3, 3, 0 });
		g_quLvShouNaKDPrice[L"广东省"].push_back({ 0, 3, 3, 3, 0 });
		g_quLvShouNaKDPrice[L"福建省"].push_back({ 0, 3, 3, 3, 0 });
		g_quLvShouNaKDPrice[L"广西壮族自治区"].push_back({ 0, 3, 3, 3, 0 });
		g_quLvShouNaKDPrice[L"云南省"].push_back({ 0, 3, 3, 3, 0 });
		g_quLvShouNaKDPrice[L"贵州省"].push_back({ 0, 3, 3, 3, 0 });

		g_quLvShouNaKDPrice[L"四川省"].push_back({ 0, 3, 3, 3, 0 });
		g_quLvShouNaKDPrice[L"重庆"].push_back({ 0, 3, 3, 3, 0 });

		g_quLvShouNaKDPrice[L"黑龙江省"].push_back({ 0, 3, 3, 3, 0 });
		g_quLvShouNaKDPrice[L"吉林省"].push_back({ 0, 3, 3, 3, 0 });
		g_quLvShouNaKDPrice[L"辽宁省"].push_back({ 0, 3, 3, 3, 0 });

		g_quLvShouNaKDPrice[L"深圳市"].push_back({ 0, 3, 3, 4, 0 });
		g_quLvShouNaKDPrice[L"上海"].push_back({ 0, 3, 3, 4, 0 });
		g_quLvShouNaKDPrice[L"北京"].push_back({ 0, 3, 3, 4, 0 });
		//3kg以上
		g_quLvShouNaKDPrice[L"河南省"].push_back({ 3, 0, 1, 3.8, 1.2 });
		g_quLvShouNaKDPrice[L"江苏省"].push_back({ 3, 0, 1, 3.8, 1.2 });
		g_quLvShouNaKDPrice[L"浙江省"].push_back({ 3, 0, 1, 3.8, 1.2 });
		g_quLvShouNaKDPrice[L"安徽省"].push_back({ 3, 0, 1, 3.8, 1.2 });
		g_quLvShouNaKDPrice[L"山东省"].push_back({ 3, 0, 1, 3.8, 1.2 });
		g_quLvShouNaKDPrice[L"天津"].push_back({ 3, 0, 1, 3.8, 1.2 });
		g_quLvShouNaKDPrice[L"河北省"].push_back({ 3, 0, 1, 3.8, 1.2 });
		g_quLvShouNaKDPrice[L"湖南省"].push_back({ 3, 0, 1, 3.8, 1.2 });
		g_quLvShouNaKDPrice[L"湖北省"].push_back({ 3, 0, 1, 3.8, 1.2 });
		g_quLvShouNaKDPrice[L"山西省"].push_back({ 3, 0, 1, 3.8, 1.2 });
		g_quLvShouNaKDPrice[L"陕西省"].push_back({ 3, 0, 1, 3.8, 1.2 });
		g_quLvShouNaKDPrice[L"江西省"].push_back({ 3, 0, 1, 3.8, 1.2 });
		g_quLvShouNaKDPrice[L"广东省"].push_back({ 3, 0, 1, 3.8, 1.2 });
		g_quLvShouNaKDPrice[L"福建省"].push_back({ 3, 0, 1, 3.8, 1.2 });
		g_quLvShouNaKDPrice[L"广西壮族自治区"].push_back({ 3, 0, 1, 3.8, 1.2 });
		g_quLvShouNaKDPrice[L"云南省"].push_back({ 3, 0, 1, 3.8, 1.2 });
		g_quLvShouNaKDPrice[L"贵州省"].push_back({ 3, 0, 1, 3.8, 1.2 });

		g_quLvShouNaKDPrice[L"四川省"].push_back({ 3, 0, 1, 3.5, 0.9 });
		g_quLvShouNaKDPrice[L"重庆"].push_back({ 3, 0, 1, 3.5, 0.9 });

		g_quLvShouNaKDPrice[L"黑龙江省"].push_back({ 3, 0, 1, 5.1, 2.5 });
		g_quLvShouNaKDPrice[L"吉林省"].push_back({ 3, 0, 1, 5.1, 2.5 });
		g_quLvShouNaKDPrice[L"辽宁省"].push_back({ 3, 0, 1, 5.1, 2.5 });

		g_quLvShouNaKDPrice[L"深圳市"].push_back({ 3, 0, 1, 3.8, 1.2 });
		g_quLvShouNaKDPrice[L"上海"].push_back({ 3, 0, 1, 3.8, 1.2 });
		g_quLvShouNaKDPrice[L"北京"].push_back({ 3, 0, 1, 3.8, 1.2 });
		//特殊区域
		g_quLvShouNaKDPrice[L"新疆维吾尔自治区"].push_back({ 0, 0, 1, 16, 4 });
		g_quLvShouNaKDPrice[L"西藏自治区"].push_back({ 0, 0, 1, 9, 7 });
		g_quLvShouNaKDPrice[L"宁夏回族自治区"].push_back({ 0, 0, 1, 7, 5 });
		g_quLvShouNaKDPrice[L"青海省"].push_back({ 0, 0, 1, 7, 5 });
		g_quLvShouNaKDPrice[L"海南省"].push_back({ 0, 0, 1, 7, 5 });
		g_quLvShouNaKDPrice[L"内蒙古自治区"].push_back({ 0, 0, 1, 8, 6 });
		g_quLvShouNaKDPrice[L"甘肃省"].push_back({ 0, 0, 1, 6, 5 });
	}
	//硕果流香
	{
		//3kg
		g_shuoGuoLiuXiangKDPrice[L"河南省"].push_back({ 0, 3, 3, 2.9, 0 });
		g_shuoGuoLiuXiangKDPrice[L"江苏省"].push_back({ 0, 3, 3, 2.9, 0 });
		g_shuoGuoLiuXiangKDPrice[L"浙江省"].push_back({ 0, 3, 3, 2.9, 0 });
		g_shuoGuoLiuXiangKDPrice[L"安徽省"].push_back({ 0, 3, 3, 2.9, 0 });
		g_shuoGuoLiuXiangKDPrice[L"山东省"].push_back({ 0, 3, 3, 2.9, 0 });
		g_shuoGuoLiuXiangKDPrice[L"天津"].push_back({ 0, 3, 3, 2.9, 0 });
		g_shuoGuoLiuXiangKDPrice[L"河北省"].push_back({ 0, 3, 3, 2.9, 0 });
		g_shuoGuoLiuXiangKDPrice[L"湖南省"].push_back({ 0, 3, 3, 2.9, 0 });
		g_shuoGuoLiuXiangKDPrice[L"湖北省"].push_back({ 0, 3, 3, 2.9, 0 });
		g_shuoGuoLiuXiangKDPrice[L"山西省"].push_back({ 0, 3, 3, 2.9, 0 });
		g_shuoGuoLiuXiangKDPrice[L"陕西省"].push_back({ 0, 3, 3, 2.9, 0 });
		g_shuoGuoLiuXiangKDPrice[L"江西省"].push_back({ 0, 3, 3, 2.9, 0 });
		g_shuoGuoLiuXiangKDPrice[L"广东省"].push_back({ 0, 3, 3, 2.9, 0 });
		g_shuoGuoLiuXiangKDPrice[L"福建省"].push_back({ 0, 3, 3, 2.9, 0 });
		g_shuoGuoLiuXiangKDPrice[L"广西壮族自治区"].push_back({ 0, 3, 3, 2.9, 0 });
		g_shuoGuoLiuXiangKDPrice[L"云南省"].push_back({ 0, 3, 3, 2.9, 0 });
		g_shuoGuoLiuXiangKDPrice[L"贵州省"].push_back({ 0, 3, 3, 2.9, 0 });

		g_shuoGuoLiuXiangKDPrice[L"四川省"].push_back({ 0, 3, 3, 2.9, 0 });
		g_shuoGuoLiuXiangKDPrice[L"重庆"].push_back({ 0, 3, 3, 2.9, 0 });

		g_shuoGuoLiuXiangKDPrice[L"黑龙江省"].push_back({ 0, 3, 3, 4.4, 0 });
		g_shuoGuoLiuXiangKDPrice[L"吉林省"].push_back({ 0, 3, 3, 4.4, 0 });
		g_shuoGuoLiuXiangKDPrice[L"辽宁省"].push_back({ 0, 3, 3, 4.4, 0 });

		g_shuoGuoLiuXiangKDPrice[L"深圳市"].push_back({ 0, 3, 3, 2.9, 0 });
		g_shuoGuoLiuXiangKDPrice[L"上海"].push_back({ 0, 3, 3, 2.9, 0 });
		g_shuoGuoLiuXiangKDPrice[L"北京"].push_back({ 0, 3, 3, 2.9, 0 });
		//3kg以上
		g_shuoGuoLiuXiangKDPrice[L"河南省"].push_back({ 3, 0, 3, 3, 1.3 });
		g_shuoGuoLiuXiangKDPrice[L"江苏省"].push_back({ 3, 0, 3, 3, 1.3 });
		g_shuoGuoLiuXiangKDPrice[L"浙江省"].push_back({ 3, 0, 3, 3, 1.3 });
		g_shuoGuoLiuXiangKDPrice[L"安徽省"].push_back({ 3, 0, 3, 3, 1.3 });
		g_shuoGuoLiuXiangKDPrice[L"山东省"].push_back({ 3, 0, 3, 3, 1.3 });
		g_shuoGuoLiuXiangKDPrice[L"天津"].push_back({ 3, 0, 3, 3, 1.3 });
		g_shuoGuoLiuXiangKDPrice[L"河北省"].push_back({ 3, 0, 3, 3, 1.3 });
		g_shuoGuoLiuXiangKDPrice[L"湖南省"].push_back({ 3, 0, 3, 3, 1.3 });
		g_shuoGuoLiuXiangKDPrice[L"湖北省"].push_back({ 3, 0, 3, 3, 1.3 });
		g_shuoGuoLiuXiangKDPrice[L"山西省"].push_back({ 3, 0, 3, 3, 1.3 });
		g_shuoGuoLiuXiangKDPrice[L"陕西省"].push_back({ 3, 0, 3, 3, 1.3 });
		g_shuoGuoLiuXiangKDPrice[L"江西省"].push_back({ 3, 0, 3, 3, 1.3 });
		g_shuoGuoLiuXiangKDPrice[L"广东省"].push_back({ 3, 0, 3, 3, 1.3 });
		g_shuoGuoLiuXiangKDPrice[L"福建省"].push_back({ 3, 0, 3, 3, 1.3 });
		g_shuoGuoLiuXiangKDPrice[L"广西壮族自治区"].push_back({ 3, 0, 3, 3, 1.3 });
		g_shuoGuoLiuXiangKDPrice[L"云南省"].push_back({ 3, 0, 3, 3, 1.3 });
		g_shuoGuoLiuXiangKDPrice[L"贵州省"].push_back({ 3, 0, 3, 3, 1.3 });

		g_shuoGuoLiuXiangKDPrice[L"四川省"].push_back({ 3, 0, 3, 3, 1 });
		g_shuoGuoLiuXiangKDPrice[L"重庆"].push_back({ 3, 0, 3, 3, 1.3 });

		g_shuoGuoLiuXiangKDPrice[L"黑龙江省"].push_back({ 3, 0, 1, 5, 2 });
		g_shuoGuoLiuXiangKDPrice[L"吉林省"].push_back({ 3, 0, 1, 5, 2 });
		g_shuoGuoLiuXiangKDPrice[L"辽宁省"].push_back({ 3, 0, 1, 5, 2 });

		g_shuoGuoLiuXiangKDPrice[L"深圳市"].push_back({ 3, 0, 3, 3, 1.3 });
		g_shuoGuoLiuXiangKDPrice[L"上海"].push_back({ 3, 0, 3, 3, 1.3 });
		g_shuoGuoLiuXiangKDPrice[L"北京"].push_back({ 3, 0, 3, 3, 1.3 });
		//特殊区域
		g_shuoGuoLiuXiangKDPrice[L"新疆维吾尔自治区"].push_back({ 0, 0, 1, 16, 4 });
		g_shuoGuoLiuXiangKDPrice[L"西藏自治区"].push_back({ 0, 0, 1, 9, 7 });
		g_shuoGuoLiuXiangKDPrice[L"宁夏回族自治区"].push_back({ 0, 0, 1, 7, 5 });
		g_shuoGuoLiuXiangKDPrice[L"青海省"].push_back({ 0, 0, 1, 7, 5 });
		g_shuoGuoLiuXiangKDPrice[L"海南省"].push_back({ 0, 0, 1, 7, 5 });
		g_shuoGuoLiuXiangKDPrice[L"内蒙古自治区"].push_back({ 0, 0, 1, 8, 6 });
		g_shuoGuoLiuXiangKDPrice[L"甘肃省"].push_back({ 0, 0, 1, 6, 5 });
	}
	//星星少女
	{
		//2kg
		g_xingXingShaoNvKDPrice[L"河南省"].push_back({ 0, 2, 2, 2.6, 0 });
		g_xingXingShaoNvKDPrice[L"江苏省"].push_back({ 0, 2, 2, 2.6, 0 });
		g_xingXingShaoNvKDPrice[L"浙江省"].push_back({ 0, 2, 2, 2.6, 0 });
		g_xingXingShaoNvKDPrice[L"安徽省"].push_back({ 0, 2, 2, 2.6, 0 });
		g_xingXingShaoNvKDPrice[L"山东省"].push_back({ 0, 2, 2, 2.6, 0 });
		g_xingXingShaoNvKDPrice[L"天津"].push_back({ 0, 2, 2, 2.6, 0 });
		g_xingXingShaoNvKDPrice[L"河北省"].push_back({ 0, 2, 2, 2.6, 0 });
		g_xingXingShaoNvKDPrice[L"湖南省"].push_back({ 0, 2, 2, 2.6, 0 });
		g_xingXingShaoNvKDPrice[L"湖北省"].push_back({ 0, 2, 2, 2.6, 0 });
		g_xingXingShaoNvKDPrice[L"山西省"].push_back({ 0, 2, 2, 2.6, 0 });
		g_xingXingShaoNvKDPrice[L"陕西省"].push_back({ 0, 2, 2, 2.6, 0 });
		g_xingXingShaoNvKDPrice[L"江西省"].push_back({ 0, 2, 2, 2.6, 0 });
		g_xingXingShaoNvKDPrice[L"广东省"].push_back({ 0, 2, 2, 2.6, 0 });
		g_xingXingShaoNvKDPrice[L"福建省"].push_back({ 0, 2, 2, 2.6, 0 });
		g_xingXingShaoNvKDPrice[L"广西壮族自治区"].push_back({ 0, 2, 2, 2.6, 0 });
		g_xingXingShaoNvKDPrice[L"云南省"].push_back({ 0, 2, 2, 2.6, 0 });
		g_xingXingShaoNvKDPrice[L"贵州省"].push_back({ 0, 2, 2, 2.6, 0 });

		g_xingXingShaoNvKDPrice[L"四川省"].push_back({ 0, 2, 2, 2.6, 0 });
		g_xingXingShaoNvKDPrice[L"重庆"].push_back({ 0, 2, 2, 2.6, 0 });

		g_xingXingShaoNvKDPrice[L"黑龙江省"].push_back({ 0, 2, 2, 2.6, 0 });
		g_xingXingShaoNvKDPrice[L"吉林省"].push_back({ 0, 2, 2, 2.6, 0 });
		g_xingXingShaoNvKDPrice[L"辽宁省"].push_back({ 0, 2, 2, 2.6, 0 });

		g_xingXingShaoNvKDPrice[L"深圳市"].push_back({ 0, 2, 2, 3.5, 0 });
		g_xingXingShaoNvKDPrice[L"上海"].push_back({ 0, 2, 2, 3.5, 0 });
		g_xingXingShaoNvKDPrice[L"北京"].push_back({ 0, 2, 2, 3.5, 0 });
		//3kg
		g_xingXingShaoNvKDPrice[L"河南省"].push_back({ 2, 3, 3, 2.9, 0 });
		g_xingXingShaoNvKDPrice[L"江苏省"].push_back({ 2, 3, 3, 2.9, 0 });
		g_xingXingShaoNvKDPrice[L"浙江省"].push_back({ 2, 3, 3, 2.9, 0 });
		g_xingXingShaoNvKDPrice[L"安徽省"].push_back({ 2, 3, 3, 2.9, 0 });
		g_xingXingShaoNvKDPrice[L"山东省"].push_back({ 2, 3, 3, 2.9, 0 });
		g_xingXingShaoNvKDPrice[L"天津"].push_back({ 2, 3, 3, 2.9, 0 });
		g_xingXingShaoNvKDPrice[L"河北省"].push_back({ 2, 3, 3, 2.9, 0 });
		g_xingXingShaoNvKDPrice[L"湖南省"].push_back({ 2, 3, 3, 2.9, 0 });
		g_xingXingShaoNvKDPrice[L"湖北省"].push_back({ 2, 3, 3, 2.9, 0 });
		g_xingXingShaoNvKDPrice[L"山西省"].push_back({ 2, 3, 3, 2.9, 0 });
		g_xingXingShaoNvKDPrice[L"陕西省"].push_back({ 2, 3, 3, 2.9, 0 });
		g_xingXingShaoNvKDPrice[L"江西省"].push_back({ 2, 3, 3, 2.9, 0 });
		g_xingXingShaoNvKDPrice[L"广东省"].push_back({ 2, 3, 3, 2.9, 0 });
		g_xingXingShaoNvKDPrice[L"福建省"].push_back({ 2, 3, 3, 2.9, 0 });
		g_xingXingShaoNvKDPrice[L"广西壮族自治区"].push_back({ 2, 3, 3, 2.9, 0 });
		g_xingXingShaoNvKDPrice[L"云南省"].push_back({ 2, 3, 3, 2.9, 0 });
		g_xingXingShaoNvKDPrice[L"贵州省"].push_back({ 2, 3, 3, 2.9, 0 });

		g_xingXingShaoNvKDPrice[L"四川省"].push_back({ 2, 3, 3, 2.9, 0 });
		g_xingXingShaoNvKDPrice[L"重庆"].push_back({ 2, 3, 3, 2.9, 0 });

		g_xingXingShaoNvKDPrice[L"黑龙江省"].push_back({ 2, 3, 3, 2.9, 0 });
		g_xingXingShaoNvKDPrice[L"吉林省"].push_back({ 2, 3, 3, 2.9, 0 });
		g_xingXingShaoNvKDPrice[L"辽宁省"].push_back({ 2, 3, 3, 2.9, 0 });

		g_xingXingShaoNvKDPrice[L"深圳市"].push_back({ 2, 3, 3, 3.8, 0 });
		g_xingXingShaoNvKDPrice[L"上海"].push_back({ 2, 3, 3, 3.8, 0 });
		g_xingXingShaoNvKDPrice[L"北京"].push_back({ 2, 3, 3, 3.8, 0 });
		//3kg以上
		g_xingXingShaoNvKDPrice[L"河南省"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_xingXingShaoNvKDPrice[L"江苏省"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_xingXingShaoNvKDPrice[L"浙江省"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_xingXingShaoNvKDPrice[L"安徽省"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_xingXingShaoNvKDPrice[L"山东省"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_xingXingShaoNvKDPrice[L"天津"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_xingXingShaoNvKDPrice[L"河北省"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_xingXingShaoNvKDPrice[L"湖南省"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_xingXingShaoNvKDPrice[L"湖北省"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_xingXingShaoNvKDPrice[L"山西省"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_xingXingShaoNvKDPrice[L"陕西省"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_xingXingShaoNvKDPrice[L"江西省"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_xingXingShaoNvKDPrice[L"广东省"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_xingXingShaoNvKDPrice[L"福建省"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_xingXingShaoNvKDPrice[L"广西壮族自治区"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_xingXingShaoNvKDPrice[L"云南省"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_xingXingShaoNvKDPrice[L"贵州省"].push_back({ 3, 0, 1, 3.6, 1.1 });

		g_xingXingShaoNvKDPrice[L"四川省"].push_back({ 3, 0, 1, 3.4, 0.9 });
		g_xingXingShaoNvKDPrice[L"重庆"].push_back({ 3, 0, 1, 3.4, 0.9 });

		g_xingXingShaoNvKDPrice[L"黑龙江省"].push_back({ 3, 0, 1, 5.1, 2.5 });
		g_xingXingShaoNvKDPrice[L"吉林省"].push_back({ 3, 0, 1, 5.1, 2.5 });
		g_xingXingShaoNvKDPrice[L"辽宁省"].push_back({ 3, 0, 1, 5.1, 2.5 });

		g_xingXingShaoNvKDPrice[L"深圳市"].push_back({ 3, 0, 1, 3.8, 1.2 });
		g_xingXingShaoNvKDPrice[L"上海"].push_back({ 3, 0, 1, 3.8, 1.2 });
		g_xingXingShaoNvKDPrice[L"北京"].push_back({ 3, 0, 1, 3.8, 1.2 });
		//特殊区域
		g_xingXingShaoNvKDPrice[L"新疆维吾尔自治区"].push_back({ 0, 0, 1, 16, 4 });
		g_xingXingShaoNvKDPrice[L"西藏自治区"].push_back({ 0, 0, 1, 9, 7 });
		g_xingXingShaoNvKDPrice[L"宁夏回族自治区"].push_back({ 0, 0, 1, 7, 5 });
		g_xingXingShaoNvKDPrice[L"青海省"].push_back({ 0, 0, 1, 7, 5 });
		g_xingXingShaoNvKDPrice[L"海南省"].push_back({ 0, 0, 1, 7, 5 });
		g_xingXingShaoNvKDPrice[L"内蒙古自治区"].push_back({ 0, 0, 1, 8, 6 });
		g_xingXingShaoNvKDPrice[L"甘肃省"].push_back({ 0, 0, 1, 6, 5 });\
	}
	//兔娘娘
	{
		//1kg
		g_tuNiangNiangKDPrice[L"河南省"].push_back({ 0, 1, 1, 2.4, 0 });
		g_tuNiangNiangKDPrice[L"江苏省"].push_back({ 0, 1, 1, 2.4, 0 });
		g_tuNiangNiangKDPrice[L"浙江省"].push_back({ 0, 1, 1, 2.4, 0 });
		g_tuNiangNiangKDPrice[L"安徽省"].push_back({ 0, 1, 1, 2.4, 0 });
		g_tuNiangNiangKDPrice[L"山东省"].push_back({ 0, 1, 1, 2.4, 0 });
		g_tuNiangNiangKDPrice[L"天津"].push_back({ 0, 1, 1, 2.4, 0 });
		g_tuNiangNiangKDPrice[L"河北省"].push_back({ 0, 1, 1, 2.4, 0 });
		g_tuNiangNiangKDPrice[L"湖南省"].push_back({ 0, 1, 1, 2.4, 0 });
		g_tuNiangNiangKDPrice[L"湖北省"].push_back({ 0, 1, 1, 2.4, 0 });
		g_tuNiangNiangKDPrice[L"山西省"].push_back({ 0, 1, 1, 2.4, 0 });
		g_tuNiangNiangKDPrice[L"陕西省"].push_back({ 0, 1, 1, 2.4, 0 });
		g_tuNiangNiangKDPrice[L"江西省"].push_back({ 0, 1, 1, 2.4, 0 });
		g_tuNiangNiangKDPrice[L"广东省"].push_back({ 0, 1, 1, 2.4, 0 });
		g_tuNiangNiangKDPrice[L"福建省"].push_back({ 0, 1, 1, 2.4, 0 });
		g_tuNiangNiangKDPrice[L"广西壮族自治区"].push_back({ 0, 1, 1, 2.4, 0 });
		g_tuNiangNiangKDPrice[L"云南省"].push_back({ 0, 1, 1, 2.4, 0 });
		g_tuNiangNiangKDPrice[L"贵州省"].push_back({ 0, 1, 1, 2.4, 0 });
		g_tuNiangNiangKDPrice[L"四川省"].push_back({ 0, 1, 1, 2.4, 0 });
		g_tuNiangNiangKDPrice[L"重庆"].push_back({ 0, 1, 1, 2.4, 0 });

		g_tuNiangNiangKDPrice[L"黑龙江省"].push_back({ 0, 1, 1, 2.4, 0 });
		g_tuNiangNiangKDPrice[L"吉林省"].push_back({ 0, 1, 1, 2.4, 0 });
		g_tuNiangNiangKDPrice[L"辽宁省"].push_back({ 0, 1, 1, 2.4, 0 });
		g_tuNiangNiangKDPrice[L"宁夏回族自治区"].push_back({ 0, 1, 1, 2.4, 0 });
		g_tuNiangNiangKDPrice[L"甘肃省"].push_back({ 0, 1, 1, 2.4, 0 }); 

		g_tuNiangNiangKDPrice[L"深圳市"].push_back({ 0, 1, 1, 3, 0 });
		g_tuNiangNiangKDPrice[L"上海"].push_back({ 0, 1, 1, 3, 0 });
		g_tuNiangNiangKDPrice[L"北京"].push_back({ 0, 1, 1, 3, 0 });
		g_tuNiangNiangKDPrice[L"青海省"].push_back({ 0, 1, 1, 3, 0 });
		//2kg
		g_tuNiangNiangKDPrice[L"河南省"].push_back({ 1, 2, 2, 2.6, 0 });
		g_tuNiangNiangKDPrice[L"江苏省"].push_back({ 1, 2, 2, 2.6, 0 });
		g_tuNiangNiangKDPrice[L"浙江省"].push_back({ 1, 2, 2, 2.6, 0 });
		g_tuNiangNiangKDPrice[L"安徽省"].push_back({ 1, 2, 2, 2.6, 0 });
		g_tuNiangNiangKDPrice[L"山东省"].push_back({ 1, 2, 2, 2.6, 0 });
		g_tuNiangNiangKDPrice[L"天津"].push_back({ 1, 2, 2, 2.6, 0 });
		g_tuNiangNiangKDPrice[L"河北省"].push_back({ 1, 2, 2, 2.6, 0 });
		g_tuNiangNiangKDPrice[L"湖南省"].push_back({ 1, 2, 2, 2.6, 0 });
		g_tuNiangNiangKDPrice[L"湖北省"].push_back({ 1, 2, 2, 2.6, 0 });
		g_tuNiangNiangKDPrice[L"山西省"].push_back({ 1, 2, 2, 2.6, 0 });
		g_tuNiangNiangKDPrice[L"陕西省"].push_back({ 1, 2, 2, 2.6, 0 });
		g_tuNiangNiangKDPrice[L"江西省"].push_back({ 1, 2, 2, 2.6, 0 });
		g_tuNiangNiangKDPrice[L"广东省"].push_back({ 1, 2, 2, 2.6, 0 });
		g_tuNiangNiangKDPrice[L"福建省"].push_back({ 1, 2, 2, 2.6, 0 });
		g_tuNiangNiangKDPrice[L"广西壮族自治区"].push_back({ 1, 2, 2, 2.6, 0 });
		g_tuNiangNiangKDPrice[L"云南省"].push_back({ 1, 2, 2, 2.6, 0 });
		g_tuNiangNiangKDPrice[L"贵州省"].push_back({ 1, 2, 2, 2.6, 0 });
		g_tuNiangNiangKDPrice[L"四川省"].push_back({ 1, 2, 2, 2.6, 0 });
		g_tuNiangNiangKDPrice[L"重庆"].push_back({ 1, 2, 2, 2.6, 0 });

		g_tuNiangNiangKDPrice[L"黑龙江省"].push_back({ 1, 2, 2, 2.6, 0 });
		g_tuNiangNiangKDPrice[L"吉林省"].push_back({ 1, 2, 2, 2.6, 0 });
		g_tuNiangNiangKDPrice[L"辽宁省"].push_back({ 1, 2, 2, 2.6, 0 });
		g_tuNiangNiangKDPrice[L"宁夏回族自治区"].push_back({ 1, 2, 2, 2.6, 0 });
		g_tuNiangNiangKDPrice[L"甘肃省"].push_back({ 1, 2, 2, 2.6, 0 });

		g_tuNiangNiangKDPrice[L"深圳市"].push_back({ 1, 2, 2, 3,4, 0 });
		g_tuNiangNiangKDPrice[L"上海"].push_back({ 1, 2, 2, 3,4, 0 });
		g_tuNiangNiangKDPrice[L"北京"].push_back({ 1, 2, 2, 3,4, 0 });
		g_tuNiangNiangKDPrice[L"青海省"].push_back({ 1, 2, 2, 3,4, 0 });
		//3kg
		g_tuNiangNiangKDPrice[L"河南省"].push_back({ 2, 3, 3, 2.9, 0 });
		g_tuNiangNiangKDPrice[L"江苏省"].push_back({ 2, 3, 3, 2.9, 0 });
		g_tuNiangNiangKDPrice[L"浙江省"].push_back({ 2, 3, 3, 2.9, 0 });
		g_tuNiangNiangKDPrice[L"安徽省"].push_back({ 2, 3, 3, 2.9, 0 });
		g_tuNiangNiangKDPrice[L"山东省"].push_back({ 2, 3, 3, 2.9, 0 });
		g_tuNiangNiangKDPrice[L"天津"].push_back({ 2, 3, 3, 2.9, 0 });
		g_tuNiangNiangKDPrice[L"河北省"].push_back({ 2, 3, 3, 2.9, 0 });
		g_tuNiangNiangKDPrice[L"湖南省"].push_back({ 2, 3, 3, 2.9, 0 });
		g_tuNiangNiangKDPrice[L"湖北省"].push_back({ 2, 3, 3, 2.9, 0 });
		g_tuNiangNiangKDPrice[L"山西省"].push_back({ 2, 3, 3, 2.9, 0 });
		g_tuNiangNiangKDPrice[L"陕西省"].push_back({ 2, 3, 3, 2.9, 0 });
		g_tuNiangNiangKDPrice[L"江西省"].push_back({ 2, 3, 3, 2.9, 0 });
		g_tuNiangNiangKDPrice[L"广东省"].push_back({ 2, 3, 3, 2.9, 0 });
		g_tuNiangNiangKDPrice[L"福建省"].push_back({ 2, 3, 3, 2.9, 0 });
		g_tuNiangNiangKDPrice[L"广西壮族自治区"].push_back({ 2, 3, 3, 2.9, 0 });
		g_tuNiangNiangKDPrice[L"云南省"].push_back({ 2, 3, 3, 2.9, 0 });
		g_tuNiangNiangKDPrice[L"贵州省"].push_back({ 2, 3, 3, 2.9, 0 });
		g_tuNiangNiangKDPrice[L"四川省"].push_back({ 2, 3, 3, 2.9, 0 });
		g_tuNiangNiangKDPrice[L"重庆"].push_back({ 2, 3, 3, 2.9, 0 });

		g_tuNiangNiangKDPrice[L"黑龙江省"].push_back({ 2, 3, 3, 2.9, 0 });
		g_tuNiangNiangKDPrice[L"吉林省"].push_back({ 2, 3, 3, 2.9, 0 });
		g_tuNiangNiangKDPrice[L"辽宁省"].push_back({ 2, 3, 3, 2.9, 0 });
		g_tuNiangNiangKDPrice[L"宁夏回族自治区"].push_back({ 2, 3, 3, 2.9, 0 });
		g_tuNiangNiangKDPrice[L"甘肃省"].push_back({ 2, 3, 3, 2.9, 0 });

		g_tuNiangNiangKDPrice[L"深圳市"].push_back({ 2, 3, 3, 3.8, 0 });
		g_tuNiangNiangKDPrice[L"上海"].push_back({ 2, 3, 3, 3.8, 0 });
		g_tuNiangNiangKDPrice[L"北京"].push_back({ 2, 3, 3, 3.8, 0 });
		g_tuNiangNiangKDPrice[L"青海省"].push_back({ 2, 3, 3, 3.8, 0 });
		//3kg以上
		g_tuNiangNiangKDPrice[L"河南省"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_tuNiangNiangKDPrice[L"江苏省"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_tuNiangNiangKDPrice[L"浙江省"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_tuNiangNiangKDPrice[L"安徽省"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_tuNiangNiangKDPrice[L"山东省"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_tuNiangNiangKDPrice[L"天津"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_tuNiangNiangKDPrice[L"河北省"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_tuNiangNiangKDPrice[L"湖南省"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_tuNiangNiangKDPrice[L"湖北省"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_tuNiangNiangKDPrice[L"山西省"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_tuNiangNiangKDPrice[L"陕西省"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_tuNiangNiangKDPrice[L"江西省"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_tuNiangNiangKDPrice[L"广东省"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_tuNiangNiangKDPrice[L"福建省"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_tuNiangNiangKDPrice[L"广西壮族自治区"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_tuNiangNiangKDPrice[L"云南省"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_tuNiangNiangKDPrice[L"贵州省"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_tuNiangNiangKDPrice[L"四川省"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_tuNiangNiangKDPrice[L"重庆"].push_back({ 3, 0, 1, 3.6, 1.1 });

		g_tuNiangNiangKDPrice[L"黑龙江省"].push_back({ 3, 0, 1, 5.1, 2.5 });
		g_tuNiangNiangKDPrice[L"吉林省"].push_back({ 3, 0, 1, 5.1, 2.5 });
		g_tuNiangNiangKDPrice[L"辽宁省"].push_back({ 3, 0, 1, 5.1, 2.5 });
		g_tuNiangNiangKDPrice[L"宁夏回族自治区"].push_back({ 3, 0, 1, 5.1, 2.5 });
		g_tuNiangNiangKDPrice[L"甘肃省"].push_back({ 3, 0, 1, 5.1, 2.5 });

		g_tuNiangNiangKDPrice[L"深圳市"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_tuNiangNiangKDPrice[L"上海"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_tuNiangNiangKDPrice[L"北京"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_tuNiangNiangKDPrice[L"青海省"].push_back({ 3, 0, 1, 5.1, 2.5 });
		//特殊区域
		g_tuNiangNiangKDPrice[L"新疆维吾尔自治区"].push_back({ 0, 0, 1, 16, 4 });
		g_tuNiangNiangKDPrice[L"西藏自治区"].push_back({ 0, 0, 1, 9, 7 });
		g_tuNiangNiangKDPrice[L"海南省"].push_back({ 0, 0, 1, 7, 5 });
		g_tuNiangNiangKDPrice[L"内蒙古自治区"].push_back({ 0, 0, 1, 8, 6 });
	}
	//初见柠檬茶
	{
		//3kg
		g_chuJianNingMengChaKDPrice[L"河南省"].push_back({ 0, 3, 3, 3, 0 });
		g_chuJianNingMengChaKDPrice[L"江苏省"].push_back({ 0, 3, 3, 3, 0 });
		g_chuJianNingMengChaKDPrice[L"浙江省"].push_back({ 0, 3, 3, 3, 0 });
		g_chuJianNingMengChaKDPrice[L"安徽省"].push_back({ 0, 3, 3, 3, 0 });
		g_chuJianNingMengChaKDPrice[L"山东省"].push_back({ 0, 3, 3, 3, 0 });
		g_chuJianNingMengChaKDPrice[L"天津"].push_back({ 0, 3, 3, 3, 0 });
		g_chuJianNingMengChaKDPrice[L"河北省"].push_back({ 0, 3, 3, 3, 0 });
		g_chuJianNingMengChaKDPrice[L"湖南省"].push_back({ 0, 3, 3, 3, 0 });
		g_chuJianNingMengChaKDPrice[L"湖北省"].push_back({ 0, 3, 3, 3, 0 });
		g_chuJianNingMengChaKDPrice[L"山西省"].push_back({ 0, 3, 3, 3, 0 });
		g_chuJianNingMengChaKDPrice[L"陕西省"].push_back({ 0, 3, 3, 3, 0 });
		g_chuJianNingMengChaKDPrice[L"江西省"].push_back({ 0, 3, 3, 3, 0 });
		g_chuJianNingMengChaKDPrice[L"广东省"].push_back({ 0, 3, 3, 3, 0 });
		g_chuJianNingMengChaKDPrice[L"福建省"].push_back({ 0, 3, 3, 3, 0 });
		g_chuJianNingMengChaKDPrice[L"广西壮族自治区"].push_back({ 0, 3, 3, 3, 0 });
		g_chuJianNingMengChaKDPrice[L"云南省"].push_back({ 0, 3, 3, 3, 0 });
		g_chuJianNingMengChaKDPrice[L"贵州省"].push_back({ 0, 3, 3, 3, 0 });

		g_chuJianNingMengChaKDPrice[L"四川省"].push_back({ 0, 3, 3, 3, 0 });
		g_chuJianNingMengChaKDPrice[L"重庆"].push_back({ 0, 3, 3, 3, 0 });

		g_chuJianNingMengChaKDPrice[L"黑龙江省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_chuJianNingMengChaKDPrice[L"吉林省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_chuJianNingMengChaKDPrice[L"辽宁省"].push_back({ 0, 3, 3, 3.5, 0 });

		g_chuJianNingMengChaKDPrice[L"深圳市"].push_back({ 0, 3, 3, 3.9, 0 });
		g_chuJianNingMengChaKDPrice[L"上海"].push_back({ 0, 3, 3, 3.9, 0 });
		g_chuJianNingMengChaKDPrice[L"北京"].push_back({ 0, 3, 3, 3.9, 0 });

		//3-5kg
		g_chuJianNingMengChaKDPrice[L"河南省"].push_back({ 3, 5, 5, 4.5, 0 });
		g_chuJianNingMengChaKDPrice[L"江苏省"].push_back({ 3, 5, 5, 4.5, 0 });
		g_chuJianNingMengChaKDPrice[L"浙江省"].push_back({ 3, 5, 5, 4.5, 0 });
		g_chuJianNingMengChaKDPrice[L"安徽省"].push_back({ 3, 5, 5, 4.5, 0 });
		g_chuJianNingMengChaKDPrice[L"山东省"].push_back({ 3, 5, 5, 4.5, 0 });
		g_chuJianNingMengChaKDPrice[L"天津"].push_back({ 3, 5, 5, 4.5, 0 });
		g_chuJianNingMengChaKDPrice[L"河北省"].push_back({ 3, 5, 5, 4.5, 0 });
		g_chuJianNingMengChaKDPrice[L"湖南省"].push_back({ 3, 5, 5, 4.5, 0 });
		g_chuJianNingMengChaKDPrice[L"湖北省"].push_back({ 3, 5, 5, 4.5, 0 });
		g_chuJianNingMengChaKDPrice[L"山西省"].push_back({ 3, 5, 5, 4.5, 0 });
		g_chuJianNingMengChaKDPrice[L"陕西省"].push_back({ 3, 5, 5, 4.5, 0 });
		g_chuJianNingMengChaKDPrice[L"江西省"].push_back({ 3, 5, 5, 4.5, 0 });
		g_chuJianNingMengChaKDPrice[L"广东省"].push_back({ 3, 5, 5, 4.5, 0 });
		g_chuJianNingMengChaKDPrice[L"福建省"].push_back({ 3, 5, 5, 4.5, 0 });
		g_chuJianNingMengChaKDPrice[L"广西壮族自治区"].push_back({ 3, 5, 5, 4.5, 0 });
		g_chuJianNingMengChaKDPrice[L"云南省"].push_back({ 3, 5, 5, 4.5, 0 });
		g_chuJianNingMengChaKDPrice[L"贵州省"].push_back({ 3, 5, 5, 4.5, 0 });

		g_chuJianNingMengChaKDPrice[L"四川省"].push_back({ 3, 5, 5, 4.5, 0 });
		g_chuJianNingMengChaKDPrice[L"重庆"].push_back({ 3, 5, 5, 4.5, 0 });

		g_chuJianNingMengChaKDPrice[L"黑龙江省"].push_back({ 3, 5, 5, 5, 0 });
		g_chuJianNingMengChaKDPrice[L"吉林省"].push_back({ 3, 5, 5, 5, 0 });
		g_chuJianNingMengChaKDPrice[L"辽宁省"].push_back({ 3, 5, 5, 5, 0 });

		g_chuJianNingMengChaKDPrice[L"深圳市"].push_back({ 3, 5, 5, 6.2, 0 });
		g_chuJianNingMengChaKDPrice[L"上海"].push_back({ 3, 5, 5, 6.2, 0 });
		g_chuJianNingMengChaKDPrice[L"北京"].push_back({ 3, 5, 5, 6.2, 0 });

		//5kg以上
		g_chuJianNingMengChaKDPrice[L"河南省"].push_back({ 5, 0, 1, 3.6, 1.2 });
		g_chuJianNingMengChaKDPrice[L"江苏省"].push_back({ 5, 0, 1, 3.6, 1.2 });
		g_chuJianNingMengChaKDPrice[L"浙江省"].push_back({ 5, 0, 1, 3.6, 1.2 });
		g_chuJianNingMengChaKDPrice[L"安徽省"].push_back({ 5, 0, 1, 3.6, 1.2 });
		g_chuJianNingMengChaKDPrice[L"山东省"].push_back({ 5, 0, 1, 3.6, 1.2 });
		g_chuJianNingMengChaKDPrice[L"天津"].push_back({ 5, 0, 1, 3.6, 1.2 });
		g_chuJianNingMengChaKDPrice[L"河北省"].push_back({ 5, 0, 1, 3.6, 1.2 });
		g_chuJianNingMengChaKDPrice[L"湖南省"].push_back({ 5, 0, 1, 3.6, 1.2 });
		g_chuJianNingMengChaKDPrice[L"湖北省"].push_back({ 5, 0, 1, 3.6, 1.2 });
		g_chuJianNingMengChaKDPrice[L"山西省"].push_back({ 5, 0, 1, 3.6, 1.2 });
		g_chuJianNingMengChaKDPrice[L"陕西省"].push_back({ 5, 0, 1, 3.6, 1.2 });
		g_chuJianNingMengChaKDPrice[L"江西省"].push_back({ 5, 0, 1, 3.6, 1.2 });
		g_chuJianNingMengChaKDPrice[L"广东省"].push_back({ 5, 0, 1, 3.6, 1.2 });
		g_chuJianNingMengChaKDPrice[L"福建省"].push_back({ 5, 0, 1, 3.6, 1.2 });
		g_chuJianNingMengChaKDPrice[L"广西壮族自治区"].push_back({ 5, 0, 1, 3.6, 1.2 });
		g_chuJianNingMengChaKDPrice[L"云南省"].push_back({ 5, 0, 1, 3.6, 1.2 });
		g_chuJianNingMengChaKDPrice[L"贵州省"].push_back({ 5, 0, 1, 3.6, 1.2 });

		g_chuJianNingMengChaKDPrice[L"四川省"].push_back({ 5, 0, 1, 3.6, 1.2 });
		g_chuJianNingMengChaKDPrice[L"重庆"].push_back({ 5, 0, 1, 3.6, 1.2 });

		g_chuJianNingMengChaKDPrice[L"黑龙江省"].push_back({ 5, 0, 1, 5.2, 2.6 });
		g_chuJianNingMengChaKDPrice[L"吉林省"].push_back({ 5, 0, 1, 5.2, 2.6 });
		g_chuJianNingMengChaKDPrice[L"辽宁省"].push_back({ 5, 0, 1, 5.2, 2.6 });

		g_chuJianNingMengChaKDPrice[L"深圳市"].push_back({ 5, 0, 1, 3.6, 1.2 });
		g_chuJianNingMengChaKDPrice[L"上海"].push_back({ 5, 0, 1, 3.6, 1.2 });
		g_chuJianNingMengChaKDPrice[L"北京"].push_back({ 5, 0, 1, 3.6, 1.2 });
		//特殊区域
		g_chuJianNingMengChaKDPrice[L"新疆维吾尔自治区"].push_back({ 0, 0, 1, 16, 4 });
		g_chuJianNingMengChaKDPrice[L"西藏自治区"].push_back({ 0, 0, 1, 9, 7 });
		g_chuJianNingMengChaKDPrice[L"宁夏回族自治区"].push_back({ 0, 0, 1, 7, 5 });
		g_chuJianNingMengChaKDPrice[L"青海省"].push_back({ 0, 0, 1, 7, 5 });
		g_chuJianNingMengChaKDPrice[L"海南省"].push_back({ 0, 0, 1, 7, 5 });
		g_chuJianNingMengChaKDPrice[L"内蒙古自治区"].push_back({ 0, 0, 1, 8, 6 });
		g_chuJianNingMengChaKDPrice[L"甘肃省"].push_back({ 0, 0, 1, 6, 5 });
	}

	//卡多格
	{
		//1kg
		g_tuKaDuoGeKDPrice[L"河南省"].push_back({ 0, 1, 1, 2.1, 0 });
		g_tuKaDuoGeKDPrice[L"江苏省"].push_back({ 0, 1, 1, 2.1, 0 });
		g_tuKaDuoGeKDPrice[L"浙江省"].push_back({ 0, 1, 1, 2.1, 0 });
		g_tuKaDuoGeKDPrice[L"安徽省"].push_back({ 0, 1, 1, 2.1, 0 });
		g_tuKaDuoGeKDPrice[L"山东省"].push_back({ 0, 1, 1, 2.1, 0 });
		g_tuKaDuoGeKDPrice[L"天津"].push_back({ 0, 1, 1, 2.1, 0 });
		g_tuKaDuoGeKDPrice[L"河北省"].push_back({ 0, 1, 1, 2.1, 0 });
		g_tuKaDuoGeKDPrice[L"湖南省"].push_back({ 0, 1, 1, 2.1, 0 });
		g_tuKaDuoGeKDPrice[L"湖北省"].push_back({ 0, 1, 1, 2.1, 0 });
		g_tuKaDuoGeKDPrice[L"山西省"].push_back({ 0, 1, 1, 2.1, 0 });
		g_tuKaDuoGeKDPrice[L"陕西省"].push_back({ 0, 1, 1, 2.1, 0 });
		g_tuKaDuoGeKDPrice[L"江西省"].push_back({ 0, 1, 1, 2.1, 0 });
		g_tuKaDuoGeKDPrice[L"广东省"].push_back({ 0, 1, 1, 2.1, 0 });
		g_tuKaDuoGeKDPrice[L"福建省"].push_back({ 0, 1, 1, 2.1, 0 });
		g_tuKaDuoGeKDPrice[L"广西壮族自治区"].push_back({ 0, 1, 1, 2.1, 0 });
		g_tuKaDuoGeKDPrice[L"云南省"].push_back({ 0, 1, 1, 2.1, 0 });
		g_tuKaDuoGeKDPrice[L"贵州省"].push_back({ 0, 1, 1, 2.1, 0 });

		g_tuKaDuoGeKDPrice[L"四川省"].push_back({ 0, 1, 1, 2.1, 0 });
		g_tuKaDuoGeKDPrice[L"重庆"].push_back({ 0, 1, 1, 2.1, 0 });

		g_tuKaDuoGeKDPrice[L"黑龙江省"].push_back({ 0, 1, 1, 2.1, 0 });
		g_tuKaDuoGeKDPrice[L"吉林省"].push_back({ 0, 1, 1, 2.1, 0 });
		g_tuKaDuoGeKDPrice[L"辽宁省"].push_back({ 0, 1, 1, 2.1, 0 });

		g_tuKaDuoGeKDPrice[L"深圳市"].push_back({ 0, 1, 1, 2.9, 0 });
		g_tuKaDuoGeKDPrice[L"上海"].push_back({ 0, 1, 1, 2.9, 0 });
		g_tuKaDuoGeKDPrice[L"北京"].push_back({ 0, 1, 1, 2.9, 0 });
		//2kg
		g_tuKaDuoGeKDPrice[L"河南省"].push_back({ 1, 2, 2, 2.5, 0 });
		g_tuKaDuoGeKDPrice[L"江苏省"].push_back({ 1, 2, 2, 2.5, 0 });
		g_tuKaDuoGeKDPrice[L"浙江省"].push_back({ 1, 2, 2, 2.5, 0 });
		g_tuKaDuoGeKDPrice[L"安徽省"].push_back({ 1, 2, 2, 2.5, 0 });
		g_tuKaDuoGeKDPrice[L"山东省"].push_back({ 1, 2, 2, 2.5, 0 });
		g_tuKaDuoGeKDPrice[L"天津"].push_back({ 1, 2, 2, 2.5, 0 });
		g_tuKaDuoGeKDPrice[L"河北省"].push_back({ 1, 2, 2, 2.5, 0 });
		g_tuKaDuoGeKDPrice[L"湖南省"].push_back({ 1, 2, 2, 2.5, 0 });
		g_tuKaDuoGeKDPrice[L"湖北省"].push_back({ 1, 2, 2, 2.5, 0 });
		g_tuKaDuoGeKDPrice[L"山西省"].push_back({ 1, 2, 2, 2.5, 0 });
		g_tuKaDuoGeKDPrice[L"陕西省"].push_back({ 1, 2, 2, 2.5, 0 });
		g_tuKaDuoGeKDPrice[L"江西省"].push_back({ 1, 2, 2, 2.5, 0 });
		g_tuKaDuoGeKDPrice[L"广东省"].push_back({ 1, 2, 2, 2.5, 0 });
		g_tuKaDuoGeKDPrice[L"福建省"].push_back({ 1, 2, 2, 2.5, 0 });
		g_tuKaDuoGeKDPrice[L"广西壮族自治区"].push_back({ 1, 2, 2, 2.5, 0 });
		g_tuKaDuoGeKDPrice[L"云南省"].push_back({ 1, 2, 2, 2.5, 0 });
		g_tuKaDuoGeKDPrice[L"贵州省"].push_back({ 1, 2, 2, 2.5, 0 });

		g_tuKaDuoGeKDPrice[L"四川省"].push_back({ 1, 2, 2, 2.5, 0 });
		g_tuKaDuoGeKDPrice[L"重庆"].push_back({ 1, 2, 2, 2.5, 0 });

		g_tuKaDuoGeKDPrice[L"黑龙江省"].push_back({ 1, 2, 2, 2.5, 0 });
		g_tuKaDuoGeKDPrice[L"吉林省"].push_back({ 1, 2, 2, 2.5, 0 });
		g_tuKaDuoGeKDPrice[L"辽宁省"].push_back({ 1, 2, 2, 2.5, 0 });

		g_tuKaDuoGeKDPrice[L"深圳市"].push_back({ 1, 2, 2, 3.3, 0 });
		g_tuKaDuoGeKDPrice[L"上海"].push_back({ 1, 2, 2, 3.3, 0 });
		g_tuKaDuoGeKDPrice[L"北京"].push_back({ 1, 2, 2, 3.3, 0 });
		//3kg
		g_tuKaDuoGeKDPrice[L"河南省"].push_back({ 2, 3, 3, 2.8, 0 });
		g_tuKaDuoGeKDPrice[L"江苏省"].push_back({ 2, 3, 3, 2.8, 0 });
		g_tuKaDuoGeKDPrice[L"浙江省"].push_back({ 2, 3, 3, 2.8, 0 });
		g_tuKaDuoGeKDPrice[L"安徽省"].push_back({ 2, 3, 3, 2.8, 0 });
		g_tuKaDuoGeKDPrice[L"山东省"].push_back({ 2, 3, 3, 2.8, 0 });
		g_tuKaDuoGeKDPrice[L"天津"].push_back({ 2, 3, 3, 2.8, 0 });
		g_tuKaDuoGeKDPrice[L"河北省"].push_back({ 2, 3, 3, 2.8, 0 });
		g_tuKaDuoGeKDPrice[L"湖南省"].push_back({ 2, 3, 3, 2.8, 0 });
		g_tuKaDuoGeKDPrice[L"湖北省"].push_back({ 2, 3, 3, 2.8, 0 });
		g_tuKaDuoGeKDPrice[L"山西省"].push_back({ 2, 3, 3, 2.8, 0 });
		g_tuKaDuoGeKDPrice[L"陕西省"].push_back({ 2, 3, 3, 2.8, 0 });
		g_tuKaDuoGeKDPrice[L"江西省"].push_back({ 2, 3, 3, 2.8, 0 });
		g_tuKaDuoGeKDPrice[L"广东省"].push_back({ 2, 3, 3, 2.8, 0 });
		g_tuKaDuoGeKDPrice[L"福建省"].push_back({ 2, 3, 3, 2.8, 0 });
		g_tuKaDuoGeKDPrice[L"广西壮族自治区"].push_back({ 2, 3, 3, 2.8, 0 });
		g_tuKaDuoGeKDPrice[L"云南省"].push_back({ 2, 3, 3, 2.8, 0 });
		g_tuKaDuoGeKDPrice[L"贵州省"].push_back({ 2, 3, 3, 2.8, 0 });

		g_tuKaDuoGeKDPrice[L"四川省"].push_back({ 2, 3, 3, 2.8, 0 });
		g_tuKaDuoGeKDPrice[L"重庆"].push_back({ 2, 3, 3, 2.8, 0 });

		g_tuKaDuoGeKDPrice[L"黑龙江省"].push_back({ 2, 3, 3, 2.8, 0 });
		g_tuKaDuoGeKDPrice[L"吉林省"].push_back({ 2, 3, 3, 2.8, 0 });
		g_tuKaDuoGeKDPrice[L"辽宁省"].push_back({ 2, 3, 3, 2.8, 0 });

		g_tuKaDuoGeKDPrice[L"深圳市"].push_back({ 2, 3, 3, 3.6, 0 });
		g_tuKaDuoGeKDPrice[L"上海"].push_back({ 2, 3, 3, 3.6, 0 });
		g_tuKaDuoGeKDPrice[L"北京"].push_back({ 2, 3, 3, 3.6, 0 });

		//3-5kg
		g_tuKaDuoGeKDPrice[L"河南省"].push_back({ 3, 5, 5, 4.2, 0 });
		g_tuKaDuoGeKDPrice[L"江苏省"].push_back({ 3, 5, 5, 4.2, 0 });
		g_tuKaDuoGeKDPrice[L"浙江省"].push_back({ 3, 5, 5, 4.2, 0 });
		g_tuKaDuoGeKDPrice[L"安徽省"].push_back({ 3, 5, 5, 4.2, 0 });
		g_tuKaDuoGeKDPrice[L"山东省"].push_back({ 3, 5, 5, 4.2, 0 });
		g_tuKaDuoGeKDPrice[L"天津"].push_back({ 3, 5, 5, 4.2, 0 });
		g_tuKaDuoGeKDPrice[L"河北省"].push_back({ 3, 5, 5, 4.2, 0 });
		g_tuKaDuoGeKDPrice[L"湖南省"].push_back({ 3, 5, 5, 4.2, 0 });
		g_tuKaDuoGeKDPrice[L"湖北省"].push_back({ 3, 5, 5, 4.2, 0 });
		g_tuKaDuoGeKDPrice[L"山西省"].push_back({ 3, 5, 5, 4.2, 0 });
		g_tuKaDuoGeKDPrice[L"陕西省"].push_back({ 3, 5, 5, 4.2, 0 });
		g_tuKaDuoGeKDPrice[L"江西省"].push_back({ 3, 5, 5, 4.2, 0 });
		g_tuKaDuoGeKDPrice[L"广东省"].push_back({ 3, 5, 5, 4.2, 0 });
		g_tuKaDuoGeKDPrice[L"福建省"].push_back({ 3, 5, 5, 4.2, 0 });
		g_tuKaDuoGeKDPrice[L"广西壮族自治区"].push_back({ 3, 5, 5, 4.2, 0 });
		g_tuKaDuoGeKDPrice[L"云南省"].push_back({ 3, 5, 5, 4.2, 0 });
		g_tuKaDuoGeKDPrice[L"贵州省"].push_back({ 3, 5, 5, 4.2, 0 });

		g_tuKaDuoGeKDPrice[L"四川省"].push_back({ 3, 5, 5, 4.2, 0 });
		g_tuKaDuoGeKDPrice[L"重庆"].push_back({ 3, 5, 5, 4.2, 0 });

		g_tuKaDuoGeKDPrice[L"黑龙江省"].push_back({ 3, 5, 5, 4.2, 0 });
		g_tuKaDuoGeKDPrice[L"吉林省"].push_back({ 3, 5, 5, 4.2, 0 });
		g_tuKaDuoGeKDPrice[L"辽宁省"].push_back({ 3, 5, 5, 4.2, 0 });

		g_tuKaDuoGeKDPrice[L"深圳市"].push_back({ 3, 5, 5, 5.9, 0 });
		g_tuKaDuoGeKDPrice[L"上海"].push_back({ 3, 5, 5, 5.9, 0 });
		g_tuKaDuoGeKDPrice[L"北京"].push_back({ 3, 5, 5, 5.9, 0 });

		//5kg以上
		g_tuKaDuoGeKDPrice[L"河南省"].push_back({ 5, 0, 1, 3.6, 1.1 });
		g_tuKaDuoGeKDPrice[L"江苏省"].push_back({ 5, 0, 1, 3.6, 1.1 });
		g_tuKaDuoGeKDPrice[L"浙江省"].push_back({ 5, 0, 1, 3.6, 1.1 });
		g_tuKaDuoGeKDPrice[L"安徽省"].push_back({ 5, 0, 1, 3.6, 1.1 });
		g_tuKaDuoGeKDPrice[L"山东省"].push_back({ 5, 0, 1, 3.6, 1.1 });
		g_tuKaDuoGeKDPrice[L"天津"].push_back({ 5, 0, 1, 3.6, 1.1 });
		g_tuKaDuoGeKDPrice[L"河北省"].push_back({ 5, 0, 1, 3.6, 1.1 });
		g_tuKaDuoGeKDPrice[L"湖南省"].push_back({ 5, 0, 1, 3.6, 1.1 });
		g_tuKaDuoGeKDPrice[L"湖北省"].push_back({ 5, 0, 1, 3.6, 1.1 });
		g_tuKaDuoGeKDPrice[L"山西省"].push_back({ 5, 0, 1, 3.6, 1.1 });
		g_tuKaDuoGeKDPrice[L"陕西省"].push_back({ 5, 0, 1, 3.6, 1.1 });
		g_tuKaDuoGeKDPrice[L"江西省"].push_back({ 5, 0, 1, 3.6, 1.1 });
		g_tuKaDuoGeKDPrice[L"广东省"].push_back({ 5, 0, 1, 3.6, 1.1 });
		g_tuKaDuoGeKDPrice[L"福建省"].push_back({ 5, 0, 1, 3.6, 1.1 });
		g_tuKaDuoGeKDPrice[L"广西壮族自治区"].push_back({ 5, 0, 1, 3.6, 1.1 });
		g_tuKaDuoGeKDPrice[L"云南省"].push_back({ 5, 0, 1, 3.6, 1.1 });
		g_tuKaDuoGeKDPrice[L"贵州省"].push_back({ 5, 0, 1, 3.6, 1.1 });

		g_tuKaDuoGeKDPrice[L"四川省"].push_back({ 5, 0, 1, 3.6, 1.1 });
		g_tuKaDuoGeKDPrice[L"重庆"].push_back({ 5, 0, 1, 3.6, 1.1 });

		g_tuKaDuoGeKDPrice[L"黑龙江省"].push_back({ 5, 0, 1, 5, 2.5 });
		g_tuKaDuoGeKDPrice[L"吉林省"].push_back({ 5, 0, 1, 5, 2.5 });
		g_tuKaDuoGeKDPrice[L"辽宁省"].push_back({ 5, 0, 1, 5, 2.5 });

		g_tuKaDuoGeKDPrice[L"深圳市"].push_back({ 5, 0, 1, 3.6, 1.1 });
		g_tuKaDuoGeKDPrice[L"上海"].push_back({ 5, 0, 1, 3.6, 1.1 });
		g_tuKaDuoGeKDPrice[L"北京"].push_back({ 5, 0, 1, 3.6, 1.1 });
		//特殊区域
		g_tuKaDuoGeKDPrice[L"新疆维吾尔自治区"].push_back({ 0, 0, 1, 16, 4 });
		g_tuKaDuoGeKDPrice[L"西藏自治区"].push_back({ 0, 0, 1, 9, 7 });
		g_tuKaDuoGeKDPrice[L"宁夏回族自治区"].push_back({ 0, 0, 1, 7, 5 });
		g_tuKaDuoGeKDPrice[L"青海省"].push_back({ 0, 0, 1, 7, 5 });
		g_tuKaDuoGeKDPrice[L"海南省"].push_back({ 0, 0, 1, 7, 5 });
		g_tuKaDuoGeKDPrice[L"内蒙古自治区"].push_back({ 0, 0, 1, 8, 6 });
		g_tuKaDuoGeKDPrice[L"甘肃省"].push_back({ 0, 0, 1, 6, 5 });
	}
	//小白熊
	{
		//3kg
		g_xiaoBaiXiongKDPrice[L"河南省"].push_back({ 0, 3, 3, 2.9, 0 });
		g_xiaoBaiXiongKDPrice[L"江苏省"].push_back({ 0, 3, 3, 2.9, 0 });
		g_xiaoBaiXiongKDPrice[L"浙江省"].push_back({ 0, 3, 3, 2.9, 0 });
		g_xiaoBaiXiongKDPrice[L"安徽省"].push_back({ 0, 3, 3, 2.9, 0 });
		g_xiaoBaiXiongKDPrice[L"山东省"].push_back({ 0, 3, 3, 2.9, 0 });
		g_xiaoBaiXiongKDPrice[L"天津"].push_back({ 0, 3, 3, 2.9, 0 });
		g_xiaoBaiXiongKDPrice[L"河北省"].push_back({ 0, 3, 3, 2.9, 0 });
		g_xiaoBaiXiongKDPrice[L"湖南省"].push_back({ 0, 3, 3, 2.9, 0 });
		g_xiaoBaiXiongKDPrice[L"湖北省"].push_back({ 0, 3, 3, 2.9, 0 });
		g_xiaoBaiXiongKDPrice[L"山西省"].push_back({ 0, 3, 3, 2.9, 0 });
		g_xiaoBaiXiongKDPrice[L"陕西省"].push_back({ 0, 3, 3, 2.9, 0 });
		g_xiaoBaiXiongKDPrice[L"江西省"].push_back({ 0, 3, 3, 2.9, 0 });
		g_xiaoBaiXiongKDPrice[L"广东省"].push_back({ 0, 3, 3, 2.9, 0 });
		g_xiaoBaiXiongKDPrice[L"福建省"].push_back({ 0, 3, 3, 2.9, 0 });
		g_xiaoBaiXiongKDPrice[L"广西壮族自治区"].push_back({ 0, 3, 3, 2.9, 0 });
		g_xiaoBaiXiongKDPrice[L"云南省"].push_back({ 0, 3, 3, 2.9, 0 });
		g_xiaoBaiXiongKDPrice[L"贵州省"].push_back({ 0, 3, 3, 2.9, 0 });

		g_xiaoBaiXiongKDPrice[L"四川省"].push_back({ 0, 3, 3, 2.9, 0 });
		g_xiaoBaiXiongKDPrice[L"重庆"].push_back({ 0, 3, 3, 2.9, 0 });

		g_xiaoBaiXiongKDPrice[L"黑龙江省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xiaoBaiXiongKDPrice[L"吉林省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xiaoBaiXiongKDPrice[L"辽宁省"].push_back({ 0, 3, 3, 3.5, 0 });

		g_xiaoBaiXiongKDPrice[L"深圳市"].push_back({ 0, 3, 3, 3.9, 0 });
		g_xiaoBaiXiongKDPrice[L"上海"].push_back({ 0, 3, 3, 3.9, 0 });
		g_xiaoBaiXiongKDPrice[L"北京"].push_back({ 0, 3, 3, 3.9, 0 });

		//3kg以上
		g_xiaoBaiXiongKDPrice[L"河南省"].push_back({ 3, 0, 1, 3.6, 1.2 });
		g_xiaoBaiXiongKDPrice[L"江苏省"].push_back({ 3, 0, 1, 3.6, 1.2 });
		g_xiaoBaiXiongKDPrice[L"浙江省"].push_back({ 3, 0, 1, 3.6, 1.2 });
		g_xiaoBaiXiongKDPrice[L"安徽省"].push_back({ 3, 0, 1, 3.6, 1.2 });
		g_xiaoBaiXiongKDPrice[L"山东省"].push_back({ 3, 0, 1, 3.6, 1.2 });
		g_xiaoBaiXiongKDPrice[L"天津"].push_back({ 3, 0, 1, 3.6, 1.2 });
		g_xiaoBaiXiongKDPrice[L"河北省"].push_back({ 3, 0, 1, 3.6, 1.2 });
		g_xiaoBaiXiongKDPrice[L"湖南省"].push_back({ 3, 0, 1, 3.6, 1.2 });
		g_xiaoBaiXiongKDPrice[L"湖北省"].push_back({ 3, 0, 1, 3.6, 1.2 });
		g_xiaoBaiXiongKDPrice[L"山西省"].push_back({ 3, 0, 1, 3.6, 1.2 });
		g_xiaoBaiXiongKDPrice[L"陕西省"].push_back({ 3, 0, 1, 3.6, 1.2 });
		g_xiaoBaiXiongKDPrice[L"江西省"].push_back({ 3, 0, 1, 3.6, 1.2 });
		g_xiaoBaiXiongKDPrice[L"广东省"].push_back({ 3, 0, 1, 3.6, 1.2 });
		g_xiaoBaiXiongKDPrice[L"福建省"].push_back({ 3, 0, 1, 3.6, 1.2 });
		g_xiaoBaiXiongKDPrice[L"广西壮族自治区"].push_back({ 3, 0, 1, 3.6, 1.2 });
		g_xiaoBaiXiongKDPrice[L"云南省"].push_back({ 3, 0, 1, 3.6, 1.2 });
		g_xiaoBaiXiongKDPrice[L"贵州省"].push_back({ 3, 0, 1, 3.6, 1.2 });

		g_xiaoBaiXiongKDPrice[L"四川省"].push_back({ 3, 0, 1, 3.6, 1.2 });
		g_xiaoBaiXiongKDPrice[L"重庆"].push_back({ 3, 0, 1, 3.6, 1.2 });

		g_xiaoBaiXiongKDPrice[L"黑龙江省"].push_back({ 3, 0, 1, 5.2, 2.6 });
		g_xiaoBaiXiongKDPrice[L"吉林省"].push_back({ 3, 0, 1, 5.2, 2.6 });
		g_xiaoBaiXiongKDPrice[L"辽宁省"].push_back({ 3, 0, 1, 5.2, 2.6 });

		g_xiaoBaiXiongKDPrice[L"深圳市"].push_back({ 3, 0, 1, 3.6, 1.2 });
		g_xiaoBaiXiongKDPrice[L"上海"].push_back({ 3, 0, 1, 3.6, 1.2 });
		g_xiaoBaiXiongKDPrice[L"北京"].push_back({ 3, 0, 1, 3.6, 1.2 });
		//特殊区域
		g_xiaoBaiXiongKDPrice[L"新疆维吾尔自治区"].push_back({ 0, 0, 1, 16, 4 });
		g_xiaoBaiXiongKDPrice[L"西藏自治区"].push_back({ 0, 0, 1, 9, 7 });
		g_xiaoBaiXiongKDPrice[L"宁夏回族自治区"].push_back({ 0, 0, 1, 7, 5 });
		g_xiaoBaiXiongKDPrice[L"青海省"].push_back({ 0, 0, 1, 7, 5 });
		g_xiaoBaiXiongKDPrice[L"海南省"].push_back({ 0, 0, 1, 7, 5 });
		g_xiaoBaiXiongKDPrice[L"内蒙古自治区"].push_back({ 0, 0, 1, 8, 6 });
		g_xiaoBaiXiongKDPrice[L"甘肃省"].push_back({ 0, 0, 1, 6, 5 });
	}
	//艾维尔
}

//----------------------------------------------------------------------------------//