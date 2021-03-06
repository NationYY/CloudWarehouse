﻿
// StorageBillDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "StorageBill.h"
#include "StorageBillDlg.h"
#include "afxdialogex.h"
#include "func_common.h"
#include <stdio.h>
#include <io.h>
#include <direct.h>
#include "shlwapi.h"
#include "expressPrice.h"
#define THROW_ERROR(info) AddLog(info); return false;
#define SHEET_CELL_STRING(sheet, r, c, strOut) _pStr = sheet->Cell(r, c)->GetWString();\
if(_pStr)\
	strOut = _pStr;

#define SHEET_CELL_DOUBLE(sheet, r, c, dOut) dOut = sheet->Cell(r, c)->GetDouble();

#define SHEET_CELL_INT(sheet, r, c, nOut) nOut = sheet->Cell(r, c)->GetInteger();

#define TOTAL_FILE_PATH L"./系统数据/"+m_strYM+L"/销售出库单"
#define DETAIL_FILE_PATH L"./系统数据/"+m_strYM+L"/销售出库明细"
#define SF_FILE_PATH L"./系统数据/"+m_strYM+L"/顺丰账单.xls"
#define IN_STORAGE_PATH L"./系统数据/"+m_strYM+L"/入库明细账.xls"
#define KUAI_YUN_WEIGHT_FILE_PATH L"./系统数据/"+m_strYM+L"/快运出库重量.xls"
#define BSKD_FILE_PATH L"./系统数据/"+m_strYM+L"/百世快递账单.xls"
#define ZTKY_FILE_PATH L"./系统数据/"+m_strYM+L"/中通快运账单.xls"
#define DUODUOMAICAI_DETAIL_FILE_PATH L"./系统数据/"+m_strYM+L"/多多买菜出库明细.xls"
#define DUODUOMAICAI_IN_STORAGE_PATH L"./系统数据/"+m_strYM+L"/多多买菜入库明细账.xls"
#define DUODUOMAICAI_DIAOBO_PATH L"./系统数据/"+m_strYM+L"/多多买菜调拨明细.xls"

#define DUODUOMAICAI_PRICE_FILE L"./系统数据/DuoDuoMaiCai_Price.ini"
const wchar_t* g_arrWorksheetName[] ={L"顺丰重量差异订单", L"顺丰云仓未处理单号", L"顺丰价格异常", L"百世快递重量差异订单", L"中通快运重量差异订单", L"中通快运费用差异订单"};
int g_arrRecordRowIndex[] ={0, 0, 0, 0, 0, 0};
const wchar_t* g_arrHuoZhuName[] ={L"永创耀辉", L"弥雅食器", L"泰福商贸", L"颐麦科技", L"新马帮", L"七一酱园", L"永创昆仑山", L"凡将", L"韩太郎", L"玖王", L"至善电商", L"女巫科技", L"辣风芹", L"维敷康", L"硕果流香", L"静心阁", L"昆仑山水卡", L"阔伟电商", L"趣旅收纳", L"星星少女零食", L"兔娘娘", L"初见柠檬茶", L"卡多格", L"小白熊", L"艾维尔"};
void ListFiles(const char * dir, std::list<string>& listFiles);
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg: public CDialogEx
{
public:
	CAboutDlg();

	// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg(): CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CStorageBillDlg 对话框



CStorageBillDlg::CStorageBillDlg(CWnd* pParent /*=NULL*/)
: CDialogEx(CStorageBillDlg::IDD, pParent),
 m_bExit(false), m_bRun(false), m_sfHandleCol(-1), m_bskdHandleCol(-1), m_ztkyHandleCol(-1),
 m_bDuoDuoMaiCai(false), m_bZYKYMore(false), m_ztkyChengBenCol(-1), m_bCheckYDKD(false), m_bSingleYDKD(false)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CStorageBillDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST3, m_ctrlListLog);
	DDX_Control(pDX, IDC_EDIT1, m_editYM);
	DDX_Control(pDX, IDC_CHECK1, m_checkSF);
	DDX_Control(pDX, IDC_CHECK2, m_checkBSKD);
	DDX_Control(pDX, IDC_CHECK3, m_checkYGZD);
	DDX_Control(pDX, IDC_CHECK4, m_checkZTKY);
	DDX_Control(pDX, IDC_CHECK5, m_checkDuoDuoMaiCai);
	DDX_Control(pDX, IDC_CHECK7, m_checkZTKYMore);
	DDX_Control(pDX, IDC_CHECK6, m_checkYDKDCheck);
	DDX_Control(pDX, IDC_CHECK8, m_checkSingleYDKD);
}

BEGIN_MESSAGE_MAP(CStorageBillDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CStorageBillDlg::OnBnClickedCreateBill)
	ON_WM_TIMER()
	ON_LBN_DBLCLK(IDC_LIST3, &CStorageBillDlg::OnLbnDblclkLogList)
	ON_BN_CLICKED(IDC_CHECK7, &CStorageBillDlg::OnBnClickedCheckZTKYMore)
	ON_BN_CLICKED(IDC_CHECK5, &CStorageBillDlg::OnBnClickedCheckDDMC)
	ON_BN_CLICKED(IDC_CHECK3, &CStorageBillDlg::OnBnClickedCheckYG)
	ON_BN_CLICKED(IDC_CHECK6, &CStorageBillDlg::OnBnClickedCheckYDKD)
END_MESSAGE_MAP()


// CStorageBillDlg 消息处理程序

