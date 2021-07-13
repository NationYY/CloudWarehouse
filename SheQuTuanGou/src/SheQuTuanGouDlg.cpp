
// 社团团购账单工具Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "SheQuTuanGou.h"
#include "SheQuTuanGouDlg.h"
#include "afxdialogex.h"
#include "func_common.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#define DATA_PATH "./数据文件"
#define EXPORT_PATH L"./账单生成"
#define PRICE_FILE L"./price.ini"
#define ZUI_DI_TUI_HUO_FEI 10
#define THROW_ERROR(info) AddLog(info); return false;
#define SHEET_CELL_STRING(sheet, r, c, strOut) _pStr = sheet->Cell(r, c)->GetWString();\
if(_pStr)\
	strOut = _pStr;

#define SHEET_CELL_DOUBLE(sheet, r, c, dOut) dOut = sheet->Cell(r, c)->GetDouble();

#define SHEET_CELL_INT(sheet, r, c, nOut) nOut = sheet->Cell(r, c)->GetInteger();

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框


class CAboutDlg : public CDialogEx
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

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CSheQuTuanGouDlg 对话框



CSheQuTuanGouDlg::CSheQuTuanGouDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSheQuTuanGouDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSheQuTuanGouDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ctrlListLog);
	DDX_Control(pDX, IDC_LIST2, m_listCtrlAllKeHu);
	DDX_Control(pDX, IDC_EDIT1, m_editName);
	DDX_Control(pDX, IDC_COMBO1, m_combMonth);
}

