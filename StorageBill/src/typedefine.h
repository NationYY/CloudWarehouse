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
	sSalesInfo(): strHuoZhu(L""), strShouJianRen(L""), strWuLiuGongSi(L""), strWuLiuDanHao(L""), strSheng(L""), strShouJianRenDiZhi(L""),
		strZhongLiang(L""), strFaHuoShijian(L""), strHuoPinZongShuLiang(L""), strHuoPinMingXi(L""), nRow(0), strYuanShiDanHao(L""), nBaoJiaJinE(0)
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
#define DOUBLE_PRECISION 0.00000001