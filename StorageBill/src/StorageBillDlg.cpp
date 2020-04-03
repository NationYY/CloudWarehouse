
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

#define TOTAL_FILE_PATH L"./系统数据/"+m_strYM+L"/销售出库单.xls"
#define DETAIL_FILE_PATH L"./系统数据/"+m_strYM+L"/销售出库明细.xls"
#define SF_FILE_PATH L"./系统数据/"+m_strYM+L"/顺丰账单.xls"
#define IN_STORAGE_PATH L"./系统数据/"+m_strYM+L"/入库明细账.xls"
#define BS_FILE_PATH L"./系统数据/"+m_strYM+L"/百世账单.xls"


const wchar_t* g_arrWorksheetName[] ={L"顺丰重量差异订单", L"顺丰云仓未处理单号", L"顺丰价格异常"};
int g_arrRecordRowIndex[] ={0, 0, 0};
const wchar_t* g_arrHuoZhuName[] ={L"魔合科技N", L"永创耀辉", L"弥雅食器", L"泰福商贸"};


//------------------------------------顺丰价格--------------------------------------//
//魔合科技															//
double g_moHeKeJiSFPrice[4][2] ={{13, 3.5}, {15, 5}, {19, 5}, {27, 8}};				//
//永创耀辉																	//
double g_yongChuangYaoHuiSFPrice[4][2] ={{11, 2.6}, {12, 4.5}, {16, 4.5}, {22, 7}};	//
//----------------------------------------------------------------------------------//


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
m_bExit(false), m_bRun(false), m_sfHandleCol(-1)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CStorageBillDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST3, m_ctrlListLog);
	DDX_Control(pDX, IDC_EDIT1, m_editYM);
	DDX_Control(pDX, IDC_CHECK1, m_checkSF);
	DDX_Control(pDX, IDC_CHECK2, m_checkBS);
}

