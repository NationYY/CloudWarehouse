#pragma once
extern void PrepareExpressPrice();
//百世
extern std::map< std::wstring, std::list<sExpressPriceInfo> > g_taiFuShangMaoBSPrice;
extern std::map< std::wstring, std::list<sExpressPriceInfo> > g_yiMaiKeJiBSPrice;
extern std::map< std::wstring, std::list<sExpressPriceInfo> > g_qiYiJiangYuanBSPrice;
extern std::map< std::wstring, std::list<sExpressPriceInfo> > g_xinMaBangBSPrice;
extern std::map< std::wstring, std::list<sExpressPriceInfo> > g_miYaBSPrice;
extern std::map< std::wstring, std::list<sExpressPriceInfo> > g_yongChuangYaoHuiKDPrice;
//圆通
extern std::map< std::wstring, std::list<sExpressPriceInfo> > g_kunLunShanYTPrice;

//------------------------------------顺丰价格--------------------------------------//
//永创耀辉
extern std::vector< std::list<sExpressPriceInfo> > g_yongChuangYaoHuiSFPrice;
//----------------------------------------------------------------------------------//

//------------------------------------快运价格--------------------------------------//
//永创耀辉
extern std::map< std::wstring, sLargeExpressPriceInfo > g_yongChuangYaoHuiZTKYPrice;
extern std::map< std::wstring, sLargeExpressPriceInfo > g_xinMaBangZTKYPrice;
//----------------------------------------------------------------------------------//


//----------------------------------成本核算价格用---------------------------------//
extern std::map< std::wstring, sLargeExpressPriceInfo > g_chengBenZTKYPrice;