BOOL CStorageBillDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if(pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if(!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码
	m_logicThread = boost::thread(boost::bind(&CStorageBillDlg::_LogicThread, this));
	SetTimer(0, 1, NULL);
	time_t tNow = time(NULL);
	tm* pTM = localtime(&tNow);
	CString ym;
	if(pTM->tm_mon+1 == 1)
		ym.Format(L"%d12", pTM->tm_year+1900-1);
	else
		ym.Format(L"%d%02d", pTM->tm_year+1900, pTM->tm_mon);
	m_editYM.SetWindowText(ym.GetBuffer());
	PrepareExpressPrice();
	m_bSFErrorPrice = false;
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CStorageBillDlg::FillKDWeight()
{
	std::map< std::wstring, std::list<sSalesInfo> >::iterator itB1 = m_mapAllSalesInfo.begin();
	std::map< std::wstring, std::list<sSalesInfo> >::iterator itE1 = m_mapAllSalesInfo.end();
	while(itB1 != itE1)
	{
		std::list<sSalesInfo>::iterator itB2 = itB1->second.begin();
		std::list<sSalesInfo>::iterator itE2 = itB1->second.end();
		while(itB2 != itE2)
		{
			if(IsBaiShiKuaiDi(itB2->strWuLiuGongSi) && IsZero(itB2->strZhongLiang))
			{
				std::map<std::wstring, sBSKDAuthData>::iterator itBS = m_mapBSKDAuthData.find(itB2->strWuLiuDanHao);
				if(itBS != m_mapBSKDAuthData.end())
					itB2->strZhongLiang = CFuncCommon::Double2WString(itBS->second.ysWeight+DOUBLE_PRECISION, 2);
				else
				{
					std::list<sSalesInfo>::iterator _itB2 = itB1->second.begin();
					std::list<sSalesInfo>::iterator _itE2 = itB1->second.end();
					while(_itB2 != _itE2)
					{
						if(_itB2 != itB2 && _itB2->strHuoPinMingXi == itB2->strHuoPinMingXi && !IsZero(_itB2->strZhongLiang))
						{
							itB2->strZhongLiang = _itB2->strZhongLiang;
							break;
						}
						_itB2++;
					}
					if(_itB2 == _itE2)
					{
						wchar_t szBuffer[128] = { 0 };
						wsprintfW(szBuffer, L"%s 修复重量失败,未找到订单", itB2->strWuLiuDanHao.c_str());
						AddLog(szBuffer);
					}
				}
			}
			else if(IsShunFengKuaiDi(itB2->strWuLiuGongSi) && IsZero(itB2->strZhongLiang))
			{
				std::map<std::wstring, sSFAuthData>::iterator itSF = m_mapSFAuthData.find(itB2->strWuLiuDanHao);
				if(itSF != m_mapSFAuthData.end())
					itB2->strZhongLiang = itSF->second.weight;
				else
				{
					std::list<sSalesInfo>::iterator _itB2 = itB1->second.begin();
					std::list<sSalesInfo>::iterator _itE2 = itB1->second.end();
					while(_itB2 != _itE2)
					{
						if(_itB2 != itB2 && _itB2->strHuoPinMingXi == itB2->strHuoPinMingXi && !IsZero(_itB2->strZhongLiang))
						{
							itB2->strZhongLiang = _itB2->strZhongLiang;
							break;
						}
						_itB2++;
					}
					if(_itB2 == _itE2)
					{
						wchar_t szBuffer[128] = { 0 };
						wsprintfW(szBuffer, L"%s 修复重量失败,未找到订单", itB2->strWuLiuDanHao.c_str());
						AddLog(szBuffer);
					}
				}
			}
			itB2++;
		}
		itB1++;
	}

}

bool CStorageBillDlg::Handle_DuoDuoMaiCai()
{
	std::wstring strHuiZong = L"";
	std::map< std::wstring, std::map< std::wstring, std::list<sDuoDuoMaiCaiChuKuInfo> > >::iterator itB = m_mapDuoDuoMaiCaiChuKu.begin();
	std::map< std::wstring, std::map< std::wstring, std::list<sDuoDuoMaiCaiChuKuInfo> > >::iterator itE = m_mapDuoDuoMaiCaiChuKu.end();
	while(itB != itE)
	{
		sDuoDuoMaiCaiPriceInfo* pPriceInfo = &g_duoDuoMaiCaiPrice[itB->first];
		BasicExcel excel;
		excel.AddWorksheet(L"费用明细");
		
		wstring fileName = L"./Export_" + m_strYM + L"/" + itB->first + L"_" + m_strYM + L"对账单.xls";
		if(strHuiZong == L"")
			strHuiZong = L"=[" + itB->first + L"_" + m_strYM + L"对账单.xls" + L"]费用明细!$B$";
		else
			strHuiZong = strHuiZong + L"+[" + itB->first + L"_" + m_strYM + L"对账单.xls" + L"]费用明细!$B$";
		string _file = CFuncCommon::WString2String(fileName.c_str());
		BasicExcelWorksheet* sheet = excel.GetWorksheet(L"费用明细");
		int nRecordRowIndex = 0;
		sheet->Cell(nRecordRowIndex, 0)->SetWString(L"来货时间");
		sheet->Cell(nRecordRowIndex, 1)->SetWString(L"货品名称");
		sheet->Cell(nRecordRowIndex, 2)->SetWString(L"数量");
		sheet->Cell(nRecordRowIndex, 3)->SetWString(L"重量(kg)");
		sheet->Cell(nRecordRowIndex, 4)->SetWString(L"体积(m3)");
		sheet->Cell(nRecordRowIndex, 5)->SetWString(L"装卸费");
		nRecordRowIndex++;
		std::map< std::wstring, std::list<sDuoDuoMaiCaiRuKuInfo> >::iterator itRK = m_mapDuoDuoMaiCaiRuKu.find(pPriceInfo->strPinPai);
		if(itRK != m_mapDuoDuoMaiCaiRuKu.end())
		{
			std::list<sDuoDuoMaiCaiRuKuInfo>::iterator itRB = itRK->second.begin();
			std::list<sDuoDuoMaiCaiRuKuInfo>::iterator itRE = itRK->second.end();
			while(itRB != itRE)
			{
				std::wstring strDate = itRB->strShenHeShiJian.substr(0, 11);
				sheet->Cell(nRecordRowIndex, 0)->SetWString(strDate.c_str());
				sheet->Cell(nRecordRowIndex, 1)->SetWString(itRB->strHuoPinMingCheng.c_str());
				sheet->Cell(nRecordRowIndex, 2)->SetInteger(itRB->nShuLiang);
				sheet->Cell(nRecordRowIndex, 3)->SetWString(CFuncCommon::Double2WString(itRB->dZhongLiang*itRB->nShuLiang+DOUBLE_PRECISION, 4).c_str());
				double dTiJiCheck = itRB->dTiJi;
				double dTiJi = itRB->dTiJi;
				if(itRB->dTiJi > 100)
					dTiJi = itRB->dTiJi/1000000;
				else
					dTiJiCheck = itRB->dTiJi*100*100*100;
				sheet->Cell(nRecordRowIndex, 4)->SetWString(CFuncCommon::Double2WString(dTiJi*itRB->nShuLiang+DOUBLE_PRECISION, 4).c_str());
				if(dTiJiCheck/6000 > itRB->dZhongLiang)
				{
					//泡货
					if(pPriceInfo->dbPHzxf > DOUBLE_PRECISION)
						sheet->Cell(nRecordRowIndex, 5)->SetDouble(dTiJi*itRB->nShuLiang*pPriceInfo->dbPHzxf);
					else
						sheet->Cell(nRecordRowIndex, 5)->SetDouble(itRB->dZhongLiang*itRB->nShuLiang/1000*pPriceInfo->dbZHzxf);
				}
				else
				{
					//重货
					if(pPriceInfo->dbZHzxf > DOUBLE_PRECISION)
						sheet->Cell(nRecordRowIndex, 5)->SetDouble(itRB->dZhongLiang*itRB->nShuLiang/1000*pPriceInfo->dbZHzxf);
					else
						sheet->Cell(nRecordRowIndex, 5)->SetDouble(dTiJi*itRB->nShuLiang*pPriceInfo->dbPHzxf);
				}
				nRecordRowIndex++;
				++itRB;
			}
		}
		nRecordRowIndex++;
		sDuoDuoMaiCaiPriceDetail* pPrice = NULL;
		{
			sheet->Cell(nRecordRowIndex, 0)->SetWString(L"多多送货时间");
			sheet->Cell(nRecordRowIndex, 1)->SetWString(L"货品名称");
			sheet->Cell(nRecordRowIndex, 2)->SetWString(L"数量");
			sheet->Cell(nRecordRowIndex, 3)->SetWString(L"重量(kg)");
			sheet->Cell(nRecordRowIndex, 4)->SetWString(L"体积(m3)");
			sheet->Cell(nRecordRowIndex, 5)->SetWString(L"送货费");
			sheet->Cell(nRecordRowIndex, 6)->SetWString(L"装卸费");
			sheet->Cell(nRecordRowIndex, 7)->SetWString(L"箱数");
			sheet->Cell(nRecordRowIndex, 8)->SetWString(L"贴标费");
			sheet->Cell(nRecordRowIndex, 9)->SetWString(L"备注");
			nRecordRowIndex++;
			std::map< std::wstring, std::list<sDuoDuoMaiCaiChuKuInfo> >::iterator itB1 = itB->second.begin();
			std::map< std::wstring, std::list<sDuoDuoMaiCaiChuKuInfo> >::iterator itE1 = itB->second.end();
			while(itB1 != itE1)
			{
				bool bHaveBeiZhu = false;
				if(itB1->second.begin()->strKeFuBeiZhu != L"")
				{
					sheet->Cell(nRecordRowIndex, 9)->SetWString(itB1->second.begin()->strKeFuBeiZhu.c_str());
					bHaveBeiZhu = true;
				}
				if(itB1->second.begin()->isBuDan)
				{
					if(!bHaveBeiZhu)
						sheet->Cell(nRecordRowIndex, 9)->SetWString(L"补单");
					pPrice = &pPriceInfo->BuDanPrice;
				}
				else
					pPrice = &pPriceInfo->biaoZhunPrice;
				sheet->Cell(nRecordRowIndex, 0)->SetWString(itB1->first.c_str());
				std::list<sDuoDuoMaiCaiChuKuInfo>::iterator itB2 = itB1->second.begin();
				std::list<sDuoDuoMaiCaiChuKuInfo>::iterator itE2 = itB1->second.end();
				int fhRowIndex = -1;
				double shf = 0;
				while(itB2 != itE2)
				{
					sheet->Cell(nRecordRowIndex, 1)->SetWString(itB2->strHuoPinMingCheng.c_str());
					sheet->Cell(nRecordRowIndex, 2)->SetInteger(itB2->nShuLiang);
					sheet->Cell(nRecordRowIndex, 3)->SetDouble(itB2->dZhongLiang);
					if(itB2 == itB1->second.begin())
					{
						fhRowIndex = nRecordRowIndex;
						sheet->Cell(nRecordRowIndex, 7)->SetInteger(itB2->nBoxCnt);
						if(pPriceInfo->tieBiao > DOUBLE_PRECISION)
							sheet->Cell(nRecordRowIndex, 8)->SetDouble(pPriceInfo->tieBiao*itB2->nBoxCnt);
						else
							sheet->Cell(nRecordRowIndex, 8)->SetDouble(0);
					}
					double dTiJiCheck = itB2->dTiJi;
					double dTiJi = itB2->dTiJi;
					if(itB2->dTiJi > 100)
						dTiJi = itB2->dTiJi / 1000000;
					else
						dTiJiCheck = itB2->dTiJi * 100 * 100 * 100;
					sheet->Cell(nRecordRowIndex, 4)->SetDouble(dTiJi);
					double shfZL = itB2->dZhongLiang*pPrice->fhZhongLiang;
					double shfTJ = dTiJi*pPrice->fhTiJi;
					shf += max(shfZL, shfTJ);
					if(dTiJiCheck / 6000 > itB2->dZhongLiang)
					{
						//泡货
						if(pPrice->zxPaoHuo > DOUBLE_PRECISION)
							sheet->Cell(nRecordRowIndex, 6)->SetDouble(dTiJi*pPrice->zxPaoHuo * 2);
						else
							sheet->Cell(nRecordRowIndex, 6)->SetDouble(itB2->dZhongLiang / 1000 * pPrice->zxZhongHuo * 2);
					}
					else
					{
						//重货
						if(pPrice->zxZhongHuo > DOUBLE_PRECISION)
							sheet->Cell(nRecordRowIndex, 6)->SetDouble(itB2->dZhongLiang / 1000 * pPrice->zxZhongHuo * 2);
						else
							sheet->Cell(nRecordRowIndex, 6)->SetDouble(dTiJi*pPrice->zxPaoHuo * 2);
					}
					sheet->Cell(fhRowIndex, 5)->SetDouble(max(pPrice->qiBu,shf));
					nRecordRowIndex++;
					itB2++;
				}

				

				itB1++;
			}
		}
		nRecordRowIndex++;
		{
			sheet->Cell(nRecordRowIndex, 0)->SetWString(L"退货时间");
			sheet->Cell(nRecordRowIndex, 1)->SetWString(L"货品名称");
			sheet->Cell(nRecordRowIndex, 2)->SetWString(L"数量");
			sheet->Cell(nRecordRowIndex, 3)->SetWString(L"重量(kg)");
			sheet->Cell(nRecordRowIndex, 4)->SetWString(L"体积(m3)");
			sheet->Cell(nRecordRowIndex, 5)->SetWString(L"退货费");
			sheet->Cell(nRecordRowIndex, 6)->SetWString(L"装卸费");
			nRecordRowIndex++;
			std::map< std::wstring, std::map< std::wstring, std::list<sDuoDuoMaiCaiRuKuInfo> > >::iterator itRK = m_mapDuoDuoMaiCaiTuiHuo.find(pPriceInfo->strPinPai);
			if(itRK != m_mapDuoDuoMaiCaiTuiHuo.end())
			{
				std::map< std::wstring, std::list<sDuoDuoMaiCaiRuKuInfo> >::iterator _itRB = itRK->second.begin();
				std::map< std::wstring, std::list<sDuoDuoMaiCaiRuKuInfo> >::iterator _itRE = itRK->second.end();
				while(_itRB != _itRE)
				{
					std::list<sDuoDuoMaiCaiRuKuInfo>::iterator itRB = _itRB->second.begin();
					std::list<sDuoDuoMaiCaiRuKuInfo>::iterator itRE = _itRB->second.end();
					double shf = 0;
					double zxf = 0;
					int row_index = -1;
					while(itRB != itRE)
					{
						if(itRB == _itRB->second.begin())
						{
							std::wstring strDate = itRB->strShenHeShiJian.substr(0, 11);
							sheet->Cell(nRecordRowIndex, 0)->SetWString(strDate.c_str());
							row_index = nRecordRowIndex;
						}
						sheet->Cell(nRecordRowIndex, 1)->SetWString(itRB->strHuoPinMingCheng.c_str());
						sheet->Cell(nRecordRowIndex, 2)->SetInteger(itRB->nShuLiang);
						sheet->Cell(nRecordRowIndex, 3)->SetWString(CFuncCommon::Double2WString(itRB->dZhongLiang*itRB->nShuLiang + DOUBLE_PRECISION, 4).c_str());
						double dTiJiCheck = itRB->dTiJi;
						double dTiJi = itRB->dTiJi;
						if(itRB->dTiJi > 100)
							dTiJi = itRB->dTiJi / 1000000;
						else
							dTiJiCheck = itRB->dTiJi * 100 * 100 * 100;
						sheet->Cell(nRecordRowIndex, 4)->SetWString(CFuncCommon::Double2WString(dTiJi*itRB->nShuLiang + DOUBLE_PRECISION, 4).c_str());
						double shfZL = 0;
						if(pPriceInfo->thZHPrice > DOUBLE_PRECISION)
							shfZL = itRB->dZhongLiang*itRB->nShuLiang*pPriceInfo->thZHPrice;
						else
							shfZL = itRB->dZhongLiang*itRB->nShuLiang*pPriceInfo->biaoZhunPrice.fhZhongLiang;
						double shfTJ = 0;
						if(pPriceInfo->thPHPrice > DOUBLE_PRECISION)
							shfTJ = dTiJi*pPriceInfo->thPHPrice;
						else
							shfTJ = dTiJi*pPriceInfo->biaoZhunPrice.fhTiJi;
						shf += max(shfZL, shfTJ);
						if(dTiJiCheck / 6000 > itRB->dZhongLiang)
						{
							//泡货
							if(pPriceInfo->biaoZhunPrice.zxPaoHuo > DOUBLE_PRECISION)
								zxf += dTiJi*itRB->nShuLiang*pPriceInfo->biaoZhunPrice.zxPaoHuo;
							else
								zxf += itRB->dZhongLiang*itRB->nShuLiang / 1000 * pPrice->zxZhongHuo;
						}
						else
						{
							//重货
							if(pPrice->zxZhongHuo > DOUBLE_PRECISION)
								zxf += itRB->dZhongLiang*itRB->nShuLiang / 1000 * pPrice->zxZhongHuo;
							else
								zxf += dTiJi*itRB->nShuLiang*pPriceInfo->biaoZhunPrice.zxPaoHuo;
						}
						nRecordRowIndex++;
						++itRB;
					}
					if(shf + zxf < pPriceInfo->tuiHuoMianFei)
					{
						sheet->Cell(row_index, 5)->SetDouble(0);
						sheet->Cell(row_index, 6)->SetDouble(0);
					}
					else
					{
						sheet->Cell(row_index, 5)->SetDouble(shf);
						sheet->Cell(row_index, 6)->SetDouble(zxf);
					}
					++_itRB;
				}
			}
		}

		nRecordRowIndex++;
		{
			sheet->Cell(nRecordRowIndex, 0)->SetWString(L"调拨出库时间");
			sheet->Cell(nRecordRowIndex, 1)->SetWString(L"货品名称");
			sheet->Cell(nRecordRowIndex, 2)->SetWString(L"数量");
			sheet->Cell(nRecordRowIndex, 3)->SetWString(L"重量(kg)");
			sheet->Cell(nRecordRowIndex, 4)->SetWString(L"体积(m3)");
			sheet->Cell(nRecordRowIndex, 5)->SetWString(L"装卸费");
			nRecordRowIndex++;
			std::map< std::wstring, std::list<sDuoDuoMaiCaiDiaoBoInfo> >::iterator itRK = m_mapDuoDuoMaiCaiDiaoBo.find(pPriceInfo->strPinPai);
			if(itRK != m_mapDuoDuoMaiCaiDiaoBo.end())
			{
				std::list<sDuoDuoMaiCaiDiaoBoInfo>::iterator itRB = itRK->second.begin();
				std::list<sDuoDuoMaiCaiDiaoBoInfo>::iterator itRE = itRK->second.end();
				while(itRB != itRE)
				{
					std::wstring strDate = itRB->strChuKuShiJian.substr(0, 11);
					sheet->Cell(nRecordRowIndex, 0)->SetWString(strDate.c_str());
					sheet->Cell(nRecordRowIndex, 1)->SetWString(itRB->strHuoPinMingCheng.c_str());
					sheet->Cell(nRecordRowIndex, 2)->SetInteger(itRB->nShuLiang);

					sheet->Cell(nRecordRowIndex, 3)->SetWString(L"0");
					sheet->Cell(nRecordRowIndex, 4)->SetWString(L"0");
					sheet->Cell(nRecordRowIndex, 5)->SetWString(L"0");
					std::map< std::wstring, std::map< std::wstring, sDuoDuoMaiCaiChanPinXinXi> >::iterator itPP = m_mapDuoDuoMaiCaiShangPinXinXi.find(pPriceInfo->strPinPai);
					if(itPP != m_mapDuoDuoMaiCaiShangPinXinXi.end())
					{
						std::map< std::wstring, sDuoDuoMaiCaiChanPinXinXi>::iterator itHP = itPP->second.find(itRB->strHuoPinMingCheng.c_str());
						if(itHP != itPP->second.end())
						{
							double zxf = 0;
							sheet->Cell(nRecordRowIndex, 3)->SetWString(CFuncCommon::Double2WString(itHP->second.zl*itRB->nShuLiang + DOUBLE_PRECISION, 4).c_str());
							double dTiJiCheck = itHP->second.tj;
							double dTiJi = itHP->second.tj;
							if(itHP->second.tj > 100)
								dTiJi = itHP->second.tj / 1000000;
							else
								dTiJiCheck = itHP->second.tj * 100 * 100 * 100;
							sheet->Cell(nRecordRowIndex, 4)->SetWString(CFuncCommon::Double2WString(dTiJi*itRB->nShuLiang + DOUBLE_PRECISION, 4).c_str());
							if(dTiJiCheck / 6000 > itHP->second.zl)
							{
								//泡货
								if(pPriceInfo->dbPHzxf > DOUBLE_PRECISION)
									zxf += dTiJi*itRB->nShuLiang*pPriceInfo->dbPHzxf;
								else
									zxf += itHP->second.zl*itRB->nShuLiang / 1000 * pPriceInfo->dbZHzxf;
							}
							else
							{
								//重货
								if(pPriceInfo->dbZHzxf > DOUBLE_PRECISION)
									zxf += itHP->second.zl*itRB->nShuLiang / 1000 * pPriceInfo->dbZHzxf;
								else
									zxf += dTiJi*itRB->nShuLiang*pPriceInfo->dbPHzxf;
							}
							sheet->Cell(nRecordRowIndex, 5)->SetDouble(zxf);
						}
					}

					
					nRecordRowIndex++;
					
					++itRB;
				}
			}
		}


		nRecordRowIndex++;
		sheet->Cell(nRecordRowIndex, 0)->SetWString(L"租用面积(平方)");
		sheet->Cell(nRecordRowIndex, 1)->SetWString(L"起租时间");
		sheet->Cell(nRecordRowIndex, 2)->SetWString(L"结算时间");
		sheet->Cell(nRecordRowIndex, 3)->SetWString(L"费用(元)");
		nRecordRowIndex++;

		sheet->Cell(nRecordRowIndex, 0)->SetInteger(pPriceInfo->nZuiXiaoMianJi);

		sheet->Cell(nRecordRowIndex, 1)->SetWString((m_strYM + L"01").c_str());
		wstring lastDay;
		time_t tNow = time(NULL);
		tm* pTM = localtime(&tNow);
		if(pTM->tm_mon + 1 == 1)
			lastDay = GetLastDay(pTM->tm_year + 1900 - 1, 12);
		else
			lastDay = GetLastDay(pTM->tm_year + 1900, pTM->tm_mon);
		sheet->Cell(nRecordRowIndex, 2)->SetWString((m_strYM + lastDay).c_str());
		wstring gs = L"";
		gs = gs + L"=A" + CFuncCommon::String2WString(CFuncCommon::ToString(nRecordRowIndex+1)) + L"*" + pPriceInfo->zujin + L"*1.15" ;
		sheet->Cell(nRecordRowIndex, 3)->SetWString(gs.c_str());
		gs = L"";
		gs = gs + L"=INT(SUM(F:F,G:G,I:I)+D" + CFuncCommon::String2WString(CFuncCommon::ToString(nRecordRowIndex+1)) + L")";
		nRecordRowIndex++;
		nRecordRowIndex++;
		sheet->Cell(nRecordRowIndex, 0)->SetWString(L"合计");
		sheet->Cell(nRecordRowIndex++, 1)->SetWString(gs.c_str());
		wchar_t ws[33];
		strHuiZong = strHuiZong + _itow(nRecordRowIndex, ws, 10);
		excel.SaveAs(_file.c_str());
		wchar_t szBuffer[128] = { 0 };
		wsprintfW(szBuffer, L"%s 账单生成成功", itB->first.c_str());
		AddLog(szBuffer);
		++itB;
	}

	BasicExcel _excel;
	_excel.AddWorksheet(L"汇总");

	wstring fileName = L"./Export_" + m_strYM + L"/" + L"汇总.xls";
	string _file = CFuncCommon::WString2String(fileName.c_str());
	BasicExcelWorksheet* _sheet = _excel.GetWorksheet(L"汇总");
	_sheet->Cell(0, 0)->SetWString(strHuiZong.c_str());
	_excel.SaveAs(_file.c_str());
	return true;
}

std::wstring CStorageBillDlg::GetLastDay(int year, int month)
{
	if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		return L"31";
	else if(month == 2)
	{
		if((year % 100 == 0 && year % 400 == 0) || (year % 100 != 0 && year % 4 == 0))
			return L"29";
		else
			return L"28";
	}
	else
		return L"30";
}
	
void CStorageBillDlg::_LogicThread()
{
	while(!m_bExit)
	{
		if(m_bRun)
		{
			if(m_bDuoDuoMaiCai)
			{
				if(!LoadDuoDuoMaiCaiPrice())
					goto __break_logic;
				if(!ParseDuoDuoMaiCaiALLData())
					goto __break_logic;
				if(!Handle_DuoDuoMaiCai())
					goto __break_logic;
				AddLog(L"多多买菜账单生成完成");

				AddLog(L"冰露水价格另算");
				AddLog(L"放心食品一箱2");
				AddLog(L"蔬菜协助入库0.05一份");
				AddLog(L"冰露协助入库500件以下0.2一件,以上0.1");
			}
			else
			{
				if(!LoadYDKDData())
					goto __break_logic;
				if(!ParseALLData())
					goto __break_logic;
				if(!CreateHuoZhuFile())
					goto __break_logic;
				Sleep(2000);
				if(!LoadSFData())
					goto __break_logic;
				if(!LoadBSKDData())
					goto __break_logic;
				if(!LoadZTKYData())
					goto __break_logic;
				if(m_bZYKYMore)
					CheckZTKYMore();
				else if(m_bCheckYDKD)
					CheckYDKDMore();
				else
				{
					FillKDWeight();
					if(!Handle_YongChuangYaoHui())
						goto __break_logic;
					if(!m_bYG)
					{
						if(!Handle_MiYaShiQi())
							goto __break_logic;
						if(!Handle_TaiFuShangMao())
							goto __break_logic;
						if(!Handle_YiMaiKeJi())
							goto __break_logic;
						if(!Handle_XinMaBang())
							goto __break_logic;
						if(!Handle_QiYiJiangYuan())
							goto __break_logic;
						if(!Handle_HanTaiLang())
							goto __break_logic;
						if(!Handle_HaTeNengLiang())
							goto __break_logic;
						//if(!Handle_LaFengQing())
						//	goto __break_logic;
						if(!Handle_ZhiShanDianShang(L"至善电商"))
							goto __break_logic;
						if(!Handle_ZhiShanDianShang(L"女巫科技"))
							goto __break_logic;
						if(!Handle_WeiFuKang())
							goto __break_logic;
						if(!Handle_ShuoGuoLiuXiang())
							goto __break_logic;
						if(!Handle_JingXinGe())
							goto __break_logic;
						if(!Handle_KunLunShanShuiKa())
							goto __break_logic;
						if(!Handle_KuoWeiDianShang())
							goto __break_logic;
						if(!Handle_QuLvShouNa())
							goto __break_logic;
						if(!Handle_XingXingShaoNv())
							goto __break_logic;
						if(!Handle_TuNiangNiang())
							goto __break_logic;
						if(!Handle_ChuJianNingMengCha())
							goto __break_logic;
						if(!Handle_KaDuoGe())
							goto __break_logic;
						if(!Handle_XiaoBaiXiong())
							goto __break_logic;
						if(!Handle_AiWeiEr())
							goto __break_logic;
					}
				}
				wstring filePath = L"./Export_" + m_strYM + L"/" + L"compare_record.xls";
				string _filePath = CFuncCommon::WString2String(filePath.c_str());
				m_recordExcel.SaveAs(_filePath.c_str());
				m_sfExcel.Save();
				m_bskdExcel.Save();
				m_ztkyExcel.Save();
				std::map<BasicExcel*, sYDKDHandleCol>::iterator itEB = m_mapYDKDHandleCol.begin();
				std::map<BasicExcel*, sYDKDHandleCol>::iterator itEE = m_mapYDKDHandleCol.end();
				while(itEB != itEE)
				{
					itEB->first->Save();
					delete itEB->first;
					++itEB;
				}
				AddLog(L"账单生成完成");
				AddLog(L"顺丰 整件酒包装盒");
				AddLog(L"春节快递加价");
			}
		}
	__break_logic:
		m_bRun = false;
		boost::this_thread::sleep(boost::posix_time::milliseconds(10));
	}
}

void CStorageBillDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CStorageBillDlg::OnPaint()
{
	if(IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CStorageBillDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CStorageBillDlg::OnBnClickedCreateBill()
{
	CString strYM;
	m_editYM.GetWindowText(strYM);
	if(strYM == "")
	{
		MessageBox(L"未填写账单年月");
		return;
	}
	m_bSF = (m_checkSF.GetState()==1);
	m_bSingleYDKD = (m_checkSingleYDKD.GetState()==1);
	m_bBSKD = (m_checkBSKD.GetState()==1);
	m_bZYKY = (m_checkZTKY.GetState()==1);
	m_bYG = (m_checkYGZD.GetState()==1);
	m_bZYKYMore = (m_checkZTKYMore.GetState()==1);
	m_bCheckYDKD = (m_checkYDKDCheck.GetState()==1);
	m_bDuoDuoMaiCai = (m_checkDuoDuoMaiCai.GetState()==1);
	m_bRun = true;
	m_strYM = strYM.GetBuffer();
	wstring folderPath = L"./Export_" + m_strYM;
	if(0 != _waccess(folderPath.c_str(), 0))
		_wmkdir(folderPath.c_str());
	m_logFile.close();
	wstring logPath = folderPath + L"./log.txt";
	m_logFile.open(logPath);
	m_logFile.imbue(std::locale("chs"));
	if(!m_logFile.is_open())
	{
		MessageBox(L"创建日志文件失败!");
		return;
	}
	AddLog(L"开始生成账单信息");
}

void CStorageBillDlg::AddLog(std::wstring strLog)
{
	m_queueLog.push(strLog);
}

void CStorageBillDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	wstring strLog;
	if(m_queueLog.pop(strLog))
	{
		m_logFile << strLog << endl;
		m_logFile.flush();

		m_ctrlListLog.InsertString(0, strLog.c_str());
		SetHScroll();
		if(strLog == L"账单生成完成")
			MessageBox(L"账单生成完成");
	}
	CDialogEx::OnTimer(nIDEvent);
}

void CStorageBillDlg::SetHScroll()
{
	CDC* dc = GetDC();
	SIZE s;
	int index;
	CString str;
	long temp;
	for(index = 0; index< m_ctrlListLog.GetCount(); index++)
	{
		m_ctrlListLog.GetText(index, str);
		s = dc->GetTextExtent(str, str.GetLength() + 1);

		temp = (long)SendDlgItemMessage(IDC_LIST3, LB_GETHORIZONTALEXTENT, 0, 0);
		if(s.cx > temp)
			SendDlgItemMessage(IDC_LIST3, LB_SETHORIZONTALEXTENT, (WPARAM)s.cx, 0);
	}
	ReleaseDC(dc);
}

bool CStorageBillDlg::LoadXiaoShouChuKuMingXi(std::wstring wfileName, bool checkFail)
{
	BasicExcel detailExcel;
	std::string fileName = CFuncCommon::WString2String(wfileName.c_str());
	if(!detailExcel.Load(fileName.c_str()))
	{
		if(checkFail)
		{
			wchar_t szBuffer[128] ={0};
			wsprintfW(szBuffer, L"%s 加载失败", wfileName.c_str());
			THROW_ERROR(szBuffer);
		}
		return true;
	}
	std::set<int> setNoZL;
	BasicExcelWorksheet* detailSheet = detailExcel.GetWorksheet(L"Sheet1");
	if(detailSheet)
	{
		std::set<std::wstring> setNotHaveBaoJiaJinE;
		size_t maxRows = detailSheet->GetTotalRows();
		size_t maxCols = detailSheet->GetTotalCols();

		int nHuoPinMingCheng = -1;
		int nHuoPinZongShuLiang = -1;
		int nHuoPinShuLiang = -1;
		int nWuLiuDanHao = -1;
		int nSheng = -1;
		int nShengShiQu = -1;
		int nShi = -1;
		int nPinPai = -1;
		for(size_t c = 0; c < maxCols; ++c)
		{
			BasicExcelCell* cell = detailSheet->Cell(0, c);
			std::wstring strTitle = cell->GetWString();
			if(strTitle == L"货品名称")
				nHuoPinMingCheng = c;
			else if(strTitle == L"货品总数量")
				nHuoPinZongShuLiang = c;
			else if(strTitle == L"货品数量")
				nHuoPinShuLiang = c;
			else if(strTitle == L"物流编号")
				nWuLiuDanHao = c;
			else if(strTitle == L"省")
				nSheng = c;
			else if(strTitle == L"市")
				nShi = c;
			else if(strTitle == L"省市区")
				nShengShiQu = c;
			else if(strTitle == L"品牌")
				nPinPai = c;
		}
		if(nHuoPinMingCheng == -1 || nHuoPinZongShuLiang == -1 || nHuoPinShuLiang == -1 || nWuLiuDanHao == -1 || nSheng == -1 || nShi == -1 || nShengShiQu == -1 || nPinPai == -1)
		{
			wchar_t szBuffer[128] ={0};
			wsprintfW(szBuffer, L"%s 有标题未找到", wfileName.c_str());
			THROW_ERROR(szBuffer);
		}
		for(size_t r = 1; r < maxRows; ++r)
		{
			std::wstring strWuLiuDanHao;
			std::wstring strPinPai;
			const wchar_t* _pStr = NULL;
			SHEET_CELL_STRING(detailSheet, r, nWuLiuDanHao, strWuLiuDanHao);
			SHEET_CELL_STRING(detailSheet, r, nPinPai, strPinPai);
			std::map< std::wstring, sSalesInfo* >::iterator it = m_mapTempSalesInfo.find(strWuLiuDanHao);
			if(it == m_mapTempSalesInfo.end())
			{
				continue;
				wchar_t szBuffer[128] ={0};
				wsprintfW(szBuffer, L"%s 未找到单号%s 行数=%d", wfileName.c_str(), strWuLiuDanHao.c_str(), r);
				THROW_ERROR(szBuffer);
			}
			double dZSL = detailSheet->Cell(r, nHuoPinZongShuLiang)->GetDouble();
			it->second->strHuoPinZongShuLiang = CFuncCommon::Double2WString(dZSL+DOUBLE_PRECISION, 0);
			SHEET_CELL_STRING(detailSheet, r, nSheng, it->second->strSheng);
			if(it->second->strSheng == L"")
			{
				wstring strShengShiQu = L"";
				SHEET_CELL_STRING(detailSheet, r, nShengShiQu, strShengShiQu);
				if(strShengShiQu.find(L"广西区省") != wstring::npos)
				{
					it->second->strSheng = L"广西壮族自治区";
				}
				else if(strShengShiQu.find(L"宁夏区省") != wstring::npos)
				{
					it->second->strSheng = L"宁夏回族自治区";
				}
				else
				{
					wchar_t szBuffer[128] ={0};
					wsprintfW(szBuffer, L"%s 未识别省市区 %s", wfileName.c_str(), strShengShiQu.c_str());
					THROW_ERROR(szBuffer);
				}
			}
			SHEET_CELL_STRING(detailSheet, r, nShi, it->second->strShi);
			std::wstring strHuoPinMingCheng;
			SHEET_CELL_STRING(detailSheet, r, nHuoPinMingCheng, strHuoPinMingCheng);
			double dSL = detailSheet->Cell(r, nHuoPinShuLiang)->GetDouble();
			std::wstring strHuoPinShuLiang = CFuncCommon::Double2WString(dSL+DOUBLE_PRECISION, 0);
			if(it->second->strHuoPinMingXi == L"")
				it->second->strHuoPinMingXi = strHuoPinMingCheng + L"@" + strHuoPinShuLiang;
			else
				it->second->strHuoPinMingXi = it->second->strHuoPinMingXi + L";" + strHuoPinMingCheng + L"@" + strHuoPinShuLiang;
			if(strPinPai == L"昆仑山")
				it->second->bKunLunShan = true;
			if(strHuoPinMingCheng != L"杏汁180ml*1罐" && strHuoPinMingCheng != L"番茄汁180ml*1罐")
				it->second->bChaiFen = false;

			if(it->second->strHuoZhu == L"辣风芹")
			{
				if(IsBaiShiKuaiDi(it->second->strWuLiuGongSi) || IsYunDaKuaiDi(it->second->strWuLiuGongSi))
				{
					if(strHuoPinMingCheng == L"辣风芹炒米粉")
					{
						int nCnt = _wtoi(strHuoPinShuLiang.c_str());
						switch(nCnt)
						{
						case 1:
							it->second->strZhongLiang = L"0.5430";
							break;
						case 2:
							it->second->strZhongLiang = L"0.9880";
							break;
						case 3:
							it->second->strZhongLiang = L"1.4850";
							break;
						case 4:
							it->second->strZhongLiang = L"1.9250";
							break;
						case 5:
							it->second->strZhongLiang = L"2.3630";
							break;
						case 6:
							it->second->strZhongLiang = L"2.8100";
							break;
						case 8:
							it->second->strZhongLiang = L"3.9440";
							break;
						case 10:
							it->second->strZhongLiang = L"4.7320";
							break;
						default:
							{
								double zl = 0.4933*nCnt;
								it->second->strZhongLiang = CFuncCommon::Double2WString(zl, 4);
							}
							break;
						}
					}
					else if(strHuoPinMingCheng == L"赠品")
						it->second->strZhongLiang = L"1.0000";
				}
			}


			int nBjsl = _wtoi(strHuoPinShuLiang.c_str());
			if(strWuLiuDanHao == L"SF1038081448912")
				int a = 3;
			std::map< std::wstring, int >::iterator itBJ = m_mapBaoJiaJinE.find(strHuoPinMingCheng);
			if(itBJ != m_mapBaoJiaJinE.end())
				it->second->nBaoJiaJinE += itBJ->second*nBjsl;
			else if(it->second->strHuoZhu == L"永创耀辉" && strPinPai != L"昆仑山" && IsShunFengKuaiDi(it->second->strWuLiuGongSi))
			{
				std::set<std::wstring>::iterator itNHBJ = setNotHaveBaoJiaJinE.find(strHuoPinMingCheng);
				if(itNHBJ == setNotHaveBaoJiaJinE.end())
				{
					setNotHaveBaoJiaJinE.insert(strHuoPinMingCheng);
					wchar_t szBuffer[128] ={0};
					wsprintfW(szBuffer, L"未找到保价金额 货品=%s", strHuoPinMingCheng.c_str());
					AddLog(szBuffer);
				}
			}
		}
		wchar_t szBuffer[128] ={0};
		wsprintfW(szBuffer, L"读取 %s 成功", wfileName.c_str());
		AddLog(szBuffer);
	}
	else
	{
		wchar_t szBuffer[128] ={0};
		wsprintfW(szBuffer, L"%s 加载失败", wfileName.c_str());
		THROW_ERROR(szBuffer);
	}
	return true;
}

bool CStorageBillDlg::LoadXiaoShouChuKuDan(std::wstring wfileName, bool checkFail)
{
	std::string fileName = CFuncCommon::WString2String(wfileName.c_str());
	BasicExcel totalExcel;
	if(!totalExcel.Load(fileName.c_str()))
	{
		if(checkFail)
		{
			wchar_t szBuffer[128] ={0};
			wsprintfW(szBuffer, L"%s 加载失败", wfileName.c_str());
			THROW_ERROR(szBuffer);
		}
		return true;
	}
	BasicExcelWorksheet* totalSheet = totalExcel.GetWorksheet(L"Sheet1");
	if(totalSheet)
	{
		size_t maxRows = totalSheet->GetTotalRows();
		size_t maxCols = totalSheet->GetTotalCols();

		int nHuoZhu = -1;
		int nShouJianRen = -1;
		int nWuLiuGongSi = -1;
		int nWuLiuDanHao = -1;
		int nShouJianRenDiZhi = -1;
		int nZhongLiang = -1;
		int nFaHuoShijian = -1;
		int nYuanShiDanHao = -1;
		int nDianPu = -1;
		int nBaoZhuang = -1;
		int nKeFuBeiZhu = -1;
		for(size_t c = 0; c < maxCols; ++c)
		{
			BasicExcelCell* cell = totalSheet->Cell(0, c);
			std::wstring strTitle = cell->GetWString();
			if(strTitle == L"货主")
				nHuoZhu = c;
			else if(strTitle == L"收件人")
				nShouJianRen = c;
			else if(strTitle == L"物流公司")
				nWuLiuGongSi = c;
			else if(strTitle == L"物流单号")
				nWuLiuDanHao = c;
			else if(strTitle == L"收件人地址")
				nShouJianRenDiZhi = c;
			else if(strTitle == L"实际重量")
				nZhongLiang = c;
			else if(strTitle == L"发货时间")
				nFaHuoShijian = c;
			else if(strTitle == L"原始单号")
				nYuanShiDanHao = c;
			else if(strTitle == L"店铺")
				nDianPu = c;
			else if(strTitle == L"包装")
				nBaoZhuang = c;
			else if(strTitle == L"客服备注")
				nKeFuBeiZhu = c;

		}
		if(nHuoZhu == -1 || nShouJianRen == -1 || nWuLiuGongSi == -1 || nWuLiuDanHao == -1 || nShouJianRenDiZhi == -1 || nZhongLiang == -1 || nFaHuoShijian == -1 || nYuanShiDanHao == -1 || nDianPu == -1 || nKeFuBeiZhu == -1)
		{
			wchar_t szBuffer[128] ={0};
			wsprintfW(szBuffer, L"%s 有标题未找到", wfileName.c_str());
			THROW_ERROR(szBuffer);
		}
		for(size_t r = 1; r < maxRows; ++r)
		{
			sSalesInfo _data;
			const wchar_t* _pStr = NULL;
			SHEET_CELL_STRING(totalSheet, r, nHuoZhu, _data.strHuoZhu);
			SHEET_CELL_STRING(totalSheet, r, nShouJianRen, _data.strShouJianRen);
			SHEET_CELL_STRING(totalSheet, r, nWuLiuGongSi, _data.strWuLiuGongSi);
			SHEET_CELL_STRING(totalSheet, r, nWuLiuDanHao, _data.strWuLiuDanHao);
			if(_data.strWuLiuDanHao == L"557032185722055")
				int a = 3;
			if(_data.strWuLiuDanHao == L"SF1038081448912")
				int a = 3;
			SHEET_CELL_STRING(totalSheet, r, nShouJianRenDiZhi, _data.strShouJianRenDiZhi);
			SHEET_CELL_STRING(totalSheet, r, nYuanShiDanHao, _data.strYuanShiDanHao);
			SHEET_CELL_STRING(totalSheet, r, nDianPu, _data.strDianPu);
			SHEET_CELL_STRING(totalSheet, r, nBaoZhuang, _data.strBaoZhuang);
			SHEET_CELL_STRING(totalSheet, r, nKeFuBeiZhu, _data.strKeFuBeiZhu);
			if(_data.strYuanShiDanHao != L"")
				_data.bChaiFen = false;
			const wchar_t* szZL = totalSheet->Cell(r, nZhongLiang)->GetWString();
			double dTemp = 0.0;
			if(szZL == NULL)
				dTemp = totalSheet->Cell(r, nZhongLiang)->GetDouble();
			else
				dTemp = _wtof(szZL);
			if(dTemp > 0.001)
				dTemp += 0.05;
			if(IsShunFengKuaiDi(_data.strWuLiuGongSi))
			{
				m_setSFCangKuData.insert(_data.strWuLiuDanHao);
				if(m_bSF)
					m_mapYCNeedSFHandle[_data.strHuoZhu].insert(_data.strWuLiuDanHao);
			}
			_data.strZhongLiang = CFuncCommon::Double2WString(dTemp+DOUBLE_PRECISION, 2);
			SHEET_CELL_STRING(totalSheet, r, nFaHuoShijian, _data.strFaHuoShijian);
			m_mapAllSalesInfo[_data.strHuoZhu].push_back(_data);
			std::list<sSalesInfo>::iterator it = --m_mapAllSalesInfo[_data.strHuoZhu].end();
			m_mapTempSalesInfo[_data.strWuLiuDanHao] = &(*it);
		}
		wchar_t szBuffer[128] ={0};
		wsprintfW(szBuffer, L"读取 %s 成功", wfileName.c_str());
		AddLog(szBuffer);
	}
	else
	{
		wchar_t szBuffer[128] ={0};
		wsprintfW(szBuffer, L"%s 加载失败", wfileName.c_str());
		THROW_ERROR(szBuffer);
	}
	return true;
}
bool CStorageBillDlg::LoadDuoDuoMaiCaiPrice()
{
	std::list<wstring> listAllHuoZhu;
	for(int i=0; i<200; ++i)
	{
		wchar_t szBuffer[128] = { 0 };
		wchar_t szResult[128] = { 0 };
		wsprintfW(szBuffer, L"HuoZhu%d", i+1);
		GetPrivateProfileString(L"HuoZhu", szBuffer, L"", szResult, 128, DUODUOMAICAI_PRICE_FILE);
		if(StrCmpW(szResult, L"") == 0)
			break;
		listAllHuoZhu.push_back(szResult);
	}
	std::list<wstring>::iterator itB = listAllHuoZhu.begin();
	std::list<wstring>::iterator itE = listAllHuoZhu.end();
	while(itB != itE)
	{
		wchar_t szBuffer[128] = { 0 };
		wchar_t szDianPu[128] = { 0 };
		wchar_t szTijiCM[128] = { 0 };
		wchar_t szZuJin[128] = { 0 };
		wchar_t szZuiXiaoMianJi[128] = {};
		wchar_t szTieBiaoFeiYong[128] = { 0 };
		wchar_t szTuiHuoMianDan[128] = { 0 };
		wchar_t szBiaoZhun_PaoHuoZhuangXie[128] = { 0 };
		wchar_t szBiaoZhun_ZhongHuoZhuangXie[128] = { 0 };
		wchar_t szBiaoZhun_TiJiFaHuo[128] = { 0 };
		wchar_t szBiaoZhun_ZhongLiangFaHuo[128] = { 0 };
		wchar_t szBiaoZhun_FaHuoQiBuJia[128] = { 0 };

		wchar_t szBuDan_PaoHuoZhuangXie[128] = { 0 };
		wchar_t szBuDan_ZhongHuoZhuangXie[128] = { 0 };
		wchar_t szBuDan_TiJiFaHuo[128] = { 0 };
		wchar_t szBuDan_ZhongLiangFaHuo[128] = { 0 };
		wchar_t szBuDan_FaHuoQiBuJia[128] = { 0 };

		wchar_t szDiaoBo_ZhongHuoZhuangXie[128] = { 0 };
		wchar_t szDiaoBo_PaoHuoZhuangXie[128] = { 0 };

		wchar_t szPaoHuoTuiHuo[128] = { 0 };
		wchar_t szZhongHuoTuiHuo[128] = { 0 };

		wsprintfW(szBuffer, L"%s_店铺名称", itB->c_str());
		GetPrivateProfileString(L"Price", szBuffer, L"", szDianPu, 128, DUODUOMAICAI_PRICE_FILE);
		if(StrCmpW(szDianPu, L"") == 0)
		{
			wchar_t szBuffer[128] = { 0 };
			wsprintfW(szBuffer, L"多多买菜 未找到货主详细价格%s", itB->c_str());
			THROW_ERROR(szBuffer);
		}
		wsprintfW(szBuffer, L"%s_体积厘米", itB->c_str());
		GetPrivateProfileString(L"Price", szBuffer, L"", szTijiCM, 128, DUODUOMAICAI_PRICE_FILE);

		wsprintfW(szBuffer, L"%s_租金", itB->c_str());
		GetPrivateProfileString(L"Price", szBuffer, L"", szZuJin, 128, DUODUOMAICAI_PRICE_FILE);

		wsprintfW(szBuffer, L"%s_最小面积", itB->c_str());
		GetPrivateProfileString(L"Price", szBuffer, L"", szZuiXiaoMianJi, 128, DUODUOMAICAI_PRICE_FILE);

		wsprintfW(szBuffer, L"%s_贴标费用", itB->c_str());
		GetPrivateProfileString(L"Price", szBuffer, L"", szTieBiaoFeiYong, 128, DUODUOMAICAI_PRICE_FILE);

		wsprintfW(szBuffer, L"%s_退货免单费", itB->c_str());
		GetPrivateProfileString(L"Price", szBuffer, L"", szTuiHuoMianDan, 128, DUODUOMAICAI_PRICE_FILE);

		wsprintfW(szBuffer, L"%s_标准_抛货装卸价格", itB->c_str());
		GetPrivateProfileString(L"Price", szBuffer, L"", szBiaoZhun_PaoHuoZhuangXie, 128, DUODUOMAICAI_PRICE_FILE);
		wsprintfW(szBuffer, L"%s_标准_重货装卸价格", itB->c_str());
		GetPrivateProfileString(L"Price", szBuffer, L"", szBiaoZhun_ZhongHuoZhuangXie, 128, DUODUOMAICAI_PRICE_FILE);
		wsprintfW(szBuffer, L"%s_标准_体积发货价格", itB->c_str());
		GetPrivateProfileString(L"Price", szBuffer, L"", szBiaoZhun_TiJiFaHuo, 128, DUODUOMAICAI_PRICE_FILE);
		wsprintfW(szBuffer, L"%s_标准_重量发货价格", itB->c_str());
		GetPrivateProfileString(L"Price", szBuffer, L"", szBiaoZhun_ZhongLiangFaHuo, 128, DUODUOMAICAI_PRICE_FILE);
		wsprintfW(szBuffer, L"%s_标准_发货起步价", itB->c_str());
		GetPrivateProfileString(L"Price", szBuffer, L"", szBiaoZhun_FaHuoQiBuJia, 128, DUODUOMAICAI_PRICE_FILE);

		wsprintfW(szBuffer, L"%s_补单_抛货装卸价格", itB->c_str());
		GetPrivateProfileString(L"Price", szBuffer, L"", szBuDan_PaoHuoZhuangXie, 128, DUODUOMAICAI_PRICE_FILE);
		wsprintfW(szBuffer, L"%s_补单_重货装卸价格", itB->c_str());
		GetPrivateProfileString(L"Price", szBuffer, L"", szBuDan_ZhongHuoZhuangXie, 128, DUODUOMAICAI_PRICE_FILE);
		wsprintfW(szBuffer, L"%s_补单_体积发货价格", itB->c_str());
		GetPrivateProfileString(L"Price", szBuffer, L"", szBuDan_TiJiFaHuo, 128, DUODUOMAICAI_PRICE_FILE);
		wsprintfW(szBuffer, L"%s_补单_重量发货价格", itB->c_str());
		GetPrivateProfileString(L"Price", szBuffer, L"", szBuDan_ZhongLiangFaHuo, 128, DUODUOMAICAI_PRICE_FILE);
		wsprintfW(szBuffer, L"%s_补单_发货起步价", itB->c_str());
		GetPrivateProfileString(L"Price", szBuffer, L"", szBuDan_FaHuoQiBuJia, 128, DUODUOMAICAI_PRICE_FILE);

		wsprintfW(szBuffer, L"%s_调拨抛货装卸价格", itB->c_str());
		GetPrivateProfileString(L"Price", szBuffer, L"", szDiaoBo_PaoHuoZhuangXie, 128, DUODUOMAICAI_PRICE_FILE);
		wsprintfW(szBuffer, L"%s_调拨重货装卸价格", itB->c_str());
		GetPrivateProfileString(L"Price", szBuffer, L"", szDiaoBo_ZhongHuoZhuangXie, 128, DUODUOMAICAI_PRICE_FILE);

		wsprintfW(szBuffer, L"%s_抛货退货价格", itB->c_str());
		GetPrivateProfileString(L"Price", szBuffer, L"", szPaoHuoTuiHuo, 128, DUODUOMAICAI_PRICE_FILE);
		wsprintfW(szBuffer, L"%s_重货退货价格", itB->c_str());
		GetPrivateProfileString(L"Price", szBuffer, L"", szZhongHuoTuiHuo, 128, DUODUOMAICAI_PRICE_FILE);


		g_duoDuoMaiCaiPrice[szDianPu].strPinPai = itB->c_str();
		g_duoDuoMaiCaiPrice[szDianPu].isCM = (StrCmpW(szTijiCM, L"1") == 0);
		g_duoDuoMaiCaiPrice[szDianPu].zujin = szZuJin;
		g_duoDuoMaiCaiPrice[szDianPu].tieBiao = _wtof(szTieBiaoFeiYong);
		g_duoDuoMaiCaiPrice[szDianPu].tuiHuoMianFei = _wtof(szTuiHuoMianDan);
		g_duoDuoMaiCaiPrice[szDianPu].nZuiXiaoMianJi = _wtoi(szZuiXiaoMianJi);
		g_duoDuoMaiCaiPrice[szDianPu].dbZHzxf = _wtof(szDiaoBo_ZhongHuoZhuangXie);
		g_duoDuoMaiCaiPrice[szDianPu].dbPHzxf = _wtof(szDiaoBo_PaoHuoZhuangXie);

		g_duoDuoMaiCaiPrice[szDianPu].thPHPrice = _wtof(szPaoHuoTuiHuo);
		g_duoDuoMaiCaiPrice[szDianPu].thZHPrice = _wtof(szZhongHuoTuiHuo);

		g_duoDuoMaiCaiPrice[szDianPu].biaoZhunPrice.zxPaoHuo  = _wtof(szBiaoZhun_PaoHuoZhuangXie);
		g_duoDuoMaiCaiPrice[szDianPu].biaoZhunPrice.zxZhongHuo  = _wtof(szBiaoZhun_ZhongHuoZhuangXie);
		g_duoDuoMaiCaiPrice[szDianPu].biaoZhunPrice.fhTiJi  = _wtof(szBiaoZhun_TiJiFaHuo);
		g_duoDuoMaiCaiPrice[szDianPu].biaoZhunPrice.fhZhongLiang  = _wtof(szBiaoZhun_ZhongLiangFaHuo);
		g_duoDuoMaiCaiPrice[szDianPu].biaoZhunPrice.qiBu  = _wtof(szBiaoZhun_FaHuoQiBuJia);

		g_duoDuoMaiCaiPrice[szDianPu].BuDanPrice.zxPaoHuo = _wtof(szBuDan_PaoHuoZhuangXie);
		g_duoDuoMaiCaiPrice[szDianPu].BuDanPrice.zxZhongHuo = _wtof(szBuDan_ZhongHuoZhuangXie);
		g_duoDuoMaiCaiPrice[szDianPu].BuDanPrice.fhTiJi = _wtof(szBuDan_TiJiFaHuo);
		g_duoDuoMaiCaiPrice[szDianPu].BuDanPrice.fhZhongLiang = _wtof(szBuDan_ZhongLiangFaHuo);
		g_duoDuoMaiCaiPrice[szDianPu].BuDanPrice.qiBu = _wtof(szBuDan_FaHuoQiBuJia);
		++itB;
	}
	return true;
}

bool CStorageBillDlg::ParseDuoDuoMaiCaiALLData()
{
	{
		BasicExcel excel;
		std::wstring strFileName = DUODUOMAICAI_DETAIL_FILE_PATH;
		std::string fileName = CFuncCommon::WString2String(strFileName.c_str());
		if(!excel.Load(fileName.c_str()))
		{
			wchar_t szBuffer[128] = { 0 };
			wsprintfW(szBuffer, L"%s 加载失败", strFileName.c_str());
			THROW_ERROR(szBuffer);
		}
		BasicExcelWorksheet* sheet = excel.GetWorksheet(L"Sheet1");
		if(sheet)
		{
			size_t maxRows = sheet->GetTotalRows();
			size_t maxCols = sheet->GetTotalCols();

			int nHuoZhu = -1;
			int nDianPu = -1;
			int nHuoPinMingCheng = -1;
			int nHuoPinShuLiang = -1;
			int nZhongLiang = -1;
			int nTiJi = -1;
			int nJieDanShiJian = -1;
			int nDaYinBeiZhu = -1;
			int nKeFuBeiZhu = -1;
			for(size_t c = 0; c < maxCols; ++c)
			{
				BasicExcelCell* cell = sheet->Cell(0, c);
				std::wstring strTitle = cell->GetWString();
				if(strTitle == L"货主")
					nHuoZhu = c;
				else if(strTitle == L"店铺")
					nDianPu = c;
				else if(strTitle == L"货品名称")
					nHuoPinMingCheng = c;
				else if(strTitle == L"货品数量")
					nHuoPinShuLiang = c;
				else if(strTitle == L"货品总重量")
					nZhongLiang = c;
				else if(strTitle == L"货品总体积")
					nTiJi = c;
				else if(strTitle == L"发货时间")
					nJieDanShiJian = c;
				else if(strTitle == L"打印备注")
					nDaYinBeiZhu = c;
				else if(strTitle == L"客服备注")
					nKeFuBeiZhu = c;
				
			}
			if(nHuoZhu == -1 || nDianPu == -1 || nHuoPinMingCheng == -1 || nHuoPinShuLiang == -1 || nZhongLiang == -1 || nTiJi == -1 || nJieDanShiJian == -1 || nKeFuBeiZhu == -1)
			{
				wchar_t szBuffer[128] = { 0 };
				wsprintfW(szBuffer, L"%s 有标题未找到", strFileName.c_str());
				THROW_ERROR(szBuffer);
			}
			for(size_t r = 1; r < maxRows; ++r)
			{
				std::wstring strHuoZhu;
				std::wstring strDianPu;
				std::wstring strJieDanShiJian;
				const wchar_t* _pStr = NULL;
				SHEET_CELL_STRING(sheet, r, nHuoZhu, strHuoZhu);
				SHEET_CELL_STRING(sheet, r, nDianPu, strDianPu);
				SHEET_CELL_STRING(sheet, r, nJieDanShiJian, strJieDanShiJian);

				if(strHuoZhu == L"多多买菜")
				{
					std::map< std::wstring, sDuoDuoMaiCaiPriceInfo >::iterator itHuoZhu = g_duoDuoMaiCaiPrice.find(strDianPu);
					if(itHuoZhu == g_duoDuoMaiCaiPrice.end())
					{
						wchar_t szBuffer[128] = { 0 };
						wsprintfW(szBuffer, L"%s 未找到多多买菜报价", strDianPu.c_str());
						THROW_ERROR(szBuffer);
					}
					sDuoDuoMaiCaiChuKuInfo data;
					SHEET_CELL_STRING(sheet, r, nHuoPinMingCheng, data.strHuoPinMingCheng);
					SHEET_CELL_STRING(sheet, r, nKeFuBeiZhu, data.strKeFuBeiZhu);
					SHEET_CELL_INT(sheet, r, nHuoPinShuLiang, data.nShuLiang);
					SHEET_CELL_DOUBLE(sheet, r, nZhongLiang, data.dZhongLiang);
					SHEET_CELL_DOUBLE(sheet, r, nTiJi, data.dTiJi);
					wstring dybz;
					SHEET_CELL_STRING(sheet, r, nDaYinBeiZhu, dybz);
					vec_wvals out;
					CFuncCommon::parse_pairs(dybz, out, L";");
					for(int i=0; i<out.size(); ++i)
					{
						int nPos = out[i].find(L"箱");
						if(out[i] == L"补单")
							data.isBuDan = true;
						else if(nPos != wstring::npos)
						{
							wstring cnt = out[i].substr(0, nPos);
							data.nBoxCnt = _wtoi(cnt.c_str());
						}
					}
					m_mapDuoDuoMaiCaiChuKu[strDianPu][strJieDanShiJian].push_back(data);
				}
			}
			wchar_t szBuffer[128] = { 0 };
			wsprintfW(szBuffer, L"读取 %s 成功", strFileName.c_str());
			AddLog(szBuffer);
		}
		else
		{
			wchar_t szBuffer[128] = { 0 };
			wsprintfW(szBuffer, L"%s 加载失败", strFileName.c_str());
			THROW_ERROR(szBuffer);
		}
	}
	{
		BasicExcel excel;
		std::wstring strFileName = DUODUOMAICAI_IN_STORAGE_PATH;
		std::string fileName = CFuncCommon::WString2String(strFileName.c_str());
		if(!excel.Load(fileName.c_str()))
		{
			wchar_t szBuffer[128] = { 0 };
			wsprintfW(szBuffer, L"%s 加载失败", strFileName.c_str());
			THROW_ERROR(szBuffer);
		}
		BasicExcelWorksheet* sheet = excel.GetWorksheet(L"Sheet1");
		if(sheet)
		{
			size_t maxRows = sheet->GetTotalRows();
			size_t maxCols = sheet->GetTotalCols();

			int nHuoZhu = -1;
			int nPinPai = -1;
			int nHuoPinMingCheng = -1;
			int nHuoPinShuLiang = -1;
			int nZhongLiang = -1;
			int nTiJi = -1;
			int nShenHeShiJian = -1;
			int nBeiZhu = -1;
			for(size_t c = 0; c < maxCols; ++c)
			{
				BasicExcelCell* cell = sheet->Cell(0, c);
				std::wstring strTitle = cell->GetWString();
				if(strTitle == L"货主")
					nHuoZhu = c;
				else if(strTitle == L"品牌")
					nPinPai = c;
				else if(strTitle == L"货品名称")
					nHuoPinMingCheng = c;
				else if(strTitle == L"数量")
					nHuoPinShuLiang = c;
				else if(strTitle == L"重量")
					nZhongLiang = c;
				else if(strTitle == L"体积")
					nTiJi = c;
				else if(strTitle == L"审核时间")
					nShenHeShiJian = c;
				else if(strTitle == L"备注")
					nBeiZhu = c;
			}
			if(nHuoZhu == -1 || nPinPai == -1 || nHuoPinMingCheng == -1 || nHuoPinShuLiang == -1 || nZhongLiang == -1 || nTiJi == -1 || nShenHeShiJian == -1)
			{
				wchar_t szBuffer[128] = { 0 };
				wsprintfW(szBuffer, L"%s 有标题未找到", strFileName.c_str());
				THROW_ERROR(szBuffer);
			}
			for(size_t r = 1; r < maxRows; ++r)
			{
				std::wstring strHuoZhu;
				std::wstring strPinPai;
				const wchar_t* _pStr = NULL;
				SHEET_CELL_STRING(sheet, r, nHuoZhu, strHuoZhu);
				SHEET_CELL_STRING(sheet, r, nPinPai, strPinPai);
				if(strHuoZhu == L"多多买菜")
				{
					sDuoDuoMaiCaiRuKuInfo data;
					SHEET_CELL_STRING(sheet, r, nHuoPinMingCheng, data.strHuoPinMingCheng);
					SHEET_CELL_INT(sheet, r, nHuoPinShuLiang, data.nShuLiang);
					SHEET_CELL_DOUBLE(sheet, r, nZhongLiang, data.dZhongLiang);
					SHEET_CELL_DOUBLE(sheet, r, nTiJi, data.dTiJi);
					SHEET_CELL_STRING(sheet, r, nShenHeShiJian, data.strShenHeShiJian);
					wstring bz;
					SHEET_CELL_STRING(sheet, r, nBeiZhu, bz);
					if(bz == L"退货")
						m_mapDuoDuoMaiCaiTuiHuo[strPinPai][data.strShenHeShiJian].push_back(data);
					else
						m_mapDuoDuoMaiCaiRuKu[strPinPai].push_back(data);
					m_mapDuoDuoMaiCaiShangPinXinXi[strPinPai][data.strHuoPinMingCheng].tj = data.dTiJi;
					m_mapDuoDuoMaiCaiShangPinXinXi[strPinPai][data.strHuoPinMingCheng].zl = data.dZhongLiang;
				}
			}
			wchar_t szBuffer[128] = { 0 };
			wsprintfW(szBuffer, L"读取 %s 成功", strFileName.c_str());
			AddLog(szBuffer);
		}
		else
		{
			wchar_t szBuffer[128] = { 0 };
			wsprintfW(szBuffer, L"%s 加载失败", strFileName.c_str());
			THROW_ERROR(szBuffer);
		}
	}
	{
		BasicExcel excel;
		std::wstring strFileName = DUODUOMAICAI_DIAOBO_PATH;
		std::string fileName = CFuncCommon::WString2String(strFileName.c_str());
		if(!excel.Load(fileName.c_str()))
		{
			wchar_t szBuffer[128] = { 0 };
			wsprintfW(szBuffer, L"%s 加载失败", strFileName.c_str());
			THROW_ERROR(szBuffer);
		}
		BasicExcelWorksheet* sheet = excel.GetWorksheet(L"Sheet1");
		if(sheet)
		{
			size_t maxRows = sheet->GetTotalRows();
			size_t maxCols = sheet->GetTotalCols();

			int nHuoZhu = -1;
			int nPinPai = -1;
			int nHuoPinMingCheng = -1;
			int nHuoPinShuLiang = -1;
			int nChuKuShiJian = -1;
			for(size_t c = 0; c < maxCols; ++c)
			{
				BasicExcelCell* cell = sheet->Cell(0, c);
				std::wstring strTitle = cell->GetWString();
				if(strTitle == L"货主")
					nHuoZhu = c;
				else if(strTitle == L"品牌")
					nPinPai = c;
				else if(strTitle == L"货品名称")
					nHuoPinMingCheng = c;
				else if(strTitle == L"数量")
					nHuoPinShuLiang = c;
				else if(strTitle == L"出库时间")
					nChuKuShiJian = c;
			}
			if(nHuoZhu == -1 || nPinPai == -1 || nHuoPinMingCheng == -1 || nHuoPinShuLiang == -1 || nChuKuShiJian == -1)
			{
				wchar_t szBuffer[128] = { 0 };
				wsprintfW(szBuffer, L"%s 有标题未找到", strFileName.c_str());
				THROW_ERROR(szBuffer);
			}
			for(size_t r = 1; r < maxRows; ++r)
			{
				std::wstring strHuoZhu;
				std::wstring strPinPai;
				const wchar_t* _pStr = NULL;
				SHEET_CELL_STRING(sheet, r, nHuoZhu, strHuoZhu);
				SHEET_CELL_STRING(sheet, r, nPinPai, strPinPai);
				if(strHuoZhu == L"多多买菜")
				{
					sDuoDuoMaiCaiDiaoBoInfo data;
					SHEET_CELL_STRING(sheet, r, nHuoPinMingCheng, data.strHuoPinMingCheng);
					SHEET_CELL_INT(sheet, r, nHuoPinShuLiang, data.nShuLiang);
					SHEET_CELL_STRING(sheet, r, nChuKuShiJian, data.strChuKuShiJian);
					m_mapDuoDuoMaiCaiDiaoBo[strPinPai].push_back(data);
				}
			}
			wchar_t szBuffer[128] = { 0 };
			wsprintfW(szBuffer, L"读取 %s 成功", strFileName.c_str());
			AddLog(szBuffer);
		}
		else
		{
			wchar_t szBuffer[128] = { 0 };
			wsprintfW(szBuffer, L"%s 加载失败", strFileName.c_str());
			THROW_ERROR(szBuffer);
		}
		
	}
	return true;
}

bool CStorageBillDlg::ParseALLData()
{
	std::wstring strTotalFileName = TOTAL_FILE_PATH;
	std::wstring strDetailFileName = DETAIL_FILE_PATH;
	std::wstring strInStorageFileName = IN_STORAGE_PATH;
	std::wstring strKuaiYunWeightFileName = KUAI_YUN_WEIGHT_FILE_PATH;
	BasicExcel inStorageExcel;
	BasicExcel kuaiYunWeightExcel;
	BasicExcel baoJiaExcel;
	if(!m_bZYKYMore && !m_bCheckYDKD)
	{
		std::string strBaoJiaFileName = "./系统数据/保价统计.xls";
		if(!baoJiaExcel.Load(strBaoJiaFileName.c_str()))
		{
			THROW_ERROR(L"保价统计 加载失败");
		}
		BasicExcelWorksheet* baoJiaSheet = baoJiaExcel.GetWorksheet(L"Sheet1");
		if(baoJiaSheet)
		{
			size_t maxRows = baoJiaSheet->GetTotalRows();
			size_t maxCols = baoJiaSheet->GetTotalCols();
			int nHuoPinMingCheng = -1;
			int nJinE = -1;
			for(size_t c = 0; c < maxCols; ++c)
			{
				BasicExcelCell* cell = baoJiaSheet->Cell(0, c);
				std::wstring strTitle = cell->GetWString();
				if(strTitle == L"货品名称")
					nHuoPinMingCheng = c;
				else if(strTitle == L"保价价格")
					nJinE = c;
			}
			if(nHuoPinMingCheng == -1 || nJinE == -1)
			{
				THROW_ERROR(L"保价统计 有标题未找到");
			}
			for(size_t r = 1; r < maxRows; ++r)
			{
				const wchar_t* _pStr = NULL;
				std::wstring strHuoPinMingCheng;
				int jinE;
				SHEET_CELL_STRING(baoJiaSheet, r, nHuoPinMingCheng, strHuoPinMingCheng);
				SHEET_CELL_INT(baoJiaSheet, r, nJinE, jinE);
				m_mapBaoJiaJinE[strHuoPinMingCheng] = jinE;
			}
			AddLog(L"读取保价统计成功");
		}
		else
		{
			THROW_ERROR(L"保价统计 加载失败");
		}
	}
	for(int i=1; i<10; ++i)
	{
		wchar_t szBuffer[128] ={0};
		wsprintfW(szBuffer, L"%s%d.xls", strTotalFileName.c_str(), i);
		if(!LoadXiaoShouChuKuDan(szBuffer, i==1))
			return false;
	}
	
	for(int i = 1; i < 10; ++i)
	{
		wchar_t szBuffer[128] = { 0 };
		wsprintfW(szBuffer, L"%s%d.xls", strDetailFileName.c_str(), i);
		if(!LoadXiaoShouChuKuMingXi(szBuffer, i == 1))
			return false;
	}
	if(!m_bZYKYMore && !m_bCheckYDKD)
	{
		std::map< std::wstring, sSalesInfo* >::iterator itTmpB = m_mapTempSalesInfo.begin();
		std::map< std::wstring, sSalesInfo* >::iterator itTmpE = m_mapTempSalesInfo.end();
		while(itTmpB != itTmpE)
		{
			if(itTmpB->second->bKunLunShan)
			{
				if(itTmpB->second->strWuLiuGongSi.find(L"快运") == std::string::npos && IsZero(itTmpB->second->strZhongLiang))
				{
					if(itTmpB->second->strHuoPinMingXi == L"昆仑山矿泉水K4-4L@1")
						itTmpB->second->strZhongLiang = L"18";
					else if(itTmpB->second->strHuoPinMingXi == L"昆仑山矿泉水K12-510ml（小包装）@1")
						itTmpB->second->strZhongLiang = L"6.90";
					else if(itTmpB->second->strHuoPinMingXi == L"昆仑山矿泉水K24-350mL（大包装）@1")
						itTmpB->second->strZhongLiang = L"9.80";
					else if(itTmpB->second->strHuoPinMingXi == L"昆仑山矿泉水K12-350mL（小包装）@1")
						itTmpB->second->strZhongLiang = L"4.98";
					else if(itTmpB->second->strHuoPinMingXi == L"昆仑山矿泉水K12-1.23L@1")
						itTmpB->second->strZhongLiang = L"16.40";
					else if(itTmpB->second->strHuoPinMingXi == L"昆仑山矿泉水K24-510mL（大包装）@1")
						itTmpB->second->strZhongLiang = L"13.80";
					else if(itTmpB->second->strHuoPinMingXi == L"昆仑山矿泉水K6—510ml@1")
						itTmpB->second->strZhongLiang = L"4.05";

				}
			}
			++itTmpB;
		}
	}
	if(!m_bZYKYMore && !m_bCheckYDKD)
	{
		std::string _strKuaiYunWeightFileName = CFuncCommon::WString2String(strKuaiYunWeightFileName.c_str());
		if(!kuaiYunWeightExcel.Load(_strKuaiYunWeightFileName.c_str()))
		{
			THROW_ERROR(L"快运出库重量 加载失败");
		}
		BasicExcelWorksheet* kuaiYunWeightSheet = kuaiYunWeightExcel.GetWorksheet(L"sheet1");
		if(kuaiYunWeightSheet)
		{
			size_t maxRows = kuaiYunWeightSheet->GetTotalRows();
			size_t maxCols = kuaiYunWeightSheet->GetTotalCols();


			int nWuLiuDanHao = -1;
			int nZhongLiang = -1;
			for(size_t c = 0; c < maxCols; ++c)
			{
				BasicExcelCell* cell = kuaiYunWeightSheet->Cell(0, c);
				std::wstring strTitle = cell->GetWString();
				if(strTitle == L"物流编号")
					nWuLiuDanHao = c;
				else if(strTitle == L"重量")
					nZhongLiang = c;
			}
			if(nWuLiuDanHao == -1 || nZhongLiang == -1)
			{
				THROW_ERROR(L"快运出库重量 有标题未找到");
			}
			for(size_t r = 1; r < maxRows; ++r)
			{
				std::wstring strWuLiuDanHao;
				double dZhongLiang;
				const wchar_t* _pStr = NULL;
				SHEET_CELL_STRING(kuaiYunWeightSheet, r, nWuLiuDanHao, strWuLiuDanHao);
				SHEET_CELL_DOUBLE(kuaiYunWeightSheet, r, nZhongLiang, dZhongLiang);
				std::map< std::wstring, sSalesInfo* >::iterator it = m_mapTempSalesInfo.find(strWuLiuDanHao);
				if(it == m_mapTempSalesInfo.end())
				{
					wchar_t szBuffer[128] = { 0 };
					wsprintfW(szBuffer, L"快运出库重量 未找到单号%s 行数=%d", strWuLiuDanHao.c_str(), r);
					AddLog(szBuffer);
					continue;
				}
				it->second->strZhongLiang = CFuncCommon::Double2WString(dZhongLiang + DOUBLE_PRECISION, 2);
			}
			AddLog(L"读取快运出库重量成功");
		}
		else
		{
			THROW_ERROR(L"快运出库重量 加载失败");
		}
	}
	m_mapTempSalesInfo.clear();
	if(!m_bYG && !m_bZYKYMore && !m_bCheckYDKD)
	{
		std::string _strInStorageFileName = CFuncCommon::WString2String(strInStorageFileName.c_str());
		if(!inStorageExcel.Load(_strInStorageFileName.c_str()))
		{
			THROW_ERROR(L"入库明细账 加载失败");
		}
		BasicExcelWorksheet* inStorageSheet = inStorageExcel.GetWorksheet(L"Sheet1");
		if(inStorageSheet)
		{
			size_t maxRows = inStorageSheet->GetTotalRows();
			size_t maxCols = inStorageSheet->GetTotalCols();

			int nHuoZhu = -1;
			int nRuKuYuanYin = -1;
			int nShangJiaBianMa = -1;
			int nHuoPingBianMa = -1;
			int nHuoPinMingCheng = -1;
			int nShuLiang = -1;
			int nPinPai = -1;
			for(size_t c = 0; c < maxCols; ++c)
			{
				BasicExcelCell* cell = inStorageSheet->Cell(0, c);
				std::wstring strTitle = cell->GetWString();
				if(strTitle == L"货主")
					nHuoZhu = c;
				else if(strTitle == L"入库原因")
					nRuKuYuanYin = c;
				else if(strTitle == L"商家编码")
					nShangJiaBianMa = c;
				else if(strTitle == L"货品编号")
					nHuoPingBianMa = c;
				else if(strTitle == L"货品名称")
					nHuoPinMingCheng = c;
				else if(strTitle == L"数量")
					nShuLiang = c;
				else if(strTitle == L"品牌")
					nPinPai = c;
			}
			if(nHuoZhu == -1 || nRuKuYuanYin == -1 || nShangJiaBianMa == -1 || nHuoPingBianMa == -1 || nHuoPinMingCheng == -1 || nShuLiang == -1 || nPinPai == -1)
			{
				THROW_ERROR(L"入库明细账 有标题未找到");
			}
			for(size_t r = 1; r < maxRows; ++r)
			{
				sInStorageInfo info;
				const wchar_t* _pStr = NULL;
				SHEET_CELL_STRING(inStorageSheet, r, nHuoZhu, info.strHuoZhu);
				std::wstring strRuKuYuanYin;
				SHEET_CELL_STRING(inStorageSheet, r, nRuKuYuanYin, strRuKuYuanYin);
				if(strRuKuYuanYin != L"其它入库" && strRuKuYuanYin != L"采购入库")
					continue;
				SHEET_CELL_STRING(inStorageSheet, r, nShangJiaBianMa, info.strShangJiaBianMa);
				SHEET_CELL_STRING(inStorageSheet, r, nHuoPingBianMa, info.strHuoPinBianMa);
				SHEET_CELL_STRING(inStorageSheet, r, nHuoPinMingCheng, info.strHuoPinMingCheng);
				SHEET_CELL_STRING(inStorageSheet, r, nPinPai, info.strPinPai);
				info.nCnt = inStorageSheet->Cell(r, nShuLiang)->GetInteger();
				std::wstring strKey = info.strShangJiaBianMa + info.strHuoPinBianMa;
				std::map< std::wstring, std::map<std::wstring, sInStorageInfo> >::iterator itHuoZhu = m_mapInStorageInfo.find(info.strHuoZhu);
				if(itHuoZhu == m_mapInStorageInfo.end())
					m_mapInStorageInfo[info.strHuoZhu][strKey] = info;
				else
				{
					std::map<std::wstring, sInStorageInfo>::iterator itInfo = itHuoZhu->second.find(strKey);
					if(itInfo == itHuoZhu->second.end())
						itHuoZhu->second[strKey] = info;
					else
						itInfo->second.nCnt += info.nCnt;
				}
			}
			AddLog(L"读取入库明细账成功");
		}
		else
		{
			THROW_ERROR(L"入库明细账 加载失败");
		}
	}
	return true;
}

bool CStorageBillDlg::CreateHuoZhuFile()
{
	if(m_bZYKYMore)
		return true;
	wstring folderPath = L"./Export_" + m_strYM;
	if(0 != _waccess(folderPath.c_str(), 0))
		_wmkdir(folderPath.c_str());
	int nHuoZhuCnt = sizeof(g_arrHuoZhuName)/sizeof(const wchar_t*);
	for(int i=0; i<nHuoZhuCnt; ++i)
	{
		wstring fileName = folderPath + L"/" + g_arrHuoZhuName[i] + L"_" + m_strYM + L"对账单.xls";
		::DeleteFileW(fileName.c_str());
	}
	wstring filePath = L"./Export_" + m_strYM + L"/" + L"compare_record.xls";
	::DeleteFileW(filePath.c_str());
	std::map< std::wstring, std::list<sSalesInfo> >::iterator itB = m_mapAllSalesInfo.begin();
	std::map< std::wstring, std::list<sSalesInfo> >::iterator itE = m_mapAllSalesInfo.end();
	while(itB != itE)
	{
		int i=0;
		for(; i<nHuoZhuCnt; ++i)
		{
			if(wcscmp(itB->first.c_str(), g_arrHuoZhuName[i]) == 0)
				break;
		}
		if(i == nHuoZhuCnt && itB->first != L"哈特能量" && itB->first != L"多多买菜")
		{
			CString szText;
			szText.Format(L"存在未处理的货主:%s 是否继续?", itB->first.c_str());
			if(MessageBox(szText, NULL, MB_YESNO) == IDNO)
				return false;
		}
		++itB;
	}


	m_recordExcel.AddWorksheet(g_arrWorksheetName[0]);
	m_recordExcel.AddWorksheet(g_arrWorksheetName[1]);
	m_recordExcel.AddWorksheet(g_arrWorksheetName[2]);
	m_recordExcel.AddWorksheet(g_arrWorksheetName[3]);
	m_recordExcel.AddWorksheet(g_arrWorksheetName[4]);
	m_recordExcel.AddWorksheet(g_arrWorksheetName[5]);
	
	BasicExcelWorksheet* recordSheet = m_recordExcel.GetWorksheet(g_arrWorksheetName[0]);
	if(recordSheet)
	{
		recordSheet->Cell(g_arrRecordRowIndex[0], 0)->SetWString(L"单号");
		recordSheet->Cell(g_arrRecordRowIndex[0], 1)->SetWString(L"顺丰重量");
		recordSheet->Cell(g_arrRecordRowIndex[0], 2)->SetWString(L"云仓重量");
		recordSheet->Cell(g_arrRecordRowIndex[0], 3)->SetWString(L"云仓计费重量");
		g_arrRecordRowIndex[0]++;
	}
	recordSheet = m_recordExcel.GetWorksheet(g_arrWorksheetName[3]);
	if(recordSheet)
	{
		recordSheet->Cell(g_arrRecordRowIndex[3], 0)->SetWString(L"货主");
		recordSheet->Cell(g_arrRecordRowIndex[3], 1)->SetWString(L"单号");
		recordSheet->Cell(g_arrRecordRowIndex[3], 2)->SetWString(L"百世重量");
		recordSheet->Cell(g_arrRecordRowIndex[3], 3)->SetWString(L"云仓重量");
		g_arrRecordRowIndex[3]++;
	}
	recordSheet = m_recordExcel.GetWorksheet(g_arrWorksheetName[4]);
	if(recordSheet)
	{
		recordSheet->Cell(g_arrRecordRowIndex[4], 0)->SetWString(L"货主");
		recordSheet->Cell(g_arrRecordRowIndex[4], 1)->SetWString(L"单号");
		recordSheet->Cell(g_arrRecordRowIndex[4], 2)->SetWString(L"中通重量");
		recordSheet->Cell(g_arrRecordRowIndex[4], 3)->SetWString(L"云仓重量");
		g_arrRecordRowIndex[4]++;
	}
	recordSheet = m_recordExcel.GetWorksheet(g_arrWorksheetName[5]);
	if(recordSheet)
	{
		recordSheet->Cell(g_arrRecordRowIndex[5], 0)->SetWString(L"货主");
		recordSheet->Cell(g_arrRecordRowIndex[5], 1)->SetWString(L"单号");
		recordSheet->Cell(g_arrRecordRowIndex[5], 2)->SetWString(L"中通费用");
		recordSheet->Cell(g_arrRecordRowIndex[5], 3)->SetWString(L"报价费用");
		g_arrRecordRowIndex[5]++;
	}
	return true;
}

bool CStorageBillDlg::CreateExcel(wchar_t* szHuoZhu, BasicExcel& excel, std::list<sSalesInfo>& listSalesInfo, std::map<std::wstring, sInStorageInfo>& mapInStorageInfo)
{
	wstring strHuoZhu = szHuoZhu;
	if(listSalesInfo.size() == 0)
		return true;
	int nRecordRowIndex = 1;
	excel.AddWorksheet(L"订单费用");
	excel.AddWorksheet(L"入库费用");
	excel.AddWorksheet(L"仓租费用");
	excel.AddWorksheet(L"其他费用");
	excel.AddWorksheet(L"合计");
	BasicExcelWorksheet* sheet = excel.GetWorksheet(L"订单费用");
	if(sheet)
	{
		sheet->Cell(0, eET_ShouJianRen)->SetWString(L"收件人");
		sheet->Cell(0, eET_Sheng)->SetWString(L"省");
		sheet->Cell(0, eET_WuLiuGongSi)->SetWString(L"物流公司");
		sheet->Cell(0, eET_WuLiuDanHao)->SetWString(L"物流单号");
		sheet->Cell(0, eET_DianPu)->SetWString(L"店铺");
		sheet->Cell(0, eET_ZhongLiang)->SetWString(L"重量");
		sheet->Cell(0, eET_FaHuoShiJian)->SetWString(L"发货时间");
		sheet->Cell(0, eET_HuoPinZongShuLiang)->SetWString(L"货品总数量");
		sheet->Cell(0, eET_HuoPinMingXi)->SetWString(L"货品明细");
		sheet->Cell(0, eET_JiFeiZhongLiang)->SetWString(L"计费重量");
		sheet->Cell(0, eET_BaoZhuang)->SetWString(L"包装");
		sheet->Cell(0, eET_WuLiuFei)->SetWString(L"物流费");
		sheet->Cell(0, eET_WuLiuChengBen)->SetWString(L"物流成本");
		sheet->Cell(0, eET_HaoCaiFei)->SetWString(L"耗材费");
		sheet->Cell(0, eET_CaoZuoFei)->SetWString(L"操作费");
		sheet->Cell(0, eET_ZengZhiFeiYong)->SetWString(L"增值费用");
		sheet->Cell(0, eET_BeiZhu)->SetWString(L"备注");
		sheet->Cell(0, eET_KeFuBeiZhu)->SetWString(L"客服备注");
		if(StrCmpW(szHuoZhu, L"昆仑山水卡") == 0 )
		{
			sheet->Cell(0, eET_KunLunShanShuiKa_510_24)->SetWString(L"510*24");
			sheet->Cell(0, eET_KunLunShanShuiKa_4_4)->SetWString(L"4*4");
			sheet->Cell(0, eET_KunLunShanShuiKa_510_12)->SetWString(L"510*12");
			sheet->Cell(0, eET_KunLunShanShuiKa_123_12)->SetWString(L"1.23*12");
			sheet->Cell(0, eET_KunLunShanShuiKa_350_24)->SetWString(L"350*24");
			sheet->Cell(0, eET_KunLunShanShuiKa_350_12)->SetWString(L"350*12");
		}

		std::list<sSalesInfo>::iterator itB = listSalesInfo.begin();
		std::list<sSalesInfo>::iterator itE = listSalesInfo.end();
		while(itB != itE)
		{
			itB->nRow = nRecordRowIndex;
			sheet->Cell(nRecordRowIndex, eET_ShouJianRen)->SetWString(itB->strShouJianRen.c_str());
			sheet->Cell(nRecordRowIndex, eET_Sheng)->SetWString(itB->strSheng.c_str());
			sheet->Cell(nRecordRowIndex, eET_WuLiuGongSi)->SetWString(itB->strWuLiuGongSi.c_str());
			sheet->Cell(nRecordRowIndex, eET_WuLiuDanHao)->SetWString(itB->strWuLiuDanHao.c_str());
			sheet->Cell(nRecordRowIndex, eET_DianPu)->SetWString(itB->strDianPu.c_str());
			if(strHuoZhu == L"静心阁" && IsZero(itB->strZhongLiang))
			{
				double zl = 0;
				map_key_wstring_val_int mapRet;
				if(CFuncCommon::ParseKeyWStringInt(itB->strHuoPinMingXi, mapRet))
				{
					map_key_wstring_val_int::iterator _itB = mapRet.begin();
					map_key_wstring_val_int::iterator _itE = mapRet.end();
					while(_itB != _itE)
					{
						if(_itB->first == L"云阅读-大头儿子和小头爸爸写信和读信")
						{
							zl += (0.2*_itB->second);
						}
						else if(_itB->first == L"云阅读快乐读书吧-神笔马良七色花跟我一起玩儿愿望的实现二年级下册4本套装")
						{
							zl += ((0.5+0.03)*_itB->second);
						}
						else if(_itB->first == L"云阅读-二年级上册5本套装")
						{
							zl += ((0.6+0.03)*_itB->second);
						}
						else
						{
							wchar_t szBuffer[128] = { 0 };
							wsprintfW(szBuffer, L"静心阁找不到书本名 单号=%s %s", itB->strWuLiuDanHao.c_str(), _itB->first.c_str());
							AddLog(szBuffer);
						}
						++_itB;
					}
					if(zl > DOUBLE_PRECISION)
						zl += 0.03;
					itB->strZhongLiang = CFuncCommon::Double2WString(zl, 4);
				}
			}
			if(strHuoZhu == L"星星少女零食" && IsZero(itB->strZhongLiang))
			{
				double zl = 0;
				map_key_wstring_val_int mapRet;
				if(CFuncCommon::ParseKeyWStringInt(itB->strHuoPinMingXi, mapRet))
				{
					map_key_wstring_val_int::iterator _itB = mapRet.begin();
					map_key_wstring_val_int::iterator _itE = mapRet.end();
					while(_itB != _itE)
					{
						if(_itB->first == L"1KG新西兰酸奶味沙琪玛")
						{
							zl += (1.2240*_itB->second);
						}
						else if(_itB->first == L"500g蛋黄瓦格饼牛奶味")
						{
							zl += (0.6385*_itB->second);
						}
						else if(_itB->first == L"1KG新西兰牛奶味沙琪玛")
						{
							zl += (1.2240*_itB->second);
						}
						else if(_itB->first == L"500g蛋黄瓦格饼芝麻味")
						{
							zl += (0.6385*_itB->second);
						}
						else
						{
							wchar_t szBuffer[128] = { 0 };
							wsprintfW(szBuffer, L"星星少女零食找不到产品名 单号=%s %s", itB->strWuLiuDanHao.c_str(), _itB->first.c_str());
							AddLog(szBuffer);
						}
						++_itB;
					}
					itB->strZhongLiang = CFuncCommon::Double2WString(zl, 4);
				}
			}
			if(strHuoZhu == L"阔伟电商" && IsZero(itB->strZhongLiang))
			{
				double zl = 0;
				map_key_wstring_val_int mapRet;
				if(CFuncCommon::ParseKeyWStringInt(itB->strHuoPinMingXi, mapRet))
				{
					map_key_wstring_val_int::iterator _itB = mapRet.begin();
					map_key_wstring_val_int::iterator _itE = mapRet.end();
					while(_itB != _itE)
					{
						if(_itB->first == L"宜五曲酒（白）纯粮食酿造500ml单瓶")
						{
							zl += (1.05*_itB->second);
						}
						else if(_itB->first == L"宜五曲酒（红）纯粮食酿造500ml单瓶")
						{
							zl += (1.05*_itB->second);
						}
						else
						{
							wchar_t szBuffer[128] = { 0 };
							wsprintfW(szBuffer, L"阔伟电商找不到产品名 单号=%s %s", itB->strWuLiuDanHao.c_str(), _itB->first.c_str());
							AddLog(szBuffer);
						}
						++_itB;
					}
					itB->strZhongLiang = CFuncCommon::Double2WString(zl, 4);
				}
			}
			sheet->Cell(nRecordRowIndex, eET_ZhongLiang)->SetWString(itB->strZhongLiang.c_str());
			sheet->Cell(nRecordRowIndex, eET_FaHuoShiJian)->SetWString(itB->strFaHuoShijian.c_str());
			sheet->Cell(nRecordRowIndex, eET_HuoPinZongShuLiang)->SetWString(itB->strHuoPinZongShuLiang.c_str());
			sheet->Cell(nRecordRowIndex, eET_HuoPinMingXi)->SetWString(itB->strHuoPinMingXi.c_str());
			map_key_wstring_val_int mapRet;
			bool b18l = true;
			if(CFuncCommon::ParseKeyWStringInt(itB->strHuoPinMingXi, mapRet))
			{
				map_key_wstring_val_int::iterator _itB = mapRet.begin();
				map_key_wstring_val_int::iterator _itE = mapRet.end();
				while(_itB != _itE)
				{
					if(_itB->first != L"生抽酱油1.8L" && _itB->first != L"高粱香醋1.8L")
						b18l = false;
					++_itB;
				}
			}
			if(b18l)
			{
				int nZSL = _wtoi(itB->strHuoPinZongShuLiang.c_str());
				if(nZSL == 1)
					sheet->Cell(nRecordRowIndex, eET_BaoZhuang)->SetWString(L"单支装纸箱");
				else
					sheet->Cell(nRecordRowIndex, eET_BaoZhuang)->SetWString(L"两支装纸箱");
			}
			else
				sheet->Cell(nRecordRowIndex, eET_BaoZhuang)->SetWString(itB->strBaoZhuang.c_str());
			sheet->Cell(nRecordRowIndex, eET_KeFuBeiZhu)->SetWString(itB->strKeFuBeiZhu.c_str());
			//待计算
			sheet->Cell(nRecordRowIndex, eET_JiFeiZhongLiang)->SetWString(L"0");
			sheet->Cell(nRecordRowIndex, eET_WuLiuFei)->SetWString(L"0");
			if(IsShunFengKuaiDi(itB->strWuLiuGongSi))
			{
				if(m_bSF)
				{
					std::map<std::wstring, sSFAuthData>::iterator it = m_mapSFAuthData.find(itB->strWuLiuDanHao);
					if(it != m_mapSFAuthData.end())
						sheet->Cell(nRecordRowIndex, eET_WuLiuChengBen)->SetWString(it->second.needPay.c_str());
					else
					{
						sheet->Cell(nRecordRowIndex, eET_WuLiuChengBen)->SetWString(L"0");
						wchar_t szBuffer[128] = { 0 };
						wsprintfW(szBuffer, L"未找到顺丰成本 单号=%s 货主=%s", itB->strWuLiuDanHao.c_str(), itB->strHuoZhu.c_str());
						AddLog(szBuffer);
					}
				}
			}
			else if(IsBaiShiKuaiDi(itB->strWuLiuGongSi))
			{
				if(m_bBSKD)
				{
					std::map<std::wstring, sBSKDAuthData>::iterator it = m_mapBSKDAuthData.find(itB->strWuLiuDanHao);
					if(it != m_mapBSKDAuthData.end())
						sheet->Cell(nRecordRowIndex, eET_WuLiuChengBen)->SetWString(CFuncCommon::Double2WString(it->second.needPay + DOUBLE_PRECISION, 1).c_str());
					else
					{
						if(itB->strWuLiuDanHao.at(0) == L'5' &&
							itB->strWuLiuDanHao.at(1) == L'5' &&
							itB->strWuLiuDanHao.at(2) == L'0' &&
							itB->strWuLiuDanHao.at(3) == L'0' &&
							itB->strWuLiuDanHao.at(4) == L'0'
							)
						{
						}
						else
						{
							sheet->Cell(nRecordRowIndex, eET_WuLiuChengBen)->SetWString(L"0");
							wchar_t szBuffer[128] = { 0 };
							wsprintfW(szBuffer, L"未找到百世快递成本 单号=%s 货主=%s", itB->strWuLiuDanHao.c_str(), itB->strHuoZhu.c_str());
							AddLog(szBuffer);
						}
					}
				}
			}
			else if(IsZhongTongKuaiYun(itB->strWuLiuGongSi))
			{
				if(m_bZYKY)
				{
					std::map<std::wstring, sZTKYAuthData>::iterator it = m_mapZTKYAuthData.find(itB->strWuLiuDanHao);
					if(it != m_mapZTKYAuthData.end())
						sheet->Cell(nRecordRowIndex, eET_WuLiuChengBen)->SetWString(CFuncCommon::Double2WString(it->second.yingShou + DOUBLE_PRECISION, 1).c_str());
					else
					{
						sheet->Cell(nRecordRowIndex, eET_WuLiuChengBen)->SetWString(L"0");
						wchar_t szBuffer[128] = { 0 };
						wsprintfW(szBuffer, L"未找到中通快运成本 单号=%s 货主=%s", itB->strWuLiuDanHao.c_str(), itB->strHuoZhu.c_str());
						AddLog(szBuffer);
					}
				}
			}
			else
				sheet->Cell(nRecordRowIndex, eET_WuLiuChengBen)->SetWString(L"0");
			sheet->Cell(nRecordRowIndex, eET_HaoCaiFei)->SetWString(L"0");
			sheet->Cell(nRecordRowIndex, eET_CaoZuoFei)->SetWString(L"0");
			sheet->Cell(nRecordRowIndex, eET_ZengZhiFeiYong)->SetWString(L"0");
			nRecordRowIndex++;
			itB++;
		}
	}
	nRecordRowIndex = 1;
	sheet = excel.GetWorksheet(L"入库费用");
	if(sheet)
	{
		sheet->Cell(0, 0)->SetWString(L"商家编码");
		sheet->Cell(0, 1)->SetWString(L"货品编号");
		sheet->Cell(0, 2)->SetWString(L"货品名称");
		sheet->Cell(0, 3)->SetWString(L"入库数量");
		sheet->Cell(0, 4)->SetWString(L"入库费用");

		std::map<std::wstring, sInStorageInfo>::iterator itB = mapInStorageInfo.begin();
		std::map<std::wstring, sInStorageInfo>::iterator itE = mapInStorageInfo.end();
		while(itB != itE)
		{
			itB->second.nRow = nRecordRowIndex;
			sheet->Cell(nRecordRowIndex, 0)->SetWString(itB->second.strShangJiaBianMa.c_str());
			sheet->Cell(nRecordRowIndex, 1)->SetWString(itB->second.strHuoPinBianMa.c_str());
			sheet->Cell(nRecordRowIndex, 2)->SetWString(itB->second.strHuoPinMingCheng.c_str());
			sheet->Cell(nRecordRowIndex, 3)->SetInteger(itB->second.nCnt);
			//待计算
			sheet->Cell(nRecordRowIndex, 4)->SetWString(L"0");
			nRecordRowIndex++;
			itB++;
		}
	}
	sheet = excel.GetWorksheet(L"仓租费用");
	if(sheet)
	{
		sheet->Cell(0, 0)->SetWString(L"租用面积(平方)");
		sheet->Cell(0, 1)->SetWString(L"起租时间");
		sheet->Cell(0, 2)->SetWString(L"结算时间");
		sheet->Cell(0, 3)->SetWString(L"费用(元)");
	}
	sheet = excel.GetWorksheet(L"其他费用");
	if(sheet)
	{
		sheet->Cell(0, 0)->SetWString(L"日期");
		sheet->Cell(0, 1)->SetWString(L"费用出处");
		sheet->Cell(0, 2)->SetWString(L"金额");
	}
	sheet = excel.GetWorksheet(L"合计");
	if(sheet)
	{
		if(strHuoZhu == L"七一酱园" || strHuoZhu == L"新马帮" || strHuoZhu == L"颐麦科技")
			sheet->Cell(0, 0)->SetWString(L"=(SUM(订单费用!L:L,订单费用!M:M,订单费用!N:N,订单费用!O:O,入库费用!E:E,仓租费用!D:D,其他费用!C:C))*1.06");
		else if(strHuoZhu == L"永创昆仑山")
			sheet->Cell(0, 0)->SetWString(L"=(SUM(订单费用!L:L,订单费用!M:M,订单费用!N:N,订单费用!O:O,入库费用!E:E,仓租费用!D:D,其他费用!C:C)+3600)*1.06");
		else
			sheet->Cell(0, 0)->SetWString(L"=SUM(订单费用!L:L,订单费用!M:M,订单费用!N:N,订单费用!O:O,入库费用!E:E,仓租费用!D:D,其他费用!C:C)");
	}
	return true;
}

bool CStorageBillDlg::Handle_TaiFuShangMao()
{

	BasicExcel excel;
	if(!CreateExcel(L"泰福商贸", excel, m_mapAllSalesInfo[L"泰福商贸"], m_mapInStorageInfo[L"泰福商贸"]))
		return false;
	wstring fileName = L"./Export_" + m_strYM + L"/" + L"泰福商贸_" + m_strYM + L"对账单.xls";
	string _file = CFuncCommon::WString2String(fileName.c_str());
	CompareWhithWuLiu(L"泰福商贸", m_mapAllSalesInfo[L"泰福商贸"]);
	//计算相关费用
	{
		BasicExcelWorksheet* sheet = excel.GetWorksheet(L"订单费用");
		if(sheet)
		{
			std::list<sSalesInfo>& listSales = m_mapAllSalesInfo[L"泰福商贸"];
			std::list<sSalesInfo>::iterator itB = listSales.begin();
			std::list<sSalesInfo>::iterator itE = listSales.end();
			while(itB != itE)
			{
				wstring strBeiZhu = L"";
				int nWeight = 0;
				if(!IsZhengShu(itB->strZhongLiang))
				{
					double nZhongLiang = _wtof(itB->strZhongLiang.c_str());
					nZhongLiang += 1;
					nZhongLiang += DOUBLE_PRECISION;
					nWeight = int(nZhongLiang);
					if(nWeight < 3)
						nWeight = 3;
					wchar_t szWeight[10] = { 0 };
					_itow_s(nWeight, szWeight, 10);
					sheet->Cell(itB->nRow, eET_JiFeiZhongLiang)->SetWString(szWeight);
				}
				else
				{
					if(IsZero(itB->strZhongLiang))
						nWeight = 0;
					else
					{
						nWeight = _wtoi(itB->strZhongLiang.c_str());
						if(nWeight < 3)
							nWeight = 3;
					}

					wchar_t szWeight[10] = { 0 };
					_itow_s(nWeight, szWeight, 10);
					sheet->Cell(itB->nRow, eET_JiFeiZhongLiang)->SetWString(szWeight);
				}
				double dZengZhi = 0;
				//计算物流费
				{
					if(IsBaiShiKuaiDi(itB->strWuLiuGongSi) || IsZhongTongKuaiYun(itB->strWuLiuGongSi) || IsYunDaKuaiDi(itB->strWuLiuGongSi) || IsZhongTongKuaiYun(itB->strWuLiuGongSi))
					{
						double money = 0;
						if(nWeight > 0)
						{
							double money = GetKDPrice(nWeight, itB->strSheng, itB->strShi, g_taiFuShangMaoBSPrice, L"百世快递", itB->strWuLiuDanHao);
							sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1).c_str());
						}
					}
					else
					{
						wchar_t szOut[120] = { 0 };
						_swprintf(szOut, L"[未知的物流方式] 货主=%s 单号=%s 物流公司=%s", itB->strHuoZhu.c_str(), itB->strWuLiuDanHao.c_str(), itB->strWuLiuGongSi.c_str());
						AddLog(szOut);
					}
				}
				//打包费用
				{
					double _price = 0.8;
					sheet->Cell(itB->nRow, eET_CaoZuoFei)->SetWString(CFuncCommon::Double2WString(_price + DOUBLE_PRECISION, 1).c_str());
				}
				++itB;
			}
		}

	}

	excel.SaveAs(_file.c_str());
	AddLog(L"泰福商贸账单生成成功");
	return true;
}

bool CStorageBillDlg::CompareWhithWuLiu(std::wstring strHuoZhu, std::list<sSalesInfo>& listInfo, bool bWait)
{
	BasicExcelWorksheet* recordSheet0 = m_recordExcel.GetWorksheet(g_arrWorksheetName[0]);
	if(recordSheet0 == NULL)
		return false;
	BasicExcelWorksheet* sfSheet = NULL;
	BasicExcelWorksheet* recordSheet3 = NULL;
	BasicExcelWorksheet* bsSheet = NULL;
	BasicExcelWorksheet* recordSheet4 = NULL;
	BasicExcelWorksheet* ztSheet = NULL;
	if(m_bSF)
	{
	
		sfSheet = m_sfExcel.GetWorksheet(L"Sheet0");
		if(sfSheet == NULL)
		{
			THROW_ERROR(L"顺丰账单找不到 Sheet0 子表");
		}
		
	}
	if(m_bBSKD)
	{
		recordSheet3 = m_recordExcel.GetWorksheet(g_arrWorksheetName[3]);
		if(recordSheet3 == NULL)
			return false;
		bsSheet = m_bskdExcel.GetWorksheet(L"Sheet1");
		if(bsSheet == NULL)
		{
			THROW_ERROR(L"百世快递账单找不到 Sheet1 子表");
		}
	}
	if(m_bZYKY)
	{
		recordSheet4 = m_recordExcel.GetWorksheet(g_arrWorksheetName[4]);
		if(recordSheet4 == NULL)
			return false;
		ztSheet = m_ztkyExcel.GetWorksheet(L"Sheet1");
		if(ztSheet == NULL)
		{
			THROW_ERROR(L"中通快运账单找不到 Sheet1 子表");
		}
	}
	std::list<sSalesInfo>::iterator itYCBegin = listInfo.begin();
	std::list<sSalesInfo>::iterator itYCEnd = listInfo.end();
	while(itYCBegin != itYCEnd)
	{
		if(m_bSF && IsShunFengKuaiDi(itYCBegin->strWuLiuGongSi))
		{
			std::map<std::wstring, sSFAuthData>::iterator itSF = m_mapSFAuthData.find(itYCBegin->strWuLiuDanHao);
			if(itSF != m_mapSFAuthData.end())
			{
				//if(!itSF->second.bHandle)
				{
					wistringstream iss1(itSF->second.weight.c_str());
					wistringstream iss2(itYCBegin->strZhongLiang.c_str());
					double dSFWeight;
					double dYCWeight;
					double finalWeight;
					iss1 >> dSFWeight;
					iss2 >> dYCWeight;
					int nWeight = (int)floor(dYCWeight);
					double dOffset = dYCWeight - nWeight;
					if(dOffset >= 0.5)
						finalWeight = nWeight + 1;
					else if(dOffset > 0.0)
						finalWeight = nWeight + 0.5;
					else
						finalWeight = dYCWeight;
					if(finalWeight > DOUBLE_PRECISION && finalWeight < 1)
						finalWeight = 1;
					else if(finalWeight - 0.0 < DOUBLE_PRECISION)
					{
						finalWeight = dSFWeight;
						itYCBegin->strZhongLiang = CFuncCommon::Double2WString(finalWeight + DOUBLE_PRECISION, 2);
					}
					if(finalWeight < dSFWeight)
					{
						if(dSFWeight - finalWeight < 3)
						{
							itYCBegin->strZhongLiang = CFuncCommon::Double2WString(dSFWeight + DOUBLE_PRECISION, 2);
							sfSheet->Cell(itSF->second.row, m_sfHandleCol)->SetWString(L"1");
						}
						else
						{
							recordSheet0->Cell(g_arrRecordRowIndex[0], 0)->SetWString(itSF->first.c_str());
							recordSheet0->Cell(g_arrRecordRowIndex[0], 1)->SetDouble(dSFWeight);
							recordSheet0->Cell(g_arrRecordRowIndex[0], 2)->SetWString(itYCBegin->strZhongLiang.c_str());
							recordSheet0->Cell(g_arrRecordRowIndex[0], 3)->SetDouble(finalWeight);
							g_arrRecordRowIndex[0]++;
							sfSheet->Cell(itSF->second.row, m_sfHandleCol)->SetWString(L"1");
							m_setSFZhongLiangYiChang.insert(itSF->first.c_str());
						}
					}
					else
					{
						itSF->second.bHandle = true;
						sfSheet->Cell(itSF->second.row, m_sfHandleCol)->SetWString(L"1");
					}
				}
				m_mapYCNeedSFHandle[strHuoZhu].erase(itYCBegin->strWuLiuDanHao);
			}
		}
		if(m_bBSKD && IsBaiShiKuaiDi(itYCBegin->strWuLiuGongSi))
		{
			std::map<std::wstring, sBSKDAuthData>::iterator itBS = m_mapBSKDAuthData.find(itYCBegin->strWuLiuDanHao);
			if(itBS != m_mapBSKDAuthData.end())
			{
				wistringstream iss(itYCBegin->strZhongLiang.c_str());
				double dBSWeight = itBS->second.ysWeight;
				double dYCWeight;
				iss >> dYCWeight;
				int nYCWeight = (int)ceil(dYCWeight);
				int nBSWeight = (int)ceil(dBSWeight);
				if(dBSWeight > dYCWeight && nBSWeight > nYCWeight)
				{
					if(dBSWeight - dYCWeight < 2)
					{
						itYCBegin->strZhongLiang = CFuncCommon::Double2WString(dBSWeight + DOUBLE_PRECISION, 2);
						bsSheet->Cell(itBS->second.row, m_bskdHandleCol)->SetWString(L"1");
					}
					else
					{
						recordSheet3->Cell(g_arrRecordRowIndex[3], 0)->SetWString(strHuoZhu.c_str());
						recordSheet3->Cell(g_arrRecordRowIndex[3], 1)->SetWString(itBS->first.c_str());
						recordSheet3->Cell(g_arrRecordRowIndex[3], 2)->SetDouble(dBSWeight);
						recordSheet3->Cell(g_arrRecordRowIndex[3], 3)->SetWString(itYCBegin->strZhongLiang.c_str());
						g_arrRecordRowIndex[3]++;
						bsSheet->Cell(itBS->second.row, m_bskdHandleCol)->SetWString(L"1");
					}
				}
				else
					bsSheet->Cell(itBS->second.row, m_bskdHandleCol)->SetWString(L"1");
			}
		}
		if(m_bZYKY && IsZhongTongKuaiYun(itYCBegin->strWuLiuGongSi))
		{
			std::map<std::wstring, sZTKYAuthData>::iterator itZT = m_mapZTKYAuthData.find(itYCBegin->strWuLiuDanHao);
			if(itZT != m_mapZTKYAuthData.end())
			{
				wistringstream iss(itYCBegin->strZhongLiang.c_str());
				double dZTWeight = itZT->second.finalWeight;
				double dYCWeight;
				iss >> dYCWeight;
				if(dZTWeight > dYCWeight + DOUBLE_PRECISION)
				{
					recordSheet4->Cell(g_arrRecordRowIndex[4], 0)->SetWString(strHuoZhu.c_str());
					recordSheet4->Cell(g_arrRecordRowIndex[4], 1)->SetWString(itZT->first.c_str());
					recordSheet4->Cell(g_arrRecordRowIndex[4], 2)->SetDouble(dZTWeight);
					recordSheet4->Cell(g_arrRecordRowIndex[4], 3)->SetWString(itYCBegin->strZhongLiang.c_str());
					g_arrRecordRowIndex[4]++;
					ztSheet->Cell(itZT->second.row, m_ztkyHandleCol)->SetWString(L"重量异常");
				}
				else
					ztSheet->Cell(itZT->second.row, m_ztkyHandleCol)->SetWString(L"1");
			}
		}
		if(m_bSingleYDKD && IsYunDaKuaiDi(itYCBegin->strWuLiuGongSi))
		{
			std::map<std::wstring, sYDKDAuthData>::iterator itBS = m_mapYDKDAuthData.find(itYCBegin->strWuLiuDanHao);
			if(itBS != m_mapYDKDAuthData.end())
			{
				BasicExcelWorksheet* ydSheet = itBS->second.ydkdExcel->GetWorksheet(L"Sheet1");
				ydSheet->Cell(itBS->second.row, m_mapYDKDHandleCol[itBS->second.ydkdExcel].handleCol)->SetWString(L"1");

				wistringstream iss(itYCBegin->strZhongLiang.c_str());
				double dYCWeight;
				iss >> dYCWeight;
				if(dYCWeight > DOUBLE_PRECISION)
				{
					bool bError = false;
					if(dYCWeight <= 0.3)
					{
						if(itBS->second.ysWeight > 0.3)
							bError = true;
					}
					else if(dYCWeight <= 1)
					{
						if(itBS->second.ysWeight > 1)
							bError = true;
					}
					else if(dYCWeight <= 2.2)
					{
						if(itBS->second.ysWeight > 2.2)
							bError = true;
					}
					else if(dYCWeight <= 3.3)
					{
						if(itBS->second.ysWeight > 3.3)
							bError = true;
					}
					else if(dYCWeight <= 4)
					{
						if(itBS->second.ysWeight > 4)
							bError = true;
					}
					else if(dYCWeight <= 5.5)
					{
						if(itBS->second.ysWeight > 5.5)
							bError = true;
					}
					else
					{
						int nYC = int(dYCWeight);
						int nYD = int(itBS->second.ysWeight);
						if(nYD > nYC)
							bError = true;
					}
					if(bError)
					{
						std::wstring strWeight = CFuncCommon::Double2WString(dYCWeight + DOUBLE_PRECISION, 2);
						ydSheet->Cell(itBS->second.row, m_mapYDKDHandleCol[itBS->second.ydkdExcel].bzCol1)->SetWString(strWeight.c_str());
						double price = GetYDKDChengBen(dYCWeight, itYCBegin->strSheng, itYCBegin->strShi);
						std::wstring strPrice = CFuncCommon::Double2WString(price + DOUBLE_PRECISION, 2);
						ydSheet->Cell(itBS->second.row, m_mapYDKDHandleCol[itBS->second.ydkdExcel].bzCol2)->SetWString(strPrice.c_str());
					}
				}
			}
		}
		++itYCBegin;
	}
	if(!bWait)
	{
		BasicExcelWorksheet* recordSheet1 = m_recordExcel.GetWorksheet(g_arrWorksheetName[1]);
		std::set<std::wstring>::iterator itB = m_mapYCNeedSFHandle[strHuoZhu].begin();
		std::set<std::wstring>::iterator itE = m_mapYCNeedSFHandle[strHuoZhu].end();
		while(itB != itE)
		{
			recordSheet1->Cell(g_arrRecordRowIndex[1], 0)->SetWString(itB->c_str());
			recordSheet1->Cell(g_arrRecordRowIndex[1], 1)->SetWString(strHuoZhu.c_str());
			g_arrRecordRowIndex[1]++;
			++itB;
		}
	}
	return true;
}

double CStorageBillDlg::GetYDKDChengBen(double dWeight, wstring strSheng, wstring strShi)
{
	if(strSheng == L"内蒙古自治区")
	{
		int nZL = (int)dWeight;
		if(nZL + DOUBLE_PRECISION < dWeight)
			nZL++;
		return nZL*8 + 3;
	}
	else if(strSheng == L"海南省")
	{
		int nZL = (int)dWeight;
		if(nZL + DOUBLE_PRECISION < dWeight)
			nZL++;
		return nZL * 7 + 3;
	}
	else if(strSheng == L"新疆维吾尔自治区")
	{
		int nZL = (int)dWeight;
		if(nZL + DOUBLE_PRECISION < dWeight)
			nZL++;
		return nZL * 15 + 3;
	}
	else if(strSheng == L"西藏自治区")
	{
		int nZL = (int)dWeight;
		if(nZL + DOUBLE_PRECISION < dWeight)
			nZL++;
		return nZL * 12 + 3;
	}
	if(dWeight <= 0.3)
	{
		if(strSheng == L"四川省")
			return 1.65;
		else if(strSheng == L"重庆")
			return 1.65;
		else if(strSheng == L"北京")
			return 2.75;
		else if(strSheng == L"上海")
			return 2.45;
		else if(strShi == L"深圳市")
			return 2.45;
		else if(strSheng == L"广东省" || strSheng == L"浙江省" || strSheng == L"江苏省" || strSheng == L"安徽省" || strSheng == L"江西省" || strSheng == L"山东省" || strSheng == L"福建省" || strSheng == L"湖南省" || 
				strSheng == L"湖北省" || strSheng == L"河南省" || strSheng == L"河北省" || strSheng == L"天津" || strSheng == L"山西省" || strSheng == L"云南省" || strSheng == L"贵州省" || strSheng == L"陕西省" || strSheng == L"广西壮族自治区")
			return 1.65;
		else if(strSheng == L"辽宁省" || strSheng == L"吉林省" || strSheng == L"黑龙江省" || strSheng == L"宁夏回族自治区" || strSheng == L"甘肃省")
			return 1.65;
		else if(strSheng == L"青海省")
			return 2.3;
		else
		{
			wchar_t szBuffer[128] = { 0 };
			wsprintfW(szBuffer, L"韵达快递计算成本找不到省=%s 市=%s", strSheng.c_str(), strShi.c_str());
			AddLog(szBuffer);
		}
	}
	else if(dWeight <= 1)
	{
		if(strSheng == L"四川省")
			return 1.8;
		else if(strSheng == L"重庆")
			return 1.8;
		else if(strSheng == L"北京")
			return 2.9;
		else if(strSheng == L"上海")
			return 2.6;
		else if(strShi == L"深圳市")
			return 2.6;
		else if(strSheng == L"广东省" || strSheng == L"浙江省" || strSheng == L"江苏省" || strSheng == L"安徽省" || strSheng == L"江西省" || strSheng == L"山东省" || strSheng == L"福建省" || strSheng == L"湖南省" ||
			strSheng == L"湖北省" || strSheng == L"河南省" || strSheng == L"河北省" || strSheng == L"天津" || strSheng == L"山西省" || strSheng == L"云南省" || strSheng == L"贵州省" || strSheng == L"陕西省" || strSheng == L"广西壮族自治区")
			return 1.8;
		else if(strSheng == L"辽宁省" || strSheng == L"吉林省" || strSheng == L"黑龙江省" || strSheng == L"宁夏回族自治区" || strSheng == L"甘肃省")
			return 1.8;
		else if(strSheng == L"青海省")
			return 2.45;
		else
		{
			wchar_t szBuffer[128] = { 0 };
			wsprintfW(szBuffer, L"韵达快递计算成本找不到省=%s 市=%s", strSheng.c_str(), strShi.c_str());
			AddLog(szBuffer);
		}
	}
	else if(dWeight <= 2.2)
	{
		if(strSheng == L"四川省")
			return 2.15;
		else if(strSheng == L"重庆")
			return 2.15;
		else if(strSheng == L"北京")
			return 3.25;
		else if(strSheng == L"上海")
			return 2.95;
		else if(strShi == L"深圳市")
			return 2.95;
		else if(strSheng == L"广东省" || strSheng == L"浙江省" || strSheng == L"江苏省" || strSheng == L"安徽省" || strSheng == L"江西省" || strSheng == L"山东省" || strSheng == L"福建省" || strSheng == L"湖南省" ||
			strSheng == L"湖北省" || strSheng == L"河南省" || strSheng == L"河北省" || strSheng == L"天津" || strSheng == L"山西省" || strSheng == L"云南省" || strSheng == L"贵州省" || strSheng == L"陕西省" || strSheng == L"广西壮族自治区")
			return 2.15;
		else if(strSheng == L"辽宁省" || strSheng == L"吉林省" || strSheng == L"黑龙江省" || strSheng == L"宁夏回族自治区" || strSheng == L"甘肃省")
			return 2.15;
		else if(strSheng == L"青海省")
			return 2.8;
		else
		{
			wchar_t szBuffer[128] = { 0 };
			wsprintfW(szBuffer, L"韵达快递计算成本找不到省=%s 市=%s", strSheng.c_str(), strShi.c_str());
			AddLog(szBuffer);
		}
	}
	else if(dWeight <= 3.3)
	{
		if(strSheng == L"四川省")
			return 2.5;
		else if(strSheng == L"重庆")
			return 2.5;
		else if(strSheng == L"北京")
			return 3.6;
		else if(strSheng == L"上海")
			return 3.3;
		else if(strShi == L"深圳市")
			return 3.3;
		else if(strSheng == L"广东省" || strSheng == L"浙江省" || strSheng == L"江苏省" || strSheng == L"安徽省" || strSheng == L"江西省" || strSheng == L"山东省" || strSheng == L"福建省" || strSheng == L"湖南省" ||
			strSheng == L"湖北省" || strSheng == L"河南省" || strSheng == L"河北省" || strSheng == L"天津" || strSheng == L"山西省" || strSheng == L"云南省" || strSheng == L"贵州省" || strSheng == L"陕西省" || strSheng == L"广西壮族自治区")
			return 2.5;
		else if(strSheng == L"辽宁省" || strSheng == L"吉林省" || strSheng == L"黑龙江省" || strSheng == L"宁夏回族自治区" || strSheng == L"甘肃省")
			return 2.5;
		else if(strSheng == L"青海省")
			return 3.15;
		else
		{
			wchar_t szBuffer[128] = { 0 };
			wsprintfW(szBuffer, L"韵达快递计算成本找不到省=%s 市=%s", strSheng.c_str(), strShi.c_str());
			AddLog(szBuffer);
		}
	}
	else if(dWeight <= 4)
	{
		if(strSheng == L"四川省")
			return 3.7;
		else if(strSheng == L"重庆")
			return 3.7;
		else if(strSheng == L"北京")
			return 5.3;
		else if(strSheng == L"上海")
			return 5.6;
		else if(strShi == L"深圳市")
			return 4.5;
		else if(strSheng == L"广东省" || strSheng == L"浙江省" || strSheng == L"江苏省" || strSheng == L"安徽省" || strSheng == L"江西省" || strSheng == L"山东省" || strSheng == L"福建省" || strSheng == L"湖南省" ||
			strSheng == L"湖北省" || strSheng == L"河南省" || strSheng == L"河北省" || strSheng == L"天津" || strSheng == L"山西省" || strSheng == L"云南省" || strSheng == L"贵州省" || strSheng == L"陕西省" || strSheng == L"广西壮族自治区")
			return 3.7;
		else if(strSheng == L"辽宁省" || strSheng == L"吉林省" || strSheng == L"黑龙江省" || strSheng == L"宁夏回族自治区" || strSheng == L"甘肃省")
			return 3.7;
		else if(strSheng == L"青海省")
			return 4.35;
		else
		{
			wchar_t szBuffer[128] = { 0 };
			wsprintfW(szBuffer, L"韵达快递计算成本找不到省=%s 市=%s", strSheng.c_str(), strShi.c_str());
			AddLog(szBuffer);
		}
	}
	else if(dWeight <= 5.5)
	{
		if(strSheng == L"四川省")
			return 3.8;
		else if(strSheng == L"重庆")
			return 3.8;
		else if(strSheng == L"北京")
			return 5.6;
		else if(strSheng == L"上海")
			return 5.9;
		else if(strShi == L"深圳市")
			return 4.6;
		else if(strSheng == L"广东省" || strSheng == L"浙江省" || strSheng == L"江苏省" || strSheng == L"安徽省" || strSheng == L"江西省" || strSheng == L"山东省" || strSheng == L"福建省" || strSheng == L"湖南省" ||
			strSheng == L"湖北省" || strSheng == L"河南省" || strSheng == L"河北省" || strSheng == L"天津" || strSheng == L"山西省" || strSheng == L"云南省" || strSheng == L"贵州省" || strSheng == L"陕西省" || strSheng == L"广西壮族自治区")
			return 3.8;
		else if(strSheng == L"辽宁省" || strSheng == L"吉林省" || strSheng == L"黑龙江省" || strSheng == L"宁夏回族自治区" || strSheng == L"甘肃省")
			return 3.8;
		else if(strSheng == L"青海省")
			return 4.45;
		else
		{
			wchar_t szBuffer[128] = { 0 };
			wsprintfW(szBuffer, L"韵达快递计算成本找不到省=%s 市=%s", strSheng.c_str(), strShi.c_str());
			AddLog(szBuffer);
		}
	}
	else
	{
		int nZL = (int)dWeight;
		if(nZL + DOUBLE_PRECISION < dWeight)
			nZL++;
		if(strSheng == L"四川省")
			return nZL*0.6 + 2.6;
		else if(strSheng == L"重庆")
			return nZL*0.7 + 2.6;
		else if(strSheng == L"北京")
			return nZL*0.95 + 2.6;
		else if(strSheng == L"上海")
			return nZL*0.95 + 2.6;
		else if(strShi == L"深圳市")
			return nZL*0.95 + 2.6;
		else if(strSheng == L"广东省" || strSheng == L"浙江省" || strSheng == L"江苏省" || strSheng == L"安徽省" || strSheng == L"江西省" || strSheng == L"山东省" || strSheng == L"福建省" || strSheng == L"湖南省" ||
			strSheng == L"湖北省" || strSheng == L"河南省" || strSheng == L"河北省" || strSheng == L"天津" || strSheng == L"山西省" || strSheng == L"云南省" || strSheng == L"贵州省" || strSheng == L"陕西省" || strSheng == L"广西壮族自治区")
			return nZL*0.95 + 2.6;
		else if(strSheng == L"辽宁省" || strSheng == L"吉林省" || strSheng == L"黑龙江省" || strSheng == L"宁夏回族自治区" || strSheng == L"甘肃省")
			return nZL*2.4 + 2.6;
		else if(strSheng == L"青海省")
			return nZL*2.4 + 2.6;
		else
		{
			wchar_t szBuffer[128] = { 0 };
			wsprintfW(szBuffer, L"韵达快递计算成本找不到省=%s 市=%s", strSheng.c_str(), strShi.c_str());
			AddLog(szBuffer);
		}
	}
	return 0.0;
}

bool CStorageBillDlg::Handle_YongChuangYaoHui_KunLunShan()
{
	std::list<sSalesInfo> listKunLunShanSales;
	std::list<sSalesInfo>::iterator itSB = m_mapAllSalesInfo[L"永创耀辉"].begin();
	std::list<sSalesInfo>::iterator itSE = m_mapAllSalesInfo[L"永创耀辉"].end();
	while(itSB != itSE)
	{
		if(itSB->bKunLunShan)
		{
			listKunLunShanSales.push_back(*itSB);
			itSB = m_mapAllSalesInfo[L"永创耀辉"].erase(itSB);
			continue;
		}
		++itSB;
	}

	itSB = m_mapAllSalesInfo[L"永创昆仑山"].begin();
	itSE = m_mapAllSalesInfo[L"永创昆仑山"].end();
	while(itSB != itSE)
	{
		listKunLunShanSales.push_back(*itSB);
		++itSB;
	}


	std::map<std::wstring, sInStorageInfo> mapKunLunShanInStorage;
	std::map<std::wstring, sInStorageInfo>::iterator itIB = m_mapInStorageInfo[L"永创耀辉"].begin();
	std::map<std::wstring, sInStorageInfo>::iterator itIE = m_mapInStorageInfo[L"永创耀辉"].end();
	while(itIB != itIE)
	{
		if(itIB->second.strPinPai == L"昆仑山")
		{
			mapKunLunShanInStorage[itIB->first] = itIB->second;
			itIB = m_mapInStorageInfo[L"永创耀辉"].erase(itIB);
			continue;
		}
		++itIB;
	}
	BasicExcel excel;
	if(!CreateExcel(L"永创昆仑山", excel, listKunLunShanSales, mapKunLunShanInStorage))
		return false;
	wstring fileName = L"./Export_" + m_strYM + L"/" + L"永创昆仑山_" + m_strYM + L"对账单.xls";
	string _file = CFuncCommon::WString2String(fileName.c_str());
	CompareWhithWuLiu(L"永创耀辉", listKunLunShanSales, true);
	//计算相关费用
	
	{
		BasicExcelWorksheet* sheet = excel.GetWorksheet(L"订单费用");
		if(sheet)
		{
			std::list<sSalesInfo>::iterator itB = listKunLunShanSales.begin();
			std::list<sSalesInfo>::iterator itE = listKunLunShanSales.end();
			while(itB != itE)
			{
				wstring strBeiZhu = L"";
				int nWeight = 0;
				if(!IsZhengShu(itB->strZhongLiang))
				{
					double nZhongLiang = _wtof(itB->strZhongLiang.c_str());
					nZhongLiang += 1;
					nZhongLiang += DOUBLE_PRECISION;
					nWeight = int(nZhongLiang);
					//if(itB->strWuLiuGongSi != L"顺丰热敏(线下)" && itB->strWuLiuGongSi != L"顺丰热敏(拼多多)")
					//{
					//	if(nWeight < 3)
					//		nWeight = 3;
					//}
					wchar_t szWeight[10] = { 0 };
					_itow_s(nWeight, szWeight, 10);
					sheet->Cell(itB->nRow, eET_JiFeiZhongLiang)->SetWString(szWeight);
				}
				else
				{
					nWeight = _wtoi(itB->strZhongLiang.c_str());
					//if(itB->strWuLiuGongSi != L"顺丰热敏(线下)" && itB->strWuLiuGongSi != L"顺丰热敏(拼多多)")
					//{
					//	if(nWeight < 3)
					//			nWeight = 3;
					//}
					wchar_t szWeight[10] = { 0 };
					_itow_s(nWeight, szWeight, 10);
					sheet->Cell(itB->nRow, eET_JiFeiZhongLiang)->SetWString(szWeight);
				}
				
				double dZengZhi = 0;
				double dHaoCaiFei = 0;
				//计算物流费
				{
					if(IsShunFengKuaiDi(itB->strWuLiuGongSi))
					{
						double money = GetSFPrice(nWeight, itB->strSheng, g_yongChuangYaoHuiSFPrice, itB->strWuLiuDanHao);
						double sourceBJ = 0.0;
						std::map<std::wstring, sSFAuthData>::iterator itSF = m_mapSFAuthData.find(itB->strWuLiuDanHao);
						if(itSF != m_mapSFAuthData.end())
							sourceBJ = _wtof(itSF->second.bjPay.c_str());
						if(itB->nBaoJiaJinE != 0)
						{
							dZengZhi += (itB->nBaoJiaJinE*0.003);
							if(dZengZhi < 1)
								dZengZhi = 0.0;
							else
							{
								if(strBeiZhu == L"")
									strBeiZhu = strBeiZhu + L"保价";
								else
									strBeiZhu = strBeiZhu + L" | 保价";
							}
						}
						else if(sourceBJ > DOUBLE_PRECISION)
						{
							dZengZhi += sourceBJ;
							if(strBeiZhu == L"")
								strBeiZhu = strBeiZhu + L"保价";
							else
								strBeiZhu = strBeiZhu + L" | 保价";
						}
						if(sourceBJ > DOUBLE_PRECISION && sourceBJ > dZengZhi)
							dZengZhi = sourceBJ;
						if(itSF != m_mapSFAuthData.end())
						{
							if(itSF->second.type != L"特惠专配" && itSF->second.type != L"电商标快")
							{
								std::set<std::wstring>::iterator itType = m_setSFOtherType.find(itSF->second.type);
								if(itType != m_setSFOtherType.end())
								{
									wchar_t szOut[120] = { 0 };
									_swprintf(szOut, L"顺丰出现异常产品类型[%s]", itSF->second.type.c_str());
									AddLog(szOut);
									m_setSFOtherType.insert(itSF->second.type);
								}
								double _needPay = _wtof(itSF->second.needPay.c_str());
								double _backPay = 0.0;
								double _bjPay = 0.0;
								if(itSF->second.backPay != L"")
									_backPay = _wtof(itSF->second.backPay.c_str());
								if(itSF->second.bjPay != L"")
									_bjPay = _wtof(itSF->second.bjPay.c_str());
								money = _needPay - _backPay - _bjPay + 3;
							}
							if(itSF->second.backPay != L"")
							{
								double backPay = _wtof(itSF->second.backPay.c_str());
								money += backPay;

								if(strBeiZhu == L"")
									strBeiZhu = strBeiZhu + L"转寄退回";
								else
									strBeiZhu = strBeiZhu + L" | 转寄退回";
							}
							double needPay = _wtof(itSF->second.needPay.c_str());
							if(needPay > money + dZengZhi)
							{
								std::set<std::wstring>::iterator it = m_setSFZhongLiangYiChang.find(itB->strWuLiuDanHao.c_str());
								if(it == m_setSFZhongLiangYiChang.end())
								{
									if(!m_bSFErrorPrice)
									{
										AddLog(L"顺丰费用有异常");
										m_bSFErrorPrice = true;
									}
									BasicExcelWorksheet* recordSheet = m_recordExcel.GetWorksheet(g_arrWorksheetName[2]);
									recordSheet->Cell(g_arrRecordRowIndex[2], 0)->SetWString(itB->strWuLiuDanHao.c_str());
									recordSheet->Cell(g_arrRecordRowIndex[2], 1)->SetWString(itB->strHuoZhu.c_str());
									g_arrRecordRowIndex[2]++;
								}
							}
						}
						std::wstring strmoney = CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1);
						sheet->Cell(itB->nRow, eET_WuLiuFei)->SetDouble(_wtof(strmoney.c_str()));

					}
					else if(IsBaiShiKuaiDi(itB->strWuLiuGongSi) || IsZhongTongKuaiYun(itB->strWuLiuGongSi) || 
						IsYunDaKuaiDi(itB->strWuLiuGongSi) || IsYuanTongKuaiDi(itB->strWuLiuGongSi) || IsYunDaKuaiYun(itB->strWuLiuGongSi))
					{
						map_key_wstring_val_int mapRet;
						bool bChunShui = false;
						if(CFuncCommon::ParseKeyWStringInt(itB->strHuoPinMingXi, mapRet))
						{
							bChunShui = true;
							map_key_wstring_val_int::iterator _itB = mapRet.begin();
							map_key_wstring_val_int::iterator _itE = mapRet.end();
							while(_itB != _itE)
							{
								if(_itB->first != L"昆仑山矿泉水K4-4L" && _itB->first != L"昆仑山矿泉水K12-510ml（小包装）" &&
								   _itB->first != L"昆仑山矿泉水K24-350mL（大包装）" && _itB->first != L"昆仑山矿泉水K12-350mL（小包装）" &&
								   _itB->first != L"昆仑山矿泉水K12-1.23L" && _itB->first != L"昆仑山矿泉水K24-510mL（大包装）" &&
								   _itB->first != L"昆仑山保湿水100ml" && _itB->first != L"昆仑山保湿水300ml" && 
								   _itB->first != L"昆仑山矿泉水510mL(单瓶大包装)" && _itB->first != L"昆仑山矿泉水1.23L(单瓶)" &&
								   _itB->first != L"昆仑山矿泉水K6—510ml"
								   )
								{
									bChunShui = false;
									//break;
								}
								if(_itB->first == L"昆仑山矿泉水K6—510ml")
								{
									dHaoCaiFei += 0.9;
								}
								if(_itB->first == L"昆仑山保湿水100ml")
								{
									dHaoCaiFei += 0.6;
								}
								if(_itB->first == L"昆仑山保湿水300ml")
								{
									dHaoCaiFei += 0.9;
								}
								++_itB;
							}
							if(bChunShui)
							{
								_itB = mapRet.begin();
								double money = 0.0;
								map_key_wstring_val_int::iterator _itE = mapRet.end();
								while(_itB != _itE)
								{
									if(_itB->first == L"昆仑山矿泉水K4-4L")
									{
										money += (GetKDPrice(19, itB->strSheng, itB->strShi, g_kunLunShanYTPrice, L"圆通快递", itB->strWuLiuDanHao)*_itB->second);
									}
									else if(_itB->first == L"昆仑山矿泉水K12-510ml（小包装）")
									{
										money += (GetKDPrice(7, itB->strSheng, itB->strShi, g_kunLunShanYTPrice, L"圆通快递", itB->strWuLiuDanHao)*_itB->second);
									}
									else if(_itB->first == L"昆仑山矿泉水K24-350mL（大包装）")
									{
										money += (GetKDPrice(10, itB->strSheng, itB->strShi, g_kunLunShanYTPrice, L"圆通快递", itB->strWuLiuDanHao)*_itB->second);
									}
									else if(_itB->first == L"昆仑山矿泉水K12-350mL（小包装）")
									{
										money += (GetKDPrice(5, itB->strSheng, itB->strShi, g_kunLunShanYTPrice, L"圆通快递", itB->strWuLiuDanHao)*_itB->second);
									}
									else if(_itB->first == L"昆仑山矿泉水K12-1.23L")
									{
										money += (GetKDPrice(17, itB->strSheng, itB->strShi, g_kunLunShanYTPrice, L"圆通快递", itB->strWuLiuDanHao)*_itB->second);
									}
									else if(_itB->first == L"昆仑山矿泉水K24-510mL（大包装）")
									{
										money += (GetKDPrice(14, itB->strSheng, itB->strShi, g_kunLunShanYTPrice, L"圆通快递", itB->strWuLiuDanHao)*_itB->second);
									}
									else if(_itB->first == L"昆仑山矿泉水510mL(单瓶大包装)")
									{
										money += (GetKDPrice(1, itB->strSheng, itB->strShi, g_kunLunShanYTPrice, L"圆通快递", itB->strWuLiuDanHao)*_itB->second);
									}
									else if(_itB->first == L"昆仑山矿泉水1.23L(单瓶)")
									{
										money += (GetKDPrice(2, itB->strSheng, itB->strShi, g_kunLunShanYTPrice, L"圆通快递", itB->strWuLiuDanHao)*_itB->second);
									}
									else if(_itB->first == L"昆仑山保湿水100ml")
									{
										money += (GetKDPrice(1, itB->strSheng, itB->strShi, g_kunLunShanYTPrice, L"圆通快递", itB->strWuLiuDanHao)*_itB->second);
									}
									else if(_itB->first == L"昆仑山保湿水300ml")
									{
										money += (GetKDPrice(1, itB->strSheng, itB->strShi, g_kunLunShanYTPrice, L"圆通快递", itB->strWuLiuDanHao)*_itB->second);
									}
									else if(_itB->first == L"昆仑山矿泉水K6—510ml")
									{
										money += (GetKDPrice(5, itB->strSheng, itB->strShi, g_kunLunShanYTPrice, L"圆通快递", itB->strWuLiuDanHao)*_itB->second);
									}
									++_itB;
								}
								std::wstring strmoney = CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1);
								sheet->Cell(itB->nRow, eET_WuLiuFei)->SetDouble(_wtof(strmoney.c_str()));
							}
							else
							{
								double money = GetKDPrice(nWeight, itB->strSheng, itB->strShi, g_kunLunShanYTPrice, L"圆通快递", itB->strWuLiuDanHao);
								std::wstring strmoney = CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1);
								dHaoCaiFei += 0.9;
								sheet->Cell(itB->nRow, eET_WuLiuFei)->SetDouble(_wtof(strmoney.c_str()));
							}
						}
						if(IsZhongTongKuaiYun(itB->strWuLiuGongSi) || IsYunDaKuaiYun(itB->strWuLiuGongSi))
						{
							std::map<std::wstring, sZTKYAuthData>::iterator itZTKY = m_mapZTKYAuthData.find(itB->strWuLiuDanHao);
							bool bSL = false;
							if(itZTKY != m_mapZTKYAuthData.end())
							{
								double chengbenMoney = GetKYPrice(nWeight, itB->strSheng, itB->strShi, g_chengBenZTKYPrice, itB->strWuLiuDanHao);
								if(chengbenMoney+DOUBLE_PRECISION  < itZTKY->second.yingShou-itZTKY->second.qita)
								{
									BasicExcelWorksheet* recordSheet = m_recordExcel.GetWorksheet(g_arrWorksheetName[5]);
									recordSheet->Cell(g_arrRecordRowIndex[5], 0)->SetWString(L"永创耀辉");
									recordSheet->Cell(g_arrRecordRowIndex[5], 1)->SetWString(itB->strWuLiuDanHao.c_str());
									recordSheet->Cell(g_arrRecordRowIndex[5], 2)->SetWString(CFuncCommon::Double2WString(itZTKY->second.yingShou-itZTKY->second.qita + DOUBLE_PRECISION, 1).c_str());
									recordSheet->Cell(g_arrRecordRowIndex[5], 3)->SetWString(CFuncCommon::Double2WString(chengbenMoney + DOUBLE_PRECISION, 1).c_str());
									g_arrRecordRowIndex[5]++;

									BasicExcelWorksheet* ztSheet = m_ztkyExcel.GetWorksheet(L"Sheet1");
									if(ztSheet)
										ztSheet->Cell(itZTKY->second.row, m_ztkyHandleCol)->SetWString(L"价格异常");
								}

								if(itZTKY->second.qita > DOUBLE_PRECISION)
								{
									dZengZhi += itZTKY->second.qita;
									if(strBeiZhu == L"")
										strBeiZhu = strBeiZhu + L"上楼";
									else
										strBeiZhu = strBeiZhu + L" | 上楼";
									bSL = true;
								}
							}
							if(!bSL)
							{
								if(nWeight > 50)
								{
									if(nWeight < 120)
										dZengZhi += (nWeight - 50)*0.1 + 10;
									else
										dZengZhi += (nWeight - 50)*0.1 + 30;
									if(strBeiZhu == L"")
										strBeiZhu = strBeiZhu + L"上楼";
									else
										strBeiZhu = strBeiZhu + L" | 上楼";
								}
							}
						}
					}
					else
					{
						wchar_t szOut[120] = { 0 };
						_swprintf(szOut, L"[未知的物流方式] 货主=永创昆仑山 单号=%s 物流公司=%s", itB->strWuLiuDanHao.c_str(), itB->strWuLiuGongSi.c_str());
						AddLog(szOut);
					}
				}
				
				sheet->Cell(itB->nRow, eET_CaoZuoFei)->SetWString(CFuncCommon::Double2WString(0.9 + DOUBLE_PRECISION, 1).c_str());
				if(dHaoCaiFei)
					sheet->Cell(itB->nRow, eET_HaoCaiFei)->SetWString(CFuncCommon::Double2WString(dHaoCaiFei + DOUBLE_PRECISION, 1).c_str());

				//计算增值费用
				{
					if(dZengZhi > 0)
						sheet->Cell(itB->nRow, eET_ZengZhiFeiYong)->SetWString(CFuncCommon::Double2WString(dZengZhi + DOUBLE_PRECISION, 1).c_str());
				}
				sheet->Cell(itB->nRow, eET_BeiZhu)->SetWString(strBeiZhu.c_str());
				++itB;
			}
		}
	}
	excel.SaveAs(_file.c_str());
	AddLog(L"永创昆仑山账单生成成功");
	return true;
}