BEGIN_MESSAGE_MAP(CSheQuTuanGouDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_LBN_DBLCLK(IDC_LIST2, &CSheQuTuanGouDlg::OnLbnDblclkListNames)
	ON_BN_CLICKED(IDC_BUTTON1, &CSheQuTuanGouDlg::OnBnClickedButtonMakeSelZD)
	ON_BN_CLICKED(IDC_BUTTON2, &CSheQuTuanGouDlg::OnBnClickedButtonMakeAllZD)
END_MESSAGE_MAP()


// CSheQuTuanGouDlg 消息处理程序

BOOL CSheQuTuanGouDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	//m_listCtrlAllKeHu.AddString(L"1");
	// TODO:  在此添加额外的初始化代码
	CFuncCommon::GetFiles(DATA_PATH, m_vecFiles);
	for(int i=0; i<(int)m_vecFiles.size(); ++i)
	{
		if(m_vecFiles[i].at(0) == 'G')
		{
			std::string temp1 = m_vecFiles[i].substr(0, m_vecFiles[i].size()-4);
			std::wstring temp2 = CFuncCommon::String2WString(temp1.c_str());
			m_listCtrlAllKeHu.AddString(temp2.c_str());
		}
	}
	for(int i=0; i<12; ++i)
	{
		wchar_t szMon[5] = {0};
		wsprintf(szMon, L"%d", i+1);
		m_combMonth.InsertString(i, szMon);
	}

	time_t tNow = time(NULL);
	tm* pTM = localtime(&tNow);
	int nM = 0;
	if(pTM->tm_mon + 1 == 1)
		nM = 11;
	else
		nM = pTM->tm_mon-1;
	m_combMonth.SetCurSel(nM);


	m_logicThread = boost::thread(boost::bind(&CSheQuTuanGouDlg::_LogicThread, this));
	SetTimer(0, 1, NULL);

	wstring folderPath = EXPORT_PATH;
	if(0 != _waccess(folderPath.c_str(), 0))
		_wmkdir(folderPath.c_str());
	m_logFile.close();
	wstring logPath = folderPath + L"./log.txt";
	m_logFile.open(logPath);
	m_logFile.imbue(std::locale("chs"));
	if(!m_logFile.is_open())
		MessageBox(L"创建日志文件失败!");
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CSheQuTuanGouDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
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

void CSheQuTuanGouDlg::OnPaint()
{
	if (IsIconic())
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
HCURSOR CSheQuTuanGouDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSheQuTuanGouDlg::OnTimer(UINT_PTR nIDEvent)
{
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


void CSheQuTuanGouDlg::SetHScroll()
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

		temp = (long)SendDlgItemMessage(IDC_LIST1, LB_GETHORIZONTALEXTENT, 0, 0);
		if(s.cx > temp)
			SendDlgItemMessage(IDC_LIST1, LB_SETHORIZONTALEXTENT, (WPARAM)s.cx, 0);
	}
	ReleaseDC(dc);
}

void CSheQuTuanGouDlg::AddLog(std::wstring strLog)
{
	m_queueLog.push(strLog);
}


void CSheQuTuanGouDlg::_LogicThread()
{
	while(!m_bExit)
	{
		if(m_bRun)
		{
			m_dZhuangXieFeiHeJi = 0;
			m_dSongHuoFeiHeJi = 0;
			m_dTuiHuoFeiHeJi = 0;
			m_dCangChuFeiHeJi = 0;
			m_dZengZhiFeiHeJi = 0;
			list<wstring>::iterator it = m_listMakeSJNames.begin();
			while(it != m_listMakeSJNames.end())
			{
				if(!MakeZD(*it))
					goto __break_logic;
				++it;
			}
			AddLog(L"账单全部生成完毕");
			char szBuffer[128] = { 0 };
			wstring _szInfo;
			sprintf(szBuffer, "装卸费合计 %.1f", m_dZhuangXieFeiHeJi);
			_szInfo = CFuncCommon::String2WString(szBuffer);
			AddLog(_szInfo);
			sprintf(szBuffer, "送货费合计 %.1f", m_dSongHuoFeiHeJi);
			_szInfo = CFuncCommon::String2WString(szBuffer);
			AddLog(_szInfo);
			sprintf(szBuffer, "退货费合计 %.1f", m_dTuiHuoFeiHeJi);
			_szInfo = CFuncCommon::String2WString(szBuffer);
			AddLog(_szInfo);
			sprintf(szBuffer, "仓储费合计 %.1f", m_dCangChuFeiHeJi);
			_szInfo = CFuncCommon::String2WString(szBuffer);
			AddLog(_szInfo);
			sprintf(szBuffer, "增值费合计 %.1f", m_dZengZhiFeiHeJi);
			_szInfo = CFuncCommon::String2WString(szBuffer);
			AddLog(_szInfo);
		}
	__break_logic:
		m_bRun = false;
		boost::this_thread::sleep(boost::posix_time::milliseconds(10));
	}
}

void CSheQuTuanGouDlg::OnLbnDblclkListNames()
{
	int nSel = m_listCtrlAllKeHu.GetCurSel();
	if(nSel != -1)
	{
		CString strTemp;
		m_listCtrlAllKeHu.GetText(nSel, strTemp);
		m_editName.SetWindowText(strTemp.GetBuffer());
	}
	// TODO:  在此添加控件通知处理程序代码
}


void CSheQuTuanGouDlg::OnBnClickedButtonMakeSelZD()
{
	if(m_bRun)
	{
		MessageBox(L"正在生成账单,不要重复点击");
		return;
	}
	m_listMakeSJNames.clear();
	CString szName;
	m_editName.GetWindowText(szName);
	if(szName == "")
	{
		MessageBox(L"未选择商家");
		return;
	}
	CString szMonth;
	m_combMonth.GetWindowText(szMonth);
	m_nMonth = _wtoi(szMonth.GetBuffer());
	m_listMakeSJNames.push_back(szName.GetBuffer());
	m_bRun = true;
}

bool CSheQuTuanGouDlg::MakeZD(std::wstring strKeHuName)
{
	wstring info = L"读取" + strKeHuName;
	AddLog(info);
	boost::this_thread::sleep(boost::posix_time::millisec(200));
	std::string fileName1 = DATA_PATH;
	std::string fileName2 =	CFuncCommon::WString2String((L"/" + strKeHuName + L".xls").c_str());
	std::string fileName = fileName1 + fileName2;
	BasicExcel dataExcel;
	if(!dataExcel.Load(fileName.c_str()))
	{
		wchar_t szBuffer[128] = { 0 };
		wsprintfW(szBuffer, L"------------------%s 加载失败", strKeHuName.c_str());
		THROW_ERROR(szBuffer);
		return false;
	}
	m_nRuKuDataCnt = 0;
	m_nChuKuDataCnt = 0;
	m_nKunCunCnt = 0;
	m_mapGoodsBaseInfo.clear();
	m_vecRuKuInfo.clear();
	m_vecRuKuInfo.resize(31);
	m_vecChuKuInfo.clear();
	m_vecChuKuInfo.resize(31);
	m_listZengZhi.clear();
	//先读取基本信息
	LoadKuCun(dataExcel);
	//读取入库信息
	LoadRuKu(dataExcel);
	//读取出库信息
	LoadChuKu(dataExcel);
	//读取增值服务信息
	LoadZengZhi(dataExcel);
	if(m_nRuKuDataCnt == 0 && m_nChuKuDataCnt == 0 && m_nKunCunCnt == 0 && m_listZengZhi.size() == 0)
	{
		info = strKeHuName + L"------------------当月没有数据";
		AddLog(info);
		return true;
	}
	MakeData(strKeHuName);
	info = strKeHuName + L"账单生成完成";
	AddLog(info);
	return true;
}
int shou_fei_mo_shi = 0;		//收费模式
int cang_chu_fei = 0;			//仓储费
int song_huo_fei_yi_tuo = 0;	//送货费一板
int song_huo_fei_ban_tuo = 0;	//送货费半板
int tui_huo_fei_yi_tuo = 0;		//退货费一板
int tui_huo_fei_ban_tuo = 0;	//退货费半板
double tie_biao_fei = 0;		//贴标费
int mei_tuan_jia_shou = 0;		//美团加收
int zhuang_xie_zhong_huo = 0;	//装卸重货
int zhuang_xie_pao_huo = 0;		//装卸泡货
int xie_song_tui_bao_gan = 0;	//卸送退包干
int song_tui_tie_bao_gan_yi_dun = 0;	//送退贴包干吨
int song_huo_fei_yi_dun = 0;	//送货费一吨
int song_huo_fei_yi_fang = 0;	//送货费一方
int song_huo_fei_bao_di	= 0;	//送货费保底
int tui_huo_fei_yi_dun = 0;		//退货费一吨
int tui_huo_fei_yi_fang = 0;	//退货费一方
int tui_huo_fei_bao_yue = 0;	//退货费包月
double song_tui_tie_yi_jian = 0;	//送退贴一件
void ClearPrice()
{
	shou_fei_mo_shi = 0;		//收费模式
	cang_chu_fei = 0;			//仓储费
	song_huo_fei_yi_tuo = 0;	//送货费一板
	song_huo_fei_ban_tuo = 0;	//送货费半板
	tui_huo_fei_yi_tuo = 0;		//退货费一板
	tui_huo_fei_ban_tuo = 0;	//退货费半板
	tie_biao_fei = 0;			//贴标费
	mei_tuan_jia_shou = 0;		//美团加收
	zhuang_xie_zhong_huo = 0;	//装卸重货
	zhuang_xie_pao_huo = 0;		//装卸泡货
	xie_song_tui_bao_gan = 0;	//卸送退包干
	song_tui_tie_bao_gan_yi_dun = 0;	//送退贴包干
	song_huo_fei_yi_dun = 0;	//送货费一吨
	song_huo_fei_yi_fang = 0;	//送货费一方
	song_huo_fei_bao_di = 0;	//送货费保底
	tui_huo_fei_yi_dun = 0;		//退货费一吨
	tui_huo_fei_yi_fang = 0;	//退货费一方
	tui_huo_fei_bao_yue = 0;	//退货费包月
	song_tui_tie_yi_jian = 0;	//送退贴一件
}
bool CSheQuTuanGouDlg::LoadPrice(std::wstring strKeHuName)
{
	wchar_t szBuffer[128] = { 0 };
	wchar_t szResult[128] = { 0 };
	wsprintfW(szBuffer, L"%s_收费模式", strKeHuName.c_str());
	shou_fei_mo_shi = GetPrivateProfileInt(L"Price", szBuffer, -1, PRICE_FILE);
	if(shou_fei_mo_shi == -1)
	{
		wchar_t _szBuffer[128] = { 0 };
		wsprintfW(_szBuffer, L"------------------%s 未配置价格", strKeHuName.c_str());
		THROW_ERROR(_szBuffer);
	}
	switch(shou_fei_mo_shi)
	{
	case 0:
		{
			  wsprintfW(szBuffer, L"%s_仓储费", strKeHuName.c_str());
			  cang_chu_fei = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_送货费一板", strKeHuName.c_str());
			  song_huo_fei_yi_tuo = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_送货费半板", strKeHuName.c_str());
			  song_huo_fei_ban_tuo = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_退货费一板", strKeHuName.c_str());
			  tui_huo_fei_yi_tuo = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);;
			  wsprintfW(szBuffer, L"%s_退货费半板", strKeHuName.c_str());
			  tui_huo_fei_ban_tuo = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_贴标费", strKeHuName.c_str());
			  GetPrivateProfileString(L"Price", szBuffer, L"", szResult, 128, PRICE_FILE);
			  if(StrCmpW(szResult, L"") == 0)
			  {
				  wchar_t _szBuffer[128] = { 0 };
				  wsprintfW(_szBuffer, L"------------------%s 贴标费 未配置", strKeHuName.c_str());
				  THROW_ERROR(_szBuffer);
			  }
			  tie_biao_fei = _wtof(szResult);
			  wsprintfW(szBuffer, L"%s_美团加收", strKeHuName.c_str());
			  mei_tuan_jia_shou = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_装卸重货", strKeHuName.c_str());
			  zhuang_xie_zhong_huo = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_装卸泡货", strKeHuName.c_str());
			  zhuang_xie_pao_huo = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
		}
		break;
	case 1:
		{
			  wsprintfW(szBuffer, L"%s_仓储费", strKeHuName.c_str());
			  cang_chu_fei = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_美团加收", strKeHuName.c_str());
			  mei_tuan_jia_shou = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_贴标费", strKeHuName.c_str());
			  GetPrivateProfileString(L"Price", szBuffer, L"", szResult, 128, PRICE_FILE);
			  if(StrCmpW(szResult, L"") == 0)
			  {
				  wchar_t _szBuffer[128] = { 0 };
				  wsprintfW(_szBuffer, L"------------------%s 贴标费 未配置", strKeHuName.c_str());
				  THROW_ERROR(_szBuffer);
			  }
			  tie_biao_fei = _wtof(szResult);
			  wsprintfW(szBuffer, L"%s_卸送退包干", strKeHuName.c_str());
			  xie_song_tui_bao_gan = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_装卸重货", strKeHuName.c_str());
			  zhuang_xie_zhong_huo = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_装卸泡货", strKeHuName.c_str());
			  zhuang_xie_pao_huo = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
		}
		break;
	case 2:
		{
			  wsprintfW(szBuffer, L"%s_仓储费", strKeHuName.c_str());
			  cang_chu_fei = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_送退贴包干吨", strKeHuName.c_str());
			  song_tui_tie_bao_gan_yi_dun = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_美团加收", strKeHuName.c_str());
			  mei_tuan_jia_shou = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_装卸重货", strKeHuName.c_str());
			  zhuang_xie_zhong_huo = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_装卸泡货", strKeHuName.c_str());
			  zhuang_xie_pao_huo = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
		}
		break;
	case 3:
		{
			  wsprintfW(szBuffer, L"%s_仓储费", strKeHuName.c_str());
			  cang_chu_fei = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_送货费一吨", strKeHuName.c_str());
			  song_huo_fei_yi_dun = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_送货费一方", strKeHuName.c_str());
			  song_huo_fei_yi_fang = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_送货费保底", strKeHuName.c_str());
			  song_huo_fei_bao_di = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_退货费一吨", strKeHuName.c_str());
			  tui_huo_fei_yi_dun = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_退货费一方", strKeHuName.c_str());
			  tui_huo_fei_yi_fang = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_贴标费", strKeHuName.c_str());
			  GetPrivateProfileString(L"Price", szBuffer, L"", szResult, 128, PRICE_FILE);
			  if(StrCmpW(szResult, L"") == 0)
			  {
				  wchar_t _szBuffer[128] = { 0 };
				  wsprintfW(_szBuffer, L"------------------%s 贴标费 未配置", strKeHuName.c_str());
				  THROW_ERROR(_szBuffer);
			  }
			  tie_biao_fei = _wtof(szResult);
			  wsprintfW(szBuffer, L"%s_美团加收", strKeHuName.c_str());
			  mei_tuan_jia_shou = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_装卸重货", strKeHuName.c_str());
			  zhuang_xie_zhong_huo = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_装卸泡货", strKeHuName.c_str());
			  zhuang_xie_pao_huo = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
		}
		break;
	case 4:
		{
			wsprintfW(szBuffer, L"%s_仓储费", strKeHuName.c_str());
			cang_chu_fei = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			wsprintfW(szBuffer, L"%s_送货费一吨", strKeHuName.c_str());
			song_huo_fei_yi_dun = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			wsprintfW(szBuffer, L"%s_送货费一方", strKeHuName.c_str());
			song_huo_fei_yi_fang = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			wsprintfW(szBuffer, L"%s_送货费保底", strKeHuName.c_str());
			song_huo_fei_bao_di = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			wsprintfW(szBuffer, L"%s_退货费包月", strKeHuName.c_str());
			tui_huo_fei_bao_yue = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			wsprintfW(szBuffer, L"%s_贴标费", strKeHuName.c_str());
			GetPrivateProfileString(L"Price", szBuffer, L"", szResult, 128, PRICE_FILE);
			if(StrCmpW(szResult, L"") == 0)
			{
				wchar_t _szBuffer[128] = { 0 };
				wsprintfW(_szBuffer, L"------------------%s 贴标费 未配置", strKeHuName.c_str());
				THROW_ERROR(_szBuffer);
			}
			tie_biao_fei = _wtof(szResult);
			wsprintfW(szBuffer, L"%s_美团加收", strKeHuName.c_str());
			mei_tuan_jia_shou = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			wsprintfW(szBuffer, L"%s_装卸重货", strKeHuName.c_str());
			zhuang_xie_zhong_huo = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			wsprintfW(szBuffer, L"%s_装卸泡货", strKeHuName.c_str());
			zhuang_xie_pao_huo = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
		}
		break;
	case 5:
		{
			  wsprintfW(szBuffer, L"%s_仓储费", strKeHuName.c_str());
			  cang_chu_fei = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_送退贴一件", strKeHuName.c_str());
			  song_tui_tie_yi_jian =  GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_送货费保底", strKeHuName.c_str());
			  song_huo_fei_bao_di = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_贴标费", strKeHuName.c_str());
			  GetPrivateProfileString(L"Price", szBuffer, L"", szResult, 128, PRICE_FILE);
			  if(StrCmpW(szResult, L"") == 0)
			  {
				  wchar_t _szBuffer[128] = { 0 };
				  wsprintfW(_szBuffer, L"------------------%s 贴标费 未配置", strKeHuName.c_str());
				  THROW_ERROR(_szBuffer);
			  }
			  tie_biao_fei = _wtof(szResult);
			 
			  wsprintfW(szBuffer, L"%s_美团加收", strKeHuName.c_str());
			  mei_tuan_jia_shou = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_装卸重货", strKeHuName.c_str());
			  zhuang_xie_zhong_huo = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_装卸泡货", strKeHuName.c_str());
			  zhuang_xie_pao_huo = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
		}
		break;
	case 6:
		{
			  wsprintfW(szBuffer, L"%s_仓储费", strKeHuName.c_str());
			  cang_chu_fei = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_送货费一吨", strKeHuName.c_str());
			  song_huo_fei_yi_dun = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_送货费一方", strKeHuName.c_str());
			  song_huo_fei_yi_fang = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_送货费保底", strKeHuName.c_str());
			  song_huo_fei_bao_di = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_退货费一吨", strKeHuName.c_str());
			  tui_huo_fei_yi_dun = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_退货费一板", strKeHuName.c_str());
			  tui_huo_fei_yi_tuo = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);;
			  wsprintfW(szBuffer, L"%s_退货费半板", strKeHuName.c_str());
			  tui_huo_fei_ban_tuo = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_贴标费", strKeHuName.c_str());
			  GetPrivateProfileString(L"Price", szBuffer, L"", szResult, 128, PRICE_FILE);
			  if(StrCmpW(szResult, L"") == 0)
			  {
				  wchar_t _szBuffer[128] = { 0 };
				  wsprintfW(_szBuffer, L"------------------%s 贴标费 未配置", strKeHuName.c_str());
				  THROW_ERROR(_szBuffer);
			  }
			  tie_biao_fei = _wtof(szResult);
			  wsprintfW(szBuffer, L"%s_美团加收", strKeHuName.c_str());
			  mei_tuan_jia_shou = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_装卸重货", strKeHuName.c_str());
			  zhuang_xie_zhong_huo = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_装卸泡货", strKeHuName.c_str());
			  zhuang_xie_pao_huo = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
		}
		break;
	default:
		{
			wchar_t _szBuffer[128] = { 0 };
			wsprintfW(_szBuffer, L"------------------%s 未知收费模式=%d", strKeHuName.c_str(), shou_fei_mo_shi);
			THROW_ERROR(_szBuffer);
		}
		break;
	}
	return true;
}

