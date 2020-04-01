#pragma once
#include <string>
#include <map>
#include <set>
using namespace std;
struct sSFAuthData
{
	wstring number;
	wstring weight;
	wstring vaServices;
	wstring needPay;
	wstring backPay;
	bool bHandle;
	int row;
	sSFAuthData():
		number(L""),
		weight(L""),
		vaServices(L""),
		bHandle(false),
		backPay(L""),
		needPay(L""),
		row(-1)
	{
	}
};

struct sYCExportData
{
	wstring number;
	double weight;
	int row;
	sYCExportData(): number(L""),
		weight(0.0),
		row(0)
	{
	}
};
struct sSalesInfo
{
	std::wstring strHuoZhu;				//����
	std::wstring strShouJianRen;		//�ռ���
	std::wstring strWuLiuGongSi;		//������˾
	std::wstring strWuLiuDanHao;		//��������
	std::wstring strSheng;				//ʡ
	std::wstring strShouJianRenDiZhi;	//�ռ��˵�ַ
	std::wstring strZhongLiang;			//����
	std::wstring strFaHuoShijian;		//����ʱ��
	std::wstring strHuoPinZongShuLiang;	//��Ʒ������
	std::wstring strHuoPinMingXi;		//��Ʒ��ϸ
	std::wstring strYuanShiDanHao;		//ԭʼ����
	int nRow;							//��������е�����
	int nBaoJiaJinE;					//���۽��
	bool bChaiFen;						//�Ƿ��ǲ�ֶ���
	sSalesInfo(): strHuoZhu(L""), strShouJianRen(L""), strWuLiuGongSi(L""), strWuLiuDanHao(L""), strSheng(L""), strShouJianRenDiZhi(L""),
		strZhongLiang(L""), strFaHuoShijian(L""), strHuoPinZongShuLiang(L""), strHuoPinMingXi(L""), nRow(0), strYuanShiDanHao(L""), nBaoJiaJinE(0), bChaiFen(true)
	{
	}
};

struct sInStorageInfo
{
	std::wstring strHuoZhu;				//����
	std::wstring strShangJiaBianMa;     //�̼ұ���
	std::wstring strHuoPinBianMa;		//��Ʒ����
	std::wstring strHuoPinMingCheng;	//��Ʒ����
	int nCnt;
	int nRow;
	sInStorageInfo(): strHuoZhu(L""), strShangJiaBianMa(L""), strHuoPinBianMa(L""), strHuoPinMingCheng(L""), nCnt(0), nRow(0)
	{
	}
};

struct sExpressPriceInfo
{
	int nMinZL;			//��С���� ���ڵ���
	int nMaxZL;			//������� С��
	int nFirstZL;		//����
	double dFirstPrice;	//���ط���
	double dXZPrice;	//���ط���
};

#define DOUBLE_PRECISION 0.00000001
typedef std::map<std::wstring, int> map_key_wstring_val_int;
typedef std::vector<std::wstring> vec_wvals;
typedef std::vector<std::wstring> split_wstr_vec;

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