
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
#define THROW_ERROR(info) AddLog(info); return false;
#define SHEET_CELL(sheet, r, c, strOut) _pStr = sheet->Cell(r, c)->GetWString();\
if(_pStr)\
	strOut = _pStr;
#define TOTAL_FILE_PATH L"./测试数据/销售出库单" + m_strYM + L".xls"
#define DETAIL_FILE_PATH L"./测试数据/销售出库明细" + m_strYM + L".xls"
#define SF_FILE_PATH L"./测试数据/顺丰账单" + m_strYM + L".xls"
#define IN_STORAGE_PATH L"./测试数据/入库明细账" + m_strYM + L".xls"


const wchar_t* g_arrWorksheetName[] ={L"顺丰重量差异订单", L"顺丰云仓未处理单号"};
int g_arrRecordRowIndex[] ={0, 0};
const wchar_t* g_arrHuoZhuName[] ={L"魔合科技N", L"永创耀辉", L"弥雅食器"};


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
}

BEGIN_MESSAGE_MAP(CStorageBillDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CStorageBillDlg::OnBnClickedCreateBill)
	ON_WM_TIMER()
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
			if(!Handle_MoHeKeJi())
				goto __break_logic;
			if(!Handle_YongChuangYaoHui())
				goto __break_logic;
			if(!Handle_MiYaShiQi())
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
		}
		if(nHuoZhu == -1 || nShouJianRen == -1 || nWuLiuGongSi == -1 || nWuLiuDanHao == -1 || nShouJianRenDiZhi == -1 || nZhongLiang == -1 || nFaHuoShijian == -1)
		{
			THROW_ERROR(L"销售出库单 有标题未找到");
		}
		for(size_t r = 1; r < maxRows; ++r)
		{
			sSalesInfo _data;
			const wchar_t* _pStr = NULL;
			SHEET_CELL(totalSheet, r, nHuoZhu, _data.strHuoZhu);
			SHEET_CELL(totalSheet, r, nShouJianRen, _data.strShouJianRen);
			SHEET_CELL(totalSheet, r, nWuLiuGongSi, _data.strWuLiuGongSi);
			SHEET_CELL(totalSheet, r, nWuLiuDanHao, _data.strWuLiuDanHao);
			SHEET_CELL(totalSheet, r, nShouJianRenDiZhi, _data.strShouJianRenDiZhi);
			double dTemp = totalSheet->Cell(r, nZhongLiang)->GetDouble();
			dTemp += 0.05;
			if(_data.strWuLiuGongSi == L"顺丰热敏")
				m_mapYCNeedSFHandle[_data.strHuoZhu].insert(_data.strWuLiuDanHao);
			_data.strZhongLiang = CFuncCommon::Double2WString(dTemp+DOUBLE_PRECISION, 2);
			SHEET_CELL(totalSheet, r, nFaHuoShijian, _data.strFaHuoShijian);
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
		}
		if(nHuoPinMingCheng == -1 || nHuoPinZongShuLiang == -1 || nHuoPinShuLiang == -1 || nWuLiuDanHao == -1 || nSheng == -1)
		{
			THROW_ERROR(L"销售出库明细 有标题未找到");
		}
		for(size_t r = 1; r < maxRows; ++r)
		{
			std::wstring strWuLiuDanHao;
			const wchar_t* _pStr = NULL;
			SHEET_CELL(detailSheet, r, nWuLiuDanHao, strWuLiuDanHao);
			std::map< std::wstring, sSalesInfo* >::iterator it = m_mapTempSalesInfo.find(strWuLiuDanHao);
			if(it == m_mapTempSalesInfo.end())
			{
				wchar_t szBuffer[128] ={0};
				wsprintfW(szBuffer, L"销售出库明细 未找到单号%s", strWuLiuDanHao.c_str());
				THROW_ERROR(szBuffer);
			}
			double dZSL = detailSheet->Cell(r, nHuoPinZongShuLiang)->GetDouble();
			it->second->strHuoPinZongShuLiang = CFuncCommon::Double2WString(dZSL+DOUBLE_PRECISION, 0);
			SHEET_CELL(detailSheet, r, nSheng, it->second->strSheng);
			std::wstring strHuoPinMingCheng;
			SHEET_CELL(detailSheet, r, nHuoPinMingCheng, strHuoPinMingCheng);
			double dSL = detailSheet->Cell(r, nHuoPinShuLiang)->GetDouble();
			std::wstring strHuoPinShuLiang = CFuncCommon::Double2WString(dSL+DOUBLE_PRECISION, 0);
			if(it->second->strHuoPinMingXi == L"")
				it->second->strHuoPinMingXi = strHuoPinMingCheng + L"@" + strHuoPinShuLiang;
			else
				it->second->strHuoPinMingXi = it->second->strHuoPinMingXi + L";" + strHuoPinMingCheng + L"@" + strHuoPinShuLiang;
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
			SHEET_CELL(inStorageSheet, r, nHuoZhu, info.strHuoZhu);
			std::wstring strRuKuYuanYin;
			SHEET_CELL(inStorageSheet, r, nRuKuYuanYin, strRuKuYuanYin);
			if(strRuKuYuanYin != L"其它入库" && strRuKuYuanYin != L"采购入库")
				continue;
			SHEET_CELL(inStorageSheet, r, nShangJiaBianMa, info.strShangJiaBianMa);
			SHEET_CELL(inStorageSheet, r, nHuoPingBianMa, info.strHuoPinBianMa);
			SHEET_CELL(inStorageSheet, r, nHuoPinMingCheng, info.strHuoPinMingCheng);
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
		if(i == nHuoZhuCnt)// && itB->first != L"哈特能量")
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
	BasicExcelWorksheet* recordSheet = m_recordExcel.GetWorksheet(g_arrWorksheetName[0]);
	if(recordSheet)
	{
		recordSheet->Cell(g_arrRecordRowIndex[0], 0)->SetWString(L"单号");
		recordSheet->Cell(g_arrRecordRowIndex[0], 1)->SetWString(L"顺丰重量");
		recordSheet->Cell(g_arrRecordRowIndex[0], 2)->SetWString(L"云仓重量");
		g_arrRecordRowIndex[0]++;
	}
	return true;
}

