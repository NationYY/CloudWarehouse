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
};

#define DOUBLE_PRECISION 0.00000001