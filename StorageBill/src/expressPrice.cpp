#include "stdafx.h"
#include "expressPrice.h"
//------------------------------------��ݼ۸�--------------------------------------//
//ħ�ϿƼ�
std::map< std::wstring, std::list<sExpressPriceInfo> > g_moHeKeJiBSPrice;
std::map< std::wstring, std::list<sExpressPriceInfo> > g_taiFuShangMaoBSPrice;
void PrepareExpressPrice()
{
	//��С���� �������  ����	���ط���	���ط���
	//ħ�ϰ���
	{
		//0-3���� һ�ڼ�
		g_moHeKeJiBSPrice[L"�Ĵ�ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_moHeKeJiBSPrice[L"����"].push_back({ 0, 3, 3, 3.5, 0 });
		g_moHeKeJiBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_moHeKeJiBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_moHeKeJiBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_moHeKeJiBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_moHeKeJiBSPrice[L"�㽭ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_moHeKeJiBSPrice[L"�Ϻ�"].push_back({ 0, 3, 3, 3.5, 0 });
		g_moHeKeJiBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_moHeKeJiBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_moHeKeJiBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_moHeKeJiBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_moHeKeJiBSPrice[L"����"].push_back({ 0, 3, 3, 3.5, 0 });
		g_moHeKeJiBSPrice[L"���"].push_back({ 0, 3, 3, 3.5, 0 });
		g_moHeKeJiBSPrice[L"�㶫ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_moHeKeJiBSPrice[L"����׳��������"].push_back({ 0, 3, 3, 3.5, 0 });
		g_moHeKeJiBSPrice[L"�ӱ�ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_moHeKeJiBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_moHeKeJiBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_moHeKeJiBSPrice[L"ɽ��ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_moHeKeJiBSPrice[L"ɽ��ʡ"].push_back({ 0, 3, 3, 3.5, 0 });
		g_moHeKeJiBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 4, 0 });
		g_moHeKeJiBSPrice[L"���Ļ���������"].push_back({ 0, 3, 3, 4, 0 });
		g_moHeKeJiBSPrice[L"�ຣʡ"].push_back({ 0, 3, 3, 4, 0 });
		g_moHeKeJiBSPrice[L"������ʡ"].push_back({ 0, 3, 3, 3.8, 0 });
		g_moHeKeJiBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.8, 0 });
		g_moHeKeJiBSPrice[L"����ʡ"].push_back({ 0, 3, 3, 3.8, 0 });
		//3-10���� ���� ����
		g_moHeKeJiBSPrice[L"�Ĵ�ʡ"].push_back({ 3, 10, 3, 3.5, 1.7 });
		g_moHeKeJiBSPrice[L"����"].push_back({ 3, 10, 3, 3.5, 1.8 });
		g_moHeKeJiBSPrice[L"����ʡ"].push_back({ 3, 10, 3, 3.5, 1.8 });
		g_moHeKeJiBSPrice[L"����ʡ"].push_back({ 3, 10, 3, 3.5, 1.8 });
		g_moHeKeJiBSPrice[L"����ʡ"].push_back({ 3, 10, 3, 3.5, 1.8 });
		g_moHeKeJiBSPrice[L"����ʡ"].push_back({ 3, 10, 3, 3.5, 1.8 });
		g_moHeKeJiBSPrice[L"�㽭ʡ"].push_back({ 3, 10, 3, 3.5, 1.8 });
		g_moHeKeJiBSPrice[L"�Ϻ�"].push_back({ 3, 10, 3, 3.5, 1.8 });
		g_moHeKeJiBSPrice[L"����ʡ"].push_back({ 3, 10, 3, 3.5, 1.8 });
		g_moHeKeJiBSPrice[L"����ʡ"].push_back({ 3, 10, 3, 3.5, 1.8 });
		g_moHeKeJiBSPrice[L"����ʡ"].push_back({ 3, 10, 3, 3.5, 1.8 });
		g_moHeKeJiBSPrice[L"����ʡ"].push_back({ 3, 10, 3, 3.5, 1.8 });
		g_moHeKeJiBSPrice[L"����"].push_back({ 3, 10, 3, 3.5, 1.8 });
		g_moHeKeJiBSPrice[L"���"].push_back({ 3, 10, 3, 3.5, 1.8 });
		g_moHeKeJiBSPrice[L"�㶫ʡ"].push_back({ 3, 10, 3, 3.5, 1.8 });
		g_moHeKeJiBSPrice[L"����׳��������"].push_back({ 3, 10, 3, 3.5, 1.8 });
		g_moHeKeJiBSPrice[L"�ӱ�ʡ"].push_back({ 3, 10, 3, 3.5, 1.8 });
		g_moHeKeJiBSPrice[L"����ʡ"].push_back({ 3, 10, 3, 3.5, 1.8 });
		g_moHeKeJiBSPrice[L"����ʡ"].push_back({ 3, 10, 3, 3.5, 1.8 });
		g_moHeKeJiBSPrice[L"ɽ��ʡ"].push_back({ 3, 10, 3, 3.5, 1.8 });
		g_moHeKeJiBSPrice[L"ɽ��ʡ"].push_back({ 3, 10, 3, 3.5, 1.8 });
		g_moHeKeJiBSPrice[L"����ʡ"].push_back({ 3, 10, 3, 4, 2.2 });
		g_moHeKeJiBSPrice[L"���Ļ���������"].push_back({ 3, 10, 3, 4, 2.2 });
		g_moHeKeJiBSPrice[L"�ຣʡ"].push_back({ 3, 10, 3, 4, 2.2 });
		g_moHeKeJiBSPrice[L"������ʡ"].push_back({ 3, 10, 3, 3.8, 2 });
		g_moHeKeJiBSPrice[L"����ʡ"].push_back({ 3, 10, 3, 3.8, 2 });
		g_moHeKeJiBSPrice[L"����ʡ"].push_back({ 3, 10, 3, 3.8, 2 });
		//10�������� ���� ����
		g_moHeKeJiBSPrice[L"�Ĵ�ʡ"].push_back({ 10, 0, 1, 4.5, 1.8 });
		g_moHeKeJiBSPrice[L"����"].push_back({ 10, 0, 1, 4.5, 2 });
		g_moHeKeJiBSPrice[L"����ʡ"].push_back({ 10, 0, 1, 4.5, 3.5 });
		g_moHeKeJiBSPrice[L"����ʡ"].push_back({ 10, 0, 1, 4.5, 3.5 });
		g_moHeKeJiBSPrice[L"����ʡ"].push_back({ 10, 0, 1, 4.5, 3.5 });
		g_moHeKeJiBSPrice[L"����ʡ"].push_back({ 10, 0, 1, 4.5, 3.5 });
		g_moHeKeJiBSPrice[L"�㽭ʡ"].push_back({ 10, 0, 1, 4.5, 3.5 });
		g_moHeKeJiBSPrice[L"�Ϻ�"].push_back({ 10, 0, 1, 4.5, 3.5 });
		g_moHeKeJiBSPrice[L"����ʡ"].push_back({ 10, 0, 1, 4.5, 3.5 });
		g_moHeKeJiBSPrice[L"����ʡ"].push_back({ 10, 0, 1, 4.5, 3.5 });
		g_moHeKeJiBSPrice[L"����ʡ"].push_back({ 10, 0, 1, 4.5, 3.5 });
		g_moHeKeJiBSPrice[L"����ʡ"].push_back({ 10, 0, 1, 4.5, 3.5 });
		g_moHeKeJiBSPrice[L"����"].push_back({ 10, 0, 1, 4.5, 3.5 });
		g_moHeKeJiBSPrice[L"���"].push_back({ 10, 0, 1, 4.5, 3.5 });
		g_moHeKeJiBSPrice[L"�㶫ʡ"].push_back({ 10, 0, 1, 4.5, 3.5 });
		g_moHeKeJiBSPrice[L"����׳��������"].push_back({ 10, 0, 1, 4.5, 3.5 });
		g_moHeKeJiBSPrice[L"�ӱ�ʡ"].push_back({ 10, 0, 1, 4.5, 3.5 });
		g_moHeKeJiBSPrice[L"����ʡ"].push_back({ 10, 0, 1, 4.5, 3.5 });
		g_moHeKeJiBSPrice[L"����ʡ"].push_back({ 10, 0, 1, 4.5, 3.5 });
		g_moHeKeJiBSPrice[L"ɽ��ʡ"].push_back({ 10, 0, 1, 4.5, 3.5 });
		g_moHeKeJiBSPrice[L"ɽ��ʡ"].push_back({ 10, 0, 1, 4.5, 3.5 });
		g_moHeKeJiBSPrice[L"����ʡ"].push_back({ 10, 0, 1, 4.5, 5.5 });
		g_moHeKeJiBSPrice[L"���Ļ���������"].push_back({ 10, 0, 1, 4.5, 5.5 });
		g_moHeKeJiBSPrice[L"�ຣʡ"].push_back({ 10, 0, 1, 4.5, 5.5 });
		g_moHeKeJiBSPrice[L"������ʡ"].push_back({ 10, 0, 1, 4.5, 6.5 });
		g_moHeKeJiBSPrice[L"����ʡ"].push_back({ 10, 0, 1, 4.5, 6.5 });
		g_moHeKeJiBSPrice[L"����ʡ"].push_back({ 10, 0, 1, 4.5, 6.5 });
		///////////////////
		g_moHeKeJiBSPrice[L"���ɹ�������"].push_back({ 0, 0, 1, 7.5, 4.5 });
		g_moHeKeJiBSPrice[L"����ʡ"].push_back({ 0, 0, 1, 7.5, 4 });
		g_moHeKeJiBSPrice[L"�½�ά���������"].push_back({ 0, 0, 1, 13, 11 });
		g_moHeKeJiBSPrice[L"����������"].push_back({ 0, 0, 1, 13, 11 });
	}
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
}

//----------------------------------------------------------------------------------//