bool CStorageBillDlg::CreateExcel(BasicExcel& excel, std::list<sSalesInfo>& listSalesInfo, std::map<std::wstring, sInStorageInfo>& mapInStorageInfo)
{
	if(listSalesInfo.size() == 0)
		return false;
	excel.New(2);
	int nRecordRowIndex = 1;
	BasicExcelWorksheet* sheet = excel.GetWorksheet("Sheet1");
	if(sheet)
	{
		sheet->Cell(0, 0)->SetWString(L"收件人");
		sheet->Cell(0, 1)->SetWString(L"收件人地址");
		sheet->Cell(0, 2)->SetWString(L"省");
		sheet->Cell(0, 3)->SetWString(L"物流公司");
		sheet->Cell(0, 4)->SetWString(L"物流单号");
		sheet->Cell(0, 5)->SetWString(L"重量");
		sheet->Cell(0, 6)->SetWString(L"发货时间");
		sheet->Cell(0, 7)->SetWString(L"货品总数量");
		sheet->Cell(0, 8)->SetWString(L"货品明细");
		sheet->Cell(0, 9)->SetWString(L"计费重量");
		sheet->Cell(0, 10)->SetWString(L"物流费");
		sheet->Cell(0, 11)->SetWString(L"耗材费");
		sheet->Cell(0, 12)->SetWString(L"操作费");
		sheet->Cell(0, 13)->SetWString(L"增值费用");

		std::list<sSalesInfo>::iterator itB = listSalesInfo.begin();
		std::list<sSalesInfo>::iterator itE = listSalesInfo.end();
		while(itB != itE)
		{
			itB->nRow = nRecordRowIndex;
			sheet->Cell(nRecordRowIndex, 0)->SetWString(itB->strShouJianRen.c_str());
			sheet->Cell(nRecordRowIndex, 1)->SetWString(itB->strShouJianRenDiZhi.c_str());
			sheet->Cell(nRecordRowIndex, 2)->SetWString(itB->strSheng.c_str());
			sheet->Cell(nRecordRowIndex, 3)->SetWString(itB->strWuLiuGongSi.c_str());
			sheet->Cell(nRecordRowIndex, 4)->SetWString(itB->strWuLiuDanHao.c_str());
			sheet->Cell(nRecordRowIndex, 5)->SetWString(itB->strZhongLiang.c_str());
			sheet->Cell(nRecordRowIndex, 6)->SetWString(itB->strFaHuoShijian.c_str());
			sheet->Cell(nRecordRowIndex, 7)->SetWString(itB->strHuoPinZongShuLiang.c_str());
			sheet->Cell(nRecordRowIndex, 8)->SetWString(itB->strHuoPinMingXi.c_str());
			//待计算
			sheet->Cell(nRecordRowIndex, 9)->SetWString(L"0");
			sheet->Cell(nRecordRowIndex, 10)->SetWString(L"0");
			sheet->Cell(nRecordRowIndex, 11)->SetWString(L"0");
			sheet->Cell(nRecordRowIndex, 12)->SetWString(L"0");
			sheet->Cell(nRecordRowIndex, 13)->SetWString(L"0");
			nRecordRowIndex++;
			itB++;
		}
	}
	nRecordRowIndex = 1;
	sheet = excel.GetWorksheet("Sheet2");
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
		BasicExcelWorksheet* sheet = excel.GetWorksheet("Sheet1");
		if(sheet)
		{
			std::list<sSalesInfo>& listSales = m_mapAllSalesInfo[L"魔合科技N"];
			std::list<sSalesInfo>::iterator itB = listSales.begin();
			std::list<sSalesInfo>::iterator itE = listSales.end();
			while(itB != itE)
			{
				//sheet->Cell(0, 9)->SetWString(L"计费重量");
				//sheet->Cell(0, 10)->SetWString(L"打包费");
				//sheet->Cell(0, 11)->SetWString(L"耗材费");
				//sheet->Cell(0, 12)->SetWString(L"操作费");
				//sheet->Cell(0, 13)->SetWString(L"增值费用");
				wchar_t decimal = itB->strZhongLiang.at(itB->strZhongLiang.size()-1);
				if(decimal != L'0')
				{

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
	if(!CreateExcel(excel, m_mapAllSalesInfo[L"永创耀辉"], m_mapInStorageInfo[L"永创耀辉N"]))
		return false;
	wstring fileName = L"./Export_" + m_strYM + L"/" + L"永创耀辉_" + m_strYM + L"对账单.xls";
	string _file = CFuncCommon::WString2String(fileName.c_str());
	CompareWithSFData(L"永创耀辉", m_mapAllSalesInfo[L"永创耀辉"]);

	//计算相关费用
	{
		BasicExcelWorksheet* sheet = excel.GetWorksheet("Sheet1");
		if(sheet)
		{
			std::list<sSalesInfo>& listSales = m_mapAllSalesInfo[L"永创耀辉"];
			std::list<sSalesInfo>::iterator itB = listSales.begin();
			std::list<sSalesInfo>::iterator itE = listSales.end();
			while(itB != itE)
			{
				//sheet->Cell(0, 10)->SetWString(L"物流费");
				//sheet->Cell(0, 11)->SetWString(L"耗材费");
				//sheet->Cell(0, 12)->SetWString(L"操作费");
				//sheet->Cell(0, 13)->SetWString(L"增值费用");
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
					sheet->Cell(itB->nRow, 9)->SetWString(szWeight);
				}
				else
				{
					nWeight = _wtoi(itB->strZhongLiang.c_str());
					if(nWeight < 3)
						nWeight = 3;
					wchar_t szWeight[10] ={0};
					_itow_s(nWeight, szWeight, 10);
					sheet->Cell(itB->nRow, 9)->SetWString(szWeight);
				}
				//计算物流费
				{
					if(itB->strWuLiuGongSi == L"顺丰热敏")
					{
					}
					else if(itB->strWuLiuGongSi == L"百世快运")
					{
					}
					else if(itB->strWuLiuGongSi == L"百世线下(分拨)")
					{
					}
					else
					{
						wchar_t szOut[120] ={0};
						_swprintf(szOut, L"[未知的物流方式] 货主=%s 单号=%s", itB->strHuoZhu.c_str(), itB->strWuLiuDanHao.c_str());
						AddLog(szOut);
					}
				}
				sheet->Cell(itB->nRow, 12)->SetWString(L"1.1");
				//计算保费
				{
					//sheet->Cell(itB->nRow, 13)->SetWString(L"1.1");
				}

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

bool CStorageBillDlg::LoadSFData()
{
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
			else if(strTitle == L"对账结果")
			{
				bFix = true;
				m_sfHandleCol = c;
			}
		}
		if(!bFix)
			sfSheet->Cell(0, maxCols)->SetWString(L"对账结果");
		for(size_t r = 1; r < maxRows; ++r)
		{
			sSFAuthData _data;
			const wchar_t* _pStr = NULL;
			SHEET_CELL(sfSheet, r, colNumber, _data.number);
			SHEET_CELL(sfSheet, r, colWeight, _data.weight);
			SHEET_CELL(sfSheet, r, colVAServices, _data.vaServices);
			_data.row = r;
			if(_data.vaServices == L"保价")
			{
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
			if(!itSF->second.bHandle)
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
				if(finalWeight < dSFWeight)
				{
					recordSheet->Cell(g_arrRecordRowIndex[0], 0)->SetWString(itSF->first.c_str());
					recordSheet->Cell(g_arrRecordRowIndex[0], 1)->SetDouble(dSFWeight);
					recordSheet->Cell(g_arrRecordRowIndex[0], 2)->SetDouble(finalWeight);
					g_arrRecordRowIndex[0]++;
					sfSheet->Cell(itSF->second.row, m_sfHandleCol)->SetWString(L"0");
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
			recordSheet->Cell(g_arrRecordRowIndex[1]++, 0)->SetWString(itB->c_str());
			++itB;
		}
	}

	return true;
}