bool CSheQuTuanGouDlg::_____MakeZhuangXieFei(BasicExcel& excel)
{
	int nRecordRowIndex = 0;
	BasicExcelWorksheet* _sheet = excel.GetWorksheet(L"装卸费用");
	_sheet->Cell(nRecordRowIndex, 0)->SetWString(L"时间");
	_sheet->Cell(nRecordRowIndex, 1)->SetWString(L"类型");
	_sheet->Cell(nRecordRowIndex, 2)->SetWString(L"货品明细");
	_sheet->Cell(nRecordRowIndex, 3)->SetWString(L"重量(kg)");
	_sheet->Cell(nRecordRowIndex, 4)->SetWString(L"体积(m3)");
	_sheet->Cell(nRecordRowIndex, 5)->SetWString(L"装卸费");
	nRecordRowIndex++;
	for(int i = 0; i<(int)m_vecRuKuInfo.size(); ++i)
	{
		if(m_vecRuKuInfo[i].size() > 0)
		{
			list<sRuKuBaseInfo>::iterator itB = m_vecRuKuInfo[i].begin();
			list<sRuKuBaseInfo>::iterator itE = m_vecRuKuInfo[i].end();
			while(itB != itE)
			{
				if(itB->lei_xing == L"客户来货")
				{
					wchar_t _szBuffer[128] = { 0 };
					wsprintfW(_szBuffer, L"%d月%d日", m_nMonth, itB->day);
					_sheet->Cell(nRecordRowIndex, 0)->SetWString(_szBuffer);
					list<sRuKuDetailInfo>::iterator _itB = itB->detail_info.begin();
					list<sRuKuDetailInfo>::iterator _itE = itB->detail_info.end();
					wchar_t _szGoodsInfo[512] = {0};
					double zl = 0;
					double tj = 0;
					double zhuang_xie_fei = 0;
					while(_itB != _itE)
					{
						if(wcslen(_szGoodsInfo) > 0)
							StrCatW(_szGoodsInfo, L"\t\n");
						StrCatW(_szGoodsInfo, _itB->chan_pin_ming.c_str());
						StrCatW(_szGoodsInfo, L" @ ");
						wsprintfW(_szGoodsInfo, L"%s%d%s", _szGoodsInfo, _itB->ru_ku_shu_liang, _itB->dan_wei.c_str());
						zl += _itB->zhong_liang;
						tj += _itB->ti_ji;
						++_itB;
					}
					_sheet->Cell(nRecordRowIndex, 1)->SetWString(L"云仓到货");
					_sheet->Cell(nRecordRowIndex, 2)->SetWString(_szGoodsInfo);
					_sheet->Cell(nRecordRowIndex, 3)->SetDouble(zl);
					_sheet->Cell(nRecordRowIndex, 4)->SetDouble(tj);
					switch(shou_fei_mo_shi)
					{
					case 0:
					case 3:
					case 4:
					case 6:
						{
							  zhuang_xie_fei = max(zl/1000.0*zhuang_xie_zhong_huo, tj*zhuang_xie_pao_huo);
							  m_dZhuangXieFeiHeJi += zhuang_xie_fei;
							  _sheet->Cell(nRecordRowIndex, 5)->SetDouble(zhuang_xie_fei);
						}
						break;
					case 1:
					case 2:
					case 5:
						_sheet->Cell(nRecordRowIndex, 5)->SetDouble(0);
						break;
					default:
						{
							wchar_t _szBuffer[128] = { 0 };
							wsprintfW(_szBuffer, L"------------------未处理的收费方式-装卸 类型=%d", shou_fei_mo_shi);
							THROW_ERROR(_szBuffer);
						}
						break;
					}
					nRecordRowIndex++;
				}
				++itB;
			}
		}
		if(m_vecChuKuInfo[i].size() > 0)
		{
			list<sChuKuBaseInfo>::iterator itB = m_vecChuKuInfo[i].begin();
			list<sChuKuBaseInfo>::iterator itE = m_vecChuKuInfo[i].end();
			while(itB != itE)
			{
				if(itB->lei_xing == L"客户自提")
				{
					wchar_t _szBuffer[128] = { 0 };
					wsprintfW(_szBuffer, L"%d月%d日", m_nMonth, itB->day);
					_sheet->Cell(nRecordRowIndex, 0)->SetWString(_szBuffer);
					list<sChuKuDetailInfo>::iterator _itB = itB->detail_info.begin();
					list<sChuKuDetailInfo>::iterator _itE = itB->detail_info.end();
					wchar_t _szGoodsInfo[512] = { 0 };
					double zl = 0;
					double tj = 0;
					while(_itB != _itE)
					{
						if(wcslen(_szGoodsInfo) > 0)
							StrCatW(_szGoodsInfo, L"\t\n");
						StrCatW(_szGoodsInfo, _itB->chan_pin_ming.c_str());
						StrCatW(_szGoodsInfo, L" @ ");
						wsprintfW(_szGoodsInfo, L"%s%d%s", _szGoodsInfo, _itB->chu_ku_shu_liang, _itB->dan_wei.c_str());
						zl += _itB->zhong_liang;
						tj += _itB->ti_ji;
						++_itB;
					}
					_sheet->Cell(nRecordRowIndex, 1)->SetWString(L"云仓调出");
					_sheet->Cell(nRecordRowIndex, 2)->SetWString(_szGoodsInfo);
					_sheet->Cell(nRecordRowIndex, 3)->SetDouble(zl);
					_sheet->Cell(nRecordRowIndex, 4)->SetDouble(tj);
					switch(shou_fei_mo_shi)
					{
					case 0:
					case 1:
					case 2:
					case 3:
					case 4:
					case 5:
					case 6:
						{
							 double zhuang_xie_fei = max(zl / 1000.0*zhuang_xie_zhong_huo, tj*zhuang_xie_pao_huo);
							 m_dZhuangXieFeiHeJi += zhuang_xie_fei;
							 _sheet->Cell(nRecordRowIndex, 5)->SetDouble(zhuang_xie_fei);
						}
						break;
					default:
						{
							 wchar_t _szBuffer[128] = { 0 };
							 wsprintfW(_szBuffer, L"------------------未处理的收费方式-装卸 类型=%d", shou_fei_mo_shi);
							 THROW_ERROR(_szBuffer);
						}
						break;
					}
					nRecordRowIndex++;
				}
				++itB;
			}
		}
	}
	return true;
}
std::wstring he_ji;
bool CSheQuTuanGouDlg::MakeData(std::wstring strKeHuName)
{
	std::wstring _strKeHuName = strKeHuName.substr(4);
	ClearPrice();                                              
	if(!LoadPrice(_strKeHuName))
		return false;
	he_ji = L"=SUM(装卸费用!F:F)+SUM(送货费用!I:I)+SUM(退货费用!G:G)+SUM(仓储费用!C:C)+SUM(增值费用!C:C)";
	BasicExcel excel;
	excel.AddWorksheet(L"装卸费用");
	excel.AddWorksheet(L"送货费用");
	excel.AddWorksheet(L"退货费用");
	excel.AddWorksheet(L"增值费用");
	excel.AddWorksheet(L"仓储费用");
	excel.AddWorksheet(L"合计");

	wchar_t _szBuffer[512] = { 0 };
	wsprintfW(_szBuffer, L"%s/%s_%d月账单.xls", EXPORT_PATH, strKeHuName.c_str(), m_nMonth);
	::DeleteFileW(_szBuffer);
	_____MakeZhuangXieFei(excel);
	_____MakeSongHuoFei(excel);
	_____MakeTuiHuoFei(excel);
	_____MakeCangChuFei(excel);
	_____MakeZengZhiFei(excel);
	
	BasicExcelWorksheet* _sheet = excel.GetWorksheet(L"合计");
	_sheet->Cell(0,0)->SetWString(he_ji.c_str());
	string _file = CFuncCommon::WString2String(_szBuffer);
	excel.SaveAs(_file.c_str());

	return true;
}

