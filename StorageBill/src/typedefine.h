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
	std::wstring strHuoZhu;				//货主
	std::wstring strShouJianRen;		//收件人
	std::wstring strWuLiuGongSi;		//物流公司
	std::wstring strWuLiuDanHao;		//物流单号
	std::wstring strSheng;				//省
	std::wstring strShouJianRenDiZhi;	//收件人地址
	std::wstring strZhongLiang;			//重量
	std::wstring strFaHuoShijian;		//发货时间
	std::wstring strHuoPinZongShuLiang;	//货品总数量
	std::wstring strHuoPinMingXi;		//货品明细
	std::wstring strYuanShiDanHao;		//原始单号
	int nRow;							//在输出表中的行数
	int nBaoJiaJinE;					//保价金额
	sSalesInfo(): strHuoZhu(L""), strShouJianRen(L""), strWuLiuGongSi(L""), strWuLiuDanHao(L""), strSheng(L""), strShouJianRenDiZhi(L""),
		strZhongLiang(L""), strFaHuoShijian(L""), strHuoPinZongShuLiang(L""), strHuoPinMingXi(L""), nRow(0), strYuanShiDanHao(L""), nBaoJiaJinE(0)
	{
	}
};

struct sInStorageInfo
{
	std::wstring strHuoZhu;				//货主
	std::wstring strShangJiaBianMa;     //商家编码
	std::wstring strHuoPinBianMa;		//货品编码
	std::wstring strHuoPinMingCheng;	//货品名称
	int nCnt;
	int nRow;
	sInStorageInfo(): strHuoZhu(L""), strShangJiaBianMa(L""), strHuoPinBianMa(L""), strHuoPinMingCheng(L""), nCnt(0), nRow(0)
	{
	}
};
#define DOUBLE_PRECISION 0.00000001