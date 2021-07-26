#include "stdafx.h"
#include "expressPrice.h"
//------------------------------------��ݼ۸�--------------------------------------//
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

//------------------------------------˳��۸�--------------------------------------//
//����ҫ��
std::vector< std::list<sExpressPriceInfo> > g_yongChuangYaoHuiSFPrice;
//����
std::vector< std::list<sExpressPriceInfo> > g_miYaSFPrice;
//��һ��԰
std::vector< std::list<sExpressPriceInfo> > g_qiYiJiangYuanSFPrice;
//����Ƽ�
std::vector< std::list<sExpressPriceInfo> > g_yiMaiKeJiSFPrice;
//Ȥ������
std::vector< std::list<sExpressPriceInfo> > g_quLvShouNaSFPrice;
//˶������
std::vector< std::list<sExpressPriceInfo> > g_shuoGuoLiuXiangSFPrice;
//���Ƶ���
std::vector< std::list<sExpressPriceInfo> > g_zhiShanSFPrice;
//----------------------------------------------------------------------------------//


//------------------------------------���˼۸�--------------------------------------//
//����ҫ��
std::map< std::wstring, std::list<sLargeExpressPriceInfo> > g_yongChuangYaoHuiZTKYPrice;
//�����
std::map< std::wstring, std::list<sLargeExpressPriceInfo> > g_xinMaBangZTKYPrice;
//����Ƽ�
std::map< std::wstring, std::list<sLargeExpressPriceInfo> > g_yiMaiKeJiZTKYPrice;
//����
std::map< std::wstring, std::list<sLargeExpressPriceInfo> > g_miYaZTKYPrice;
//��һ��԰
std::map< std::wstring, std::list<sLargeExpressPriceInfo> > g_qiYiJiangYuanZTKYPrice;
//���Ƶ���
std::map< std::wstring, std::list<sLargeExpressPriceInfo> > g_zhiShanZTKYPrice;
//ά��
std::map< std::wstring, std::list<sLargeExpressPriceInfo> > g_weiFuKangZTKYPrice;
//----------------------------------------------------------------------------------//


//----------------------------------�ɱ�����۸���---------------------------------//
std::map< std::wstring, std::list<sLargeExpressPriceInfo> > g_chengBenZTKYPrice;

//----------------------------------������---------------------------------------//
std::map< std::wstring, sDuoDuoMaiCaiPriceInfo > g_duoDuoMaiCaiPrice;

