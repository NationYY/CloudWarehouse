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
	std::wstring strHuoZhu;				//货主
	std::wstring strShouJianRen;		//收件人
	std::wstring strWuLiuGongSi;		//物流公司
	std::wstring strWuLiuDanHao;		//物流单号
	std::wstring strSheng;				//省
	std::wstring strShi;				//市
	std::wstring strShouJianRenDiZhi;	//收件人地址
	std::wstring strZhongLiang;			//重量
	std::wstring strFaHuoShijian;		//发货时间
	std::wstring strHuoPinZongShuLiang;	//货品总数量
	std::wstring strHuoPinMingXi;		//货品明细
	std::wstring strYuanShiDanHao;		//原始单号
	std::wstring strDianPu;				//店铺
	std::wstring strBaoZhuang;			//包装
	std::wstring strKeFuBeiZhu;			//包装
	int nRow;							//在输出表中的行数
	int nBaoJiaJinE;					//保价金额
	bool bChaiFen;						//是否是拆分订单
	bool bXiuGaiZhongLiang;				//是否自动计算重量
	bool bKunLunShan;					//是否昆仑山
	double wuLiuFeiYong;				//物流费用 对账的时候用
	double zengZhiFeiYong;				//增值费用 对账的时候用
	sSalesInfo(): strHuoZhu(L""), strShouJianRen(L""), strWuLiuGongSi(L""), strWuLiuDanHao(L""), strSheng(L""), strShouJianRenDiZhi(L""),
		strZhongLiang(L""), strFaHuoShijian(L""), strHuoPinZongShuLiang(L""), strHuoPinMingXi(L""), nRow(0), strYuanShiDanHao(L""), 
		strDianPu(L""),nBaoJiaJinE(0), bChaiFen(true), strBaoZhuang(L""), strKeFuBeiZhu(L""), bXiuGaiZhongLiang(L""), bKunLunShan(false), strShi(L""),
		wuLiuFeiYong(0), zengZhiFeiYong(0)
	{
	}
};

struct sDuoDuoMaiCaiChuKuInfo
{
	std::wstring strHuoPinMingCheng;	//货品名称
	int nShuLiang;						//货品数量
	bool isBuDan;				//是否补单
	int nBoxCnt;				//箱数
	double dZhongLiang;			//重量
	double dTiJi;				//体积
	std::wstring strKeFuBeiZhu;	//客服备注
	sDuoDuoMaiCaiChuKuInfo():
		nShuLiang(0), isBuDan(false), nBoxCnt(0), dZhongLiang(0.0), dTiJi(0.0), strKeFuBeiZhu(L"")
	{
	}
};

struct sDuoDuoMaiCaiRuKuInfo
{
	std::wstring strShenHeShiJian;		//审核时间
	std::wstring strHuoPinMingCheng;	//货品名称
	int nShuLiang;						//货品数量
	double dZhongLiang;			//重量
	double dTiJi;				//体积
};

struct sDuoDuoMaiCaiDiaoBoInfo
{
	std::wstring strChuKuShiJian;		//出库时间
	std::wstring strHuoPinMingCheng;	//货品名称
	int nShuLiang;						//货品数量
};

struct sInStorageInfo
{
	std::wstring strHuoZhu;				//货主
	std::wstring strShangJiaBianMa;     //商家编码
	std::wstring strHuoPinBianMa;		//货品编码
	std::wstring strHuoPinMingCheng;	//货品名称
	std::wstring strPinPai;
	int nCnt;
	int nRow;
	sInStorageInfo(): strHuoZhu(L""), strShangJiaBianMa(L""), strHuoPinBianMa(L""), strHuoPinMingCheng(L""), nCnt(0), nRow(0), strPinPai(L"")
	{
	}
};

//快递价格
struct sExpressPriceInfo
{
	int nMinZL;			//最小重量 大于等于
	int nMaxZL;			//最大重量 小于
	int nFirstZL;		//首重
	double dFirstPrice;	//首重费用
	double dXZPrice;	//续重费用
	double dFirstCommission;//首重抽成
	double dXZCommission;	//续重抽成
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

//快运价格
struct sLargeExpressPriceInfo
{
	int nMinZL;			//最小重量 大于等于
	int nMaxZL;			//最大重量 小于
	int nFirstZL;		//首重
	double dFirstPrice;	//首重费用
	double dXZPrice;	//续重费用
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
	double dbZHzxf;	//调拨重货装卸费
	double dbPHzxf;	//调拨泡货装卸费
	double thZHPrice;//退货重货费
	double thPHPrice;//退货泡货费
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

