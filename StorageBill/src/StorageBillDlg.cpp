
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

const wchar_t* g_arrWorksheetName[] ={L"顺丰重量差异订单", L"顺丰云仓未处理单号", L"顺丰价格异常", L"百世快递重量差异订单", L"中通快运重量差异订单", L"中通快运费用差异订单"};
int g_arrRecordRowIndex[] ={0, 0, 0, 0, 0, 0};
const wchar_t* g_arrHuoZhuName[] ={L"永创耀辉", L"弥雅食器", L"泰福商贸", L"颐麦科技", L"新马帮", L"七一酱园", L"永创昆仑山", L"凡将", L"韩太郎", L"玖王"};

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
m_bExit(false), m_bRun(false), m_sfHandleCol(-1), m_bskdHandleCol(-1), m_ztkyHandleCol(-1)
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
	m_checkBSKD.SetCheck(1);
	m_checkZTKY.SetCheck(1);
	m_bSFErrorPrice = false;
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
			if(!LoadBSKDData())
				goto __break_logic;
			if(!LoadZTKYData())
				goto __break_logic;
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
			}
			wstring filePath = L"./Export_" + m_strYM + L"/" + L"compare_record.xls";
			string _filePath = CFuncCommon::WString2String(filePath.c_str());
			m_recordExcel.SaveAs(_filePath.c_str());
			m_sfExcel.Save();
			m_bskdExcel.Save();
			m_ztkyExcel.Save();
			AddLog(L"账单生成完成");


			AddLog(L"[昆仑山矿泉水K6—510ml] 包装盒");
			AddLog(L"[45度小郎酒（精酿）分享装100ml*6] [45度小郎酒（精酿）100ml] [45度经典小郎酒100ml] [45度小郎酒（经典）分享装100ml*6] 包装盒");
			AddLog(L"[五粮液歪嘴酒100ml] 包装盒");
			AddLog(L"顺丰 [贵州茅台酒飞天茅台53度酱香型白酒1.5L] [五粮液1618珍酿52度3L] [贵州茅台酒飞天茅台53度酱香型白酒3L] [贵州茅台酒飞天茅台53度酱香型白酒6L] 包装盒");
			AddLog(L"顺丰 整件酒包装盒");
			AddLog(L"罗永浩带货 价格修改");
			AddLog(L"辣风芹 刷单价格修改  代发50多单顺丰价格修改");
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
	m_bBSKD = (m_checkBSKD.GetState()==1);
	m_bZYKY = (m_checkZTKY.GetState()==1);
	m_bYG = (m_checkYGZD.GetState()==1);
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
		return false;
	}
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
				wsprintfW(szBuffer, L"%s 未找到单号%s", wfileName.c_str(), strWuLiuDanHao.c_str());
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
			int nBjsl = _wtoi(strHuoPinShuLiang.c_str());
			std::map< std::wstring, int >::iterator itBJ = m_mapBaoJiaJinE.find(strHuoPinMingCheng);
			if(itBJ != m_mapBaoJiaJinE.end())
				it->second->nBaoJiaJinE += itBJ->second*nBjsl;
			else if(it->second->strHuoZhu == L"永创耀辉" && strPinPai != L"昆仑山" && (itB->second->strWuLiuGongSi == L"顺丰热敏(线下)" || itB->second->strWuLiuGongSi == L"顺丰热敏(拼多多)"))
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
		return false;
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
			if((_data.strWuLiuGongSi == L"顺丰热敏(线下)" || _data.strWuLiuGongSi == L"顺丰热敏(拼多多)") && m_bSF)
				m_mapYCNeedSFHandle[_data.strHuoZhu].insert(_data.strWuLiuDanHao);
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

bool CStorageBillDlg::ParseALLData()
{
	std::wstring strTotalFileName = TOTAL_FILE_PATH;
	std::wstring strDetailFileName = DETAIL_FILE_PATH;
	std::wstring strInStorageFileName = IN_STORAGE_PATH;
	std::wstring strKuaiYunWeightFileName = KUAI_YUN_WEIGHT_FILE_PATH;
	BasicExcel inStorageExcel;
	BasicExcel kuaiYunWeightExcel;
	BasicExcel baoJiaExcel;
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
	for(int i=1; i<10; ++i)
	{
		wchar_t szBuffer[128] ={0};
		wsprintfW(szBuffer, L"%s%d.xls", strTotalFileName.c_str(), i);
		LoadXiaoShouChuKuDan(szBuffer, i==1);
	}
	for(int i=1; i<10; ++i)
	{
		wchar_t szBuffer[128] ={0};
		wsprintfW(szBuffer, L"%s%d.xls", strDetailFileName.c_str(), i);
		LoadXiaoShouChuKuMingXi(szBuffer, i==1);
	}
	
	std::map< std::wstring, sSalesInfo* >::iterator itTmpB = m_mapTempSalesInfo.begin();
	std::map< std::wstring, sSalesInfo* >::iterator itTmpE = m_mapTempSalesInfo.end();
	while(itTmpB != itTmpE)
	{
		if(itTmpB->second->bKunLunShan)
		{
			if(itTmpB->second->strWuLiuGongSi.find(L"快运") == std::string::npos && itTmpB->second->strZhongLiang == L"0.00")
			{
				if(itTmpB->second->strHuoPinMingXi == L"昆仑山矿泉水K4-4L@1")
					itTmpB->second->strZhongLiang = L"17.90";
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
			}
		}
		++itTmpB;
	}

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
				wsprintfW(szBuffer, L"快运出库重量 未找到单号%s", strWuLiuDanHao.c_str());
				THROW_ERROR(szBuffer);
			}
			it->second->strZhongLiang = CFuncCommon::Double2WString(dZhongLiang+DOUBLE_PRECISION, 2);
		}
		AddLog(L"读取快运出库重量成功");
	}
	else
	{
		THROW_ERROR(L"快运出库重量 加载失败");
	}
	m_mapTempSalesInfo.clear();
	if(!m_bYG)
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

