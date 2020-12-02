#pragma once
extern void PrepareExpressPrice();
//百世
extern std::map< std::wstring, std::list<sExpressPriceInfo> > g_taiFuShangMaoBSPrice;
extern std::map< std::wstring, std::list<sExpressPriceInfo> > g_yiMaiKeJiBSPrice;
extern std::map< std::wstring, std::list<sExpressPriceInfo> > g_qiYiJiangYuanBSPrice;
extern std::map< std::wstring, std::list<sExpressPriceInfo> > g_xinMaBangBSPrice;
extern std::map< std::wstring, std::list<sExpressPriceInfo> > g_miYaBSPrice;
extern std::map< std::wstring, std::list<sExpressPriceInfo> > g_yongChuangYaoHuiKDPrice;
extern std::map< std::wstring, std::list<sExpressPriceInfo> > g_laFengQingKDPrice;
extern std::map< std::wstring, std::list<sExpressPriceInfo> > g_zhiShanBSKDPrice;
extern std::map< std::wstring, std::list<sExpressPriceInfo> > g_zhiShanQTKDPrice;
//圆通
extern std::map< std::wstring, std::list<sExpressPriceInfo> > g_kunLunShanYTPrice;

//------------------------------------顺丰价格--------------------------------------//
//永创耀辉
extern std::vector< std::list<sExpressPriceInfo> > g_yongChuangYaoHuiSFPrice;
//弥雅
extern std::vector< std::list<sExpressPriceInfo> > g_miYaSFPrice;
//七一酱园
extern std::vector< std::list<sExpressPriceInfo> > g_qiYiJiangYuanSFPrice;
//----------------------------------------------------------------------------------//

//------------------------------------快运价格--------------------------------------//
//永创耀辉
extern std::map< std::wstring, sLargeExpressPriceInfo > g_yongChuangYaoHuiZTKYPrice;
//新马帮
extern std::map< std::wstring, sLargeExpressPriceInfo > g_xinMaBangZTKYPrice;
//颐麦科技
extern std::map< std::wstring, sLargeExpressPriceInfo > g_yiMaiKeJiZTKYPrice;
//弥雅
extern std::map< std::wstring, sLargeExpressPriceInfo > g_miYaZTKYPrice;
//七一酱园
extern std::map< std::wstring, sLargeExpressPriceInfo > g_qiYiJiangYuanZTKYPrice;
//----------------------------------------------------------------------------------//


//----------------------------------成本核算价格用---------------------------------//
extern std::map< std::wstring, sLargeExpressPriceInfo > g_chengBenZTKYPrice;