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
//�ϴ�
extern std::map< std::wstring, std::list<sExpressPriceInfo> > g_weiFuKangYDKDPrice;
extern std::map< std::wstring, std::list<sExpressPriceInfo> > g_jingXinGeYDKDPrice;
extern std::map< std::wstring, std::list<sExpressPriceInfo> > g_quLvShouNaKDPrice;
extern std::map< std::wstring, std::list<sExpressPriceInfo> > g_shuoGuoLiuXiangKDPrice;
extern std::map< std::wstring, std::list<sExpressPriceInfo> > g_xingXingShaoNvKDPrice;
//------------------------------------˳��۸�--------------------------------------//
//����ҫ��
extern std::vector< std::list<sExpressPriceInfo> > g_yongChuangYaoHuiSFPrice;
//����
extern std::vector< std::list<sExpressPriceInfo> > g_miYaSFPrice;
//��һ��԰
extern std::vector< std::list<sExpressPriceInfo> > g_qiYiJiangYuanSFPrice;
//����Ƽ�
extern std::vector< std::list<sExpressPriceInfo> > g_yiMaiKeJiSFPrice;
//Ȥ������
extern std::vector< std::list<sExpressPriceInfo> > g_quLvShouNaSFPrice;
//˶������
extern std::vector< std::list<sExpressPriceInfo> > g_shuoGuoLiuXiangSFPrice;
//----------------------------------------------------------------------------------//

//------------------------------------���˼۸�--------------------------------------//
//����ҫ��
extern std::map< std::wstring, std::list<sLargeExpressPriceInfo> > g_yongChuangYaoHuiZTKYPrice;
//�����
extern std::map< std::wstring, std::list<sLargeExpressPriceInfo> > g_xinMaBangZTKYPrice;
//����Ƽ�
extern std::map< std::wstring, std::list<sLargeExpressPriceInfo> > g_yiMaiKeJiZTKYPrice;
//����
extern std::map< std::wstring, std::list<sLargeExpressPriceInfo> > g_miYaZTKYPrice;
//��һ��԰
extern std::map< std::wstring, std::list<sLargeExpressPriceInfo> > g_qiYiJiangYuanZTKYPrice;
//���Ƶ���
extern std::map< std::wstring, std::list<sLargeExpressPriceInfo> > g_zhiShanZTKYPrice;
//ά��
extern std::map< std::wstring, std::list<sLargeExpressPriceInfo> > g_weiFuKangZTKYPrice;
//----------------------------------------------------------------------------------//


//----------------------------------�ɱ�����۸���---------------------------------//
extern std::map< std::wstring, std::list<sLargeExpressPriceInfo> > g_chengBenZTKYPrice;

//----------------------------------������---------------------------------------//
extern std::map< std::wstring, sDuoDuoMaiCaiPriceInfo > g_duoDuoMaiCaiPrice;