BEGIN_MESSAGE_MAP(CStorageBillDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CStorageBillDlg::OnBnClickedCreateBill)
	ON_WM_TIMER()
	ON_LBN_DBLCLK(IDC_LIST3, &CStorageBillDlg::OnLbnDblclkLogList)
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
	m_checkSF.SetCheck(1);
	m_checkBS.SetCheck(1);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CStorageBillDlg::_LogicThread()
{
	while(!m_bExit)
	{
		if(m_bRun)
		{
			if(!ParseALLData())
				goto __break_logic;
			if(!CreateHuoZhuFile())
				goto __break_logic;
			Sleep(2000);
			if(!LoadSFData())
				goto __break_logic;
			if(!LoadBSData())
				goto __break_logic;
			if(!Handle_MoHeKeJi())
				goto __break_logic;
			if(!Handle_YongChuangYaoHui())
				goto __break_logic;
			if(!Handle_MiYaShiQi())
				goto __break_logic;
			if(!Handle_TaiFuShangMao())
				goto __break_logic;
			wstring filePath = L"./Export_" + m_strYM + L"/" + L"compare_record.xls";
			string _filePath = CFuncCommon::WString2String(filePath.c_str());
			m_recordExcel.SaveAs(_filePath.c_str());
			m_sfExcel.Save();
			AddLog(L"账单生成完成");
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
	m_bBS = (m_checkBS.GetState()==1);
	m_bRun = true;
	m_strYM = strYM.GetBuffer();
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

bool CStorageBillDlg::ParseALLData()
{
	std::wstring strTotalFileName = TOTAL_FILE_PATH;
	std::wstring strDetailFileName = DETAIL_FILE_PATH;
	std::wstring strInStorageFileName = IN_STORAGE_PATH;
	BasicExcel totalExcel;
	BasicExcel inStorageExcel;
	BasicExcel detailExcel;
	std::string _strTotalFileName = CFuncCommon::WString2String(strTotalFileName.c_str());
	totalExcel.Load(_strTotalFileName.c_str());
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
			
		}
		if(nHuoZhu == -1 || nShouJianRen == -1 || nWuLiuGongSi == -1 || nWuLiuDanHao == -1 || nShouJianRenDiZhi == -1 || nZhongLiang == -1 || nFaHuoShijian == -1 || nYuanShiDanHao == -1 || nDianPu == -1)
		{
			THROW_ERROR(L"销售出库单 有标题未找到");
		}
		for(size_t r = 1; r < maxRows; ++r)
		{
			sSalesInfo _data;
			const wchar_t* _pStr = NULL;
			SHEET_CELL_STRING(totalSheet, r, nHuoZhu, _data.strHuoZhu);
			SHEET_CELL_STRING(totalSheet, r, nShouJianRen, _data.strShouJianRen);
			SHEET_CELL_STRING(totalSheet, r, nWuLiuGongSi, _data.strWuLiuGongSi);
			SHEET_CELL_STRING(totalSheet, r, nWuLiuDanHao, _data.strWuLiuDanHao);
			SHEET_CELL_STRING(totalSheet, r, nShouJianRenDiZhi, _data.strShouJianRenDiZhi);
			SHEET_CELL_STRING(totalSheet, r, nYuanShiDanHao, _data.strYuanShiDanHao);
			SHEET_CELL_STRING(totalSheet, r, nDianPu, _data.strDianPu);
			if(_data.strYuanShiDanHao != L"")
				_data.bChaiFen = false;
			double dTemp = totalSheet->Cell(r, nZhongLiang)->GetDouble();
			if(dTemp > 0.001)
				dTemp += 0.05;
			if(_data.strWuLiuGongSi == L"顺丰热敏" && m_bSF)
				m_mapYCNeedSFHandle[_data.strHuoZhu].insert(_data.strWuLiuDanHao);
			_data.strZhongLiang = CFuncCommon::Double2WString(dTemp+DOUBLE_PRECISION, 2);
			SHEET_CELL_STRING(totalSheet, r, nFaHuoShijian, _data.strFaHuoShijian);
			m_mapAllSalesInfo[_data.strHuoZhu].push_back(_data);
			std::list<sSalesInfo>::iterator it = --m_mapAllSalesInfo[_data.strHuoZhu].end();
			m_mapTempSalesInfo[_data.strWuLiuDanHao] = &(*it);
		}
	}

	std::string _strDetailFileName = CFuncCommon::WString2String(strDetailFileName.c_str());
	detailExcel.Load(_strDetailFileName.c_str());
	BasicExcelWorksheet* detailSheet = detailExcel.GetWorksheet(L"Sheet1");
	if(detailSheet)
	{
		size_t maxRows = detailSheet->GetTotalRows();
		size_t maxCols = detailSheet->GetTotalCols();

		int nHuoPinMingCheng = -1;
		int nHuoPinZongShuLiang = -1;
		int nHuoPinShuLiang = -1;
		int nWuLiuDanHao = -1;
		int nSheng = -1;
		int nShengShiQu = -1;
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
			else if(strTitle == L"省市区")
				nShengShiQu = c;
			
		}
		if(nHuoPinMingCheng == -1 || nHuoPinZongShuLiang == -1 || nHuoPinShuLiang == -1 || nWuLiuDanHao == -1 || nSheng == -1 || nShengShiQu == -1)
		{
			THROW_ERROR(L"销售出库明细 有标题未找到");
		}
		for(size_t r = 1; r < maxRows; ++r)
		{
			std::wstring strWuLiuDanHao;
			const wchar_t* _pStr = NULL;
			SHEET_CELL_STRING(detailSheet, r, nWuLiuDanHao, strWuLiuDanHao);
			std::map< std::wstring, sSalesInfo* >::iterator it = m_mapTempSalesInfo.find(strWuLiuDanHao);
			if(it == m_mapTempSalesInfo.end())
			{
				wchar_t szBuffer[128] ={0};
				wsprintfW(szBuffer, L"销售出库明细 未找到单号%s", strWuLiuDanHao.c_str());
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
					wchar_t szBuffer[128] = { 0 };
					wsprintfW(szBuffer, L"销售出库明细 未识别省市区 %s", strShengShiQu.c_str());
					THROW_ERROR(szBuffer);
				}
			}
			std::wstring strHuoPinMingCheng;
			SHEET_CELL_STRING(detailSheet, r, nHuoPinMingCheng, strHuoPinMingCheng);
			double dSL = detailSheet->Cell(r, nHuoPinShuLiang)->GetDouble();
			std::wstring strHuoPinShuLiang = CFuncCommon::Double2WString(dSL+DOUBLE_PRECISION, 0);
			if(it->second->strHuoPinMingXi == L"")
				it->second->strHuoPinMingXi = strHuoPinMingCheng + L"@" + strHuoPinShuLiang;
			else
				it->second->strHuoPinMingXi = it->second->strHuoPinMingXi + L";" + strHuoPinMingCheng + L"@" + strHuoPinShuLiang;
			
			if(strHuoPinMingCheng != L"杏汁180ml*1罐" && strHuoPinMingCheng != L"番茄汁180ml*1罐")
				it->second->bChaiFen = false;
			int nBjsl = _wtoi(strHuoPinShuLiang.c_str());
			if(strHuoPinMingCheng == L"五粮液乙亥猪年纪念酒52%500mL")
			{
				if(nBjsl >= 6)
					it->second->nBaoJiaJinE += 5000;
				else
					it->second->nBaoJiaJinE += 900*nBjsl;
			}
			else if(strHuoPinMingCheng == L"五粮液52度囍•庚子鼠年纪念酒500ml*2")
			{
				if(nBjsl >= 6)
					it->second->nBaoJiaJinE += 5000;
				else
					it->second->nBaoJiaJinE += 900 * nBjsl;
			}
			else if(strHuoPinMingCheng == L"五粮液52度囍•乙亥猪年纪念酒500ml*4")
			{
				if(nBjsl >= 6)
					it->second->nBaoJiaJinE += 5000;
				else
					it->second->nBaoJiaJinE += 800 * nBjsl;
			}
			else if(strHuoPinMingCheng == L"五粮液52度囍•乙亥猪年纪念酒500ml*2")
			{
				if(nBjsl >= 6)
					it->second->nBaoJiaJinE += 5000;
				else
					it->second->nBaoJiaJinE += 900 * nBjsl;
			}
			else if(strHuoPinMingCheng == L"郎.青花郎（20）酱香型53度白酒500ml")
			{
				if(nBjsl >= 6)
					it->second->nBaoJiaJinE += 5000;
				else
					it->second->nBaoJiaJinE += 900 * nBjsl;
			}
			else if(strHuoPinMingCheng == L"53度贵州茅台酒蓝")
			{
				it->second->nBaoJiaJinE += 3000 * nBjsl;
			}
			else if(strHuoPinMingCheng == L"贵州茅台酒（青印）53度500ml")
			{
				it->second->nBaoJiaJinE += 2500 * nBjsl;
			}
			else if(strHuoPinMingCheng == L"52度国窖1573经典装")
			{
				it->second->nBaoJiaJinE += 800 * nBjsl;
			}
			else if(strHuoPinMingCheng == L"53度飞天茅台酒（猴年纪念酒）")
			{
				it->second->nBaoJiaJinE += 4000 * nBjsl;
			}
			else if(strHuoPinMingCheng == L"贵州茅台酒飞天茅台53度酱香型白酒3L")
			{
				it->second->nBaoJiaJinE += 20000 * nBjsl;
			}
			else if(strHuoPinMingCheng == L"五粮液（经典) 52%500mL")
			{
				it->second->nBaoJiaJinE += 1000 * nBjsl;
			}
			else if(strHuoPinMingCheng == L"五粮液52度丁酉生肖鸡酒500ml")
			{
				it->second->nBaoJiaJinE += 1000 * nBjsl;
			}
			else if(strHuoPinMingCheng == L"五粮液缘定晶生戒指版500ml")
			{
				it->second->nBaoJiaJinE += 1000 * nBjsl;
			}
		}
	}
	m_mapTempSalesInfo.clear();

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
		}
		if(nHuoZhu == -1 || nRuKuYuanYin == -1 || nShangJiaBianMa == -1 || nHuoPingBianMa == -1 || nHuoPinMingCheng == -1 || nShuLiang == -1)
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
			info.nCnt = inStorageSheet->Cell(r, nShuLiang)->GetInteger();
			std::wstring strKey = info.strShangJiaBianMa+info.strHuoPinBianMa;
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
	}
	return true;
}