bool CStorageBillDlg::Handle_YongChuangYaoHui()
{
	if(!Handle_YongChuangYaoHui_KunLunShan())
		return false;
	BasicExcel excel;
	if(!CreateExcel(L"永创耀辉", excel, m_mapAllSalesInfo[L"永创耀辉"], m_mapInStorageInfo[L"永创耀辉"]))
		return false;
	wstring fileName = L"./Export_" + m_strYM + L"/" + L"永创耀辉_" + m_strYM + L"对账单.xls";
	string _file = CFuncCommon::WString2String(fileName.c_str());
	CompareWhithWuLiu(L"永创耀辉", m_mapAllSalesInfo[L"永创耀辉"]);
	//计算相关费用
	{
		BasicExcelWorksheet* sheet = excel.GetWorksheet(L"订单费用");
		if(sheet)
		{
			std::list<sSalesInfo>& listSales = m_mapAllSalesInfo[L"永创耀辉"];
			std::list<sSalesInfo>::iterator itB = listSales.begin();
			std::list<sSalesInfo>::iterator itE = listSales.end();
			while(itB != itE)
			{
				wstring strBeiZhu = L"";
				int nWeight = 0;
				if(!IsZhengShu(itB->strZhongLiang))
				{
					double nZhongLiang = _wtof(itB->strZhongLiang.c_str());
					nZhongLiang += 1;
					nZhongLiang += DOUBLE_PRECISION;
					nWeight = int(nZhongLiang);
					wchar_t szWeight[10] ={0};
					_itow_s(nWeight, szWeight, 10);
					sheet->Cell(itB->nRow, eET_JiFeiZhongLiang)->SetWString(szWeight);
				}
				else
				{
					if(IsZero(itB->strZhongLiang))
						nWeight = 0;
					else
						nWeight = _wtoi(itB->strZhongLiang.c_str());
					wchar_t szWeight[10] ={0};
					_itow_s(nWeight, szWeight, 10);
					sheet->Cell(itB->nRow, eET_JiFeiZhongLiang)->SetWString(szWeight);
				}
				double dZengZhi = 0;
				double dHaoCaiFei = 0;
				double dHaoCaiCnt = 0;
				//计算物流费
				{
					map_key_wstring_val_int mapRet;
					if(CFuncCommon::ParseKeyWStringInt(itB->strHuoPinMingXi, mapRet))
					{
						map_key_wstring_val_int::iterator _itB = mapRet.begin();
						map_key_wstring_val_int::iterator _itE = mapRet.end();
						while(_itB != _itE)
						{
							if(_itB->first == L"45度小郎酒（精酿）分享装100ml*6" )
							{
								dHaoCaiFei += 0.8;
							}
							else if(_itB->first == L"45度小郎酒（经典）分享装100ml*6")
							{
								dHaoCaiFei += 0.8;
							}
							else if(_itB->first == L"五粮液歪嘴酒100ml")
							{
								dHaoCaiFei += 0.8;
							}
							else if(_itB->first == L"45度小郎酒（精酿）100ml")
							{
								dHaoCaiFei += 0.8;
							}
							else if(_itB->first == L"贵州茅台酒飞天茅台53度酱香型白酒1.5L")
							{
								dHaoCaiCnt += _itB->second;
							}
							else if(_itB->first == L"五粮液1618珍酿52度3L")
							{
								dHaoCaiCnt += _itB->second;
							}
							else if(_itB->first == L"贵州茅台酒飞天茅台53度酱香型白酒3L")
							{
								dHaoCaiCnt += _itB->second;
							}
							else if(_itB->first == L"贵州茅台酒飞天茅台53度酱香型白酒6L")
							{
								dHaoCaiCnt += _itB->second;
							}
							else if(_itB->first == L"五粮液52度囍乙亥猪年纪念酒500ml*4")
							{
								dHaoCaiCnt += _itB->second;
							}
							else if(_itB->second >= 6)
							{
								dHaoCaiCnt += (_itB->second/6);
							}
							++_itB;
						}
					}
					if(IsShunFengKuaiDi(itB->strWuLiuGongSi))
					{
						dHaoCaiFei += (dHaoCaiCnt*5);
						double money = GetSFPrice(nWeight, itB->strSheng, g_yongChuangYaoHuiSFPrice, itB->strWuLiuDanHao);
						double sourceBJ = 0;
						std::map<std::wstring, sSFAuthData>::iterator itSF = m_mapSFAuthData.find(itB->strWuLiuDanHao);
						if(itSF != m_mapSFAuthData.end())
							sourceBJ = _wtof(itSF->second.bjPay.c_str());
						if(itB->nBaoJiaJinE != 0)
						{
							dZengZhi += (itB->nBaoJiaJinE*0.003);
							if(dZengZhi < 1)
								dZengZhi = 0.0;
							else
							{
								if(strBeiZhu == L"")
									strBeiZhu = strBeiZhu + L"保价";
								else
									strBeiZhu = strBeiZhu + L" | 保价";
							}
						}
						else if(sourceBJ > DOUBLE_PRECISION)
						{
							dZengZhi += sourceBJ;
							if(strBeiZhu == L"")
								strBeiZhu = strBeiZhu + L"保价";
							else
								strBeiZhu = strBeiZhu + L" | 保价";
						}
						//if(sourceBJ > DOUBLE_PRECISION && sourceBJ > dZengZhi)
						//	dZengZhi = sourceBJ;
						if(itSF != m_mapSFAuthData.end())
						{
							if(itSF->second.type != L"特惠专配" && itSF->second.type != L"电商标快")
							{
								std::set<std::wstring>::iterator itType = m_setSFOtherType.find(itSF->second.type);
								if(itType != m_setSFOtherType.end())
								{
									wchar_t szOut[120] = { 0 };
									_swprintf(szOut, L"顺丰出现异常产品类型[%s]", itSF->second.type.c_str());
									AddLog(szOut);
									m_setSFOtherType.insert(itSF->second.type);
								}
								double _needPay = _wtof(itSF->second.needPay.c_str());
								double _backPay = 0.0;
								double _bjPay = 0.0;
								double _djPay = 0.0;
								if(itSF->second.backPay != L"")
									_backPay = _wtof(itSF->second.backPay.c_str());
								if(itSF->second.bjPay != L"")
									_bjPay = _wtof(itSF->second.bjPay.c_str());
								if(itSF->second.djPay != L"")
									_djPay = _wtof(itSF->second.djPay.c_str());
								money = _needPay - _backPay - _bjPay - _djPay + 3;
							}
							if(itSF->second.backPay != L"")
							{
								double backPay = _wtof(itSF->second.backPay.c_str());
								money += backPay;

								if(strBeiZhu == L"")
									strBeiZhu = strBeiZhu + L"转寄退回";
								else
									strBeiZhu = strBeiZhu + L" | 转寄退回";
							}
							if(itSF->second.djPay != L"")
							{
								double djPay = _wtof(itSF->second.djPay.c_str());
								money += djPay;

								if(strBeiZhu == L"")
									strBeiZhu = strBeiZhu + L"大件入户";
								else
									strBeiZhu = strBeiZhu + L" | 大件入户";
							}
							double needPay = _wtof(itSF->second.needPay.c_str());
							if(needPay > money+dZengZhi)
							{
								std::set<std::wstring>::iterator it = m_setSFZhongLiangYiChang.find(itB->strWuLiuDanHao.c_str());
								if(it == m_setSFZhongLiangYiChang.end())
								{
									if(!m_bSFErrorPrice)
									{
										AddLog(L"顺丰费用有异常");
										m_bSFErrorPrice = true;
									}
									BasicExcelWorksheet* recordSheet = m_recordExcel.GetWorksheet(g_arrWorksheetName[2]);
									recordSheet->Cell(g_arrRecordRowIndex[2], 0)->SetWString(itB->strWuLiuDanHao.c_str());
									recordSheet->Cell(g_arrRecordRowIndex[2], 1)->SetWString(itB->strHuoZhu.c_str());
									g_arrRecordRowIndex[2]++;
								}
							}
						}
						
						sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money+DOUBLE_PRECISION, 1).c_str());


					}
					else if(IsBaiShiKuaiYun(itB->strWuLiuGongSi))
						sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(L"2.5");
					else if(IsZhongTongKuaiYun(itB->strWuLiuGongSi) || IsYunDaKuaiYun(itB->strWuLiuGongSi))
					{
						double money = GetKYPrice(nWeight, itB->strSheng, itB->strShi, g_yongChuangYaoHuiZTKYPrice, itB->strWuLiuDanHao);
						sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1).c_str());

						bool bSL = false;
						std::map<std::wstring, sZTKYAuthData>::iterator itZTKY = m_mapZTKYAuthData.find(itB->strWuLiuDanHao);
						if(itZTKY != m_mapZTKYAuthData.end())
						{
							double chengbenMoney = GetKYPrice(nWeight, itB->strSheng, itB->strShi, g_chengBenZTKYPrice, itB->strWuLiuDanHao);
							if(chengbenMoney+DOUBLE_PRECISION < itZTKY->second.yingShou-itZTKY->second.qita)
							{
								BasicExcelWorksheet* recordSheet = m_recordExcel.GetWorksheet(g_arrWorksheetName[5]);
								recordSheet->Cell(g_arrRecordRowIndex[5], 0)->SetWString(L"永创耀辉");
								recordSheet->Cell(g_arrRecordRowIndex[5], 1)->SetWString(itB->strWuLiuDanHao.c_str());
								recordSheet->Cell(g_arrRecordRowIndex[5], 2)->SetWString(CFuncCommon::Double2WString(itZTKY->second.yingShou-itZTKY->second.qita + DOUBLE_PRECISION, 1).c_str());
								recordSheet->Cell(g_arrRecordRowIndex[5], 3)->SetWString(CFuncCommon::Double2WString(chengbenMoney + DOUBLE_PRECISION, 1).c_str());
								g_arrRecordRowIndex[5]++;

								BasicExcelWorksheet* ztSheet = m_ztkyExcel.GetWorksheet(L"Sheet1");
								if(ztSheet)
									ztSheet->Cell(itZTKY->second.row, m_ztkyHandleCol)->SetWString(L"价格异常");
							}
							if(itZTKY->second.qita > DOUBLE_PRECISION)
							{
								dZengZhi += itZTKY->second.qita;
								if(strBeiZhu == L"")
									strBeiZhu = strBeiZhu + L"上楼";
								else
									strBeiZhu = strBeiZhu + L" | 上楼";
								bSL = true;
							}
						}
						if(!bSL)
						{
							if(nWeight > 50)
							{
								if(nWeight < 120)
									dZengZhi += (nWeight - 50)*0.1 + 10;
								else
									dZengZhi += (nWeight - 50)*0.1 + 30;
								if(strBeiZhu == L"")
									strBeiZhu = strBeiZhu + L"上楼";
								else
									strBeiZhu = strBeiZhu + L" | 上楼";
							}
						}
					}
					else if(IsBaiShiKuaiDi(itB->strWuLiuGongSi))
					{
						double money = 0;
						if(nWeight > 0)
						{
							if(nWeight > 3)
								money = 1.3 + (nWeight - 3)*0.8;
							else
								money = 1.3;
							sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1).c_str());
						}
					}
					else if(IsYunDaKuaiDi(itB->strWuLiuGongSi) || IsYuanTongKuaiDi(itB->strWuLiuGongSi))
					{
						double money = GetKDPrice(nWeight, itB->strSheng, itB->strShi, g_yongChuangYaoHuiKDPrice, L"韵达快递", itB->strWuLiuDanHao);
						sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1).c_str());
					}
					else
					{
						wchar_t szOut[120] ={0};
						_swprintf(szOut, L"[未知的物流方式] 货主=%s 单号=%s 物流公司=%s", itB->strHuoZhu.c_str(), itB->strWuLiuDanHao.c_str(), itB->strWuLiuGongSi.c_str());
						AddLog(szOut);
					}
				}
				sheet->Cell(itB->nRow, eET_CaoZuoFei)->SetWString(L"1.1");
				if(dHaoCaiFei > 0)
					sheet->Cell(itB->nRow, eET_HaoCaiFei)->SetWString(CFuncCommon::Double2WString(dHaoCaiFei + DOUBLE_PRECISION, 1).c_str());
				//计算增值费用
				{
					//云集贴标费
					if(itB->strYuanShiDanHao.size() >= 2)
					{
						wchar_t char1 = itB->strYuanShiDanHao.at(0);
						wchar_t char2 = itB->strYuanShiDanHao.at(1);
						if(char1 == L'S' && char2 == L'O')
						{
							dZengZhi += 0.3;
							if(strBeiZhu == L"")
								strBeiZhu = strBeiZhu + L"贴标";
							else
								strBeiZhu = strBeiZhu + L" | 贴标";
						}
					}
					if(dZengZhi > 0)
						sheet->Cell(itB->nRow, eET_ZengZhiFeiYong)->SetWString(CFuncCommon::Double2WString(dZengZhi+DOUBLE_PRECISION,1).c_str());
				}
				sheet->Cell(itB->nRow, eET_BeiZhu)->SetWString(strBeiZhu.c_str());
				++itB;
			}
		}

	}
	excel.SaveAs(_file.c_str());
	AddLog(L"永创耀辉账单生成成功");
	return true;
}

