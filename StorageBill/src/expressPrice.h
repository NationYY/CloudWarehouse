#pragma once
extern void PrepareExpressPrice();
//����
extern std::map< std::wstring, std::list<sExpressPriceInfo> > g_taiFuShangMaoBSPrice;
extern std::map< std::wstring, std::list<sExpressPriceInfo> > g_yiMaiKeJiBSPrice;
extern std::map< std::wstring, std::list<sExpressPriceInfo> > g_qiYiJiangYuanBSPrice;
extern std::map< std::wstring, std::list<sExpressPriceInfo> > g_xinMaBangBSPrice;
extern std::map< std::wstring, std::list<sExpressPriceInfo> > g_miYaBSPrice;
extern std::map< std::wstring, std::list<sExpressPriceInfo> > g_yongChuangYaoHuiKDPrice;
//Բͨ
extern std::map< std::wstring, std::list<sExpressPriceInfo> > g_kunLunShanYTPrice;

//------------------------------------˳��۸�--------------------------------------//
//����ҫ��
extern std::vector< std::list<sExpressPriceInfo> > g_yongChuangYaoHuiSFPrice;
//----------------------------------------------------------------------------------//

//------------------------------------���˼۸�--------------------------------------//
//����ҫ��
extern std::map< std::wstring, sLargeExpressPriceInfo > g_yongChuangYaoHuiZTKYPrice;
extern std::map< std::wstring, sLargeExpressPriceInfo > g_xinMaBangZTKYPrice;
//----------------------------------------------------------------------------------//


//----------------------------------�ɱ�����۸���---------------------------------//
extern std::map< std::wstring, sLargeExpressPriceInfo > g_chengBenZTKYPrice;