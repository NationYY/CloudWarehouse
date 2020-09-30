#include "stdafx.h"
#include "expressPrice.h"
//------------------------------------��ݼ۸�--------------------------------------//
std::map< std::wstring, std::list<sExpressPriceInfo> > g_taiFuShangMaoBSPrice;
std::map< std::wstring, std::list<sExpressPriceInfo> > g_yiMaiKeJiBSPrice;
std::map< std::wstring, std::list<sExpressPriceInfo> > g_qiYiJiangYuanBSPrice;
std::map< std::wstring, std::list<sExpressPriceInfo> > g_xinMaBangBSPrice;
std::map< std::wstring, std::list<sExpressPriceInfo> > g_miYaBSPrice;
std::map< std::wstring, std::list<sExpressPriceInfo> > g_kunLunShanYTPrice;
//----------------------------------------------------------------------------------//

//------------------------------------˳��۸�--------------------------------------//
//����ҫ��
std::vector< std::list<sExpressPriceInfo> > g_yongChuangYaoHuiSFPrice;
//----------------------------------------------------------------------------------//


//------------------------------------���˼۸�--------------------------------------//
//����ҫ��
std::vector< std::list<sExpressPriceInfo> > g_yongChuangYaoHuiZTKYPrice;
//----------------------------------------------------------------------------------//

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

	//����ҫ����ͨ����
	{
		g_yongChuangYaoHuiZTKYPrice
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
}

//----------------------------------------------------------------------------------//