bool CStorageBillDlg::Handle_MiYaShiQi()
{
	BasicExcel excel;
	if(!CreateExcel(L"弥雅食器", excel, m_mapAllSalesInfo[L"弥雅食器"], m_mapInStorageInfo[L"弥雅食器"]))
		return false;
	wstring fileName = L"./Export_" + m_strYM + L"/" + L"弥雅食器_" + m_strYM + L"对账单.xls";
	string _file = CFuncCommon::WString2String(fileName.c_str());
	CompareWhithWuLiu(L"弥雅食器", m_mapAllSalesInfo[L"弥雅食器"]);
	//计算相关费用
	{
		BasicExcelWorksheet* sheet = excel.GetWorksheet(L"订单费用");
		if(sheet)
		{
			std::list<sSalesInfo>& listSales = m_mapAllSalesInfo[L"弥雅食器"];
			std::list<sSalesInfo>::iterator itB = listSales.begin();
			std::list<sSalesInfo>::iterator itE = listSales.end();
			while(itB != itE)
			{
				wstring strBeiZhu = L"";
				int nWeight = 0;
				if(!IsZhengShu(itB->strZhongLiang))
				{
					double nZhongLiang = _wtof(itB->strZhongLiang.c_str());
					nZhongLiang += 1;
					nZhongLiang += DOUBLE_PRECISION;
					nWeight = int(nZhongLiang);
					if(nWeight < 3)
						nWeight = 3;
					wchar_t szWeight[10] = { 0 };
					_itow_s(nWeight, szWeight, 10);
					sheet->Cell(itB->nRow, eET_JiFeiZhongLiang)->SetWString(szWeight);
				}
				else
				{
					if(IsZero(itB->strZhongLiang))
						nWeight = 0;
					else
					{
						nWeight = _wtoi(itB->strZhongLiang.c_str());
						if(nWeight < 3)
							nWeight = 3;
					}

					wchar_t szWeight[10] = { 0 };
					_itow_s(nWeight, szWeight, 10);
					sheet->Cell(itB->nRow, eET_JiFeiZhongLiang)->SetWString(szWeight);
				}
				double dZengZhi = 0;
				//计算物流费
				{
					if(IsShunFengKuaiDi(itB->strWuLiuGongSi))
					{
						double money = GetSFPrice(nWeight, itB->strSheng, g_miYaSFPrice, itB->strWuLiuDanHao);
						double sourceBJ = 0;
						std::map<std::wstring, sSFAuthData>::iterator itSF = m_mapSFAuthData.find(itB->strWuLiuDanHao);
						if(itSF != m_mapSFAuthData.end())
							sourceBJ = _wtof(itSF->second.bjPay.c_str());
						if(itB->nBaoJiaJinE != 0)
						{
							dZengZhi += (itB->nBaoJiaJinE*0.003);
							if(dZengZhi < 1)
								dZengZhi = 0.0;
							else
							{
								if(strBeiZhu == L"")
									strBeiZhu = strBeiZhu + L"保价";
								else
									strBeiZhu = strBeiZhu + L" | 保价";
							}
						}
						else if(sourceBJ > DOUBLE_PRECISION)
						{
							dZengZhi += sourceBJ;
							if(strBeiZhu == L"")
								strBeiZhu = strBeiZhu + L"保价";
							else
								strBeiZhu = strBeiZhu + L" | 保价";
						}

						if(itSF != m_mapSFAuthData.end())
						{
							if(itSF->second.type != L"特惠专配" && itSF->second.type != L"电商标快")
							{
								std::set<std::wstring>::iterator itType = m_setSFOtherType.find(itSF->second.type);
								if(itType != m_setSFOtherType.end())
								{
									wchar_t szOut[120] = { 0 };
									_swprintf(szOut, L"顺丰出现异常产品类型[%s]", itSF->second.type.c_str());
									AddLog(szOut);
									m_setSFOtherType.insert(itSF->second.type);
								}
								double _needPay = _wtof(itSF->second.needPay.c_str());
								double _backPay = 0.0;
								double _bjPay = 0.0;
								if(itSF->second.backPay != L"")
									_backPay = _wtof(itSF->second.backPay.c_str());
								if(itSF->second.bjPay != L"")
									_bjPay = _wtof(itSF->second.bjPay.c_str());
								money = _needPay - _backPay - _bjPay + 3;
							}
							if(itSF->second.backPay != L"")
							{
								double backPay = _wtof(itSF->second.backPay.c_str());
								money += backPay;

								if(strBeiZhu == L"")
									strBeiZhu = strBeiZhu + L"转寄退回";
								else
									strBeiZhu = strBeiZhu + L" | 转寄退回";
							}
							double needPay = _wtof(itSF->second.needPay.c_str());
							if(needPay > money + dZengZhi)
							{
								std::set<std::wstring>::iterator it = m_setSFZhongLiangYiChang.find(itB->strWuLiuDanHao.c_str());
								if(it == m_setSFZhongLiangYiChang.end())
								{
									if(!m_bSFErrorPrice)
									{
										AddLog(L"顺丰费用有异常");
										m_bSFErrorPrice = true;
									}
									BasicExcelWorksheet* recordSheet = m_recordExcel.GetWorksheet(g_arrWorksheetName[2]);
									recordSheet->Cell(g_arrRecordRowIndex[2], 0)->SetWString(itB->strWuLiuDanHao.c_str());
									recordSheet->Cell(g_arrRecordRowIndex[2], 1)->SetWString(itB->strHuoZhu.c_str());
									g_arrRecordRowIndex[2]++;
								}
							}
						}

						sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1).c_str());
					}
					else if(IsBaiShiKuaiDi(itB->strWuLiuGongSi) || IsYunDaKuaiDi(itB->strWuLiuGongSi))
					{
						double money = 0;
						if(nWeight > 0)
						{
							double money = GetKDPrice(nWeight, itB->strSheng, itB->strShi, g_miYaBSPrice, L"百世快递", itB->strWuLiuDanHao);
							sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1).c_str());
						}
					}
					else if(IsZhongTongKuaiYun(itB->strWuLiuGongSi) || IsYunDaKuaiYun(itB->strWuLiuGongSi))
					{
						double money = GetKYPrice(nWeight, itB->strSheng, itB->strShi, g_miYaZTKYPrice, itB->strWuLiuDanHao);
						sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1).c_str());
						if(IsZhongTongKuaiYun(itB->strWuLiuGongSi))
						{
							bool bSL = false;
							std::map<std::wstring, sZTKYAuthData>::iterator itZTKY = m_mapZTKYAuthData.find(itB->strWuLiuDanHao);
							if(itZTKY != m_mapZTKYAuthData.end())
							{
								double chengbenMoney = GetKYPrice(nWeight, itB->strSheng, itB->strShi, g_chengBenZTKYPrice, itB->strWuLiuDanHao);
								if(chengbenMoney + DOUBLE_PRECISION < itZTKY->second.yingShou - itZTKY->second.qita)
								{
									BasicExcelWorksheet* recordSheet = m_recordExcel.GetWorksheet(g_arrWorksheetName[5]);
									recordSheet->Cell(g_arrRecordRowIndex[5], 0)->SetWString(L"弥雅食器");
									recordSheet->Cell(g_arrRecordRowIndex[5], 1)->SetWString(itB->strWuLiuDanHao.c_str());
									recordSheet->Cell(g_arrRecordRowIndex[5], 2)->SetWString(CFuncCommon::Double2WString(itZTKY->second.yingShou - itZTKY->second.qita + DOUBLE_PRECISION, 1).c_str());
									recordSheet->Cell(g_arrRecordRowIndex[5], 3)->SetWString(CFuncCommon::Double2WString(chengbenMoney + DOUBLE_PRECISION, 1).c_str());
									g_arrRecordRowIndex[5]++;

									BasicExcelWorksheet* ztSheet = m_ztkyExcel.GetWorksheet(L"Sheet1");
									if(ztSheet)
										ztSheet->Cell(itZTKY->second.row, m_ztkyHandleCol)->SetWString(L"价格异常");
								}
								if(itZTKY->second.qita > DOUBLE_PRECISION)
								{
									dZengZhi += itZTKY->second.qita;
									if(strBeiZhu == L"")
										strBeiZhu = strBeiZhu + L"上楼";
									else
										strBeiZhu = strBeiZhu + L" | 上楼";
									bSL = true;
								}
							}
							if(!bSL)
							{
								if(nWeight > 50)
								{
									if(nWeight < 120)
										dZengZhi += (nWeight - 50)*0.1 + 10;
									else
										dZengZhi += (nWeight - 50)*0.1 + 30;
									if(strBeiZhu == L"")
										strBeiZhu = strBeiZhu + L"上楼";
									else
										strBeiZhu = strBeiZhu + L" | 上楼";
								}
							}
						}
					}
					else
					{
						wchar_t szOut[120] = { 0 };
						_swprintf(szOut, L"[未知的物流方式] 货主=%s 单号=%s 物流公司=%s", itB->strHuoZhu.c_str(), itB->strWuLiuDanHao.c_str(), itB->strWuLiuGongSi.c_str());
						AddLog(szOut);
					}
				}
				sheet->Cell(itB->nRow, eET_BeiZhu)->SetWString(strBeiZhu.c_str());
				//打包费用
				{
					double _price = 2;
					sheet->Cell(itB->nRow, eET_CaoZuoFei)->SetWString(CFuncCommon::Double2WString(_price + DOUBLE_PRECISION, 1).c_str());
				}
				++itB;
			}
		}

	}
	excel.SaveAs(_file.c_str());
	AddLog(L"弥雅食器账单生成成功");
	return true;
}