bool CSheQuTuanGouDlg::_____MakeZengZhiFei(BasicExcel& excel)
{
	int nRecordRowIndex = 0;
	BasicExcelWorksheet* _sheet = excel.GetWorksheet(L"增值费用");
	_sheet->Cell(nRecordRowIndex, 0)->SetWString(L"日期");
	_sheet->Cell(nRecordRowIndex, 1)->SetWString(L"内容");
	_sheet->Cell(nRecordRowIndex, 2)->SetWString(L"费用");
	nRecordRowIndex++;
	list<sZengZhiInfo>::iterator itB = m_listZengZhi.begin();
	list<sZengZhiInfo>::iterator itE = m_listZengZhi.end();
	while(itB != itE)
	{
		wchar_t _szBuffer[512] = { 0 };
		wsprintfW(_szBuffer, L"%d月%d日", m_nMonth, itB->day);
		_sheet->Cell(nRecordRowIndex, 0)->SetWString(_szBuffer);
		memset(_szBuffer, 0, sizeof(_szBuffer));
		bool first = true;
		double fy = 0;
		if(itB->da_ka_ci_shu > 0)
		{
			if(!first)
				StrCatW(_szBuffer, L"\t\n");
			wsprintfW(_szBuffer, L"%s代打卡%d次", _szBuffer, itB->da_ka_ci_shu);
			first = false;
			fy += 20;

		}
		if(itB->dai_ru_ku_ci_shu > 0)
		{
			if(!first)
				StrCatW(_szBuffer, L"\t\n");
			wsprintfW(_szBuffer, L"%s代入库%d个sku", _szBuffer, itB->dai_ru_ku_ci_shu);
			first = false;
			if(itB->dai_ru_ku_ci_shu > 1)
			{
				fy += 30;
				fy += (itB->dai_ru_ku_ci_shu - 1)*10;
			}
			else
				fy += 30;

		}
		if(itB->tie_biao_shu > 0)
		{
			if(!first)
				StrCatW(_szBuffer, L"\t\n");
			wsprintfW(_szBuffer, L"%s贴标%d个", _szBuffer, itB->tie_biao_shu);
			fy += (0.2*itB->tie_biao_shu);
			first = false;
		}
		_sheet->Cell(nRecordRowIndex, 1)->SetWString(_szBuffer);
		_sheet->Cell(nRecordRowIndex, 2)->SetDouble(fy);
		nRecordRowIndex++;
		m_dZengZhiFeiHeJi += fy;
		++itB;
	}
	return true;
}


bool CSheQuTuanGouDlg::_____MakeCangChuFei(BasicExcel& excel)
{
	int nRecordRowIndex = 0;
	BasicExcelWorksheet* _sheet = excel.GetWorksheet(L"仓储费用");
	_sheet->Cell(nRecordRowIndex, 0)->SetWString(L"日期");
	_sheet->Cell(nRecordRowIndex, 1)->SetWString(L"板数");
	_sheet->Cell(nRecordRowIndex, 2)->SetWString(L"费用");
	nRecordRowIndex++;
	//先把超过账期月的数据回溯
	map<wstring, sGoodsCangChuInfo> mapKuCunInfo;
	map<wstring, sGoodsBaseInfo>::iterator itB = m_mapGoodsBaseInfo.begin();
	map<wstring, sGoodsBaseInfo>::iterator itE = m_mapGoodsBaseInfo.end();
	while(itB != itE)
	{
		sGoodsCangChuInfo info;
		info.ban_shu_biao_zhun = itB->second.ban_shu_biao_zhun;
		info.chan_pin_ming = itB->first;
		info.ku_cun = itB->second.ku_cun;
		mapKuCunInfo[itB->first] = info;
		++itB;
	}
	map<wstring, sGoodsCangChuInfo>::iterator _itB = mapKuCunInfo.begin();
	map<wstring, sGoodsCangChuInfo>::iterator _itE = mapKuCunInfo.end();
	while(_itB != _itE)
	{
		map<wstring, int>::iterator it = m_mapAfterRuKu.find(_itB->first);
		if(it != m_mapAfterRuKu.end())
		{
			_itB->second.ku_cun -= it->second;
		}
		it = m_mapAfterChuKu.find(_itB->first);
		if(it != m_mapAfterChuKu.end())
		{
			_itB->second.ku_cun += it->second;
		}
		if(_itB->second.ku_cun < 0)
			_itB->second.ku_cun = 0;
		++_itB;
	}
	time_t tNow = time(NULL);
	tm* pTM = localtime(&tNow);
	int nYear = pTM->tm_year + 1900;
	int nLastDay = 0;
	switch(m_nMonth)
	{
	case 1:
		nLastDay = 31;
		break;
	case 2:
		{
			if((nYear%100!=0 && nYear%4==0) || (nYear%400 == 0))
				nLastDay = 29;
			else
				nLastDay = 28;
		}
		break;
	case 3:
		nLastDay = 31;
		break;
	case 4:
		nLastDay = 30;
		break;
	case 5:
		nLastDay = 31;
		break;
	case 6:
		nLastDay = 30;
		break;
	case 7:
		nLastDay = 31;
		break;
	case 8:
		nLastDay = 31;
		break;
	case 9:
		nLastDay = 30;
		break;
	case 10:
		nLastDay = 31;
		break;
	case 11:
		nLastDay = 30;
		break;
	case 12:
		nLastDay = 31;
		break;
	default:
		break;
	}
	for(int i=nLastDay; i>=1; --i)
	{
		{
			list<sRuKuBaseInfo>::iterator itB = m_vecRuKuInfo[i - 1].begin();
			list<sRuKuBaseInfo>::iterator itE = m_vecRuKuInfo[i - 1].end();
			while(itB != itE)
			{
				list<sRuKuDetailInfo>::iterator _itB = itB->detail_info.begin();
				list<sRuKuDetailInfo>::iterator _itE = itB->detail_info.end();
				while(_itB != _itE)
				{
					map<wstring, sGoodsCangChuInfo>::iterator itGood = mapKuCunInfo.find(_itB->chan_pin_ming);
					if(itGood != mapKuCunInfo.end())
						itGood->second.ku_cun -= _itB->ru_ku_shu_liang;
					++_itB;
				}
				++itB;
			}
		}
		{
			list<sChuKuBaseInfo>::iterator itB = m_vecChuKuInfo[i - 1].begin();
			list<sChuKuBaseInfo>::iterator itE = m_vecChuKuInfo[i - 1].end();
			while(itB != itE)
			{
				list<sChuKuDetailInfo>::iterator _itB = itB->detail_info.begin();
				list<sChuKuDetailInfo>::iterator _itE = itB->detail_info.end();
				while(_itB != _itE)
				{
					map<wstring, sGoodsCangChuInfo>::iterator itGood = mapKuCunInfo.find(_itB->chan_pin_ming);
					if(itGood != mapKuCunInfo.end())
						itGood->second.ku_cun += _itB->chu_ku_shu_liang;
					++_itB;
				}
				++itB;
			}
		}
		{
			double bs = 0;
			map<wstring, sGoodsCangChuInfo>::iterator itB = mapKuCunInfo.begin();
			map<wstring, sGoodsCangChuInfo>::iterator itE = mapKuCunInfo.end();
			while(itB != itE)
			{
				if(itB->second.ku_cun > 0)
				{
					if(itB->second.ban_shu_biao_zhun)
					{
						double _bs = itB->second.ku_cun / (double)itB->second.ban_shu_biao_zhun;
						if(_bs > 1)
						{
							int nbs = int(_bs);
							double dXS = _bs - double(nbs);
							bs += nbs;
							if(dXS > DOUBLE_PRECISION)
								bs += 1;
						}
						else if(_bs >= 0.5 && _bs < 1)
							bs += 1;
						else if(_bs < 0.5)
							bs += 0.5;
					}
					else
						bs += 1;
				}
				++itB;
			}
			int nbs = int(bs);
			double dXS = bs - double(nbs);
			if(dXS > DOUBLE_PRECISION)
				bs = nbs + 1;


			wchar_t _szBuffer[128] = { 0 };
			wsprintfW(_szBuffer, L"%d月%d日", m_nMonth, i);
			_sheet->Cell(nRecordRowIndex, 0)->SetWString(_szBuffer);
			_sheet->Cell(nRecordRowIndex, 1)->SetDouble(bs);
			_sheet->Cell(nRecordRowIndex, 2)->SetDouble(bs*cang_chu_fei);
			m_dCangChuFeiHeJi += bs*cang_chu_fei;
			nRecordRowIndex++;
		}
	}
	return true;
}

