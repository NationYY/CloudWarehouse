#pragma once
extern void PrepareExpressPrice();
//����
extern std::map< std::wstring, std::list<sExpressPriceInfo> > g_taiFuShangMaoBSPrice;
extern std::map< std::wstring, std::list<sExpressPriceInfo> > g_yiMaiKeJiBSPrice;
extern std::map< std::wstring, std::list<sExpressPriceInfo> > g_qiYiJiangYuanBSPrice;
extern std::map< std::wstring, std::list<sExpressPriceInfo> > g_xinMaBangBSPrice;
extern std::map< std::wstring, std::list<sExpressPriceInfo> > g_miYaBSPrice;
extern std::map< std::wstring, std::list<sExpressPriceInfo> > g_yongChuangYaoHuiKDPrice;
extern std::map< std::wstring, std::list<sExpressPriceInfo> > g_laFengQingKDPrice;
extern std::map< std::wstring, std::list<sExpressPriceInfo> > g_zhiShanBSKDPrice;
extern std::map< std::wstring, std::list<sExpressPriceInfo> > g_zhiShanQTKDPrice;
//Բͨ
extern std::map< std::wstring, std::list<sExpressPriceInfo> > g_kunLunShanYTPrice;

//------------------------------------˳��۸�--------------------------------------//
//����ҫ��
extern std::vector< std::list<sExpressPriceInfo> > g_yongChuangYaoHuiSFPrice;
//����
extern std::vector< std::list<sExpressPriceInfo> > g_miYaSFPrice;
//��һ��԰
extern std::vector< std::list<sExpressPriceInfo> > g_qiYiJiangYuanSFPrice;
//----------------------------------------------------------------------------------//

//------------------------------------���˼۸�--------------------------------------//
//����ҫ��
extern std::map< std::wstring, sLargeExpressPriceInfo > g_yongChuangYaoHuiZTKYPrice;
//�����
extern std::map< std::wstring, sLargeExpressPriceInfo > g_xinMaBangZTKYPrice;
//����Ƽ�
extern std::map< std::wstring, sLargeExpressPriceInfo > g_yiMaiKeJiZTKYPrice;
//����
extern std::map< std::wstring, sLargeExpressPriceInfo > g_miYaZTKYPrice;
//��һ��԰
extern std::map< std::wstring, sLargeExpressPriceInfo > g_qiYiJiangYuanZTKYPrice;
//----------------------------------------------------------------------------------//


//----------------------------------�ɱ�����۸���---------------------------------//
extern std::map< std::wstring, sLargeExpressPriceInfo > g_chengBenZTKYPrice;