bool CStorageBillDlg::LoadBSKDData()
{
	if(m_bZYKYMore)
		return true;
	if(m_bCheckYDKD)
		return true;
	if(!m_bBSKD)
		return true;
	std::wstring strBSFileName = BSKD_FILE_PATH;
	std::string _strBSFileName = CFuncCommon::WString2String(strBSFileName.c_str());
	m_bskdExcel.Load(_strBSFileName.c_str());
	BasicExcelWorksheet* bsSheet = m_bskdExcel.GetWorksheet(L"Sheet1");
	if(bsSheet)
	{
		size_t maxRows = bsSheet->GetTotalRows();
		size_t maxCols = bsSheet->GetTotalCols();
		m_bskdHandleCol = maxCols;
		//load tile
		int colNumber = -1;
		int colWeight = -1;
		int colYsWeight = -1;
		int needPay = -1;
		bool bFix = false;
		for(size_t c = 0; c < maxCols; ++c)
		{
			BasicExcelCell* cell = bsSheet->Cell(0, c);
			const wchar_t* _titile = cell->GetWString();
			if(_titile)
			{
				std::wstring strTitle = _titile;

				if(strTitle == L"运单号")
					colNumber = c;
				else if(strTitle == L"计费重量")
					colWeight = c;
				else if(strTitle == L"费用")
					needPay = c;
				else if(strTitle == L"原始重量")
					colYsWeight = c;
				else if(strTitle == L"对账结果")
				{
					bFix = true;
					m_bskdHandleCol = c;
				}
			}
		}
		if(colNumber == -1 || colWeight == -1 || needPay == -1 || colYsWeight == 1)
		{
			wchar_t szBuffer[128] = { 0 };
			wsprintfW(szBuffer, L"百世快递账单有标题未找到");
			THROW_ERROR(szBuffer);
		}
		if(!bFix)
			bsSheet->Cell(0, maxCols)->SetWString(L"对账结果");
		for(size_t r = 1; r < maxRows; ++r)
		{
			sBSKDAuthData _data;
			const wchar_t* _pStr = NULL;
			SHEET_CELL_STRING(bsSheet, r, colNumber, _data.number);
			SHEET_CELL_INT(bsSheet, r, colWeight, _data.finalWeight);
			SHEET_CELL_DOUBLE(bsSheet, r, colYsWeight, _data.ysWeight);
			SHEET_CELL_DOUBLE(bsSheet, r, needPay, _data.needPay);
			_data.row = r;
			m_mapBSKDAuthData[_data.number] = _data;
		}
		AddLog(L"读取百世快递账单成功");
	}
	else
	{
		THROW_ERROR(L"读取百世快递账单失败");
	}
	return true;
}

bool CStorageBillDlg::LoadYDKDData()
{
	if(!m_bCheckYDKD && !m_bSingleYDKD)
		return true;
	std::list<string> listFiles;
	ListFiles("./系统数据/韵达快递账单/*.*", listFiles);
	std::list<string>::iterator itB = listFiles.begin();
	std::list<string>::iterator itE = listFiles.end();
	while(itB != itE)
	{
		_LoadYDKDData((*itB).c_str());
		++itB;
	}
	AddLog(L"韵达快递账单读取完成");
	return true;
}

bool CStorageBillDlg::_LoadYDKDData(const char *file)
{
	BasicExcel* pExcel = new BasicExcel;
	pExcel->Load(file);
	BasicExcelWorksheet* ydSheet = pExcel->GetWorksheet(L"Sheet1");
	if(ydSheet)
	{
		size_t maxRows = ydSheet->GetTotalRows();
		size_t maxCols = ydSheet->GetTotalCols();
		m_mapYDKDHandleCol[pExcel].handleCol = maxCols;
		m_mapYDKDHandleCol[pExcel].bzCol1 = maxCols+1;
		m_mapYDKDHandleCol[pExcel].bzCol2 = maxCols+2;
		//load tile
		int colNumber = -1;
		int colWeight = -1;
		int colYsWeight = -1;
		bool bFix = false;
		for(size_t c = 0; c < maxCols; ++c)
		{
			BasicExcelCell* cell = ydSheet->Cell(0, c);
			const wchar_t* _titile = cell->GetWString();
			if(_titile)
			{
				std::wstring strTitle = _titile;

				if(strTitle == L"运单编号")
					colNumber = c;
				else if(strTitle == L"取整")
					colWeight = c;
				else if(strTitle == L"新结算重量")
					colYsWeight = c;
				else if(strTitle == L"对账结果")
				{
					bFix = true;
					m_mapYDKDHandleCol[pExcel].handleCol = c;
				}
			}
		}
		if(colNumber == -1 || colWeight == -1 || colYsWeight == 1)
		{
			wchar_t szBuffer[128] = { 0 };
			wsprintfW(szBuffer, L"韵达快递账单有标题未找到");
			THROW_ERROR(szBuffer);
		}
		if(!bFix)
		{
			ydSheet->Cell(0, maxCols)->SetWString(L"对账结果");
			ydSheet->Cell(0, maxCols+1)->SetWString(L"卓越出库重量");
			ydSheet->Cell(0, maxCols+2)->SetWString(L"卓越运费");
		}
		else
		{
			m_mapYDKDHandleCol[pExcel].bzCol1 = m_mapYDKDHandleCol[pExcel].handleCol + 1;
			m_mapYDKDHandleCol[pExcel].bzCol2 = m_mapYDKDHandleCol[pExcel].handleCol + 2;
		}
		for(size_t r = 1; r < maxRows; ++r)
		{
			sYDKDAuthData _data;
			_data.ydkdExcel = pExcel;
			const wchar_t* _pStr = NULL;
			SHEET_CELL_STRING(ydSheet, r, colNumber, _data.number);
			SHEET_CELL_INT(ydSheet, r, colWeight, _data.finalWeight);
			SHEET_CELL_DOUBLE(ydSheet, r, colYsWeight, _data.ysWeight);
			_data.row = r;
			m_mapYDKDAuthData[_data.number] = _data;
		}
		std::wstring wstrFile = CFuncCommon::String2WString(file);
		wchar_t szBuffer[128] = { 0 };
		wsprintfW(szBuffer, L"读取%s成功", wstrFile.c_str());
		AddLog(szBuffer);
	}
	else
	{
		std::wstring wstrFile = CFuncCommon::String2WString(file);
		wchar_t szBuffer[128] = { 0 };
		wsprintfW(szBuffer, L"读取%s失败", wstrFile.c_str());
		THROW_ERROR(szBuffer);
	}
	return true;
}

void ListFiles(const char * dir, std::list<string>& listFiles)
{
	intptr_t handle;
	_finddata_t findData;
	std::string filePath = dir;
	filePath = filePath.substr(0, filePath.size()-3);
	handle = _findfirst(dir, &findData);    // 查找目录中的第一个文件
	if(handle == -1)
		return;
	do
	{
		if(findData.attrib & _A_SUBDIR)    // 是否是子目录并且不为"."或".."
			int a = 3;
		else if(findData.name[0] == '2')
		{
			std::string name = filePath + findData.name;
			listFiles.push_back(name);
		}
	} while(_findnext(handle, &findData) == 0); 
	_findclose(handle);
}

bool CStorageBillDlg::LoadZTKYData()
{
	if(!m_bZYKY && !m_bZYKYMore)
		return true;
	std::wstring strZTFileName = ZTKY_FILE_PATH;
	std::string _strZTFileName = CFuncCommon::WString2String(strZTFileName.c_str());
	m_ztkyExcel.Load(_strZTFileName.c_str());
	BasicExcelWorksheet* ztSheet = m_ztkyExcel.GetWorksheet(L"Sheet1");
	if(ztSheet)
	{
		size_t maxRows = ztSheet->GetTotalRows();
		size_t maxCols = ztSheet->GetTotalCols();
		m_ztkyHandleCol = maxCols;
		//load tile
		int colNumber = -1;
		int colWeight = -1;
		int yingShou = -1;
		int qita = -1;
		int qitaInfo = -1;
		int sheng = -1;
		int shi = -1;
		bool bFix = false;
		bool bChengBen = false;
		for(size_t c = 0; c < maxCols; ++c)
		{
			BasicExcelCell* cell = ztSheet->Cell(0, c);
			const wchar_t* _titile = cell->GetWString();
			if(_titile)
			{
				std::wstring strTitle = _titile;
				if(strTitle == L"运单号")
					colNumber = c;
				else if(strTitle == L"结算重量")
					colWeight = c;
				else if(strTitle == L"应收")
					yingShou = c;
				else if(strTitle == L"其他")
					qita = c;
				else if(strTitle == L"备注")
					qitaInfo = c;
				else if(strTitle == L"省")
					sheng = c;
				else if(strTitle == L"市")
					shi = c;
				else if(strTitle == L"对账结果")
				{
					bFix = true;
					m_ztkyHandleCol = c;
				}
				else if(strTitle == L"云仓成本")
				{
					bChengBen = true;
					m_ztkyChengBenCol = c;
				}
			}
			
		}
		if(colNumber == -1 || colWeight == -1 || yingShou == -1 || qita == -1 || qitaInfo == -1 || sheng == -1 || shi == -1)
		{
			wchar_t szBuffer[128] = { 0 };
			wsprintfW(szBuffer, L"中通快运账单有标题未找到");
			THROW_ERROR(szBuffer);
		}
		int nOtherCol = maxCols;
		if(!bFix)
		{
			m_ztkyHandleCol = nOtherCol;
			ztSheet->Cell(0, nOtherCol++)->SetWString(L"对账结果");
		}
		if(!bChengBen)
		{
			m_ztkyChengBenCol = nOtherCol;
			ztSheet->Cell(0, nOtherCol++)->SetWString(L"云仓成本");
		}
		for(size_t r = 1; r < maxRows; ++r)
		{
			sZTKYAuthData _data;
			const wchar_t* _pStr = NULL;
			SHEET_CELL_STRING(ztSheet, r, colNumber, _data.number);
			SHEET_CELL_STRING(ztSheet, r, sheng, _data.sheng);
			SHEET_CELL_STRING(ztSheet, r, shi, _data.shi);
			SHEET_CELL_DOUBLE(ztSheet, r, colWeight, _data.finalWeight);
			SHEET_CELL_DOUBLE(ztSheet, r, yingShou, _data.yingShou);
			SHEET_CELL_DOUBLE(ztSheet, r, qita, _data.qita);
			SHEET_CELL_STRING(ztSheet, r, qitaInfo, _data.qitaInfo);
			_data.row = r;
			m_mapZTKYAuthData[_data.number] = _data;
		}
		AddLog(L"读取中通快运账单成功	");
	}
	else
	{
		THROW_ERROR(L"读取中通快运账单失败");
	}
	return true;
}

bool CStorageBillDlg::CheckYDKDMore()
{
	std::map< std::wstring, std::list<sSalesInfo> >::iterator itB1 = m_mapAllSalesInfo.begin();
	std::map< std::wstring, std::list<sSalesInfo> >::iterator itE1 = m_mapAllSalesInfo.end();
	while(itB1 != itE1)
	{
		std::list<sSalesInfo>::iterator itB2 = itB1->second.begin();
		std::list<sSalesInfo>::iterator itE2 = itB1->second.end();
		while(itB2 != itE2)
		{
			if(IsYunDaKuaiDi(itB2->strWuLiuGongSi))
			{
				++itB2;
				continue;
			}
			std::map<std::wstring, sYDKDAuthData>::iterator itYD = m_mapYDKDAuthData.find(itB2->strWuLiuDanHao);
			if(itYD != m_mapYDKDAuthData.end())
			{
				BasicExcelWorksheet* ydSheet = itYD->second.ydkdExcel->GetWorksheet(L"Sheet1");
				ydSheet->Cell(itYD->second.row, m_mapYDKDHandleCol[itYD->second.ydkdExcel].handleCol)->SetWString(L"1");
				
			}
			itB2++;
		}
		itB1++;
	}
	return true;
}

bool CStorageBillDlg::CheckZTKYMore()
{
	BasicExcelWorksheet* ztSheet = m_ztkyExcel.GetWorksheet(L"Sheet1");
	if(ztSheet == NULL)
	{
		THROW_ERROR(L"中通快运账单找不到 Sheet1 子表");
	}
	std::map< std::wstring, std::list<sSalesInfo> >::iterator itB1 = m_mapAllSalesInfo.begin();
	std::map< std::wstring, std::list<sSalesInfo> >::iterator itE1 = m_mapAllSalesInfo.end();
	while(itB1 != itE1)
	{
		std::list<sSalesInfo>::iterator itB2 = itB1->second.begin();
		std::list<sSalesInfo>::iterator itE2 = itB1->second.end();
		while(itB2 != itE2)
		{
			if(IsZhongTongKuaiYun(itB2->strWuLiuGongSi))
			{
				++itB2;
				continue;
			}
			std::map<std::wstring, sZTKYAuthData>::iterator itZT = m_mapZTKYAuthData.find(itB2->strWuLiuDanHao);
			if(itZT != m_mapZTKYAuthData.end())
			{
				ztSheet->Cell(itZT->second.row, m_ztkyHandleCol)->SetWString(L"1");
				itZT->second.bHandleChengBen = true;
				/*int nWeight = 0;
				if(!IsZhengShu(itB2->strZhongLiang))
				{
					double nZhongLiang = _wtof(itB2->strZhongLiang.c_str());
					nZhongLiang += 1;
					nZhongLiang += DOUBLE_PRECISION;
					nWeight = int(nZhongLiang);
				}
				else
				{
					if(IsZero(itB2->strZhongLiang))
						nWeight = 0;
					else
						nWeight = _wtoi(itB2->strZhongLiang.c_str());
				}*/
				double dZhongLiang = itZT->second.finalWeight;
				dZhongLiang += DOUBLE_PRECISION;
				int nWeight = int(dZhongLiang);
				double price = GetKYPrice(nWeight, itB2->strSheng, itB2->strShi, g_chengBenZTKYPrice, itB2->strWuLiuDanHao, false);
				ztSheet->Cell(itZT->second.row, m_ztkyChengBenCol)->SetDouble(price);
			}
			itB2++;
		}
		itB1++;
	}

	std::map<std::wstring, sZTKYAuthData>::iterator __itB = m_mapZTKYAuthData.begin();
	std::map<std::wstring, sZTKYAuthData>::iterator __itE = m_mapZTKYAuthData.end();
	while(__itB != __itE)
	{
		if(!__itB->second.bHandleChengBen)
		{
			double dZhongLiang = __itB->second.finalWeight;
			dZhongLiang += DOUBLE_PRECISION;
			int nWeight = int(dZhongLiang);
			double price = GetKYPrice(nWeight, __itB->second.sheng, __itB->second.shi, g_chengBenZTKYPrice, __itB->first, false);
			ztSheet->Cell(__itB->second.row, m_ztkyChengBenCol)->SetDouble(price);
		}

		++__itB;
	}
	return true;
}
bool CStorageBillDlg::LoadSFData()
{
	if(m_bZYKYMore)
		return true;
	if(m_bCheckYDKD)
		return true;
	if(!m_bSF)
		return true;
	std::wstring strSFFileName = SF_FILE_PATH;
	std::string _strSFFileName = CFuncCommon::WString2String(strSFFileName.c_str());
	m_sfExcel.Load(_strSFFileName.c_str());
	BasicExcelWorksheet* sfSheet = m_sfExcel.GetWorksheet(L"Sheet0");
	if(sfSheet)
	{
		size_t maxRows = sfSheet->GetTotalRows();
		size_t maxCols = sfSheet->GetTotalCols();
		m_sfHandleCol = maxCols;
		//load tile
		int colNumber = -1;
		int colWeight = -1;
		int colVAServices = -1;
		int colNeedPay = -1;
		int colType = -1;
		bool bFix = false;
		for(size_t c = 0; c < maxCols; ++c)
		{
			BasicExcelCell* cell = sfSheet->Cell(0, c);
			std::wstring strTitle = cell->GetWString();
			if(strTitle == L"运单号码")
				colNumber = c;
			else if(strTitle == L"计费重量")
				colWeight = c;
			else if(strTitle == L"增值费用")
				colVAServices = c;
			else if(strTitle == L"应付金额")
				colNeedPay = c;
			else if(strTitle == L"产品类型")
				colType = c;
			else if(strTitle == L"对账结果")
			{
				bFix = true;
				m_sfHandleCol = c;
			}
		}		
		if(colNumber == -1 || colWeight == -1 || colVAServices == -1 || colNeedPay == -1 || colType == -1)
		{
			THROW_ERROR(L"顺丰账单 有标题未找到");
		}
		if(!bFix)
			sfSheet->Cell(0, maxCols)->SetWString(L"对账结果");
		for(size_t r = 1; r < maxRows; ++r)
		{
			sSFAuthData _data;
			const wchar_t* _pStr = NULL;
			SHEET_CELL_STRING(sfSheet, r, colNumber, _data.number);
			SHEET_CELL_STRING(sfSheet, r, colWeight, _data.weight);
			SHEET_CELL_STRING(sfSheet, r, colVAServices, _data.vaServices);
			SHEET_CELL_STRING(sfSheet, r, colNeedPay, _data.needPay);
			SHEET_CELL_STRING(sfSheet, r, colType, _data.type);
			_data.row = r;
			std::set<std::wstring>::iterator itLiveCheck = m_setSFCangKuData.find(_data.number);
			if(itLiveCheck != m_setSFCangKuData.end())
				sfSheet->Cell(r, m_sfHandleCol)->SetWString(L"1");
			if(_data.vaServices == L"保价" || _data.vaServices == L"特安" || _data.vaServices == L"易碎保" || _data.vaServices == L"包装服务" || _data.vaServices == L"资源调节费" || _data.vaServices == L"超长超重服务")
			{
				std::map<std::wstring, sSFAuthData>::iterator it = m_mapSFAuthData.find(_data.number);
				if(it != m_mapSFAuthData.end())
				{
					double before = _wtof(it->second.needPay.c_str());
					double now = _wtof(_data.needPay.c_str());
					double after = before+now;
					it->second.needPay = CFuncCommon::Double2WString(after, 2);
					it->second.bjPay = _data.needPay;
				}
				else
				{
					wchar_t szBuffer[128] = { 0 };
					wsprintfW(szBuffer, L"顺丰保费 未找到相应单号 %s", _data.number.c_str());
					AddLog(szBuffer);
				}
				continue;
			}
			else if(_data.vaServices == L"转寄退回" || _data.vaServices == L"异地退回" || _data.vaServices == L"原单退回" || _data.vaServices == L"异地转寄" || _data.vaServices == L"同城退回" || _data.vaServices == L"同城转寄")
			{
				std::map<std::wstring, sSFAuthData>::iterator it = m_mapSFAuthData.find(_data.number);
				if(it != m_mapSFAuthData.end())
				{
					double before = _wtof(it->second.needPay.c_str());
					double now = _wtof(_data.needPay.c_str());
					double after = before + now;
					it->second.needPay = CFuncCommon::Double2WString(after, 2);
					it->second.backPay = _data.needPay;
				}
				else
				{
					wchar_t szBuffer[128] = { 0 };
					wsprintfW(szBuffer, L"顺丰转寄退回 未找到相应单号 %s", _data.number.c_str());
					AddLog(szBuffer);
				}
				continue;
			}
			else if(_data.vaServices == L"大件入户")
			{
				std::map<std::wstring, sSFAuthData>::iterator it = m_mapSFAuthData.find(_data.number);
				if(it != m_mapSFAuthData.end())
				{
					double before = _wtof(it->second.needPay.c_str());
					double now = _wtof(_data.needPay.c_str());
					double after = before + now;
					it->second.needPay = CFuncCommon::Double2WString(after, 2);
					it->second.djPay = _data.needPay;
				}
				else
				{
					wchar_t szBuffer[128] = { 0 };
					wsprintfW(szBuffer, L"顺丰大件入户 未找到相应单号 %s", _data.number.c_str());
					AddLog(szBuffer);
				}
				continue;
			}
			else if(_data.vaServices != L"")
			{
				wchar_t szBuffer[128] = { 0 };
				wsprintfW(szBuffer, L"顺丰未知增值服务类型 %s", _data.vaServices.c_str());
				AddLog(szBuffer);
			}
			_pStr = sfSheet->Cell(r, m_sfHandleCol)->GetWString();
			if(_pStr)
			{
				if(wcscmp(_pStr, L"1") == 0)
					_data.bHandle = true;
			}
			m_mapSFAuthData[_data.number] = _data;
		}
		AddLog(L"读取顺丰账单成功");
	}
	else
	{
		THROW_ERROR(L"读取顺丰账单失败");
	}
	return true;
}

void CStorageBillDlg::OnLbnDblclkLogList()
{
	int nSel = m_ctrlListLog.GetCurSel();
	if(nSel != -1)
	{
		CString info;
		m_ctrlListLog.GetText(nSel, info);
		if(OpenClipboard())
		{
			std::string _info = CFuncCommon::WString2String(info.GetBuffer());
			HGLOBAL clipbuffer;
			char* buffer;
			EmptyClipboard();
			clipbuffer = GlobalAlloc(GMEM_DDESHARE, _info.size()+1);
			buffer = (char*)GlobalLock(clipbuffer);
			strcpy(buffer, _info.c_str());
			GlobalUnlock(clipbuffer);
			SetClipboardData(CF_TEXT, clipbuffer);
			CloseClipboard();
		}
	}
	// TODO:  在此添加控件通知处理程序代码
}


double CStorageBillDlg::GetSFPrice(int nWeight, wstring strSheng, std::vector< std::list<sExpressPriceInfo> >& vecPrice, wstring danhao)
{
	int nIndex = -1;
	if(vecPrice.size() == 4)
	{
		if(strSheng == L"四川省" || strSheng == L"重庆")
			nIndex = 0;
		else if(strSheng == L"北京" || strSheng == L"贵州省" || strSheng == L"河北省" || strSheng == L"湖北省" || strSheng == L"江苏省" || strSheng == L"陕西省" || strSheng == L"上海" || strSheng == L"天津" || strSheng == L"云南省" || strSheng == L"浙江省")
			nIndex = 1;
		else if(strSheng == L"安徽省" || strSheng == L"福建省" || strSheng == L"甘肃省" || strSheng == L"广东省" || strSheng == L"广西壮族自治区" || strSheng == L"海南省" || strSheng == L"河南省" || strSheng == L"湖南省" || strSheng == L"江西省" || strSheng == L"宁夏回族自治区" || strSheng == L"青海省" || strSheng == L"山东省" || strSheng == L"山西省")
			nIndex = 2;
		else if(strSheng == L"黑龙江省" || strSheng == L"吉林省" || strSheng == L"辽宁省" || strSheng == L"内蒙古自治区" || strSheng == L"新疆维吾尔自治区" || strSheng == L"西藏自治区")
			nIndex = 3;
		else
		{
			wchar_t szBuffer[128] = { 0 };
			wsprintfW(szBuffer, L"顺丰 未知省份 %s", strSheng.c_str());
			THROW_ERROR(szBuffer);
		}
	}
	else
	{
		if(strSheng == L"四川省" || strSheng == L"重庆" ||
			strSheng == L"北京" || strSheng == L"贵州省" || strSheng == L"河北省" || strSheng == L"湖北省" || strSheng == L"江苏省" || strSheng == L"陕西省" || strSheng == L"上海" || strSheng == L"天津" || strSheng == L"云南省" || strSheng == L"浙江省" ||
			strSheng == L"安徽省" || strSheng == L"福建省" || strSheng == L"甘肃省" || strSheng == L"广东省" || strSheng == L"广西壮族自治区" || strSheng == L"海南省" || strSheng == L"河南省" || strSheng == L"湖南省" || strSheng == L"江西省" || strSheng == L"宁夏回族自治区" || strSheng == L"青海省" || strSheng == L"山东省" || strSheng == L"山西省")
			nIndex = 0;
		else if(strSheng == L"黑龙江省" || strSheng == L"吉林省" || strSheng == L"辽宁省" || strSheng == L"内蒙古自治区" || strSheng == L"新疆维吾尔自治区" || strSheng == L"西藏自治区")
			nIndex = 1;
		else
		{
			wchar_t szBuffer[128] = { 0 };
			wsprintfW(szBuffer, L"顺丰 未知省份 %s", strSheng.c_str());
			THROW_ERROR(szBuffer);
		}
	}
	std::list<sExpressPriceInfo>::iterator itB = vecPrice[nIndex].begin();
	std::list<sExpressPriceInfo>::iterator itE = vecPrice[nIndex].end();
	while(itB != itE)
	{
		if(nWeight > itB->nMinZL && (nWeight <= itB->nMaxZL || itB->nMaxZL == 0))
		{
			if(nWeight <= itB->nFirstZL)
				return itB->dFirstPrice;
			else
				return itB->dFirstPrice + (nWeight - itB->nFirstZL)*itB->dXZPrice;
		}
		++itB;
	}
	wchar_t szBuffer[128] = { 0 };
	wsprintfW(szBuffer, L"顺丰快递 %s 重量不含有对应价格区间 %s %d", danhao.c_str(), strSheng.c_str(), nWeight);
	THROW_ERROR(szBuffer);
}