bool CStorageBillDlg::CreateExcel(BasicExcel& excel, std::list<sSalesInfo>& listSalesInfo, std::map<std::wstring, sInStorageInfo>& mapInStorageInfo)
{
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
		sheet->Cell(0, eET_BaoZhuang)->SetWString(L"包装");
		sheet->Cell(0, eET_WuLiuFei)->SetWString(L"物流费");
		sheet->Cell(0, eET_WuLiuChengBen)->SetWString(L"物流成本");
		sheet->Cell(0, eET_HaoCaiFei)->SetWString(L"耗材费");
		sheet->Cell(0, eET_CaoZuoFei)->SetWString(L"操作费");
		sheet->Cell(0, eET_ZengZhiFeiYong)->SetWString(L"增值费用");
		sheet->Cell(0, eET_BeiZhu)->SetWString(L"备注");
		sheet->Cell(0, eET_KeFuBeiZhu)->SetWString(L"客服备注");
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
			if(itB->strWuLiuGongSi == L"顺丰热敏(线下)" || itB->strWuLiuGongSi == L"顺丰热敏(拼多多)")
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
			else if(itB->strWuLiuGongSi == L"百世线下(分拨)" || itB->strWuLiuGongSi == L"百世快递(菜鸟)" || itB->strWuLiuGongSi == L"百世快递(拼多多)")
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
			else if(itB->strWuLiuGongSi == L"中通快运" || itB->strWuLiuGongSi == L"中通快运(菜鸟)")
			{
				if(m_bZYKY)
				{
					std::map<std::wstring, sZTKYAuthData>::iterator it = m_mapZYKYAuthData.find(itB->strWuLiuDanHao);
					if(it != m_mapZYKYAuthData.end())
						sheet->Cell(nRecordRowIndex, eET_WuLiuChengBen)->SetWString(CFuncCommon::Double2WString(it->second.wuliuPay + it->second.shanglowPay + DOUBLE_PRECISION, 1).c_str());
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
	CompareWithBSKDData(L"泰福商贸", m_mapAllSalesInfo[L"泰福商贸"]);
	CompareWithZTKYData(L"泰福商贸", m_mapAllSalesInfo[L"泰福商贸"]);
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
					if(itB->strWuLiuGongSi == L"百世线下(分拨)" || itB->strWuLiuGongSi == L"百世快递(菜鸟)" || itB->strWuLiuGongSi == L"百世快递(拼多多)")
					{
						double money = 0;
						if(nWeight > 0)
						{
							double money = GetKDPrice(nWeight, itB->strSheng, g_taiFuShangMaoBSPrice, L"百世快递");
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
	if(!CreateExcel(excel, listKunLunShanSales, mapKunLunShanInStorage))
		return false;
	wstring fileName = L"./Export_" + m_strYM + L"/" + L"永创昆仑山_" + m_strYM + L"对账单.xls";
	string _file = CFuncCommon::WString2String(fileName.c_str());
	CompareWithSFData(L"永创耀辉", listKunLunShanSales, true);
	CompareWithBSKDData(L"永创耀辉", listKunLunShanSales);
	CompareWithZTKYData(L"永创耀辉", listKunLunShanSales);
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
				wchar_t decimal1 = itB->strZhongLiang.at(itB->strZhongLiang.size() - 1);
				wchar_t decimal2 = itB->strZhongLiang.at(itB->strZhongLiang.size() - 2);
				if(decimal1 != L'0' || decimal2 != L'0')
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
				//计算物流费
				{
					if(itB->strWuLiuGongSi == L"顺丰热敏(线下)" || itB->strWuLiuGongSi == L"顺丰热敏(拼多多)")
					{
						double money = GetSFPrice(nWeight, itB->strSheng, g_yongChuangYaoHuiSFPrice);
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
							if(itSF->second.type != L"特惠专配")
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
					else if(itB->strWuLiuGongSi == L"百世线下(分拨)" || itB->strWuLiuGongSi == L"百世快递(菜鸟)" || itB->strWuLiuGongSi == L"百世快递(拼多多)" || itB->strWuLiuGongSi == L"百世快运" || itB->strWuLiuGongSi == L"中通快运" || itB->strWuLiuGongSi == L"中通快运(菜鸟)")
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
								   _itB->first != L"昆仑山保湿水100ml" &&_itB->first != L"昆仑山保湿水300ml" && 
								   _itB->first != L"昆仑山矿泉水510mL(单瓶大包装)" &&_itB->first != L"昆仑山矿泉水1.23L(单瓶)"
								   )
								{
									bChunShui = false;
									break;
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
										money += (GetKDPrice(19, itB->strSheng, g_kunLunShanYTPrice, L"圆通快递")*_itB->second);
									}
									else if(_itB->first == L"昆仑山矿泉水K12-510ml（小包装）")
									{
										money += (GetKDPrice(7, itB->strSheng, g_kunLunShanYTPrice, L"圆通快递")*_itB->second);
									}
									else if(_itB->first == L"昆仑山矿泉水K24-350mL（大包装）")
									{
										money += (GetKDPrice(10, itB->strSheng, g_kunLunShanYTPrice, L"圆通快递")*_itB->second);
									}
									else if(_itB->first == L"昆仑山矿泉水K12-350mL（小包装）")
									{
										money += (GetKDPrice(5, itB->strSheng, g_kunLunShanYTPrice, L"圆通快递")*_itB->second);
									}
									else if(_itB->first == L"昆仑山矿泉水K12-1.23L")
									{
										money += (GetKDPrice(17, itB->strSheng, g_kunLunShanYTPrice, L"圆通快递")*_itB->second);
									}
									else if(_itB->first == L"昆仑山矿泉水K24-510mL（大包装）")
									{
										money += (GetKDPrice(14, itB->strSheng, g_kunLunShanYTPrice, L"圆通快递")*_itB->second);
									}
									else if(_itB->first == L"昆仑山矿泉水510mL(单瓶大包装)")
									{
										money += (GetKDPrice(1, itB->strSheng, g_kunLunShanYTPrice, L"圆通快递")*_itB->second);
									}
									else if(_itB->first == L"昆仑山矿泉水1.23L(单瓶)")
									{
										money += (GetKDPrice(2, itB->strSheng, g_kunLunShanYTPrice, L"圆通快递")*_itB->second);
									}
									else if(_itB->first == L"昆仑山保湿水100ml")
									{
										money += (GetKDPrice(1, itB->strSheng, g_kunLunShanYTPrice, L"圆通快递")*_itB->second);
									}
									else if(_itB->first == L"昆仑山保湿水300ml")
									{
										money += (GetKDPrice(1, itB->strSheng, g_kunLunShanYTPrice, L"圆通快递")*_itB->second);
									}
									++_itB;
								}
								sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1).c_str());
							}
						}
						if(itB->strWuLiuGongSi == L"中通快运" || itB->strWuLiuGongSi == L"中通快运(菜鸟)")
						{
							std::map<std::wstring, sZTKYAuthData>::iterator itZTKY = m_mapZYKYAuthData.find(itB->strWuLiuDanHao);
							if(itZTKY != m_mapZYKYAuthData.end())
							{
								double chengbenMoney = GetKYPrice(nWeight, itB->strSheng, itB->strShi, g_chengBenZTKYPrice);
								if(chengbenMoney+DOUBLE_PRECISION  < itZTKY->second.wuliuPay)
								{
									BasicExcelWorksheet* recordSheet = m_recordExcel.GetWorksheet(g_arrWorksheetName[5]);
									recordSheet->Cell(g_arrRecordRowIndex[5], 0)->SetWString(L"永创耀辉");
									recordSheet->Cell(g_arrRecordRowIndex[5], 1)->SetWString(itB->strWuLiuDanHao.c_str());
									recordSheet->Cell(g_arrRecordRowIndex[5], 2)->SetWString(CFuncCommon::Double2WString(itZTKY->second.wuliuPay + DOUBLE_PRECISION, 1).c_str());
									recordSheet->Cell(g_arrRecordRowIndex[5], 3)->SetWString(CFuncCommon::Double2WString(chengbenMoney + DOUBLE_PRECISION, 1).c_str());
									g_arrRecordRowIndex[5]++;
								}

								if(itZTKY->second.shanglowPay > DOUBLE_PRECISION)
								{
									dZengZhi += itZTKY->second.shanglowPay;
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
	if(!CreateExcel(excel, m_mapAllSalesInfo[L"永创耀辉"], m_mapInStorageInfo[L"永创耀辉"]))
		return false;
	wstring fileName = L"./Export_" + m_strYM + L"/" + L"永创耀辉_" + m_strYM + L"对账单.xls";
	string _file = CFuncCommon::WString2String(fileName.c_str());
	CompareWithSFData(L"永创耀辉", m_mapAllSalesInfo[L"永创耀辉"]);
	CompareWithBSKDData(L"永创耀辉", m_mapAllSalesInfo[L"永创耀辉"]);
	CompareWithZTKYData(L"永创耀辉", m_mapAllSalesInfo[L"永创耀辉"]);
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
					wchar_t szWeight[10] ={0};
					_itow_s(nWeight, szWeight, 10);
					sheet->Cell(itB->nRow, eET_JiFeiZhongLiang)->SetWString(szWeight);
				}
				else
				{
					if(itB->strZhongLiang == L"0.00")
						nWeight = 0;
					else
						nWeight = _wtoi(itB->strZhongLiang.c_str());
					wchar_t szWeight[10] ={0};
					_itow_s(nWeight, szWeight, 10);
					sheet->Cell(itB->nRow, eET_JiFeiZhongLiang)->SetWString(szWeight);
				}
				double dZengZhi = 0;
				//计算物流费
				{
					if(itB->strWuLiuGongSi == L"顺丰热敏(线下)" || itB->strWuLiuGongSi == L"顺丰热敏(拼多多)")
					{
						double money = GetSFPrice(nWeight, itB->strSheng, g_yongChuangYaoHuiSFPrice);
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
							if(itSF->second.type != L"特惠专配")
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
					else if(itB->strWuLiuGongSi == L"百世快运")
						sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(L"2.5");
					else if(itB->strWuLiuGongSi == L"中通快运" || itB->strWuLiuGongSi == L"中通快运(菜鸟)")
					{
						double money = GetKYPrice(nWeight, itB->strSheng, itB->strShi, g_yongChuangYaoHuiZTKYPrice);
						sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1).c_str());

						std::map<std::wstring, sZTKYAuthData>::iterator itZTKY = m_mapZYKYAuthData.find(itB->strWuLiuDanHao);
						if(itZTKY != m_mapZYKYAuthData.end())
						{
							double chengbenMoney = GetKYPrice(nWeight, itB->strSheng, itB->strShi, g_chengBenZTKYPrice);
							if(chengbenMoney+DOUBLE_PRECISION < itZTKY->second.wuliuPay)
							{
								BasicExcelWorksheet* recordSheet = m_recordExcel.GetWorksheet(g_arrWorksheetName[5]);
								recordSheet->Cell(g_arrRecordRowIndex[5], 0)->SetWString(L"永创耀辉");
								recordSheet->Cell(g_arrRecordRowIndex[5], 1)->SetWString(itB->strWuLiuDanHao.c_str());
								recordSheet->Cell(g_arrRecordRowIndex[5], 2)->SetWString(CFuncCommon::Double2WString(itZTKY->second.wuliuPay + DOUBLE_PRECISION, 1).c_str());
								recordSheet->Cell(g_arrRecordRowIndex[5], 3)->SetWString(CFuncCommon::Double2WString(chengbenMoney + DOUBLE_PRECISION, 1).c_str());
								g_arrRecordRowIndex[5]++;
							}
							if(itZTKY->second.shanglowPay > DOUBLE_PRECISION)
							{
								dZengZhi += itZTKY->second.shanglowPay;
								if(strBeiZhu == L"")
									strBeiZhu = strBeiZhu + L"上楼";
								else
									strBeiZhu = strBeiZhu + L" | 上楼";
							}
						}
					}
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
					else if(itB->strWuLiuGongSi == L"中通快递" || itB->strWuLiuGongSi == L"百世快递(菜鸟)" || itB->strWuLiuGongSi == L"百世快递(拼多多)" )
					{
						double money = GetKDPrice(nWeight, itB->strSheng, g_yongChuangYaoHuiKDPrice, L"百世快递");
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
	if(!CreateExcel(excel, m_mapAllSalesInfo[L"弥雅食器"], m_mapInStorageInfo[L"弥雅食器"]))
		return false;
	wstring fileName = L"./Export_" + m_strYM + L"/" + L"弥雅食器_" + m_strYM + L"对账单.xls";
	string _file = CFuncCommon::WString2String(fileName.c_str());
	CompareWithSFData(L"弥雅食器", m_mapAllSalesInfo[L"弥雅食器"]);
	CompareWithBSKDData(L"弥雅食器", m_mapAllSalesInfo[L"弥雅食器"]);
	CompareWithZTKYData(L"弥雅食器", m_mapAllSalesInfo[L"弥雅食器"]);
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
					if(itB->strWuLiuGongSi == L"顺丰热敏(线下)" || itB->strWuLiuGongSi == L"顺丰热敏(拼多多)")
					{
						double money = GetSFPrice(nWeight, itB->strSheng, g_miYaSFPrice);
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
							if(itSF->second.type != L"特惠专配")
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
					else if(itB->strWuLiuGongSi == L"百世线下(分拨)" || itB->strWuLiuGongSi == L"百世快递(菜鸟)" || itB->strWuLiuGongSi == L"百世快递(拼多多)")
					{
						double money = 0;
						if(nWeight > 0)
						{
							double money = GetKDPrice(nWeight, itB->strSheng, g_miYaBSPrice, L"百世快递");
							sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1).c_str());
						}
					}
					else if(itB->strWuLiuGongSi == L"百世快运" || itB->strWuLiuGongSi == L"中通快运" || itB->strWuLiuGongSi == L"中通快运(菜鸟)")
					{
						double money = GetKYPrice(nWeight, itB->strSheng, itB->strShi, g_miYaZTKYPrice);
						sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1).c_str());
						if(itB->strWuLiuGongSi == L"中通快运" || itB->strWuLiuGongSi == L"中通快运(菜鸟)")
						{
							std::map<std::wstring, sZTKYAuthData>::iterator itZTKY = m_mapZYKYAuthData.find(itB->strWuLiuDanHao);
							if(itZTKY != m_mapZYKYAuthData.end())
							{
								if(itZTKY->second.shanglowPay > DOUBLE_PRECISION)
								{
									dZengZhi += itZTKY->second.shanglowPay;
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
	if(!m_bBSKD)
		return true;
	std::wstring strBSFileName = BSKD_FILE_PATH;
	std::string _strBSFileName = CFuncCommon::WString2String(strBSFileName.c_str());
	m_bskdExcel.Load(_strBSFileName.c_str());
	BasicExcelWorksheet* bsSheet = m_bskdExcel.GetWorksheet(L"账单明细");
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

bool CStorageBillDlg::LoadZTKYData()
{
	if(!m_bZYKY)
		return true;
	std::wstring strZTFileName = ZTKY_FILE_PATH;
	std::string _strZTFileName = CFuncCommon::WString2String(strZTFileName.c_str());
	m_ztkyExcel.Load(_strZTFileName.c_str());
	BasicExcelWorksheet* ztSheet = m_ztkyExcel.GetWorksheet(L"Sheet2");
	if(ztSheet)
	{
		size_t maxRows = ztSheet->GetTotalRows();
		size_t maxCols = ztSheet->GetTotalCols();
		m_ztkyHandleCol = maxCols;
		//load tile
		int colNumber = -1;
		int colWeight = -1;
		int wuliuPay = -1;
		int shanglouPay = -1;
		bool bFix = false;
		for(size_t c = 0; c < maxCols; ++c)
		{
			BasicExcelCell* cell = ztSheet->Cell(0, c);
			const wchar_t* _titile = cell->GetWString();
			if(_titile)
			{
				std::wstring strTitle = _titile;
				if(strTitle == L"物流单号")
					colNumber = c;
				else if(strTitle == L"计费重量")
					colWeight = c;
				else if(strTitle == L"物流费")
					wuliuPay = c;
				else if(strTitle == L"上楼费")
					shanglouPay = c;
				else if(strTitle == L"对账结果")
				{
					bFix = true;
					m_ztkyHandleCol = c;
				}
			}
			
		}
		if(colNumber == -1 || colWeight == -1 || wuliuPay == -1 || shanglouPay == 1)
		{
			wchar_t szBuffer[128] = { 0 };
			wsprintfW(szBuffer, L"中通快运账单有标题未找到");
			THROW_ERROR(szBuffer);
		}
		if(!bFix)
			ztSheet->Cell(0, maxCols)->SetWString(L"对账结果");
		for(size_t r = 1; r < maxRows; ++r)
		{
			sZTKYAuthData _data;
			const wchar_t* _pStr = NULL;
			SHEET_CELL_STRING(ztSheet, r, colNumber, _data.number);
			SHEET_CELL_DOUBLE(ztSheet, r, colWeight, _data.finalWeight);
			SHEET_CELL_DOUBLE(ztSheet, r, wuliuPay, _data.wuliuPay);
			SHEET_CELL_DOUBLE(ztSheet, r, shanglouPay, _data.shanglowPay);
			_data.row = r;
			m_mapZYKYAuthData[_data.number] = _data;
		}
		AddLog(L"读取中通快运账单成功");
	}
	else
	{
		THROW_ERROR(L"读取中通快运账单失败");
	}
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
			if(_data.vaServices == L"保价" || _data.vaServices == L"特安" || _data.vaServices == L"易碎保")
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
				sfSheet->Cell(r, m_sfHandleCol)->SetWString(L"1");
				continue;
			}
			else if(_data.vaServices == L"转寄退回" || _data.vaServices == L"异地退回")
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
				sfSheet->Cell(r, m_sfHandleCol)->SetWString(L"1");
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

bool CStorageBillDlg::CompareWithSFData(std::wstring strHuoZhu, std::list<sSalesInfo>& listInfo, bool bWait)
{
	if(!m_bSF)
		return true;
	BasicExcelWorksheet* recordSheet = m_recordExcel.GetWorksheet(g_arrWorksheetName[0]);
	if(recordSheet == NULL)
		return false;
	BasicExcelWorksheet* sfSheet = m_sfExcel.GetWorksheet(L"Sheet0");
	if(sfSheet == NULL)
	{
		THROW_ERROR(L"顺丰账单找不到 Sheet0 子表");
	}
	std::list<sSalesInfo>::iterator itYCBegin = listInfo.begin();
	std::list<sSalesInfo>::iterator itYCEnd = listInfo.end();
	while(itYCBegin != itYCEnd)
	{
		if(itYCBegin->strWuLiuGongSi != L"顺丰热敏(拼多多)" && itYCBegin->strWuLiuGongSi != L"顺丰热敏(线下)")
		{
			++itYCBegin;
			continue;
		}
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
					sfSheet->Cell(itSF->second.row, m_sfHandleCol)->SetWString(L"1");
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
	if(!bWait)
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

bool CStorageBillDlg::CompareWithBSKDData(std::wstring strHuoZhu, std::list<sSalesInfo>& listInfo)
{
	if(!m_bBSKD)
		return true;
	BasicExcelWorksheet* recordSheet = m_recordExcel.GetWorksheet(g_arrWorksheetName[3]);
	if(recordSheet == NULL)
		return false;
	BasicExcelWorksheet* bsSheet = m_bskdExcel.GetWorksheet(L"账单明细");
	if(bsSheet == NULL)
	{
		THROW_ERROR(L"百世快递账单找不到 账单明细 子表");
	}
	std::list<sSalesInfo>::iterator itYCBegin = listInfo.begin();
	std::list<sSalesInfo>::iterator itYCEnd = listInfo.end();
	while(itYCBegin != itYCEnd)
	{
		if(itYCBegin->strWuLiuGongSi != L"百世线下(分拨)" && itYCBegin->strWuLiuGongSi != L"百世快递(菜鸟)" && itYCBegin->strWuLiuGongSi != L"百世快递(拼多多)")
		{
			++itYCBegin;
			continue;
		}
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
				recordSheet->Cell(g_arrRecordRowIndex[3], 0)->SetWString(strHuoZhu.c_str());
				recordSheet->Cell(g_arrRecordRowIndex[3], 1)->SetWString(itBS->first.c_str());
				recordSheet->Cell(g_arrRecordRowIndex[3], 2)->SetDouble(dBSWeight);
				recordSheet->Cell(g_arrRecordRowIndex[3], 3)->SetWString(itYCBegin->strZhongLiang.c_str());
				g_arrRecordRowIndex[3]++;
				bsSheet->Cell(itBS->second.row, m_bskdHandleCol)->SetWString(L"1");
			}
			else
				bsSheet->Cell(itBS->second.row, m_bskdHandleCol)->SetWString(L"1");
		}
		++itYCBegin;
	}
	return true;
}

bool CStorageBillDlg::CompareWithZTKYData(std::wstring strHuoZhu, std::list<sSalesInfo>& listInfo)
{
	if(!m_bZYKY)
		return true;
	BasicExcelWorksheet* recordSheet = m_recordExcel.GetWorksheet(g_arrWorksheetName[4]);
	if(recordSheet == NULL)
		return false;
	BasicExcelWorksheet* ztSheet = m_ztkyExcel.GetWorksheet(L"Sheet2");
	if(ztSheet == NULL)
	{
		THROW_ERROR(L"中通快运账单找不到 账单明细 子表");
	}
	std::list<sSalesInfo>::iterator itYCBegin = listInfo.begin();
	std::list<sSalesInfo>::iterator itYCEnd = listInfo.end();
	while(itYCBegin != itYCEnd)
	{
		if(itYCBegin->strWuLiuGongSi != L"中通快运" && itYCBegin->strWuLiuGongSi != L"中通快运(菜鸟)")
		{
			++itYCBegin;
			continue;
		}
		std::map<std::wstring, sZTKYAuthData>::iterator itZT = m_mapZYKYAuthData.find(itYCBegin->strWuLiuDanHao);
		if(itZT != m_mapZYKYAuthData.end())
		{
			wistringstream iss(itYCBegin->strZhongLiang.c_str());
			double dZTWeight = itZT->second.finalWeight;
			double dYCWeight;
			iss >> dYCWeight;
			if(dZTWeight > dYCWeight+DOUBLE_PRECISION)
			{
				recordSheet->Cell(g_arrRecordRowIndex[4], 0)->SetWString(strHuoZhu.c_str());
				recordSheet->Cell(g_arrRecordRowIndex[4], 1)->SetWString(itZT->first.c_str());
				recordSheet->Cell(g_arrRecordRowIndex[4], 2)->SetDouble(dZTWeight);
				recordSheet->Cell(g_arrRecordRowIndex[4], 3)->SetWString(itYCBegin->strZhongLiang.c_str());
				g_arrRecordRowIndex[4]++;
				ztSheet->Cell(itZT->second.row, m_ztkyHandleCol)->SetWString(L"1");
			}
			else
				ztSheet->Cell(itZT->second.row, m_ztkyHandleCol)->SetWString(L"1");
		}
		++itYCBegin;
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


double CStorageBillDlg::GetSFPrice(int nWeight, wstring strSheng, std::vector< std::list<sExpressPriceInfo> >& vecPrice)
{
	int nIndex = -1;
	if(strSheng == L"四川省" || strSheng == L"重庆")
		nIndex = 0;
	else if(strSheng == L"北京" || strSheng == L"贵州省" || strSheng == L"河北省" || strSheng == L"湖北省" || strSheng == L"江苏省" || strSheng == L"陕西省" || strSheng == L"上海" || strSheng == L"天津" || strSheng == L"云南省" || strSheng == L"浙江省")
		nIndex = 1;
	else if(strSheng == L"安徽省" || strSheng == L"福建省" || strSheng == L"甘肃省" || strSheng == L"广东省" || strSheng == L"广西壮族自治区" || strSheng == L"海南省" || strSheng == L"河南省" || strSheng == L"湖南省" || strSheng == L"江西省" || strSheng == L"宁夏回族自治区" || strSheng == L"青海省" || strSheng == L"山东省" || strSheng == L"山西省")
		nIndex = 2;
	else if(strSheng == L"黑龙江省" || strSheng == L"吉林省" || strSheng == L"辽宁省" || strSheng == L"内蒙古自治区" || strSheng == L"新疆维吾尔自治区")
		nIndex = 3;
	else
	{
		wchar_t szBuffer[128] = { 0 };
		wsprintfW(szBuffer, L"顺丰 未知省份 %s", strSheng.c_str());
		THROW_ERROR(szBuffer);
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
	wsprintfW(szBuffer, L"顺丰快递 重量不含有对应价格区间 %s %d", strSheng.c_str(), nWeight);
	THROW_ERROR(szBuffer);
}

double CStorageBillDlg::GetKDPrice(int nWeight, wstring strSheng, std::map< std::wstring, std::list<sExpressPriceInfo> >& mapPrice, wstring strKuDiType)
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
					return itB->dFirstPrice + itB->dFirstCommission;
				else
					return itB->dFirstPrice + itB->dFirstCommission + (nWeight-itB->nFirstZL)*itB->dXZPrice + (nWeight-itB->nFirstZL)*itB->dXZCommission;
			}
			++itB;
		}
		wchar_t szBuffer[128] = { 0 };
		wsprintfW(szBuffer, L"%s 重量不含有对应价格区间 %s %d", strKuDiType.c_str(), strSheng.c_str(), nWeight);
		THROW_ERROR(szBuffer);
	}
	else
	{
		wchar_t szBuffer[128] = { 0 };
		wsprintfW(szBuffer, L"%s 未知省份 %s", strKuDiType.c_str(), strSheng.c_str());
		THROW_ERROR(szBuffer);
	}
	return 0.0;
}

double CStorageBillDlg::GetKYPrice(int nWeight, wstring strSheng, wstring strShi, std::map< std::wstring, sLargeExpressPriceInfo >& mapPrice)
{
	if(strShi != L"")
	{
		std::map< std::wstring, sLargeExpressPriceInfo >::iterator it = mapPrice.find(strShi);
		if(it != mapPrice.end())
		{
			double price = 0;
			price = nWeight * it->second.dXZPrice;
			if(price < it->second.minPrice)
				return it->second.minPrice;
			return price;
		}
	}
	std::map< std::wstring, sLargeExpressPriceInfo >::iterator it = mapPrice.find(strSheng);
	if(it != mapPrice.end())
	{
		double price = 0;
		price = nWeight * it->second.dXZPrice;
		if(price < it->second.minPrice)
			return it->second.minPrice;
		return price;
	}
	return 0.0;
}

bool CStorageBillDlg::Handle_YiMaiKeJi()
{
	BasicExcel excel;
	if(!CreateExcel(excel, m_mapAllSalesInfo[L"颐麦科技"], m_mapInStorageInfo[L"颐麦科技"]))
		return false;
	wstring fileName = L"./Export_" + m_strYM + L"/" + L"颐麦科技_" + m_strYM + L"对账单.xls";
	string _file = CFuncCommon::WString2String(fileName.c_str());
	CompareWithSFData(L"颐麦科技", m_mapAllSalesInfo[L"颐麦科技"]);
	CompareWithBSKDData(L"颐麦科技", m_mapAllSalesInfo[L"颐麦科技"]);
	CompareWithZTKYData(L"颐麦科技", m_mapAllSalesInfo[L"颐麦科技"]);
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
					if(itB->strWuLiuGongSi == L"百世线下(分拨)" || itB->strWuLiuGongSi == L"百世快递(菜鸟)" || itB->strWuLiuGongSi == L"百世快递(拼多多)" )
					{
						double money = 0;
						if(nWeight > 0)
						{
							double money = GetKDPrice(nWeight, itB->strSheng, g_yiMaiKeJiBSPrice, L"百世快递");
							sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1).c_str());
						}
					}
					else if(itB->strWuLiuGongSi == L"百世快运" || itB->strWuLiuGongSi == L"中通快运" || itB->strWuLiuGongSi == L"中通快运(菜鸟)")
					{
						double money = GetKYPrice(nWeight, itB->strSheng, itB->strShi, g_yiMaiKeJiZTKYPrice);
						sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1).c_str());
						if(itB->strWuLiuGongSi == L"中通快运" || itB->strWuLiuGongSi == L"中通快运(菜鸟)")
						{
							std::map<std::wstring, sZTKYAuthData>::iterator itZTKY = m_mapZYKYAuthData.find(itB->strWuLiuDanHao);
							if(itZTKY != m_mapZYKYAuthData.end())
							{
								if(itZTKY->second.shanglowPay > DOUBLE_PRECISION)
								{
									dZengZhi += itZTKY->second.shanglowPay;
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
	if(!CreateExcel(excel, m_mapAllSalesInfo[L"新马帮"], m_mapInStorageInfo[L"新马帮"]))
		return false;
	wstring fileName = L"./Export_" + m_strYM + L"/" + L"新马帮_" + m_strYM + L"对账单.xls";
	string _file = CFuncCommon::WString2String(fileName.c_str());
	CompareWithSFData(L"新马帮", m_mapAllSalesInfo[L"新马帮"]);
	CompareWithBSKDData(L"新马帮", m_mapAllSalesInfo[L"新马帮"]);
	CompareWithZTKYData(L"新马帮", m_mapAllSalesInfo[L"新马帮"]);
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
					if(itB->strWuLiuGongSi == L"百世线下(分拨)" || itB->strWuLiuGongSi == L"百世快递(菜鸟)" || itB->strWuLiuGongSi == L"百世快递(拼多多)" )
					{
						double money = 0;
						int nZSL = _wtoi(itB->strHuoPinZongShuLiang.c_str());
						if(nZSL != 1)
						{
							wchar_t szOut[120] = { 0 };
							_swprintf(szOut, L"[新马帮快递货品数量异常] 单号=%s", itB->strWuLiuDanHao.c_str());
							AddLog(szOut);
						}
						else
						{
							double money = GetKDPrice(5, itB->strSheng, g_xinMaBangBSPrice, L"百世快递");
							money += 0.4;
							sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1).c_str());
						}
					}
					else if(itB->strWuLiuGongSi == L"百世快运" || itB->strWuLiuGongSi == L"中通快运" || itB->strWuLiuGongSi == L"中通快运(菜鸟)")
					{
						double money = GetKYPrice(nWeight, itB->strSheng, itB->strShi, g_xinMaBangZTKYPrice);
						sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1).c_str());
						if(itB->strWuLiuGongSi == L"中通快运" || itB->strWuLiuGongSi == L"中通快运(菜鸟)")
						{
							std::map<std::wstring, sZTKYAuthData>::iterator itZTKY = m_mapZYKYAuthData.find(itB->strWuLiuDanHao);
							if(itZTKY != m_mapZYKYAuthData.end())
							{
								double chengbenMoney = GetKYPrice(nWeight, itB->strSheng, itB->strShi, g_chengBenZTKYPrice);
								if(chengbenMoney+DOUBLE_PRECISION < itZTKY->second.wuliuPay)
								{
									BasicExcelWorksheet* recordSheet = m_recordExcel.GetWorksheet(g_arrWorksheetName[5]);
									recordSheet->Cell(g_arrRecordRowIndex[5], 0)->SetWString(L"永创耀辉");
									recordSheet->Cell(g_arrRecordRowIndex[5], 1)->SetWString(itB->strWuLiuDanHao.c_str());
									recordSheet->Cell(g_arrRecordRowIndex[5], 2)->SetWString(CFuncCommon::Double2WString(itZTKY->second.wuliuPay + DOUBLE_PRECISION, 1).c_str());
									recordSheet->Cell(g_arrRecordRowIndex[5], 3)->SetWString(CFuncCommon::Double2WString(chengbenMoney + DOUBLE_PRECISION, 1).c_str());
									g_arrRecordRowIndex[5]++;
								}

								if(itZTKY->second.shanglowPay > DOUBLE_PRECISION)
								{
									dZengZhi += itZTKY->second.shanglowPay;
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

bool CStorageBillDlg::Handle_HanTaiLang()
{
	CompareWithSFData(L"韩太郎", m_mapAllSalesInfo[L"韩太郎"]);
	CompareWithBSKDData(L"韩太郎", m_mapAllSalesInfo[L"韩太郎"]);
	CompareWithZTKYData(L"韩太郎", m_mapAllSalesInfo[L"韩太郎"]);
	return true;
}

bool CStorageBillDlg::Handle_HaTeNengLiang()
{

	BasicExcel excel;
	if(!CreateExcel(excel, m_mapAllSalesInfo[L"哈特能量"], m_mapInStorageInfo[L"哈特能量"]))
		return false;
	wstring fileName = L"./Export_" + m_strYM + L"/" + L"哈特能量_" + m_strYM + L"对账单.xls";
	string _file = CFuncCommon::WString2String(fileName.c_str());
	CompareWithSFData(L"哈特能量", m_mapAllSalesInfo[L"哈特能量"]);
	CompareWithBSKDData(L"哈特能量", m_mapAllSalesInfo[L"哈特能量"]);
	CompareWithZTKYData(L"哈特能量", m_mapAllSalesInfo[L"哈特能量"]);
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
				wchar_t decimal1 = itB->strZhongLiang.at(itB->strZhongLiang.size() - 1);
				wchar_t decimal2 = itB->strZhongLiang.at(itB->strZhongLiang.size() - 2);
				if(decimal1 != L'0' || decimal2 != L'0')
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
					if(itB->strZhongLiang == L"0.00")
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
					if(itB->strWuLiuGongSi == L"顺丰热敏(线下)" || itB->strWuLiuGongSi == L"顺丰热敏(拼多多)")
					{
						double money = GetSFPrice(nWeight, itB->strSheng, g_yongChuangYaoHuiSFPrice);
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
							if(itSF->second.type != L"特惠专配")
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
					else if(itB->strWuLiuGongSi == L"百世快运")
						sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(L"2.5");
					else if(itB->strWuLiuGongSi == L"中通快运" || itB->strWuLiuGongSi == L"中通快运(菜鸟)")
					{
						double money = GetKYPrice(nWeight, itB->strSheng, itB->strShi, g_yongChuangYaoHuiZTKYPrice);
						sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1).c_str());

						std::map<std::wstring, sZTKYAuthData>::iterator itZTKY = m_mapZYKYAuthData.find(itB->strWuLiuDanHao);
						if(itZTKY != m_mapZYKYAuthData.end())
						{
							double chengbenMoney = GetKYPrice(nWeight, itB->strSheng, itB->strShi, g_chengBenZTKYPrice);
							if(chengbenMoney + DOUBLE_PRECISION < itZTKY->second.wuliuPay)
							{
								BasicExcelWorksheet* recordSheet = m_recordExcel.GetWorksheet(g_arrWorksheetName[5]);
								recordSheet->Cell(g_arrRecordRowIndex[5], 0)->SetWString(L"哈特能量");
								recordSheet->Cell(g_arrRecordRowIndex[5], 1)->SetWString(itB->strWuLiuDanHao.c_str());
								recordSheet->Cell(g_arrRecordRowIndex[5], 2)->SetWString(CFuncCommon::Double2WString(itZTKY->second.wuliuPay + DOUBLE_PRECISION, 1).c_str());
								recordSheet->Cell(g_arrRecordRowIndex[5], 3)->SetWString(CFuncCommon::Double2WString(chengbenMoney + DOUBLE_PRECISION, 1).c_str());
								g_arrRecordRowIndex[5]++;
							}
							if(itZTKY->second.shanglowPay > DOUBLE_PRECISION)
							{
								dZengZhi += itZTKY->second.shanglowPay;
								if(strBeiZhu == L"")
									strBeiZhu = strBeiZhu + L"上楼";
								else
									strBeiZhu = strBeiZhu + L" | 上楼";
							}
						}
					}
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
					else if(itB->strWuLiuGongSi == L"中通快递" || itB->strWuLiuGongSi == L"百世快递(菜鸟)" || itB->strWuLiuGongSi == L"百世快递(拼多多)")
					{
						double money = GetKDPrice(nWeight, itB->strSheng, g_yongChuangYaoHuiKDPrice, L"百世快递");
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
	if(!CreateExcel(excel, m_mapAllSalesInfo[L"七一酱园"], m_mapInStorageInfo[L"七一酱园"]))
		return false;
	wstring fileName = L"./Export_" + m_strYM + L"/" + L"七一酱园_" + m_strYM + L"对账单.xls";
	string _file = CFuncCommon::WString2String(fileName.c_str());
	CompareWithSFData(L"七一酱园", m_mapAllSalesInfo[L"七一酱园"]);
	CompareWithBSKDData(L"七一酱园", m_mapAllSalesInfo[L"七一酱园"]);
	CompareWithZTKYData(L"七一酱园", m_mapAllSalesInfo[L"七一酱园"]);
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
					if(itB->strWuLiuGongSi == L"百世线下(分拨)" || itB->strWuLiuGongSi == L"百世快递(菜鸟)" || itB->strWuLiuGongSi == L"百世快递(拼多多)")
					{
						double money = 0;
						if(nWeight > 0)
						{
							double money = GetKDPrice(nWeight, itB->strSheng, g_qiYiJiangYuanBSPrice, L"百世快递");
							sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1).c_str());
						}
					}
					else if(itB->strWuLiuGongSi == L"顺丰热敏(线下)" || itB->strWuLiuGongSi == L"顺丰热敏(拼多多)")
					{
						double money = GetSFPrice(nWeight, itB->strSheng, g_qiYiJiangYuanSFPrice);
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
							if(itSF->second.type != L"特惠专配")
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
					else if(itB->strWuLiuGongSi == L"百世快运" || itB->strWuLiuGongSi == L"中通快运" || itB->strWuLiuGongSi == L"中通快运(菜鸟)")
					{
						double money = GetKYPrice(nWeight, itB->strSheng, itB->strShi, g_qiYiJiangYuanZTKYPrice);
						sheet->Cell(itB->nRow, eET_WuLiuFei)->SetWString(CFuncCommon::Double2WString(money + DOUBLE_PRECISION, 1).c_str());
						if(itB->strWuLiuGongSi == L"中通快运" || itB->strWuLiuGongSi == L"中通快运(菜鸟)")
						{
							std::map<std::wstring, sZTKYAuthData>::iterator itZTKY = m_mapZYKYAuthData.find(itB->strWuLiuDanHao);
							if(itZTKY != m_mapZYKYAuthData.end())
							{
								double chengbenMoney = GetKYPrice(nWeight, itB->strSheng, itB->strShi, g_chengBenZTKYPrice);
								if(chengbenMoney + DOUBLE_PRECISION < itZTKY->second.wuliuPay)
								{
									BasicExcelWorksheet* recordSheet = m_recordExcel.GetWorksheet(g_arrWorksheetName[5]);
									recordSheet->Cell(g_arrRecordRowIndex[5], 0)->SetWString(L"永创耀辉");
									recordSheet->Cell(g_arrRecordRowIndex[5], 1)->SetWString(itB->strWuLiuDanHao.c_str());
									recordSheet->Cell(g_arrRecordRowIndex[5], 2)->SetWString(CFuncCommon::Double2WString(itZTKY->second.wuliuPay + DOUBLE_PRECISION, 1).c_str());
									recordSheet->Cell(g_arrRecordRowIndex[5], 3)->SetWString(CFuncCommon::Double2WString(chengbenMoney + DOUBLE_PRECISION, 1).c_str());
									g_arrRecordRowIndex[5]++;
								}

								if(itZTKY->second.shanglowPay > DOUBLE_PRECISION)
								{
									dZengZhi += itZTKY->second.shanglowPay;
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
						{
							wchar_t szOut[120] = { 0 };
							_swprintf(szOut, L"[未知包装物] 货主=%s 单号=%s 物流公司=%s", itB->strHuoZhu.c_str(), itB->strWuLiuDanHao.c_str(), itB->strWuLiuGongSi.c_str());
							AddLog(szOut);
						}
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