bool CStorageBillDlg::CreateHuoZhuFile()
{
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
		if(i == nHuoZhuCnt && itB->first != L"哈特能量")
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
	BasicExcelWorksheet* recordSheet = m_recordExcel.GetWorksheet(g_arrWorksheetName[0]);
	if(recordSheet)
	{
		recordSheet->Cell(g_arrRecordRowIndex[0], 0)->SetWString(L"单号");
		recordSheet->Cell(g_arrRecordRowIndex[0], 1)->SetWString(L"顺丰重量");
		recordSheet->Cell(g_arrRecordRowIndex[0], 2)->SetWString(L"云仓重量");
		recordSheet->Cell(g_arrRecordRowIndex[0], 3)->SetWString(L"云仓计费重量");
		g_arrRecordRowIndex[0]++;
	}
	return true;
}

bool CStorageBillDlg::CreateExcel(BasicExcel& excel, std::list<sSalesInfo>& listSalesInfo, std::map<std::wstring, sInStorageInfo>& mapInStorageInfo)
{
	if(listSalesInfo.size() == 0)
		return false;
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
		sheet->Cell(0, eET_ShouJianRenDiZhi)->SetWString(L"收件人地址");
		sheet->Cell(0, eET_Sheng)->SetWString(L"省");
		sheet->Cell(0, eET_WuLiuGongSi)->SetWString(L"物流公司");
		sheet->Cell(0, eET_WuLiuDanHao)->SetWString(L"物流单号");
		sheet->Cell(0, eET_YuanShiDanHao)->SetWString(L"原始单号");
		sheet->Cell(0, eET_DianPu)->SetWString(L"店铺");
		sheet->Cell(0, eET_ZhongLiang)->SetWString(L"重量");
		sheet->Cell(0, eET_FaHuoShiJian)->SetWString(L"发货时间");
		sheet->Cell(0, eET_HuoPinZongShuLiang)->SetWString(L"货品总数量");
		sheet->Cell(0, eET_HuoPinMingXi)->SetWString(L"货品明细");
		sheet->Cell(0, eET_JiFeiZhongLiang)->SetWString(L"计费重量");
		sheet->Cell(0, eET_WuLiuFei)->SetWString(L"物流费");
		sheet->Cell(0, eET_WuLiuChengBen)->SetWString(L"物流成本");
		sheet->Cell(0, eET_HaoCaiFei)->SetWString(L"耗材费");
		sheet->Cell(0, eET_CaoZuoFei)->SetWString(L"操作费");
		sheet->Cell(0, eET_ZengZhiFeiYong)->SetWString(L"增值费用");
		sheet->Cell(0, eET_BeiZhu)->SetWString(L"备注");
		std::list<sSalesInfo>::iterator itB = listSalesInfo.begin();
		std::list<sSalesInfo>::iterator itE = listSalesInfo.end();
		while(itB != itE)
		{
			itB->nRow = nRecordRowIndex;
			sheet->Cell(nRecordRowIndex, eET_ShouJianRen)->SetWString(itB->strShouJianRen.c_str());
			sheet->Cell(nRecordRowIndex, eET_ShouJianRenDiZhi)->SetWString(itB->strShouJianRenDiZhi.c_str());
			sheet->Cell(nRecordRowIndex, eET_Sheng)->SetWString(itB->strSheng.c_str());
			sheet->Cell(nRecordRowIndex, eET_WuLiuGongSi)->SetWString(itB->strWuLiuGongSi.c_str());
			sheet->Cell(nRecordRowIndex, eET_WuLiuDanHao)->SetWString(itB->strWuLiuDanHao.c_str());
			sheet->Cell(nRecordRowIndex, eET_YuanShiDanHao)->SetWString(itB->strYuanShiDanHao.c_str());
			sheet->Cell(nRecordRowIndex, eET_DianPu)->SetWString(itB->strDianPu.c_str());
			sheet->Cell(nRecordRowIndex, eET_ZhongLiang)->SetWString(itB->strZhongLiang.c_str());
			sheet->Cell(nRecordRowIndex, eET_FaHuoShiJian)->SetWString(itB->strFaHuoShijian.c_str());
			sheet->Cell(nRecordRowIndex, eET_HuoPinZongShuLiang)->SetWString(itB->strHuoPinZongShuLiang.c_str());
			sheet->Cell(nRecordRowIndex, eET_HuoPinMingXi)->SetWString(itB->strHuoPinMingXi.c_str());
			//待计算
			sheet->Cell(nRecordRowIndex, eET_JiFeiZhongLiang)->SetWString(L"0");
			sheet->Cell(nRecordRowIndex, eET_WuLiuFei)->SetWString(L"0");
			if(itB->strWuLiuGongSi == L"顺丰热敏")
			{
				std::map<std::wstring, sSFAuthData>::iterator it = m_mapSFAuthData.find(itB->strWuLiuDanHao);
				if(it != m_mapSFAuthData.end())
					sheet->Cell(nRecordRowIndex, eET_WuLiuChengBen)->SetWString(it->second.needPay.c_str());
				else
				{
					wchar_t szBuffer[128] = { 0 };
					wsprintfW(szBuffer, L"未找到顺丰成本 单号=%s 货主=%s", itB->strWuLiuDanHao.c_str(), itB->strHuoZhu.c_str());
					AddLog(szBuffer);
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
	return true;
}


bool CStorageBillDlg::Handle_MoHeKeJi()
{
	BasicExcel excel;
	if(!CreateExcel(excel, m_mapAllSalesInfo[L"魔合科技N"], m_mapInStorageInfo[L"魔合科技N"]))
		return false;
	wstring fileName = L"./Export_" + m_strYM + L"/" + L"魔合科技N_" + m_strYM + L"对账单.xls";
	string _file = CFuncCommon::WString2String(fileName.c_str());
	CompareWithSFData(L"魔合科技N", m_mapAllSalesInfo[L"魔合科技N"]);
	//计算相关费用
	//单独TH-043和单独TH-042按拆单价格
	{
		BasicExcelWorksheet* sheet = excel.GetWorksheet(L"订单费用");
		if(sheet)
		{
			std::list<sSalesInfo>& listSales = m_mapAllSalesInfo[L"魔合科技N"];
			std::list<sSalesInfo>::iterator itB = listSales.begin();
			std::list<sSalesInfo>::iterator itE = listSales.end();
			while(itB != itE)
			{
				wstring strBeiZhu = L"";
				int nWeight = 0;
				wchar_t decimal1 = itB->strZhongLiang.at(itB->strZhongLiang.size() - 1);
				wchar_t decimal2 = itB->strZhongLiang.at(itB->strZhongLiang.size() - 2);
				if(decimal1 != L'0' || decimal2 != L'0')
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
					if(itB->strZhongLiang == L"0.00")
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
					if(itB->strWuLiuGongSi == L"顺丰热敏")
					{
						double money = GetSFPrice(nWeight, itB->strSheng, g_moHeKeJiSFPrice);
						std::map<std::wstring, sSFAuthData>::iterator itSF = m_mapSFAuthData.find(itB->strWuLiuDanHao);
						if(itSF != m_mapSFAuthData.end())
						{
							if(itSF->second.backPay != L"")
							{
								double backPay = _wtof(itSF->second.backPay.c_str());
								money += backPay;
								strBeiZhu = strBeiZhu + L"转寄退回";
							}
							double needPay = _wtof(itSF->second.needPay.c_str());
							if(needPay > money)
							{
								std::set<std::wstring>::iterator it = m_setSFZhongLiangYiChang.find(itB->strWuLiuDanHao.c_str());
								if(it == m_setSFZhongLiangYiChang.end())
								{
									BasicExcelWorksheet* recordSheet = m_recordExcel.GetWorksheet(g_arrWorksheetName[2]);
									recordSheet->Cell(g_arrRecordRowIndex[2], 0)->SetWString(itB->strWuLiuDanHao.c_str());
									recordSheet->Cell(g_arrRecordRowIndex[2], 1)->SetWString(itB->strHuoZhu.c_str());
									g_arrRecordRowIndex[2]++;
								}
							}
						}
						if(itB->nBaoJiaJinE != 0)
						{
							if(itB->nBaoJiaJinE > 1000)
								dZengZhi += int(itB->nBaoJiaJinE*0.005);
							else
								dZengZhi += 2;

							if(strBeiZhu == L"")
								strBeiZhu = strBeiZhu + L"保价";
							else
								strBeiZhu = strBeiZhu + L" | 保价";
						}
						sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1).c_str());


					}
					else if(itB->strWuLiuGongSi == L"百世线下(分拨)")
					{
						double money = 0;
						if(nWeight > 0)
						{
							double money = GetBSPrice(nWeight, itB->strSheng, g_moHeKeJiBSPrice);
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
					//如果是拆分的订单
					double _price = 0.0;
					int nZSL = _wtoi(itB->strHuoPinZongShuLiang.c_str());
					if(itB->bChaiFen)
					{
						if(nZSL > 6)
							_price = 0.5+(nZSL-6)*0.1;
						else
							_price = 0.5;
						
					}
					else
					{
						if(nZSL > 8)
							_price = 0.6 + (nZSL - 8)*0.1;
						else
							_price = 0.6;
					}
					sheet->Cell(itB->nRow, eET_CaoZuoFei)->SetWString(CFuncCommon::Double2WString(_price + DOUBLE_PRECISION, 1).c_str());
				}
				++itB;
			}
		}

	}

	excel.SaveAs(_file.c_str());
	return true;
}

bool CStorageBillDlg::Handle_TaiFuShangMao()
{

	BasicExcel excel;
	if(!CreateExcel(excel, m_mapAllSalesInfo[L"泰福商贸"], m_mapInStorageInfo[L"泰福商贸"]))
		return false;
	wstring fileName = L"./Export_" + m_strYM + L"/" + L"泰福商贸_" + m_strYM + L"对账单.xls";
	string _file = CFuncCommon::WString2String(fileName.c_str());
	CompareWithSFData(L"泰福商贸", m_mapAllSalesInfo[L"泰福商贸"]);
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
				wchar_t decimal1 = itB->strZhongLiang.at(itB->strZhongLiang.size() - 1);
				wchar_t decimal2 = itB->strZhongLiang.at(itB->strZhongLiang.size() - 2);
				if(decimal1 != L'0' || decimal2 != L'0')
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
					if(itB->strZhongLiang == L"0.00")
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
					if(itB->strWuLiuGongSi == L"顺丰热敏")
					{
						double money = GetSFPrice(nWeight, itB->strSheng, g_moHeKeJiSFPrice);
						std::map<std::wstring, sSFAuthData>::iterator itSF = m_mapSFAuthData.find(itB->strWuLiuDanHao);
						if(itSF != m_mapSFAuthData.end())
						{
							if(itSF->second.backPay != L"")
							{
								double backPay = _wtof(itSF->second.backPay.c_str());
								money += backPay;
								strBeiZhu = strBeiZhu + L"转寄退回";
							}
							double needPay = _wtof(itSF->second.needPay.c_str());
							if(needPay > money)
							{
								std::set<std::wstring>::iterator it = m_setSFZhongLiangYiChang.find(itB->strWuLiuDanHao.c_str());
								if(it == m_setSFZhongLiangYiChang.end())
								{
									BasicExcelWorksheet* recordSheet = m_recordExcel.GetWorksheet(g_arrWorksheetName[2]);
									recordSheet->Cell(g_arrRecordRowIndex[2], 0)->SetWString(itB->strWuLiuDanHao.c_str());
									recordSheet->Cell(g_arrRecordRowIndex[2], 1)->SetWString(itB->strHuoZhu.c_str());
									g_arrRecordRowIndex[2]++;
								}
							}
						}
						if(itB->nBaoJiaJinE != 0)
						{
							if(itB->nBaoJiaJinE > 1000)
								dZengZhi += int(itB->nBaoJiaJinE*0.005);
							else
								dZengZhi += 2;

							if(strBeiZhu == L"")
								strBeiZhu = strBeiZhu + L"保价";
							else
								strBeiZhu = strBeiZhu + L" | 保价";
						}
						sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1).c_str());


					}
					else if(itB->strWuLiuGongSi == L"百世线下(分拨)")
					{
						double money = 0;
						if(nWeight > 0)
						{
							double money = GetBSPrice(nWeight, itB->strSheng, g_taiFuShangMaoBSPrice);
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
	return true;
}

bool CStorageBillDlg::Handle_YongChuangYaoHui()
{
	BasicExcel excel;
	if(!CreateExcel(excel, m_mapAllSalesInfo[L"永创耀辉"], m_mapInStorageInfo[L"永创耀辉"]))
		return false;
	wstring fileName = L"./Export_" + m_strYM + L"/" + L"永创耀辉_" + m_strYM + L"对账单.xls";
	string _file = CFuncCommon::WString2String(fileName.c_str());
	CompareWithSFData(L"永创耀辉", m_mapAllSalesInfo[L"永创耀辉"]);

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
				wchar_t decimal1 = itB->strZhongLiang.at(itB->strZhongLiang.size()-1);
				wchar_t decimal2 = itB->strZhongLiang.at(itB->strZhongLiang.size()-2);
				if(decimal1 != L'0' || decimal2 != L'0')
				{
					double nZhongLiang = _wtof(itB->strZhongLiang.c_str());
					nZhongLiang += 1;
					nZhongLiang += DOUBLE_PRECISION;
					nWeight = int(nZhongLiang);
					if(nWeight < 3)
						nWeight = 3;
					wchar_t szWeight[10] ={0};
					_itow_s(nWeight, szWeight, 10);
					sheet->Cell(itB->nRow, eET_JiFeiZhongLiang)->SetWString(szWeight);
				}
				else
				{
					if(itB->strZhongLiang == L"0.00")
						nWeight = 0;
					else
					{
						nWeight = _wtoi(itB->strZhongLiang.c_str());
						if(nWeight < 3)
							nWeight = 3;
					}
					
					wchar_t szWeight[10] ={0};
					_itow_s(nWeight, szWeight, 10);
					sheet->Cell(itB->nRow, eET_JiFeiZhongLiang)->SetWString(szWeight);
				}
				double dZengZhi = 0;
				//计算物流费
				{
					if(itB->strWuLiuGongSi == L"顺丰热敏")
					{
						double money = GetSFPrice(nWeight, itB->strSheng, g_yongChuangYaoHuiSFPrice);
						int sourceBJ = 0;
						std::map<std::wstring, sSFAuthData>::iterator itSF = m_mapSFAuthData.find(itB->strWuLiuDanHao);
						if(itSF != m_mapSFAuthData.end())
						{
							sourceBJ = _wtoi(itSF->second.bjPay.c_str());
							if(itSF->second.backPay != L"")
							{
								double backPay = _wtof(itSF->second.backPay.c_str());
								money += backPay;
								strBeiZhu = strBeiZhu + L"转寄退回";
							}
							double needPay = _wtof(itSF->second.needPay.c_str());
							if(needPay > money)
							{
								std::set<std::wstring>::iterator it = m_setSFZhongLiangYiChang.find(itB->strWuLiuDanHao.c_str());
								if(it == m_setSFZhongLiangYiChang.end())
								{
									wchar_t szOut[120] = { 0 };
									_swprintf(szOut, L"[顺丰费用异常] 货主=%s 单号=%s", itB->strHuoZhu.c_str(), itB->strWuLiuDanHao.c_str());
									AddLog(szOut);

									BasicExcelWorksheet* recordSheet = m_recordExcel.GetWorksheet(g_arrWorksheetName[2]);
									recordSheet->Cell(g_arrRecordRowIndex[2], 0)->SetWString(itB->strWuLiuDanHao.c_str());
									recordSheet->Cell(g_arrRecordRowIndex[2], 1)->SetWString(itB->strHuoZhu.c_str());
									g_arrRecordRowIndex[2]++;
								}
							}
						}
						if(itB->nBaoJiaJinE != 0 || sourceBJ > 0)
						{
							int nLocalBj = 0;
							if(itB->nBaoJiaJinE > 1000)
								nLocalBj = int(itB->nBaoJiaJinE*0.005);
							else
								nLocalBj = 2;

							dZengZhi += max(nLocalBj, sourceBJ);

							if(strBeiZhu == L"")
								strBeiZhu = strBeiZhu + L"保价";
							else
								strBeiZhu = strBeiZhu + L" | 保价";
						}
						sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money+DOUBLE_PRECISION, 1).c_str());


					}
					else if(itB->strWuLiuGongSi == L"百世快运")
						sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(L"3.5");
					else if(itB->strWuLiuGongSi == L"中通快运")
						sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(L"3.5");
					else if(itB->strWuLiuGongSi == L"百世线下(分拨)")
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
					else
					{
						wchar_t szOut[120] ={0};
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
						sheet->Cell(itB->nRow, eET_ZengZhiFeiYong)->SetWString(CFuncCommon::Double2WString(dZengZhi+DOUBLE_PRECISION,1).c_str());
				}
				sheet->Cell(itB->nRow, eET_BeiZhu)->SetWString(strBeiZhu.c_str());
				++itB;
			}
		}

	}
	excel.SaveAs(_file.c_str());

	return true;
}