double CStorageBillDlg::GetKDPrice(int nWeight, wstring strSheng, wstring strShi, std::map< std::wstring, std::list<sExpressPriceInfo> >& mapPrice, wstring strKuDiType, wstring danhao, bool bWarnning)
{
	std::map< std::wstring, std::list<sExpressPriceInfo> >::iterator it;
	if(strShi != L"")
	{
		it = mapPrice.find(strShi);
		if(it == mapPrice.end())
			it = mapPrice.find(strSheng);
	}
	else
		it = mapPrice.find(strSheng);
	if(it != mapPrice.end())
	{
		std::list<sExpressPriceInfo>::iterator itB = it->second.begin();
		std::list<sExpressPriceInfo>::iterator itE = it->second.end();
		while(itB != itE)
		{
			if(nWeight > itB->nMinZL && (nWeight <= itB->nMaxZL || itB->nMaxZL == 0))
			{
				if(nWeight <= itB->nFirstZL)
					return itB->dFirstPrice + itB->dFirstCommission;
				else
					return itB->dFirstPrice + itB->dFirstCommission + (nWeight-itB->nFirstZL)*itB->dXZPrice + (nWeight-itB->nFirstZL)*itB->dXZCommission;
			}
			++itB;
		}
		if(!bWarnning)
			return 0.0;
		wchar_t szBuffer[128] = { 0 };
		wsprintfW(szBuffer, L"%s %s 重量不含有对应价格区间 %s %d", strKuDiType.c_str(), danhao.c_str(), strSheng.c_str(), nWeight);
		THROW_ERROR(szBuffer);
	}
	else
	{
		wchar_t szBuffer[128] = { 0 };
		wsprintfW(szBuffer, L"%s %s 未知省份 %s", strKuDiType.c_str(), danhao.c_str(), strSheng.c_str());
		THROW_ERROR(szBuffer);
	}
	return 0.0;
}

double CStorageBillDlg::GetKYPrice(int nWeight, wstring strSheng, wstring strShi, std::map< std::wstring, std::list<sLargeExpressPriceInfo> >& mapPrice, wstring danhao, bool bWarnning)
{
	std::map< std::wstring, std::list<sLargeExpressPriceInfo> >::iterator it;
	if(strShi != L"")
	{
		it = mapPrice.find(strShi);
		if(it == mapPrice.end())
			it = mapPrice.find(strSheng);
	}
	else
		it = mapPrice.find(strSheng);
	if(it != mapPrice.end())
	{
		std::list<sLargeExpressPriceInfo>::iterator itB = it->second.begin();
		std::list<sLargeExpressPriceInfo>::iterator itE = it->second.end();
		while(itB != itE)
		{
			if(nWeight > itB->nMinZL && (nWeight <= itB->nMaxZL || itB->nMaxZL == 0))
			{
				if(nWeight <= itB->nFirstZL)
					return itB->dFirstPrice;
				else
					return itB->dFirstPrice + (nWeight - itB->nFirstZL)*itB->dXZPrice;
			}
			++itB;
		}
		if(!bWarnning)
			return 0.0;
		wchar_t szBuffer[128] = { 0 };
		wsprintfW(szBuffer, L"快运重量不含有对应价格区间 %s %d [%s]", strSheng.c_str(), nWeight, danhao.c_str());
		THROW_ERROR(szBuffer);
	}
	else
	{
		wchar_t szBuffer[128] = { 0 };
		wsprintfW(szBuffer, L"快运未知省份 %s [%s]", strSheng.c_str(), danhao.c_str());
		THROW_ERROR(szBuffer);
	}
	return 0.0;
}

bool CStorageBillDlg::IsZhengShu(std::wstring number)
{
	int nPos = number.find('.');
	if(nPos == std::wstring::npos)
		return true;
	else
	{
		for(int i=nPos+1; i<number.size(); ++i)
		{
			wchar_t t = number.at(i);
			if(t != L'0')
				return false;
		}
		return true;
	}
}

bool CStorageBillDlg::IsZero(std::wstring number)
{
	double dNumber = _wtof(number.c_str());
	if(dNumber < DOUBLE_PRECISION)
		return true;
	return false;
}

bool CStorageBillDlg::Handle_YiMaiKeJi()
{
	BasicExcel excel;
	if(!CreateExcel(L"颐麦科技", excel, m_mapAllSalesInfo[L"颐麦科技"], m_mapInStorageInfo[L"颐麦科技"]))
		return false;
	wstring fileName = L"./Export_" + m_strYM + L"/" + L"颐麦科技_" + m_strYM + L"对账单.xls";
	string _file = CFuncCommon::WString2String(fileName.c_str());
	CompareWhithWuLiu(L"颐麦科技", m_mapAllSalesInfo[L"颐麦科技"]);
	//计算相关费用
	{
		BasicExcelWorksheet* sheet = excel.GetWorksheet(L"订单费用");
		if(sheet)
		{
			std::list<sSalesInfo>& listSales = m_mapAllSalesInfo[L"颐麦科技"];
			std::list<sSalesInfo>::iterator itB = listSales.begin();
			std::list<sSalesInfo>::iterator itE = listSales.end();
			while(itB != itE)
			{
				wstring strBeiZhu = L"";
				int nWeight = 0;
				if(!IsZhengShu(itB->strZhongLiang))
				{
					double nZhongLiang = _wtof(itB->strZhongLiang.c_str());
					nZhongLiang += 1;
					nZhongLiang += DOUBLE_PRECISION;
					nWeight = int(nZhongLiang);
					if(nWeight < 3)
						nWeight = 3;
					wchar_t szWeight[10] = { 0 };
					_itow_s(nWeight, szWeight, 10);
					sheet->Cell(itB->nRow, eET_JiFeiZhongLiang)->SetWString(szWeight);
				}
				else
				{
					if(IsZero(itB->strZhongLiang))
						nWeight = 0;
					else
					{
						nWeight = _wtoi(itB->strZhongLiang.c_str());
						if(nWeight < 3)
							nWeight = 3;
					}

					wchar_t szWeight[10] = { 0 };
					_itow_s(nWeight, szWeight, 10);
					sheet->Cell(itB->nRow, eET_JiFeiZhongLiang)->SetWString(szWeight);
				}
				double dZengZhi = 0;
				//计算物流费
				{
					if(IsBaiShiKuaiDi(itB->strWuLiuGongSi) || IsYunDaKuaiDi(itB->strWuLiuGongSi))
					{
						double money = 0;
						if(nWeight > 0)
						{
							double money = GetKDPrice(nWeight, itB->strSheng, itB->strShi, g_yiMaiKeJiBSPrice, L"韵达快递", itB->strWuLiuDanHao);
							sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1).c_str());
						}
					}
					else if(IsBaiShiKuaiYun(itB->strWuLiuGongSi) || IsZhongTongKuaiYun(itB->strWuLiuGongSi) || IsYunDaKuaiYun(itB->strWuLiuGongSi))
					{
						double money = GetKYPrice(nWeight, itB->strSheng, itB->strShi, g_yiMaiKeJiZTKYPrice, itB->strWuLiuDanHao);
						sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1).c_str());
						if(IsZhongTongKuaiYun(itB->strWuLiuGongSi))
						{
							bool bSL = false;
							std::map<std::wstring, sZTKYAuthData>::iterator itZTKY = m_mapZTKYAuthData.find(itB->strWuLiuDanHao);
							if(itZTKY != m_mapZTKYAuthData.end())
							{
								double chengbenMoney = GetKYPrice(nWeight, itB->strSheng, itB->strShi, g_chengBenZTKYPrice, itB->strWuLiuDanHao);
								if(chengbenMoney + DOUBLE_PRECISION < itZTKY->second.yingShou - itZTKY->second.qita)
								{
									BasicExcelWorksheet* recordSheet = m_recordExcel.GetWorksheet(g_arrWorksheetName[5]);
									recordSheet->Cell(g_arrRecordRowIndex[5], 0)->SetWString(L"颐麦科技");
									recordSheet->Cell(g_arrRecordRowIndex[5], 1)->SetWString(itB->strWuLiuDanHao.c_str());
									recordSheet->Cell(g_arrRecordRowIndex[5], 2)->SetWString(CFuncCommon::Double2WString(itZTKY->second.yingShou - itZTKY->second.qita + DOUBLE_PRECISION, 1).c_str());
									recordSheet->Cell(g_arrRecordRowIndex[5], 3)->SetWString(CFuncCommon::Double2WString(chengbenMoney + DOUBLE_PRECISION, 1).c_str());
									g_arrRecordRowIndex[5]++;

									BasicExcelWorksheet* ztSheet = m_ztkyExcel.GetWorksheet(L"Sheet1");
									if(ztSheet)
										ztSheet->Cell(itZTKY->second.row, m_ztkyHandleCol)->SetWString(L"价格异常");
								}
								if(itZTKY->second.qita > DOUBLE_PRECISION)
								{
									dZengZhi += itZTKY->second.qita;
									if(strBeiZhu == L"")
										strBeiZhu = strBeiZhu + L"上楼";
									else
										strBeiZhu = strBeiZhu + L" | 上楼";
									bSL = true;
								}
							}
							if(!bSL)
							{
								if(nWeight > 50)
								{
									if(nWeight < 120)
										dZengZhi += (nWeight - 50)*0.1 + 10;
									else
										dZengZhi += (nWeight - 50)*0.1 + 30;
									if(strBeiZhu == L"")
										strBeiZhu = strBeiZhu + L"上楼";
									else
										strBeiZhu = strBeiZhu + L" | 上楼";
								}
							}
						}
					}
					else if(IsShunFengKuaiDi(itB->strWuLiuGongSi))
					{
						double money = GetSFPrice(nWeight, itB->strSheng, g_yiMaiKeJiSFPrice, itB->strWuLiuDanHao);
						sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1).c_str());
					}
					else
					{
						wchar_t szOut[120] = { 0 };
						_swprintf(szOut, L"[未知的物流方式] 货主=%s 单号=%s 物流公司=%s", itB->strHuoZhu.c_str(), itB->strWuLiuDanHao.c_str(), itB->strWuLiuGongSi.c_str());
						AddLog(szOut);
					}
				}
				//打包费用
				{
					double _price = 0.8;
					int nZSL = _wtoi(itB->strHuoPinZongShuLiang.c_str());
					if(nZSL > 8)
						_price = 0.8 + (nZSL - 8)*0.1;
					else
						_price = 0.8;
					sheet->Cell(itB->nRow, eET_CaoZuoFei)->SetWString(CFuncCommon::Double2WString(_price + DOUBLE_PRECISION, 1).c_str());
				}
				sheet->Cell(itB->nRow, eET_BeiZhu)->SetWString(strBeiZhu.c_str());
				++itB;
			}
		}

	}
	excel.SaveAs(_file.c_str());
	AddLog(L"颐麦科技账单生成成功");
	return true;
}

bool CStorageBillDlg::Handle_XinMaBang()
{
	BasicExcel excel;
	if(!CreateExcel(L"新马帮", excel, m_mapAllSalesInfo[L"新马帮"], m_mapInStorageInfo[L"新马帮"]))
		return false;
	wstring fileName = L"./Export_" + m_strYM + L"/" + L"新马帮_" + m_strYM + L"对账单.xls";
	string _file = CFuncCommon::WString2String(fileName.c_str());
	CompareWhithWuLiu(L"新马帮", m_mapAllSalesInfo[L"新马帮"]);
	//计算相关费用
	{
		BasicExcelWorksheet* sheet = excel.GetWorksheet(L"订单费用");
		if(sheet)
		{
			std::list<sSalesInfo>& listSales = m_mapAllSalesInfo[L"新马帮"];
			std::list<sSalesInfo>::iterator itB = listSales.begin();
			std::list<sSalesInfo>::iterator itE = listSales.end();
			while(itB != itE)
			{
				wstring strBeiZhu = L"";
				int nWeight = 0;
				if(!IsZhengShu(itB->strZhongLiang))
				{
					double nZhongLiang = _wtof(itB->strZhongLiang.c_str());
					nZhongLiang += 1;
					nZhongLiang += DOUBLE_PRECISION;
					nWeight = int(nZhongLiang);
					if(nWeight < 3)
						nWeight = 3;
					wchar_t szWeight[10] = { 0 };
					_itow_s(nWeight, szWeight, 10);
					sheet->Cell(itB->nRow, eET_JiFeiZhongLiang)->SetWString(szWeight);
				}
				else
				{
					if(IsZero(itB->strZhongLiang))
						nWeight = 0;
					else
					{
						nWeight = _wtoi(itB->strZhongLiang.c_str());
						if(nWeight < 3)
							nWeight = 3;
					}

					wchar_t szWeight[10] = { 0 };
					_itow_s(nWeight, szWeight, 10);
					sheet->Cell(itB->nRow, eET_JiFeiZhongLiang)->SetWString(szWeight);
				}
				double dZengZhi = 0;
				//计算物流费
				{
					if(IsBaiShiKuaiDi(itB->strWuLiuGongSi) || IsYunDaKuaiDi(itB->strWuLiuGongSi))
					{
						double money = 0;
						int nZSL = _wtoi(itB->strHuoPinZongShuLiang.c_str());
						if(nZSL != 1)
						{
							double money = GetKDPrice(nWeight, itB->strSheng, itB->strShi, g_xinMaBangBSPrice, L"百世快递", itB->strWuLiuDanHao);
							sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1).c_str());
						}
						else
						{
							double money = GetKDPrice(5, itB->strSheng, itB->strShi, g_xinMaBangBSPrice, L"百世快递", itB->strWuLiuDanHao);
							money += 0.4;
							sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1).c_str());
						}
					}
					else if(IsZhongTongKuaiYun(itB->strWuLiuGongSi) || IsYunDaKuaiYun(itB->strWuLiuGongSi))
					{
						double money = GetKYPrice(nWeight, itB->strSheng, itB->strShi, g_xinMaBangZTKYPrice, itB->strWuLiuDanHao);
						sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1).c_str());
						if(IsZhongTongKuaiYun(itB->strWuLiuGongSi))
						{
							bool bSL = false;
							std::map<std::wstring, sZTKYAuthData>::iterator itZTKY = m_mapZTKYAuthData.find(itB->strWuLiuDanHao);
							if(itZTKY != m_mapZTKYAuthData.end())
							{
								double chengbenMoney = GetKYPrice(nWeight, itB->strSheng, itB->strShi, g_chengBenZTKYPrice, itB->strWuLiuDanHao);
								if(chengbenMoney+DOUBLE_PRECISION < itZTKY->second.yingShou-itZTKY->second.qita)
								{
									BasicExcelWorksheet* recordSheet = m_recordExcel.GetWorksheet(g_arrWorksheetName[5]);
									recordSheet->Cell(g_arrRecordRowIndex[5], 0)->SetWString(L"新马帮");
									recordSheet->Cell(g_arrRecordRowIndex[5], 1)->SetWString(itB->strWuLiuDanHao.c_str());
									recordSheet->Cell(g_arrRecordRowIndex[5], 2)->SetWString(CFuncCommon::Double2WString(itZTKY->second.yingShou-itZTKY->second.qita + DOUBLE_PRECISION, 1).c_str());
									recordSheet->Cell(g_arrRecordRowIndex[5], 3)->SetWString(CFuncCommon::Double2WString(chengbenMoney + DOUBLE_PRECISION, 1).c_str());
									g_arrRecordRowIndex[5]++;

									BasicExcelWorksheet* ztSheet = m_ztkyExcel.GetWorksheet(L"Sheet1");
									if(ztSheet)
										ztSheet->Cell(itZTKY->second.row, m_ztkyHandleCol)->SetWString(L"价格异常");
								}

								if(itZTKY->second.qita > DOUBLE_PRECISION)
								{
									dZengZhi += itZTKY->second.qita;
									if(strBeiZhu == L"")
										strBeiZhu = strBeiZhu + L"上楼";
									else
										strBeiZhu = strBeiZhu + L" | 上楼";
									bSL = true;
								}
							}
							if(!bSL)
							{
								if(nWeight > 50)
								{
									if(nWeight < 120)
										dZengZhi += (nWeight - 50)*0.1 + 10;
									else
										dZengZhi += (nWeight - 50)*0.1 + 30;
									if(strBeiZhu == L"")
										strBeiZhu = strBeiZhu + L"上楼";
									else
										strBeiZhu = strBeiZhu + L" | 上楼";
								}
							}
						}
					}
					else
					{
						wchar_t szOut[120] = { 0 };
						_swprintf(szOut, L"[未知的物流方式] 货主=%s 单号=%s 物流公司=%s", itB->strHuoZhu.c_str(), itB->strWuLiuDanHao.c_str(), itB->strWuLiuGongSi.c_str());
						AddLog(szOut);
					}
				}
				//计算增值费用
				{
					if(dZengZhi > 0)
						sheet->Cell(itB->nRow, eET_ZengZhiFeiYong)->SetWString(CFuncCommon::Double2WString(dZengZhi + DOUBLE_PRECISION, 1).c_str());
				}
				sheet->Cell(itB->nRow, eET_BeiZhu)->SetWString(strBeiZhu.c_str());
				++itB;
			}
		}
	}
	excel.SaveAs(_file.c_str());
	AddLog(L"新马帮账单生成成功");
	return true;
}

bool CStorageBillDlg::Handle_KunLunShanShuiKa()
{
	BasicExcel excel;
	if(!CreateExcel(L"昆仑山水卡", excel, m_mapAllSalesInfo[L"昆仑山水卡"], m_mapInStorageInfo[L"昆仑山水卡"]))
		return false;
	wstring fileName = L"./Export_" + m_strYM + L"/" + L"昆仑山水卡_" + m_strYM + L"对账单.xls";
	string _file = CFuncCommon::WString2String(fileName.c_str());
	CompareWhithWuLiu(L"昆仑山水卡", m_mapAllSalesInfo[L"昆仑山水卡"]);
	//计算相关费用
	{
		BasicExcelWorksheet* sheet = excel.GetWorksheet(L"订单费用");
		if(sheet)
		{
			std::list<sSalesInfo>& listSales = m_mapAllSalesInfo[L"昆仑山水卡"];
			std::list<sSalesInfo>::iterator itB = listSales.begin();
			std::list<sSalesInfo>::iterator itE = listSales.end();
			while(itB != itE)
			{
				map_key_wstring_val_int mapRet;
				double money = 0.0;
				if(CFuncCommon::ParseKeyWStringInt(itB->strHuoPinMingXi, mapRet))
				{
					map_key_wstring_val_int::iterator _itB = mapRet.begin();
					map_key_wstring_val_int::iterator _itE = mapRet.end();
					while(_itB != _itE)
					{
						if(_itB->first == L"昆仑山 510ml*12")
						{
							sheet->Cell(itB->nRow, eET_KunLunShanShuiKa_510_12)->SetInteger(_itB->second);
							money += (12*_itB->second);
						}
						else if(_itB->first == L"昆仑山 510ml*24")
						{
							sheet->Cell(itB->nRow, eET_KunLunShanShuiKa_510_24)->SetInteger(_itB->second);
							money += (18*_itB->second);
						}
						else if(_itB->first == L"昆仑山 4L*4")
						{
							sheet->Cell(itB->nRow, eET_KunLunShanShuiKa_4_4)->SetInteger(_itB->second);
							money += (20*_itB->second);
						}
						else if(_itB->first == L"昆仑山 1.23L*12")
						{
							sheet->Cell(itB->nRow, eET_KunLunShanShuiKa_123_12)->SetInteger(_itB->second);
							money += (20*_itB->second);
						}
						else if(_itB->first == L"昆仑山 350ml*12")
						{
							sheet->Cell(itB->nRow, eET_KunLunShanShuiKa_350_12)->SetInteger(_itB->second);
							money += (5*_itB->second);
						}
						else if(_itB->first == L"昆仑山 350ml*24")
						{
							sheet->Cell(itB->nRow, eET_KunLunShanShuiKa_350_24)->SetInteger(_itB->second);
							money += (14*_itB->second);
						}
						else
						{
							wchar_t szBuffer[128] = { 0 };
							wsprintfW(szBuffer, L"昆仑山水卡找不到产品名 单号=%s %s", itB->strWuLiuDanHao.c_str(), _itB->first.c_str());
							AddLog(szBuffer);
						}
						++_itB;
					}
				}
				sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1).c_str());
				++itB;
			}
		}
	}
	excel.SaveAs(_file.c_str());
	AddLog(L"昆仑山水卡账单生成成功");
	return true;
}

bool CStorageBillDlg::Handle_KuoWeiDianShang()
{
	BasicExcel excel;
	if(!CreateExcel(L"阔伟电商", excel, m_mapAllSalesInfo[L"阔伟电商"], m_mapInStorageInfo[L"阔伟电商"]))
		return false;
	wstring fileName = L"./Export_" + m_strYM + L"/" + L"阔伟电商_" + m_strYM + L"对账单.xls";
	string _file = CFuncCommon::WString2String(fileName.c_str());
	CompareWhithWuLiu(L"阔伟电商", m_mapAllSalesInfo[L"阔伟电商"]);
	//计算相关费用
	{
		BasicExcelWorksheet* sheet = excel.GetWorksheet(L"订单费用");
		if(sheet)
		{
			std::list<sSalesInfo>& listSales = m_mapAllSalesInfo[L"阔伟电商"];
			std::list<sSalesInfo>::iterator itB = listSales.begin();
			std::list<sSalesInfo>::iterator itE = listSales.end();
			while(itB != itE)
			{
				wstring strBeiZhu = L"";
				int nWeight = 0;
				if(!IsZhengShu(itB->strZhongLiang))
				{
					double nZhongLiang = _wtof(itB->strZhongLiang.c_str());
					nZhongLiang += 1;
					nZhongLiang += DOUBLE_PRECISION;
					nWeight = int(nZhongLiang);
					wchar_t szWeight[10] = { 0 };
					_itow_s(nWeight, szWeight, 10);
					sheet->Cell(itB->nRow, eET_JiFeiZhongLiang)->SetWString(szWeight);
				}
				else
				{
					if(IsZero(itB->strZhongLiang))
						nWeight = 0;
					else
						nWeight = _wtoi(itB->strZhongLiang.c_str());
					wchar_t szWeight[10] = { 0 };
					_itow_s(nWeight, szWeight, 10);
					sheet->Cell(itB->nRow, eET_JiFeiZhongLiang)->SetWString(szWeight);
				}
				double dZengZhi = 0;
				//计算物流费
				{
					if(IsShunFengKuaiDi(itB->strWuLiuGongSi))
					{
						double money = GetSFPrice(nWeight, itB->strSheng, g_yongChuangYaoHuiSFPrice, itB->strWuLiuDanHao);
						double sourceBJ = 0;
						std::map<std::wstring, sSFAuthData>::iterator itSF = m_mapSFAuthData.find(itB->strWuLiuDanHao);
						if(itSF != m_mapSFAuthData.end())
							sourceBJ = _wtof(itSF->second.bjPay.c_str());
						if(itB->nBaoJiaJinE != 0)
						{
							dZengZhi += (itB->nBaoJiaJinE*0.003);
							if(dZengZhi < 1)
								dZengZhi = 0.0;
							else
							{
								if(strBeiZhu == L"")
									strBeiZhu = strBeiZhu + L"保价";
								else
									strBeiZhu = strBeiZhu + L" | 保价";
							}
						}
						else if(sourceBJ > DOUBLE_PRECISION)
						{
							dZengZhi += sourceBJ;
							if(strBeiZhu == L"")
								strBeiZhu = strBeiZhu + L"保价";
							else
								strBeiZhu = strBeiZhu + L" | 保价";
						}
						if(itSF != m_mapSFAuthData.end())
						{
							if(itSF->second.type != L"特惠专配" && itSF->second.type != L"电商标快")
							{
								std::set<std::wstring>::iterator itType = m_setSFOtherType.find(itSF->second.type);
								if(itType != m_setSFOtherType.end())
								{
									wchar_t szOut[120] = { 0 };
									_swprintf(szOut, L"顺丰出现异常产品类型[%s]", itSF->second.type.c_str());
									AddLog(szOut);
									m_setSFOtherType.insert(itSF->second.type);
								}
								double _needPay = _wtof(itSF->second.needPay.c_str());
								double _backPay = 0.0;
								double _bjPay = 0.0;
								if(itSF->second.backPay != L"")
									_backPay = _wtof(itSF->second.backPay.c_str());
								if(itSF->second.bjPay != L"")
									_bjPay = _wtof(itSF->second.bjPay.c_str());
								money = _needPay - _backPay - _bjPay + 3;
							}
							if(itSF->second.backPay != L"")
							{
								double backPay = _wtof(itSF->second.backPay.c_str());
								money += backPay;

								if(strBeiZhu == L"")
									strBeiZhu = strBeiZhu + L"转寄退回";
								else
									strBeiZhu = strBeiZhu + L" | 转寄退回";
							}
							double needPay = _wtof(itSF->second.needPay.c_str());
							if(needPay > money + dZengZhi)
							{
								std::set<std::wstring>::iterator it = m_setSFZhongLiangYiChang.find(itB->strWuLiuDanHao.c_str());
								if(it == m_setSFZhongLiangYiChang.end())
								{
									if(!m_bSFErrorPrice)
									{
										AddLog(L"顺丰费用有异常");
										m_bSFErrorPrice = true;
									}
									BasicExcelWorksheet* recordSheet = m_recordExcel.GetWorksheet(g_arrWorksheetName[2]);
									recordSheet->Cell(g_arrRecordRowIndex[2], 0)->SetWString(itB->strWuLiuDanHao.c_str());
									recordSheet->Cell(g_arrRecordRowIndex[2], 1)->SetWString(itB->strHuoZhu.c_str());
									g_arrRecordRowIndex[2]++;
								}
							}
						}

						sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1).c_str());


					}
					else if(IsZhongTongKuaiYun(itB->strWuLiuGongSi) || IsYunDaKuaiYun(itB->strWuLiuGongSi))
					{
						double money = GetKYPrice(nWeight, itB->strSheng, itB->strShi, g_yongChuangYaoHuiZTKYPrice, itB->strWuLiuDanHao);
						sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1).c_str());

						bool bSL = false;
						std::map<std::wstring, sZTKYAuthData>::iterator itZTKY = m_mapZTKYAuthData.find(itB->strWuLiuDanHao);
						if(itZTKY != m_mapZTKYAuthData.end())
						{
							double chengbenMoney = GetKYPrice(nWeight, itB->strSheng, itB->strShi, g_chengBenZTKYPrice, itB->strWuLiuDanHao);
							if(chengbenMoney + DOUBLE_PRECISION < itZTKY->second.yingShou - itZTKY->second.qita)
							{
								BasicExcelWorksheet* recordSheet = m_recordExcel.GetWorksheet(g_arrWorksheetName[5]);
								recordSheet->Cell(g_arrRecordRowIndex[5], 0)->SetWString(L"阔伟电商");
								recordSheet->Cell(g_arrRecordRowIndex[5], 1)->SetWString(itB->strWuLiuDanHao.c_str());
								recordSheet->Cell(g_arrRecordRowIndex[5], 2)->SetWString(CFuncCommon::Double2WString(itZTKY->second.yingShou - itZTKY->second.qita + DOUBLE_PRECISION, 1).c_str());
								recordSheet->Cell(g_arrRecordRowIndex[5], 3)->SetWString(CFuncCommon::Double2WString(chengbenMoney + DOUBLE_PRECISION, 1).c_str());
								g_arrRecordRowIndex[5]++;

								BasicExcelWorksheet* ztSheet = m_ztkyExcel.GetWorksheet(L"Sheet1");
								if(ztSheet)
									ztSheet->Cell(itZTKY->second.row, m_ztkyHandleCol)->SetWString(L"价格异常");
							}
							if(itZTKY->second.qita > DOUBLE_PRECISION)
							{
								dZengZhi += itZTKY->second.qita;
								if(strBeiZhu == L"")
									strBeiZhu = strBeiZhu + L"上楼";
								else
									strBeiZhu = strBeiZhu + L" | 上楼";
								bSL = true;
							}
						}
						if(!bSL)
						{
							if(nWeight > 50)
							{
								if(nWeight < 120)
									dZengZhi += (nWeight - 50)*0.1 + 10;
								else
									dZengZhi += (nWeight - 50)*0.1 + 30;
								if(strBeiZhu == L"")
									strBeiZhu = strBeiZhu + L"上楼";
								else
									strBeiZhu = strBeiZhu + L" | 上楼";
							}
						}
					}
					else if(IsYunDaKuaiDi(itB->strWuLiuGongSi))
					{
						double money = GetKDPrice(nWeight, itB->strSheng, itB->strShi, g_yongChuangYaoHuiKDPrice, L"韵达快递", itB->strWuLiuDanHao);
						sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1).c_str());
					}
					else
					{
						wchar_t szOut[120] = { 0 };
						_swprintf(szOut, L"[未知的物流方式] 货主=%s 单号=%s 物流公司=%s", itB->strHuoZhu.c_str(), itB->strWuLiuDanHao.c_str(), itB->strWuLiuGongSi.c_str());
						AddLog(szOut);
					}
				}
				sheet->Cell(itB->nRow, eET_CaoZuoFei)->SetWString(L"1.1");
				//计算增值费用
				{
					//云集贴标费
					if(itB->strYuanShiDanHao.size() >= 2)
					{
						wchar_t char1 = itB->strYuanShiDanHao.at(0);
						wchar_t char2 = itB->strYuanShiDanHao.at(1);
						if(char1 == L'S' && char2 == L'O')
						{
							dZengZhi += 0.3;
							if(strBeiZhu == L"")
								strBeiZhu = strBeiZhu + L"贴标";
							else
								strBeiZhu = strBeiZhu + L" | 贴标";
						}
					}
					if(dZengZhi > 0)
						sheet->Cell(itB->nRow, eET_ZengZhiFeiYong)->SetWString(CFuncCommon::Double2WString(dZengZhi + DOUBLE_PRECISION, 1).c_str());
				}
				sheet->Cell(itB->nRow, eET_BeiZhu)->SetWString(strBeiZhu.c_str());
				++itB;
			}
		}

	}
	excel.SaveAs(_file.c_str());
	AddLog(L"永创耀辉账单生成成功");
	return true;
}

bool CStorageBillDlg::Handle_JingXinGe()
{
	BasicExcel excel;
	if(!CreateExcel(L"静心阁", excel, m_mapAllSalesInfo[L"静心阁"], m_mapInStorageInfo[L"静心阁"]))
		return false;
	wstring fileName = L"./Export_" + m_strYM + L"/" + L"静心阁_" + m_strYM + L"对账单.xls";
	string _file = CFuncCommon::WString2String(fileName.c_str());
	CompareWhithWuLiu(L"静心阁", m_mapAllSalesInfo[L"静心阁"]);
	//计算相关费用
	{
		BasicExcelWorksheet* sheet = excel.GetWorksheet(L"订单费用");
		if(sheet)
		{
			std::list<sSalesInfo>& listSales = m_mapAllSalesInfo[L"静心阁"];
			std::list<sSalesInfo>::iterator itB = listSales.begin();
			std::list<sSalesInfo>::iterator itE = listSales.end();
			while(itB != itE)
			{
				wstring strBeiZhu = L"";
				int nWeight = 0;
				if(!IsZhengShu(itB->strZhongLiang))
				{
					double nZhongLiang = _wtof(itB->strZhongLiang.c_str());
					nZhongLiang += 1;
					nZhongLiang += DOUBLE_PRECISION;
					nWeight = int(nZhongLiang);
					wchar_t szWeight[10] = { 0 };
					_itow_s(nWeight, szWeight, 10);
					sheet->Cell(itB->nRow, eET_JiFeiZhongLiang)->SetWString(szWeight);
				}
				else
				{
					if(IsZero(itB->strZhongLiang))
						nWeight = 0;
					else
						nWeight = _wtoi(itB->strZhongLiang.c_str());
					wchar_t szWeight[10] = { 0 };
					_itow_s(nWeight, szWeight, 10);
					sheet->Cell(itB->nRow, eET_JiFeiZhongLiang)->SetWString(szWeight);
				}
				double dZengZhi = 0;
				//计算物流费
				{
					if(IsShunFengKuaiDi(itB->strWuLiuGongSi)  || IsYunDaKuaiDi(itB->strWuLiuGongSi))
					{
						double money = 0;
						if(nWeight > 0)
						{
							double money = GetKDPrice(nWeight, itB->strSheng, itB->strShi, g_jingXinGeYDKDPrice, L"韵达快递", itB->strWuLiuDanHao);
							sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1).c_str());
						}
					}
					else
					{
						wchar_t szOut[120] = { 0 };
						_swprintf(szOut, L"[未知的物流方式] 货主=%s 单号=%s 物流公司=%s", itB->strHuoZhu.c_str(), itB->strWuLiuDanHao.c_str(), itB->strWuLiuGongSi.c_str());
						AddLog(szOut);
					}
				}
				double _price = 0.4;
				int nZSL = _wtoi(itB->strHuoPinZongShuLiang.c_str());
				if(nZSL == 0)
				{
					wchar_t szOut[120] = { 0 };
					_swprintf(szOut, L"[异常货品数量] 货主=%s 单号=%s 物流公司=%s", itB->strHuoZhu.c_str(), itB->strWuLiuDanHao.c_str(), itB->strWuLiuGongSi.c_str());
					AddLog(szOut);
				}
				if(nZSL > 8)
					_price = 0.4 + (nZSL - 8)*0.1;
				else
					_price = 0.4;
				sheet->Cell(itB->nRow, eET_CaoZuoFei)->SetWString(CFuncCommon::Double2WString(_price + DOUBLE_PRECISION, 1).c_str());
				//计算增值费用
				{
					if(dZengZhi > 0)
						sheet->Cell(itB->nRow, eET_ZengZhiFeiYong)->SetWString(CFuncCommon::Double2WString(dZengZhi + DOUBLE_PRECISION, 1).c_str());
				}
				sheet->Cell(itB->nRow, eET_BeiZhu)->SetWString(strBeiZhu.c_str());
				++itB;
			}
		}
	}
	excel.SaveAs(_file.c_str());
	AddLog(L"静心阁账单生成成功");
	return true;
}

bool CStorageBillDlg::Handle_AiWeiEr()
{
	BasicExcel excel;
	if(!CreateExcel(L"艾维尔", excel, m_mapAllSalesInfo[L"艾维尔"], m_mapInStorageInfo[L"艾维尔"]))
		return false;
	wstring fileName = L"./Export_" + m_strYM + L"/" + L"艾维尔_" + m_strYM + L"对账单.xls";
	string _file = CFuncCommon::WString2String(fileName.c_str());
	CompareWhithWuLiu(L"艾维尔", m_mapAllSalesInfo[L"艾维尔"]);
	//计算相关费用
	{
		BasicExcelWorksheet* sheet = excel.GetWorksheet(L"订单费用");
		if(sheet)
		{
			std::list<sSalesInfo>& listSales = m_mapAllSalesInfo[L"艾维尔"];
			std::list<sSalesInfo>::iterator itB = listSales.begin();
			std::list<sSalesInfo>::iterator itE = listSales.end();
			while(itB != itE)
			{
				wstring strBeiZhu = L"";
				int nWeight = 0;
				if(!IsZhengShu(itB->strZhongLiang))
				{
					double nZhongLiang = _wtof(itB->strZhongLiang.c_str());
					nZhongLiang += 1;
					nZhongLiang += DOUBLE_PRECISION;
					nWeight = int(nZhongLiang);
					if(nWeight < 3)
						nWeight = 3;
					wchar_t szWeight[10] = { 0 };
					_itow_s(nWeight, szWeight, 10);
					sheet->Cell(itB->nRow, eET_JiFeiZhongLiang)->SetWString(szWeight);
				}
				else
				{
					if(IsZero(itB->strZhongLiang))
						nWeight = 0;
					else
					{
						nWeight = _wtoi(itB->strZhongLiang.c_str());
						if(nWeight < 3)
							nWeight = 3;
					}
					wchar_t szWeight[10] = { 0 };
					_itow_s(nWeight, szWeight, 10);
					sheet->Cell(itB->nRow, eET_JiFeiZhongLiang)->SetWString(szWeight);
				}
				double dZengZhi = 0;
				//计算物流费
				{
					if(IsYunDaKuaiDi(itB->strWuLiuGongSi) || IsShunFengKuaiDi(itB->strWuLiuGongSi))
					{
						double money = 0;
						if(nWeight > 0)
						{
							double money = GetKDPrice(nWeight, itB->strSheng, itB->strShi, g_aiWeiErKDPrice, L"韵达快递", itB->strWuLiuDanHao);
							sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1).c_str());
						}
					}
					else
					{
						wchar_t szOut[120] = { 0 };
						_swprintf(szOut, L"[未知的物流方式] 货主=%s 单号=%s 物流公司=%s", itB->strHuoZhu.c_str(), itB->strWuLiuDanHao.c_str(), itB->strWuLiuGongSi.c_str());
						AddLog(szOut);
					}
				}
				double _price = 1;
				int nZSL = _wtoi(itB->strHuoPinZongShuLiang.c_str());
				if(nZSL == 0)
				{
					wchar_t szOut[120] = { 0 };
					_swprintf(szOut, L"[异常货品数量] 货主=%s 单号=%s 物流公司=%s", itB->strHuoZhu.c_str(), itB->strWuLiuDanHao.c_str(), itB->strWuLiuGongSi.c_str());
					AddLog(szOut);
				}
				if(nZSL > 5)
					_price = 0.7 + (nZSL - 5)*0.1;
				else
					_price = 0.7;
				sheet->Cell(itB->nRow, eET_CaoZuoFei)->SetWString(CFuncCommon::Double2WString(_price + DOUBLE_PRECISION, 1).c_str());
				//计算增值费用
				{
					if(dZengZhi > 0)
						sheet->Cell(itB->nRow, eET_ZengZhiFeiYong)->SetWString(CFuncCommon::Double2WString(dZengZhi + DOUBLE_PRECISION, 1).c_str());
				}
				sheet->Cell(itB->nRow, eET_BeiZhu)->SetWString(strBeiZhu.c_str());
				++itB;
			}
		}
	}
	excel.SaveAs(_file.c_str());
	AddLog(L"艾维尔账单生成成功");
	return true;
}

