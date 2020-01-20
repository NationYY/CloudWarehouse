#include <string>
#include <map>
#include <set>
using namespace std;
struct sSFAuthData
{
	wstring number;
	wstring weight;
	wstring vaServices;
	int row;
};

struct sYCExportData
{
	wstring number;
	double weight;
	int row;
};
struct sSalesInfo
{
	std::wstring strHuoZhu;				//货主
	std::wstring strShouJianRen;		//收件人
	std::wstring strWuLiuGongSi;		//物流公司
	std::wstring strWuLiuDanHao;		//物流单号
	std::wstring strSheng;				//省
	std::wstring strShouJianRenDiZhi;	//收件人地址
	double dZhongLiang;					//重量
	std::wstring strFaHuoShijian;		//发货地址
	std::wstring strHuoPinZongShuLiang;	//货品总数量
	std::wstring strHuoPinMingXi;
};

#define DOUBLE_PRECISION 0.00000001