bool CStorageBillDlg::Handle_MiYaShiQi()
{
	BasicExcel excel;
	if(!CreateExcel(excel, m_mapAllSalesInfo[L"弥雅食器"], m_mapInStorageInfo[L"弥雅食器"]))
		return false;
	wstring fileName = L"./Export_" + m_strYM + L"/" + L"弥雅食器_" + m_strYM + L"对账单.xls";
	string _file = CFuncCommon::WString2String(fileName.c_str());
	excel.SaveAs(_file.c_str());
	CompareWithSFData(L"弥雅食器", m_mapAllSalesInfo[L"弥雅食器"]);
	return true;
}

bool CStorageBillDlg::LoadBSData()
{
	if(!m_bBS)
		return true;
	std::wstring strBSFileName = BS_FILE_PATH;
	std::string _strBSFileName = CFuncCommon::WString2String(strBSFileName.c_str());
	m_bsExcel.Load(_strBSFileName.c_str());
	BasicExcelWorksheet* bsSheet = m_bsExcel.GetWorksheet(L"Sheet");

	if(bsSheet)
	{
		size_t maxRows = bsSheet->GetTotalRows();
		size_t maxCols = bsSheet->GetTotalCols();
		m_sfHandleCol = maxCols;
		//load tile
		int colNumber = -1;
		int colWeight = -1;
		int needPay1 = -1;
		int needPay2 = -1;
		int needPay3 = -1;
		int needPay4 = -1;
		int needPay5 = -1;
		for(size_t c = 0; c < maxCols; ++c)
		{
			BasicExcelCell* cell = bsSheet->Cell(0, c);
			std::wstring strTitle = cell->GetWString();
			if(strTitle == L"运单编号")
				colNumber = c;
			else if(strTitle == L"总部计费重量")
				colWeight = c;
			else if(strTitle == L"总部收中转费")
				needPay1 = c;
			else if(strTitle == L"总部收有偿派费")
				needPay2 = c;
			else if(strTitle == L"总部收计重费")
				needPay3 = c;
			else if(strTitle == L"总部收扫描费")
				needPay4 = c;
			else if(strTitle == L"总部收寄件派费")
				needPay5 = c;
		}
		if(colNumber == -1 || colWeight == -1 || needPay1 == -1 || needPay2 == -1 || needPay3 == -1 || needPay4 == -1 || needPay5 == -1)
		{
			THROW_ERROR(L"百世账单 有标题未找到");
		}

		for(size_t r = 1; r < maxRows; ++r)
		{
			sBSAuthData _data;
			const wchar_t* _pStr = NULL;
			SHEET_CELL_STRING(bsSheet, r, colNumber, _data.number);
			SHEET_CELL_DOUBLE(bsSheet, r, colWeight, _data.weight);
			SHEET_CELL_DOUBLE(bsSheet, r, needPay1, _data.needPay1);
			SHEET_CELL_DOUBLE(bsSheet, r, needPay2, _data.needPay2);
			SHEET_CELL_DOUBLE(bsSheet, r, needPay3, _data.needPay3);
			SHEET_CELL_DOUBLE(bsSheet, r, needPay4, _data.needPay4);
			SHEET_CELL_DOUBLE(bsSheet, r, needPay5, _data.needPay5);
			_data.row = r;
			m_mapBSAuthData[_data.number] = _data;
		}
	}
	else
	{
		THROW_ERROR(L"读取百世账单失败");
	}
	m_bsExcel.Save();
	return true;
}