void PrepareExpressPrice()
{
	
	//��С���� �������  ����	���ط���	���ط���
	//̩����ó
	{
		//0-3���� һ�ڼ�
		g_taiFuShangMaoBSPrice[L"�Ĵ�ʡ"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"����"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"�㽭ʡ"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"�Ϻ�"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"����"].push_back({ 0, 3, 3, 4.2, 0 });
		g_taiFuShangMaoBSPrice[L"���"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"�㶫ʡ"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"����׳��������"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"�ӱ�ʡ"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"ɽ��ʡ"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"ɽ��ʡ"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 4.2, 0 });
		g_taiFuShangMaoBSPrice[L"���Ļ���������"].push_back({ 0, 3, 3, 4.2, 0 });
		g_taiFuShangMaoBSPrice[L"�ຣʡ"].push_back({ 0, 3, 3, 4.2, 0 });
		g_taiFuShangMaoBSPrice[L"������ʡ"].push_back({ 0, 3, 3, 4.2, 0 });
		g_taiFuShangMaoBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 4.2, 0 });
		g_taiFuShangMaoBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 4.2, 0 });
		//3��������
		g_taiFuShangMaoBSPrice[L"�Ĵ�ʡ"].push_back({ 3, 0, 1, 3.8, 1.2 });
		g_taiFuShangMaoBSPrice[L"����"].push_back({ 3, 0, 1, 3.8, 1.7 });
		g_taiFuShangMaoBSPrice[L"����ʡ"].push_back({ 3, 0, 1, 3.8, 1.7 });
		g_taiFuShangMaoBSPrice[L"����ʡ"].push_back({ 3, 0, 1, 3.8, 1.7 });
		g_taiFuShangMaoBSPrice[L"����ʡ"].push_back({ 3, 0, 1, 3.8, 1.7 });
		g_taiFuShangMaoBSPrice[L"����ʡ"].push_back({ 3, 0, 1, 3.8, 1.7 });
		g_taiFuShangMaoBSPrice[L"�㽭ʡ"].push_back({ 3, 0, 1, 3.8, 1.7 });
		g_taiFuShangMaoBSPrice[L"�Ϻ�"].push_back({ 3, 0, 1, 3.8, 2 });
		g_taiFuShangMaoBSPrice[L"����ʡ"].push_back({ 3, 0, 1, 3.8, 1.7 });
		g_taiFuShangMaoBSPrice[L"����ʡ"].push_back({ 3, 0, 1, 3.8, 1.7 });
		g_taiFuShangMaoBSPrice[L"����ʡ"].push_back({ 3, 0, 1, 3.8, 1.7 });
		g_taiFuShangMaoBSPrice[L"����ʡ"].push_back({ 3, 0, 1, 3.8, 1.7 });
		g_taiFuShangMaoBSPrice[L"����"].push_back({ 3, 0, 1, 4.2, 2 });
		g_taiFuShangMaoBSPrice[L"���"].push_back({ 3, 0, 1, 3.8, 1.7 });
		g_taiFuShangMaoBSPrice[L"�㶫ʡ"].push_back({ 3, 0, 1, 3.8, 1.7 });
		g_taiFuShangMaoBSPrice[L"����׳��������"].push_back({ 3, 0, 1, 3.8, 1.7 });
		g_taiFuShangMaoBSPrice[L"�ӱ�ʡ"].push_back({ 3, 0, 1, 3.8, 1.7 });
		g_taiFuShangMaoBSPrice[L"����ʡ"].push_back({ 3, 0, 1, 3.8, 1.7 });
		g_taiFuShangMaoBSPrice[L"����ʡ"].push_back({ 3, 0, 1, 3.8, 1.7 });
		g_taiFuShangMaoBSPrice[L"ɽ��ʡ"].push_back({ 3, 0, 1, 3.8, 1.7 });
		g_taiFuShangMaoBSPrice[L"ɽ��ʡ"].push_back({ 3, 0, 1, 3.8, 1.7 });
		g_taiFuShangMaoBSPrice[L"����ʡ"].push_back({ 3, 0, 1, 4.2, 2.2 });
		g_taiFuShangMaoBSPrice[L"���Ļ���������"].push_back({ 3, 0, 1, 4.2, 2.4 });
		g_taiFuShangMaoBSPrice[L"�ຣʡ"].push_back({ 3, 0, 1, 4.2, 2.4 });
		g_taiFuShangMaoBSPrice[L"������ʡ"].push_back({ 3, 0, 1, 4.2, 2.5 });
		g_taiFuShangMaoBSPrice[L"����ʡ"].push_back({ 3, 0, 1, 4.2, 2.2 });
		g_taiFuShangMaoBSPrice[L"����ʡ"].push_back({ 3, 0, 1, 4.2, 1.7 });
	}
	//����Ƽ�
	{
		//0-3���� һ�ڼ�
		g_yiMaiKeJiBSPrice[L"�Ϻ�"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"����"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"�㽭ʡ"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"ɽ��ʡ"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"���"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"�ӱ�ʡ"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"ɽ��ʡ"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"�㶫ʡ"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"����׳��������"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"�Ĵ�ʡ"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"����"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"���Ļ���������"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"�ຣʡ"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"������ʡ"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"���ɹ�������"].push_back({ 0, 3, 3, 3.4, 0 });
		g_yiMaiKeJiBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.4, 0 });
		//
		g_yiMaiKeJiBSPrice[L"�½�ά���������"].push_back({ 0, 0, 1, 15.5, 13.5 });
		g_yiMaiKeJiBSPrice[L"����������"].push_back({ 0, 0, 1, 17.5, 17.5 });
		//3��������
		g_yiMaiKeJiBSPrice[L"�Ϻ�"].push_back({ 3, 0, 3, 5, 1.5 });
		g_yiMaiKeJiBSPrice[L"����"].push_back({ 3, 0, 3, 5, 1.5 });
		g_yiMaiKeJiBSPrice[L"����ʡ"].push_back({ 3, 0, 3, 5, 1.3 });
		g_yiMaiKeJiBSPrice[L"����ʡ"].push_back({ 3, 0, 3, 5, 1.3 });
		g_yiMaiKeJiBSPrice[L"�㽭ʡ"].push_back({ 3, 0, 3, 5, 1.3 });
		g_yiMaiKeJiBSPrice[L"����ʡ"].push_back({ 3, 0, 3, 5, 1.3 });
		g_yiMaiKeJiBSPrice[L"ɽ��ʡ"].push_back({ 3, 0, 3, 5, 1.3 });
		g_yiMaiKeJiBSPrice[L"���"].push_back({ 3, 0, 3, 5, 1.3 });
		g_yiMaiKeJiBSPrice[L"�ӱ�ʡ"].push_back({ 3, 0, 3, 5, 1.3 });
		g_yiMaiKeJiBSPrice[L"����ʡ"].push_back({ 3, 0, 3, 5, 1.3 });
		g_yiMaiKeJiBSPrice[L"����ʡ"].push_back({ 3, 0, 3, 5, 1.3 });
		g_yiMaiKeJiBSPrice[L"ɽ��ʡ"].push_back({ 3, 0, 3, 5, 1.3 });
		g_yiMaiKeJiBSPrice[L"����ʡ"].push_back({ 3, 0, 3, 5, 1.3 });
		g_yiMaiKeJiBSPrice[L"����ʡ"].push_back({ 3, 0, 3, 5, 1.3 });
		g_yiMaiKeJiBSPrice[L"�㶫ʡ"].push_back({ 3, 0, 3, 5, 1.3 });
		g_yiMaiKeJiBSPrice[L"����ʡ"].push_back({ 3, 0, 3, 5, 1.3 });
		g_yiMaiKeJiBSPrice[L"����׳��������"].push_back({ 3, 0, 3, 5, 1.3 });
		g_yiMaiKeJiBSPrice[L"�Ĵ�ʡ"].push_back({ 3, 0, 3, 5, 1 });
		g_yiMaiKeJiBSPrice[L"����"].push_back({ 3, 0, 3, 5, 1.2 });
		g_yiMaiKeJiBSPrice[L"����ʡ"].push_back({ 3, 0, 3, 5, 1.2 });
		g_yiMaiKeJiBSPrice[L"����ʡ"].push_back({ 3, 0, 3, 5, 1.2 });
		g_yiMaiKeJiBSPrice[L"����ʡ"].push_back({ 3, 0, 3, 5, 1.8 });
		g_yiMaiKeJiBSPrice[L"���Ļ���������"].push_back({ 3, 0, 3, 5, 1.8 });
		g_yiMaiKeJiBSPrice[L"�ຣʡ"].push_back({ 3, 0, 3, 5, 1.8 });
		g_yiMaiKeJiBSPrice[L"������ʡ"].push_back({ 3, 0, 3, 5, 2 });
		g_yiMaiKeJiBSPrice[L"����ʡ"].push_back({ 3, 0, 3, 5, 2 });
		g_yiMaiKeJiBSPrice[L"����ʡ"].push_back({ 3, 0, 3, 5, 2 });
		g_yiMaiKeJiBSPrice[L"���ɹ�������"].push_back({ 3, 0, 3, 6.5, 5.5 });
		g_yiMaiKeJiBSPrice[L"����ʡ"].push_back({ 3, 0, 3, 5, 4 });
	}
	//��һ��԰
	{
		//0-3���� һ�ڼ�
		g_qiYiJiangYuanBSPrice[L"�Ĵ�ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_qiYiJiangYuanBSPrice[L"����"].push_back({ 0, 3, 3, 3.5, 0 });
		g_qiYiJiangYuanBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_qiYiJiangYuanBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_qiYiJiangYuanBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_qiYiJiangYuanBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_qiYiJiangYuanBSPrice[L"�㽭ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_qiYiJiangYuanBSPrice[L"�Ϻ�"].push_back({ 0, 3, 3, 3.5, 0 });
		g_qiYiJiangYuanBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_qiYiJiangYuanBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_qiYiJiangYuanBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_qiYiJiangYuanBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_qiYiJiangYuanBSPrice[L"����"].push_back({ 0, 3, 3, 3.5, 0 });
		g_qiYiJiangYuanBSPrice[L"���"].push_back({ 0, 3, 3, 3.5, 0 });
		g_qiYiJiangYuanBSPrice[L"�㶫ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_qiYiJiangYuanBSPrice[L"����׳��������"].push_back({ 0, 3, 3, 3.5, 0 });
		g_qiYiJiangYuanBSPrice[L"�ӱ�ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_qiYiJiangYuanBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_qiYiJiangYuanBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_qiYiJiangYuanBSPrice[L"ɽ��ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_qiYiJiangYuanBSPrice[L"ɽ��ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_qiYiJiangYuanBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 4.5, 0 });
		g_qiYiJiangYuanBSPrice[L"���Ļ���������"].push_back({ 0, 3, 3, 4.5, 0 });
		g_qiYiJiangYuanBSPrice[L"�ຣʡ"].push_back({ 0, 3, 3, 4.5, 0 });
		g_qiYiJiangYuanBSPrice[L"������ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_qiYiJiangYuanBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_qiYiJiangYuanBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		//
		g_qiYiJiangYuanBSPrice[L"���ɹ�������"].push_back({ 0, 0, 1, 9, 5 });
		g_qiYiJiangYuanBSPrice[L"����ʡ"].push_back({ 0, 0, 1, 9, 5 });
		g_qiYiJiangYuanBSPrice[L"�½�ά���������"].push_back({ 0, 0, 1, 15, 13 });
		g_qiYiJiangYuanBSPrice[L"����������"].push_back({ 0, 0, 1, 17, 17 });
		//3-5����
		g_qiYiJiangYuanBSPrice[L"�Ĵ�ʡ"].push_back({ 3, 5, 3, 4.5, 1.6 });
		g_qiYiJiangYuanBSPrice[L"����"].push_back({ 3, 5, 3, 4.5, 1.8 });
		g_qiYiJiangYuanBSPrice[L"����ʡ"].push_back({ 3, 5, 3, 4.5, 1.8 });
		g_qiYiJiangYuanBSPrice[L"����ʡ"].push_back({ 3, 5, 3, 4.5, 1.8 });
		g_qiYiJiangYuanBSPrice[L"����ʡ"].push_back({ 3, 5, 3, 4.5, 1.8 });
		g_qiYiJiangYuanBSPrice[L"����ʡ"].push_back({ 3, 5, 3, 4.5, 1.8 });
		g_qiYiJiangYuanBSPrice[L"�㽭ʡ"].push_back({ 3, 5, 3, 4.5, 1.8 });
		g_qiYiJiangYuanBSPrice[L"�Ϻ�"].push_back({ 3, 5, 3, 4.5, 1.8 });
		g_qiYiJiangYuanBSPrice[L"����ʡ"].push_back({ 3, 5, 3, 4.5, 1.8 });
		g_qiYiJiangYuanBSPrice[L"����ʡ"].push_back({ 3, 5, 3, 4.5, 1.8 });
		g_qiYiJiangYuanBSPrice[L"����ʡ"].push_back({ 3, 5, 3, 4.5, 1.8 });
		g_qiYiJiangYuanBSPrice[L"����ʡ"].push_back({ 3, 5, 3, 4.5, 1.8 });
		g_qiYiJiangYuanBSPrice[L"����"].push_back({ 3, 5, 3, 4.5, 1.8 });
		g_qiYiJiangYuanBSPrice[L"���"].push_back({ 3, 5, 3, 4.5, 1.8 });
		g_qiYiJiangYuanBSPrice[L"�㶫ʡ"].push_back({ 3, 5, 3, 4.5, 1.8 });
		g_qiYiJiangYuanBSPrice[L"����׳��������"].push_back({ 3, 5, 3, 4.5, 1.8 });
		g_qiYiJiangYuanBSPrice[L"�ӱ�ʡ"].push_back({ 3, 5, 3, 4.5, 1.8 });
		g_qiYiJiangYuanBSPrice[L"����ʡ"].push_back({ 3, 5, 3, 4.5, 1.8 });
		g_qiYiJiangYuanBSPrice[L"����ʡ"].push_back({ 3, 5, 3, 4.5, 1.8 });
		g_qiYiJiangYuanBSPrice[L"ɽ��ʡ"].push_back({ 3, 5, 3, 4.5, 1.8 });
		g_qiYiJiangYuanBSPrice[L"ɽ��ʡ"].push_back({ 3, 5, 3, 4.5, 1.8 });
		g_qiYiJiangYuanBSPrice[L"����ʡ"].push_back({ 3, 5, 3, 4.5, 2.5 });
		g_qiYiJiangYuanBSPrice[L"���Ļ���������"].push_back({ 3, 5, 3, 4.5, 2.5 });
		g_qiYiJiangYuanBSPrice[L"�ຣʡ"].push_back({ 3, 5, 3, 4.5, 2.5 });
		g_qiYiJiangYuanBSPrice[L"������ʡ"].push_back({ 3, 5, 3, 4.5, 2.5 });
		g_qiYiJiangYuanBSPrice[L"����ʡ"].push_back({ 3, 5, 3, 4.5, 2.5 });
		g_qiYiJiangYuanBSPrice[L"����ʡ"].push_back({ 3, 5, 3, 4.5, 2.5 });
		//5��������
		g_qiYiJiangYuanBSPrice[L"�Ĵ�ʡ"].push_back({ 5, 0, 1, 4.2, 1.6 });
		g_qiYiJiangYuanBSPrice[L"����"].push_back({ 5, 0, 1, 4.2, 1.8 });
		g_qiYiJiangYuanBSPrice[L"����ʡ"].push_back({ 5, 0, 1, 4.2, 3.2 });
		g_qiYiJiangYuanBSPrice[L"����ʡ"].push_back({ 5, 0, 1, 4.2, 3.2 });
		g_qiYiJiangYuanBSPrice[L"����ʡ"].push_back({ 5, 0, 1, 4.2, 3.2 });
		g_qiYiJiangYuanBSPrice[L"����ʡ"].push_back({ 5, 0, 1, 4.2, 3.2 });
		g_qiYiJiangYuanBSPrice[L"�㽭ʡ"].push_back({ 5, 0, 1, 4.2, 3.2 });
		g_qiYiJiangYuanBSPrice[L"�Ϻ�"].push_back({ 5, 0, 1, 4.2, 3.2 });
		g_qiYiJiangYuanBSPrice[L"����ʡ"].push_back({ 5, 0, 1, 4.2, 3.2 });
		g_qiYiJiangYuanBSPrice[L"����ʡ"].push_back({ 5, 0, 1, 4.2, 3.2 });
		g_qiYiJiangYuanBSPrice[L"����ʡ"].push_back({ 5, 0, 1, 4.2, 3.2 });
		g_qiYiJiangYuanBSPrice[L"����ʡ"].push_back({ 5, 0, 1, 4.2, 3.2 });
		g_qiYiJiangYuanBSPrice[L"����"].push_back({ 5, 0, 1, 4.2, 3.2 });
		g_qiYiJiangYuanBSPrice[L"���"].push_back({ 5, 0, 1, 4.2, 3.2 });
		g_qiYiJiangYuanBSPrice[L"�㶫ʡ"].push_back({ 5, 0, 1, 4.2, 3.2 });
		g_qiYiJiangYuanBSPrice[L"����׳��������"].push_back({ 5, 0, 1, 4.2, 3.2 });
		g_qiYiJiangYuanBSPrice[L"�ӱ�ʡ"].push_back({ 5, 0, 1, 4.2, 3.2 });
		g_qiYiJiangYuanBSPrice[L"����ʡ"].push_back({ 5, 0, 1, 4.2, 3.2 });
		g_qiYiJiangYuanBSPrice[L"����ʡ"].push_back({ 5, 0, 1, 4.2, 3.2 });
		g_qiYiJiangYuanBSPrice[L"ɽ��ʡ"].push_back({ 5, 0, 1, 4.2, 3.2 });
		g_qiYiJiangYuanBSPrice[L"ɽ��ʡ"].push_back({ 5, 0, 1, 4.2, 3.2 });
		g_qiYiJiangYuanBSPrice[L"����ʡ"].push_back({ 5, 0, 1, 4.2, 5.2 });
		g_qiYiJiangYuanBSPrice[L"���Ļ���������"].push_back({ 5, 0, 1, 4.2, 5.2 });
		g_qiYiJiangYuanBSPrice[L"�ຣʡ"].push_back({ 5, 0, 1, 4.2, 5.2 });
		g_qiYiJiangYuanBSPrice[L"������ʡ"].push_back({ 5, 0, 1, 4.2, 6.2 });
		g_qiYiJiangYuanBSPrice[L"����ʡ"].push_back({ 5, 0, 1, 4.2, 6.2 });
		g_qiYiJiangYuanBSPrice[L"����ʡ"].push_back({ 5, 0, 1, 4.2, 6.2 });
	}
	//�����
	{
		//0-3���� һ�ڼ�
		g_xinMaBangBSPrice[L"�Ϻ�"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"����"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"�㽭ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"ɽ��ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"���"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"�ӱ�ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"ɽ��ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"�㶫ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"����׳��������"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"�Ĵ�ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"����"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"���Ļ���������"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"�ຣʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"������ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xinMaBangBSPrice[L"���ɹ�������"].push_back({ 0, 3, 3, 3.5, 0 });
		//
		g_xinMaBangBSPrice[L"�½�ά���������"].push_back({ 0, 0, 1, 15.5, 14 });
		g_xinMaBangBSPrice[L"����������"].push_back({ 0, 0, 1, 17.5, 18 });
		//3-5���� һ�ڼ�
		g_xinMaBangBSPrice[L"�Ϻ�"].push_back({ 3, 5, 3, 4.3, 0 });
		g_xinMaBangBSPrice[L"����"].push_back({ 3, 5, 3, 4.3, 0 });
		g_xinMaBangBSPrice[L"����ʡ"].push_back({ 3, 5, 3, 4.3, 0 });
		g_xinMaBangBSPrice[L"����ʡ"].push_back({ 3, 5, 3, 4.3, 0 });
		g_xinMaBangBSPrice[L"�㽭ʡ"].push_back({ 3, 5, 3, 4.3, 0 });
		g_xinMaBangBSPrice[L"����ʡ"].push_back({ 3, 5, 3, 4.3, 0 });
		g_xinMaBangBSPrice[L"ɽ��ʡ"].push_back({ 3, 5, 3, 4.3, 0 });
		g_xinMaBangBSPrice[L"���"].push_back({ 3, 5, 3, 4.3, 0 });
		g_xinMaBangBSPrice[L"�ӱ�ʡ"].push_back({ 3, 5, 3, 4.3, 0 });
		g_xinMaBangBSPrice[L"����ʡ"].push_back({ 3, 5, 3, 4.3, 0 });
		g_xinMaBangBSPrice[L"����ʡ"].push_back({ 3, 5, 3, 4.3, 0 });
		g_xinMaBangBSPrice[L"ɽ��ʡ"].push_back({ 3, 5, 3, 4.3, 0 });
		g_xinMaBangBSPrice[L"����ʡ"].push_back({ 3, 5, 3, 4.3, 0 });
		g_xinMaBangBSPrice[L"����ʡ"].push_back({ 3, 5, 3, 4.3, 0 });
		g_xinMaBangBSPrice[L"�㶫ʡ"].push_back({ 3, 5, 3, 4.3, 0 });
		g_xinMaBangBSPrice[L"����ʡ"].push_back({ 3, 5, 3, 4.3, 0 });
		g_xinMaBangBSPrice[L"����׳��������"].push_back({ 3, 5, 3, 4.3, 0 });
		g_xinMaBangBSPrice[L"�Ĵ�ʡ"].push_back({ 3, 5, 3, 4.3, 0 });
		g_xinMaBangBSPrice[L"����"].push_back({ 3, 5, 3, 4.3, 0 });
		g_xinMaBangBSPrice[L"����ʡ"].push_back({ 3, 5, 3, 4.3, 0 });
		g_xinMaBangBSPrice[L"����ʡ"].push_back({ 3, 5, 3, 4.3, 0 });
		g_xinMaBangBSPrice[L"����ʡ"].push_back({ 3, 5, 3, 4.5, 0 });
		g_xinMaBangBSPrice[L"���Ļ���������"].push_back({ 3, 5, 3, 4.5, 0 });
		g_xinMaBangBSPrice[L"�ຣʡ"].push_back({ 3, 5, 3, 4.5, 0 });
		g_xinMaBangBSPrice[L"������ʡ"].push_back({ 3, 5, 3, 4.5, 0 });
		g_xinMaBangBSPrice[L"����ʡ"].push_back({ 3, 5, 3, 4.5, 0 });
		g_xinMaBangBSPrice[L"����ʡ"].push_back({ 3, 5, 3, 4.5, 0 });
		g_xinMaBangBSPrice[L"����ʡ"].push_back({ 3, 5, 3, 5.3, 0 });
		g_xinMaBangBSPrice[L"���ɹ�������"].push_back({ 3, 5, 3, 5.3, 0 });
		//5��������
		g_xinMaBangBSPrice[L"�Ϻ�"].push_back({ 5, 0, 3, 5, 1.4 });
		g_xinMaBangBSPrice[L"����"].push_back({ 5, 0, 3, 5, 1.4 });
		g_xinMaBangBSPrice[L"����ʡ"].push_back({ 5, 0, 3, 5, 1.2 });
		g_xinMaBangBSPrice[L"����ʡ"].push_back({ 5, 0, 3, 5, 1.2 });
		g_xinMaBangBSPrice[L"�㽭ʡ"].push_back({ 5, 0, 3, 5, 1.2 });
		g_xinMaBangBSPrice[L"����ʡ"].push_back({ 5, 0, 3, 5, 1.2 });
		g_xinMaBangBSPrice[L"ɽ��ʡ"].push_back({ 5, 0, 3, 5, 1.2 });
		g_xinMaBangBSPrice[L"���"].push_back({ 5, 0, 3, 5, 1.2 });
		g_xinMaBangBSPrice[L"�ӱ�ʡ"].push_back({ 5, 0, 3, 5, 1.2 });
		g_xinMaBangBSPrice[L"����ʡ"].push_back({ 5, 0, 3, 5, 1.2 });
		g_xinMaBangBSPrice[L"����ʡ"].push_back({ 5, 0, 3, 5, 1.2 });
		g_xinMaBangBSPrice[L"ɽ��ʡ"].push_back({ 5, 0, 3, 5, 1.2 });
		g_xinMaBangBSPrice[L"����ʡ"].push_back({ 5, 0, 3, 5, 1.2 });
		g_xinMaBangBSPrice[L"����ʡ"].push_back({ 5, 0, 3, 5, 1.2 });
		g_xinMaBangBSPrice[L"�㶫ʡ"].push_back({ 5, 0, 3, 5, 1.2 });
		g_xinMaBangBSPrice[L"����ʡ"].push_back({ 5, 0, 3, 5, 1.2 });
		g_xinMaBangBSPrice[L"����׳��������"].push_back({ 5, 0, 3, 5, 1.2 });
		g_xinMaBangBSPrice[L"�Ĵ�ʡ"].push_back({ 5, 0, 3, 5, 0.8 });
		g_xinMaBangBSPrice[L"����"].push_back({ 5, 0, 3, 5, 1.2 });
		g_xinMaBangBSPrice[L"����ʡ"].push_back({ 5, 0, 3, 5, 1.2 });
		g_xinMaBangBSPrice[L"����ʡ"].push_back({ 5, 0, 3, 5, 1.2 });
		g_xinMaBangBSPrice[L"����ʡ"].push_back({ 5, 0, 3, 5, 1.8 });
		g_xinMaBangBSPrice[L"���Ļ���������"].push_back({ 5, 0, 3, 5, 1.8 });
		g_xinMaBangBSPrice[L"�ຣʡ"].push_back({ 5, 0, 3, 5, 1.8 });
		g_xinMaBangBSPrice[L"������ʡ"].push_back({ 5, 0, 3, 5, 2 });
		g_xinMaBangBSPrice[L"����ʡ"].push_back({ 5, 0, 3, 5, 2 });
		g_xinMaBangBSPrice[L"����ʡ"].push_back({ 5, 0, 3, 5, 2 });
		g_xinMaBangBSPrice[L"����ʡ"].push_back({ 5, 0, 3, 5, 3.7 });
		g_xinMaBangBSPrice[L"���ɹ�������"].push_back({ 5, 0, 3, 7, 5.7 });
	}
	//����ҫ��˳��
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
	//���Ű���
	{
		//3������
		g_miYaBSPrice[L"�Ĵ�ʡ"].push_back({ 0, 0, 3, 4.2, 1 });
		g_miYaBSPrice[L"����"].push_back({ 0, 0, 3, 4.2, 1 });
		g_miYaBSPrice[L"����ʡ"].push_back({ 0, 0, 3, 4.2, 2 });
		g_miYaBSPrice[L"����ʡ"].push_back({ 0, 0, 3, 4.2, 2 });
		g_miYaBSPrice[L"����ʡ"].push_back({ 0, 0, 3, 4.2, 2 });
		g_miYaBSPrice[L"����ʡ"].push_back({ 0, 0, 3, 4.2, 2 });
		g_miYaBSPrice[L"�㽭ʡ"].push_back({ 0, 0, 3, 4.2, 2 });
		g_miYaBSPrice[L"�Ϻ�"].push_back({ 0, 0, 3, 4.2, 2 });
		g_miYaBSPrice[L"����ʡ"].push_back({ 0, 0, 3, 4.2, 2 });
		g_miYaBSPrice[L"����ʡ"].push_back({ 0, 0, 3, 4.2, 2 });
		g_miYaBSPrice[L"����ʡ"].push_back({ 0, 0, 3, 4.2, 2 });
		g_miYaBSPrice[L"����ʡ"].push_back({ 0, 0, 3, 4.2, 2 });
		g_miYaBSPrice[L"����"].push_back({ 0, 0, 3, 4.2, 3.5 });
		g_miYaBSPrice[L"���"].push_back({ 0, 0, 3, 4.2, 2 });
		g_miYaBSPrice[L"�㶫ʡ"].push_back({ 0, 0, 3, 4.2, 2 });
		g_miYaBSPrice[L"����׳��������"].push_back({ 0, 0, 3, 4.2, 2 });
		g_miYaBSPrice[L"�ӱ�ʡ"].push_back({ 0, 0, 3, 4.2, 2 });
		g_miYaBSPrice[L"����ʡ"].push_back({ 0, 0, 3, 4.2, 2 });
		g_miYaBSPrice[L"����ʡ"].push_back({ 0, 0, 3, 4.2, 2 });
		g_miYaBSPrice[L"ɽ��ʡ"].push_back({ 0, 0, 3, 4.2, 3.5 });
		g_miYaBSPrice[L"ɽ��ʡ"].push_back({ 0, 0, 3, 4.2, 2 });
		g_miYaBSPrice[L"����ʡ"].push_back({ 0, 0, 3, 4.2, 3.5 });
		g_miYaBSPrice[L"���Ļ���������"].push_back({ 0, 0, 3, 4.2, 6 });
		g_miYaBSPrice[L"�ຣʡ"].push_back({ 0, 0, 3, 4.2, 6 });
		g_miYaBSPrice[L"������ʡ"].push_back({ 0, 0, 3, 4.2, 3.5 });
		g_miYaBSPrice[L"����ʡ"].push_back({ 0, 0, 3, 4.2, 3.5 });
		g_miYaBSPrice[L"����ʡ"].push_back({ 0, 0, 3, 4.2, 3.5 });
		g_miYaBSPrice[L"����ʡ"].push_back({ 0, 0, 3, 8, 6 });
		//
		g_miYaBSPrice[L"���ɹ�������"].push_back({ 0, 0, 1, 8, 6 });
		g_miYaBSPrice[L"�½�ά���������"].push_back({ 0, 0, 1, 8, 6 });
		g_miYaBSPrice[L"����������"].push_back({ 0, 0, 1, 8, 6 });
	}
	//����ɽԲͨ
	{
		//
		g_kunLunShanYTPrice[L"�Ϻ�"].push_back({ 0, 3, 3, 3.5, 0 });
		g_kunLunShanYTPrice[L"����"].push_back({ 0, 3, 3, 3.5, 0 });
		g_kunLunShanYTPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_kunLunShanYTPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_kunLunShanYTPrice[L"�㽭ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_kunLunShanYTPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_kunLunShanYTPrice[L"ɽ��ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_kunLunShanYTPrice[L"���"].push_back({ 0, 3, 3, 3.5, 0 });
		g_kunLunShanYTPrice[L"�ӱ�ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_kunLunShanYTPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_kunLunShanYTPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_kunLunShanYTPrice[L"ɽ��ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_kunLunShanYTPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_kunLunShanYTPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_kunLunShanYTPrice[L"�㶫ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_kunLunShanYTPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_kunLunShanYTPrice[L"����׳��������"].push_back({ 0, 3, 3, 3.5, 0 });
		g_kunLunShanYTPrice[L"�Ĵ�ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_kunLunShanYTPrice[L"����"].push_back({ 0, 3, 3, 3.5, 0 });
		g_kunLunShanYTPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_kunLunShanYTPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_kunLunShanYTPrice[L"����ʡ"].push_back({ 0, 3, 3, 4, 0 });
		g_kunLunShanYTPrice[L"���Ļ���������"].push_back({ 0, 3, 3, 4, 0 });
		g_kunLunShanYTPrice[L"�ຣʡ"].push_back({ 0, 3, 3, 4, 0 });
		g_kunLunShanYTPrice[L"������ʡ"].push_back({ 0, 3, 3, 4, 0 });
		g_kunLunShanYTPrice[L"����ʡ"].push_back({ 0, 3, 3, 4, 0 });
		g_kunLunShanYTPrice[L"����ʡ"].push_back({ 0, 3, 3, 4, 0 });
		g_kunLunShanYTPrice[L"���ɹ�������"].push_back({ 0, 3, 3, 4.5, 0 });
		g_kunLunShanYTPrice[L"����ʡ"].push_back({ 0, 3, 3, 4.5, 0 });
		//3-5һ�ڼ�
		g_kunLunShanYTPrice[L"�Ϻ�"].push_back({ 3, 5, 3, 3.75, 0 });
		g_kunLunShanYTPrice[L"����"].push_back({ 3, 5, 3, 3.75, 0 });
		g_kunLunShanYTPrice[L"����ʡ"].push_back({ 3, 5, 3, 3.75, 0 });
		g_kunLunShanYTPrice[L"����ʡ"].push_back({ 3, 5, 3, 3.75, 0 });
		g_kunLunShanYTPrice[L"�㽭ʡ"].push_back({ 3, 5, 3, 3.75, 0 });
		g_kunLunShanYTPrice[L"����ʡ"].push_back({ 3, 5, 3, 3.75, 0 });
		g_kunLunShanYTPrice[L"ɽ��ʡ"].push_back({ 3, 5, 3, 3.75, 0 });
		g_kunLunShanYTPrice[L"���"].push_back({ 3, 5, 3, 3.75, 0 });
		g_kunLunShanYTPrice[L"�ӱ�ʡ"].push_back({ 3, 5, 3, 3.75, 0 });
		g_kunLunShanYTPrice[L"����ʡ"].push_back({ 3, 5, 3, 3.75, 0 });
		g_kunLunShanYTPrice[L"����ʡ"].push_back({ 3, 5, 3, 3.75, 0 });
		g_kunLunShanYTPrice[L"ɽ��ʡ"].push_back({ 3, 5, 3, 3.75, 0 });
		g_kunLunShanYTPrice[L"����ʡ"].push_back({ 3, 5, 3, 3.75, 0 });
		g_kunLunShanYTPrice[L"����ʡ"].push_back({ 3, 5, 3, 3.75, 0 });
		g_kunLunShanYTPrice[L"�㶫ʡ"].push_back({ 3, 5, 3, 3.75, 0 });
		g_kunLunShanYTPrice[L"����ʡ"].push_back({ 3, 5, 3, 3.75, 0 });
		g_kunLunShanYTPrice[L"����׳��������"].push_back({ 3, 5, 3, 3.75, 0 });
		g_kunLunShanYTPrice[L"�Ĵ�ʡ"].push_back({ 3, 5, 3, 3.75, 0 });
		g_kunLunShanYTPrice[L"����"].push_back({ 3, 5, 3, 3.75, 0 });
		g_kunLunShanYTPrice[L"����ʡ"].push_back({ 3, 5, 3, 3.75, 0 });
		g_kunLunShanYTPrice[L"����ʡ"].push_back({ 3, 5, 3, 3.75, 0 });
		g_kunLunShanYTPrice[L"����ʡ"].push_back({ 3, 5, 3, 3.95, 0 });
		g_kunLunShanYTPrice[L"���Ļ���������"].push_back({ 3, 5, 3, 3.95, 0 });
		g_kunLunShanYTPrice[L"�ຣʡ"].push_back({ 3, 5, 3, 3.95, 0 });
		g_kunLunShanYTPrice[L"������ʡ"].push_back({ 3, 5, 3, 3.95, 0 });
		g_kunLunShanYTPrice[L"����ʡ"].push_back({ 3, 5, 3, 3.95, 0 });
		g_kunLunShanYTPrice[L"����ʡ"].push_back({ 3, 5, 3, 3.95, 0 });
		g_kunLunShanYTPrice[L"���ɹ�������"].push_back({ 3, 5, 3, 4.25, 0 });
		g_kunLunShanYTPrice[L"����ʡ"].push_back({ 3, 5, 3, 4.25, 0 });
		//5����
		g_kunLunShanYTPrice[L"�Ϻ�"].push_back({ 5, 0, 3, 4.5, 1.2 });
		g_kunLunShanYTPrice[L"����"].push_back({ 5, 0, 3, 4.5, 1.2 });
		g_kunLunShanYTPrice[L"����ʡ"].push_back({ 5, 0, 3, 4.5, 1 });
		g_kunLunShanYTPrice[L"����ʡ"].push_back({ 5, 0, 3, 4.5, 1 });
		g_kunLunShanYTPrice[L"�㽭ʡ"].push_back({ 5, 0, 3, 4.5, 1 });
		g_kunLunShanYTPrice[L"����ʡ"].push_back({ 5, 0, 3, 4.5, 1 });
		g_kunLunShanYTPrice[L"ɽ��ʡ"].push_back({ 5, 0, 3, 4.5, 1 });
		g_kunLunShanYTPrice[L"���"].push_back({ 5, 0, 3, 4.5, 1 });
		g_kunLunShanYTPrice[L"�ӱ�ʡ"].push_back({ 5, 0, 3, 4.5, 1 });
		g_kunLunShanYTPrice[L"����ʡ"].push_back({ 5, 0, 3, 4.5, 1 });
		g_kunLunShanYTPrice[L"����ʡ"].push_back({ 5, 0, 3, 4.5, 1 });
		g_kunLunShanYTPrice[L"ɽ��ʡ"].push_back({ 5, 0, 3, 4.5, 1 });
		g_kunLunShanYTPrice[L"����ʡ"].push_back({ 5, 0, 3, 4.5, 1 });
		g_kunLunShanYTPrice[L"����ʡ"].push_back({ 5, 0, 3, 4.5, 1 });
		g_kunLunShanYTPrice[L"�㶫ʡ"].push_back({ 5, 0, 3, 4.5, 1 });
		g_kunLunShanYTPrice[L"����ʡ"].push_back({ 5, 0, 3, 4.5, 1 });
		g_kunLunShanYTPrice[L"����׳��������"].push_back({ 5, 0, 3, 4.5, 1 });
		g_kunLunShanYTPrice[L"�Ĵ�ʡ"].push_back({ 5, 0, 3, 4.5, 0.6 });
		g_kunLunShanYTPrice[L"����"].push_back({ 5, 0, 3, 4.5, 1 });
		g_kunLunShanYTPrice[L"����ʡ"].push_back({ 5, 0, 3, 4.5, 1 });
		g_kunLunShanYTPrice[L"����ʡ"].push_back({ 5, 0, 3, 4.5, 1 });
		g_kunLunShanYTPrice[L"����ʡ"].push_back({ 5, 0, 3, 4.5, 1.6 });
		g_kunLunShanYTPrice[L"���Ļ���������"].push_back({ 5, 0, 3, 4.5, 1.6 });
		g_kunLunShanYTPrice[L"�ຣʡ"].push_back({ 5, 0, 3, 4.5, 1.6 });
		g_kunLunShanYTPrice[L"������ʡ"].push_back({ 5, 0, 3, 4.5, 1.8 });
		g_kunLunShanYTPrice[L"����ʡ"].push_back({ 5, 0, 3, 4.5, 1.8 });
		g_kunLunShanYTPrice[L"����ʡ"].push_back({ 5, 0, 3, 4.5, 1.8 });
		g_kunLunShanYTPrice[L"���ɹ�������"].push_back({ 5, 0, 3, 6, 5 });
		g_kunLunShanYTPrice[L"����ʡ"].push_back({ 5, 0, 3, 4.5, 3.5 });
		//
		g_kunLunShanYTPrice[L"�½�ά���������"].push_back({ 0, 0, 26, 80, 3 });
		g_kunLunShanYTPrice[L"����������"].push_back({ 0, 0, 15, 60, 4 });
	}
	//��ͨ���˳ɱ�
	{
		//12����
		g_chengBenZTKYPrice[L"����ʡ"].push_back({ 0, 12, 12, 35, 0 });
		g_chengBenZTKYPrice[L"����ʡ"].push_back({ 0, 12, 12, 35, 0 });
		g_chengBenZTKYPrice[L"������ʡ"].push_back({ 0, 12, 12, 35, 0 });
		g_chengBenZTKYPrice[L"����ʡ"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"����ʡ"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"����ʡ"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"�Ϻ�"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"����ʡ"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"ɽ��ʡ"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"����ʡ"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"����ʡ"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"�㽭ʡ"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"���ɹ�������"].push_back({ 0, 12, 12, 40, 0 });
		g_chengBenZTKYPrice[L"����"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"���"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"ɽ��ʡ"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"�ӱ�ʡ"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"����׳��������"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"�㶫ʡ"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"����ʡ"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"���Ļ���������"].push_back({ 0, 12, 12, 40, 0 });
		g_chengBenZTKYPrice[L"�½�ά���������"].push_back({ 0, 12, 12, 55, 0 });
		g_chengBenZTKYPrice[L"����ʡ"].push_back({ 0, 12, 12, 40, 0 });
		g_chengBenZTKYPrice[L"����ʡ"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"�ຣʡ"].push_back({ 0, 12, 12, 50, 0 });
		g_chengBenZTKYPrice[L"����ʡ"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"��ɽ��"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"�ڽ���"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"��ɽ����������"].push_back({ 0, 12, 12, 40, 0 });
		g_chengBenZTKYPrice[L"�ϳ���"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"�˱���"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"������"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"��Ԫ��"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"�㰲��"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"������"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"�ɶ���"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"��֦����"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"������"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"���β���������"].push_back({ 0, 12, 12, 40, 0 });
		g_chengBenZTKYPrice[L"üɽ��"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"������"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"�Թ���"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"������"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"������"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"������"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"���Ӳ���Ǽ��������"].push_back({ 0, 12, 12, 40, 0 });
		g_chengBenZTKYPrice[L"�Ű���"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"����������"].push_back({ 0, 12, 12, 70, 0 });
		g_chengBenZTKYPrice[L"����ʡ"].push_back({ 0, 12, 12, 16, 0 });
		g_chengBenZTKYPrice[L"����"].push_back({ 0, 12, 12, 16, 0 });
		//13-20����
		g_chengBenZTKYPrice[L"����ʡ"].push_back({ 12, 20, 20, 40, 0 });
		g_chengBenZTKYPrice[L"����ʡ"].push_back({ 12, 20, 20, 40, 0 });
		g_chengBenZTKYPrice[L"������ʡ"].push_back({ 12, 20, 20, 40, 0 });
		g_chengBenZTKYPrice[L"����ʡ"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"����ʡ"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"����ʡ"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"�Ϻ�"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"����ʡ"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"ɽ��ʡ"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"����ʡ"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"����ʡ"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"�㽭ʡ"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"���ɹ�������"].push_back({ 12, 20, 20, 50, 0 });
		g_chengBenZTKYPrice[L"����"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"���"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"ɽ��ʡ"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"�ӱ�ʡ"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"����׳��������"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"�㶫ʡ"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"����ʡ"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"���Ļ���������"].push_back({ 12, 20, 20, 50, 0 });
		g_chengBenZTKYPrice[L"�½�ά���������"].push_back({ 12, 20, 20, 55, 0 });
		g_chengBenZTKYPrice[L"����ʡ"].push_back({ 12, 20, 20, 50, 0 });
		g_chengBenZTKYPrice[L"����ʡ"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"�ຣʡ"].push_back({ 12, 20, 20, 55, 0 });
		g_chengBenZTKYPrice[L"����ʡ"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"��ɽ��"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"�ڽ���"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"��ɽ����������"].push_back({ 12, 20, 20, 50, 0 });
		g_chengBenZTKYPrice[L"�ϳ���"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"�˱���"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"������"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"��Ԫ��"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"�㰲��"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"������"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"�ɶ���"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"��֦����"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"������"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"���β���������"].push_back({ 12, 20, 20, 50, 0 });
		g_chengBenZTKYPrice[L"üɽ��"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"������"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"�Թ���"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"������"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"������"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"������"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"���Ӳ���Ǽ��������"].push_back({ 12, 20, 20, 50, 0 });
		g_chengBenZTKYPrice[L"�Ű���"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"����������"].push_back({ 12, 20, 20, 80, 0 });
		g_chengBenZTKYPrice[L"����ʡ"].push_back({ 12, 20, 20, 19, 0 });
		g_chengBenZTKYPrice[L"����"].push_back({ 12, 20, 20, 19, 0 });
		//20��������
		g_chengBenZTKYPrice[L"����ʡ"].push_back({ 20, 0, 20, 40, 1.5 });
		g_chengBenZTKYPrice[L"����ʡ"].push_back({ 20, 0, 20, 40, 1.5 });
		g_chengBenZTKYPrice[L"������ʡ"].push_back({ 20, 0, 20, 40, 1.5 });
		g_chengBenZTKYPrice[L"����ʡ"].push_back({ 20, 0, 20, 19, 1.1 });
		g_chengBenZTKYPrice[L"����ʡ"].push_back({ 20, 0, 20, 19, 1.1 });
		g_chengBenZTKYPrice[L"����ʡ"].push_back({ 20, 0, 20, 19, 1.1 });
		g_chengBenZTKYPrice[L"�Ϻ�"].push_back({ 20, 0, 20, 19, 1.1 });
		g_chengBenZTKYPrice[L"����ʡ"].push_back({ 20, 0, 20, 19, 1.1 });
		g_chengBenZTKYPrice[L"ɽ��ʡ"].push_back({ 20, 0, 20, 19, 1.1 });
		g_chengBenZTKYPrice[L"����ʡ"].push_back({ 20, 0, 20, 19, 1.1 });
		g_chengBenZTKYPrice[L"����ʡ"].push_back({ 20, 0, 20, 19, 1.1 });
		g_chengBenZTKYPrice[L"�㽭ʡ"].push_back({ 20, 0, 20, 19, 1.1 });
		g_chengBenZTKYPrice[L"���ɹ�������"].push_back({ 20, 0, 20, 50, 1.50 });
		g_chengBenZTKYPrice[L"����"].push_back({ 20, 0, 20, 19, 1.1 });
		g_chengBenZTKYPrice[L"���"].push_back({ 20, 0, 20, 19, 1.1 });
		g_chengBenZTKYPrice[L"ɽ��ʡ"].push_back({ 20, 0, 20, 19, 1.1 });
		g_chengBenZTKYPrice[L"�ӱ�ʡ"].push_back({ 20, 0, 20, 19, 1.1 });
		g_chengBenZTKYPrice[L"����׳��������"].push_back({ 20, 0, 20, 19, 1.1 });
		g_chengBenZTKYPrice[L"�㶫ʡ"].push_back({ 20, 0, 20, 19, 1.1 });
		g_chengBenZTKYPrice[L"����ʡ"].push_back({ 20, 0, 20, 19, 1.1 });
		g_chengBenZTKYPrice[L"���Ļ���������"].push_back({ 20, 0, 20, 50, 1.5 });
		g_chengBenZTKYPrice[L"�½�ά���������"].push_back({ 20, 0, 20, 55, 3 });
		g_chengBenZTKYPrice[L"����ʡ"].push_back({ 20, 0, 20, 50, 1.6 });
		g_chengBenZTKYPrice[L"����ʡ"].push_back({ 20, 0, 20, 19, 1.1 });
		g_chengBenZTKYPrice[L"�ຣʡ"].push_back({ 20, 0, 20, 55, 3 });

		g_chengBenZTKYPrice[L"����ʡ"].push_back({ 20, 0, 20, 19, 1.1 });

		g_chengBenZTKYPrice[L"��ɽ��"].push_back({ 20, 0, 20, 19, 0.8 });
		g_chengBenZTKYPrice[L"�ڽ���"].push_back({ 20, 0, 20, 19, 0.8 });
		g_chengBenZTKYPrice[L"��ɽ����������"].push_back({ 20, 0, 20, 50, 1.50 });
		g_chengBenZTKYPrice[L"�ϳ���"].push_back({ 20, 0, 20, 19, 0.8 });
		g_chengBenZTKYPrice[L"�˱���"].push_back({ 20, 0, 20, 19, 0.8 });
		g_chengBenZTKYPrice[L"������"].push_back({ 20, 0, 20, 19, 0.8 });
		g_chengBenZTKYPrice[L"��Ԫ��"].push_back({ 20, 0, 20, 19, 0.8 });
		g_chengBenZTKYPrice[L"�㰲��"].push_back({ 20, 0, 20, 19, 0.8 });
		g_chengBenZTKYPrice[L"������"].push_back({ 20, 0, 20, 19, 0.8 });
		g_chengBenZTKYPrice[L"�ɶ���"].push_back({ 20, 0, 20, 19, 0.8 });
		g_chengBenZTKYPrice[L"��֦����"].push_back({ 20, 0, 20, 19, 1.0 });
		g_chengBenZTKYPrice[L"������"].push_back({ 20, 0, 20, 19, 0.8 });
		g_chengBenZTKYPrice[L"���β���������"].push_back({ 20, 0, 20, 50, 1.50 });
		g_chengBenZTKYPrice[L"üɽ��"].push_back({ 20, 0, 20, 19, 0.8 });
		g_chengBenZTKYPrice[L"������"].push_back({ 20, 0, 20, 19, 0.8 });
		g_chengBenZTKYPrice[L"�Թ���"].push_back({ 20, 0, 20, 19, 0.8 });
		g_chengBenZTKYPrice[L"������"].push_back({ 20, 0, 20, 19, 0.8 });
		g_chengBenZTKYPrice[L"������"].push_back({ 20, 0, 20, 19, 0.8 });
		g_chengBenZTKYPrice[L"������"].push_back({ 20, 0, 20, 19, 0.8 });
		g_chengBenZTKYPrice[L"���Ӳ���Ǽ��������"].push_back({ 20, 0, 20, 50, 1.50 });
		g_chengBenZTKYPrice[L"�Ű���"].push_back({ 20, 0, 20, 19, 0.8 });
		g_chengBenZTKYPrice[L"����������"].push_back({ 20, 0, 20, 80, 3 });
		g_chengBenZTKYPrice[L"����ʡ"].push_back({ 20, 0, 20, 19, 1.1 });
		g_chengBenZTKYPrice[L"����"].push_back({ 20, 0, 20, 19, 1.0 });
	}
	//����ҫ����ͨ����
	{
		//12����
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"].push_back({ 0, 12, 12, 40, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"].push_back({ 0, 12, 12, 40, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"������ʡ"].push_back({ 0, 12, 12, 40, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"�Ϻ�"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"ɽ��ʡ"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"�㽭ʡ"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"���ɹ�������"].push_back({ 0, 12, 12, 45, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"����"].push_back({ 0, 12, 12, 25, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"���"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"ɽ��ʡ"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"�ӱ�ʡ"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"����׳��������"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"�㶫ʡ"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"���Ļ���������"].push_back({ 0, 12, 12, 45, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"�½�ά���������"].push_back({ 0, 12, 12, 55, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"].push_back({ 0, 12, 12, 45, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"�ຣʡ"].push_back({ 0, 12, 12, 50, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"��ɽ��"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"�ڽ���"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"��ɽ����������"].push_back({ 0, 12, 12, 29, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"�ϳ���"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"�˱���"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"������"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"��Ԫ��"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"�㰲��"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"������"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"�ɶ���"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"��֦����"].push_back({ 0, 12, 12, 29, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"������"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"���β���������"].push_back({ 0, 12, 12, 29, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"üɽ��"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"������"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"�Թ���"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"������"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"������"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"������"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"���Ӳ���Ǽ��������"].push_back({ 0, 12, 12, 29, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"�Ű���"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"����������"].push_back({ 0, 12, 12, 60, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"].push_back({ 0, 12, 12, 19, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"����"].push_back({ 0, 12, 12, 19, 0 });
		//13-20����
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"].push_back({ 12, 20, 20, 50, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"].push_back({ 12, 20, 20, 50, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"������ʡ"].push_back({ 12, 20, 20, 50, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"�Ϻ�"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"ɽ��ʡ"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"�㽭ʡ"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"���ɹ�������"].push_back({ 12, 20, 20, 55, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"����"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"���"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"ɽ��ʡ"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"�ӱ�ʡ"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"����׳��������"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"�㶫ʡ"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"���Ļ���������"].push_back({ 12, 20, 20, 55, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"�½�ά���������"].push_back({ 12, 20, 20, 60, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"].push_back({ 12, 20, 20, 55, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"�ຣʡ"].push_back({ 12, 20, 20, 55, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"��ɽ��"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"�ڽ���"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"��ɽ����������"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"�ϳ���"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"�˱���"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"������"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"��Ԫ��"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"�㰲��"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"������"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"�ɶ���"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"��֦����"].push_back({ 12, 20, 20, 35, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"������"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"���β���������"].push_back({ 12, 20, 20, 35, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"üɽ��"].push_back({ 12, 20, 20, 30, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"������"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"�Թ���"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"������"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"������"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"������"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"���Ӳ���Ǽ��������"].push_back({ 12, 20, 20, 35, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"�Ű���"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"����������"].push_back({ 12, 20, 20, 70, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"].push_back({ 12, 20, 20, 24, 0 });
		g_yongChuangYaoHuiZTKYPrice[L"����"].push_back({ 12, 20, 20, 24, 0 });
		//20��������
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"].push_back({ 20, 0, 20, 50, 2.00 });
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"].push_back({ 20, 0, 20, 50, 2.00 });
		g_yongChuangYaoHuiZTKYPrice[L"������ʡ"].push_back({ 20, 0, 20, 50, 2.00 });
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"].push_back({ 20, 0, 20, 24, 1.20 });
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"].push_back({ 20, 0, 20, 24, 1.20 });
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"].push_back({ 20, 0, 20, 24, 1.20 });
		g_yongChuangYaoHuiZTKYPrice[L"�Ϻ�"].push_back({ 20, 0, 20, 24, 1.20 });
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"].push_back({ 20, 0, 20, 24, 1.20 });
		g_yongChuangYaoHuiZTKYPrice[L"ɽ��ʡ"].push_back({ 20, 0, 20, 24, 1.20 });
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"].push_back({ 20, 0, 20, 24, 1.20 });
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"].push_back({ 20, 0, 20, 24, 1.20 });
		g_yongChuangYaoHuiZTKYPrice[L"�㽭ʡ"].push_back({ 20, 0, 20, 24, 1.20 });
		g_yongChuangYaoHuiZTKYPrice[L"���ɹ�������"].push_back({ 20, 0, 20, 55, 1.80 });
		g_yongChuangYaoHuiZTKYPrice[L"����"].push_back({ 20, 0, 20, 24, 1.20 });
		g_yongChuangYaoHuiZTKYPrice[L"���"].push_back({ 20, 0, 20, 24, 1.20 });
		g_yongChuangYaoHuiZTKYPrice[L"ɽ��ʡ"].push_back({ 20, 0, 20, 24, 1.20 });
		g_yongChuangYaoHuiZTKYPrice[L"�ӱ�ʡ"].push_back({ 20, 0, 20, 24, 1.20 });
		g_yongChuangYaoHuiZTKYPrice[L"����׳��������"].push_back({ 20, 0, 20, 24, 1.20 });
		g_yongChuangYaoHuiZTKYPrice[L"�㶫ʡ"].push_back({ 20, 0, 20, 24, 1.20 });
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"].push_back({ 20, 0, 20, 24, 1.20 });
		g_yongChuangYaoHuiZTKYPrice[L"���Ļ���������"].push_back({ 20, 0, 20, 55, 2.00 });
		g_yongChuangYaoHuiZTKYPrice[L"�½�ά���������"].push_back({ 20, 0, 20, 60, 2.90 });
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"].push_back({ 20, 0, 20, 55, 2.00 });
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"].push_back({ 20, 0, 20, 24, 1.20 });
		g_yongChuangYaoHuiZTKYPrice[L"�ຣʡ"].push_back({ 20, 0, 20, 55, 2.40 });
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"].push_back({ 20, 0, 20, 24, 1.20 });
		g_yongChuangYaoHuiZTKYPrice[L"��ɽ��"].push_back({ 20, 0, 20, 24, 0.80 });
		g_yongChuangYaoHuiZTKYPrice[L"�ڽ���"].push_back({ 20, 0, 20, 24, 0.90 });
		g_yongChuangYaoHuiZTKYPrice[L"��ɽ����������"].push_back({ 20, 0, 20, 24, 1.20 });
		g_yongChuangYaoHuiZTKYPrice[L"�ϳ���"].push_back({ 20, 0, 20, 24, 0.80 });
		g_yongChuangYaoHuiZTKYPrice[L"�˱���"].push_back({ 20, 0, 20, 24, 0.90 });
		g_yongChuangYaoHuiZTKYPrice[L"������"].push_back({ 20, 0, 20, 24, 0.90 });
		g_yongChuangYaoHuiZTKYPrice[L"��Ԫ��"].push_back({ 20, 0, 20, 24, 0.90 });
		g_yongChuangYaoHuiZTKYPrice[L"�㰲��"].push_back({ 20, 0, 20, 24, 0.90 });
		g_yongChuangYaoHuiZTKYPrice[L"������"].push_back({ 20, 0, 20, 24, 0.80 });
		g_yongChuangYaoHuiZTKYPrice[L"�ɶ���"].push_back({ 20, 0, 20, 24, 0.70 });
		g_yongChuangYaoHuiZTKYPrice[L"��֦����"].push_back({ 20, 0, 20, 35, 1.20 });
		g_yongChuangYaoHuiZTKYPrice[L"������"].push_back({ 20, 0, 20, 24, 1.00 });
		g_yongChuangYaoHuiZTKYPrice[L"���β���������"].push_back({ 20, 0, 20, 35, 1.20 });
		g_yongChuangYaoHuiZTKYPrice[L"üɽ��"].push_back({ 20, 0, 20, 30, 0.80 });
		g_yongChuangYaoHuiZTKYPrice[L"������"].push_back({ 20, 0, 20, 24, 0.80 });
		g_yongChuangYaoHuiZTKYPrice[L"�Թ���"].push_back({ 20, 0, 20, 24, 0.90 });
		g_yongChuangYaoHuiZTKYPrice[L"������"].push_back({ 20, 0, 20, 24, 0.80 });
		g_yongChuangYaoHuiZTKYPrice[L"������"].push_back({ 20, 0, 20, 24, 1.00 });
		g_yongChuangYaoHuiZTKYPrice[L"������"].push_back({ 20, 0, 20, 24, 0.80 });
		g_yongChuangYaoHuiZTKYPrice[L"���Ӳ���Ǽ��������"].push_back({ 20, 0, 20, 35, 1.20 });
		g_yongChuangYaoHuiZTKYPrice[L"�Ű���"].push_back({ 20, 0, 20, 24, 0.90 });
		g_yongChuangYaoHuiZTKYPrice[L"����������"].push_back({ 20, 0, 20, 70, 2.80 });
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"].push_back({ 20, 0, 20, 24, 1.20 });
		g_yongChuangYaoHuiZTKYPrice[L"����"].push_back({ 20, 0, 20, 24, 1.00 });
	}
	//����ҫ�Կ�ݼ۸�
	{
		//0-1���� һ�ڼ�
		g_yongChuangYaoHuiKDPrice[L"�Ϻ�"].push_back({ 0, 1, 1, 2.5, 0, 1.3 });
		g_yongChuangYaoHuiKDPrice[L"����"].push_back({ 0, 1, 1, 2.5, 0, 1.3 });
		g_yongChuangYaoHuiKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2.5, 0, 1.3 });
		g_yongChuangYaoHuiKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2.5, 0, 1.3 });
		g_yongChuangYaoHuiKDPrice[L"�㽭ʡ"].push_back({ 0, 1, 1, 2.5, 0, 1.3 });
		g_yongChuangYaoHuiKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2.5, 0, 1.3 });
		g_yongChuangYaoHuiKDPrice[L"ɽ��ʡ"].push_back({ 0, 1, 1, 2.5, 0, 1.3 });
		g_yongChuangYaoHuiKDPrice[L"���"].push_back({ 0, 1, 1, 2.5, 0, 1.3 });
		g_yongChuangYaoHuiKDPrice[L"�ӱ�ʡ"].push_back({ 0, 1, 1, 2.5, 0, 1.3 });
		g_yongChuangYaoHuiKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2.5, 0, 1.3 });
		g_yongChuangYaoHuiKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2.5, 0, 1.3 });
		g_yongChuangYaoHuiKDPrice[L"ɽ��ʡ"].push_back({ 0, 1, 1, 2.5, 0, 1.3 });
		g_yongChuangYaoHuiKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2.5, 0, 1.3 });
		g_yongChuangYaoHuiKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2.5, 0, 1.3 });
		g_yongChuangYaoHuiKDPrice[L"�㶫ʡ"].push_back({ 0, 1, 1, 2.5, 0, 1.3 });
		g_yongChuangYaoHuiKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2.5, 0, 1.3 });
		g_yongChuangYaoHuiKDPrice[L"����׳��������"].push_back({ 0, 1, 1, 2.5, 0, 1.3 });
		g_yongChuangYaoHuiKDPrice[L"�Ĵ�ʡ"].push_back({ 0, 1, 1, 2.5, 0, 1.3 });
		g_yongChuangYaoHuiKDPrice[L"����"].push_back({ 0, 1, 1, 2.5, 0, 1.3 });
		g_yongChuangYaoHuiKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2.5, 0, 1.3 });
		g_yongChuangYaoHuiKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2.5, 0, 1.3 });
		g_yongChuangYaoHuiKDPrice[L"������ʡ"].push_back({ 0, 1, 1, 2.5, 0, 1.3 });
		g_yongChuangYaoHuiKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2.5, 0, 1.3 });
		g_yongChuangYaoHuiKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2.5, 0, 1.3 });
		//1��������
		g_yongChuangYaoHuiKDPrice[L"�Ϻ�"].push_back({ 1, 0, 3, 3, 0.9, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"����"].push_back({ 1, 0, 3, 3, 0.9, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"����ʡ"].push_back({ 1, 0, 3, 3, 0.9, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"����ʡ"].push_back({ 1, 0, 3, 3, 0.9, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"�㽭ʡ"].push_back({ 1, 0, 3, 3, 0.9, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"����ʡ"].push_back({ 1, 0, 3, 3, 0.9, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"ɽ��ʡ"].push_back({ 1, 0, 3, 3, 0.9, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"���"].push_back({ 1, 0, 3, 3, 0.9, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"�ӱ�ʡ"].push_back({ 1, 0, 3, 3, 0.9, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"����ʡ"].push_back({ 1, 0, 3, 3, 0.9, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"����ʡ"].push_back({ 1, 0, 3, 3, 0.9, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"ɽ��ʡ"].push_back({ 1, 0, 3, 3, 0.9, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"����ʡ"].push_back({ 1, 0, 3, 3, 0.9, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"����ʡ"].push_back({ 1, 0, 3, 3, 0.9, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"�㶫ʡ"].push_back({ 1, 0, 3, 3, 0.9, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"����ʡ"].push_back({ 1, 0, 3, 3, 0.9, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"����׳��������"].push_back({ 1, 0, 3, 3, 0.9, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"�Ĵ�ʡ"].push_back({ 1, 0, 3, 3, 0.7, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"����"].push_back({ 1, 0, 3, 3, 0.7, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"����ʡ"].push_back({ 1, 0, 3, 3, 0.9, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"����ʡ"].push_back({ 1, 0, 3, 3, 0.9, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"������ʡ"].push_back({ 1, 0, 3, 3, 1.5, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"����ʡ"].push_back({ 1, 0, 3, 3, 1.5, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"����ʡ"].push_back({ 1, 0, 3, 3, 1.5, 1.3, 0.8 });


		g_yongChuangYaoHuiKDPrice[L"���Ļ���������"].push_back({ 0, 0, 1, 6, 4, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"�ຣʡ"].push_back({ 0, 0, 1, 6, 4, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"����ʡ"].push_back({ 0, 0, 1, 6, 4, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"�½�ά���������"].push_back({ 0, 0, 1, 8, 6, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"����������"].push_back({ 0, 0, 1, 8, 6, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"���ɹ�������"].push_back({ 0, 0, 1, 6, 5, 1.3, 0.8 });
		g_yongChuangYaoHuiKDPrice[L"����ʡ"].push_back({ 0, 0, 1, 5, 4, 1.3, 0.8 });
	}
	//�����ۿ�ݼ۸�
	{
		g_laFengQingKDPrice[L"�Ĵ�ʡ"].push_back({ 0, 0, 3, 2.7, 1 });
		g_laFengQingKDPrice[L"����"].push_back({ 0, 0, 3, 2.7, 1 });
		g_laFengQingKDPrice[L"����ʡ"].push_back({ 0, 0, 3, 2.7, 1.5 });
		g_laFengQingKDPrice[L"����ʡ"].push_back({ 0, 0, 3, 2.7, 1.5 });
		g_laFengQingKDPrice[L"����ʡ"].push_back({ 0, 0, 3, 2.7, 1.5 });
		g_laFengQingKDPrice[L"����ʡ"].push_back({ 0, 0, 3, 2.7, 1.5 });
		g_laFengQingKDPrice[L"�㽭ʡ"].push_back({ 0, 0, 3, 2.7, 1.5 });
		g_laFengQingKDPrice[L"�Ϻ�"].push_back({ 0, 0, 3, 2.7, 1.5 });
		g_laFengQingKDPrice[L"����ʡ"].push_back({ 0, 0, 3, 2.7, 1.5 });
		g_laFengQingKDPrice[L"����ʡ"].push_back({ 0, 0, 3, 2.7, 1.5 });
		g_laFengQingKDPrice[L"����ʡ"].push_back({ 0, 0, 3, 2.7, 1.5 });
		g_laFengQingKDPrice[L"����ʡ"].push_back({ 0, 0, 3, 2.7, 1.5 });
		g_laFengQingKDPrice[L"���"].push_back({ 0, 0, 3, 2.7, 1.5 });
		g_laFengQingKDPrice[L"�㶫ʡ"].push_back({ 0, 0, 3, 2.7, 1.5 });
		g_laFengQingKDPrice[L"����׳��������"].push_back({ 0, 0, 3, 2.7, 1.5 });
		g_laFengQingKDPrice[L"�ӱ�ʡ"].push_back({ 0, 0, 3, 2.7, 1.5 });
		g_laFengQingKDPrice[L"����ʡ"].push_back({ 0, 0, 3, 2.7, 1.5 });
		g_laFengQingKDPrice[L"����ʡ"].push_back({ 0, 0, 3, 2.7, 1.5 });
		g_laFengQingKDPrice[L"ɽ��ʡ"].push_back({ 0, 0, 3, 2.7, 1.5 });
		g_laFengQingKDPrice[L"ɽ��ʡ"].push_back({ 0, 0, 3, 2.7, 1.5 });
		g_laFengQingKDPrice[L"����"].push_back({ 0, 0, 3, 2.7, 1.5 });
		g_laFengQingKDPrice[L"������ʡ"].push_back({ 0, 0, 3, 2.7, 1.5 });
		g_laFengQingKDPrice[L"����ʡ"].push_back({ 0, 0, 3, 2.7, 1.5 });
		g_laFengQingKDPrice[L"����ʡ"].push_back({ 0, 0, 3, 2.7, 1.5 });
		g_laFengQingKDPrice[L"���Ļ���������"].push_back({ 0, 0, 3, 3.1, 2.5 });
		g_laFengQingKDPrice[L"�ຣʡ"].push_back({ 0, 0, 3, 3.1, 2.5 });
		g_laFengQingKDPrice[L"����ʡ"].push_back({ 0, 0, 3, 3.1, 2.5 });
		g_laFengQingKDPrice[L"����ʡ"].push_back({ 0, 0, 3, 3.1, 2.5 });
		g_laFengQingKDPrice[L"���ɹ�������"].push_back({ 0, 0, 3, 3.1, 2.5 });
		//
		g_laFengQingKDPrice[L"�½�ά���������"].push_back({ 0, 0, 1, 7, 7 });
		g_laFengQingKDPrice[L"����������"].push_back({ 0, 0, 1, 12, 12 });
	}
	//���Ƶ��̰������
	{
		//1����
		g_zhiShanBSKDPrice[L"�Ĵ�ʡ"].push_back({ 0, 1, 1, 2.8, 0 });
		g_zhiShanBSKDPrice[L"����"].push_back({ 0, 1, 1, 2.8, 0 });
		g_zhiShanBSKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2.8, 0 });
		g_zhiShanBSKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2.8, 0 });
		g_zhiShanBSKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2.8, 0 });
		g_zhiShanBSKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2.8, 0 });
		g_zhiShanBSKDPrice[L"�㽭ʡ"].push_back({ 0, 1, 1, 2.8, 0 });
		g_zhiShanBSKDPrice[L"�Ϻ�"].push_back({ 0, 1, 1, 2.8, 0 });
		g_zhiShanBSKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2.8, 0 });
		g_zhiShanBSKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2.8, 0 });
		g_zhiShanBSKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2.8, 0 });
		g_zhiShanBSKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2.8, 0 });
		g_zhiShanBSKDPrice[L"���"].push_back({ 0, 1, 1, 2.8, 0 });
		g_zhiShanBSKDPrice[L"�㶫ʡ"].push_back({ 0, 1, 1, 2.8, 0 });
		g_zhiShanBSKDPrice[L"����׳��������"].push_back({ 0, 1, 1, 2.8, 0 });
		g_zhiShanBSKDPrice[L"�ӱ�ʡ"].push_back({ 0, 1, 1, 2.8, 0 });
		g_zhiShanBSKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2.8, 0 });
		g_zhiShanBSKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2.8, 0 });
		g_zhiShanBSKDPrice[L"ɽ��ʡ"].push_back({ 0, 1, 1, 2.8, 0 });
		g_zhiShanBSKDPrice[L"ɽ��ʡ"].push_back({ 0, 1, 1, 2.8, 0 });
		g_zhiShanBSKDPrice[L"����"].push_back({ 0, 1, 1, 2.8, 0 });
		g_zhiShanBSKDPrice[L"������ʡ"].push_back({ 0, 1, 1, 3.8, 0 });
		g_zhiShanBSKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 3.8, 0 });
		g_zhiShanBSKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 3.8, 0 });
		//1-3����
		g_zhiShanBSKDPrice[L"�Ĵ�ʡ"].push_back({ 1, 3, 3, 3.2, 0 });
		g_zhiShanBSKDPrice[L"����"].push_back({ 1, 3, 3, 3.2, 0 });
		g_zhiShanBSKDPrice[L"����ʡ"].push_back({ 1, 3, 3, 3.2, 0 });
		g_zhiShanBSKDPrice[L"����ʡ"].push_back({ 1, 3, 3, 3.2, 0 });
		g_zhiShanBSKDPrice[L"����ʡ"].push_back({ 1, 3, 3, 3.2, 0 });
		g_zhiShanBSKDPrice[L"����ʡ"].push_back({ 1, 3, 3, 3.2, 0 });
		g_zhiShanBSKDPrice[L"�㽭ʡ"].push_back({ 1, 3, 3, 3.2, 0 });
		g_zhiShanBSKDPrice[L"�Ϻ�"].push_back({ 1, 3, 3, 3.2, 0 });
		g_zhiShanBSKDPrice[L"����ʡ"].push_back({ 1, 3, 3, 3.2, 0 });
		g_zhiShanBSKDPrice[L"����ʡ"].push_back({ 1, 3, 3, 3.2, 0 });
		g_zhiShanBSKDPrice[L"����ʡ"].push_back({ 1, 3, 3, 3.2, 0 });
		g_zhiShanBSKDPrice[L"����ʡ"].push_back({ 1, 3, 3, 3.2, 0 });
		g_zhiShanBSKDPrice[L"���"].push_back({ 1, 3, 3, 3.2, 0 });
		g_zhiShanBSKDPrice[L"�㶫ʡ"].push_back({ 1, 3, 3, 3.2, 0 });
		g_zhiShanBSKDPrice[L"����׳��������"].push_back({ 1, 3, 3, 3.2, 0 });
		g_zhiShanBSKDPrice[L"�ӱ�ʡ"].push_back({ 1, 3, 3, 3.2, 0 });
		g_zhiShanBSKDPrice[L"����ʡ"].push_back({ 1, 3, 3, 3.2, 0 });
		g_zhiShanBSKDPrice[L"����ʡ"].push_back({ 1, 3, 3, 3.2, 0 });
		g_zhiShanBSKDPrice[L"ɽ��ʡ"].push_back({ 1, 3, 3, 3.2, 0 });
		g_zhiShanBSKDPrice[L"ɽ��ʡ"].push_back({ 1, 3, 3, 3.2, 0 });
		g_zhiShanBSKDPrice[L"����"].push_back({ 1, 3, 3, 3.2, 0 });
		g_zhiShanBSKDPrice[L"������ʡ"].push_back({ 1, 3, 3, 4.2, 0 });
		g_zhiShanBSKDPrice[L"����ʡ"].push_back({ 1, 3, 3, 4.2, 0 });
		g_zhiShanBSKDPrice[L"����ʡ"].push_back({ 1, 3, 3, 4.2, 0 });
		//3��������
		g_zhiShanBSKDPrice[L"�Ĵ�ʡ"].push_back({ 3, 0, 3, 3, 1 });
		g_zhiShanBSKDPrice[L"����"].push_back({ 3, 0, 3, 3, 1.3 });
		g_zhiShanBSKDPrice[L"����ʡ"].push_back({ 3, 0, 3, 3, 1.3 });
		g_zhiShanBSKDPrice[L"����ʡ"].push_back({ 3, 0, 3, 3, 1.3 });
		g_zhiShanBSKDPrice[L"����ʡ"].push_back({ 3, 0, 3, 3, 1.3 });
		g_zhiShanBSKDPrice[L"����ʡ"].push_back({ 3, 0, 3, 3, 1.3 });
		g_zhiShanBSKDPrice[L"�㽭ʡ"].push_back({ 3, 0, 3, 3, 1.3 });
		g_zhiShanBSKDPrice[L"�Ϻ�"].push_back({ 3, 0, 3, 3, 1.3 });
		g_zhiShanBSKDPrice[L"����ʡ"].push_back({ 3, 0, 3, 3, 1.3 });
		g_zhiShanBSKDPrice[L"����ʡ"].push_back({ 3, 0, 3, 3, 1.3 });
		g_zhiShanBSKDPrice[L"����ʡ"].push_back({ 3, 0, 3, 3, 1.3 });
		g_zhiShanBSKDPrice[L"����ʡ"].push_back({ 3, 0, 3, 3, 1.3 });
		g_zhiShanBSKDPrice[L"���"].push_back({ 3, 0, 3, 3, 1.3 });
		g_zhiShanBSKDPrice[L"�㶫ʡ"].push_back({ 3, 0, 3, 3, 1.3 });
		g_zhiShanBSKDPrice[L"����׳��������"].push_back({ 3, 0, 3, 3, 1.3 });
		g_zhiShanBSKDPrice[L"�ӱ�ʡ"].push_back({ 3, 0, 3, 3, 1.3 });
		g_zhiShanBSKDPrice[L"����ʡ"].push_back({ 3, 0, 3, 3, 1.3 });
		g_zhiShanBSKDPrice[L"����ʡ"].push_back({ 3, 0, 3, 3, 1.3 });
		g_zhiShanBSKDPrice[L"ɽ��ʡ"].push_back({ 3, 0, 3, 3, 1.3 });
		g_zhiShanBSKDPrice[L"ɽ��ʡ"].push_back({ 3, 0, 3, 3, 1.3 });
		g_zhiShanBSKDPrice[L"����"].push_back({ 3, 0, 3, 3, 1.3 });
		g_zhiShanBSKDPrice[L"������ʡ"].push_back({ 3, 0, 3, 5, 2 });
		g_zhiShanBSKDPrice[L"����ʡ"].push_back({ 3, 0, 3, 5, 2 });
		g_zhiShanBSKDPrice[L"����ʡ"].push_back({ 3, 0, 3, 5, 2 });

		g_zhiShanBSKDPrice[L"���Ļ���������"].push_back({ 0, 0, 1, 7, 5 });
		g_zhiShanBSKDPrice[L"�ຣʡ"].push_back({ 0, 0, 1, 7, 5 });
		g_zhiShanBSKDPrice[L"����ʡ"].push_back({ 0, 0, 1, 7, 5 });
		g_zhiShanBSKDPrice[L"����ʡ"].push_back({ 0, 0, 1, 6, 5 });
		g_zhiShanBSKDPrice[L"���ɹ�������"].push_back({ 0, 0, 1, 7, 6 });
		g_zhiShanBSKDPrice[L"�½�ά���������"].push_back({ 0, 0, 1, 9, 7 });
		g_zhiShanBSKDPrice[L"����������"].push_back({ 0, 0, 1, 9, 7 });
	}
	//���Ƶ����������
	{
		
		//1����
		g_zhiShanQTKDPrice[L"�Ĵ�ʡ"].push_back({ 0, 1, 1, 3.2, 0 });
		g_zhiShanQTKDPrice[L"����"].push_back({ 0, 1, 1, 3.2, 0 });
		g_zhiShanQTKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 3.2, 0 });
		g_zhiShanQTKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 3.2, 0 });
		g_zhiShanQTKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 3.2, 0 });
		g_zhiShanQTKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 3.2, 0 });
		g_zhiShanQTKDPrice[L"�㽭ʡ"].push_back({ 0, 1, 1, 3.2, 0 });
		
		g_zhiShanQTKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 3.2, 0 });
		g_zhiShanQTKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 3.2, 0 });
		g_zhiShanQTKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 3.2, 0 });
		g_zhiShanQTKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 3.2, 0 });
		g_zhiShanQTKDPrice[L"���"].push_back({ 0, 1, 1, 3.2, 0 });
		g_zhiShanQTKDPrice[L"�㶫ʡ"].push_back({ 0, 1, 1, 3.2, 0 });
		g_zhiShanQTKDPrice[L"����׳��������"].push_back({ 0, 1, 1, 3.2, 0 });
		g_zhiShanQTKDPrice[L"�ӱ�ʡ"].push_back({ 0, 1, 1, 3.2, 0 });
		g_zhiShanQTKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 3.2, 0 });
		g_zhiShanQTKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 3.2, 0 });
		g_zhiShanQTKDPrice[L"ɽ��ʡ"].push_back({ 0, 1, 1, 3.2, 0 });
		g_zhiShanQTKDPrice[L"ɽ��ʡ"].push_back({ 0, 1, 1, 3.2, 0 });

		g_zhiShanQTKDPrice[L"������ʡ"].push_back({ 0, 1, 1, 3.2, 0 });
		g_zhiShanQTKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 3.2, 0 });
		g_zhiShanQTKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 3.2, 0 });
		g_zhiShanQTKDPrice[L"���Ļ���������"].push_back({ 0, 1, 1, 3.2, 0 });
		g_zhiShanQTKDPrice[L"�ຣʡ"].push_back({ 0, 1, 1, 3.2, 0 });
		g_zhiShanQTKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 3.2, 0 });

		g_zhiShanQTKDPrice[L"����"].push_back({ 0, 1, 1, 4, 0 });
		g_zhiShanQTKDPrice[L"�Ϻ�"].push_back({ 0, 1, 1, 3.8, 0 });
		//3kg
		g_zhiShanQTKDPrice[L"�Ĵ�ʡ"].push_back({ 1, 3, 3, 3.7, 0 });
		g_zhiShanQTKDPrice[L"����"].push_back({ 1, 3, 3, 3.7, 0 });
		g_zhiShanQTKDPrice[L"����ʡ"].push_back({ 1, 3, 3, 3.7, 0 });
		g_zhiShanQTKDPrice[L"����ʡ"].push_back({ 1, 3, 3, 3.7, 0 });
		g_zhiShanQTKDPrice[L"����ʡ"].push_back({ 1, 3, 3, 3.7, 0 });
		g_zhiShanQTKDPrice[L"����ʡ"].push_back({ 1, 3, 3, 3.7, 0 });
		g_zhiShanQTKDPrice[L"�㽭ʡ"].push_back({ 1, 3, 3, 3.7, 0 });

		g_zhiShanQTKDPrice[L"����ʡ"].push_back({ 1, 3, 3, 3.7, 0 });
		g_zhiShanQTKDPrice[L"����ʡ"].push_back({ 1, 3, 3, 3.7, 0 });
		g_zhiShanQTKDPrice[L"����ʡ"].push_back({ 1, 3, 3, 3.7, 0 });
		g_zhiShanQTKDPrice[L"����ʡ"].push_back({ 1, 3, 3, 3.7, 0 });
		g_zhiShanQTKDPrice[L"���"].push_back({ 1, 3, 3, 3.7, 0 });
		g_zhiShanQTKDPrice[L"�㶫ʡ"].push_back({ 1, 3, 3, 3.7, 0 });
		g_zhiShanQTKDPrice[L"����׳��������"].push_back({ 1, 3, 3, 3.7, 0 });
		g_zhiShanQTKDPrice[L"�ӱ�ʡ"].push_back({ 1, 3, 3, 3.7, 0 });
		g_zhiShanQTKDPrice[L"����ʡ"].push_back({ 1, 3, 3, 3.7, 0 });
		g_zhiShanQTKDPrice[L"����ʡ"].push_back({ 1, 3, 3, 3.7, 0 });
		g_zhiShanQTKDPrice[L"ɽ��ʡ"].push_back({ 1, 3, 3, 3.7, 0 });
		g_zhiShanQTKDPrice[L"ɽ��ʡ"].push_back({ 1, 3, 3, 3.7, 0 });

		g_zhiShanQTKDPrice[L"������ʡ"].push_back({ 1, 3, 3, 3.7, 0 });
		g_zhiShanQTKDPrice[L"����ʡ"].push_back({ 1, 3, 3, 3.7, 0 });
		g_zhiShanQTKDPrice[L"����ʡ"].push_back({ 1, 3, 3, 3.7, 0 });
		g_zhiShanQTKDPrice[L"���Ļ���������"].push_back({ 1, 3, 3, 3.7, 0 });
		g_zhiShanQTKDPrice[L"�ຣʡ"].push_back({ 1, 3, 3, 3.7, 0 });
		g_zhiShanQTKDPrice[L"����ʡ"].push_back({ 1, 3, 3, 3.7, 0 });

		g_zhiShanQTKDPrice[L"�Ϻ�"].push_back({ 1, 3, 3, 4.3, 0 });
		g_zhiShanQTKDPrice[L"����"].push_back({ 1, 3, 3, 4.5, 0 });
		//3-5kg
		g_zhiShanQTKDPrice[L"�Ĵ�ʡ"].push_back({ 3, 5, 5, 6, 0 });
		g_zhiShanQTKDPrice[L"����"].push_back({ 3, 5, 5, 6, 0 });
		g_zhiShanQTKDPrice[L"����ʡ"].push_back({ 3, 5, 5, 6, 0 });
		g_zhiShanQTKDPrice[L"����ʡ"].push_back({ 3, 5, 5, 6, 0 });
		g_zhiShanQTKDPrice[L"����ʡ"].push_back({ 3, 5, 5, 6, 0 });
		g_zhiShanQTKDPrice[L"����ʡ"].push_back({ 3, 5, 5, 6, 0 });
		g_zhiShanQTKDPrice[L"�㽭ʡ"].push_back({ 3, 5, 5, 6, 0 });

		g_zhiShanQTKDPrice[L"����ʡ"].push_back({ 3, 5, 5, 6, 0 });
		g_zhiShanQTKDPrice[L"����ʡ"].push_back({ 3, 5, 5, 6, 0 });
		g_zhiShanQTKDPrice[L"����ʡ"].push_back({ 3, 5, 5, 6, 0 });
		g_zhiShanQTKDPrice[L"����ʡ"].push_back({ 3, 5, 5, 6, 0 });
		g_zhiShanQTKDPrice[L"���"].push_back({ 3, 5, 5, 6, 0 });
		g_zhiShanQTKDPrice[L"�㶫ʡ"].push_back({ 3, 5, 5, 6, 0 });
		g_zhiShanQTKDPrice[L"����׳��������"].push_back({ 3, 5, 5, 6, 0 });
		g_zhiShanQTKDPrice[L"�ӱ�ʡ"].push_back({ 3, 5, 5, 6, 0 });
		g_zhiShanQTKDPrice[L"����ʡ"].push_back({ 3, 5, 5, 6, 0 });
		g_zhiShanQTKDPrice[L"����ʡ"].push_back({ 3, 5, 5, 6, 0 });
		g_zhiShanQTKDPrice[L"ɽ��ʡ"].push_back({ 3, 5, 5, 6, 0 });
		g_zhiShanQTKDPrice[L"ɽ��ʡ"].push_back({ 3, 5, 5, 6, 0 });

		g_zhiShanQTKDPrice[L"������ʡ"].push_back({ 3, 5, 5, 6.5, 0 });
		g_zhiShanQTKDPrice[L"����ʡ"].push_back({ 3, 5, 5, 6.5, 0 });
		g_zhiShanQTKDPrice[L"����ʡ"].push_back({ 3, 5, 5, 6.5, 0 });
		g_zhiShanQTKDPrice[L"���Ļ���������"].push_back({ 3, 5, 5, 6.5, 0 });
		g_zhiShanQTKDPrice[L"�ຣʡ"].push_back({ 3, 5, 5, 6.5, 0 });
		g_zhiShanQTKDPrice[L"����ʡ"].push_back({ 3, 5, 5, 6.5, 0 });

		g_zhiShanQTKDPrice[L"�Ϻ�"].push_back({ 3, 5, 5, 6, 0 });
		g_zhiShanQTKDPrice[L"����"].push_back({ 3, 5, 5, 6.5, 0 });
		//5kg����
		g_zhiShanQTKDPrice[L"�Ĵ�ʡ"].push_back({ 5, 0, 1, 4.7, 1.3 });
		g_zhiShanQTKDPrice[L"����"].push_back({ 5, 0, 1, 4.7, 1.3 });
		g_zhiShanQTKDPrice[L"����ʡ"].push_back({ 5, 0, 1, 5.5, 1.8 });
		g_zhiShanQTKDPrice[L"����ʡ"].push_back({ 5, 0, 1, 5.5, 1.8 });
		g_zhiShanQTKDPrice[L"����ʡ"].push_back({ 5, 0, 1, 5.5, 1.8 });
		g_zhiShanQTKDPrice[L"����ʡ"].push_back({ 5, 0, 1, 5.5, 1.8 });
		g_zhiShanQTKDPrice[L"�㽭ʡ"].push_back({ 5, 0, 1, 5.5, 1.8 });

		g_zhiShanQTKDPrice[L"����ʡ"].push_back({ 5, 0, 1, 5.5, 1.8 });
		g_zhiShanQTKDPrice[L"����ʡ"].push_back({ 5, 0, 1, 5.5, 1.8 });
		g_zhiShanQTKDPrice[L"����ʡ"].push_back({ 5, 0, 1, 5.5, 1.8 });
		g_zhiShanQTKDPrice[L"����ʡ"].push_back({ 5, 0, 1, 5.5, 1.8 });
		g_zhiShanQTKDPrice[L"���"].push_back({ 5, 0, 1, 5.5, 1.8 });
		g_zhiShanQTKDPrice[L"�㶫ʡ"].push_back({ 5, 0, 1, 5.5, 1.8 });
		g_zhiShanQTKDPrice[L"����׳��������"].push_back({ 5, 0, 1, 5.5, 1.8 });
		g_zhiShanQTKDPrice[L"�ӱ�ʡ"].push_back({ 5, 0, 1, 5.5, 1.8 });
		g_zhiShanQTKDPrice[L"����ʡ"].push_back({ 5, 0, 1, 5.5, 1.8 });
		g_zhiShanQTKDPrice[L"����ʡ"].push_back({ 5, 0, 1, 5.5, 1.8 });
		g_zhiShanQTKDPrice[L"ɽ��ʡ"].push_back({ 5, 0, 1, 5.5, 1.8 });
		g_zhiShanQTKDPrice[L"ɽ��ʡ"].push_back({ 5, 0, 1, 5.5, 1.8 });

		g_zhiShanQTKDPrice[L"������ʡ"].push_back({ 5, 0, 1, 7, 3.8 });
		g_zhiShanQTKDPrice[L"����ʡ"].push_back({ 5, 0, 1, 7, 3.8 });
		g_zhiShanQTKDPrice[L"����ʡ"].push_back({ 5, 0, 1, 7, 3.8 });
		g_zhiShanQTKDPrice[L"���Ļ���������"].push_back({ 5, 0, 1, 7, 3.8 });
		g_zhiShanQTKDPrice[L"�ຣʡ"].push_back({ 5, 0, 1, 7, 3.8 });
		g_zhiShanQTKDPrice[L"����ʡ"].push_back({ 5, 0, 1, 7, 3.8 });

		g_zhiShanQTKDPrice[L"�Ϻ�"].push_back({ 5, 0, 1, 5.5, 2.2 });
		g_zhiShanQTKDPrice[L"����"].push_back({ 5, 0, 1, 6, 2.7 });


		g_zhiShanQTKDPrice[L"����ʡ"].push_back({ 0, 0, 1, 10, 5.7 });
		g_zhiShanQTKDPrice[L"���ɹ�������"].push_back({ 0, 0, 1, 10, 5.7 });
		g_zhiShanQTKDPrice[L"�½�ά���������"].push_back({ 0, 0, 1, 11, 7.5 });
		g_zhiShanQTKDPrice[L"����������"].push_back({ 0, 0, 1, 11, 7.5 });

	}
	//ά���ϴ���
	{
		//3����
		g_weiFuKangYDKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 2.9, 0 });
		g_weiFuKangYDKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 2.9, 0 });
		g_weiFuKangYDKDPrice[L"�㽭ʡ"].push_back({ 0, 3, 3, 2.9, 0 });
		g_weiFuKangYDKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 2.9, 0 });
		g_weiFuKangYDKDPrice[L"ɽ��ʡ"].push_back({ 0, 3, 3, 2.9, 0 });
		g_weiFuKangYDKDPrice[L"���"].push_back({ 0, 3, 3, 2.9, 0 });
		g_weiFuKangYDKDPrice[L"�ӱ�ʡ"].push_back({ 0, 3, 3, 2.9, 0 });
		g_weiFuKangYDKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 2.9, 0 });
		g_weiFuKangYDKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 2.9, 0 });
		g_weiFuKangYDKDPrice[L"ɽ��ʡ"].push_back({ 0, 3, 3, 2.9, 0 });
		g_weiFuKangYDKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 2.9, 0 });
		g_weiFuKangYDKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 2.9, 0 });
		g_weiFuKangYDKDPrice[L"�㶫ʡ"].push_back({ 0, 3, 3, 2.9, 0 });
		g_weiFuKangYDKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 2.9, 0 });
		g_weiFuKangYDKDPrice[L"����׳��������"].push_back({ 0, 3, 3, 2.9, 0 });
		g_weiFuKangYDKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 2.9, 0 });
		g_weiFuKangYDKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 2.9, 0 });
		g_weiFuKangYDKDPrice[L"����"].push_back({ 0, 3, 3, 2.9, 0 });

		g_weiFuKangYDKDPrice[L"�Ĵ�ʡ"].push_back({ 0, 3, 3, 2.8, 0 });

		g_weiFuKangYDKDPrice[L"������ʡ"].push_back({ 0, 3, 3, 4, 0 });
		g_weiFuKangYDKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 4, 0 });
		g_weiFuKangYDKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 4, 0 });
		
		g_weiFuKangYDKDPrice[L"������"].push_back({ 0, 3, 3, 4, 0 });
		g_weiFuKangYDKDPrice[L"�Ϻ�"].push_back({ 0, 3, 3, 4, 0 });
		g_weiFuKangYDKDPrice[L"����"].push_back({ 0, 3, 3, 4, 0 });
		//3��������
		g_weiFuKangYDKDPrice[L"����ʡ"].push_back({ 3, 0, 3, 4, 1.3 });
		g_weiFuKangYDKDPrice[L"����ʡ"].push_back({ 3, 0, 3, 4, 1.3 });
		g_weiFuKangYDKDPrice[L"�㽭ʡ"].push_back({ 3, 0, 3, 4, 1.3 });
		g_weiFuKangYDKDPrice[L"����ʡ"].push_back({ 3, 0, 3, 4, 1.3 });
		g_weiFuKangYDKDPrice[L"ɽ��ʡ"].push_back({ 3, 0, 3, 4, 1.3 });
		g_weiFuKangYDKDPrice[L"���"].push_back({ 3, 0, 3, 4, 1.3 });
		g_weiFuKangYDKDPrice[L"�ӱ�ʡ"].push_back({ 3, 0, 3, 4, 1.3 });
		g_weiFuKangYDKDPrice[L"����ʡ"].push_back({ 3, 0, 3, 4, 1.3 });
		g_weiFuKangYDKDPrice[L"����ʡ"].push_back({ 3, 0, 3, 4, 1.3 });
		g_weiFuKangYDKDPrice[L"ɽ��ʡ"].push_back({ 3, 0, 3, 4, 1.3 });
		g_weiFuKangYDKDPrice[L"����ʡ"].push_back({ 3, 0, 3, 4, 1.3 });
		g_weiFuKangYDKDPrice[L"����ʡ"].push_back({ 3, 0, 3, 4, 1.3 });
		g_weiFuKangYDKDPrice[L"�㶫ʡ"].push_back({ 3, 0, 3, 4, 1.3 });
		g_weiFuKangYDKDPrice[L"����ʡ"].push_back({ 3, 0, 3, 4, 1.3 });
		g_weiFuKangYDKDPrice[L"����׳��������"].push_back({ 3, 0, 3, 4, 1.3 });
		g_weiFuKangYDKDPrice[L"����ʡ"].push_back({ 3, 0, 3, 4, 1.3 });
		g_weiFuKangYDKDPrice[L"����ʡ"].push_back({ 3, 0, 3, 4, 1.3 });
		g_weiFuKangYDKDPrice[L"����"].push_back({ 3, 0, 3, 4, 1.3 });

		g_weiFuKangYDKDPrice[L"�Ĵ�ʡ"].push_back({ 3, 0, 3, 4, 1 });

		g_weiFuKangYDKDPrice[L"������ʡ"].push_back({ 3, 0, 3, 5, 2.5 });
		g_weiFuKangYDKDPrice[L"����ʡ"].push_back({ 3, 0, 3, 5, 2.5 });
		g_weiFuKangYDKDPrice[L"����ʡ"].push_back({ 3, 0, 3, 5, 2.5 });

		g_weiFuKangYDKDPrice[L"������"].push_back({ 3, 0, 3, 4, 1.3 });
		g_weiFuKangYDKDPrice[L"�Ϻ�"].push_back({ 3, 0, 3, 4, 1.3 });
		g_weiFuKangYDKDPrice[L"����"].push_back({ 3, 0, 3, 4, 1.3 });
		//��������
		g_weiFuKangYDKDPrice[L"�½�ά���������"].push_back({ 0, 0, 1, 16, 4 });
		g_weiFuKangYDKDPrice[L"����������"].push_back({ 0, 0, 1, 9, 7 });
		g_weiFuKangYDKDPrice[L"���Ļ���������"].push_back({ 0, 0, 1, 7, 5 });
		g_weiFuKangYDKDPrice[L"�ຣʡ"].push_back({ 0, 0, 1, 7, 5 });
		g_weiFuKangYDKDPrice[L"����ʡ"].push_back({ 0, 0, 1, 7, 5 });
		g_weiFuKangYDKDPrice[L"���ɹ�������"].push_back({ 0, 0, 1, 8, 6 });
		g_weiFuKangYDKDPrice[L"����ʡ"].push_back({ 0, 0, 1, 6, 5 });
	}
	{
		g_weiFuKangZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  27,	1.3 });
		g_weiFuKangZTKYPrice[L"����"].push_back({ 0, 0, 20,  27, 1.3 });
		g_weiFuKangZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  27,	1.3 });
		g_weiFuKangZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  37,	1.8 });
		g_weiFuKangZTKYPrice[L"�㶫ʡ"].push_back({ 0, 0, 20,  27,	1.3 });
		g_weiFuKangZTKYPrice[L"����׳��������"].push_back({ 0, 0, 20,  27,	1.3 });
		g_weiFuKangZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  27,	1.3 });
		g_weiFuKangZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  44,	2.2 });
		g_weiFuKangZTKYPrice[L"�ӱ�ʡ"].push_back({ 0, 0, 20,  27,	1.3 });
		g_weiFuKangZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  27,	1.3 });
		g_weiFuKangZTKYPrice[L"������ʡ"].push_back({ 0, 0, 20,  39, 1.7 });
		g_weiFuKangZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  27, 1.3 });
		g_weiFuKangZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  27, 1.3 });
		g_weiFuKangZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  39,	1.7 });
		g_weiFuKangZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  27,	1.3 });
		g_weiFuKangZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  27,	1.3 });
		g_weiFuKangZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  39,	1.7 });
		g_weiFuKangZTKYPrice[L"���ɹ�������"].push_back({ 0, 0, 20,  44, 1.7 });
		g_weiFuKangZTKYPrice[L"���Ļ���������"].push_back({ 0, 0, 20,  44,	1.7 });
		g_weiFuKangZTKYPrice[L"�ຣʡ"].push_back({ 0, 0, 20,  44,	1.7 });
		g_weiFuKangZTKYPrice[L"ɽ��ʡ"].push_back({ 0, 0, 20,  27,	1.3 });
		g_weiFuKangZTKYPrice[L"ɽ��ʡ"].push_back({ 0, 0, 20,  27,	1.3 });
		g_weiFuKangZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  27,	1.3 });
		g_weiFuKangZTKYPrice[L"�Ϻ�"].push_back({ 0, 0, 20,  29, 1.3 });
		g_weiFuKangZTKYPrice[L"���"].push_back({ 0, 0, 20,  29, 1.3 });
		g_weiFuKangZTKYPrice[L"����������"].push_back({ 0, 0, 20,  74, 3.2 });
		g_weiFuKangZTKYPrice[L"�½�ά���������"].push_back({ 0, 0, 20,  54, 3.2 });
		g_weiFuKangZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  34,	1.3 });
		g_weiFuKangZTKYPrice[L"�㽭ʡ"].push_back({ 0, 0, 20,  27,	1.3 });
		g_weiFuKangZTKYPrice[L"�Ĵ�ʡ"].push_back({ 0, 0, 20,  23, 1.1 });
		g_weiFuKangZTKYPrice[L"���Ӳ���Ǽ��������"].push_back({ 0, 0, 20,  54,	1.7 });
		g_weiFuKangZTKYPrice[L"���β���������"].push_back({ 0, 0, 20,  54,	1.7 });
		g_weiFuKangZTKYPrice[L"��ɽ����������"].push_back({ 0, 0, 20,  54,	1.7 });
		g_weiFuKangZTKYPrice[L"������"].push_back({ 0, 0, 20,  24,	1 });
		g_weiFuKangZTKYPrice[L"üɽ��"].push_back({ 0, 0, 20,  24,	1 });
		g_weiFuKangZTKYPrice[L"������"].push_back({ 0, 0, 20,  24,	1 });
		g_weiFuKangZTKYPrice[L"�ϳ���"].push_back({ 0, 0, 20,  24,	1 });
		g_weiFuKangZTKYPrice[L"�ڽ���"].push_back({ 0, 0, 20,  24,	1 });
		g_weiFuKangZTKYPrice[L"��֦����"].push_back({ 0, 0, 20,  24, 1.2 });
		g_weiFuKangZTKYPrice[L"������"].push_back({ 0, 0, 20,  24,	1 });
		g_weiFuKangZTKYPrice[L"�Ű���"].push_back({ 0, 0, 20,  24,	1 });
		g_weiFuKangZTKYPrice[L"�˱���"].push_back({ 0, 0, 20,  24,	1 });
		g_weiFuKangZTKYPrice[L"������"].push_back({ 0, 0, 20,  24,	1 });
		g_weiFuKangZTKYPrice[L"�Թ���"].push_back({ 0, 0, 20,  24,	1 });
		g_weiFuKangZTKYPrice[L"����"].push_back({ 0, 0, 20,  27, 1.2 });
	}
		
	//�������ͨ����
	{
		g_xinMaBangZTKYPrice[L"�Ϻ�"].push_back({ 0, 0, 20,  27, 1.3 });
		g_xinMaBangZTKYPrice[L"����"].push_back({ 0, 0, 20,  27, 1.3 });
		g_xinMaBangZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  27, 1.3 });
		g_xinMaBangZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  27, 1.3 });
		g_xinMaBangZTKYPrice[L"�㽭ʡ"].push_back({ 0, 0, 20,  27, 1.3 });
		g_xinMaBangZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  27, 1.3 });
		g_xinMaBangZTKYPrice[L"ɽ��ʡ"].push_back({ 0, 0, 20,  27, 1.3 });
		g_xinMaBangZTKYPrice[L"���"].push_back({ 0, 0, 20,  27, 1.3 });
		g_xinMaBangZTKYPrice[L"�ӱ�ʡ"].push_back({ 0, 0, 20,  27, 1.3 });
		g_xinMaBangZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  27, 1.3 });
		g_xinMaBangZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  27, 1.3 });
		g_xinMaBangZTKYPrice[L"ɽ��ʡ"].push_back({ 0, 0, 20,  27, 1.3 });
		g_xinMaBangZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  27, 1.3 });
		g_xinMaBangZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  27, 1.3 });
		g_xinMaBangZTKYPrice[L"�㶫ʡ"].push_back({ 0, 0, 20,  27, 1.3 });
		g_xinMaBangZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  27, 1.3 });
		g_xinMaBangZTKYPrice[L"����׳��������"].push_back({ 0, 0, 20,  27, 1.3 });
		g_xinMaBangZTKYPrice[L"�Ĵ�ʡ"].push_back({ 0, 0, 20,  23, 1.1 });
		g_xinMaBangZTKYPrice[L"���β���������"].push_back({ 0, 0, 20,  52, 1.5 });
		g_xinMaBangZTKYPrice[L"���Ӳ���Ǽ��������"].push_back({ 0, 0, 20,  52, 1.5 });
		g_xinMaBangZTKYPrice[L"��ɽ����������"].push_back({ 0, 0, 20,  52, 1.5 });
		g_xinMaBangZTKYPrice[L"����"].push_back({ 0, 0, 20,  27, 1.2 });
		g_xinMaBangZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  27, 1.4 });
		g_xinMaBangZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  27, 1.4 });
		g_xinMaBangZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  35, 3 });
		g_xinMaBangZTKYPrice[L"���Ļ���������"].push_back({ 0, 0, 20,  45, 2.8 });
		g_xinMaBangZTKYPrice[L"�ຣʡ"].push_back({ 0, 0, 20,  45, 2.8 });
		g_xinMaBangZTKYPrice[L"������ʡ"].push_back({ 0, 0, 20,  37, 1.6 });
		g_xinMaBangZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  37, 1.6 });
		g_xinMaBangZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  37, 1.6 });
		g_xinMaBangZTKYPrice[L"���ɹ�������"].push_back({ 0, 0, 20,  75, 3 });
		g_xinMaBangZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  42, 2.7 });
		g_xinMaBangZTKYPrice[L"�½�ά���������"].push_back({ 0, 0, 20,  85, 3.2 });
		g_xinMaBangZTKYPrice[L"����������"].push_back({ 0, 0, 20,  75, 4.2 });
	}
	//����Ƽ���ͨ����
	{
		g_yiMaiKeJiZTKYPrice[L"�Ĵ�ʡ"].push_back({ 0, 0, 20,  25, 1.1 });
		g_yiMaiKeJiZTKYPrice[L"���β���������"].push_back({ 0, 0, 20,  25, 1.5 });
		g_yiMaiKeJiZTKYPrice[L"���Ӳ���Ǽ��������"].push_back({ 0, 0, 20,  25, 1.5 });
		g_yiMaiKeJiZTKYPrice[L"��ɽ����������"].push_back({ 0, 0, 20,  25, 1.5 });
		g_yiMaiKeJiZTKYPrice[L"�Ϻ�"].push_back({ 0, 0, 20,  28, 1.5 });
		g_yiMaiKeJiZTKYPrice[L"����"].push_back({ 0, 0, 20,  28, 1.5 });
		g_yiMaiKeJiZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  28, 1.5 });
		g_yiMaiKeJiZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  28, 1.5 });
		g_yiMaiKeJiZTKYPrice[L"�㽭ʡ"].push_back({ 0, 0, 20,  28, 1.5 });
		g_yiMaiKeJiZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  28, 1.5 });
		g_yiMaiKeJiZTKYPrice[L"ɽ��ʡ"].push_back({ 0, 0, 20,  28, 1.5 });
		g_yiMaiKeJiZTKYPrice[L"���"].push_back({ 0, 0, 20,  28, 1.5 });
		g_yiMaiKeJiZTKYPrice[L"�ӱ�ʡ"].push_back({ 0, 0, 20,  28, 1.5 });
		g_yiMaiKeJiZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  28, 1.5 });
		g_yiMaiKeJiZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  28, 1.5 });
		g_yiMaiKeJiZTKYPrice[L"ɽ��ʡ"].push_back({ 0, 0, 20,  28, 1.5 });
		g_yiMaiKeJiZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  28, 1.5 });
		g_yiMaiKeJiZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  28, 1.5 });
		g_yiMaiKeJiZTKYPrice[L"�㶫ʡ"].push_back({ 0, 0, 20,  28, 1.5 });
		g_yiMaiKeJiZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  28, 1.5 });
		g_yiMaiKeJiZTKYPrice[L"����׳��������"].push_back({ 0, 0, 20,  28, 1.5 });
		g_yiMaiKeJiZTKYPrice[L"����"].push_back({ 0, 0, 20,  28, 1.3 });
		g_yiMaiKeJiZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  28, 1.5 });
		g_yiMaiKeJiZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  28, 1.5 });
		g_yiMaiKeJiZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  28, 3 });
		g_yiMaiKeJiZTKYPrice[L"�ຣʡ"].push_back({ 0, 0, 20,  75, 3 });
		g_yiMaiKeJiZTKYPrice[L"������ʡ"].push_back({ 0, 0, 20,  28, 1.8 });
		g_yiMaiKeJiZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  28, 1.8 });
		g_yiMaiKeJiZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  28, 1.8 });
		g_yiMaiKeJiZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  28, 3 });
		g_yiMaiKeJiZTKYPrice[L"�½�ά���������"].push_back({ 0, 0, 20,  85, 3.5 });
		g_yiMaiKeJiZTKYPrice[L"����������"].push_back({ 0, 0, 20,  65, 4.5 });
		g_yiMaiKeJiZTKYPrice[L"���Ļ���������"].push_back({ 0, 0, 20,  54, 3 });
		g_yiMaiKeJiZTKYPrice[L"���ɹ�������"].push_back({ 0, 0, 20,  75, 3.5 });
	}
	//������ͨ����
	{
		g_miYaZTKYPrice[L"�Ϻ�"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_miYaZTKYPrice[L"����"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_miYaZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_miYaZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_miYaZTKYPrice[L"�㽭ʡ"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_miYaZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_miYaZTKYPrice[L"ɽ��ʡ"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_miYaZTKYPrice[L"���"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_miYaZTKYPrice[L"�ӱ�ʡ"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_miYaZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_miYaZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_miYaZTKYPrice[L"ɽ��ʡ"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_miYaZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_miYaZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_miYaZTKYPrice[L"�㶫ʡ"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_miYaZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_miYaZTKYPrice[L"����׳��������"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_miYaZTKYPrice[L"�Ĵ�ʡ"].push_back({ 0, 0, 20,  22.5, 1 });
		g_miYaZTKYPrice[L"���β���������"].push_back({ 0, 0, 20,  50, 1.6 });
		g_miYaZTKYPrice[L"���Ӳ���Ǽ��������"].push_back({ 0, 0, 20,  50, 1.6 });
		g_miYaZTKYPrice[L"��ɽ����������"].push_back({ 0, 0, 20,  50, 1.6 });
		g_miYaZTKYPrice[L"����"].push_back({ 0, 0, 20,  27.5, 1.2 });
		g_miYaZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  32, 1.4 });
		g_miYaZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  27.5, 1.4 });
		g_miYaZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  35, 3 });
		g_miYaZTKYPrice[L"���Ļ���������"].push_back({ 0, 0, 20,  42.5, 2.8 });
		g_miYaZTKYPrice[L"�ຣʡ"].push_back({ 0, 0, 20,  42.5, 2.8 });
		g_miYaZTKYPrice[L"������ʡ"].push_back({ 0, 0, 20,  37, 1.7 });
		g_miYaZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  37, 1.7 });
		g_miYaZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  37, 1.7 });
		g_miYaZTKYPrice[L"���ɹ�������"].push_back({ 0, 0, 20,  72.5, 3 });
		g_miYaZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  42, 2.7 });
		g_miYaZTKYPrice[L"�½�ά���������"].push_back({ 0, 0, 20,  82.5, 3.2 });
		g_miYaZTKYPrice[L"����������"].push_back({ 0, 0, 20,  72, 4.2 });
	}
	//��һ��԰��ͨ����
	{

		g_qiYiJiangYuanZTKYPrice[L"�Ϻ�"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_qiYiJiangYuanZTKYPrice[L"����"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_qiYiJiangYuanZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_qiYiJiangYuanZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_qiYiJiangYuanZTKYPrice[L"�㽭ʡ"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_qiYiJiangYuanZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_qiYiJiangYuanZTKYPrice[L"ɽ��ʡ"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_qiYiJiangYuanZTKYPrice[L"���"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_qiYiJiangYuanZTKYPrice[L"�ӱ�ʡ"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_qiYiJiangYuanZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_qiYiJiangYuanZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_qiYiJiangYuanZTKYPrice[L"ɽ��ʡ"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_qiYiJiangYuanZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_qiYiJiangYuanZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_qiYiJiangYuanZTKYPrice[L"�㶫ʡ"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_qiYiJiangYuanZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_qiYiJiangYuanZTKYPrice[L"����׳��������"].push_back({ 0, 0, 20,  27.5, 1.3 });
		g_qiYiJiangYuanZTKYPrice[L"�Ĵ�ʡ"].push_back({ 0, 0, 20,  22.5, 1 });
		g_qiYiJiangYuanZTKYPrice[L"���β���������"].push_back({ 0, 0, 20,  50, 1.6 });
		g_qiYiJiangYuanZTKYPrice[L"���Ӳ���Ǽ��������"].push_back({ 0, 0, 20,  50, 1.6 });
		g_qiYiJiangYuanZTKYPrice[L"��ɽ����������"].push_back({ 0, 0, 20,  50, 1.6 });
		g_qiYiJiangYuanZTKYPrice[L"����"].push_back({ 0, 0, 20,  27.5, 1.2 });
		g_qiYiJiangYuanZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  32, 1.4 });
		g_qiYiJiangYuanZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  27.5, 1.4 });
		g_qiYiJiangYuanZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  35, 3 });
		g_qiYiJiangYuanZTKYPrice[L"���Ļ���������"].push_back({ 0, 0, 20,  42.5, 2.8 });
		g_qiYiJiangYuanZTKYPrice[L"�ຣʡ"].push_back({ 0, 0, 20,  42.5, 2.8 });
		g_qiYiJiangYuanZTKYPrice[L"������ʡ"].push_back({ 0, 0, 20,  37, 1.7 });
		g_qiYiJiangYuanZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  37, 1.7 });
		g_qiYiJiangYuanZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  37, 1.7 });
		g_qiYiJiangYuanZTKYPrice[L"���ɹ�������"].push_back({ 0, 0, 20,  72.5, 3 });
		g_qiYiJiangYuanZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  42, 2.7 });
		g_qiYiJiangYuanZTKYPrice[L"�½�ά���������"].push_back({ 0, 0, 20,  82.5, 3.2 });
		g_qiYiJiangYuanZTKYPrice[L"����������"].push_back({ 0, 0, 20,  72, 4.2 });
	}
	//���Ƶ�����ͨ����
	{
		g_zhiShanZTKYPrice[L"�Ϻ�"].push_back({ 0, 0, 20,  27, 1.3 });
		g_zhiShanZTKYPrice[L"����"].push_back({ 0, 0, 20,  27, 1.3 });
		g_zhiShanZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  27, 1.3 });
		g_zhiShanZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  27, 1.3 });
		g_zhiShanZTKYPrice[L"�㽭ʡ"].push_back({ 0, 0, 20,  27, 1.3 });
		g_zhiShanZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  27, 1.3 });
		g_zhiShanZTKYPrice[L"ɽ��ʡ"].push_back({ 0, 0, 20,  27, 1.3 });
		g_zhiShanZTKYPrice[L"���"].push_back({ 0, 0, 20,  27, 1.3 });
		g_zhiShanZTKYPrice[L"�ӱ�ʡ"].push_back({ 0, 0, 20,  27, 1.3 });
		g_zhiShanZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  27, 1.3 });
		g_zhiShanZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  27, 1.3 });
		g_zhiShanZTKYPrice[L"ɽ��ʡ"].push_back({ 0, 0, 20,  27, 1.3 });
		g_zhiShanZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  27, 1.3 });
		g_zhiShanZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  27, 1.3 });
		g_zhiShanZTKYPrice[L"�㶫ʡ"].push_back({ 0, 0, 20,  27, 1.3 });
		g_zhiShanZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  27, 1.3 });
		g_zhiShanZTKYPrice[L"����׳��������"].push_back({ 0, 0, 20,  27, 1.3 });
		g_zhiShanZTKYPrice[L"�Ĵ�ʡ"].push_back({ 0, 0, 20,  22, 1 });
		g_zhiShanZTKYPrice[L"���β���������"].push_back({ 0, 0, 20,  50, 1.6 });
		g_zhiShanZTKYPrice[L"���Ӳ���Ǽ��������"].push_back({ 0, 0, 20,  50, 1.6 });
		g_zhiShanZTKYPrice[L"��ɽ����������"].push_back({ 0, 0, 20,  50, 1.6 });
		g_zhiShanZTKYPrice[L"����"].push_back({ 0, 0, 20,  27, 1.2 });
		g_zhiShanZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  32, 1.4 });
		g_zhiShanZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  27, 1.4 });
		g_zhiShanZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  35, 3 });
		g_zhiShanZTKYPrice[L"���Ļ���������"].push_back({ 0, 0, 20,  42, 2.8 });
		g_zhiShanZTKYPrice[L"�ຣʡ"].push_back({ 0, 0, 20,  42, 2.8 });
		g_zhiShanZTKYPrice[L"������ʡ"].push_back({ 0, 0, 20,  37, 1.7 });
		g_zhiShanZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  37, 1.7 });
		g_zhiShanZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  37, 1.7 });
		g_zhiShanZTKYPrice[L"���ɹ�������"].push_back({ 0, 0, 20,  72, 3 });
		g_zhiShanZTKYPrice[L"����ʡ"].push_back({ 0, 0, 20,  42, 2.7 });
		g_zhiShanZTKYPrice[L"�½�ά���������"].push_back({ 0, 0, 20,  82, 3.2 });
		g_zhiShanZTKYPrice[L"����������"].push_back({ 0, 0, 20,  72, 4.2 });
	}
	//����˳��
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
	//��һ��԰˳��
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
	//����Ƽ�˳��
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
	//������˳��
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
	//���Ƶ���˳��
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
	//˶������˳��
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
	//���ĸ��ϴ���
	{
		//1����
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2, 0 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2, 0 });
		g_jingXinGeYDKDPrice[L"�㽭ʡ"].push_back({ 0, 1, 1, 2, 0 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2, 0 });
		g_jingXinGeYDKDPrice[L"ɽ��ʡ"].push_back({ 0, 1, 1, 2, 0 });
		g_jingXinGeYDKDPrice[L"���"].push_back({ 0, 1, 1, 2, 0 });
		g_jingXinGeYDKDPrice[L"�ӱ�ʡ"].push_back({ 0, 1, 1, 2, 0 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2, 0 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2, 0 });
		g_jingXinGeYDKDPrice[L"ɽ��ʡ"].push_back({ 0, 1, 1, 2, 0 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2, 0 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2, 0 });
		g_jingXinGeYDKDPrice[L"�㶫ʡ"].push_back({ 0, 1, 1, 2, 0 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2, 0 });
		g_jingXinGeYDKDPrice[L"����׳��������"].push_back({ 0, 1, 1, 2, 0 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2, 0 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2, 0 });
		
		g_jingXinGeYDKDPrice[L"�Ĵ�ʡ"].push_back({ 0, 1, 1, 2, 0 });
		g_jingXinGeYDKDPrice[L"����"].push_back({ 0, 1, 1, 2, 0 });

		g_jingXinGeYDKDPrice[L"������ʡ"].push_back({ 0, 1, 1, 2, 0 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2, 0 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2, 0 });

		g_jingXinGeYDKDPrice[L"������"].push_back({ 0, 1, 1, 2.9, 0 });
		g_jingXinGeYDKDPrice[L"�Ϻ�"].push_back({ 0, 1, 1, 2.9, 0 });
		g_jingXinGeYDKDPrice[L"����"].push_back({ 0, 1, 1, 2.9, 0 });
		//2����
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 1, 2, 2, 2.3, 0 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 1, 2, 2, 2.3, 0 });
		g_jingXinGeYDKDPrice[L"�㽭ʡ"].push_back({ 1, 2, 2, 2.3, 0 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 1, 2, 2, 2.3, 0 });
		g_jingXinGeYDKDPrice[L"ɽ��ʡ"].push_back({ 1, 2, 2, 2.3, 0 });
		g_jingXinGeYDKDPrice[L"���"].push_back({ 1, 2, 2, 2.3, 0 });
		g_jingXinGeYDKDPrice[L"�ӱ�ʡ"].push_back({ 1, 2, 2, 2.3, 0 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 1, 2, 2, 2.3, 0 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 1, 2, 2, 2.3, 0 });
		g_jingXinGeYDKDPrice[L"ɽ��ʡ"].push_back({ 1, 2, 2, 2.3, 0 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 1, 2, 2, 2.3, 0 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 1, 2, 2, 2.3, 0 });
		g_jingXinGeYDKDPrice[L"�㶫ʡ"].push_back({ 1, 2, 2, 2.3, 0 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 1, 2, 2, 2.3, 0 });
		g_jingXinGeYDKDPrice[L"����׳��������"].push_back({ 1, 2, 2, 2.3, 0 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 1, 2, 2, 2.3, 0 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 1, 2, 2, 2.3, 0 });

		g_jingXinGeYDKDPrice[L"�Ĵ�ʡ"].push_back({ 1, 2, 2, 2.3, 0 });
		g_jingXinGeYDKDPrice[L"����"].push_back({ 1, 2, 2, 2.3, 0 });

		g_jingXinGeYDKDPrice[L"������ʡ"].push_back({ 1, 2, 2, 2.4, 0 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 1, 2, 2, 2.4, 0 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 1, 2, 2, 2.4, 0 });

		g_jingXinGeYDKDPrice[L"������"].push_back({ 1, 2, 2, 3.2, 0 });
		g_jingXinGeYDKDPrice[L"�Ϻ�"].push_back({ 1, 2, 2, 3.2, 0 });
		g_jingXinGeYDKDPrice[L"����"].push_back({ 1, 2, 2, 3.2, 0 });
		//3����
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 2, 3, 3, 2.7, 0 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 2, 3, 3, 2.7, 0 });
		g_jingXinGeYDKDPrice[L"�㽭ʡ"].push_back({ 2, 3, 3, 2.7, 0 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 2, 3, 3, 2.7, 0 });
		g_jingXinGeYDKDPrice[L"ɽ��ʡ"].push_back({ 2, 3, 3, 2.7, 0 });
		g_jingXinGeYDKDPrice[L"���"].push_back({ 2, 3, 3, 2.7, 0 });
		g_jingXinGeYDKDPrice[L"�ӱ�ʡ"].push_back({ 2, 3, 3, 2.7, 0 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 2, 3, 3, 2.7, 0 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 2, 3, 3, 2.7, 0 });
		g_jingXinGeYDKDPrice[L"ɽ��ʡ"].push_back({ 2, 3, 3, 2.7, 0 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 2, 3, 3, 2.7, 0 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 2, 3, 3, 2.7, 0 });
		g_jingXinGeYDKDPrice[L"�㶫ʡ"].push_back({ 2, 3, 3, 2.7, 0 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 2, 3, 3, 2.7, 0 });
		g_jingXinGeYDKDPrice[L"����׳��������"].push_back({ 2, 3, 3, 2.7, 0 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 2, 3, 3, 2.7, 0 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 2, 3, 3, 2.7, 0 });

		g_jingXinGeYDKDPrice[L"�Ĵ�ʡ"].push_back({ 2, 3, 3, 2.7, 0 });
		g_jingXinGeYDKDPrice[L"����"].push_back({ 2, 3, 3, 2.7, 0 });

		g_jingXinGeYDKDPrice[L"������ʡ"].push_back({ 2, 3, 3, 2.8, 0 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 2, 3, 3, 2.8, 0 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 2, 3, 3, 2.8, 0 });

		g_jingXinGeYDKDPrice[L"������"].push_back({ 2, 3, 3, 3.6, 0 });
		g_jingXinGeYDKDPrice[L"�Ϻ�"].push_back({ 2, 3, 3, 3.6, 0 });
		g_jingXinGeYDKDPrice[L"����"].push_back({ 2, 3, 3, 3.6, 0 });
		//3-5����
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 3, 5, 5, 4.1, 0 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 3, 5, 5, 4.1, 0 });
		g_jingXinGeYDKDPrice[L"�㽭ʡ"].push_back({ 3, 5, 5, 4.1, 0 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 3, 5, 5, 4.1, 0 });
		g_jingXinGeYDKDPrice[L"ɽ��ʡ"].push_back({ 3, 5, 5, 4.1, 0 });
		g_jingXinGeYDKDPrice[L"���"].push_back({ 3, 5, 5, 4.1, 0 });
		g_jingXinGeYDKDPrice[L"�ӱ�ʡ"].push_back({ 3, 5, 5, 4.1, 0 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 3, 5, 5, 4.1, 0 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 3, 5, 5, 4.1, 0 });
		g_jingXinGeYDKDPrice[L"ɽ��ʡ"].push_back({ 3, 5, 5, 4.1, 0 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 3, 5, 5, 4.1, 0 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 3, 5, 5, 4.1, 0 });
		g_jingXinGeYDKDPrice[L"�㶫ʡ"].push_back({ 3, 5, 5, 4.1, 0 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 3, 5, 5, 4.1, 0 });
		g_jingXinGeYDKDPrice[L"����׳��������"].push_back({ 3, 5, 5, 4.1, 0 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 3, 5, 5, 4.1, 0 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 3, 5, 5, 4.1, 0 });

		g_jingXinGeYDKDPrice[L"�Ĵ�ʡ"].push_back({ 3, 5, 5, 4.1, 0 });
		g_jingXinGeYDKDPrice[L"����"].push_back({ 3, 5, 5, 4.1, 0 });

		g_jingXinGeYDKDPrice[L"������ʡ"].push_back({ 3, 5, 5, 4.2, 0 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 3, 5, 5, 4.2, 0 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 3, 5, 5, 4.2, 0 });

		g_jingXinGeYDKDPrice[L"������"].push_back({ 3, 5, 5, 5.9, 0 });
		g_jingXinGeYDKDPrice[L"�Ϻ�"].push_back({ 3, 5, 5, 5.9, 0 });
		g_jingXinGeYDKDPrice[L"����"].push_back({ 3, 5, 5, 5.9, 0 });
		//5��������
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 5, 0, 1, 3.8, 1.2 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 5, 0, 1, 3.8, 1.2 });
		g_jingXinGeYDKDPrice[L"�㽭ʡ"].push_back({ 5, 0, 1, 3.8, 1.2 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 5, 0, 1, 3.8, 1.2 });
		g_jingXinGeYDKDPrice[L"ɽ��ʡ"].push_back({ 5, 0, 1, 3.8, 1.2 });
		g_jingXinGeYDKDPrice[L"���"].push_back({ 5, 0, 1, 3.8, 1.2 });
		g_jingXinGeYDKDPrice[L"�ӱ�ʡ"].push_back({ 5, 0, 1, 3.8, 1.2 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 5, 0, 1, 3.8, 1.2 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 5, 0, 1, 3.8, 1.2 });
		g_jingXinGeYDKDPrice[L"ɽ��ʡ"].push_back({ 5, 0, 1, 3.8, 1.2 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 5, 0, 1, 3.8, 1.2 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 5, 0, 1, 3.8, 1.2 });
		g_jingXinGeYDKDPrice[L"�㶫ʡ"].push_back({ 5, 0, 1, 3.8, 1.2 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 5, 0, 1, 3.8, 1.2 });
		g_jingXinGeYDKDPrice[L"����׳��������"].push_back({ 5, 0, 1, 3.8, 1.2 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 5, 0, 1, 3.8, 1.2 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 5, 0, 1, 3.8, 1.2 });

		g_jingXinGeYDKDPrice[L"�Ĵ�ʡ"].push_back({ 5, 0, 1, 3.8, 0.8 });
		g_jingXinGeYDKDPrice[L"����"].push_back({ 5, 0, 1, 3.8, 0.8 });

		g_jingXinGeYDKDPrice[L"������ʡ"].push_back({ 5, 0, 1, 5.1, 2.5 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 5, 0, 1, 5.1, 2.5 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 5, 0, 1, 5.1, 2.5 });

		g_jingXinGeYDKDPrice[L"������"].push_back({ 5, 0, 1, 3.8, 1.2 });
		g_jingXinGeYDKDPrice[L"�Ϻ�"].push_back({ 5, 0, 1, 3.8, 1.2 });
		g_jingXinGeYDKDPrice[L"����"].push_back({ 5, 0, 1, 3.8, 1.2 });
		//��������
		g_jingXinGeYDKDPrice[L"�½�ά���������"].push_back({ 0, 0, 1, 16, 4 });
		g_jingXinGeYDKDPrice[L"����������"].push_back({ 0, 0, 1, 9, 7 });
		g_jingXinGeYDKDPrice[L"���Ļ���������"].push_back({ 0, 0, 1, 7, 5 });
		g_jingXinGeYDKDPrice[L"�ຣʡ"].push_back({ 0, 0, 1, 7, 5 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 0, 0, 1, 7, 5 });
		g_jingXinGeYDKDPrice[L"���ɹ�������"].push_back({ 0, 0, 1, 8, 6 });
		g_jingXinGeYDKDPrice[L"����ʡ"].push_back({ 0, 0, 1, 6, 5 });
	}
	//Ȥ�ÿ��
	{
		//3kg
		g_quLvShouNaKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 3, 0 });
		g_quLvShouNaKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 3, 0 });
		g_quLvShouNaKDPrice[L"�㽭ʡ"].push_back({ 0, 3, 3, 3, 0 });
		g_quLvShouNaKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 3, 0 });
		g_quLvShouNaKDPrice[L"ɽ��ʡ"].push_back({ 0, 3, 3, 3, 0 });
		g_quLvShouNaKDPrice[L"���"].push_back({ 0, 3, 3, 3, 0 });
		g_quLvShouNaKDPrice[L"�ӱ�ʡ"].push_back({ 0, 3, 3, 3, 0 });
		g_quLvShouNaKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 3, 0 });
		g_quLvShouNaKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 3, 0 });
		g_quLvShouNaKDPrice[L"ɽ��ʡ"].push_back({ 0, 3, 3, 3, 0 });
		g_quLvShouNaKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 3, 0 });
		g_quLvShouNaKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 3, 0 });
		g_quLvShouNaKDPrice[L"�㶫ʡ"].push_back({ 0, 3, 3, 3, 0 });
		g_quLvShouNaKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 3, 0 });
		g_quLvShouNaKDPrice[L"����׳��������"].push_back({ 0, 3, 3, 3, 0 });
		g_quLvShouNaKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 3, 0 });
		g_quLvShouNaKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 3, 0 });

		g_quLvShouNaKDPrice[L"�Ĵ�ʡ"].push_back({ 0, 3, 3, 3, 0 });
		g_quLvShouNaKDPrice[L"����"].push_back({ 0, 3, 3, 3, 0 });

		g_quLvShouNaKDPrice[L"������ʡ"].push_back({ 0, 3, 3, 3, 0 });
		g_quLvShouNaKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 3, 0 });
		g_quLvShouNaKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 3, 0 });

		g_quLvShouNaKDPrice[L"������"].push_back({ 0, 3, 3, 4, 0 });
		g_quLvShouNaKDPrice[L"�Ϻ�"].push_back({ 0, 3, 3, 4, 0 });
		g_quLvShouNaKDPrice[L"����"].push_back({ 0, 3, 3, 4, 0 });
		//3kg����
		g_quLvShouNaKDPrice[L"����ʡ"].push_back({ 3, 0, 1, 3.8, 1.2 });
		g_quLvShouNaKDPrice[L"����ʡ"].push_back({ 3, 0, 1, 3.8, 1.2 });
		g_quLvShouNaKDPrice[L"�㽭ʡ"].push_back({ 3, 0, 1, 3.8, 1.2 });
		g_quLvShouNaKDPrice[L"����ʡ"].push_back({ 3, 0, 1, 3.8, 1.2 });
		g_quLvShouNaKDPrice[L"ɽ��ʡ"].push_back({ 3, 0, 1, 3.8, 1.2 });
		g_quLvShouNaKDPrice[L"���"].push_back({ 3, 0, 1, 3.8, 1.2 });
		g_quLvShouNaKDPrice[L"�ӱ�ʡ"].push_back({ 3, 0, 1, 3.8, 1.2 });
		g_quLvShouNaKDPrice[L"����ʡ"].push_back({ 3, 0, 1, 3.8, 1.2 });
		g_quLvShouNaKDPrice[L"����ʡ"].push_back({ 3, 0, 1, 3.8, 1.2 });
		g_quLvShouNaKDPrice[L"ɽ��ʡ"].push_back({ 3, 0, 1, 3.8, 1.2 });
		g_quLvShouNaKDPrice[L"����ʡ"].push_back({ 3, 0, 1, 3.8, 1.2 });
		g_quLvShouNaKDPrice[L"����ʡ"].push_back({ 3, 0, 1, 3.8, 1.2 });
		g_quLvShouNaKDPrice[L"�㶫ʡ"].push_back({ 3, 0, 1, 3.8, 1.2 });
		g_quLvShouNaKDPrice[L"����ʡ"].push_back({ 3, 0, 1, 3.8, 1.2 });
		g_quLvShouNaKDPrice[L"����׳��������"].push_back({ 3, 0, 1, 3.8, 1.2 });
		g_quLvShouNaKDPrice[L"����ʡ"].push_back({ 3, 0, 1, 3.8, 1.2 });
		g_quLvShouNaKDPrice[L"����ʡ"].push_back({ 3, 0, 1, 3.8, 1.2 });

		g_quLvShouNaKDPrice[L"�Ĵ�ʡ"].push_back({ 3, 0, 1, 3.5, 0.9 });
		g_quLvShouNaKDPrice[L"����"].push_back({ 3, 0, 1, 3.5, 0.9 });

		g_quLvShouNaKDPrice[L"������ʡ"].push_back({ 3, 0, 1, 5.1, 2.5 });
		g_quLvShouNaKDPrice[L"����ʡ"].push_back({ 3, 0, 1, 5.1, 2.5 });
		g_quLvShouNaKDPrice[L"����ʡ"].push_back({ 3, 0, 1, 5.1, 2.5 });

		g_quLvShouNaKDPrice[L"������"].push_back({ 3, 0, 1, 3.8, 1.2 });
		g_quLvShouNaKDPrice[L"�Ϻ�"].push_back({ 3, 0, 1, 3.8, 1.2 });
		g_quLvShouNaKDPrice[L"����"].push_back({ 3, 0, 1, 3.8, 1.2 });
		//��������
		g_quLvShouNaKDPrice[L"�½�ά���������"].push_back({ 0, 0, 1, 16, 4 });
		g_quLvShouNaKDPrice[L"����������"].push_back({ 0, 0, 1, 9, 7 });
		g_quLvShouNaKDPrice[L"���Ļ���������"].push_back({ 0, 0, 1, 7, 5 });
		g_quLvShouNaKDPrice[L"�ຣʡ"].push_back({ 0, 0, 1, 7, 5 });
		g_quLvShouNaKDPrice[L"����ʡ"].push_back({ 0, 0, 1, 7, 5 });
		g_quLvShouNaKDPrice[L"���ɹ�������"].push_back({ 0, 0, 1, 8, 6 });
		g_quLvShouNaKDPrice[L"����ʡ"].push_back({ 0, 0, 1, 6, 5 });
	}
	//˶������
	{
		//3kg
		g_shuoGuoLiuXiangKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 2.9, 0 });
		g_shuoGuoLiuXiangKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 2.9, 0 });
		g_shuoGuoLiuXiangKDPrice[L"�㽭ʡ"].push_back({ 0, 3, 3, 2.9, 0 });
		g_shuoGuoLiuXiangKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 2.9, 0 });
		g_shuoGuoLiuXiangKDPrice[L"ɽ��ʡ"].push_back({ 0, 3, 3, 2.9, 0 });
		g_shuoGuoLiuXiangKDPrice[L"���"].push_back({ 0, 3, 3, 2.9, 0 });
		g_shuoGuoLiuXiangKDPrice[L"�ӱ�ʡ"].push_back({ 0, 3, 3, 2.9, 0 });
		g_shuoGuoLiuXiangKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 2.9, 0 });
		g_shuoGuoLiuXiangKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 2.9, 0 });
		g_shuoGuoLiuXiangKDPrice[L"ɽ��ʡ"].push_back({ 0, 3, 3, 2.9, 0 });
		g_shuoGuoLiuXiangKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 2.9, 0 });
		g_shuoGuoLiuXiangKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 2.9, 0 });
		g_shuoGuoLiuXiangKDPrice[L"�㶫ʡ"].push_back({ 0, 3, 3, 2.9, 0 });
		g_shuoGuoLiuXiangKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 2.9, 0 });
		g_shuoGuoLiuXiangKDPrice[L"����׳��������"].push_back({ 0, 3, 3, 2.9, 0 });
		g_shuoGuoLiuXiangKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 2.9, 0 });
		g_shuoGuoLiuXiangKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 2.9, 0 });

		g_shuoGuoLiuXiangKDPrice[L"�Ĵ�ʡ"].push_back({ 0, 3, 3, 2.9, 0 });
		g_shuoGuoLiuXiangKDPrice[L"����"].push_back({ 0, 3, 3, 2.9, 0 });

		g_shuoGuoLiuXiangKDPrice[L"������ʡ"].push_back({ 0, 3, 3, 4.4, 0 });
		g_shuoGuoLiuXiangKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 4.4, 0 });
		g_shuoGuoLiuXiangKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 4.4, 0 });

		g_shuoGuoLiuXiangKDPrice[L"������"].push_back({ 0, 3, 3, 2.9, 0 });
		g_shuoGuoLiuXiangKDPrice[L"�Ϻ�"].push_back({ 0, 3, 3, 2.9, 0 });
		g_shuoGuoLiuXiangKDPrice[L"����"].push_back({ 0, 3, 3, 2.9, 0 });
		//3kg����
		g_shuoGuoLiuXiangKDPrice[L"����ʡ"].push_back({ 3, 0, 3, 3, 1.3 });
		g_shuoGuoLiuXiangKDPrice[L"����ʡ"].push_back({ 3, 0, 3, 3, 1.3 });
		g_shuoGuoLiuXiangKDPrice[L"�㽭ʡ"].push_back({ 3, 0, 3, 3, 1.3 });
		g_shuoGuoLiuXiangKDPrice[L"����ʡ"].push_back({ 3, 0, 3, 3, 1.3 });
		g_shuoGuoLiuXiangKDPrice[L"ɽ��ʡ"].push_back({ 3, 0, 3, 3, 1.3 });
		g_shuoGuoLiuXiangKDPrice[L"���"].push_back({ 3, 0, 3, 3, 1.3 });
		g_shuoGuoLiuXiangKDPrice[L"�ӱ�ʡ"].push_back({ 3, 0, 3, 3, 1.3 });
		g_shuoGuoLiuXiangKDPrice[L"����ʡ"].push_back({ 3, 0, 3, 3, 1.3 });
		g_shuoGuoLiuXiangKDPrice[L"����ʡ"].push_back({ 3, 0, 3, 3, 1.3 });
		g_shuoGuoLiuXiangKDPrice[L"ɽ��ʡ"].push_back({ 3, 0, 3, 3, 1.3 });
		g_shuoGuoLiuXiangKDPrice[L"����ʡ"].push_back({ 3, 0, 3, 3, 1.3 });
		g_shuoGuoLiuXiangKDPrice[L"����ʡ"].push_back({ 3, 0, 3, 3, 1.3 });
		g_shuoGuoLiuXiangKDPrice[L"�㶫ʡ"].push_back({ 3, 0, 3, 3, 1.3 });
		g_shuoGuoLiuXiangKDPrice[L"����ʡ"].push_back({ 3, 0, 3, 3, 1.3 });
		g_shuoGuoLiuXiangKDPrice[L"����׳��������"].push_back({ 3, 0, 3, 3, 1.3 });
		g_shuoGuoLiuXiangKDPrice[L"����ʡ"].push_back({ 3, 0, 3, 3, 1.3 });
		g_shuoGuoLiuXiangKDPrice[L"����ʡ"].push_back({ 3, 0, 3, 3, 1.3 });

		g_shuoGuoLiuXiangKDPrice[L"�Ĵ�ʡ"].push_back({ 3, 0, 3, 3, 1 });
		g_shuoGuoLiuXiangKDPrice[L"����"].push_back({ 3, 0, 3, 3, 1.3 });

		g_shuoGuoLiuXiangKDPrice[L"������ʡ"].push_back({ 3, 0, 1, 5, 2 });
		g_shuoGuoLiuXiangKDPrice[L"����ʡ"].push_back({ 3, 0, 1, 5, 2 });
		g_shuoGuoLiuXiangKDPrice[L"����ʡ"].push_back({ 3, 0, 1, 5, 2 });

		g_shuoGuoLiuXiangKDPrice[L"������"].push_back({ 3, 0, 3, 3, 1.3 });
		g_shuoGuoLiuXiangKDPrice[L"�Ϻ�"].push_back({ 3, 0, 3, 3, 1.3 });
		g_shuoGuoLiuXiangKDPrice[L"����"].push_back({ 3, 0, 3, 3, 1.3 });
		//��������
		g_shuoGuoLiuXiangKDPrice[L"�½�ά���������"].push_back({ 0, 0, 1, 16, 4 });
		g_shuoGuoLiuXiangKDPrice[L"����������"].push_back({ 0, 0, 1, 9, 7 });
		g_shuoGuoLiuXiangKDPrice[L"���Ļ���������"].push_back({ 0, 0, 1, 7, 5 });
		g_shuoGuoLiuXiangKDPrice[L"�ຣʡ"].push_back({ 0, 0, 1, 7, 5 });
		g_shuoGuoLiuXiangKDPrice[L"����ʡ"].push_back({ 0, 0, 1, 7, 5 });
		g_shuoGuoLiuXiangKDPrice[L"���ɹ�������"].push_back({ 0, 0, 1, 8, 6 });
		g_shuoGuoLiuXiangKDPrice[L"����ʡ"].push_back({ 0, 0, 1, 6, 5 });
	}
	//������Ů
	{
		//2kg
		g_xingXingShaoNvKDPrice[L"����ʡ"].push_back({ 0, 2, 2, 2.6, 0 });
		g_xingXingShaoNvKDPrice[L"����ʡ"].push_back({ 0, 2, 2, 2.6, 0 });
		g_xingXingShaoNvKDPrice[L"�㽭ʡ"].push_back({ 0, 2, 2, 2.6, 0 });
		g_xingXingShaoNvKDPrice[L"����ʡ"].push_back({ 0, 2, 2, 2.6, 0 });
		g_xingXingShaoNvKDPrice[L"ɽ��ʡ"].push_back({ 0, 2, 2, 2.6, 0 });
		g_xingXingShaoNvKDPrice[L"���"].push_back({ 0, 2, 2, 2.6, 0 });
		g_xingXingShaoNvKDPrice[L"�ӱ�ʡ"].push_back({ 0, 2, 2, 2.6, 0 });
		g_xingXingShaoNvKDPrice[L"����ʡ"].push_back({ 0, 2, 2, 2.6, 0 });
		g_xingXingShaoNvKDPrice[L"����ʡ"].push_back({ 0, 2, 2, 2.6, 0 });
		g_xingXingShaoNvKDPrice[L"ɽ��ʡ"].push_back({ 0, 2, 2, 2.6, 0 });
		g_xingXingShaoNvKDPrice[L"����ʡ"].push_back({ 0, 2, 2, 2.6, 0 });
		g_xingXingShaoNvKDPrice[L"����ʡ"].push_back({ 0, 2, 2, 2.6, 0 });
		g_xingXingShaoNvKDPrice[L"�㶫ʡ"].push_back({ 0, 2, 2, 2.6, 0 });
		g_xingXingShaoNvKDPrice[L"����ʡ"].push_back({ 0, 2, 2, 2.6, 0 });
		g_xingXingShaoNvKDPrice[L"����׳��������"].push_back({ 0, 2, 2, 2.6, 0 });
		g_xingXingShaoNvKDPrice[L"����ʡ"].push_back({ 0, 2, 2, 2.6, 0 });
		g_xingXingShaoNvKDPrice[L"����ʡ"].push_back({ 0, 2, 2, 2.6, 0 });

		g_xingXingShaoNvKDPrice[L"�Ĵ�ʡ"].push_back({ 0, 2, 2, 2.6, 0 });
		g_xingXingShaoNvKDPrice[L"����"].push_back({ 0, 2, 2, 2.6, 0 });

		g_xingXingShaoNvKDPrice[L"������ʡ"].push_back({ 0, 2, 2, 2.6, 0 });
		g_xingXingShaoNvKDPrice[L"����ʡ"].push_back({ 0, 2, 2, 2.6, 0 });
		g_xingXingShaoNvKDPrice[L"����ʡ"].push_back({ 0, 2, 2, 2.6, 0 });

		g_xingXingShaoNvKDPrice[L"������"].push_back({ 0, 2, 2, 3.5, 0 });
		g_xingXingShaoNvKDPrice[L"�Ϻ�"].push_back({ 0, 2, 2, 3.5, 0 });
		g_xingXingShaoNvKDPrice[L"����"].push_back({ 0, 2, 2, 3.5, 0 });
		//3kg
		g_xingXingShaoNvKDPrice[L"����ʡ"].push_back({ 2, 3, 3, 2.9, 0 });
		g_xingXingShaoNvKDPrice[L"����ʡ"].push_back({ 2, 3, 3, 2.9, 0 });
		g_xingXingShaoNvKDPrice[L"�㽭ʡ"].push_back({ 2, 3, 3, 2.9, 0 });
		g_xingXingShaoNvKDPrice[L"����ʡ"].push_back({ 2, 3, 3, 2.9, 0 });
		g_xingXingShaoNvKDPrice[L"ɽ��ʡ"].push_back({ 2, 3, 3, 2.9, 0 });
		g_xingXingShaoNvKDPrice[L"���"].push_back({ 2, 3, 3, 2.9, 0 });
		g_xingXingShaoNvKDPrice[L"�ӱ�ʡ"].push_back({ 2, 3, 3, 2.9, 0 });
		g_xingXingShaoNvKDPrice[L"����ʡ"].push_back({ 2, 3, 3, 2.9, 0 });
		g_xingXingShaoNvKDPrice[L"����ʡ"].push_back({ 2, 3, 3, 2.9, 0 });
		g_xingXingShaoNvKDPrice[L"ɽ��ʡ"].push_back({ 2, 3, 3, 2.9, 0 });
		g_xingXingShaoNvKDPrice[L"����ʡ"].push_back({ 2, 3, 3, 2.9, 0 });
		g_xingXingShaoNvKDPrice[L"����ʡ"].push_back({ 2, 3, 3, 2.9, 0 });
		g_xingXingShaoNvKDPrice[L"�㶫ʡ"].push_back({ 2, 3, 3, 2.9, 0 });
		g_xingXingShaoNvKDPrice[L"����ʡ"].push_back({ 2, 3, 3, 2.9, 0 });
		g_xingXingShaoNvKDPrice[L"����׳��������"].push_back({ 2, 3, 3, 2.9, 0 });
		g_xingXingShaoNvKDPrice[L"����ʡ"].push_back({ 2, 3, 3, 2.9, 0 });
		g_xingXingShaoNvKDPrice[L"����ʡ"].push_back({ 2, 3, 3, 2.9, 0 });

		g_xingXingShaoNvKDPrice[L"�Ĵ�ʡ"].push_back({ 2, 3, 3, 2.9, 0 });
		g_xingXingShaoNvKDPrice[L"����"].push_back({ 2, 3, 3, 2.9, 0 });

		g_xingXingShaoNvKDPrice[L"������ʡ"].push_back({ 2, 3, 3, 2.9, 0 });
		g_xingXingShaoNvKDPrice[L"����ʡ"].push_back({ 2, 3, 3, 2.9, 0 });
		g_xingXingShaoNvKDPrice[L"����ʡ"].push_back({ 2, 3, 3, 2.9, 0 });

		g_xingXingShaoNvKDPrice[L"������"].push_back({ 2, 3, 3, 3.8, 0 });
		g_xingXingShaoNvKDPrice[L"�Ϻ�"].push_back({ 2, 3, 3, 3.8, 0 });
		g_xingXingShaoNvKDPrice[L"����"].push_back({ 2, 3, 3, 3.8, 0 });
		//3kg����
		g_xingXingShaoNvKDPrice[L"����ʡ"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_xingXingShaoNvKDPrice[L"����ʡ"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_xingXingShaoNvKDPrice[L"�㽭ʡ"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_xingXingShaoNvKDPrice[L"����ʡ"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_xingXingShaoNvKDPrice[L"ɽ��ʡ"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_xingXingShaoNvKDPrice[L"���"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_xingXingShaoNvKDPrice[L"�ӱ�ʡ"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_xingXingShaoNvKDPrice[L"����ʡ"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_xingXingShaoNvKDPrice[L"����ʡ"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_xingXingShaoNvKDPrice[L"ɽ��ʡ"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_xingXingShaoNvKDPrice[L"����ʡ"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_xingXingShaoNvKDPrice[L"����ʡ"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_xingXingShaoNvKDPrice[L"�㶫ʡ"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_xingXingShaoNvKDPrice[L"����ʡ"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_xingXingShaoNvKDPrice[L"����׳��������"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_xingXingShaoNvKDPrice[L"����ʡ"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_xingXingShaoNvKDPrice[L"����ʡ"].push_back({ 3, 0, 1, 3.6, 1.1 });

		g_xingXingShaoNvKDPrice[L"�Ĵ�ʡ"].push_back({ 3, 0, 1, 3.4, 0.9 });
		g_xingXingShaoNvKDPrice[L"����"].push_back({ 3, 0, 1, 3.4, 0.9 });

		g_xingXingShaoNvKDPrice[L"������ʡ"].push_back({ 3, 0, 1, 5.1, 2.5 });
		g_xingXingShaoNvKDPrice[L"����ʡ"].push_back({ 3, 0, 1, 5.1, 2.5 });
		g_xingXingShaoNvKDPrice[L"����ʡ"].push_back({ 3, 0, 1, 5.1, 2.5 });

		g_xingXingShaoNvKDPrice[L"������"].push_back({ 3, 0, 1, 3.8, 1.2 });
		g_xingXingShaoNvKDPrice[L"�Ϻ�"].push_back({ 3, 0, 1, 3.8, 1.2 });
		g_xingXingShaoNvKDPrice[L"����"].push_back({ 3, 0, 1, 3.8, 1.2 });
		//��������
		g_xingXingShaoNvKDPrice[L"�½�ά���������"].push_back({ 0, 0, 1, 16, 4 });
		g_xingXingShaoNvKDPrice[L"����������"].push_back({ 0, 0, 1, 9, 7 });
		g_xingXingShaoNvKDPrice[L"���Ļ���������"].push_back({ 0, 0, 1, 7, 5 });
		g_xingXingShaoNvKDPrice[L"�ຣʡ"].push_back({ 0, 0, 1, 7, 5 });
		g_xingXingShaoNvKDPrice[L"����ʡ"].push_back({ 0, 0, 1, 7, 5 });
		g_xingXingShaoNvKDPrice[L"���ɹ�������"].push_back({ 0, 0, 1, 8, 6 });
		g_xingXingShaoNvKDPrice[L"����ʡ"].push_back({ 0, 0, 1, 6, 5 });\
	}
	//������
	{
		//1kg
		g_tuNiangNiangKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2.4, 0 });
		g_tuNiangNiangKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2.4, 0 });
		g_tuNiangNiangKDPrice[L"�㽭ʡ"].push_back({ 0, 1, 1, 2.4, 0 });
		g_tuNiangNiangKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2.4, 0 });
		g_tuNiangNiangKDPrice[L"ɽ��ʡ"].push_back({ 0, 1, 1, 2.4, 0 });
		g_tuNiangNiangKDPrice[L"���"].push_back({ 0, 1, 1, 2.4, 0 });
		g_tuNiangNiangKDPrice[L"�ӱ�ʡ"].push_back({ 0, 1, 1, 2.4, 0 });
		g_tuNiangNiangKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2.4, 0 });
		g_tuNiangNiangKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2.4, 0 });
		g_tuNiangNiangKDPrice[L"ɽ��ʡ"].push_back({ 0, 1, 1, 2.4, 0 });
		g_tuNiangNiangKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2.4, 0 });
		g_tuNiangNiangKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2.4, 0 });
		g_tuNiangNiangKDPrice[L"�㶫ʡ"].push_back({ 0, 1, 1, 2.4, 0 });
		g_tuNiangNiangKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2.4, 0 });
		g_tuNiangNiangKDPrice[L"����׳��������"].push_back({ 0, 1, 1, 2.4, 0 });
		g_tuNiangNiangKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2.4, 0 });
		g_tuNiangNiangKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2.4, 0 });
		g_tuNiangNiangKDPrice[L"�Ĵ�ʡ"].push_back({ 0, 1, 1, 2.4, 0 });
		g_tuNiangNiangKDPrice[L"����"].push_back({ 0, 1, 1, 2.4, 0 });

		g_tuNiangNiangKDPrice[L"������ʡ"].push_back({ 0, 1, 1, 2.4, 0 });
		g_tuNiangNiangKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2.4, 0 });
		g_tuNiangNiangKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2.4, 0 });
		g_tuNiangNiangKDPrice[L"���Ļ���������"].push_back({ 0, 1, 1, 2.4, 0 });
		g_tuNiangNiangKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2.4, 0 }); 

		g_tuNiangNiangKDPrice[L"������"].push_back({ 0, 1, 1, 3, 0 });
		g_tuNiangNiangKDPrice[L"�Ϻ�"].push_back({ 0, 1, 1, 3, 0 });
		g_tuNiangNiangKDPrice[L"����"].push_back({ 0, 1, 1, 3, 0 });
		g_tuNiangNiangKDPrice[L"�ຣʡ"].push_back({ 0, 1, 1, 3, 0 });
		//2kg
		g_tuNiangNiangKDPrice[L"����ʡ"].push_back({ 1, 2, 2, 2.6, 0 });
		g_tuNiangNiangKDPrice[L"����ʡ"].push_back({ 1, 2, 2, 2.6, 0 });
		g_tuNiangNiangKDPrice[L"�㽭ʡ"].push_back({ 1, 2, 2, 2.6, 0 });
		g_tuNiangNiangKDPrice[L"����ʡ"].push_back({ 1, 2, 2, 2.6, 0 });
		g_tuNiangNiangKDPrice[L"ɽ��ʡ"].push_back({ 1, 2, 2, 2.6, 0 });
		g_tuNiangNiangKDPrice[L"���"].push_back({ 1, 2, 2, 2.6, 0 });
		g_tuNiangNiangKDPrice[L"�ӱ�ʡ"].push_back({ 1, 2, 2, 2.6, 0 });
		g_tuNiangNiangKDPrice[L"����ʡ"].push_back({ 1, 2, 2, 2.6, 0 });
		g_tuNiangNiangKDPrice[L"����ʡ"].push_back({ 1, 2, 2, 2.6, 0 });
		g_tuNiangNiangKDPrice[L"ɽ��ʡ"].push_back({ 1, 2, 2, 2.6, 0 });
		g_tuNiangNiangKDPrice[L"����ʡ"].push_back({ 1, 2, 2, 2.6, 0 });
		g_tuNiangNiangKDPrice[L"����ʡ"].push_back({ 1, 2, 2, 2.6, 0 });
		g_tuNiangNiangKDPrice[L"�㶫ʡ"].push_back({ 1, 2, 2, 2.6, 0 });
		g_tuNiangNiangKDPrice[L"����ʡ"].push_back({ 1, 2, 2, 2.6, 0 });
		g_tuNiangNiangKDPrice[L"����׳��������"].push_back({ 1, 2, 2, 2.6, 0 });
		g_tuNiangNiangKDPrice[L"����ʡ"].push_back({ 1, 2, 2, 2.6, 0 });
		g_tuNiangNiangKDPrice[L"����ʡ"].push_back({ 1, 2, 2, 2.6, 0 });
		g_tuNiangNiangKDPrice[L"�Ĵ�ʡ"].push_back({ 1, 2, 2, 2.6, 0 });
		g_tuNiangNiangKDPrice[L"����"].push_back({ 1, 2, 2, 2.6, 0 });

		g_tuNiangNiangKDPrice[L"������ʡ"].push_back({ 1, 2, 2, 2.6, 0 });
		g_tuNiangNiangKDPrice[L"����ʡ"].push_back({ 1, 2, 2, 2.6, 0 });
		g_tuNiangNiangKDPrice[L"����ʡ"].push_back({ 1, 2, 2, 2.6, 0 });
		g_tuNiangNiangKDPrice[L"���Ļ���������"].push_back({ 1, 2, 2, 2.6, 0 });
		g_tuNiangNiangKDPrice[L"����ʡ"].push_back({ 1, 2, 2, 2.6, 0 });

		g_tuNiangNiangKDPrice[L"������"].push_back({ 1, 2, 2, 3,4, 0 });
		g_tuNiangNiangKDPrice[L"�Ϻ�"].push_back({ 1, 2, 2, 3,4, 0 });
		g_tuNiangNiangKDPrice[L"����"].push_back({ 1, 2, 2, 3,4, 0 });
		g_tuNiangNiangKDPrice[L"�ຣʡ"].push_back({ 1, 2, 2, 3,4, 0 });
		//3kg
		g_tuNiangNiangKDPrice[L"����ʡ"].push_back({ 2, 3, 3, 2.9, 0 });
		g_tuNiangNiangKDPrice[L"����ʡ"].push_back({ 2, 3, 3, 2.9, 0 });
		g_tuNiangNiangKDPrice[L"�㽭ʡ"].push_back({ 2, 3, 3, 2.9, 0 });
		g_tuNiangNiangKDPrice[L"����ʡ"].push_back({ 2, 3, 3, 2.9, 0 });
		g_tuNiangNiangKDPrice[L"ɽ��ʡ"].push_back({ 2, 3, 3, 2.9, 0 });
		g_tuNiangNiangKDPrice[L"���"].push_back({ 2, 3, 3, 2.9, 0 });
		g_tuNiangNiangKDPrice[L"�ӱ�ʡ"].push_back({ 2, 3, 3, 2.9, 0 });
		g_tuNiangNiangKDPrice[L"����ʡ"].push_back({ 2, 3, 3, 2.9, 0 });
		g_tuNiangNiangKDPrice[L"����ʡ"].push_back({ 2, 3, 3, 2.9, 0 });
		g_tuNiangNiangKDPrice[L"ɽ��ʡ"].push_back({ 2, 3, 3, 2.9, 0 });
		g_tuNiangNiangKDPrice[L"����ʡ"].push_back({ 2, 3, 3, 2.9, 0 });
		g_tuNiangNiangKDPrice[L"����ʡ"].push_back({ 2, 3, 3, 2.9, 0 });
		g_tuNiangNiangKDPrice[L"�㶫ʡ"].push_back({ 2, 3, 3, 2.9, 0 });
		g_tuNiangNiangKDPrice[L"����ʡ"].push_back({ 2, 3, 3, 2.9, 0 });
		g_tuNiangNiangKDPrice[L"����׳��������"].push_back({ 2, 3, 3, 2.9, 0 });
		g_tuNiangNiangKDPrice[L"����ʡ"].push_back({ 2, 3, 3, 2.9, 0 });
		g_tuNiangNiangKDPrice[L"����ʡ"].push_back({ 2, 3, 3, 2.9, 0 });
		g_tuNiangNiangKDPrice[L"�Ĵ�ʡ"].push_back({ 2, 3, 3, 2.9, 0 });
		g_tuNiangNiangKDPrice[L"����"].push_back({ 2, 3, 3, 2.9, 0 });

		g_tuNiangNiangKDPrice[L"������ʡ"].push_back({ 2, 3, 3, 2.9, 0 });
		g_tuNiangNiangKDPrice[L"����ʡ"].push_back({ 2, 3, 3, 2.9, 0 });
		g_tuNiangNiangKDPrice[L"����ʡ"].push_back({ 2, 3, 3, 2.9, 0 });
		g_tuNiangNiangKDPrice[L"���Ļ���������"].push_back({ 2, 3, 3, 2.9, 0 });
		g_tuNiangNiangKDPrice[L"����ʡ"].push_back({ 2, 3, 3, 2.9, 0 });

		g_tuNiangNiangKDPrice[L"������"].push_back({ 2, 3, 3, 3.8, 0 });
		g_tuNiangNiangKDPrice[L"�Ϻ�"].push_back({ 2, 3, 3, 3.8, 0 });
		g_tuNiangNiangKDPrice[L"����"].push_back({ 2, 3, 3, 3.8, 0 });
		g_tuNiangNiangKDPrice[L"�ຣʡ"].push_back({ 2, 3, 3, 3.8, 0 });
		//3kg����
		g_tuNiangNiangKDPrice[L"����ʡ"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_tuNiangNiangKDPrice[L"����ʡ"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_tuNiangNiangKDPrice[L"�㽭ʡ"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_tuNiangNiangKDPrice[L"����ʡ"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_tuNiangNiangKDPrice[L"ɽ��ʡ"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_tuNiangNiangKDPrice[L"���"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_tuNiangNiangKDPrice[L"�ӱ�ʡ"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_tuNiangNiangKDPrice[L"����ʡ"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_tuNiangNiangKDPrice[L"����ʡ"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_tuNiangNiangKDPrice[L"ɽ��ʡ"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_tuNiangNiangKDPrice[L"����ʡ"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_tuNiangNiangKDPrice[L"����ʡ"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_tuNiangNiangKDPrice[L"�㶫ʡ"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_tuNiangNiangKDPrice[L"����ʡ"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_tuNiangNiangKDPrice[L"����׳��������"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_tuNiangNiangKDPrice[L"����ʡ"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_tuNiangNiangKDPrice[L"����ʡ"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_tuNiangNiangKDPrice[L"�Ĵ�ʡ"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_tuNiangNiangKDPrice[L"����"].push_back({ 3, 0, 1, 3.6, 1.1 });

		g_tuNiangNiangKDPrice[L"������ʡ"].push_back({ 3, 0, 1, 5.1, 2.5 });
		g_tuNiangNiangKDPrice[L"����ʡ"].push_back({ 3, 0, 1, 5.1, 2.5 });
		g_tuNiangNiangKDPrice[L"����ʡ"].push_back({ 3, 0, 1, 5.1, 2.5 });
		g_tuNiangNiangKDPrice[L"���Ļ���������"].push_back({ 3, 0, 1, 5.1, 2.5 });
		g_tuNiangNiangKDPrice[L"����ʡ"].push_back({ 3, 0, 1, 5.1, 2.5 });

		g_tuNiangNiangKDPrice[L"������"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_tuNiangNiangKDPrice[L"�Ϻ�"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_tuNiangNiangKDPrice[L"����"].push_back({ 3, 0, 1, 3.6, 1.1 });
		g_tuNiangNiangKDPrice[L"�ຣʡ"].push_back({ 3, 0, 1, 5.1, 2.5 });
		//��������
		g_tuNiangNiangKDPrice[L"�½�ά���������"].push_back({ 0, 0, 1, 16, 4 });
		g_tuNiangNiangKDPrice[L"����������"].push_back({ 0, 0, 1, 9, 7 });
		g_tuNiangNiangKDPrice[L"����ʡ"].push_back({ 0, 0, 1, 7, 5 });
		g_tuNiangNiangKDPrice[L"���ɹ�������"].push_back({ 0, 0, 1, 8, 6 });
	}
	//�������ʲ�
	{
		//3kg
		g_chuJianNingMengChaKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 3, 0 });
		g_chuJianNingMengChaKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 3, 0 });
		g_chuJianNingMengChaKDPrice[L"�㽭ʡ"].push_back({ 0, 3, 3, 3, 0 });
		g_chuJianNingMengChaKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 3, 0 });
		g_chuJianNingMengChaKDPrice[L"ɽ��ʡ"].push_back({ 0, 3, 3, 3, 0 });
		g_chuJianNingMengChaKDPrice[L"���"].push_back({ 0, 3, 3, 3, 0 });
		g_chuJianNingMengChaKDPrice[L"�ӱ�ʡ"].push_back({ 0, 3, 3, 3, 0 });
		g_chuJianNingMengChaKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 3, 0 });
		g_chuJianNingMengChaKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 3, 0 });
		g_chuJianNingMengChaKDPrice[L"ɽ��ʡ"].push_back({ 0, 3, 3, 3, 0 });
		g_chuJianNingMengChaKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 3, 0 });
		g_chuJianNingMengChaKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 3, 0 });
		g_chuJianNingMengChaKDPrice[L"�㶫ʡ"].push_back({ 0, 3, 3, 3, 0 });
		g_chuJianNingMengChaKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 3, 0 });
		g_chuJianNingMengChaKDPrice[L"����׳��������"].push_back({ 0, 3, 3, 3, 0 });
		g_chuJianNingMengChaKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 3, 0 });
		g_chuJianNingMengChaKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 3, 0 });

		g_chuJianNingMengChaKDPrice[L"�Ĵ�ʡ"].push_back({ 0, 3, 3, 3, 0 });
		g_chuJianNingMengChaKDPrice[L"����"].push_back({ 0, 3, 3, 3, 0 });

		g_chuJianNingMengChaKDPrice[L"������ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_chuJianNingMengChaKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_chuJianNingMengChaKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.5, 0 });

		g_chuJianNingMengChaKDPrice[L"������"].push_back({ 0, 3, 3, 3.9, 0 });
		g_chuJianNingMengChaKDPrice[L"�Ϻ�"].push_back({ 0, 3, 3, 3.9, 0 });
		g_chuJianNingMengChaKDPrice[L"����"].push_back({ 0, 3, 3, 3.9, 0 });

		//3-5kg
		g_chuJianNingMengChaKDPrice[L"����ʡ"].push_back({ 3, 5, 5, 4.5, 0 });
		g_chuJianNingMengChaKDPrice[L"����ʡ"].push_back({ 3, 5, 5, 4.5, 0 });
		g_chuJianNingMengChaKDPrice[L"�㽭ʡ"].push_back({ 3, 5, 5, 4.5, 0 });
		g_chuJianNingMengChaKDPrice[L"����ʡ"].push_back({ 3, 5, 5, 4.5, 0 });
		g_chuJianNingMengChaKDPrice[L"ɽ��ʡ"].push_back({ 3, 5, 5, 4.5, 0 });
		g_chuJianNingMengChaKDPrice[L"���"].push_back({ 3, 5, 5, 4.5, 0 });
		g_chuJianNingMengChaKDPrice[L"�ӱ�ʡ"].push_back({ 3, 5, 5, 4.5, 0 });
		g_chuJianNingMengChaKDPrice[L"����ʡ"].push_back({ 3, 5, 5, 4.5, 0 });
		g_chuJianNingMengChaKDPrice[L"����ʡ"].push_back({ 3, 5, 5, 4.5, 0 });
		g_chuJianNingMengChaKDPrice[L"ɽ��ʡ"].push_back({ 3, 5, 5, 4.5, 0 });
		g_chuJianNingMengChaKDPrice[L"����ʡ"].push_back({ 3, 5, 5, 4.5, 0 });
		g_chuJianNingMengChaKDPrice[L"����ʡ"].push_back({ 3, 5, 5, 4.5, 0 });
		g_chuJianNingMengChaKDPrice[L"�㶫ʡ"].push_back({ 3, 5, 5, 4.5, 0 });
		g_chuJianNingMengChaKDPrice[L"����ʡ"].push_back({ 3, 5, 5, 4.5, 0 });
		g_chuJianNingMengChaKDPrice[L"����׳��������"].push_back({ 3, 5, 5, 4.5, 0 });
		g_chuJianNingMengChaKDPrice[L"����ʡ"].push_back({ 3, 5, 5, 4.5, 0 });
		g_chuJianNingMengChaKDPrice[L"����ʡ"].push_back({ 3, 5, 5, 4.5, 0 });

		g_chuJianNingMengChaKDPrice[L"�Ĵ�ʡ"].push_back({ 3, 5, 5, 4.5, 0 });
		g_chuJianNingMengChaKDPrice[L"����"].push_back({ 3, 5, 5, 4.5, 0 });

		g_chuJianNingMengChaKDPrice[L"������ʡ"].push_back({ 3, 5, 5, 5, 0 });
		g_chuJianNingMengChaKDPrice[L"����ʡ"].push_back({ 3, 5, 5, 5, 0 });
		g_chuJianNingMengChaKDPrice[L"����ʡ"].push_back({ 3, 5, 5, 5, 0 });

		g_chuJianNingMengChaKDPrice[L"������"].push_back({ 3, 5, 5, 6.2, 0 });
		g_chuJianNingMengChaKDPrice[L"�Ϻ�"].push_back({ 3, 5, 5, 6.2, 0 });
		g_chuJianNingMengChaKDPrice[L"����"].push_back({ 3, 5, 5, 6.2, 0 });

		//5kg����
		g_chuJianNingMengChaKDPrice[L"����ʡ"].push_back({ 5, 0, 1, 3.6, 1.2 });
		g_chuJianNingMengChaKDPrice[L"����ʡ"].push_back({ 5, 0, 1, 3.6, 1.2 });
		g_chuJianNingMengChaKDPrice[L"�㽭ʡ"].push_back({ 5, 0, 1, 3.6, 1.2 });
		g_chuJianNingMengChaKDPrice[L"����ʡ"].push_back({ 5, 0, 1, 3.6, 1.2 });
		g_chuJianNingMengChaKDPrice[L"ɽ��ʡ"].push_back({ 5, 0, 1, 3.6, 1.2 });
		g_chuJianNingMengChaKDPrice[L"���"].push_back({ 5, 0, 1, 3.6, 1.2 });
		g_chuJianNingMengChaKDPrice[L"�ӱ�ʡ"].push_back({ 5, 0, 1, 3.6, 1.2 });
		g_chuJianNingMengChaKDPrice[L"����ʡ"].push_back({ 5, 0, 1, 3.6, 1.2 });
		g_chuJianNingMengChaKDPrice[L"����ʡ"].push_back({ 5, 0, 1, 3.6, 1.2 });
		g_chuJianNingMengChaKDPrice[L"ɽ��ʡ"].push_back({ 5, 0, 1, 3.6, 1.2 });
		g_chuJianNingMengChaKDPrice[L"����ʡ"].push_back({ 5, 0, 1, 3.6, 1.2 });
		g_chuJianNingMengChaKDPrice[L"����ʡ"].push_back({ 5, 0, 1, 3.6, 1.2 });
		g_chuJianNingMengChaKDPrice[L"�㶫ʡ"].push_back({ 5, 0, 1, 3.6, 1.2 });
		g_chuJianNingMengChaKDPrice[L"����ʡ"].push_back({ 5, 0, 1, 3.6, 1.2 });
		g_chuJianNingMengChaKDPrice[L"����׳��������"].push_back({ 5, 0, 1, 3.6, 1.2 });
		g_chuJianNingMengChaKDPrice[L"����ʡ"].push_back({ 5, 0, 1, 3.6, 1.2 });
		g_chuJianNingMengChaKDPrice[L"����ʡ"].push_back({ 5, 0, 1, 3.6, 1.2 });

		g_chuJianNingMengChaKDPrice[L"�Ĵ�ʡ"].push_back({ 5, 0, 1, 3.6, 1.2 });
		g_chuJianNingMengChaKDPrice[L"����"].push_back({ 5, 0, 1, 3.6, 1.2 });

		g_chuJianNingMengChaKDPrice[L"������ʡ"].push_back({ 5, 0, 1, 5.2, 2.6 });
		g_chuJianNingMengChaKDPrice[L"����ʡ"].push_back({ 5, 0, 1, 5.2, 2.6 });
		g_chuJianNingMengChaKDPrice[L"����ʡ"].push_back({ 5, 0, 1, 5.2, 2.6 });

		g_chuJianNingMengChaKDPrice[L"������"].push_back({ 5, 0, 1, 3.6, 1.2 });
		g_chuJianNingMengChaKDPrice[L"�Ϻ�"].push_back({ 5, 0, 1, 3.6, 1.2 });
		g_chuJianNingMengChaKDPrice[L"����"].push_back({ 5, 0, 1, 3.6, 1.2 });
		//��������
		g_chuJianNingMengChaKDPrice[L"�½�ά���������"].push_back({ 0, 0, 1, 16, 4 });
		g_chuJianNingMengChaKDPrice[L"����������"].push_back({ 0, 0, 1, 9, 7 });
		g_chuJianNingMengChaKDPrice[L"���Ļ���������"].push_back({ 0, 0, 1, 7, 5 });
		g_chuJianNingMengChaKDPrice[L"�ຣʡ"].push_back({ 0, 0, 1, 7, 5 });
		g_chuJianNingMengChaKDPrice[L"����ʡ"].push_back({ 0, 0, 1, 7, 5 });
		g_chuJianNingMengChaKDPrice[L"���ɹ�������"].push_back({ 0, 0, 1, 8, 6 });
		g_chuJianNingMengChaKDPrice[L"����ʡ"].push_back({ 0, 0, 1, 6, 5 });
	}

	//�����
	{
		//1kg
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2.1, 0 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2.1, 0 });
		g_tuKaDuoGeKDPrice[L"�㽭ʡ"].push_back({ 0, 1, 1, 2.1, 0 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2.1, 0 });
		g_tuKaDuoGeKDPrice[L"ɽ��ʡ"].push_back({ 0, 1, 1, 2.1, 0 });
		g_tuKaDuoGeKDPrice[L"���"].push_back({ 0, 1, 1, 2.1, 0 });
		g_tuKaDuoGeKDPrice[L"�ӱ�ʡ"].push_back({ 0, 1, 1, 2.1, 0 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2.1, 0 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2.1, 0 });
		g_tuKaDuoGeKDPrice[L"ɽ��ʡ"].push_back({ 0, 1, 1, 2.1, 0 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2.1, 0 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2.1, 0 });
		g_tuKaDuoGeKDPrice[L"�㶫ʡ"].push_back({ 0, 1, 1, 2.1, 0 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2.1, 0 });
		g_tuKaDuoGeKDPrice[L"����׳��������"].push_back({ 0, 1, 1, 2.1, 0 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2.1, 0 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2.1, 0 });

		g_tuKaDuoGeKDPrice[L"�Ĵ�ʡ"].push_back({ 0, 1, 1, 2.1, 0 });
		g_tuKaDuoGeKDPrice[L"����"].push_back({ 0, 1, 1, 2.1, 0 });

		g_tuKaDuoGeKDPrice[L"������ʡ"].push_back({ 0, 1, 1, 2.1, 0 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2.1, 0 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 0, 1, 1, 2.1, 0 });

		g_tuKaDuoGeKDPrice[L"������"].push_back({ 0, 1, 1, 2.9, 0 });
		g_tuKaDuoGeKDPrice[L"�Ϻ�"].push_back({ 0, 1, 1, 2.9, 0 });
		g_tuKaDuoGeKDPrice[L"����"].push_back({ 0, 1, 1, 2.9, 0 });
		//2kg
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 1, 2, 2, 2.5, 0 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 1, 2, 2, 2.5, 0 });
		g_tuKaDuoGeKDPrice[L"�㽭ʡ"].push_back({ 1, 2, 2, 2.5, 0 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 1, 2, 2, 2.5, 0 });
		g_tuKaDuoGeKDPrice[L"ɽ��ʡ"].push_back({ 1, 2, 2, 2.5, 0 });
		g_tuKaDuoGeKDPrice[L"���"].push_back({ 1, 2, 2, 2.5, 0 });
		g_tuKaDuoGeKDPrice[L"�ӱ�ʡ"].push_back({ 1, 2, 2, 2.5, 0 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 1, 2, 2, 2.5, 0 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 1, 2, 2, 2.5, 0 });
		g_tuKaDuoGeKDPrice[L"ɽ��ʡ"].push_back({ 1, 2, 2, 2.5, 0 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 1, 2, 2, 2.5, 0 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 1, 2, 2, 2.5, 0 });
		g_tuKaDuoGeKDPrice[L"�㶫ʡ"].push_back({ 1, 2, 2, 2.5, 0 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 1, 2, 2, 2.5, 0 });
		g_tuKaDuoGeKDPrice[L"����׳��������"].push_back({ 1, 2, 2, 2.5, 0 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 1, 2, 2, 2.5, 0 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 1, 2, 2, 2.5, 0 });

		g_tuKaDuoGeKDPrice[L"�Ĵ�ʡ"].push_back({ 1, 2, 2, 2.5, 0 });
		g_tuKaDuoGeKDPrice[L"����"].push_back({ 1, 2, 2, 2.5, 0 });

		g_tuKaDuoGeKDPrice[L"������ʡ"].push_back({ 1, 2, 2, 2.5, 0 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 1, 2, 2, 2.5, 0 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 1, 2, 2, 2.5, 0 });

		g_tuKaDuoGeKDPrice[L"������"].push_back({ 1, 2, 2, 3.3, 0 });
		g_tuKaDuoGeKDPrice[L"�Ϻ�"].push_back({ 1, 2, 2, 3.3, 0 });
		g_tuKaDuoGeKDPrice[L"����"].push_back({ 1, 2, 2, 3.3, 0 });
		//3kg
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 2, 3, 3, 2.8, 0 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 2, 3, 3, 2.8, 0 });
		g_tuKaDuoGeKDPrice[L"�㽭ʡ"].push_back({ 2, 3, 3, 2.8, 0 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 2, 3, 3, 2.8, 0 });
		g_tuKaDuoGeKDPrice[L"ɽ��ʡ"].push_back({ 2, 3, 3, 2.8, 0 });
		g_tuKaDuoGeKDPrice[L"���"].push_back({ 2, 3, 3, 2.8, 0 });
		g_tuKaDuoGeKDPrice[L"�ӱ�ʡ"].push_back({ 2, 3, 3, 2.8, 0 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 2, 3, 3, 2.8, 0 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 2, 3, 3, 2.8, 0 });
		g_tuKaDuoGeKDPrice[L"ɽ��ʡ"].push_back({ 2, 3, 3, 2.8, 0 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 2, 3, 3, 2.8, 0 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 2, 3, 3, 2.8, 0 });
		g_tuKaDuoGeKDPrice[L"�㶫ʡ"].push_back({ 2, 3, 3, 2.8, 0 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 2, 3, 3, 2.8, 0 });
		g_tuKaDuoGeKDPrice[L"����׳��������"].push_back({ 2, 3, 3, 2.8, 0 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 2, 3, 3, 2.8, 0 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 2, 3, 3, 2.8, 0 });

		g_tuKaDuoGeKDPrice[L"�Ĵ�ʡ"].push_back({ 2, 3, 3, 2.8, 0 });
		g_tuKaDuoGeKDPrice[L"����"].push_back({ 2, 3, 3, 2.8, 0 });

		g_tuKaDuoGeKDPrice[L"������ʡ"].push_back({ 2, 3, 3, 2.8, 0 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 2, 3, 3, 2.8, 0 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 2, 3, 3, 2.8, 0 });

		g_tuKaDuoGeKDPrice[L"������"].push_back({ 2, 3, 3, 3.6, 0 });
		g_tuKaDuoGeKDPrice[L"�Ϻ�"].push_back({ 2, 3, 3, 3.6, 0 });
		g_tuKaDuoGeKDPrice[L"����"].push_back({ 2, 3, 3, 3.6, 0 });

		//3-5kg
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 3, 5, 5, 4.2, 0 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 3, 5, 5, 4.2, 0 });
		g_tuKaDuoGeKDPrice[L"�㽭ʡ"].push_back({ 3, 5, 5, 4.2, 0 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 3, 5, 5, 4.2, 0 });
		g_tuKaDuoGeKDPrice[L"ɽ��ʡ"].push_back({ 3, 5, 5, 4.2, 0 });
		g_tuKaDuoGeKDPrice[L"���"].push_back({ 3, 5, 5, 4.2, 0 });
		g_tuKaDuoGeKDPrice[L"�ӱ�ʡ"].push_back({ 3, 5, 5, 4.2, 0 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 3, 5, 5, 4.2, 0 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 3, 5, 5, 4.2, 0 });
		g_tuKaDuoGeKDPrice[L"ɽ��ʡ"].push_back({ 3, 5, 5, 4.2, 0 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 3, 5, 5, 4.2, 0 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 3, 5, 5, 4.2, 0 });
		g_tuKaDuoGeKDPrice[L"�㶫ʡ"].push_back({ 3, 5, 5, 4.2, 0 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 3, 5, 5, 4.2, 0 });
		g_tuKaDuoGeKDPrice[L"����׳��������"].push_back({ 3, 5, 5, 4.2, 0 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 3, 5, 5, 4.2, 0 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 3, 5, 5, 4.2, 0 });

		g_tuKaDuoGeKDPrice[L"�Ĵ�ʡ"].push_back({ 3, 5, 5, 4.2, 0 });
		g_tuKaDuoGeKDPrice[L"����"].push_back({ 3, 5, 5, 4.2, 0 });

		g_tuKaDuoGeKDPrice[L"������ʡ"].push_back({ 3, 5, 5, 4.2, 0 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 3, 5, 5, 4.2, 0 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 3, 5, 5, 4.2, 0 });

		g_tuKaDuoGeKDPrice[L"������"].push_back({ 3, 5, 5, 5.9, 0 });
		g_tuKaDuoGeKDPrice[L"�Ϻ�"].push_back({ 3, 5, 5, 5.9, 0 });
		g_tuKaDuoGeKDPrice[L"����"].push_back({ 3, 5, 5, 5.9, 0 });

		//5kg����
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 5, 0, 1, 3.6, 1.1 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 5, 0, 1, 3.6, 1.1 });
		g_tuKaDuoGeKDPrice[L"�㽭ʡ"].push_back({ 5, 0, 1, 3.6, 1.1 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 5, 0, 1, 3.6, 1.1 });
		g_tuKaDuoGeKDPrice[L"ɽ��ʡ"].push_back({ 5, 0, 1, 3.6, 1.1 });
		g_tuKaDuoGeKDPrice[L"���"].push_back({ 5, 0, 1, 3.6, 1.1 });
		g_tuKaDuoGeKDPrice[L"�ӱ�ʡ"].push_back({ 5, 0, 1, 3.6, 1.1 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 5, 0, 1, 3.6, 1.1 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 5, 0, 1, 3.6, 1.1 });
		g_tuKaDuoGeKDPrice[L"ɽ��ʡ"].push_back({ 5, 0, 1, 3.6, 1.1 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 5, 0, 1, 3.6, 1.1 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 5, 0, 1, 3.6, 1.1 });
		g_tuKaDuoGeKDPrice[L"�㶫ʡ"].push_back({ 5, 0, 1, 3.6, 1.1 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 5, 0, 1, 3.6, 1.1 });
		g_tuKaDuoGeKDPrice[L"����׳��������"].push_back({ 5, 0, 1, 3.6, 1.1 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 5, 0, 1, 3.6, 1.1 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 5, 0, 1, 3.6, 1.1 });

		g_tuKaDuoGeKDPrice[L"�Ĵ�ʡ"].push_back({ 5, 0, 1, 3.6, 1.1 });
		g_tuKaDuoGeKDPrice[L"����"].push_back({ 5, 0, 1, 3.6, 1.1 });

		g_tuKaDuoGeKDPrice[L"������ʡ"].push_back({ 5, 0, 1, 5, 2.5 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 5, 0, 1, 5, 2.5 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 5, 0, 1, 5, 2.5 });

		g_tuKaDuoGeKDPrice[L"������"].push_back({ 5, 0, 1, 3.6, 1.1 });
		g_tuKaDuoGeKDPrice[L"�Ϻ�"].push_back({ 5, 0, 1, 3.6, 1.1 });
		g_tuKaDuoGeKDPrice[L"����"].push_back({ 5, 0, 1, 3.6, 1.1 });
		//��������
		g_tuKaDuoGeKDPrice[L"�½�ά���������"].push_back({ 0, 0, 1, 16, 4 });
		g_tuKaDuoGeKDPrice[L"����������"].push_back({ 0, 0, 1, 9, 7 });
		g_tuKaDuoGeKDPrice[L"���Ļ���������"].push_back({ 0, 0, 1, 7, 5 });
		g_tuKaDuoGeKDPrice[L"�ຣʡ"].push_back({ 0, 0, 1, 7, 5 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 0, 0, 1, 7, 5 });
		g_tuKaDuoGeKDPrice[L"���ɹ�������"].push_back({ 0, 0, 1, 8, 6 });
		g_tuKaDuoGeKDPrice[L"����ʡ"].push_back({ 0, 0, 1, 6, 5 });
	}
	//С����
	{
		//3kg
		g_xiaoBaiXiongKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 2.9, 0 });
		g_xiaoBaiXiongKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 2.9, 0 });
		g_xiaoBaiXiongKDPrice[L"�㽭ʡ"].push_back({ 0, 3, 3, 2.9, 0 });
		g_xiaoBaiXiongKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 2.9, 0 });
		g_xiaoBaiXiongKDPrice[L"ɽ��ʡ"].push_back({ 0, 3, 3, 2.9, 0 });
		g_xiaoBaiXiongKDPrice[L"���"].push_back({ 0, 3, 3, 2.9, 0 });
		g_xiaoBaiXiongKDPrice[L"�ӱ�ʡ"].push_back({ 0, 3, 3, 2.9, 0 });
		g_xiaoBaiXiongKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 2.9, 0 });
		g_xiaoBaiXiongKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 2.9, 0 });
		g_xiaoBaiXiongKDPrice[L"ɽ��ʡ"].push_back({ 0, 3, 3, 2.9, 0 });
		g_xiaoBaiXiongKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 2.9, 0 });
		g_xiaoBaiXiongKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 2.9, 0 });
		g_xiaoBaiXiongKDPrice[L"�㶫ʡ"].push_back({ 0, 3, 3, 2.9, 0 });
		g_xiaoBaiXiongKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 2.9, 0 });
		g_xiaoBaiXiongKDPrice[L"����׳��������"].push_back({ 0, 3, 3, 2.9, 0 });
		g_xiaoBaiXiongKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 2.9, 0 });
		g_xiaoBaiXiongKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 2.9, 0 });

		g_xiaoBaiXiongKDPrice[L"�Ĵ�ʡ"].push_back({ 0, 3, 3, 2.9, 0 });
		g_xiaoBaiXiongKDPrice[L"����"].push_back({ 0, 3, 3, 2.9, 0 });

		g_xiaoBaiXiongKDPrice[L"������ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xiaoBaiXiongKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_xiaoBaiXiongKDPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.5, 0 });

		g_xiaoBaiXiongKDPrice[L"������"].push_back({ 0, 3, 3, 3.9, 0 });
		g_xiaoBaiXiongKDPrice[L"�Ϻ�"].push_back({ 0, 3, 3, 3.9, 0 });
		g_xiaoBaiXiongKDPrice[L"����"].push_back({ 0, 3, 3, 3.9, 0 });

		//3kg����
		g_xiaoBaiXiongKDPrice[L"����ʡ"].push_back({ 3, 0, 1, 3.6, 1.2 });
		g_xiaoBaiXiongKDPrice[L"����ʡ"].push_back({ 3, 0, 1, 3.6, 1.2 });
		g_xiaoBaiXiongKDPrice[L"�㽭ʡ"].push_back({ 3, 0, 1, 3.6, 1.2 });
		g_xiaoBaiXiongKDPrice[L"����ʡ"].push_back({ 3, 0, 1, 3.6, 1.2 });
		g_xiaoBaiXiongKDPrice[L"ɽ��ʡ"].push_back({ 3, 0, 1, 3.6, 1.2 });
		g_xiaoBaiXiongKDPrice[L"���"].push_back({ 3, 0, 1, 3.6, 1.2 });
		g_xiaoBaiXiongKDPrice[L"�ӱ�ʡ"].push_back({ 3, 0, 1, 3.6, 1.2 });
		g_xiaoBaiXiongKDPrice[L"����ʡ"].push_back({ 3, 0, 1, 3.6, 1.2 });
		g_xiaoBaiXiongKDPrice[L"����ʡ"].push_back({ 3, 0, 1, 3.6, 1.2 });
		g_xiaoBaiXiongKDPrice[L"ɽ��ʡ"].push_back({ 3, 0, 1, 3.6, 1.2 });
		g_xiaoBaiXiongKDPrice[L"����ʡ"].push_back({ 3, 0, 1, 3.6, 1.2 });
		g_xiaoBaiXiongKDPrice[L"����ʡ"].push_back({ 3, 0, 1, 3.6, 1.2 });
		g_xiaoBaiXiongKDPrice[L"�㶫ʡ"].push_back({ 3, 0, 1, 3.6, 1.2 });
		g_xiaoBaiXiongKDPrice[L"����ʡ"].push_back({ 3, 0, 1, 3.6, 1.2 });
		g_xiaoBaiXiongKDPrice[L"����׳��������"].push_back({ 3, 0, 1, 3.6, 1.2 });
		g_xiaoBaiXiongKDPrice[L"����ʡ"].push_back({ 3, 0, 1, 3.6, 1.2 });
		g_xiaoBaiXiongKDPrice[L"����ʡ"].push_back({ 3, 0, 1, 3.6, 1.2 });

		g_xiaoBaiXiongKDPrice[L"�Ĵ�ʡ"].push_back({ 3, 0, 1, 3.6, 1.2 });
		g_xiaoBaiXiongKDPrice[L"����"].push_back({ 3, 0, 1, 3.6, 1.2 });

		g_xiaoBaiXiongKDPrice[L"������ʡ"].push_back({ 3, 0, 1, 5.2, 2.6 });
		g_xiaoBaiXiongKDPrice[L"����ʡ"].push_back({ 3, 0, 1, 5.2, 2.6 });
		g_xiaoBaiXiongKDPrice[L"����ʡ"].push_back({ 3, 0, 1, 5.2, 2.6 });

		g_xiaoBaiXiongKDPrice[L"������"].push_back({ 3, 0, 1, 3.6, 1.2 });
		g_xiaoBaiXiongKDPrice[L"�Ϻ�"].push_back({ 3, 0, 1, 3.6, 1.2 });
		g_xiaoBaiXiongKDPrice[L"����"].push_back({ 3, 0, 1, 3.6, 1.2 });
		//��������
		g_xiaoBaiXiongKDPrice[L"�½�ά���������"].push_back({ 0, 0, 1, 16, 4 });
		g_xiaoBaiXiongKDPrice[L"����������"].push_back({ 0, 0, 1, 9, 7 });
		g_xiaoBaiXiongKDPrice[L"���Ļ���������"].push_back({ 0, 0, 1, 7, 5 });
		g_xiaoBaiXiongKDPrice[L"�ຣʡ"].push_back({ 0, 0, 1, 7, 5 });
		g_xiaoBaiXiongKDPrice[L"����ʡ"].push_back({ 0, 0, 1, 7, 5 });
		g_xiaoBaiXiongKDPrice[L"���ɹ�������"].push_back({ 0, 0, 1, 8, 6 });
		g_xiaoBaiXiongKDPrice[L"����ʡ"].push_back({ 0, 0, 1, 6, 5 });
	}
	//��ά��
}

//----------------------------------------------------------------------------------//