bool CSheQuTuanGouDlg::_____MakeTuiHuoFei(BasicExcel& excel)
{
	int nRecordRowIndex = 0;
	BasicExcelWorksheet* _sheet = excel.GetWorksheet(L"退货费用");
	_sheet->Cell(nRecordRowIndex, 0)->SetWString(L"时间");
	_sheet->Cell(nRecordRowIndex, 1)->SetWString(L"平台");
	_sheet->Cell(nRecordRowIndex, 2)->SetWString(L"货品明细");
	_sheet->Cell(nRecordRowIndex, 3)->SetWString(L"重量(kg)");
	_sheet->Cell(nRecordRowIndex, 4)->SetWString(L"体积(m3)");
	_sheet->Cell(nRecordRowIndex, 5)->SetWString(L"板数");
	_sheet->Cell(nRecordRowIndex, 6)->SetWString(L"费用");
	nRecordRowIndex++;
	for(int i = 0; i<(int)m_vecRuKuInfo.size(); ++i)
	{
		if(m_vecRuKuInfo[i].size() > 0)
		{
			list<sRuKuBaseInfo>::iterator itB = m_vecRuKuInfo[i].begin();
			list<sRuKuBaseInfo>::iterator itE = m_vecRuKuInfo[i].end();
			while(itB != itE)
			{
				if(itB->lei_xing == L"多多退货" || itB->lei_xing == L"美团退货")
				{
					wchar_t _szBuffer[128] = { 0 };
					wsprintfW(_szBuffer, L"%d月%d日", m_nMonth, itB->day);
					_sheet->Cell(nRecordRowIndex, 0)->SetWString(_szBuffer);
					list<sRuKuDetailInfo>::iterator _itB = itB->detail_info.begin();
					list<sRuKuDetailInfo>::iterator _itE = itB->detail_info.end();
					wchar_t _szGoodsInfo[512] = { 0 };
					double zl = 0;//重量
					double tj = 0;//体积
					double bs = 0;//板数
					while(_itB != _itE)
					{
						if(wcslen(_szGoodsInfo) > 0)
							StrCatW(_szGoodsInfo, L"\t\n");
						StrCatW(_szGoodsInfo, _itB->chan_pin_ming.c_str());
						StrCatW(_szGoodsInfo, L" @ ");
						wsprintfW(_szGoodsInfo, L"%s%d%s", _szGoodsInfo, _itB->ru_ku_shu_liang, _itB->dan_wei.c_str());
						map<wstring, sGoodsBaseInfo>::iterator itGood = m_mapGoodsBaseInfo.find(_itB->chan_pin_ming);
						if(itGood != m_mapGoodsBaseInfo.end())
						{
							bs += _itB->ru_ku_shu_liang / (double)itGood->second.ban_shu_biao_zhun;
						}
						zl += _itB->zhong_liang;
						tj += _itB->ti_ji;
						++_itB;
					}
					if(itB->lei_xing == L"多多退货")
						_sheet->Cell(nRecordRowIndex, 1)->SetWString(L"多多买菜");
					if(itB->lei_xing == L"美团退货")
						_sheet->Cell(nRecordRowIndex, 1)->SetWString(L"美团优选");
					_sheet->Cell(nRecordRowIndex, 2)->SetWString(_szGoodsInfo);
					_sheet->Cell(nRecordRowIndex, 3)->SetDouble(zl);
					_sheet->Cell(nRecordRowIndex, 4)->SetDouble(tj);;
					double dXS = 0;
					int nbs = int(bs);
					dXS = bs - double(nbs);
					if(dXS > DOUBLE_PRECISION)
					{
						if(dXS - 0.5 <= DOUBLE_PRECISION)
						{
							if(nbs == 0)
							{
								if(dXS - 0.1 <= DOUBLE_PRECISION)
									_sheet->Cell(nRecordRowIndex, 5)->SetDouble(0.1);
								else
									_sheet->Cell(nRecordRowIndex, 5)->SetDouble(0.5);
							}
							else
								_sheet->Cell(nRecordRowIndex, 5)->SetDouble(nbs + 0.5);
						}
						else
							_sheet->Cell(nRecordRowIndex, 5)->SetDouble(nbs + 1);
					}
					else
						_sheet->Cell(nRecordRowIndex, 5)->SetDouble(nbs);
					switch(shou_fei_mo_shi)
					{
					case 0:
					case 6:
						{
							  double tui_huo_fei = GetTuiHuoFei(bs, tui_huo_fei_yi_tuo, tui_huo_fei_ban_tuo);
							  m_dTuiHuoFeiHeJi += tui_huo_fei;
							  _sheet->Cell(nRecordRowIndex, 6)->SetDouble(tui_huo_fei);
						}
						break;
					case 3:
						{
							  double tui_huo_fei1 = zl / 1000.0*tui_huo_fei_yi_dun;
							  double tui_huo_fei2 = tj*tui_huo_fei_yi_fang;
							  double tui_huo_fei = max(tui_huo_fei1, tui_huo_fei2);
							  m_dTuiHuoFeiHeJi += tui_huo_fei;
							  _sheet->Cell(nRecordRowIndex, 6)->SetDouble(tui_huo_fei);
						}
						break;
					case 1:
					case 2:
					case 4:
					case 5:
						{	
							_sheet->Cell(nRecordRowIndex, 6)->SetDouble(0);
						}
						break;
					default:
						{
							wchar_t _szBuffer[128] = { 0 };
							wsprintfW(_szBuffer, L"------------------未处理的收费方式-退货 类型=%d", shou_fei_mo_shi);
							THROW_ERROR(_szBuffer);
						}
						break;
					}
					nRecordRowIndex++;
				}
				++itB;
			}
		}
	}
	if(shou_fei_mo_shi == 4)
	{
		_sheet->Cell(nRecordRowIndex, 5)->SetWString(L"包月");
		_sheet->Cell(nRecordRowIndex, 6)->SetDouble((double)tui_huo_fei_bao_yue);
	}
	return true;
}

double CSheQuTuanGouDlg::GetTuiHuoFei(double bs, int tui_huo_yi_tuo, int tui_huo_ban_tuo)
{
	double dXS = 0;
	int nbs = int(bs);
	dXS = bs - double(nbs);
	double tui_huo_fei = nbs*tui_huo_fei_yi_tuo;
	if(dXS > DOUBLE_PRECISION)
	{
		if(dXS - 0.5 <= DOUBLE_PRECISION)
		{
			if(nbs == 0)
			{
				if(dXS - 0.1 <= DOUBLE_PRECISION)
				{
					if(tui_huo_fei_ban_tuo || tui_huo_fei_yi_tuo)
						tui_huo_fei += ZUI_DI_TUI_HUO_FEI;
					else
						tui_huo_fei = 0;
				}
				else
					tui_huo_fei += tui_huo_fei_ban_tuo;
			}
			else
				tui_huo_fei += tui_huo_fei_ban_tuo;
		}
		else
			tui_huo_fei += tui_huo_fei_yi_tuo;
	}
	return tui_huo_fei;
}

