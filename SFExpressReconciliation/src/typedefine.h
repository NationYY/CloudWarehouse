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
	std::wstring strHuoZhu;				//����
	std::wstring strShouJianRen;		//�ռ���
	std::wstring strWuLiuGongSi;		//������˾
	std::wstring strWuLiuDanHao;		//��������
	std::wstring strSheng;				//ʡ
	std::wstring strShouJianRenDiZhi;	//�ռ��˵�ַ
	double dZhongLiang;					//����
	std::wstring strFaHuoShijian;		//������ַ
	std::wstring strHuoPinZongShuLiang;	//��Ʒ������
	std::wstring strHuoPinMingXi;
};
std::map< std::wstring, std::list<sSalesInfo> > g_mapAllSalesInfo;
std::map< std::wstring, sSalesInfo* > g_mapTempSalesInfo;