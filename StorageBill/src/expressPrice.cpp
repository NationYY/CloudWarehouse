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
//----------------------------------------------------------------------------------//

//------------------------------------˳��۸�--------------------------------------//
//����ҫ��
std::vector< std::list<sExpressPriceInfo> > g_yongChuangYaoHuiSFPrice;
//----------------------------------------------------------------------------------//


//------------------------------------���˼۸�--------------------------------------//
//����ҫ��
std::map< std::wstring, sLargeExpressPriceInfo > g_yongChuangYaoHuiZTKYPrice;
//�����
std::map< std::wstring, sLargeExpressPriceInfo > g_xinMaBangZTKYPrice;
//----------------------------------------------------------------------------------//


//----------------------------------�ɱ�����۸���---------------------------------//
std::map< std::wstring, sLargeExpressPriceInfo > g_chengBenZTKYPrice;

void PrepareExpressPrice()
{
	g_yongChuangYaoHuiSFPrice.resize(4);
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
		g_kunLunShanYTPrice[L"�½�ά���������"].push_back({ 0, 0, 1, 15.5, 13.5 });
		g_kunLunShanYTPrice[L"����������"].push_back({ 0, 0, 1, 17.5, 17.5 });
	}
	//��ͨ���˳ɱ�
	{
		g_chengBenZTKYPrice[L"�Ϻ�"] = { 25, 1.1 };
		g_chengBenZTKYPrice[L"����"] = { 25, 1.1 };
		g_chengBenZTKYPrice[L"����ʡ"] = { 25, 1.1 };
		g_chengBenZTKYPrice[L"����ʡ"] = { 25, 1.1 };
		g_chengBenZTKYPrice[L"�㽭ʡ"] = { 25, 1.1 };
		g_chengBenZTKYPrice[L"����ʡ"] = { 25, 1.1 };
		g_chengBenZTKYPrice[L"ɽ��ʡ"] = { 25, 1.1 };
		g_chengBenZTKYPrice[L"���"] = { 25, 1.1 };
		g_chengBenZTKYPrice[L"�ӱ�ʡ"] = { 25, 1.1 };
		g_chengBenZTKYPrice[L"����ʡ"] = { 25, 1.1 };
		g_chengBenZTKYPrice[L"����ʡ"] = { 25, 1.1 };
		g_chengBenZTKYPrice[L"ɽ��ʡ"] = { 25, 1.1 };
		g_chengBenZTKYPrice[L"����ʡ"] = { 25, 1.1 };
		g_chengBenZTKYPrice[L"����ʡ"] = { 25, 1.1 };
		g_chengBenZTKYPrice[L"�㶫ʡ"] = { 25, 1.1 };
		g_chengBenZTKYPrice[L"����ʡ"] = { 25, 1.1 };
		g_chengBenZTKYPrice[L"����׳��������"] = { 25, 1.1 };
		g_chengBenZTKYPrice[L"�Ĵ�ʡ"] = { 20, 0.8 };
		g_chengBenZTKYPrice[L"���β���������"] = { 20, 1.2 };
		g_chengBenZTKYPrice[L"���Ӳ���Ǽ��������"] = { 20, 1.2 };
		g_chengBenZTKYPrice[L"��ɽ����������"] = { 20, 1.2 };
		g_chengBenZTKYPrice[L"����"] = { 25, 1 };
		g_chengBenZTKYPrice[L"����ʡ"] = { 25, 1.2 };
		g_chengBenZTKYPrice[L"����ʡ"] = { 25, 1.2 };
		g_chengBenZTKYPrice[L"����ʡ"] = { 25, 2.8 };
		g_chengBenZTKYPrice[L"���Ļ���������"] = { 40, 2.6 };
		g_chengBenZTKYPrice[L"�ຣʡ"] = { 25, 2.6 };
		g_chengBenZTKYPrice[L"������ʡ"] = { 25, 1.2 };
		g_chengBenZTKYPrice[L"����ʡ"] = { 25, 1.2 };
		g_chengBenZTKYPrice[L"����ʡ"] = { 25, 1.2 };
		g_chengBenZTKYPrice[L"���ɹ�������"] = { 70, 2.8 };
		g_chengBenZTKYPrice[L"����ʡ"] = { 25, 2.5 };
		g_chengBenZTKYPrice[L"�½�ά���������"] = { 80, 3 };
		g_chengBenZTKYPrice[L"����������"] = { 60, 4 };
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
		g_yongChuangYaoHuiZTKYPrice[L"���β���������"] = {22.5, 1.4};
		g_yongChuangYaoHuiZTKYPrice[L"���Ӳ���Ǽ��������"] = {22.5, 1.4};
		g_yongChuangYaoHuiZTKYPrice[L"��ɽ����������"] = {22.5, 1.4};
		g_yongChuangYaoHuiZTKYPrice[L"����"] = {27.5, 1.2};
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"] = {27.5, 1.4};
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"] = {27.5, 1.4};
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"] = {27.5, 3};
		g_yongChuangYaoHuiZTKYPrice[L"���Ļ���������"] = {42.5, 2.8};
		g_yongChuangYaoHuiZTKYPrice[L"�ຣʡ"] = {27.5, 2.8};
		g_yongChuangYaoHuiZTKYPrice[L"������ʡ"] = {27.5, 1.4};
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"] = {27.5, 1.4};
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"] = {27.5, 1.4};
		g_yongChuangYaoHuiZTKYPrice[L"���ɹ�������"] = {72.5, 3};
		g_yongChuangYaoHuiZTKYPrice[L"����ʡ"] = {27.5, 2.7};
		g_yongChuangYaoHuiZTKYPrice[L"�½�ά���������"] = {82.5, 3.2};
		g_yongChuangYaoHuiZTKYPrice[L"����������"] = {62.5, 4.2};
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
		g_xinMaBangZTKYPrice[L"���β���������"] = { 23, 1.5 };
		g_xinMaBangZTKYPrice[L"���Ӳ���Ǽ��������"] = { 23, 1.5 };
		g_xinMaBangZTKYPrice[L"��ɽ����������"] = { 23, 1.5 };
		g_xinMaBangZTKYPrice[L"����"] = { 27, 1.2 };
		g_xinMaBangZTKYPrice[L"����ʡ"] = { 27, 1.4 };
		g_xinMaBangZTKYPrice[L"����ʡ"] = { 27, 1.4 };
		g_xinMaBangZTKYPrice[L"����ʡ"] = { 27, 3 };
		g_xinMaBangZTKYPrice[L"���Ļ���������"] = { 45, 2.8 };
		g_xinMaBangZTKYPrice[L"�ຣʡ"] = { 27, 2.8 };
		g_xinMaBangZTKYPrice[L"������ʡ"] = { 27, 1.4 };
		g_xinMaBangZTKYPrice[L"����ʡ"] = { 27, 1.4 };
		g_xinMaBangZTKYPrice[L"����ʡ"] = { 27, 1.4 };
		g_xinMaBangZTKYPrice[L"���ɹ�������"] = { 75, 3 };
		g_xinMaBangZTKYPrice[L"����ʡ"] = { 27, 2.7 };
		g_xinMaBangZTKYPrice[L"�½�ά���������"] = { 85, 3.2 };
		g_xinMaBangZTKYPrice[L"����������"] = { 65, 4.2 };
	}
}

//----------------------------------------------------------------------------------//