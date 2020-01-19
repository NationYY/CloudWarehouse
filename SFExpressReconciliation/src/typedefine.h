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
	std::string strHuoZhu;
	std::string strShouJianRen;
	std::string strWuLiuGongSi;
	std::string strWuLiuDanHao;
	std::string strSheng;
	std::string strShouJianRenDiZhi;
	double dZhongLiang;
	std::string strFaHuoShijian;
	std::string strHuoPinMingXi;
};
std::map< std::wstring, std::list<sSalesInfo> > g_mapAllSalesInfo;