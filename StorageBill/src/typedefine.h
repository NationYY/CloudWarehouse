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
	bool bChaiFen;						//是否是拆分订单
	sSalesInfo(): strHuoZhu(L""), strShouJianRen(L""), strWuLiuGongSi(L""), strWuLiuDanHao(L""), strSheng(L""), strShouJianRenDiZhi(L""),
		strZhongLiang(L""), strFaHuoShijian(L""), strHuoPinZongShuLiang(L""), strHuoPinMingXi(L""), nRow(0), strYuanShiDanHao(L""), nBaoJiaJinE(0), bChaiFen(true)
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

struct sExpressPriceInfo
{
	int nMinZL;			//最小重量 大于等于
	int nMaxZL;			//最大重量 小于
	int nFirstZL;		//首重
	double dFirstPrice;	//首重费用
	double dXZPrice;	//续重费用
};

#define DOUBLE_PRECISION 0.00000001
typedef std::map<std::wstring, int> map_key_wstring_val_int;
typedef std::vector<std::wstring> vec_wvals;
typedef std::vector<std::wstring> split_wstr_vec;

//------------------------------------快递价格--------------------------------------//
//魔合科技
std::map< std::wstring, std::list<sExpressPriceInfo> > g_moHeKeJiBSPrice;
std::map< std::wstring, std::list<sExpressPriceInfo> > g_taiFuShangMaoBSPrice;
void PrepareExpressPrice()
{
	//最小重量 最大重量  首重	首重费用	续重费用
	//魔合百世
	{
		//0-3公斤 一口价
		g_moHeKeJiBSPrice[L"四川省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_moHeKeJiBSPrice[L"重庆"].push_back({ 0, 3, 3, 3.5, 0 });
		g_moHeKeJiBSPrice[L"云南省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_moHeKeJiBSPrice[L"贵州省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_moHeKeJiBSPrice[L"陕西省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_moHeKeJiBSPrice[L"江苏省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_moHeKeJiBSPrice[L"浙江省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_moHeKeJiBSPrice[L"上海"].push_back({ 0, 3, 3, 3.5, 0 });
		g_moHeKeJiBSPrice[L"安徽省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_moHeKeJiBSPrice[L"河南省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_moHeKeJiBSPrice[L"湖北省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_moHeKeJiBSPrice[L"福建省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_moHeKeJiBSPrice[L"北京"].push_back({ 0, 3, 3, 3.5, 0 });
		g_moHeKeJiBSPrice[L"天津"].push_back({ 0, 3, 3, 3.5, 0 });
		g_moHeKeJiBSPrice[L"广东省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_moHeKeJiBSPrice[L"广西壮族自治区"].push_back({ 0, 3, 3, 3.5, 0 });
		g_moHeKeJiBSPrice[L"河北省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_moHeKeJiBSPrice[L"湖南省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_moHeKeJiBSPrice[L"江西省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_moHeKeJiBSPrice[L"山西省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_moHeKeJiBSPrice[L"山东省"].push_back({ 0, 3, 3, 3.5, 0 });
		g_moHeKeJiBSPrice[L"甘肃省"].push_back({ 0, 3, 3, 4, 0 });
		g_moHeKeJiBSPrice[L"宁夏回族自治区"].push_back({ 0, 3, 3, 4, 0 });
		g_moHeKeJiBSPrice[L"青海省"].push_back({ 0, 3, 3, 4, 0 });
		g_moHeKeJiBSPrice[L"黑龙江省"].push_back({ 0, 3, 3, 3.8, 0 });
		g_moHeKeJiBSPrice[L"吉林省"].push_back({ 0, 3, 3, 3.8, 0 });
		g_moHeKeJiBSPrice[L"辽宁省"].push_back({ 0, 3, 3, 3.8, 0 });
		//3-10公斤 首重 续重
		g_moHeKeJiBSPrice[L"四川省"].push_back({ 3, 10, 3, 3.5, 1.7 });
		g_moHeKeJiBSPrice[L"重庆"].push_back({ 3, 10, 3, 3.5, 1.8 });
		g_moHeKeJiBSPrice[L"云南省"].push_back({ 3, 10, 3, 3.5, 1.8 });
		g_moHeKeJiBSPrice[L"贵州省"].push_back({ 3, 10, 3, 3.5, 1.8 });
		g_moHeKeJiBSPrice[L"陕西省"].push_back({ 3, 10, 3, 3.5, 1.8 });
		g_moHeKeJiBSPrice[L"江苏省"].push_back({ 3, 10, 3, 3.5, 1.8 });
		g_moHeKeJiBSPrice[L"浙江省"].push_back({ 3, 10, 3, 3.5, 1.8 });
		g_moHeKeJiBSPrice[L"上海"].push_back({ 3, 10, 3, 3.5, 1.8 });
		g_moHeKeJiBSPrice[L"安徽省"].push_back({ 3, 10, 3, 3.5, 1.8 });
		g_moHeKeJiBSPrice[L"河南省"].push_back({ 3, 10, 3, 3.5, 1.8 });
		g_moHeKeJiBSPrice[L"湖北省"].push_back({ 3, 10, 3, 3.5, 1.8 });
		g_moHeKeJiBSPrice[L"福建省"].push_back({ 3, 10, 3, 3.5, 1.8 });
		g_moHeKeJiBSPrice[L"北京"].push_back({ 3, 10, 3, 3.5, 1.8 });
		g_moHeKeJiBSPrice[L"天津"].push_back({ 3, 10, 3, 3.5, 1.8 });
		g_moHeKeJiBSPrice[L"广东省"].push_back({ 3, 10, 3, 3.5, 1.8 });
		g_moHeKeJiBSPrice[L"广西壮族自治区"].push_back({ 3, 10, 3, 3.5, 1.8 });
		g_moHeKeJiBSPrice[L"河北省"].push_back({ 3, 10, 3, 3.5, 1.8 });
		g_moHeKeJiBSPrice[L"湖南省"].push_back({ 3, 10, 3, 3.5, 1.8 });
		g_moHeKeJiBSPrice[L"江西省"].push_back({ 3, 10, 3, 3.5, 1.8 });
		g_moHeKeJiBSPrice[L"山西省"].push_back({ 3, 10, 3, 3.5, 1.8 });
		g_moHeKeJiBSPrice[L"山东省"].push_back({ 3, 10, 3, 3.5, 1.8 });
		g_moHeKeJiBSPrice[L"甘肃省"].push_back({ 3, 10, 3, 4, 2.2 });
		g_moHeKeJiBSPrice[L"宁夏回族自治区"].push_back({ 3, 10, 3, 4, 2.2 });
		g_moHeKeJiBSPrice[L"青海省"].push_back({ 3, 10, 3, 4, 2.2 });
		g_moHeKeJiBSPrice[L"黑龙江省"].push_back({ 3, 10, 3, 3.8, 2 });
		g_moHeKeJiBSPrice[L"吉林省"].push_back({ 3, 10, 3, 3.8, 2 });
		g_moHeKeJiBSPrice[L"辽宁省"].push_back({ 3, 10, 3, 3.8, 2 });
		//10公斤以上 首重 续重
		g_moHeKeJiBSPrice[L"四川省"].push_back({ 10, 0, 1, 4.5, 1.8 });
		g_moHeKeJiBSPrice[L"重庆"].push_back({ 10, 0, 1, 4.5, 2 });
		g_moHeKeJiBSPrice[L"云南省"].push_back({ 10, 0, 1, 4.5, 3.5 });
		g_moHeKeJiBSPrice[L"贵州省"].push_back({ 10, 0, 1, 4.5, 3.5 });
		g_moHeKeJiBSPrice[L"陕西省"].push_back({ 10, 0, 1, 4.5, 3.5 });
		g_moHeKeJiBSPrice[L"江苏省"].push_back({ 10, 0, 1, 4.5, 3.5 });
		g_moHeKeJiBSPrice[L"浙江省"].push_back({ 10, 0, 1, 4.5, 3.5 });
		g_moHeKeJiBSPrice[L"上海"].push_back({ 10, 0, 1, 4.5, 3.5 });
		g_moHeKeJiBSPrice[L"安徽省"].push_back({ 10, 0, 1, 4.5, 3.5 });
		g_moHeKeJiBSPrice[L"河南省"].push_back({ 10, 0, 1, 4.5, 3.5 });
		g_moHeKeJiBSPrice[L"湖北省"].push_back({ 10, 0, 1, 4.5, 3.5 });
		g_moHeKeJiBSPrice[L"福建省"].push_back({ 10, 0, 1, 4.5, 3.5 });
		g_moHeKeJiBSPrice[L"北京"].push_back({ 10, 0, 1, 4.5, 3.5 });
		g_moHeKeJiBSPrice[L"天津"].push_back({ 10, 0, 1, 4.5, 3.5 });
		g_moHeKeJiBSPrice[L"广东省"].push_back({ 10, 0, 1, 4.5, 3.5 });
		g_moHeKeJiBSPrice[L"广西壮族自治区"].push_back({ 10, 0, 1, 4.5, 3.5 });
		g_moHeKeJiBSPrice[L"河北省"].push_back({ 10, 0, 1, 4.5, 3.5 });
		g_moHeKeJiBSPrice[L"湖南省"].push_back({ 10, 0, 1, 4.5, 3.5 });
		g_moHeKeJiBSPrice[L"江西省"].push_back({ 10, 0, 1, 4.5, 3.5 });
		g_moHeKeJiBSPrice[L"山西省"].push_back({ 10, 0, 1, 4.5, 3.5 });
		g_moHeKeJiBSPrice[L"山东省"].push_back({ 10, 0, 1, 4.5, 3.5 });
		g_moHeKeJiBSPrice[L"甘肃省"].push_back({ 10, 0, 1, 4.5, 5.5 });
		g_moHeKeJiBSPrice[L"宁夏回族自治区"].push_back({ 10, 0, 1, 4.5, 5.5 });
		g_moHeKeJiBSPrice[L"青海省"].push_back({ 10, 0, 1, 4.5, 5.5 });
		g_moHeKeJiBSPrice[L"黑龙江省"].push_back({ 10, 0, 1, 4.5, 6.5 });
		g_moHeKeJiBSPrice[L"吉林省"].push_back({ 10, 0, 1, 4.5, 6.5 });
		g_moHeKeJiBSPrice[L"辽宁省"].push_back({ 10, 0, 1, 4.5, 6.5 });
		///////////////////
		g_moHeKeJiBSPrice[L"内蒙古自治区"].push_back({ 0, 0, 1, 7.5, 4.5 });
		g_moHeKeJiBSPrice[L"海南省"].push_back({ 0, 0, 1, 7.5, 4 });
		g_moHeKeJiBSPrice[L"新疆维吾尔自治区"].push_back({ 0, 0, 1, 13, 11 });
		g_moHeKeJiBSPrice[L"西藏自治区"].push_back({ 0, 0, 1, 13, 11 });
	}
	//泰福商贸
	{
		//0-3公斤 一口价
		g_taiFuShangMaoBSPrice[L"四川省"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"重庆"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"云南省"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"贵州省"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"陕西省"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"江苏省"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"浙江省"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"上海"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"安徽省"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"河南省"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"湖北省"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"福建省"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"北京"].push_back({ 0, 3, 3, 4.2, 0 });
		g_taiFuShangMaoBSPrice[L"天津"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"广东省"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"广西壮族自治区"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"河北省"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"湖南省"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"江西省"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"山西省"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"山东省"].push_back({ 0, 3, 3, 3.8, 0 });
		g_taiFuShangMaoBSPrice[L"甘肃省"].push_back({ 0, 3, 3, 4.2, 0 });
		g_taiFuShangMaoBSPrice[L"宁夏回族自治区"].push_back({ 0, 3, 3, 4.2, 0 });
		g_taiFuShangMaoBSPrice[L"青海省"].push_back({ 0, 3, 3, 4.2, 0 });
		g_taiFuShangMaoBSPrice[L"黑龙江省"].push_back({ 0, 3, 3, 4.2, 0 });
		g_taiFuShangMaoBSPrice[L"吉林省"].push_back({ 0, 3, 3, 4.2, 0 });
		g_taiFuShangMaoBSPrice[L"辽宁省"].push_back({ 0, 3, 3, 4.2, 0 });
		//3公斤以上
		g_taiFuShangMaoBSPrice[L"四川省"].push_back({ 3, 0, 1, 3.8, 1.2 });
		g_taiFuShangMaoBSPrice[L"重庆"].push_back({ 3, 0, 1, 3.8, 1.7 });
		g_taiFuShangMaoBSPrice[L"云南省"].push_back({ 3, 0, 1, 3.8, 1.7 });
		g_taiFuShangMaoBSPrice[L"贵州省"].push_back({ 3, 0, 1, 3.8, 1.7 });
		g_taiFuShangMaoBSPrice[L"陕西省"].push_back({ 3, 0, 1, 3.8, 1.7 });
		g_taiFuShangMaoBSPrice[L"江苏省"].push_back({ 3, 0, 1, 3.8, 1.7 });
		g_taiFuShangMaoBSPrice[L"浙江省"].push_back({ 3, 0, 1, 3.8, 1.7 });
		g_taiFuShangMaoBSPrice[L"上海"].push_back({ 3, 0, 1, 3.8, 2 });
		g_taiFuShangMaoBSPrice[L"安徽省"].push_back({ 3, 0, 1, 3.8, 1.7 });
		g_taiFuShangMaoBSPrice[L"河南省"].push_back({ 3, 0, 1, 3.8, 1.7 });
		g_taiFuShangMaoBSPrice[L"湖北省"].push_back({ 3, 0, 1, 3.8, 1.7 });
		g_taiFuShangMaoBSPrice[L"福建省"].push_back({ 3, 0, 1, 3.8, 1.7 });
		g_taiFuShangMaoBSPrice[L"北京"].push_back({ 3, 0, 1, 4.2, 2 });
		g_taiFuShangMaoBSPrice[L"天津"].push_back({ 3, 0, 1, 3.8, 1.7 });
		g_taiFuShangMaoBSPrice[L"广东省"].push_back({ 3, 0, 1, 3.8, 1.7 });
		g_taiFuShangMaoBSPrice[L"广西壮族自治区"].push_back({ 3, 0, 1, 3.8, 1.7 });
		g_taiFuShangMaoBSPrice[L"河北省"].push_back({ 3, 0, 1, 3.8, 1.7 });
		g_taiFuShangMaoBSPrice[L"湖南省"].push_back({ 3, 0, 1, 3.8, 1.7 });
		g_taiFuShangMaoBSPrice[L"江西省"].push_back({ 3, 0, 1, 3.8, 1.7 });
		g_taiFuShangMaoBSPrice[L"山西省"].push_back({ 3, 0, 1, 3.8, 1.7 });
		g_taiFuShangMaoBSPrice[L"山东省"].push_back({ 3, 0, 1, 3.8, 1.7 });
		g_taiFuShangMaoBSPrice[L"甘肃省"].push_back({ 3, 0, 1, 4.2, 2.2 });
		g_taiFuShangMaoBSPrice[L"宁夏回族自治区"].push_back({ 3, 0, 1, 4.2, 2.4 });
		g_taiFuShangMaoBSPrice[L"青海省"].push_back({ 3, 0, 1, 4.2, 2.4 });
		g_taiFuShangMaoBSPrice[L"黑龙江省"].push_back({ 3, 0, 1, 4.2, 2.5 });
		g_taiFuShangMaoBSPrice[L"吉林省"].push_back({ 3, 0, 1, 4.2, 2.2 });
		g_taiFuShangMaoBSPrice[L"辽宁省"].push_back({ 3, 0, 1, 4.2, 1.7 });
	}
}
//----------------------------------------------------------------------------------//