bool CSheQuTuanGouDlg::_____MakeSongHuoFei(BasicExcel& excel)
{
	int nRecordRowIndex = 0;
	BasicExcelWorksheet* _sheet = excel.GetWorksheet(L"送货费用");
	_sheet->Cell(nRecordRowIndex, 0)->SetWString(L"时间");
	_sheet->Cell(nRecordRowIndex, 1)->SetWString(L"平台");
	_sheet->Cell(nRecordRowIndex, 2)->SetWString(L"货品明细");
	_sheet->Cell(nRecordRowIndex, 3)->SetWString(L"重量(kg)");
	_sheet->Cell(nRecordRowIndex, 4)->SetWString(L"体积(m3)");
	_sheet->Cell(nRecordRowIndex, 5)->SetWString(L"板数");
	_sheet->Cell(nRecordRowIndex, 6)->SetWString(L"贴标数");
	_sheet->Cell(nRecordRowIndex, 7)->SetWString(L"备注");
	_sheet->Cell(nRecordRowIndex, 8)->SetWString(L"费用");
	nRecordRowIndex++;
	for(int i = 0; i<(int)m_vecChuKuInfo.size(); ++i)
	{
		if(m_vecChuKuInfo[i].size() > 0)
		{
			list<sChuKuBaseInfo>::iterator itB = m_vecChuKuInfo[i].begin();
			list<sChuKuBaseInfo>::iterator itE = m_vecChuKuInfo[i].end();
			while(itB != itE)
			{
				if(itB->lei_xing == L"多多送货" || itB->lei_xing == L"美团送货" || itB->lei_xing == L"盒马送货")
				{
					wchar_t _szBuffer[128] = { 0 };
					wsprintfW(_szBuffer, L"%d月%d日", m_nMonth, itB->day);
					_sheet->Cell(nRecordRowIndex, 0)->SetWString(_szBuffer);
					list<sChuKuDetailInfo>::iterator _itB = itB->detail_info.begin();
					list<sChuKuDetailInfo>::iterator _itE = itB->detail_info.end();
					wchar_t _szGoodsInfo[512] = { 0 };
					double zl = 0;//重量
					double tj = 0;//体积
					double bs = 0;//板数
					int tbs = 0;//贴标数
					bool bh = false;//补货
					while(_itB != _itE)
					{
						if(wcslen(_szGoodsInfo) > 0)
							StrCatW(_szGoodsInfo, L"\t\n");
						StrCatW(_szGoodsInfo, _itB->chan_pin_ming.c_str());
						StrCatW(_szGoodsInfo, L" @ ");
						wsprintfW(_szGoodsInfo, L"%s%d%s", _szGoodsInfo, _itB->chu_ku_shu_liang, _itB->dan_wei.c_str());
						map<wstring, sGoodsBaseInfo>::iterator itGood = m_mapGoodsBaseInfo.find(_itB->chan_pin_ming);
						if(itGood != m_mapGoodsBaseInfo.end())
						{
							bs += _itB->chu_ku_shu_liang/(double)itGood->second.ban_shu_biao_zhun;
						}
						zl += _itB->zhong_liang;
						tj += _itB->ti_ji;
						tbs += _itB->tie_biao;
						++_itB;
					}
					if(itB->bei_zhu != L"")
					{
						vec_wvals beizhus;
						CFuncCommon::parse_pairs(itB->bei_zhu, beizhus);
						for(int i=0; i<(int)beizhus.size(); ++i)
						{
							if(beizhus[i] == L"补货" || beizhus[i] == L"夜间补货")
							{
								bh = true;
							}
							else if(beizhus[i].find(L"板") != wstring::npos)
							{
								wstring szBS = beizhus[i].substr(0, beizhus[i].find(L"板"));
								double _bs = _wtof(szBS.c_str());
								bs = max(_bs, bs);
							}
						}
					}
					if(itB->lei_xing == L"多多送货")
						_sheet->Cell(nRecordRowIndex, 1)->SetWString(L"多多买菜");
					if(itB->lei_xing == L"美团送货")
						_sheet->Cell(nRecordRowIndex, 1)->SetWString(L"美团优选");
					if(itB->lei_xing == L"盒马送货")
						_sheet->Cell(nRecordRowIndex, 1)->SetWString(L"盒马优选");
					_sheet->Cell(nRecordRowIndex, 2)->SetWString(_szGoodsInfo);
					_sheet->Cell(nRecordRowIndex, 3)->SetDouble(zl);
					_sheet->Cell(nRecordRowIndex, 4)->SetDouble(tj);
					_sheet->Cell(nRecordRowIndex, 6)->SetInteger(tbs);
					if(bh)
						_sheet->Cell(nRecordRowIndex, 7)->SetWString(L"补货");
					double dXS = 0;
					int nbs = int(bs);
					dXS = bs - double(nbs);
					if(dXS > DOUBLE_PRECISION)
					{
						if(dXS - 0.5 <= DOUBLE_PRECISION)
							_sheet->Cell(nRecordRowIndex, 5)->SetDouble(nbs+0.5);
						else
							_sheet->Cell(nRecordRowIndex, 5)->SetDouble(nbs+1);
					}
					else
						_sheet->Cell(nRecordRowIndex, 5)->SetDouble(nbs);
					switch(shou_fei_mo_shi)
					{
					case 0:
						{
							double song_huo_fei = nbs*song_huo_fei_yi_tuo;
							if(dXS > DOUBLE_PRECISION)
							{
								if(dXS - 0.5 <= DOUBLE_PRECISION)
									song_huo_fei += song_huo_fei_ban_tuo;
								else
									song_huo_fei += song_huo_fei_yi_tuo;
							}
							if(itB->lei_xing == L"美团送货" || itB->lei_xing == L"盒马送货")
								song_huo_fei += mei_tuan_jia_shou;
							if(bh)
								song_huo_fei = song_huo_fei*1.3;
							song_huo_fei += tbs*tie_biao_fei;
							m_dSongHuoFeiHeJi += song_huo_fei;
							_sheet->Cell(nRecordRowIndex, 8)->SetDouble(song_huo_fei);
						}
						break;
					case 1:
						{
							double song_huo_fei = zl/1000.0*xie_song_tui_bao_gan;
							if(itB->lei_xing == L"美团送货" || itB->lei_xing == L"盒马送货")
								song_huo_fei += mei_tuan_jia_shou;
							if(bh)
								song_huo_fei = song_huo_fei*1.3;
							song_huo_fei += tbs*tie_biao_fei;
							m_dSongHuoFeiHeJi += song_huo_fei;
							_sheet->Cell(nRecordRowIndex, 8)->SetDouble(song_huo_fei);
						}
						break;
					case 2:
						{
							  double song_huo_fei = zl / 1000.0*song_tui_tie_bao_gan_yi_dun;
							  if(itB->lei_xing == L"美团送货" || itB->lei_xing == L"盒马送货")
								  song_huo_fei += mei_tuan_jia_shou;
							  if(bh)
								  song_huo_fei = song_huo_fei*1.3;
							  m_dSongHuoFeiHeJi += song_huo_fei;
							  _sheet->Cell(nRecordRowIndex, 8)->SetDouble(song_huo_fei);
						}
						break;
					case 3:
					case 6:
						{
							  double song_huo_fei1 = zl / 1000.0*song_huo_fei_yi_dun;
							  double song_huo_fei2 = tj * song_huo_fei_yi_fang;
							  double song_huo_fei = max(song_huo_fei1, song_huo_fei2);
							  song_huo_fei = max(song_huo_fei, song_huo_fei_bao_di);
							  if(itB->lei_xing == L"美团送货" || itB->lei_xing == L"盒马送货")
								  song_huo_fei += mei_tuan_jia_shou;
							  if(bh)
								  song_huo_fei = song_huo_fei*1.3;
							  song_huo_fei += tbs*tie_biao_fei;
							  m_dSongHuoFeiHeJi += song_huo_fei;
							  _sheet->Cell(nRecordRowIndex, 8)->SetDouble(song_huo_fei);
						}
						break;
					case 4:
						{
							  double song_huo_fei1 = zl / 1000.0*song_huo_fei_yi_dun;
							  double song_huo_fei2 = tj * song_huo_fei_yi_fang;
							  double song_huo_fei = max(song_huo_fei1, song_huo_fei2);
							  song_huo_fei = max(song_huo_fei, song_huo_fei_bao_di);
							  if(itB->lei_xing == L"美团送货" || itB->lei_xing == L"盒马送货")
								  song_huo_fei += mei_tuan_jia_shou;
							  if(bh)
								  song_huo_fei = song_huo_fei*1.3;
							  song_huo_fei += tbs*tie_biao_fei;
							  m_dSongHuoFeiHeJi += song_huo_fei;
							  _sheet->Cell(nRecordRowIndex, 8)->SetDouble(song_huo_fei);
						}
						break;
					case 5:
						{
							int nJS = 0;
							list<sChuKuDetailInfo>::iterator __itB =  itB->detail_info.begin();
							list<sChuKuDetailInfo>::iterator __itE =  itB->detail_info.end();
							while(__itB != __itE)
							{
								map<wstring, sGoodsBaseInfo>::iterator __it = m_mapGoodsBaseInfo.find(__itB->chan_pin_ming);
								if(__it != m_mapGoodsBaseInfo.end())
								{
									if((__itB->chu_ku_shu_liang % __it->second.xiang_gui) != 0)
									{
										nJS += __itB->chu_ku_shu_liang/__it->second.xiang_gui;
										nJS += 1;
									}
									else
									{
										nJS += __itB->chu_ku_shu_liang / __it->second.xiang_gui;
									}
								}
								++__itB;
							}
							_sheet->Cell(nRecordRowIndex, 8)->SetDouble(nJS*song_tui_tie_yi_jian);
							break;
						}
					default:
						{
							wchar_t _szBuffer[128] = { 0 };
							wsprintfW(_szBuffer, L"------------------未处理的收费方式-送货 类型=%d", shou_fei_mo_shi);
							THROW_ERROR(_szBuffer);
						}
						break;
					}
					nRecordRowIndex++;
				}
				++itB;
			}
		}
	}
	return true;
}

