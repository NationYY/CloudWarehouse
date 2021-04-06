#pragma once
#include <string>
#include <map>
#include <set>
#include "BasicExcel.hpp"
using namespace YCompoundFiles;
using namespace YExcel;
using namespace std;
struct sSFAuthData
{
	wstring number;
	wstring weight;
	wstring vaServices;
	wstring needPay;
	wstring backPay;
	wstring djPay;
	wstring bjPay;
	wstring type;
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
		row(-1),
		type(L""),
		djPay(L"")
	{
	}
};

struct sBSKDAuthData
{
	wstring number;
	double ysWeight;
	int finalWeight;
	double needPay;
	int row;
	
	sBSKDAuthData() :
		number(L""),
		ysWeight(0.0),
		finalWeight(0),
		needPay(0.0),
		row(-1)
	{
	}
};

struct sYDKDAuthData
{
	wstring number;
	double ysWeight;
	int finalWeight;
	int row;
	BasicExcel* ydkdExcel;
	sYDKDAuthData() :
		number(L""),
		ysWeight(0.0),
		finalWeight(0),
		row(-1),
		ydkdExcel(NULL)
	{
	}
};

struct sZTKYAuthData
{
	wstring number;
	double finalWeight;
	double yingShou;
	double qita;
	wstring qitaInfo;
	wstring sheng;
	wstring shi;
	int row;
	bool bHandleChengBen;
	sZTKYAuthData() :
		number(L""),
		finalWeight(0.0),
		yingShou(0.0),
		qita(0.0),
		row(-1),
		qitaInfo(L""),
		sheng(L""),
		shi(L""),
		bHandleChengBen(false)
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

struct sYDKDHandleCol
{
	int handleCol;
	int bzCol1;
	int bzCol2;
};
struct sSalesInfo
{
	std::wstring strHuoZhu;				//����
	std::wstring strShouJianRen;		//�ռ���
	std::wstring strWuLiuGongSi;		//������˾
	std::wstring strWuLiuDanHao;		//��������
	std::wstring strSheng;				//ʡ
	std::wstring strShi;				//��
	std::wstring strShouJianRenDiZhi;	//�ռ��˵�ַ
	std::wstring strZhongLiang;			//����
	std::wstring strFaHuoShijian;		//����ʱ��
	std::wstring strHuoPinZongShuLiang;	//��Ʒ������
	std::wstring strHuoPinMingXi;		//��Ʒ��ϸ
	std::wstring strYuanShiDanHao;		//ԭʼ����
	std::wstring strDianPu;				//����
	std::wstring strBaoZhuang;			//��װ
	std::wstring strKeFuBeiZhu;			//��װ
	int nRow;							//��������е�����
	int nBaoJiaJinE;					//���۽��
	bool bChaiFen;						//�Ƿ��ǲ�ֶ���
	bool bXiuGaiZhongLiang;				//�Ƿ��Զ���������
	bool bKunLunShan;					//�Ƿ�����ɽ
	double wuLiuFeiYong;				//�������� ���˵�ʱ����
	double zengZhiFeiYong;				//��ֵ���� ���˵�ʱ����
	sSalesInfo(): strHuoZhu(L""), strShouJianRen(L""), strWuLiuGongSi(L""), strWuLiuDanHao(L""), strSheng(L""), strShouJianRenDiZhi(L""),
		strZhongLiang(L""), strFaHuoShijian(L""), strHuoPinZongShuLiang(L""), strHuoPinMingXi(L""), nRow(0), strYuanShiDanHao(L""), 
		strDianPu(L""),nBaoJiaJinE(0), bChaiFen(true), strBaoZhuang(L""), strKeFuBeiZhu(L""), bXiuGaiZhongLiang(L""), bKunLunShan(false), strShi(L""),
		wuLiuFeiYong(0), zengZhiFeiYong(0)
	{
	}
};

struct sDuoDuoMaiCaiChuKuInfo
{
	std::wstring strHuoPinMingCheng;	//��Ʒ����
	int nShuLiang;						//��Ʒ����
	bool isBuDan;				//�Ƿ񲹵�
	int nBoxCnt;				//����
	double dZhongLiang;			//����
	double dTiJi;				//���
	std::wstring strKeFuBeiZhu;	//�ͷ���ע
	sDuoDuoMaiCaiChuKuInfo():
		nShuLiang(0), isBuDan(false), nBoxCnt(0), dZhongLiang(0.0), dTiJi(0.0), strKeFuBeiZhu(L"")
	{
	}
};

struct sDuoDuoMaiCaiRuKuInfo
{
	std::wstring strShenHeShiJian;		//���ʱ��
	std::wstring strHuoPinMingCheng;	//��Ʒ����
	int nShuLiang;						//��Ʒ����
	double dZhongLiang;			//����
	double dTiJi;				//���
};

struct sDuoDuoMaiCaiDiaoBoInfo
{
	std::wstring strChuKuShiJian;		//����ʱ��
	std::wstring strHuoPinMingCheng;	//��Ʒ����
	int nShuLiang;						//��Ʒ����
};

struct sInStorageInfo
{
	std::wstring strHuoZhu;				//����
	std::wstring strShangJiaBianMa;     //�̼ұ���
	std::wstring strHuoPinBianMa;		//��Ʒ����
	std::wstring strHuoPinMingCheng;	//��Ʒ����
	std::wstring strPinPai;
	int nCnt;
	int nRow;
	sInStorageInfo(): strHuoZhu(L""), strShangJiaBianMa(L""), strHuoPinBianMa(L""), strHuoPinMingCheng(L""), nCnt(0), nRow(0), strPinPai(L"")
	{
	}
};

//��ݼ۸�
struct sExpressPriceInfo
{
	int nMinZL;			//��С���� ���ڵ���
	int nMaxZL;			//������� С��
	int nFirstZL;		//����
	double dFirstPrice;	//���ط���
	double dXZPrice;	//���ط���
	double dFirstCommission;//���س��
	double dXZCommission;	//���س��
	sExpressPriceInfo(int _nMinZL, int _nMaxZL, int _nFirstZL, double _dFirstPrice,	double _dXZPrice, double _dFirstCommission=0.0, double _dXZCommission=0.0)
	{
		nMinZL = _nMinZL;
		nMaxZL = _nMaxZL;
		nFirstZL = _nFirstZL;
		dFirstPrice = _dFirstPrice;
		dXZPrice = _dXZPrice;
		dFirstCommission = _dFirstCommission;
		dXZCommission = _dXZCommission;
	}
};

//���˼۸�
struct sLargeExpressPriceInfo
{
	int nMinZL;			//��С���� ���ڵ���
	int nMaxZL;			//������� С��
	int nFirstZL;		//����
	double dFirstPrice;	//���ط���
	double dXZPrice;	//���ط���
	sLargeExpressPriceInfo(int _nMinZL, int _nMaxZL, int _nFirstZL, double _dFirstPrice, double _dXZPrice, double _dFirstCommission = 0.0, double _dXZCommission = 0.0)
	{
		nMinZL = _nMinZL;
		nMaxZL = _nMaxZL;
		nFirstZL = _nFirstZL;
		dFirstPrice = _dFirstPrice;
		dXZPrice = _dXZPrice;
	}
};
 

struct sDuoDuoMaiCaiPriceDetail
{
	double zxPaoHuo;
	double zxZhongHuo;
	double fhTiJi;
	double fhZhongLiang;
	double qiBu;
	sDuoDuoMaiCaiPriceDetail() :
		zxPaoHuo(0), zxZhongHuo(0), fhTiJi(0), fhZhongLiang(0), qiBu(0)
	{

	}
	sDuoDuoMaiCaiPriceDetail(double _zxPaoHuo, double _zxZhongHuo, double _fhTiJi, double _fhZhongLiang, double _qiBu) :
	 zxPaoHuo(_zxPaoHuo), zxZhongHuo(_zxZhongHuo), fhTiJi(_fhTiJi), fhZhongLiang(_fhZhongLiang), qiBu(_qiBu)
	{
	
	}
};

struct sDuoDuoMaiCaiPriceInfo
{
	std::wstring strPinPai;
	bool isCM;
	sDuoDuoMaiCaiPriceDetail biaoZhunPrice;
	sDuoDuoMaiCaiPriceDetail BuDanPrice;
	double tieBiao;
	double tuiHuoMianFei;
	wstring zujin;
	int nZuiXiaoMianJi;
	double dbZHzxf;	//�����ػ�װж��
	double dbPHzxf;	//�����ݻ�װж��
	double thZHPrice;//�˻��ػ���
	double thPHPrice;//�˻��ݻ���
	sDuoDuoMaiCaiPriceInfo():
	 strPinPai(L""), isCM(false), tieBiao(0), tuiHuoMianFei(0), zujin(L""), nZuiXiaoMianJi(0), dbZHzxf(0),
	 dbPHzxf(0), thZHPrice(0), thPHPrice(0)
	{
	}
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
	eET_BaoZhuang,
	eET_WuLiuFei,
	eET_WuLiuChengBen,
	eET_HaoCaiFei,
	eET_CaoZuoFei,
	eET_ZengZhiFeiYong,
	eET_BeiZhu,
	eET_KeFuBeiZhu,
	eET_KunLunShanShuiKa_510_24,
	eET_KunLunShanShuiKa_4_4,
	eET_KunLunShanShuiKa_510_12,
	eET_KunLunShanShuiKa_123_12,
	eET_KunLunShanShuiKa_350_24,
	eET_KunLunShanShuiKa_350_12
};

struct sDuoDuoMaiCaiChanPinXinXi
{
	double zl;
	double tj;
	sDuoDuoMaiCaiChanPinXinXi() :
	 zl(0), tj(0)
	{
	}
};


#define DOUBLE_PRECISION 0.00000001
typedef std::map<std::wstring, int> map_key_wstring_val_int;
typedef std::vector<std::wstring> vec_wvals;
typedef std::vector<std::wstring> split_wstr_vec;