bool CStorageBillDlg::LoadSFData()
{
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
			else if(strTitle == L"对账结果")
			{
				bFix = true;
				m_sfHandleCol = c;
			}
		}		
		if(colNumber == -1 || colWeight == -1 || colVAServices == -1 || colNeedPay == -1)
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
			_data.row = r;
			if(_data.vaServices == L"保价")
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
					THROW_ERROR(szBuffer);
				}
				sfSheet->Cell(r, m_sfHandleCol)->SetWString(L"1");
				continue;
			}
			if(_data.vaServices == L"转寄退回")
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
					THROW_ERROR(szBuffer);
				}
				sfSheet->Cell(r, m_sfHandleCol)->SetWString(L"1");
				continue;
			}
			_pStr = sfSheet->Cell(r, m_sfHandleCol)->GetWString();
			if(_pStr)
			{
				if(wcscmp(_pStr, L"1") == 0)
					_data.bHandle = true;
			}
			m_mapSFAuthData[_data.number] = _data;
		}
	}
	else
	{
		THROW_ERROR(L"读取顺丰账单失败");
	}
	m_sfExcel.Save();
	return true;
}

bool CStorageBillDlg::CompareWithSFData(std::wstring strHuoZhu, std::list<sSalesInfo>& listInfo)
{
	if(!m_bSF)
		return true;
	BasicExcelWorksheet* recordSheet = m_recordExcel.GetWorksheet(g_arrWorksheetName[0]);
	if(recordSheet == NULL)
		return false;
	BasicExcelWorksheet* sfSheet = m_sfExcel.GetWorksheet(L"Sheet0");
	if(sfSheet == NULL)
		return false;
	std::list<sSalesInfo>::iterator itYCBegin = listInfo.begin();
	std::list<sSalesInfo>::iterator itYCEnd = listInfo.end();
	while(itYCBegin != itYCEnd)
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
					itYCBegin->strZhongLiang = CFuncCommon::Double2WString(finalWeight+DOUBLE_PRECISION, 2);
				}
				if(finalWeight < dSFWeight)
				{
					recordSheet->Cell(g_arrRecordRowIndex[0], 0)->SetWString(itSF->first.c_str());
					recordSheet->Cell(g_arrRecordRowIndex[0], 1)->SetDouble(dSFWeight);
					recordSheet->Cell(g_arrRecordRowIndex[0], 2)->SetWString(itYCBegin->strZhongLiang.c_str());
					recordSheet->Cell(g_arrRecordRowIndex[0], 3)->SetDouble(finalWeight);
					g_arrRecordRowIndex[0]++;
					sfSheet->Cell(itSF->second.row, m_sfHandleCol)->SetWString(L"0");
					m_setSFZhongLiangYiChang.insert(itSF->first.c_str());
				}
				else
				{
					itSF->second.bHandle = true;
					sfSheet->Cell(itSF->second.row, m_sfHandleCol)->SetWString(L"1");
				}
			}
			m_mapYCNeedSFHandle[strHuoZhu].erase(itYCBegin->strWuLiuDanHao);
		}
		++itYCBegin;
	}

	{
		BasicExcelWorksheet* recordSheet = m_recordExcel.GetWorksheet(g_arrWorksheetName[1]);
		std::set<std::wstring>::iterator itB = m_mapYCNeedSFHandle[strHuoZhu].begin();
		std::set<std::wstring>::iterator itE = m_mapYCNeedSFHandle[strHuoZhu].end();
		while(itB != itE)
		{
			recordSheet->Cell(g_arrRecordRowIndex[1], 0)->SetWString(itB->c_str());
			recordSheet->Cell(g_arrRecordRowIndex[1], 1)->SetWString(strHuoZhu.c_str());
			g_arrRecordRowIndex[1]++;
			++itB;
		}
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


double CStorageBillDlg::GetSFPrice(int nWeight, wstring strSheng, double price[][2])
{
	double* _price = NULL;
	if(strSheng == L"四川省" || strSheng == L"重庆")
		_price = price[0];
	else if(strSheng == L"贵州省" || strSheng == L"湖北省" || strSheng == L"陕西省" || strSheng == L"云南省")
		_price = price[1];
	else if(strSheng == L"安徽省" || strSheng == L"北京" || strSheng == L"福建省" || strSheng == L"甘肃省" || strSheng == L"广东省" || strSheng == L"广西壮族自治区" || strSheng == L"海南省" || strSheng == L"河北省" || strSheng == L"河南省" || strSheng == L"湖南省" || strSheng == L"江苏省" || strSheng == L"江西省" || strSheng == L"宁夏回族自治区" || strSheng == L"青海省" || strSheng == L"山东省" || strSheng == L"山西省" || strSheng == L"上海" || strSheng == L"天津" || strSheng == L"浙江省")
		_price = price[2];
	else if(strSheng == L"黑龙江省" || strSheng == L"吉林省" || strSheng == L"辽宁省" || strSheng == L"内蒙古自治区" || strSheng == L"新疆维吾尔自治区" || strSheng == L"西藏自治区")
		_price = price[3];
	else
	{
		wchar_t szBuffer[128] ={0};
		wsprintfW(szBuffer, L"顺丰 未知省份 %s", strSheng.c_str());
		THROW_ERROR(szBuffer);
	}

	if(nWeight>0 && nWeight<=3)
		return _price[0];
	else if(nWeight > 3)
	{
		return _price[0] + _price[1]*(nWeight-3);
	}
	return 0.0;
}

double CStorageBillDlg::GetBSPrice(int nWeight, wstring strSheng, std::map< std::wstring, std::list<sExpressPriceInfo> >& mapPrice)
{
	std::map< std::wstring, std::list<sExpressPriceInfo> >::iterator it = mapPrice.find(strSheng);
	if(it != mapPrice.end())
	{
		std::list<sExpressPriceInfo>::iterator itB = it->second.begin();
		std::list<sExpressPriceInfo>::iterator itE = it->second.end();
		while(itB != itE)
		{
			if(nWeight > itB->nMinZL && (nWeight <= itB->nMaxZL || itB->nMaxZL == 0))
			{
				if(nWeight <= itB->nFirstZL)
					return itB->dFirstPrice;
				else
					return itB->dFirstPrice + (nWeight-itB->nFirstZL)*itB->dXZPrice;
			}
			++itB;
		}
		wchar_t szBuffer[128] = { 0 };
		wsprintfW(szBuffer, L"百世快递 重量不含有对应价格区间 %s %d", strSheng.c_str(), nWeight);
		THROW_ERROR(szBuffer);
	}
	else
	{
		wchar_t szBuffer[128] = { 0 };
		wsprintfW(szBuffer, L"百世快递 未知省份 %s", strSheng.c_str());
		THROW_ERROR(szBuffer);
	}
	return 0.0;
}