bool CSheQuTuanGouDlg::LoadKuCun(BasicExcel& dataExcel)
{
	enum eT
	{
		_0 = 0,	//产品名
		_1,		//箱规
		_2,		//最小单位
		_3,		//库存(最小单位)
		_4,		//库存(件数)
		_5,		//库存零头(最小单位)
		_6,		//单件吨位
		_7,		//单件方位
		_8,		//重量/最小单位
		_9,		//体积/最小单位
		_10,	//板数标准
		_M,
	};
	BasicExcelWorksheet* _sheet = dataExcel.GetWorksheet(L"库存");
	if(_sheet)
	{
		int nIndex[_M];
		for(int i = 0; i < _M; ++i)
		{
			nIndex[i] = -1;
		}
		size_t maxRows = _sheet->GetTotalRows();
		size_t maxCols = _sheet->GetTotalCols();
		for(size_t c = 0; c < maxCols; ++c)
		{
			BasicExcelCell* cell = _sheet->Cell(0, c);
			std::wstring strTitle = cell->GetWString();


			if(strTitle == L"产品名")
				nIndex[_0] = c;
			else if(strTitle == L"箱规")
				nIndex[_1] = c;
			else if(strTitle == L"最小单位")
				nIndex[_2] = c;
			else if(strTitle == L"库存(最小单位)")
				nIndex[_3] = c;
			else if(strTitle == L"库存(件数)")
				nIndex[_4] = c;
			else if(strTitle == L"库存零头(最小单位)")
				nIndex[_5] = c;
			else if(strTitle == L"单件吨位" || strTitle == L"单件重量(kg)")
				nIndex[_6] = c;
			else if(strTitle == L"单件方位" || (strTitle.find(L"单件体积(") != wstring::npos))
				nIndex[_7] = c;
			else if(strTitle == L"重量/最小单位")
				nIndex[_8] = c;
			else if(strTitle == L"体积/最小单位")
				nIndex[_9] = c;
			else if(strTitle == L"板数标准" || strTitle == L"板数标准(整件)")
				nIndex[_10] = c;
		}
		for(int i = 0; i < _M; ++i)
		{
			if(nIndex[i] == -1)
			{
				THROW_ERROR(L"------------------库存有标题未找到");
			}
		}
		for(size_t r = 1; r < maxRows; ++r)
		{
			sGoodsBaseInfo _data;
			const wchar_t* _pStr = NULL;
			SHEET_CELL_STRING(_sheet, r, nIndex[_0], _data.chan_pin_ming);
			if(_data.chan_pin_ming != L"")
			{
				SHEET_CELL_INT(_sheet, r, nIndex[_1], _data.xiang_gui);
				SHEET_CELL_STRING(_sheet, r, nIndex[_2], _data.zui_xiao_dan_wei);
				SHEET_CELL_INT(_sheet, r, nIndex[_3], _data.ku_cun);
				if(_data.ku_cun < 0)
					_data.ku_cun = 0;
				SHEET_CELL_DOUBLE(_sheet, r, nIndex[_6], _data.dan_jian_zhong_liang);
				SHEET_CELL_DOUBLE(_sheet, r, nIndex[_7], _data.dan_jian_ti_ji);
				SHEET_CELL_INT(_sheet, r, nIndex[_10], _data.ban_shu_biao_zhun);
				if(_data.dan_jian_zhong_liang < DOUBLE_PRECISION && _data.dan_jian_ti_ji < DOUBLE_PRECISION)
				{
					wstring info = L"------------------[" + _data.chan_pin_ming + L"]" + L" 缺少重量及体积数据";
					AddLog(info);
				}
				if(_data.ku_cun > 0)
					m_nKunCunCnt += _data.ku_cun;
				if(_data.ban_shu_biao_zhun == 0)
				{
					int nZLCnt = 0;
					int nTJCnt = 0;
					if(_data.dan_jian_zhong_liang > 0)
					{
						nZLCnt = int(850/_data.dan_jian_zhong_liang);
					}
					if(_data.dan_jian_ti_ji > 0)
					{
						nTJCnt = int(1.8/_data.dan_jian_ti_ji);
					}
					if(nZLCnt > 0 && nZLCnt < nTJCnt)
						_data.ban_shu_biao_zhun = nZLCnt;
					if(nTJCnt > 0 && nTJCnt < nZLCnt)
						_data.ban_shu_biao_zhun = nTJCnt;
				}
				if(1000/_data.dan_jian_zhong_liang*_data.dan_jian_ti_ji < 3)
					_data.bPaoHuo = false;
				else
					_data.bPaoHuo = true;
				_data.ban_shu_biao_zhun = _data.ban_shu_biao_zhun*_data.xiang_gui;
				m_mapGoodsBaseInfo[_data.chan_pin_ming] = _data;
			}
		}
	}
	else
	{
		THROW_ERROR(L"------------------没有找到库存分页");
	}
	return true;
}

bool CSheQuTuanGouDlg::LoadRuKu(BasicExcel& dataExcel)
{
	const wchar_t* _pStr = NULL;

	enum eT
	{
		_0 = 0,	//日期
		_1,		//入库类型
		_2,		//商品名称
		_3,		//入库数量
		_4,		//重量
		_5,		//体积
		_6,		//备注
		_7,		//入库单位
		_M,
	};
	BasicExcelWorksheet* _sheet = dataExcel.GetWorksheet(L"入库");
	if(_sheet)
	{
		int nIndex[_M];
		for(int i = 0; i < _M; ++i)
		{
			nIndex[i] = -1;
		}
		size_t maxRows = _sheet->GetTotalRows();
		size_t maxCols = _sheet->GetTotalCols();
		for(size_t c = 0; c < maxCols; ++c)
		{
			wstring strTitle;
			SHEET_CELL_STRING(_sheet, 0, c, strTitle);

			if(strTitle == L"日期")
				nIndex[_0] = c;
			else if(strTitle == L"入库类型")
				nIndex[_1] = c;
			else if(strTitle == L"商品名称")
				nIndex[_2] = c;
			else if(strTitle == L"入库数量")
				nIndex[_3] = c;
			else if(strTitle == L"重量" || strTitle == L"入库重量(kg)")
				nIndex[_4] = c;
			else if(strTitle == L"体积" || (strTitle.find(L"入库体积(") != wstring::npos))
				nIndex[_5] = c;
			else if(strTitle == L"备注")
				nIndex[_6] = c;
			else if(strTitle == L"入库单位")
				nIndex[_7] = c;
		}
		for(int i = 0; i < _M; ++i)
		{
			if(nIndex[i] == -1)
			{
				THROW_ERROR(L"------------------入库有标题未找到");
			}
		}
		sRuKuBaseInfo* pCurBaseInfo = NULL;
		bool bAfter = false;
		for(size_t r = 1; r < maxRows; ++r)
		{
			int ri_qi;
			SHEET_CELL_INT(_sheet, r, nIndex[_0], ri_qi);
			sRuKuDetailInfo detailInfo;
			SHEET_CELL_STRING(_sheet, r, nIndex[_2], detailInfo.chan_pin_ming);
			SHEET_CELL_INT(_sheet, r, nIndex[_3], detailInfo.ru_ku_shu_liang);
			SHEET_CELL_DOUBLE(_sheet, r, nIndex[_4], detailInfo.zhong_liang);
			SHEET_CELL_DOUBLE(_sheet, r, nIndex[_5], detailInfo.ti_ji);
			SHEET_CELL_STRING(_sheet, r, nIndex[_6], detailInfo.bei_zhu);
			SHEET_CELL_STRING(_sheet, r, nIndex[_7], detailInfo.dan_wei);
			if(ri_qi)
			{
				boost::gregorian::date _date(1900, boost::gregorian::Jan,1);
				_date += boost::gregorian::days(ri_qi-2);

				int _day = _date.day();
				int _month = _date.month();
				if(_month == m_nMonth)
				{
					bAfter = false;
					wstring lei_xing;
					SHEET_CELL_STRING(_sheet, r, nIndex[_1], lei_xing);
					bool bFound = false;
					if(lei_xing == L"多多退货" || lei_xing == L"美团退货")
					{
						list<sRuKuBaseInfo>::iterator itB = m_vecRuKuInfo[_day - 1].begin();
						list<sRuKuBaseInfo>::iterator itE = m_vecRuKuInfo[_day - 1].end();
						while(itB != itE)
						{
							if(itB->lei_xing == lei_xing)
							{
								pCurBaseInfo = &(*itB);
								bFound = true;
								break;
							}
							++itB;
						}
						
					}
					if(!bFound)
					{
						sRuKuBaseInfo info;
						m_vecRuKuInfo[_day - 1].push_back(info);
						pCurBaseInfo = &(*(--m_vecRuKuInfo[_day - 1].end()));
						pCurBaseInfo->day = _day;
						pCurBaseInfo->lei_xing = lei_xing;
					}
					m_nRuKuDataCnt++;
				}
				if(_month > m_nMonth)
					bAfter = true;
			}
			if(bAfter && detailInfo.chan_pin_ming != L"")
			{
				map<wstring, int>::iterator itF = m_mapAfterRuKu.find(detailInfo.chan_pin_ming);
				if(itF != m_mapAfterRuKu.end())
					itF->second += detailInfo.ru_ku_shu_liang;
				else
					m_mapAfterRuKu[detailInfo.chan_pin_ming] = detailInfo.ru_ku_shu_liang;
			}
			else if(detailInfo.chan_pin_ming != L"" && pCurBaseInfo)
			{
				bool bFound = false;
				if(pCurBaseInfo->lei_xing == L"多多退货" || pCurBaseInfo->lei_xing == L"美团退货")
				{
					list<sRuKuDetailInfo>::iterator itB = pCurBaseInfo->detail_info.begin();
					list<sRuKuDetailInfo>::iterator itE = pCurBaseInfo->detail_info.end();
					while(itB != itE)
					{
						if(itB->chan_pin_ming == detailInfo.chan_pin_ming)
						{
							itB->ru_ku_shu_liang += detailInfo.ru_ku_shu_liang;
							itB->zhong_liang += detailInfo.zhong_liang;
							itB->ti_ji += detailInfo.ti_ji;
							bFound = true;
							break;
						}
						++itB;
					}
					
				}
				if(!bFound)
					pCurBaseInfo->detail_info.push_back(detailInfo);
				m_nRuKuDataCnt++;
			}
				
		}
	}
	else
	{
		THROW_ERROR(L"------------------没有找到入库分页");
	}
	return true;
}