bool CStorageBillDlg::Handle_XiaoBaiXiong()
{
	BasicExcel excel;
	if(!CreateExcel(L"小白熊", excel, m_mapAllSalesInfo[L"小白熊"], m_mapInStorageInfo[L"小白熊"]))
		return false;
	wstring fileName = L"./Export_" + m_strYM + L"/" + L"小白熊_" + m_strYM + L"对账单.xls";
	string _file = CFuncCommon::WString2String(fileName.c_str());
	CompareWhithWuLiu(L"小白熊", m_mapAllSalesInfo[L"小白熊"]);
	//计算相关费用
	{
		BasicExcelWorksheet* sheet = excel.GetWorksheet(L"订单费用");
		if(sheet)
		{
			std::list<sSalesInfo>& listSales = m_mapAllSalesInfo[L"小白熊"];
			std::list<sSalesInfo>::iterator itB = listSales.begin();
			std::list<sSalesInfo>::iterator itE = listSales.end();
			while(itB != itE)
			{
				wstring strBeiZhu = L"";
				int nWeight = 0;
				if(!IsZhengShu(itB->strZhongLiang))
				{
					double nZhongLiang = _wtof(itB->strZhongLiang.c_str());
					nZhongLiang += 1;
					nZhongLiang += DOUBLE_PRECISION;
					nWeight = int(nZhongLiang);
					if(nWeight < 3)
						nWeight = 3;
					wchar_t szWeight[10] = { 0 };
					_itow_s(nWeight, szWeight, 10);
					sheet->Cell(itB->nRow, eET_JiFeiZhongLiang)->SetWString(szWeight);
				}
				else
				{
					if(IsZero(itB->strZhongLiang))
						nWeight = 0;
					else
					{
						nWeight = _wtoi(itB->strZhongLiang.c_str());
						if(nWeight < 3)
							nWeight = 3;
					}
					wchar_t szWeight[10] = { 0 };
					_itow_s(nWeight, szWeight, 10);
					sheet->Cell(itB->nRow, eET_JiFeiZhongLiang)->SetWString(szWeight);
				}
				double dZengZhi = 0;
				//计算物流费
				{
					if(IsYunDaKuaiDi(itB->strWuLiuGongSi) || IsShunFengKuaiDi(itB->strWuLiuGongSi))
					{
						double money = 0;
						if(nWeight > 0)
						{
							double money = GetKDPrice(nWeight, itB->strSheng, itB->strShi, g_xiaoBaiXiongKDPrice, L"韵达快递", itB->strWuLiuDanHao);
							sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1).c_str());
						}
					}
					else
					{
						wchar_t szOut[120] = { 0 };
						_swprintf(szOut, L"[未知的物流方式] 货主=%s 单号=%s 物流公司=%s", itB->strHuoZhu.c_str(), itB->strWuLiuDanHao.c_str(), itB->strWuLiuGongSi.c_str());
						AddLog(szOut);
					}
				}
				double _price = 1;
				int nZSL = _wtoi(itB->strHuoPinZongShuLiang.c_str());
				if(nZSL == 0)
				{
					wchar_t szOut[120] = { 0 };
					_swprintf(szOut, L"[异常货品数量] 货主=%s 单号=%s 物流公司=%s", itB->strHuoZhu.c_str(), itB->strWuLiuDanHao.c_str(), itB->strWuLiuGongSi.c_str());
					AddLog(szOut);
				}
				if(nZSL > 5)
					_price = 0.7 + (nZSL - 5)*0.1;
				else
					_price = 0.7;
				sheet->Cell(itB->nRow, eET_CaoZuoFei)->SetWString(CFuncCommon::Double2WString(_price + DOUBLE_PRECISION, 1).c_str());
				//计算增值费用
				{
					if(dZengZhi > 0)
						sheet->Cell(itB->nRow, eET_ZengZhiFeiYong)->SetWString(CFuncCommon::Double2WString(dZengZhi + DOUBLE_PRECISION, 1).c_str());
				}
				sheet->Cell(itB->nRow, eET_BeiZhu)->SetWString(strBeiZhu.c_str());
				++itB;
			}
		}
	}
	excel.SaveAs(_file.c_str());
	AddLog(L"小白熊账单生成成功");
	return true;
}


bool CStorageBillDlg::Handle_KaDuoGe()
{
	BasicExcel excel;
	if(!CreateExcel(L"卡多格", excel, m_mapAllSalesInfo[L"卡多格"], m_mapInStorageInfo[L"卡多格"]))
		return false;
	wstring fileName = L"./Export_" + m_strYM + L"/" + L"卡多格_" + m_strYM + L"对账单.xls";
	string _file = CFuncCommon::WString2String(fileName.c_str());
	CompareWhithWuLiu(L"卡多格", m_mapAllSalesInfo[L"卡多格"]);
	//计算相关费用
	{
		BasicExcelWorksheet* sheet = excel.GetWorksheet(L"订单费用");
		if(sheet)
		{
			std::list<sSalesInfo>& listSales = m_mapAllSalesInfo[L"卡多格"];
			std::list<sSalesInfo>::iterator itB = listSales.begin();
			std::list<sSalesInfo>::iterator itE = listSales.end();
			while(itB != itE)
			{
				wstring strBeiZhu = L"";
				int nWeight = 0;
				if(!IsZhengShu(itB->strZhongLiang))
				{
					double nZhongLiang = _wtof(itB->strZhongLiang.c_str());
					if(nZhongLiang > 3 && nZhongLiang < 5.5)
						nZhongLiang = nZhongLiang;
					else
					{
						nZhongLiang += 1;
						nZhongLiang += DOUBLE_PRECISION;
					}
					nWeight = int(nZhongLiang);
					wchar_t szWeight[10] = { 0 };
					_itow_s(nWeight, szWeight, 10);
					sheet->Cell(itB->nRow, eET_JiFeiZhongLiang)->SetWString(szWeight);
				}
				else
				{
					if(IsZero(itB->strZhongLiang))
						nWeight = 0;
					else
						nWeight = _wtoi(itB->strZhongLiang.c_str());
					wchar_t szWeight[10] = { 0 };
					_itow_s(nWeight, szWeight, 10);
					sheet->Cell(itB->nRow, eET_JiFeiZhongLiang)->SetWString(szWeight);
				}
				double dZengZhi = 0;
				//计算物流费
				{
					if(IsYunDaKuaiDi(itB->strWuLiuGongSi) || IsShunFengKuaiDi(itB->strWuLiuGongSi))
					{
						double money = 0;
						if(nWeight > 0)
						{
							double money = GetKDPrice(nWeight, itB->strSheng, itB->strShi, g_tuKaDuoGeKDPrice, L"韵达快递", itB->strWuLiuDanHao);
							sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1).c_str());
						}
					}
					else
					{
						wchar_t szOut[120] = { 0 };
						_swprintf(szOut, L"[未知的物流方式] 货主=%s 单号=%s 物流公司=%s", itB->strHuoZhu.c_str(), itB->strWuLiuDanHao.c_str(), itB->strWuLiuGongSi.c_str());
						AddLog(szOut);
					}
				}
				double _price = 1;
				int nZSL = _wtoi(itB->strHuoPinZongShuLiang.c_str());
				if(nZSL == 0)
				{
					wchar_t szOut[120] = { 0 };
					_swprintf(szOut, L"[异常货品数量] 货主=%s 单号=%s 物流公司=%s", itB->strHuoZhu.c_str(), itB->strWuLiuDanHao.c_str(), itB->strWuLiuGongSi.c_str());
					AddLog(szOut);
				}
				if(nZSL > 6)
					_price = 0.5 + (nZSL - 6)*0.1;
				else
					_price = 0.5;
				sheet->Cell(itB->nRow, eET_CaoZuoFei)->SetWString(CFuncCommon::Double2WString(_price + DOUBLE_PRECISION, 1).c_str());
				//计算增值费用
				{
					if(dZengZhi > 0)
						sheet->Cell(itB->nRow, eET_ZengZhiFeiYong)->SetWString(CFuncCommon::Double2WString(dZengZhi + DOUBLE_PRECISION, 1).c_str());
				}
				sheet->Cell(itB->nRow, eET_BeiZhu)->SetWString(strBeiZhu.c_str());
				++itB;
			}
		}
	}
	excel.SaveAs(_file.c_str());
	AddLog(L"卡多格账单生成成功");
	return true;
}

bool CStorageBillDlg::Handle_XingXingShaoNv()
{
	BasicExcel excel;
	if(!CreateExcel(L"星星少女零食", excel, m_mapAllSalesInfo[L"星星少女零食"], m_mapInStorageInfo[L"星星少女零食"]))
		return false;
	wstring fileName = L"./Export_" + m_strYM + L"/" + L"星星少女零食_" + m_strYM + L"对账单.xls";
	string _file = CFuncCommon::WString2String(fileName.c_str());
	CompareWhithWuLiu(L"星星少女零食", m_mapAllSalesInfo[L"星星少女零食"]);
	//计算相关费用
	{
		BasicExcelWorksheet* sheet = excel.GetWorksheet(L"订单费用");
		if(sheet)
		{
			double kouJian = 0;
			std::list<sSalesInfo>& listSales = m_mapAllSalesInfo[L"星星少女零食"];
			if(listSales.size() > 5000)
				kouJian = 0.1;
			else if(listSales.size() > 15000)
				kouJian = 0.2;
			std::list<sSalesInfo>::iterator itB = listSales.begin();
			std::list<sSalesInfo>::iterator itE = listSales.end();
			while(itB != itE)
			{
				wstring strBeiZhu = L"";
				int nWeight = 0;
				if(!IsZhengShu(itB->strZhongLiang))
				{
					double nZhongLiang = _wtof(itB->strZhongLiang.c_str());
					nZhongLiang += 1;
					nZhongLiang += DOUBLE_PRECISION;
					nWeight = int(nZhongLiang);
					wchar_t szWeight[10] = { 0 };
					_itow_s(nWeight, szWeight, 10);
					sheet->Cell(itB->nRow, eET_JiFeiZhongLiang)->SetWString(szWeight);
				}
				else
				{
					if(IsZero(itB->strZhongLiang))
						nWeight = 0;
					else
						nWeight = _wtoi(itB->strZhongLiang.c_str());
					wchar_t szWeight[10] = { 0 };
					_itow_s(nWeight, szWeight, 10);
					sheet->Cell(itB->nRow, eET_JiFeiZhongLiang)->SetWString(szWeight);
				}
				double dZengZhi = 0;
				//计算物流费
				{
					if(IsYunDaKuaiDi(itB->strWuLiuGongSi))
					{
						double money = 0;
						if(nWeight > 0)
						{
							double money = GetKDPrice(nWeight, itB->strSheng, itB->strShi, g_xingXingShaoNvKDPrice, L"韵达快递", itB->strWuLiuDanHao);
							money -= kouJian;
							sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1).c_str());
						}
					}
					else
					{
						wchar_t szOut[120] = { 0 };
						_swprintf(szOut, L"[未知的物流方式] 货主=%s 单号=%s 物流公司=%s", itB->strHuoZhu.c_str(), itB->strWuLiuDanHao.c_str(), itB->strWuLiuGongSi.c_str());
						AddLog(szOut);
					}
				}
				double _price = 1;
				int nZSL = _wtoi(itB->strHuoPinZongShuLiang.c_str());
				if(nZSL == 0)
				{
					wchar_t szOut[120] = { 0 };
					_swprintf(szOut, L"[异常货品数量] 货主=%s 单号=%s 物流公司=%s", itB->strHuoZhu.c_str(), itB->strWuLiuDanHao.c_str(), itB->strWuLiuGongSi.c_str());
					AddLog(szOut);
				}
				if(nZSL > 8)
					_price = 0.5 + (nZSL - 8)*0.1;
				else
					_price = 0.5;
				sheet->Cell(itB->nRow, eET_CaoZuoFei)->SetWString(CFuncCommon::Double2WString(_price + DOUBLE_PRECISION, 1).c_str());
				double haocaifei = 0.0;
				if(nZSL >= 2)
					haocaifei += 0.25;
				else if(itB->strHuoPinMingXi.find(L"蛋黄瓦格饼") != wstring::npos)
					haocaifei += 0.02;
				sheet->Cell(itB->nRow, eET_HaoCaiFei)->SetWString(CFuncCommon::Double2WString(haocaifei + DOUBLE_PRECISION, 2).c_str());
				//计算增值费用
				{
					if(dZengZhi > 0)
						sheet->Cell(itB->nRow, eET_ZengZhiFeiYong)->SetWString(CFuncCommon::Double2WString(dZengZhi + DOUBLE_PRECISION, 1).c_str());
				}
				sheet->Cell(itB->nRow, eET_BeiZhu)->SetWString(strBeiZhu.c_str());
				++itB;
			}
		}
	}
	excel.SaveAs(_file.c_str());
	AddLog(L"星星少女零食账单生成成功");
	return true;
}
bool CStorageBillDlg::Handle_ChuJianNingMengCha()
{
	BasicExcel excel;
	if(!CreateExcel(L"初见柠檬茶", excel, m_mapAllSalesInfo[L"初见柠檬茶"], m_mapInStorageInfo[L"初见柠檬茶"]))
		return false;
	wstring fileName = L"./Export_" + m_strYM + L"/" + L"初见柠檬茶_" + m_strYM + L"对账单.xls";
	string _file = CFuncCommon::WString2String(fileName.c_str());
	CompareWhithWuLiu(L"初见柠檬茶", m_mapAllSalesInfo[L"初见柠檬茶"]);
	//计算相关费用
	{
		BasicExcelWorksheet* sheet = excel.GetWorksheet(L"订单费用");
		if(sheet)
		{
			std::list<sSalesInfo>& listSales = m_mapAllSalesInfo[L"初见柠檬茶"];
			std::list<sSalesInfo>::iterator itB = listSales.begin();
			std::list<sSalesInfo>::iterator itE = listSales.end();
			while(itB != itE)
			{
				wstring strBeiZhu = L"";
				int nWeight = 0;
				if(!IsZhengShu(itB->strZhongLiang))
				{
					double nZhongLiang = _wtof(itB->strZhongLiang.c_str());
					nZhongLiang += 1;
					nZhongLiang += DOUBLE_PRECISION;
					nWeight = int(nZhongLiang);
					if(nWeight < 3)
						nWeight = 3;
					wchar_t szWeight[10] = { 0 };
					_itow_s(nWeight, szWeight, 10);
					sheet->Cell(itB->nRow, eET_JiFeiZhongLiang)->SetWString(szWeight);
				}
				else
				{
					if(IsZero(itB->strZhongLiang))
						nWeight = 0;
					else
					{
						nWeight = _wtoi(itB->strZhongLiang.c_str());
						if(nWeight < 3)
							nWeight = 3;
					}
					wchar_t szWeight[10] = { 0 };
					_itow_s(nWeight, szWeight, 10);
					sheet->Cell(itB->nRow, eET_JiFeiZhongLiang)->SetWString(szWeight);
				}
				double dZengZhi = 0;
				//计算物流费
				{
					if(IsYunDaKuaiDi(itB->strWuLiuGongSi) || IsShunFengKuaiDi(itB->strWuLiuGongSi))
					{
						double money = 0;
						if(nWeight > 0)
						{
							double money = GetKDPrice(nWeight, itB->strSheng, itB->strShi, g_chuJianNingMengChaKDPrice, L"韵达快递", itB->strWuLiuDanHao);
							sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1).c_str());
						}
					}
					else
					{
						wchar_t szOut[120] = { 0 };
						_swprintf(szOut, L"[未知的物流方式] 货主=%s 单号=%s 物流公司=%s", itB->strHuoZhu.c_str(), itB->strWuLiuDanHao.c_str(), itB->strWuLiuGongSi.c_str());
						AddLog(szOut);
					}
				}
				double _price = 1;
				int nZSL = _wtoi(itB->strHuoPinZongShuLiang.c_str());
				if(nZSL == 0)
				{
					wchar_t szOut[120] = { 0 };
					_swprintf(szOut, L"[异常货品数量] 货主=%s 单号=%s 物流公司=%s", itB->strHuoZhu.c_str(), itB->strWuLiuDanHao.c_str(), itB->strWuLiuGongSi.c_str());
					AddLog(szOut);
				}
				if(nZSL > 5)
					_price = 0.6 + (nZSL - 5)*0.1;
				else
					_price = 0.6;
				sheet->Cell(itB->nRow, eET_CaoZuoFei)->SetWString(CFuncCommon::Double2WString(_price + DOUBLE_PRECISION, 1).c_str());
				//计算增值费用
				{
					if(dZengZhi > 0)
						sheet->Cell(itB->nRow, eET_ZengZhiFeiYong)->SetWString(CFuncCommon::Double2WString(dZengZhi + DOUBLE_PRECISION, 1).c_str());
				}
				sheet->Cell(itB->nRow, eET_BeiZhu)->SetWString(strBeiZhu.c_str());
				++itB;
			}
		}
	}
	excel.SaveAs(_file.c_str());
	AddLog(L"初见柠檬茶账单生成成功");
	return true;
}

bool CStorageBillDlg::Handle_TuNiangNiang()
{
	BasicExcel excel;
	if(!CreateExcel(L"兔娘娘", excel, m_mapAllSalesInfo[L"兔娘娘"], m_mapInStorageInfo[L"兔娘娘"]))
		return false;
	wstring fileName = L"./Export_" + m_strYM + L"/" + L"兔娘娘_" + m_strYM + L"对账单.xls";
	string _file = CFuncCommon::WString2String(fileName.c_str());
	CompareWhithWuLiu(L"兔娘娘", m_mapAllSalesInfo[L"兔娘娘"]);
	//计算相关费用
	{
		BasicExcelWorksheet* sheet = excel.GetWorksheet(L"订单费用");
		if(sheet)
		{
			std::list<sSalesInfo>& listSales = m_mapAllSalesInfo[L"兔娘娘"];
			std::list<sSalesInfo>::iterator itB = listSales.begin();
			std::list<sSalesInfo>::iterator itE = listSales.end();
			while(itB != itE)
			{
				wstring strBeiZhu = L"";
				int nWeight = 0;
				if(!IsZhengShu(itB->strZhongLiang))
				{
					double nZhongLiang = _wtof(itB->strZhongLiang.c_str());
					nZhongLiang += 1;
					nZhongLiang += DOUBLE_PRECISION;
					nWeight = int(nZhongLiang);
					wchar_t szWeight[10] = { 0 };
					_itow_s(nWeight, szWeight, 10);
					sheet->Cell(itB->nRow, eET_JiFeiZhongLiang)->SetWString(szWeight);
				}
				else
				{
					if(IsZero(itB->strZhongLiang))
						nWeight = 0;
					else
						nWeight = _wtoi(itB->strZhongLiang.c_str());
					wchar_t szWeight[10] = { 0 };
					_itow_s(nWeight, szWeight, 10);
					sheet->Cell(itB->nRow, eET_JiFeiZhongLiang)->SetWString(szWeight);
				}
				double dZengZhi = 0;
				double dCaoZuoFei = 1;
				int nZSL = _wtoi(itB->strHuoPinZongShuLiang.c_str());
				if(nZSL == 0)
				{
					wchar_t szOut[120] = { 0 };
					_swprintf(szOut, L"[异常货品数量] 货主=%s 单号=%s 物流公司=%s", itB->strHuoZhu.c_str(), itB->strWuLiuDanHao.c_str(), itB->strWuLiuGongSi.c_str());
					AddLog(szOut);
				}
				//计算物流费
				{
					if(IsYunDaKuaiDi(itB->strWuLiuGongSi) || IsShunFengKuaiDi(itB->strWuLiuGongSi))
					{
						double money = 0;
						if(nWeight > 0)
						{
							double money = GetKDPrice(nWeight, itB->strSheng, itB->strShi, g_tuNiangNiangKDPrice, L"韵达快递", itB->strWuLiuDanHao);
							sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1).c_str());
						}
						if(nZSL > 6)
							dCaoZuoFei = 0.6 + (nZSL - 6)*0.1;
						else
							dCaoZuoFei = 0.6;
					}
					else if(IsShunFengKongYun(itB->strWuLiuGongSi))
					{
						if(nZSL > 6)
							dCaoZuoFei = 0.8 + (nZSL - 6)*0.1;
						else
							dCaoZuoFei = 0.8;
					}
					else
					{
						wchar_t szOut[120] = { 0 };
						_swprintf(szOut, L"[未知的物流方式] 货主=%s 单号=%s 物流公司=%s", itB->strHuoZhu.c_str(), itB->strWuLiuDanHao.c_str(), itB->strWuLiuGongSi.c_str());
						AddLog(szOut);
					}
				}
				sheet->Cell(itB->nRow, eET_CaoZuoFei)->SetWString(CFuncCommon::Double2WString(dCaoZuoFei + DOUBLE_PRECISION, 1).c_str());
				//计算增值费用
				{
					if(dZengZhi > 0)
						sheet->Cell(itB->nRow, eET_ZengZhiFeiYong)->SetWString(CFuncCommon::Double2WString(dZengZhi + DOUBLE_PRECISION, 1).c_str());
				}
				sheet->Cell(itB->nRow, eET_BeiZhu)->SetWString(strBeiZhu.c_str());
				++itB;
			}
		}
	}
	excel.SaveAs(_file.c_str());
	AddLog(L"兔娘娘账单生成成功");
	return true;
}

bool CStorageBillDlg::Handle_QuLvShouNa()
{
	BasicExcel excel;
	if(!CreateExcel(L"趣旅收纳", excel, m_mapAllSalesInfo[L"趣旅收纳"], m_mapInStorageInfo[L"趣旅收纳"]))
		return false;
	wstring fileName = L"./Export_" + m_strYM + L"/" + L"趣旅收纳_" + m_strYM + L"对账单.xls";
	string _file = CFuncCommon::WString2String(fileName.c_str());
	CompareWhithWuLiu(L"趣旅收纳", m_mapAllSalesInfo[L"趣旅收纳"]);
	//计算相关费用
	{
		BasicExcelWorksheet* sheet = excel.GetWorksheet(L"订单费用");
		if(sheet)
		{
			std::list<sSalesInfo>& listSales = m_mapAllSalesInfo[L"趣旅收纳"];
			std::list<sSalesInfo>::iterator itB = listSales.begin();
			std::list<sSalesInfo>::iterator itE = listSales.end();
			while(itB != itE)
			{
				wstring strBeiZhu = L"";
				int nWeight = 0;
				if(!IsZhengShu(itB->strZhongLiang))
				{
					double nZhongLiang = _wtof(itB->strZhongLiang.c_str());
					nZhongLiang += 1;
					nZhongLiang += DOUBLE_PRECISION;
					nWeight = int(nZhongLiang);
					if(nWeight < 3)
						nWeight = 3;
					wchar_t szWeight[10] = { 0 };
					_itow_s(nWeight, szWeight, 10);
					sheet->Cell(itB->nRow, eET_JiFeiZhongLiang)->SetWString(szWeight);
				}
				else
				{
					if(IsZero(itB->strZhongLiang))
						nWeight = 0;
					else
					{
						nWeight = _wtoi(itB->strZhongLiang.c_str());
						if(nWeight < 3)
							nWeight = 3;
					}
					wchar_t szWeight[10] = { 0 };
					_itow_s(nWeight, szWeight, 10);
					sheet->Cell(itB->nRow, eET_JiFeiZhongLiang)->SetWString(szWeight);
				}
				double dZengZhi = 0;
				//计算物流费
				{
					if(IsShunFengKuaiDi(itB->strWuLiuGongSi))
					{
						double money = GetSFPrice(nWeight, itB->strSheng, g_quLvShouNaSFPrice, itB->strWuLiuDanHao);
						double sourceBJ = 0;
						std::map<std::wstring, sSFAuthData>::iterator itSF = m_mapSFAuthData.find(itB->strWuLiuDanHao);
						if(itSF != m_mapSFAuthData.end())
							sourceBJ = _wtof(itSF->second.bjPay.c_str());
						if(itB->nBaoJiaJinE != 0)
						{
							dZengZhi += (itB->nBaoJiaJinE*0.003);
							if(dZengZhi < 1)
								dZengZhi = 0.0;
							else
							{
								if(strBeiZhu == L"")
									strBeiZhu = strBeiZhu + L"保价";
								else
									strBeiZhu = strBeiZhu + L" | 保价";
							}
						}
						else if(sourceBJ > DOUBLE_PRECISION)
						{
							dZengZhi += sourceBJ;
							if(strBeiZhu == L"")
								strBeiZhu = strBeiZhu + L"保价";
							else
								strBeiZhu = strBeiZhu + L" | 保价";
						}

						if(itSF != m_mapSFAuthData.end())
						{
							if(itSF->second.type != L"特惠专配" && itSF->second.type != L"电商标快")
							{
								std::set<std::wstring>::iterator itType = m_setSFOtherType.find(itSF->second.type);
								if(itType != m_setSFOtherType.end())
								{
									wchar_t szOut[120] = { 0 };
									_swprintf(szOut, L"顺丰出现异常产品类型[%s]", itSF->second.type.c_str());
									AddLog(szOut);
									m_setSFOtherType.insert(itSF->second.type);
								}
								double _needPay = _wtof(itSF->second.needPay.c_str());
								double _backPay = 0.0;
								double _bjPay = 0.0;
								if(itSF->second.backPay != L"")
									_backPay = _wtof(itSF->second.backPay.c_str());
								if(itSF->second.bjPay != L"")
									_bjPay = _wtof(itSF->second.bjPay.c_str());
								money = _needPay - _backPay - _bjPay + 3;
							}
							if(itSF->second.backPay != L"")
							{
								double backPay = _wtof(itSF->second.backPay.c_str());
								money += backPay;

								if(strBeiZhu == L"")
									strBeiZhu = strBeiZhu + L"转寄退回";
								else
									strBeiZhu = strBeiZhu + L" | 转寄退回";
							}
							double needPay = _wtof(itSF->second.needPay.c_str());
							if(needPay > money + dZengZhi)
							{
								std::set<std::wstring>::iterator it = m_setSFZhongLiangYiChang.find(itB->strWuLiuDanHao.c_str());
								if(it == m_setSFZhongLiangYiChang.end())
								{
									if(!m_bSFErrorPrice)
									{
										AddLog(L"顺丰费用有异常");
										m_bSFErrorPrice = true;
									}
									BasicExcelWorksheet* recordSheet = m_recordExcel.GetWorksheet(g_arrWorksheetName[2]);
									recordSheet->Cell(g_arrRecordRowIndex[2], 0)->SetWString(itB->strWuLiuDanHao.c_str());
									recordSheet->Cell(g_arrRecordRowIndex[2], 1)->SetWString(itB->strHuoZhu.c_str());
									g_arrRecordRowIndex[2]++;
								}
							}
						}

						sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1).c_str());
					}
					else if(IsYunDaKuaiDi(itB->strWuLiuGongSi))
					{
						double money = 0;
						if(nWeight > 0)
						{
							double money = GetKDPrice(nWeight, itB->strSheng, itB->strShi, g_quLvShouNaKDPrice, L"韵达快递", itB->strWuLiuDanHao);
							sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1).c_str());
						}
					}
					else
					{
						wchar_t szOut[120] = { 0 };
						_swprintf(szOut, L"[未知的物流方式] 货主=%s 单号=%s 物流公司=%s", itB->strHuoZhu.c_str(), itB->strWuLiuDanHao.c_str(), itB->strWuLiuGongSi.c_str());
						AddLog(szOut);
					}
				}
				double _price = 1;
				int nZSL = _wtoi(itB->strHuoPinZongShuLiang.c_str());
				if(nZSL == 0)
				{
					wchar_t szOut[120] = { 0 };
					_swprintf(szOut, L"[异常货品数量] 货主=%s 单号=%s 物流公司=%s", itB->strHuoZhu.c_str(), itB->strWuLiuDanHao.c_str(), itB->strWuLiuGongSi.c_str());
					AddLog(szOut);
				}
				if(nZSL > 8)
					_price = 1 + (nZSL - 8)*0.1;
				else
					_price = 1;
				sheet->Cell(itB->nRow, eET_CaoZuoFei)->SetWString(CFuncCommon::Double2WString(_price + DOUBLE_PRECISION, 1).c_str());
				//计算增值费用
				{
					if(dZengZhi > 0)
						sheet->Cell(itB->nRow, eET_ZengZhiFeiYong)->SetWString(CFuncCommon::Double2WString(dZengZhi + DOUBLE_PRECISION, 1).c_str());
				}
				sheet->Cell(itB->nRow, eET_BeiZhu)->SetWString(strBeiZhu.c_str());
				++itB;
			}
		}
	}
	excel.SaveAs(_file.c_str());
	AddLog(L"趣旅收纳账单生成成功");
	return true;
}

bool CStorageBillDlg::Handle_ShuoGuoLiuXiang()
{
	BasicExcel excel;
	if(!CreateExcel(L"硕果流香", excel, m_mapAllSalesInfo[L"硕果流香"], m_mapInStorageInfo[L"硕果流香"]))
		return false;
	wstring fileName = L"./Export_" + m_strYM + L"/" + L"硕果流香_" + m_strYM + L"对账单.xls";
	string _file = CFuncCommon::WString2String(fileName.c_str());
	CompareWhithWuLiu(L"硕果流香", m_mapAllSalesInfo[L"硕果流香"]);
	//计算相关费用
	{
		BasicExcelWorksheet* sheet = excel.GetWorksheet(L"订单费用");
		if(sheet)
		{
			std::list<sSalesInfo>& listSales = m_mapAllSalesInfo[L"硕果流香"];
			std::list<sSalesInfo>::iterator itB = listSales.begin();
			std::list<sSalesInfo>::iterator itE = listSales.end();
			while(itB != itE)
			{
				wstring strBeiZhu = L"";
				int nWeight = 0;
				if(!IsZhengShu(itB->strZhongLiang))
				{
					double nZhongLiang = _wtof(itB->strZhongLiang.c_str());
					nZhongLiang += 1;
					nZhongLiang += DOUBLE_PRECISION;
					nWeight = int(nZhongLiang);
					if(nWeight < 3)
						nWeight = 3;
					wchar_t szWeight[10] = { 0 };
					_itow_s(nWeight, szWeight, 10);
					sheet->Cell(itB->nRow, eET_JiFeiZhongLiang)->SetWString(szWeight);
				}
				else
				{
					if(IsZero(itB->strZhongLiang))
						nWeight = 0;
					else
					{
						nWeight = _wtoi(itB->strZhongLiang.c_str());
						if(nWeight < 3)
							nWeight = 3;
					}
					wchar_t szWeight[10] = { 0 };
					_itow_s(nWeight, szWeight, 10);
					sheet->Cell(itB->nRow, eET_JiFeiZhongLiang)->SetWString(szWeight);
				}
				double dZengZhi = 0;
				//计算物流费
				{
					if(IsShunFengKuaiDi(itB->strWuLiuGongSi))
					{
						double money = GetSFPrice(nWeight, itB->strSheng, g_shuoGuoLiuXiangSFPrice, itB->strWuLiuDanHao);
						double sourceBJ = 0;
						std::map<std::wstring, sSFAuthData>::iterator itSF = m_mapSFAuthData.find(itB->strWuLiuDanHao);
						if(itSF != m_mapSFAuthData.end())
							sourceBJ = _wtof(itSF->second.bjPay.c_str());
						if(itB->nBaoJiaJinE != 0)
						{
							dZengZhi += (itB->nBaoJiaJinE*0.003);
							if(dZengZhi < 1)
								dZengZhi = 0.0;
							else
							{
								if(strBeiZhu == L"")
									strBeiZhu = strBeiZhu + L"保价";
								else
									strBeiZhu = strBeiZhu + L" | 保价";
							}
						}
						else if(sourceBJ > DOUBLE_PRECISION)
						{
							dZengZhi += sourceBJ;
							if(strBeiZhu == L"")
								strBeiZhu = strBeiZhu + L"保价";
							else
								strBeiZhu = strBeiZhu + L" | 保价";
						}

						if(itSF != m_mapSFAuthData.end())
						{
							if(itSF->second.type != L"特惠专配" && itSF->second.type != L"电商标快")
							{
								std::set<std::wstring>::iterator itType = m_setSFOtherType.find(itSF->second.type);
								if(itType != m_setSFOtherType.end())
								{
									wchar_t szOut[120] = { 0 };
									_swprintf(szOut, L"顺丰出现异常产品类型[%s]", itSF->second.type.c_str());
									AddLog(szOut);
									m_setSFOtherType.insert(itSF->second.type);
								}
								double _needPay = _wtof(itSF->second.needPay.c_str());
								double _backPay = 0.0;
								double _bjPay = 0.0;
								if(itSF->second.backPay != L"")
									_backPay = _wtof(itSF->second.backPay.c_str());
								if(itSF->second.bjPay != L"")
									_bjPay = _wtof(itSF->second.bjPay.c_str());
								money = _needPay - _backPay - _bjPay + 3;
							}
							if(itSF->second.backPay != L"")
							{
								double backPay = _wtof(itSF->second.backPay.c_str());
								money += backPay;

								if(strBeiZhu == L"")
									strBeiZhu = strBeiZhu + L"转寄退回";
								else
									strBeiZhu = strBeiZhu + L" | 转寄退回";
							}
							double needPay = _wtof(itSF->second.needPay.c_str());
							if(needPay > money + dZengZhi)
							{
								std::set<std::wstring>::iterator it = m_setSFZhongLiangYiChang.find(itB->strWuLiuDanHao.c_str());
								if(it == m_setSFZhongLiangYiChang.end())
								{
									if(!m_bSFErrorPrice)
									{
										AddLog(L"顺丰费用有异常");
										m_bSFErrorPrice = true;
									}
									BasicExcelWorksheet* recordSheet = m_recordExcel.GetWorksheet(g_arrWorksheetName[2]);
									recordSheet->Cell(g_arrRecordRowIndex[2], 0)->SetWString(itB->strWuLiuDanHao.c_str());
									recordSheet->Cell(g_arrRecordRowIndex[2], 1)->SetWString(itB->strHuoZhu.c_str());
									g_arrRecordRowIndex[2]++;
								}
							}
						}

						sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1).c_str());
					}
					else if(IsYunDaKuaiDi(itB->strWuLiuGongSi))
					{
						double money = 0;
						if(nWeight > 0)
						{
							double money = GetKDPrice(nWeight, itB->strSheng, itB->strShi, g_shuoGuoLiuXiangKDPrice, L"韵达快递", itB->strWuLiuDanHao);
							sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1).c_str());
						}
					}
					else
					{
						wchar_t szOut[120] = { 0 };
						_swprintf(szOut, L"[未知的物流方式] 货主=%s 单号=%s 物流公司=%s", itB->strHuoZhu.c_str(), itB->strWuLiuDanHao.c_str(), itB->strWuLiuGongSi.c_str());
						AddLog(szOut);
					}
				}
				double _price = 0.70;
				int nZSL = _wtoi(itB->strHuoPinZongShuLiang.c_str());
				if(nZSL == 0)
				{
					wchar_t szOut[120] = { 0 };
					_swprintf(szOut, L"[异常货品数量] 货主=%s 单号=%s 物流公司=%s", itB->strHuoZhu.c_str(), itB->strWuLiuDanHao.c_str(), itB->strWuLiuGongSi.c_str());
					AddLog(szOut);
				}
				if(nZSL > 6)
					_price = 0.70 + (nZSL - 6)*0.1;
				else
					_price = 0.70;
				sheet->Cell(itB->nRow, eET_CaoZuoFei)->SetWString(CFuncCommon::Double2WString(_price + DOUBLE_PRECISION, 1).c_str());
				//计算增值费用
				{
					if(dZengZhi > 0)
						sheet->Cell(itB->nRow, eET_ZengZhiFeiYong)->SetWString(CFuncCommon::Double2WString(dZengZhi + DOUBLE_PRECISION, 1).c_str());
				}
				sheet->Cell(itB->nRow, eET_BeiZhu)->SetWString(strBeiZhu.c_str());
				++itB;
			}
		}
	}
	excel.SaveAs(_file.c_str());
	AddLog(L"硕果流香账单生成成功");
	return true;
}

bool CStorageBillDlg::Handle_HanTaiLang()
{
	CompareWhithWuLiu(L"韩太郎", m_mapAllSalesInfo[L"韩太郎"]);
	return true;
}

