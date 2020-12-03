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
//----------------------------------------------------------------------------------//

//------------------------------------˳��۸�--------------------------------------//
//����ҫ��
std::vector< std::list<sExpressPriceInfo> > g_yongChuangYaoHuiSFPrice;
//����
std::vector< std::list<sExpressPriceInfo> > g_miYaSFPrice;
//��һ��԰
std::vector< std::list<sExpressPriceInfo> > g_qiYiJiangYuanSFPrice;
//----------------------------------------------------------------------------------//


//------------------------------------���˼۸�--------------------------------------//
//����ҫ��
std::map< std::wstring, sLargeExpressPriceInfo > g_yongChuangYaoHuiZTKYPrice;
//�����
std::map< std::wstring, sLargeExpressPriceInfo > g_xinMaBangZTKYPrice;
//����Ƽ�
std::map< std::wstring, sLargeExpressPriceInfo > g_yiMaiKeJiZTKYPrice;
//����
std::map< std::wstring, sLargeExpressPriceInfo > g_miYaZTKYPrice;
//��һ��԰
std::map< std::wstring, sLargeExpressPriceInfo > g_qiYiJiangYuanZTKYPrice;
//----------------------------------------------------------------------------------//


//----------------------------------�ɱ�����۸���---------------------------------//
std::map< std::wstring, sLargeExpressPriceInfo > g_chengBenZTKYPrice;

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
		g_chengBenZTKYPrice[L"�Ϻ�"] = { 25, 1.1 };
		g_chengBenZTKYPrice[L"����"] = { 23, 1.1 };
		g_chengBenZTKYPrice[L"����ʡ"] = { 23, 1.1 };
		g_chengBenZTKYPrice[L"����ʡ"] = { 23, 1.1 };
		g_chengBenZTKYPrice[L"�㽭ʡ"] = { 23, 1.1 };
		g_chengBenZTKYPrice[L"����ʡ"] = { 23, 1.1 };
		g_chengBenZTKYPrice[L"ɽ��ʡ"] = { 23, 1.1 };
		g_chengBenZTKYPrice[L"���"] = { 25, 1.1 };
		g_chengBenZTKYPrice[L"�ӱ�ʡ"] = { 23, 1.1 };
		g_chengBenZTKYPrice[L"����ʡ"] = { 23, 1.1 };
		g_chengBenZTKYPrice[L"����ʡ"] = { 23, 1.1 };
		g_chengBenZTKYPrice[L"ɽ��ʡ"] = { 23, 1.1 };
		g_chengBenZTKYPrice[L"����ʡ"] = { 23, 1.1 };
		g_chengBenZTKYPrice[L"����ʡ"] = { 23, 1.1 };
		g_chengBenZTKYPrice[L"�㶫ʡ"] = { 23, 1.1 };
		g_chengBenZTKYPrice[L"����ʡ"] = { 23, 1.1 };
		g_chengBenZTKYPrice[L"����׳��������"] = { 23, 1.1 };
		g_chengBenZTKYPrice[L"�Ĵ�ʡ"] = { 20, 0.8 };
		g_chengBenZTKYPrice[L"���Ӳ���Ǽ��������"] = { 50, 1.5 };
		g_chengBenZTKYPrice[L"��֦����"] = { 20, 1 };

		g_chengBenZTKYPrice[L"����"] = { 23, 1 };
		g_chengBenZTKYPrice[L"����ʡ"] = { 30, 1.1 };
		g_chengBenZTKYPrice[L"����ʡ"] = { 23, 1.2 };
		g_chengBenZTKYPrice[L"����ʡ"] = { 33, 1.6 };
		g_chengBenZTKYPrice[L"���Ļ���������"] = { 40, 1.5 };
		g_chengBenZTKYPrice[L"�ຣʡ"] = { 25, 2.6 };
		g_chengBenZTKYPrice[L"������ʡ"] = { 35, 1.5 };
		g_chengBenZTKYPrice[L"����ʡ"] = { 35, 1.5 };
		g_chengBenZTKYPrice[L"����ʡ"] = { 35, 1.5 };
		g_chengBenZTKYPrice[L"���ɹ�������"] = { 40, 1.5 };
		g_chengBenZTKYPrice[L"����ʡ"] = { 40, 2.5 };
		g_chengBenZTKYPrice[L"�½�ά���������"] = { 50, 3 };
		g_chengBenZTKYPrice[L"����������"] = { 70, 3 };
	}
	//����ҫ����ͨ����
	{
		g_yongChuangYaoHuiZTKYPrice[L"�Ϻ�"] = {27.5, 1.3};
		g_yongChuangYaoHuiZTKYPrice[L"����"] = {27.5, 1.3};
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"] = {27.5, 1.3};
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"] = {27.5, 1.3};
		g_yongChuangYaoHuiZTKYPrice[L"�㽭ʡ"] = {27.5, 1.3};
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"] = {27.5, 1.3};
		g_yongChuangYaoHuiZTKYPrice[L"ɽ��ʡ"] = {27.5, 1.3};
		g_yongChuangYaoHuiZTKYPrice[L"���"] = {27.5, 1.3};
		g_yongChuangYaoHuiZTKYPrice[L"�ӱ�ʡ"] = {27.5, 1.3};
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"] = {27.5, 1.3};
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"] = {27.5, 1.3};
		g_yongChuangYaoHuiZTKYPrice[L"ɽ��ʡ"] = {27.5, 1.3};
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"] = {27.5, 1.3};
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"] = {27.5, 1.3};
		g_yongChuangYaoHuiZTKYPrice[L"�㶫ʡ"] = {27.5, 1.3};
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"] = {27.5, 1.3};
		g_yongChuangYaoHuiZTKYPrice[L"����׳��������"] = {27.5, 1.3};
		g_yongChuangYaoHuiZTKYPrice[L"�Ĵ�ʡ"] = {22.5, 1};
		g_yongChuangYaoHuiZTKYPrice[L"���β���������"] = {50, 1.5};
		g_yongChuangYaoHuiZTKYPrice[L"���Ӳ���Ǽ��������"] = {50, 1.5};
		g_yongChuangYaoHuiZTKYPrice[L"��ɽ����������"] = {50, 1.5};
		g_yongChuangYaoHuiZTKYPrice[L"����"] = {27.5, 1.2};
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"] = {33, 1.4};
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"] = {27.5, 1.4};
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"] = {35, 3};
		g_yongChuangYaoHuiZTKYPrice[L"���Ļ���������"] = {42.5, 2.8};
		g_yongChuangYaoHuiZTKYPrice[L"�ຣʡ"] = {42.5, 2.8};
		g_yongChuangYaoHuiZTKYPrice[L"������ʡ"] = {37, 1.4};
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"] = {37, 1.4};
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"] = {37, 1.4};
		g_yongChuangYaoHuiZTKYPrice[L"���ɹ�������"] = {72.5, 3};
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"] = {42, 2.7};
		g_yongChuangYaoHuiZTKYPrice[L"�½�ά���������"] = {82.5, 3.2};
		g_yongChuangYaoHuiZTKYPrice[L"����������"] = {75, 4.2};
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

	//�������ͨ����
	{
		g_xinMaBangZTKYPrice[L"�Ϻ�"] = { 27, 1.3 };
		g_xinMaBangZTKYPrice[L"����"] = { 27, 1.3 };
		g_xinMaBangZTKYPrice[L"����ʡ"] = { 27, 1.3 };
		g_xinMaBangZTKYPrice[L"����ʡ"] = { 27, 1.3 };
		g_xinMaBangZTKYPrice[L"�㽭ʡ"] = { 27, 1.3 };
		g_xinMaBangZTKYPrice[L"����ʡ"] = { 27, 1.3 };
		g_xinMaBangZTKYPrice[L"ɽ��ʡ"] = { 27, 1.3 };
		g_xinMaBangZTKYPrice[L"���"] = { 27, 1.3 };
		g_xinMaBangZTKYPrice[L"�ӱ�ʡ"] = { 27, 1.3 };
		g_xinMaBangZTKYPrice[L"����ʡ"] = { 27, 1.3 };
		g_xinMaBangZTKYPrice[L"����ʡ"] = { 27, 1.3 };
		g_xinMaBangZTKYPrice[L"ɽ��ʡ"] = { 27, 1.3 };
		g_xinMaBangZTKYPrice[L"����ʡ"] = { 27, 1.3 };
		g_xinMaBangZTKYPrice[L"����ʡ"] = { 27, 1.3 };
		g_xinMaBangZTKYPrice[L"�㶫ʡ"] = { 27, 1.3 };
		g_xinMaBangZTKYPrice[L"����ʡ"] = { 27, 1.3 };
		g_xinMaBangZTKYPrice[L"����׳��������"] = { 27, 1.3 };
		g_xinMaBangZTKYPrice[L"�Ĵ�ʡ"] = { 23, 1.1 };
		g_xinMaBangZTKYPrice[L"���β���������"] = { 52, 1.5 };
		g_xinMaBangZTKYPrice[L"���Ӳ���Ǽ��������"] = { 52, 1.5 };
		g_xinMaBangZTKYPrice[L"��ɽ����������"] = { 52, 1.5 };
		g_xinMaBangZTKYPrice[L"����"] = { 27, 1.2 };
		g_xinMaBangZTKYPrice[L"����ʡ"] = { 27, 1.4 };
		g_xinMaBangZTKYPrice[L"����ʡ"] = { 27, 1.4 };
		g_xinMaBangZTKYPrice[L"����ʡ"] = { 35, 3 };
		g_xinMaBangZTKYPrice[L"���Ļ���������"] = { 45, 2.8 };
		g_xinMaBangZTKYPrice[L"�ຣʡ"] = { 45, 2.8 };
		g_xinMaBangZTKYPrice[L"������ʡ"] = { 37, 1.6 };
		g_xinMaBangZTKYPrice[L"����ʡ"] = { 37, 1.6 };
		g_xinMaBangZTKYPrice[L"����ʡ"] = { 37, 1.6 };
		g_xinMaBangZTKYPrice[L"���ɹ�������"] = { 75, 3 };
		g_xinMaBangZTKYPrice[L"����ʡ"] = { 42, 2.7 };
		g_xinMaBangZTKYPrice[L"�½�ά���������"] = { 85, 3.2 };
		g_xinMaBangZTKYPrice[L"����������"] = { 75, 4.2 };
	}
	//����Ƽ���ͨ����
	{
		g_yiMaiKeJiZTKYPrice[L"�Ĵ�ʡ"] = { 25, 1.1 };
		g_yiMaiKeJiZTKYPrice[L"���β���������"] = { 25, 1.5 };
		g_yiMaiKeJiZTKYPrice[L"���Ӳ���Ǽ��������"] = { 25, 1.5 };
		g_yiMaiKeJiZTKYPrice[L"��ɽ����������"] = { 25, 1.5 };
		g_yiMaiKeJiZTKYPrice[L"�Ϻ�"] = { 28, 1.5 };
		g_yiMaiKeJiZTKYPrice[L"����"] = { 28, 1.5 };
		g_yiMaiKeJiZTKYPrice[L"����ʡ"] = { 28, 1.5 };
		g_yiMaiKeJiZTKYPrice[L"����ʡ"] = { 28, 1.5 };
		g_yiMaiKeJiZTKYPrice[L"�㽭ʡ"] = { 28, 1.5 };
		g_yiMaiKeJiZTKYPrice[L"����ʡ"] = { 28, 1.5 };
		g_yiMaiKeJiZTKYPrice[L"ɽ��ʡ"] = { 28, 1.5 };
		g_yiMaiKeJiZTKYPrice[L"���"] = { 28, 1.5 };
		g_yiMaiKeJiZTKYPrice[L"�ӱ�ʡ"] = { 28, 1.5 };
		g_yiMaiKeJiZTKYPrice[L"����ʡ"] = { 28, 1.5 };
		g_yiMaiKeJiZTKYPrice[L"����ʡ"] = { 28, 1.5 };
		g_yiMaiKeJiZTKYPrice[L"ɽ��ʡ"] = { 28, 1.5 };
		g_yiMaiKeJiZTKYPrice[L"����ʡ"] = { 28, 1.5 };
		g_yiMaiKeJiZTKYPrice[L"����ʡ"] = { 28, 1.5 };
		g_yiMaiKeJiZTKYPrice[L"�㶫ʡ"] = { 28, 1.5 };
		g_yiMaiKeJiZTKYPrice[L"����ʡ"] = { 28, 1.5 };
		g_yiMaiKeJiZTKYPrice[L"����׳��������"] = { 28, 1.5 };
		g_yiMaiKeJiZTKYPrice[L"����"] = { 28, 1.3 };
		g_yiMaiKeJiZTKYPrice[L"����ʡ"] = { 28, 1.5 };
		g_yiMaiKeJiZTKYPrice[L"����ʡ"] = { 28, 1.5 };
		g_yiMaiKeJiZTKYPrice[L"����ʡ"] = { 28, 3 };
		g_yiMaiKeJiZTKYPrice[L"�ຣʡ"] = { 75, 3 };
		g_yiMaiKeJiZTKYPrice[L"������ʡ"] = { 28, 1.8 };
		g_yiMaiKeJiZTKYPrice[L"����ʡ"] = { 28, 1.8 };
		g_yiMaiKeJiZTKYPrice[L"����ʡ"] = { 28, 1.8 };
		g_yiMaiKeJiZTKYPrice[L"����ʡ"] = { 28, 3 };
		g_yiMaiKeJiZTKYPrice[L"�½�ά���������"] = { 85, 3.5 };
		g_yiMaiKeJiZTKYPrice[L"����������"] = { 65, 4.5 };
		g_yiMaiKeJiZTKYPrice[L"���Ļ���������"] = { 54, 3 };
		g_yiMaiKeJiZTKYPrice[L"���ɹ�������"] = { 75, 3.5 };
	}
	//������ͨ����
	{
		g_miYaZTKYPrice[L"�Ϻ�"] = { 27.5, 1.3 };
		g_miYaZTKYPrice[L"����"] = { 27.5, 1.3 };
		g_miYaZTKYPrice[L"����ʡ"] = { 27.5, 1.3 };
		g_miYaZTKYPrice[L"����ʡ"] = { 27.5, 1.3 };
		g_miYaZTKYPrice[L"�㽭ʡ"] = { 27.5, 1.3 };
		g_miYaZTKYPrice[L"����ʡ"] = { 27.5, 1.3 };
		g_miYaZTKYPrice[L"ɽ��ʡ"] = { 27.5, 1.3 };
		g_miYaZTKYPrice[L"���"] = { 27.5, 1.3 };
		g_miYaZTKYPrice[L"�ӱ�ʡ"] = { 27.5, 1.3 };
		g_miYaZTKYPrice[L"����ʡ"] = { 27.5, 1.3 };
		g_miYaZTKYPrice[L"����ʡ"] = { 27.5, 1.3 };
		g_miYaZTKYPrice[L"ɽ��ʡ"] = { 27.5, 1.3 };
		g_miYaZTKYPrice[L"����ʡ"] = { 27.5, 1.3 };
		g_miYaZTKYPrice[L"����ʡ"] = { 27.5, 1.3 };
		g_miYaZTKYPrice[L"�㶫ʡ"] = { 27.5, 1.3 };
		g_miYaZTKYPrice[L"����ʡ"] = { 27.5, 1.3 };
		g_miYaZTKYPrice[L"����׳��������"] = { 27.5, 1.3 };
		g_miYaZTKYPrice[L"�Ĵ�ʡ"] = { 22.5, 1 };
		g_miYaZTKYPrice[L"���β���������"] = { 50, 1.6 };
		g_miYaZTKYPrice[L"���Ӳ���Ǽ��������"] = { 50, 1.6 };
		g_miYaZTKYPrice[L"��ɽ����������"] = { 50, 1.6 };
		g_miYaZTKYPrice[L"����"] = { 27.5, 1.2 };
		g_miYaZTKYPrice[L"����ʡ"] = { 32, 1.4 };
		g_miYaZTKYPrice[L"����ʡ"] = { 27.5, 1.4 };
		g_miYaZTKYPrice[L"����ʡ"] = { 35, 3 };
		g_miYaZTKYPrice[L"���Ļ���������"] = { 42.5, 2.8 };
		g_miYaZTKYPrice[L"�ຣʡ"] = { 42.5, 2.8 };
		g_miYaZTKYPrice[L"������ʡ"] = { 37, 1.7 };
		g_miYaZTKYPrice[L"����ʡ"] = { 37, 1.7 };
		g_miYaZTKYPrice[L"����ʡ"] = { 37, 1.7 };
		g_miYaZTKYPrice[L"���ɹ�������"] = { 72.5, 3 };
		g_miYaZTKYPrice[L"����ʡ"] = { 42, 2.7 };
		g_miYaZTKYPrice[L"�½�ά���������"] = { 82.5, 3.2 };
		g_miYaZTKYPrice[L"����������"] = { 72, 4.2 };
	}
	//��һ��԰��ͨ����
	{

		g_qiYiJiangYuanZTKYPrice[L"�Ϻ�"] = { 27.5, 1.3 };
		g_qiYiJiangYuanZTKYPrice[L"����"] = { 27.5, 1.3 };
		g_qiYiJiangYuanZTKYPrice[L"����ʡ"] = { 27.5, 1.3 };
		g_qiYiJiangYuanZTKYPrice[L"����ʡ"] = { 27.5, 1.3 };
		g_qiYiJiangYuanZTKYPrice[L"�㽭ʡ"] = { 27.5, 1.3 };
		g_qiYiJiangYuanZTKYPrice[L"����ʡ"] = { 27.5, 1.3 };
		g_qiYiJiangYuanZTKYPrice[L"ɽ��ʡ"] = { 27.5, 1.3 };
		g_qiYiJiangYuanZTKYPrice[L"���"] = { 27.5, 1.3 };
		g_qiYiJiangYuanZTKYPrice[L"�ӱ�ʡ"] = { 27.5, 1.3 };
		g_qiYiJiangYuanZTKYPrice[L"����ʡ"] = { 27.5, 1.3 };
		g_qiYiJiangYuanZTKYPrice[L"����ʡ"] = { 27.5, 1.3 };
		g_qiYiJiangYuanZTKYPrice[L"ɽ��ʡ"] = { 27.5, 1.3 };
		g_qiYiJiangYuanZTKYPrice[L"����ʡ"] = { 27.5, 1.3 };
		g_qiYiJiangYuanZTKYPrice[L"����ʡ"] = { 27.5, 1.3 };
		g_qiYiJiangYuanZTKYPrice[L"�㶫ʡ"] = { 27.5, 1.3 };
		g_qiYiJiangYuanZTKYPrice[L"����ʡ"] = { 27.5, 1.3 };
		g_qiYiJiangYuanZTKYPrice[L"����׳��������"] = { 27.5, 1.3 };
		g_qiYiJiangYuanZTKYPrice[L"�Ĵ�ʡ"] = { 22.5, 1 };
		g_qiYiJiangYuanZTKYPrice[L"���β���������"] = { 50, 1.6 };
		g_qiYiJiangYuanZTKYPrice[L"���Ӳ���Ǽ��������"] = { 50, 1.6 };
		g_qiYiJiangYuanZTKYPrice[L"��ɽ����������"] = { 50, 1.6 };
		g_qiYiJiangYuanZTKYPrice[L"����"] = { 27.5, 1.2 };
		g_qiYiJiangYuanZTKYPrice[L"����ʡ"] = { 32, 1.4 };
		g_qiYiJiangYuanZTKYPrice[L"����ʡ"] = { 27.5, 1.4 };
		g_qiYiJiangYuanZTKYPrice[L"����ʡ"] = { 35, 3 };
		g_qiYiJiangYuanZTKYPrice[L"���Ļ���������"] = { 42.5, 2.8 };
		g_qiYiJiangYuanZTKYPrice[L"�ຣʡ"] = { 42.5, 2.8 };
		g_qiYiJiangYuanZTKYPrice[L"������ʡ"] = { 37, 1.7 };
		g_qiYiJiangYuanZTKYPrice[L"����ʡ"] = { 37, 1.7 };
		g_qiYiJiangYuanZTKYPrice[L"����ʡ"] = { 37, 1.7 };
		g_qiYiJiangYuanZTKYPrice[L"���ɹ�������"] = { 72.5, 3 };
		g_qiYiJiangYuanZTKYPrice[L"����ʡ"] = { 42, 2.7 };
		g_qiYiJiangYuanZTKYPrice[L"�½�ά���������"] = { 82.5, 3.2 };
		g_qiYiJiangYuanZTKYPrice[L"����������"] = { 72, 4.2 };
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
	//������
	{
		g_duoDuoMaiCaiPrice[L"����_������"].strPinPai = L"����";
		g_duoDuoMaiCaiPrice[L"����_������"].biaoZhunPrice.zxPaoHuo = 15;
		g_duoDuoMaiCaiPrice[L"����_������"].biaoZhunPrice.zxZhongHuo = 25;
		g_duoDuoMaiCaiPrice[L"����_������"].biaoZhunPrice.tieBiao = 0.2;
		g_duoDuoMaiCaiPrice[L"����_������"].biaoZhunPrice.fhTiJi = 40;
		g_duoDuoMaiCaiPrice[L"����_������"].biaoZhunPrice.fhZhongLiang = 0.2;
		g_duoDuoMaiCaiPrice[L"����_������"].biaoZhunPrice.qiBu = 60;

		g_duoDuoMaiCaiPrice[L"����_������"].BuDanPrice.zxPaoHuo = 30;
		g_duoDuoMaiCaiPrice[L"����_������"].BuDanPrice.zxZhongHuo = 50;
		g_duoDuoMaiCaiPrice[L"����_������"].BuDanPrice.tieBiao = 0.2;
		g_duoDuoMaiCaiPrice[L"����_������"].BuDanPrice.fhTiJi = 80;
		g_duoDuoMaiCaiPrice[L"����_������"].BuDanPrice.fhZhongLiang = 0.4;
		g_duoDuoMaiCaiPrice[L"����_������"].BuDanPrice.qiBu = 150;


		g_duoDuoMaiCaiPrice[L"���е�_������"].strPinPai = L"���е�";
		g_duoDuoMaiCaiPrice[L"���е�_������"].tuiHuoMianFei = 30;
		g_duoDuoMaiCaiPrice[L"���е�_������"].biaoZhunPrice.zxPaoHuo = 15;
		g_duoDuoMaiCaiPrice[L"���е�_������"].biaoZhunPrice.zxZhongHuo = 25;
		g_duoDuoMaiCaiPrice[L"���е�_������"].biaoZhunPrice.tieBiao = 0.2;
		g_duoDuoMaiCaiPrice[L"���е�_������"].biaoZhunPrice.fhTiJi = 35;
		g_duoDuoMaiCaiPrice[L"���е�_������"].biaoZhunPrice.fhZhongLiang = 0.18;
		g_duoDuoMaiCaiPrice[L"���е�_������"].biaoZhunPrice.qiBu = 50;

		g_duoDuoMaiCaiPrice[L"���е�_������"].BuDanPrice.zxPaoHuo = 30;
		g_duoDuoMaiCaiPrice[L"���е�_������"].BuDanPrice.zxZhongHuo = 50;
		g_duoDuoMaiCaiPrice[L"���е�_������"].BuDanPrice.tieBiao = 0.2;
		g_duoDuoMaiCaiPrice[L"���е�_������"].BuDanPrice.fhTiJi = 70;
		g_duoDuoMaiCaiPrice[L"���е�_������"].BuDanPrice.fhZhongLiang = 0.35;
		g_duoDuoMaiCaiPrice[L"���е�_������"].BuDanPrice.qiBu = 150;


		g_duoDuoMaiCaiPrice[L"��֪_������"].strPinPai = L"��֪";
		g_duoDuoMaiCaiPrice[L"��֪_������"].tuiHuoMianFei = 30;
		g_duoDuoMaiCaiPrice[L"��֪_������"].biaoZhunPrice.zxPaoHuo = 7;
		g_duoDuoMaiCaiPrice[L"��֪_������"].biaoZhunPrice.zxZhongHuo = 25;
		g_duoDuoMaiCaiPrice[L"��֪_������"].biaoZhunPrice.tieBiao = 0.2;
		g_duoDuoMaiCaiPrice[L"��֪_������"].biaoZhunPrice.fhTiJi = 30;
		g_duoDuoMaiCaiPrice[L"��֪_������"].biaoZhunPrice.fhZhongLiang = 0.15;
		g_duoDuoMaiCaiPrice[L"��֪_������"].biaoZhunPrice.qiBu = 50;

		g_duoDuoMaiCaiPrice[L"��֪_������"].BuDanPrice.zxPaoHuo = 14;
		g_duoDuoMaiCaiPrice[L"��֪_������"].BuDanPrice.zxZhongHuo = 50;
		g_duoDuoMaiCaiPrice[L"��֪_������"].BuDanPrice.tieBiao = 0.2;
		g_duoDuoMaiCaiPrice[L"��֪_������"].BuDanPrice.fhTiJi = 60;
		g_duoDuoMaiCaiPrice[L"��֪_������"].BuDanPrice.fhZhongLiang = 0.3;
		g_duoDuoMaiCaiPrice[L"��֪_������"].BuDanPrice.qiBu = 100;

		g_duoDuoMaiCaiPrice[L"����_������"].strPinPai = L"����";
		g_duoDuoMaiCaiPrice[L"����_������"].tuiHuoMianFei = 30;
		g_duoDuoMaiCaiPrice[L"����_������"].biaoZhunPrice.zxPaoHuo = 15;
		g_duoDuoMaiCaiPrice[L"����_������"].biaoZhunPrice.zxZhongHuo = 25;
		g_duoDuoMaiCaiPrice[L"����_������"].biaoZhunPrice.tieBiao = 0.2;
		g_duoDuoMaiCaiPrice[L"����_������"].biaoZhunPrice.fhTiJi = 40;
		g_duoDuoMaiCaiPrice[L"����_������"].biaoZhunPrice.fhZhongLiang = 0.13;
		g_duoDuoMaiCaiPrice[L"����_������"].biaoZhunPrice.qiBu = 50;

		g_duoDuoMaiCaiPrice[L"����_������"].BuDanPrice.zxPaoHuo = 30;
		g_duoDuoMaiCaiPrice[L"����_������"].BuDanPrice.zxZhongHuo = 50;
		g_duoDuoMaiCaiPrice[L"����_������"].BuDanPrice.tieBiao = 0.2;
		g_duoDuoMaiCaiPrice[L"����_������"].BuDanPrice.fhTiJi = 80;
		g_duoDuoMaiCaiPrice[L"����_������"].BuDanPrice.fhZhongLiang = 0.26;
		g_duoDuoMaiCaiPrice[L"����_������"].BuDanPrice.qiBu = 100;
	}
}

//----------------------------------------------------------------------------------//