bool CSheQuTuanGouDlg::LoadChuKu(BasicExcel& dataExcel)
{
	const wchar_t* _pStr = NULL;
	enum eT
	{
		_0 = 0,	//日期
		_1,		//出库类型
		_2,		//商品名称
		_3,		//出库数量
		_4,		//出库重量
		_5,		//出库方量
		_6,		//贴标数
		_7,		//备注
		_8,		//出库单位
		_M,
	};
	BasicExcelWorksheet* _sheet = dataExcel.GetWorksheet(L"出库");
	if(_sheet)
	{
		int nIndex[_M];
		for(int i = 0; i < _M; ++i)
		{
			nIndex[i] = -1;
		}
		size_t maxRows = _sheet->GetTotalRows();
		size_t maxCols = _sheet->GetTotalCols();
		for(size_t c = 0; c < maxCols; ++c)
		{
			std::wstring strTitle;
			SHEET_CELL_STRING(_sheet, 0, c, strTitle);


			if(strTitle == L"日期")
				nIndex[_0] = c;
			else if(strTitle == L"出库类型")
				nIndex[_1] = c;
			else if(strTitle == L"商品名称")
				nIndex[_2] = c;
			else if(strTitle == L"出库数量")
				nIndex[_3] = c;
			else if(strTitle == L"出库重量" || strTitle == L"出库重量(kg)")
				nIndex[_4] = c;
			else if(strTitle == L"出库方量" || (strTitle.find(L"出库体积(") != wstring::npos))
				nIndex[_5] = c;
			else if(strTitle == L"贴标数")
				nIndex[_6] = c;
			else if(strTitle == L"备注")
				nIndex[_7] = c;
			else if(strTitle == L"出库单位")
				nIndex[_8] = c;
		}
		for(int i = 0; i < _M; ++i)
		{
			if(nIndex[i] == -1)
			{
				THROW_ERROR(L"------------------出库有标题未找到");
			}
		}
		bool bAfter = false;
		sChuKuBaseInfo* pCurBaseInfo = NULL;
		for(size_t r = 1; r < maxRows; ++r)
		{
			int ri_qi;
			SHEET_CELL_INT(_sheet, r, nIndex[_0], ri_qi);
			if(ri_qi)
			{

				boost::gregorian::date _date(1900, boost::gregorian::Jan, 1);
				_date += boost::gregorian::days(ri_qi - 2);

				int _day = _date.day();
				int _month = _date.month();
				if(_month == m_nMonth)
				{
					bAfter = false;
					sChuKuBaseInfo info;
					m_vecChuKuInfo[_day - 1].push_back(info);
					pCurBaseInfo = &(*(--m_vecChuKuInfo[_day - 1].end()));
					pCurBaseInfo->day = _day;
					wstring lei_xing;
					SHEET_CELL_STRING(_sheet, r, nIndex[_1], pCurBaseInfo->lei_xing);
				}
				if(_month > m_nMonth)
					bAfter = true;
			}
			sChuKuDetailInfo detailInfo;
			SHEET_CELL_STRING(_sheet, r, nIndex[_2], detailInfo.chan_pin_ming);
			SHEET_CELL_INT(_sheet, r, nIndex[_3], detailInfo.chu_ku_shu_liang);
			SHEET_CELL_DOUBLE(_sheet, r, nIndex[_4], detailInfo.zhong_liang);
			SHEET_CELL_DOUBLE(_sheet, r, nIndex[_5], detailInfo.ti_ji);
			SHEET_CELL_INT(_sheet, r, nIndex[_6], detailInfo.tie_biao);
			SHEET_CELL_STRING(_sheet, r, nIndex[_7], detailInfo.bei_zhu);
			SHEET_CELL_STRING(_sheet, r, nIndex[_8], detailInfo.dan_wei);
			if(bAfter && detailInfo.chan_pin_ming != L"")
			{
				map<wstring, int>::iterator itF = m_mapAfterChuKu.find(detailInfo.chan_pin_ming);
				if(itF != m_mapAfterChuKu.end())
					itF->second += detailInfo.chu_ku_shu_liang;
				else
					m_mapAfterChuKu[detailInfo.chan_pin_ming] = detailInfo.chu_ku_shu_liang;
			}
			else if(detailInfo.chan_pin_ming != L"" && pCurBaseInfo)
			{
				pCurBaseInfo->detail_info.push_back(detailInfo);
				if(detailInfo.bei_zhu != L"")
				{
					pCurBaseInfo->bei_zhu += detailInfo.bei_zhu;
					pCurBaseInfo->bei_zhu += L";";
				}
				m_nChuKuDataCnt++;
			}
		}
	}
	else
	{
		THROW_ERROR(L"------------------没有找到出库分页");
	}
	return true;
}

bool CSheQuTuanGouDlg::LoadZengZhi(BasicExcel& dataExcel)
{
	enum eT
	{
		_0 = 0,	//日期
		_1,		//类型
		_2,		//代打卡次数
		_3,		//代交货SKU数
		_4,		//贴标数
		_M,
	};
	const wchar_t* _pStr = NULL;
	BasicExcelWorksheet* _sheet = dataExcel.GetWorksheet(L"增值服务");
	if(_sheet)
	{
		int nIndex[_M];
		for(int i = 0; i < _M; ++i)
		{
			nIndex[i] = -1;
		}
		size_t maxRows = _sheet->GetTotalRows();
		size_t maxCols = _sheet->GetTotalCols();
		for(size_t c = 0; c < maxCols; ++c)
		{
			std::wstring strTitle;
			SHEET_CELL_STRING(_sheet, 0, c, strTitle);

			if(strTitle == L"日期")
				nIndex[_0] = c;
			else if(strTitle == L"类型")
				nIndex[_1] = c;
			else if(strTitle == L"代打卡次数")
				nIndex[_2] = c;
			else if(strTitle == L"代交货SKU数")
				nIndex[_3] = c;
			else if(strTitle == L"贴标数")
				nIndex[_4] = c;
		}
		for(int i = 0; i < _M; ++i)
		{
			if(nIndex[i] == -1)
			{
				THROW_ERROR(L"------------------增值服务有标题未找到");
			}
		}
		for(size_t r = 1; r < maxRows; ++r)
		{
			int ri_qi;
			SHEET_CELL_INT(_sheet, r, nIndex[_0], ri_qi);
			if(ri_qi)
			{

				boost::gregorian::date _date(1900, boost::gregorian::Jan, 1);
				_date += boost::gregorian::days(ri_qi - 2);

				int _day = _date.day();
				int _month = _date.month();
				if(_month == m_nMonth)
				{
					sZengZhiInfo detailInfo;
					detailInfo.day = _day;
					SHEET_CELL_STRING(_sheet, r, nIndex[_1], detailInfo.lei_xing);
					SHEET_CELL_INT(_sheet, r, nIndex[_2], detailInfo.da_ka_ci_shu);
					SHEET_CELL_INT(_sheet, r, nIndex[_3], detailInfo.dai_ru_ku_ci_shu);
					SHEET_CELL_INT(_sheet, r, nIndex[_4], detailInfo.tie_biao_shu);
					m_listZengZhi.push_back(detailInfo);
				}
			}
			
		}
	}
	else
	{
		THROW_ERROR(L"------------------没有找到增值服务分页");
	}
	return true;
}

void CSheQuTuanGouDlg::OnBnClickedButtonMakeAllZD()
{
	if(m_bRun)
	{
		MessageBox(L"正在生成账单,不要重复点击");
		return;
	}
	m_listMakeSJNames.clear();
	CString szMonth;
	m_combMonth.GetWindowText(szMonth);
	m_nMonth = _wtoi(szMonth.GetBuffer());
	for(int i = 0; i < (int)m_vecFiles.size(); ++i)
	{
		if(m_vecFiles[i].at(0) == 'G')
		{
			std::string temp1 = m_vecFiles[i].substr(0, m_vecFiles[i].size() - 4);
			std::wstring temp2 = CFuncCommon::String2WString(temp1.c_str());
			m_listMakeSJNames.push_back(temp2);
		}
	}
	m_bRun = true;
}
