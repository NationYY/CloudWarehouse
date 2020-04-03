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
	wstring bjPay;
	bool bHandle;
	int row;
	sSFAuthData():
		number(L""),
		weight(L""),
		vaServices(L""),
		bHandle(false),
		backPay(L""),
		needPay(L""),
		bjPay(L""),
		row(-1)
	{
	}
};

struct sBSAuthData
{
	wstring number;
	double weight;
	double needPay1;
	double needPay2;
	double needPay3;
	double needPay4;
	double needPay5;
	int row;
	sBSAuthData() :
		number(L""),
		weight(0.0),
		needPay1(0.0),
		needPay2(0.0),
		needPay3(0.0),
		needPay4(0.0),
		needPay5(0.0),
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
	std::wstring strDianPu;				//����
	int nRow;							//��������е�����
	int nBaoJiaJinE;					//���۽��
	bool bChaiFen;						//�Ƿ��ǲ�ֶ���
	sSalesInfo(): strHuoZhu(L""), strShouJianRen(L""), strWuLiuGongSi(L""), strWuLiuDanHao(L""), strSheng(L""), strShouJianRenDiZhi(L""),
		strZhongLiang(L""), strFaHuoShijian(L""), strHuoPinZongShuLiang(L""), strHuoPinMingXi(L""), nRow(0), strYuanShiDanHao(L""), 
		strDianPu(L""),nBaoJiaJinE(0), bChaiFen(true)
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

enum eExportTitle
{
	eET_ShouJianRen = 0,
	eET_ShouJianRenDiZhi,
	eET_Sheng,
	eET_WuLiuGongSi,
	eET_WuLiuDanHao,
	eET_YuanShiDanHao,
	eET_DianPu,
	eET_ZhongLiang,
	eET_FaHuoShiJian,
	eET_HuoPinZongShuLiang,
	eET_HuoPinMingXi,
	eET_JiFeiZhongLiang,
	eET_WuLiuFei,
	eET_WuLiuChengBen,
	eET_HaoCaiFei,
	eET_CaoZuoFei,
	eET_ZengZhiFeiYong,
	eET_BeiZhu,
};


#define DOUBLE_PRECISION 0.00000001
typedef std::map<std::wstring, int> map_key_wstring_val_int;
typedef std::vector<std::wstring> vec_wvals;
typedef std::vector<std::wstring> split_wstr_vec;