bool CStorageBillDlg::Handle_HaTeNengLiang()
{
	BasicExcel excel;
	if(!CreateExcel(L"哈特能量", excel, m_mapAllSalesInfo[L"哈特能量"], m_mapInStorageInfo[L"哈特能量"]))
		return false;
	wstring fileName = L"./Export_" + m_strYM + L"/" + L"哈特能量_" + m_strYM + L"对账单.xls";
	string _file = CFuncCommon::WString2String(fileName.c_str());
	CompareWhithWuLiu(L"哈特能量", m_mapAllSalesInfo[L"哈特能量"]);
	//计算相关费用
	{
		BasicExcelWorksheet* sheet = excel.GetWorksheet(L"订单费用");
		if(sheet)
		{
			std::list<sSalesInfo>& listSales = m_mapAllSalesInfo[L"哈特能量"];
			std::list<sSalesInfo>::iterator itB = listSales.begin();
			std::list<sSalesInfo>::iterator itE = listSales.end();
			while(itB != itE)
			{
				wstring strBeiZhu = L"";
				int nWeight = 0;
				if(!IsZhengShu(itB->strZhongLiang))
				{
					double nZhongLiang = _wtof(itB->strZhongLiang.c_str());
					nZhongLiang += 1;
					nZhongLiang += DOUBLE_PRECISION;
					nWeight = int(nZhongLiang);
					wchar_t szWeight[10] = { 0 };
					_itow_s(nWeight, szWeight, 10);
					sheet->Cell(itB->nRow, eET_JiFeiZhongLiang)->SetWString(szWeight);
				}
				else
				{
					if(IsZero(itB->strZhongLiang))
						nWeight = 0;
					else
						nWeight = _wtoi(itB->strZhongLiang.c_str());
					wchar_t szWeight[10] = { 0 };
					_itow_s(nWeight, szWeight, 10);
					sheet->Cell(itB->nRow, eET_JiFeiZhongLiang)->SetWString(szWeight);
				}
				double dZengZhi = 0;
				//计算物流费
				{
					if(IsShunFengKuaiDi(itB->strWuLiuGongSi))
					{
						double money = GetSFPrice(nWeight, itB->strSheng, g_yongChuangYaoHuiSFPrice, itB->strWuLiuDanHao);
						double sourceBJ = 0;
						std::map<std::wstring, sSFAuthData>::iterator itSF = m_mapSFAuthData.find(itB->strWuLiuDanHao);
						if(itSF != m_mapSFAuthData.end())
							sourceBJ = _wtof(itSF->second.bjPay.c_str());
						if(itB->nBaoJiaJinE != 0)
						{
							dZengZhi += (itB->nBaoJiaJinE*0.003);
							if(dZengZhi < 1)
								dZengZhi = 0.0;
							else
							{
								if(strBeiZhu == L"")
									strBeiZhu = strBeiZhu + L"保价";
								else
									strBeiZhu = strBeiZhu + L" | 保价";
							}
						}
						else if(sourceBJ > DOUBLE_PRECISION)
						{
							dZengZhi += sourceBJ;
							if(strBeiZhu == L"")
								strBeiZhu = strBeiZhu + L"保价";
							else
								strBeiZhu = strBeiZhu + L" | 保价";
						}
						//if(sourceBJ > DOUBLE_PRECISION && sourceBJ > dZengZhi)
						//	dZengZhi = sourceBJ;
						if(itSF != m_mapSFAuthData.end())
						{
							if(itSF->second.type != L"特惠专配" && itSF->second.type != L"电商标快")
							{
								std::set<std::wstring>::iterator itType = m_setSFOtherType.find(itSF->second.type);
								if(itType != m_setSFOtherType.end())
								{
									wchar_t szOut[120] = { 0 };
									_swprintf(szOut, L"顺丰出现异常产品类型[%s]", itSF->second.type.c_str());
									AddLog(szOut);
									m_setSFOtherType.insert(itSF->second.type);
								}
								double _needPay = _wtof(itSF->second.needPay.c_str());
								double _backPay = 0.0;
								double _bjPay = 0.0;
								if(itSF->second.backPay != L"")
									_backPay = _wtof(itSF->second.backPay.c_str());
								if(itSF->second.bjPay != L"")
									_bjPay = _wtof(itSF->second.bjPay.c_str());
								money = _needPay - _backPay - _bjPay + 3;
							}
							if(itSF->second.backPay != L"")
							{
								double backPay = _wtof(itSF->second.backPay.c_str());
								money += backPay;

								if(strBeiZhu == L"")
									strBeiZhu = strBeiZhu + L"转寄退回";
								else
									strBeiZhu = strBeiZhu + L" | 转寄退回";
							}
							double needPay = _wtof(itSF->second.needPay.c_str());
							if(needPay > money + dZengZhi)
							{
								std::set<std::wstring>::iterator it = m_setSFZhongLiangYiChang.find(itB->strWuLiuDanHao.c_str());
								if(it == m_setSFZhongLiangYiChang.end())
								{
									if(!m_bSFErrorPrice)
									{
										AddLog(L"顺丰费用有异常");
										m_bSFErrorPrice = true;
									}
									BasicExcelWorksheet* recordSheet = m_recordExcel.GetWorksheet(g_arrWorksheetName[2]);
									recordSheet->Cell(g_arrRecordRowIndex[2], 0)->SetWString(itB->strWuLiuDanHao.c_str());
									recordSheet->Cell(g_arrRecordRowIndex[2], 1)->SetWString(itB->strHuoZhu.c_str());
									g_arrRecordRowIndex[2]++;
								}
							}
						}

						sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1).c_str());


					}
					else if(IsBaiShiKuaiYun(itB->strWuLiuGongSi))
						sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(L"2.5");
					else if(IsZhongTongKuaiYun(itB->strWuLiuGongSi) || IsYunDaKuaiYun(itB->strWuLiuGongSi))
					{
						double money = GetKYPrice(nWeight, itB->strSheng, itB->strShi, g_yongChuangYaoHuiZTKYPrice, itB->strWuLiuDanHao, false);
						sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1).c_str());

						std::map<std::wstring, sZTKYAuthData>::iterator itZTKY = m_mapZTKYAuthData.find(itB->strWuLiuDanHao);
						bool bSL = false;
						if(itZTKY != m_mapZTKYAuthData.end())
						{
							double chengbenMoney = GetKYPrice(nWeight, itB->strSheng, itB->strShi, g_chengBenZTKYPrice, itB->strWuLiuDanHao, false);
							if(chengbenMoney + DOUBLE_PRECISION < itZTKY->second.yingShou-itZTKY->second.qita)
							{
								BasicExcelWorksheet* recordSheet = m_recordExcel.GetWorksheet(g_arrWorksheetName[5]);
								recordSheet->Cell(g_arrRecordRowIndex[5], 0)->SetWString(L"哈特能量");
								recordSheet->Cell(g_arrRecordRowIndex[5], 1)->SetWString(itB->strWuLiuDanHao.c_str());
								recordSheet->Cell(g_arrRecordRowIndex[5], 2)->SetWString(CFuncCommon::Double2WString(itZTKY->second.yingShou-itZTKY->second.qita + DOUBLE_PRECISION, 1).c_str());
								recordSheet->Cell(g_arrRecordRowIndex[5], 3)->SetWString(CFuncCommon::Double2WString(chengbenMoney + DOUBLE_PRECISION, 1).c_str());
								g_arrRecordRowIndex[5]++;

								BasicExcelWorksheet* ztSheet = m_ztkyExcel.GetWorksheet(L"Sheet1");
								if(ztSheet)
									ztSheet->Cell(itZTKY->second.row, m_ztkyHandleCol)->SetWString(L"价格异常");
							}
							if(itZTKY->second.qita > DOUBLE_PRECISION)
							{
								dZengZhi += itZTKY->second.qita;
								if(strBeiZhu == L"")
									strBeiZhu = strBeiZhu + L"上楼";
								else
									strBeiZhu = strBeiZhu + L" | 上楼";
								bSL = true;
							}
						}
						if(!bSL)
						{
							if(nWeight > 50)
							{
								if(nWeight < 120)
									dZengZhi += (nWeight - 50)*0.1 + 10;
								else
									dZengZhi += (nWeight - 50)*0.1 + 30;
								if(strBeiZhu == L"")
									strBeiZhu = strBeiZhu + L"上楼";
								else
									strBeiZhu = strBeiZhu + L" | 上楼";
							}
						}
					}
					else if(IsBaiShiKuaiDi(itB->strWuLiuGongSi))
					{
						double money = 0;
						if(nWeight > 0)
						{
							if(nWeight > 3)
								money = 1.3 + (nWeight - 3)*0.8;
							else
								money = 1.3;
							sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1).c_str());
						}
					}
					else if(IsYunDaKuaiDi(itB->strWuLiuGongSi))
					{
						double money = GetKDPrice(nWeight, itB->strSheng, itB->strShi, g_yongChuangYaoHuiKDPrice, L"韵达快递", itB->strWuLiuDanHao, false);
						sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1).c_str());
					}
					else
					{
						wchar_t szOut[120] = { 0 };
						_swprintf(szOut, L"[未知的物流方式] 货主=%s 单号=%s 物流公司=%s", itB->strHuoZhu.c_str(), itB->strWuLiuDanHao.c_str(), itB->strWuLiuGongSi.c_str());
						AddLog(szOut);
					}
				}
				sheet->Cell(itB->nRow, eET_CaoZuoFei)->SetWString(L"1.1");
				//计算增值费用
				{
					//云集贴标费
					if(itB->strYuanShiDanHao.size() >= 2)
					{
						wchar_t char1 = itB->strYuanShiDanHao.at(0);
						wchar_t char2 = itB->strYuanShiDanHao.at(1);
						if(char1 == L'S' && char2 == L'O')
						{
							dZengZhi += 0.3;
							if(strBeiZhu == L"")
								strBeiZhu = strBeiZhu + L"贴标";
							else
								strBeiZhu = strBeiZhu + L" | 贴标";
						}
					}
					if(dZengZhi > 0)
						sheet->Cell(itB->nRow, eET_ZengZhiFeiYong)->SetWString(CFuncCommon::Double2WString(dZengZhi + DOUBLE_PRECISION, 1).c_str());
				}
				sheet->Cell(itB->nRow, eET_BeiZhu)->SetWString(strBeiZhu.c_str());
				++itB;
			}
		}

	}
	excel.SaveAs(_file.c_str());
	AddLog(L"哈特能量账单生成成功");
	return true;
}


bool CStorageBillDlg::Handle_QiYiJiangYuan()
{
	BasicExcel excel;
	if(!CreateExcel(L"七一酱园", excel, m_mapAllSalesInfo[L"七一酱园"], m_mapInStorageInfo[L"七一酱园"]))
		return false;
	wstring fileName = L"./Export_" + m_strYM + L"/" + L"七一酱园_" + m_strYM + L"对账单.xls";
	string _file = CFuncCommon::WString2String(fileName.c_str());
	CompareWhithWuLiu(L"七一酱园", m_mapAllSalesInfo[L"七一酱园"]);
	//计算相关费用
	{
		BasicExcelWorksheet* sheet = excel.GetWorksheet(L"订单费用");
		if(sheet)
		{
			std::list<sSalesInfo>& listSales = m_mapAllSalesInfo[L"七一酱园"];
			std::list<sSalesInfo>::iterator itB = listSales.begin();
			std::list<sSalesInfo>::iterator itE = listSales.end();
			while(itB != itE)
			{
				wstring strBeiZhu = L"";
				int nWeight = 0;
				if(!IsZhengShu(itB->strZhongLiang))
				{
					double nZhongLiang = _wtof(itB->strZhongLiang.c_str());
					nZhongLiang += 1;
					nZhongLiang += DOUBLE_PRECISION;
					nWeight = int(nZhongLiang);
					if(nWeight < 3)
						nWeight = 3;
					wchar_t szWeight[10] = { 0 };
					_itow_s(nWeight, szWeight, 10);
					sheet->Cell(itB->nRow, eET_JiFeiZhongLiang)->SetWString(szWeight);
				}
				else
				{
					if(IsZero(itB->strZhongLiang))
						nWeight = 0;
					else
					{
						nWeight = _wtoi(itB->strZhongLiang.c_str());
						if(nWeight < 3)
							nWeight = 3;
					}

					wchar_t szWeight[10] = { 0 };
					_itow_s(nWeight, szWeight, 10);
					sheet->Cell(itB->nRow, eET_JiFeiZhongLiang)->SetWString(szWeight);
				}
				double dZengZhi = 0;
				//计算物流费
				{
					if(IsBaiShiKuaiDi(itB->strWuLiuGongSi) || IsYunDaKuaiDi(itB->strWuLiuGongSi))
					{
						double money = 0;
						if(nWeight > 0)
						{
							double money = GetKDPrice(nWeight, itB->strSheng, itB->strShi, g_qiYiJiangYuanBSPrice, L"百世快递", itB->strWuLiuDanHao);
							sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1).c_str());
						}
					}
					else if(IsShunFengKuaiDi(itB->strWuLiuGongSi))
					{
						double money = GetSFPrice(nWeight, itB->strSheng, g_qiYiJiangYuanSFPrice, itB->strWuLiuDanHao);
						double sourceBJ = 0;
						std::map<std::wstring, sSFAuthData>::iterator itSF = m_mapSFAuthData.find(itB->strWuLiuDanHao);
						if(itSF != m_mapSFAuthData.end())
							sourceBJ = _wtof(itSF->second.bjPay.c_str());
						if(itB->nBaoJiaJinE != 0)
						{
							dZengZhi += (itB->nBaoJiaJinE*0.003);
							if(dZengZhi < 1)
								dZengZhi = 0.0;
							else
							{
								if(strBeiZhu == L"")
									strBeiZhu = strBeiZhu + L"保价";
								else
									strBeiZhu = strBeiZhu + L" | 保价";
							}
						}
						else if(sourceBJ > DOUBLE_PRECISION)
						{
							dZengZhi += sourceBJ;
							if(strBeiZhu == L"")
								strBeiZhu = strBeiZhu + L"保价";
							else
								strBeiZhu = strBeiZhu + L" | 保价";
						}

						if(itSF != m_mapSFAuthData.end())
						{
							if(itSF->second.type != L"特惠专配" && itSF->second.type != L"电商标快")
							{
								std::set<std::wstring>::iterator itType = m_setSFOtherType.find(itSF->second.type);
								if(itType != m_setSFOtherType.end())
								{
									wchar_t szOut[120] = { 0 };
									_swprintf(szOut, L"顺丰出现异常产品类型[%s]", itSF->second.type.c_str());
									AddLog(szOut);
									m_setSFOtherType.insert(itSF->second.type);
								}
								double _needPay = _wtof(itSF->second.needPay.c_str());
								double _backPay = 0.0;
								double _bjPay = 0.0;
								if(itSF->second.backPay != L"")
									_backPay = _wtof(itSF->second.backPay.c_str());
								if(itSF->second.bjPay != L"")
									_bjPay = _wtof(itSF->second.bjPay.c_str());
								money = _needPay - _backPay - _bjPay + 3;
							}
							if(itSF->second.backPay != L"")
							{
								double backPay = _wtof(itSF->second.backPay.c_str());
								money += backPay;

								if(strBeiZhu == L"")
									strBeiZhu = strBeiZhu + L"转寄退回";
								else
									strBeiZhu = strBeiZhu + L" | 转寄退回";
							}
							double needPay = _wtof(itSF->second.needPay.c_str());
							if(needPay > money + dZengZhi)
							{
								std::set<std::wstring>::iterator it = m_setSFZhongLiangYiChang.find(itB->strWuLiuDanHao.c_str());
								if(it == m_setSFZhongLiangYiChang.end())
								{
									if(!m_bSFErrorPrice)
									{
										AddLog(L"顺丰费用有异常");
										m_bSFErrorPrice = true;
									}
									BasicExcelWorksheet* recordSheet = m_recordExcel.GetWorksheet(g_arrWorksheetName[2]);
									recordSheet->Cell(g_arrRecordRowIndex[2], 0)->SetWString(itB->strWuLiuDanHao.c_str());
									recordSheet->Cell(g_arrRecordRowIndex[2], 1)->SetWString(itB->strHuoZhu.c_str());
									g_arrRecordRowIndex[2]++;
								}
							}
						}

						sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1).c_str());
					}
					else if(IsZhongTongKuaiYun(itB->strWuLiuGongSi) || IsYunDaKuaiYun(itB->strWuLiuGongSi))
					{
						double money = GetKYPrice(nWeight, itB->strSheng, itB->strShi, g_qiYiJiangYuanZTKYPrice, itB->strWuLiuDanHao);
						sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1).c_str());
						if(IsZhongTongKuaiYun(itB->strWuLiuGongSi))
						{
							bool bSL = false;
							std::map<std::wstring, sZTKYAuthData>::iterator itZTKY = m_mapZTKYAuthData.find(itB->strWuLiuDanHao);
							if(itZTKY != m_mapZTKYAuthData.end())
							{
								double chengbenMoney = GetKYPrice(nWeight, itB->strSheng, itB->strShi, g_chengBenZTKYPrice, itB->strWuLiuDanHao);
								if(chengbenMoney + DOUBLE_PRECISION < itZTKY->second.yingShou-itZTKY->second.qita)
								{
									BasicExcelWorksheet* recordSheet = m_recordExcel.GetWorksheet(g_arrWorksheetName[5]);
									recordSheet->Cell(g_arrRecordRowIndex[5], 0)->SetWString(L"七一酱园");
									recordSheet->Cell(g_arrRecordRowIndex[5], 1)->SetWString(itB->strWuLiuDanHao.c_str());
									recordSheet->Cell(g_arrRecordRowIndex[5], 2)->SetWString(CFuncCommon::Double2WString(itZTKY->second.yingShou-itZTKY->second.qita + DOUBLE_PRECISION, 1).c_str());
									recordSheet->Cell(g_arrRecordRowIndex[5], 3)->SetWString(CFuncCommon::Double2WString(chengbenMoney + DOUBLE_PRECISION, 1).c_str());
									g_arrRecordRowIndex[5]++;

									BasicExcelWorksheet* ztSheet = m_ztkyExcel.GetWorksheet(L"Sheet1");
									if(ztSheet)
										ztSheet->Cell(itZTKY->second.row, m_ztkyHandleCol)->SetWString(L"价格异常");
								}

								if(itZTKY->second.qita > DOUBLE_PRECISION)
								{
									dZengZhi += itZTKY->second.qita;
									if(strBeiZhu == L"")
										strBeiZhu = strBeiZhu + L"上楼";
									else
										strBeiZhu = strBeiZhu + L" | 上楼";
									bSL = true;
								}
							}
							if(!bSL)
							{
								if(nWeight > 50)
								{
									if(nWeight < 120)
										dZengZhi += (nWeight - 50)*0.1 + 10;
									else
										dZengZhi += (nWeight - 50)*0.1 + 30;
									if(strBeiZhu == L"")
										strBeiZhu = strBeiZhu + L"上楼";
									else
										strBeiZhu = strBeiZhu + L" | 上楼";
								}
							}
						}
					}
					else
					{
						wchar_t szOut[120] = { 0 };
						_swprintf(szOut, L"[未知的物流方式] 货主=%s 单号=%s 物流公司=%s", itB->strHuoZhu.c_str(), itB->strWuLiuDanHao.c_str(), itB->strWuLiuGongSi.c_str());
						AddLog(szOut);
					}
				}
				//打包费用
				{
					double _price = 0.9;
					int nZSL = _wtoi(itB->strHuoPinZongShuLiang.c_str());
					if(nZSL == 0)
					{
						wchar_t szOut[120] = { 0 };
						_swprintf(szOut, L"[异常货品数量] 货主=%s 单号=%s 物流公司=%s", itB->strHuoZhu.c_str(), itB->strWuLiuDanHao.c_str(), itB->strWuLiuGongSi.c_str());
						AddLog(szOut);
					}
					if(nZSL > 5)
						_price = 0.9 + (nZSL - 5)*0.1;
					else
						_price = 0.9;
					sheet->Cell(itB->nRow, eET_CaoZuoFei)->SetWString(CFuncCommon::Double2WString(_price + DOUBLE_PRECISION, 1).c_str());
				}
				//耗材费用
				{
					int nZSL = _wtoi(itB->strHuoPinZongShuLiang.c_str());
					if(nZSL == 0)
					{
						wchar_t szOut[120] = { 0 };
						_swprintf(szOut, L"[异常货品数量] 货主=%s 单号=%s 物流公司=%s", itB->strHuoZhu.c_str(), itB->strWuLiuDanHao.c_str(), itB->strWuLiuGongSi.c_str());
						AddLog(szOut);
					}
					else
					{
						if(itB->strBaoZhuang == L"单支装纸箱")
							sheet->Cell(itB->nRow, eET_HaoCaiFei)->SetWString(CFuncCommon::Double2WString(0.1 + nZSL*0.2 + 2 + DOUBLE_PRECISION, 1).c_str());
						else if(itB->strBaoZhuang == L"两支装纸箱")
							sheet->Cell(itB->nRow, eET_HaoCaiFei)->SetWString(CFuncCommon::Double2WString(0.1 + nZSL*0.2 + 2.6 + DOUBLE_PRECISION, 1).c_str());
						else if(itB->strBaoZhuang == L"4#3层纸箱(4#3层纸箱)")
							sheet->Cell(itB->nRow, eET_HaoCaiFei)->SetWString(CFuncCommon::Double2WString(0.1 + nZSL*0.6 + 2.05 + DOUBLE_PRECISION, 1).c_str());
						else if(itB->strBaoZhuang == L"5#3层纸箱(5#3层纸箱)")
							sheet->Cell(itB->nRow, eET_HaoCaiFei)->SetWString(CFuncCommon::Double2WString(0.1 + nZSL*0.6 + 1.42 + DOUBLE_PRECISION, 1).c_str());
						else
							sheet->Cell(itB->nRow, eET_HaoCaiFei)->SetWString(CFuncCommon::Double2WString(0.1 + nZSL*0.6 + 2.05 + DOUBLE_PRECISION, 1).c_str());
						/*else
						{
							wchar_t szOut[120] = { 0 };
							_swprintf(szOut, L"[未知包装物] 货主=%s 单号=%s 物流公司=%s", itB->strHuoZhu.c_str(), itB->strWuLiuDanHao.c_str(), itB->strWuLiuGongSi.c_str());
							AddLog(szOut);
						}*/
					}
				}
				++itB;
			}
		}

	}
	excel.SaveAs(_file.c_str());
	AddLog(L"七一酱园账单生成成功");
	return true;
}

bool CStorageBillDlg::Handle_WeiFuKang()
{
	BasicExcel excel;
	if(!CreateExcel(L"维敷康", excel, m_mapAllSalesInfo[L"维敷康"], m_mapInStorageInfo[L"维敷康"]))
		return false;
	wstring fileName = L"./Export_" + m_strYM + L"/" + L"维敷康_" + m_strYM + L"对账单.xls";
	string _file = CFuncCommon::WString2String(fileName.c_str());
	CompareWhithWuLiu(L"维敷康", m_mapAllSalesInfo[L"维敷康"]);
	//计算相关费用
	{
		BasicExcelWorksheet* sheet = excel.GetWorksheet(L"订单费用");
		if(sheet)
		{
			std::list<sSalesInfo>& listSales = m_mapAllSalesInfo[L"维敷康"];
			std::list<sSalesInfo>::iterator itB = listSales.begin();
			std::list<sSalesInfo>::iterator itE = listSales.end();
			while(itB != itE)
			{
				wstring strBeiZhu = L"";
				int nWeight = 0;
				if(!IsZhengShu(itB->strZhongLiang))
				{
					double nZhongLiang = _wtof(itB->strZhongLiang.c_str());
					nZhongLiang += 1;
					nZhongLiang += DOUBLE_PRECISION;
					nWeight = int(nZhongLiang);
					if(nWeight < 3)
						nWeight = 3;
					wchar_t szWeight[10] = { 0 };
					_itow_s(nWeight, szWeight, 10);
					sheet->Cell(itB->nRow, eET_JiFeiZhongLiang)->SetWString(szWeight);
				}
				else
				{
					if(IsZero(itB->strZhongLiang))
						nWeight = 0;
					else
					{
						nWeight = _wtoi(itB->strZhongLiang.c_str());
						if(nWeight < 3)
							nWeight = 3;
					}
					wchar_t szWeight[10] = { 0 };
					_itow_s(nWeight, szWeight, 10);
					sheet->Cell(itB->nRow, eET_JiFeiZhongLiang)->SetWString(szWeight);
				}

				double dZengZhi = 0;
				//计算物流费
				{
					if(IsYunDaKuaiDi(itB->strWuLiuGongSi))
					{
						double money = GetKDPrice(nWeight, itB->strSheng, itB->strShi, g_weiFuKangYDKDPrice, L"韵达快递", itB->strWuLiuDanHao);
						sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1).c_str());
					}
					else if(IsZhongTongKuaiYun(itB->strWuLiuGongSi) || IsYunDaKuaiYun(itB->strWuLiuGongSi))
					{
						double money = GetKYPrice(nWeight, itB->strSheng, itB->strShi, g_weiFuKangZTKYPrice, itB->strWuLiuDanHao);
						sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1).c_str());
						if(IsZhongTongKuaiYun(itB->strWuLiuGongSi))
						{
							bool bSL = false;
							std::map<std::wstring, sZTKYAuthData>::iterator itZTKY = m_mapZTKYAuthData.find(itB->strWuLiuDanHao);
							if(itZTKY != m_mapZTKYAuthData.end())
							{
								double chengbenMoney = GetKYPrice(nWeight, itB->strSheng, itB->strShi, g_chengBenZTKYPrice, itB->strWuLiuDanHao);
								if(chengbenMoney + DOUBLE_PRECISION < itZTKY->second.yingShou - itZTKY->second.qita)
								{
									BasicExcelWorksheet* recordSheet = m_recordExcel.GetWorksheet(g_arrWorksheetName[5]);
									recordSheet->Cell(g_arrRecordRowIndex[5], 0)->SetWString(L"维敷康");
									recordSheet->Cell(g_arrRecordRowIndex[5], 1)->SetWString(itB->strWuLiuDanHao.c_str());
									recordSheet->Cell(g_arrRecordRowIndex[5], 2)->SetWString(CFuncCommon::Double2WString(itZTKY->second.yingShou - itZTKY->second.qita + DOUBLE_PRECISION, 1).c_str());
									recordSheet->Cell(g_arrRecordRowIndex[5], 3)->SetWString(CFuncCommon::Double2WString(chengbenMoney + DOUBLE_PRECISION, 1).c_str());
									g_arrRecordRowIndex[5]++;

									BasicExcelWorksheet* ztSheet = m_ztkyExcel.GetWorksheet(L"Sheet1");
									if(ztSheet)
										ztSheet->Cell(itZTKY->second.row, m_ztkyHandleCol)->SetWString(L"价格异常");
								}

								if(itZTKY->second.qita > DOUBLE_PRECISION)
								{
									dZengZhi += itZTKY->second.qita;
									if(strBeiZhu == L"")
										strBeiZhu = strBeiZhu + L"上楼";
									else
										strBeiZhu = strBeiZhu + L" | 上楼";
									bSL = true;
								}
							}
							if(!bSL)
							{
								if(nWeight > 50)
								{
									if(nWeight < 120)
										dZengZhi += (nWeight - 50)*0.1 + 10;
									else
										dZengZhi += (nWeight - 50)*0.1 + 30;
									if(strBeiZhu == L"")
										strBeiZhu = strBeiZhu + L"上楼";
									else
										strBeiZhu = strBeiZhu + L" | 上楼";
								}
							}
						}
					}
					else
					{
						wchar_t szOut[120] = { 0 };
						_swprintf(szOut, L"[未知的物流方式] 货主=%s 单号=%s 物流公司=%s", itB->strHuoZhu.c_str(), itB->strWuLiuDanHao.c_str(), itB->strWuLiuGongSi.c_str());
						AddLog(szOut);
					}
				}
				{
					double _price = 0.5;
					int nZSL = _wtoi(itB->strHuoPinZongShuLiang.c_str());
					if(nZSL > 0)
						_price = 0.5 * nZSL;
					sheet->Cell(itB->nRow, eET_CaoZuoFei)->SetWString(CFuncCommon::Double2WString(_price + DOUBLE_PRECISION, 1).c_str());
				}
				++itB;
			}
		}

	}
	excel.SaveAs(_file.c_str());
	AddLog(L"维敷康账单生成成功");
	return true;
	return true;
}

bool CStorageBillDlg::Handle_ZhiShanDianShang(wchar_t* szHuoZhu)
{
	BasicExcel excel;
	if(!CreateExcel(szHuoZhu, excel, m_mapAllSalesInfo[szHuoZhu], m_mapInStorageInfo[szHuoZhu]))
		return false;
	wstring fileName = L"./Export_" + m_strYM + L"/" + szHuoZhu + L"_" + m_strYM + L"对账单.xls";
	string _file = CFuncCommon::WString2String(fileName.c_str());
	CompareWhithWuLiu(szHuoZhu, m_mapAllSalesInfo[szHuoZhu]);
	//计算相关费用
	{
		BasicExcelWorksheet* sheet = excel.GetWorksheet(L"订单费用");
		if(sheet)
		{
			std::list<sSalesInfo>& listSales = m_mapAllSalesInfo[szHuoZhu];
			std::list<sSalesInfo>::iterator itB = listSales.begin();
			std::list<sSalesInfo>::iterator itE = listSales.end();
			while(itB != itE)
			{
				wstring strBeiZhu = L"";
				int nWeight = 0;
				if(!IsZhengShu(itB->strZhongLiang))
				{
					double nZhongLiang = _wtof(itB->strZhongLiang.c_str());
					nZhongLiang += 1;
					nZhongLiang += DOUBLE_PRECISION;
					nWeight = int(nZhongLiang);
					wchar_t szWeight[10] = { 0 };
					_itow_s(nWeight, szWeight, 10);
					sheet->Cell(itB->nRow, eET_JiFeiZhongLiang)->SetWString(szWeight);
				}
				else
				{
					if(IsZero(itB->strZhongLiang))
						nWeight = 0;
					else
						nWeight = _wtoi(itB->strZhongLiang.c_str());
					wchar_t szWeight[10] = { 0 };
					_itow_s(nWeight, szWeight, 10);
					sheet->Cell(itB->nRow, eET_JiFeiZhongLiang)->SetWString(szWeight);
				}

				double dZengZhi = 0;
				//计算物流费
				{
					if(IsShunFengKuaiDi(itB->strWuLiuGongSi) || itB->strWuLiuGongSi==L"顺丰空运(线下)")
					{
						double money = GetSFPrice(nWeight, itB->strSheng, g_zhiShanSFPrice, itB->strWuLiuDanHao);
						double sourceBJ = 0.0;
						std::map<std::wstring, sSFAuthData>::iterator itSF = m_mapSFAuthData.find(itB->strWuLiuDanHao);
						if(itSF != m_mapSFAuthData.end())
							sourceBJ = _wtof(itSF->second.bjPay.c_str());
						if(itB->nBaoJiaJinE != 0)
						{
							dZengZhi += (itB->nBaoJiaJinE*0.003);
							if(dZengZhi < 1)
								dZengZhi = 0.0;
							else
							{
								if(strBeiZhu == L"")
									strBeiZhu = strBeiZhu + L"保价";
								else
									strBeiZhu = strBeiZhu + L" | 保价";
							}
						}
						else if(sourceBJ > DOUBLE_PRECISION)
						{
							dZengZhi += sourceBJ;
							if(strBeiZhu == L"")
								strBeiZhu = strBeiZhu + L"保价";
							else
								strBeiZhu = strBeiZhu + L" | 保价";
						}
						if(sourceBJ > DOUBLE_PRECISION && sourceBJ > dZengZhi)
							dZengZhi = sourceBJ;
						if(itSF != m_mapSFAuthData.end())
						{
							if(itSF->second.type != L"特惠专配" && itSF->second.type != L"电商标快")
							{
								std::set<std::wstring>::iterator itType = m_setSFOtherType.find(itSF->second.type);
								if(itType != m_setSFOtherType.end())
								{
									wchar_t szOut[120] = { 0 };
									_swprintf(szOut, L"顺丰出现异常产品类型[%s]", itSF->second.type.c_str());
									AddLog(szOut);
									m_setSFOtherType.insert(itSF->second.type);
								}
								double _needPay = _wtof(itSF->second.needPay.c_str());
								double _backPay = 0.0;
								double _bjPay = 0.0;
								if(itSF->second.backPay != L"")
									_backPay = _wtof(itSF->second.backPay.c_str());
								if(itSF->second.bjPay != L"")
									_bjPay = _wtof(itSF->second.bjPay.c_str());
								money = _needPay - _backPay - _bjPay + 3;
							}
							if(itSF->second.backPay != L"")
							{
								double backPay = _wtof(itSF->second.backPay.c_str());
								money += backPay;

								if(strBeiZhu == L"")
									strBeiZhu = strBeiZhu + L"转寄退回";
								else
									strBeiZhu = strBeiZhu + L" | 转寄退回";
							}
							double needPay = _wtof(itSF->second.needPay.c_str());
							if(needPay > money + dZengZhi)
							{
								std::set<std::wstring>::iterator it = m_setSFZhongLiangYiChang.find(itB->strWuLiuDanHao.c_str());
								if(it == m_setSFZhongLiangYiChang.end())
								{
									if(!m_bSFErrorPrice)
									{
										AddLog(L"顺丰费用有异常");
										m_bSFErrorPrice = true;
									}
									BasicExcelWorksheet* recordSheet = m_recordExcel.GetWorksheet(g_arrWorksheetName[2]);
									recordSheet->Cell(g_arrRecordRowIndex[2], 0)->SetWString(itB->strWuLiuDanHao.c_str());
									recordSheet->Cell(g_arrRecordRowIndex[2], 1)->SetWString(itB->strHuoZhu.c_str());
									g_arrRecordRowIndex[2]++;
								}
							}
						}
						std::wstring strmoney = CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1);
						sheet->Cell(itB->nRow, eET_WuLiuFei)->SetDouble(_wtof(strmoney.c_str()));
					}
					else if(IsBaiShiKuaiDi(itB->strWuLiuGongSi))
					{
						double money = GetKDPrice(nWeight, itB->strSheng, itB->strShi, g_zhiShanBSKDPrice, L"百世快递", itB->strWuLiuDanHao);
						sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1).c_str());
					}
					else if(IsYunDaKuaiDi(itB->strWuLiuGongSi))
					{
						double money = GetKDPrice(nWeight, itB->strSheng, itB->strShi, g_zhiShanQTKDPrice, L"韵达快递", itB->strWuLiuDanHao);
						sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1).c_str());
					}
					else if(IsZhongTongKuaiYun(itB->strWuLiuGongSi) || IsYunDaKuaiYun(itB->strWuLiuGongSi))
					{
						double money = GetKYPrice(nWeight, itB->strSheng, itB->strShi, g_zhiShanZTKYPrice, itB->strWuLiuDanHao);
						sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1).c_str());
						if(IsZhongTongKuaiYun(itB->strWuLiuGongSi))
						{
							bool bSL = false;
							std::map<std::wstring, sZTKYAuthData>::iterator itZTKY = m_mapZTKYAuthData.find(itB->strWuLiuDanHao);
							if(itZTKY != m_mapZTKYAuthData.end())
							{
								double chengbenMoney = GetKYPrice(nWeight, itB->strSheng, itB->strShi, g_chengBenZTKYPrice, itB->strWuLiuDanHao);
								if(chengbenMoney + DOUBLE_PRECISION < itZTKY->second.yingShou - itZTKY->second.qita)
								{
									BasicExcelWorksheet* recordSheet = m_recordExcel.GetWorksheet(g_arrWorksheetName[5]);
									recordSheet->Cell(g_arrRecordRowIndex[5], 0)->SetWString(szHuoZhu);
									recordSheet->Cell(g_arrRecordRowIndex[5], 1)->SetWString(itB->strWuLiuDanHao.c_str());
									recordSheet->Cell(g_arrRecordRowIndex[5], 2)->SetWString(CFuncCommon::Double2WString(itZTKY->second.yingShou - itZTKY->second.qita + DOUBLE_PRECISION, 1).c_str());
									recordSheet->Cell(g_arrRecordRowIndex[5], 3)->SetWString(CFuncCommon::Double2WString(chengbenMoney + DOUBLE_PRECISION, 1).c_str());
									g_arrRecordRowIndex[5]++;

									BasicExcelWorksheet* ztSheet = m_ztkyExcel.GetWorksheet(L"Sheet1");
									if(ztSheet)
										ztSheet->Cell(itZTKY->second.row, m_ztkyHandleCol)->SetWString(L"价格异常");
								}

								if(itZTKY->second.qita > DOUBLE_PRECISION)
								{
									dZengZhi += itZTKY->second.qita;
									if(strBeiZhu == L"")
										strBeiZhu = strBeiZhu + L"上楼";
									else
										strBeiZhu = strBeiZhu + L" | 上楼";
									bSL = true;
								}
							}
							if(!bSL)
							{
								if(nWeight > 50)
								{
									if(nWeight < 120)
										dZengZhi += (nWeight - 50)*0.1 + 10;
									else
										dZengZhi += (nWeight - 50)*0.1 + 30;
									if(strBeiZhu == L"")
										strBeiZhu = strBeiZhu + L"上楼";
									else
										strBeiZhu = strBeiZhu + L" | 上楼";
								}
							}
						}
					}
					else
					{
						wchar_t szOut[120] = { 0 };
						_swprintf(szOut, L"[未知的物流方式] 货主=%s 单号=%s 物流公司=%s", itB->strHuoZhu.c_str(), itB->strWuLiuDanHao.c_str(), itB->strWuLiuGongSi.c_str());
						AddLog(szOut);
					}
				}
				sheet->Cell(itB->nRow, eET_HaoCaiFei)->SetWString(L"0.1");
				sheet->Cell(itB->nRow, eET_CaoZuoFei)->SetWString(L"0.8");
				++itB;
			}
		}

	}
	excel.SaveAs(_file.c_str());
	wchar_t szBuffer[128] = { 0 };
	wsprintfW(szBuffer, L"%s账单生成成功", szHuoZhu);
	AddLog(szBuffer);
	return true;
}

bool CStorageBillDlg::Handle_LaFengQing()
{
	BasicExcel excel;
	if(!CreateExcel(L"辣风芹", excel, m_mapAllSalesInfo[L"辣风芹"], m_mapInStorageInfo[L"辣风芹"]))
		return false;
	wstring fileName = L"./Export_" + m_strYM + L"/" + L"辣风芹_" + m_strYM + L"对账单.xls";
	string _file = CFuncCommon::WString2String(fileName.c_str());
	CompareWhithWuLiu(L"辣风芹", m_mapAllSalesInfo[L"辣风芹"]);
	//计算相关费用
	{
		BasicExcelWorksheet* sheet = excel.GetWorksheet(L"订单费用");
		if(sheet)
		{
			std::list<sSalesInfo>& listSales = m_mapAllSalesInfo[L"辣风芹"];
			std::list<sSalesInfo>::iterator itB = listSales.begin();
			std::list<sSalesInfo>::iterator itE = listSales.end();
			while(itB != itE)
			{
				wstring strBeiZhu = L"";
				int nWeight = 0;
				if(!IsZhengShu(itB->strZhongLiang))
				{
					double nZhongLiang = _wtof(itB->strZhongLiang.c_str());
					nZhongLiang += 1;
					nZhongLiang += DOUBLE_PRECISION;
					nWeight = int(nZhongLiang);
					if(nWeight < 3)
						nWeight = 3;
					wchar_t szWeight[10] = { 0 };
					_itow_s(nWeight, szWeight, 10);
					sheet->Cell(itB->nRow, eET_JiFeiZhongLiang)->SetWString(szWeight);
				}
				else
				{
					if(IsZero(itB->strZhongLiang))
						nWeight = 0;
					else
					{
						nWeight = _wtoi(itB->strZhongLiang.c_str());
						if(nWeight < 3)
							nWeight = 3;
					}
					wchar_t szWeight[10] = { 0 };
					_itow_s(nWeight, szWeight, 10);
					sheet->Cell(itB->nRow, eET_JiFeiZhongLiang)->SetWString(szWeight);
				}

				double dZengZhi = 0;
				//计算物流费
				{
					if(IsShunFengKuaiDi(itB->strWuLiuGongSi) || IsBaiShiKuaiDi(itB->strWuLiuGongSi) || IsYunDaKuaiDi(itB->strWuLiuGongSi)  || IsZhongTongKuaiYun(itB->strWuLiuGongSi) || IsYunDaKuaiYun(itB->strWuLiuGongSi))
					{
						double money = GetKDPrice(nWeight, itB->strSheng, itB->strShi, g_laFengQingKDPrice, L"百世快递", itB->strWuLiuDanHao);
						sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1).c_str());
					}
					else
					{
						wchar_t szOut[120] = { 0 };
						_swprintf(szOut, L"[未知的物流方式] 货主=%s 单号=%s 物流公司=%s", itB->strHuoZhu.c_str(), itB->strWuLiuDanHao.c_str(), itB->strWuLiuGongSi.c_str());
						AddLog(szOut);
					}
				}
				sheet->Cell(itB->nRow, eET_CaoZuoFei)->SetWString(L"0.4");
				++itB;
			}
		}

	}
	excel.SaveAs(_file.c_str());
	AddLog(L"辣风芹账单生成成功");
	return true;
}

void CStorageBillDlg::OnBnClickedCheckZTKYMore()
{
	if(m_checkZTKYMore.GetCheck() == 1)
	{
		m_checkDuoDuoMaiCai.SetCheck(0);
		m_checkYGZD.SetCheck(0);
		m_checkYDKDCheck.SetCheck(0);
	}
}


void CStorageBillDlg::OnBnClickedCheckDDMC()
{
	if(m_checkDuoDuoMaiCai.GetCheck() == 1)
	{
		m_checkZTKYMore.SetCheck(0);
		m_checkYGZD.SetCheck(0);
		m_checkYDKDCheck.SetCheck(0);
	}
}


void CStorageBillDlg::OnBnClickedCheckYG()
{
	if(m_checkYGZD.GetCheck() == 1)
	{
		m_checkZTKYMore.SetCheck(0);
		m_checkDuoDuoMaiCai.SetCheck(0);
		m_checkYDKDCheck.SetCheck(0);
	}
}


void CStorageBillDlg::OnBnClickedCheckYDKD()
{
	if(m_checkYDKDCheck.GetCheck() == 1)
	{
		m_checkZTKYMore.SetCheck(0);
		m_checkDuoDuoMaiCai.SetCheck(0);
		m_checkYGZD.SetCheck(0);
	}
}
