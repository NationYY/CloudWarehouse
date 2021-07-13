
// �����Ź��˵�����Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SheQuTuanGou.h"
#include "SheQuTuanGouDlg.h"
#include "afxdialogex.h"
#include "func_common.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#define DATA_PATH "./�����ļ�"
#define EXPORT_PATH L"./�˵�����"
#define PRICE_FILE L"./price.ini"
#define ZUI_DI_TUI_HUO_FEI 10
#define THROW_ERROR(info) AddLog(info); return false;
#define SHEET_CELL_STRING(sheet, r, c, strOut) _pStr = sheet->Cell(r, c)->GetWString();\
if(_pStr)\
	strOut = _pStr;

#define SHEET_CELL_DOUBLE(sheet, r, c, dOut) dOut = sheet->Cell(r, c)->GetDouble();

#define SHEET_CELL_INT(sheet, r, c, nOut) nOut = sheet->Cell(r, c)->GetInteger();

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���


class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CSheQuTuanGouDlg �Ի���



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


// CSheQuTuanGouDlg ��Ϣ�������

BOOL CSheQuTuanGouDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��
	//m_listCtrlAllKeHu.AddString(L"1");
	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
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
		MessageBox(L"������־�ļ�ʧ��!");
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CSheQuTuanGouDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
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
		if(strLog == L"�˵��������")
			MessageBox(L"�˵��������");
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
			AddLog(L"�˵�ȫ���������");
			char szBuffer[128] = { 0 };
			wstring _szInfo;
			sprintf(szBuffer, "װж�Ѻϼ� %.1f", m_dZhuangXieFeiHeJi);
			_szInfo = CFuncCommon::String2WString(szBuffer);
			AddLog(_szInfo);
			sprintf(szBuffer, "�ͻ��Ѻϼ� %.1f", m_dSongHuoFeiHeJi);
			_szInfo = CFuncCommon::String2WString(szBuffer);
			AddLog(_szInfo);
			sprintf(szBuffer, "�˻��Ѻϼ� %.1f", m_dTuiHuoFeiHeJi);
			_szInfo = CFuncCommon::String2WString(szBuffer);
			AddLog(_szInfo);
			sprintf(szBuffer, "�ִ��Ѻϼ� %.1f", m_dCangChuFeiHeJi);
			_szInfo = CFuncCommon::String2WString(szBuffer);
			AddLog(_szInfo);
			sprintf(szBuffer, "��ֵ�Ѻϼ� %.1f", m_dZengZhiFeiHeJi);
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CSheQuTuanGouDlg::OnBnClickedButtonMakeSelZD()
{
	if(m_bRun)
	{
		MessageBox(L"���������˵�,��Ҫ�ظ����");
		return;
	}
	m_listMakeSJNames.clear();
	CString szName;
	m_editName.GetWindowText(szName);
	if(szName == "")
	{
		MessageBox(L"δѡ���̼�");
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
	wstring info = L"��ȡ" + strKeHuName;
	AddLog(info);
	boost::this_thread::sleep(boost::posix_time::millisec(200));
	std::string fileName1 = DATA_PATH;
	std::string fileName2 =	CFuncCommon::WString2String((L"/" + strKeHuName + L".xls").c_str());
	std::string fileName = fileName1 + fileName2;
	BasicExcel dataExcel;
	if(!dataExcel.Load(fileName.c_str()))
	{
		wchar_t szBuffer[128] = { 0 };
		wsprintfW(szBuffer, L"------------------%s ����ʧ��", strKeHuName.c_str());
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
	//�ȶ�ȡ������Ϣ
	LoadKuCun(dataExcel);
	//��ȡ�����Ϣ
	LoadRuKu(dataExcel);
	//��ȡ������Ϣ
	LoadChuKu(dataExcel);
	//��ȡ��ֵ������Ϣ
	LoadZengZhi(dataExcel);
	if(m_nRuKuDataCnt == 0 && m_nChuKuDataCnt == 0 && m_nKunCunCnt == 0 && m_listZengZhi.size() == 0)
	{
		info = strKeHuName + L"------------------����û������";
		AddLog(info);
		return true;
	}
	MakeData(strKeHuName);
	info = strKeHuName + L"�˵��������";
	AddLog(info);
	return true;
}
int shou_fei_mo_shi = 0;		//�շ�ģʽ
int cang_chu_fei = 0;			//�ִ���
int song_huo_fei_yi_tuo = 0;	//�ͻ���һ��
int song_huo_fei_ban_tuo = 0;	//�ͻ��Ѱ��
int tui_huo_fei_yi_tuo = 0;		//�˻���һ��
int tui_huo_fei_ban_tuo = 0;	//�˻��Ѱ��
double tie_biao_fei = 0;		//�����
int mei_tuan_jia_shou = 0;		//���ż���
int zhuang_xie_zhong_huo = 0;	//װж�ػ�
int zhuang_xie_pao_huo = 0;		//װж�ݻ�
int xie_song_tui_bao_gan = 0;	//ж���˰���
int song_tui_tie_bao_gan_yi_dun = 0;	//���������ɶ�
int song_huo_fei_yi_dun = 0;	//�ͻ���һ��
int song_huo_fei_yi_fang = 0;	//�ͻ���һ��
int song_huo_fei_bao_di	= 0;	//�ͻ��ѱ���
int tui_huo_fei_yi_dun = 0;		//�˻���һ��
int tui_huo_fei_yi_fang = 0;	//�˻���һ��
int tui_huo_fei_bao_yue = 0;	//�˻��Ѱ���
double song_tui_tie_yi_jian = 0;	//������һ��
void ClearPrice()
{
	shou_fei_mo_shi = 0;		//�շ�ģʽ
	cang_chu_fei = 0;			//�ִ���
	song_huo_fei_yi_tuo = 0;	//�ͻ���һ��
	song_huo_fei_ban_tuo = 0;	//�ͻ��Ѱ��
	tui_huo_fei_yi_tuo = 0;		//�˻���һ��
	tui_huo_fei_ban_tuo = 0;	//�˻��Ѱ��
	tie_biao_fei = 0;			//�����
	mei_tuan_jia_shou = 0;		//���ż���
	zhuang_xie_zhong_huo = 0;	//װж�ػ�
	zhuang_xie_pao_huo = 0;		//װж�ݻ�
	xie_song_tui_bao_gan = 0;	//ж���˰���
	song_tui_tie_bao_gan_yi_dun = 0;	//����������
	song_huo_fei_yi_dun = 0;	//�ͻ���һ��
	song_huo_fei_yi_fang = 0;	//�ͻ���һ��
	song_huo_fei_bao_di = 0;	//�ͻ��ѱ���
	tui_huo_fei_yi_dun = 0;		//�˻���һ��
	tui_huo_fei_yi_fang = 0;	//�˻���һ��
	tui_huo_fei_bao_yue = 0;	//�˻��Ѱ���
	song_tui_tie_yi_jian = 0;	//������һ��
}
bool CSheQuTuanGouDlg::LoadPrice(std::wstring strKeHuName)
{
	wchar_t szBuffer[128] = { 0 };
	wchar_t szResult[128] = { 0 };
	wsprintfW(szBuffer, L"%s_�շ�ģʽ", strKeHuName.c_str());
	shou_fei_mo_shi = GetPrivateProfileInt(L"Price", szBuffer, -1, PRICE_FILE);
	if(shou_fei_mo_shi == -1)
	{
		wchar_t _szBuffer[128] = { 0 };
		wsprintfW(_szBuffer, L"------------------%s δ���ü۸�", strKeHuName.c_str());
		THROW_ERROR(_szBuffer);
	}
	switch(shou_fei_mo_shi)
	{
	case 0:
		{
			  wsprintfW(szBuffer, L"%s_�ִ���", strKeHuName.c_str());
			  cang_chu_fei = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_�ͻ���һ��", strKeHuName.c_str());
			  song_huo_fei_yi_tuo = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_�ͻ��Ѱ��", strKeHuName.c_str());
			  song_huo_fei_ban_tuo = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_�˻���һ��", strKeHuName.c_str());
			  tui_huo_fei_yi_tuo = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);;
			  wsprintfW(szBuffer, L"%s_�˻��Ѱ��", strKeHuName.c_str());
			  tui_huo_fei_ban_tuo = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_�����", strKeHuName.c_str());
			  GetPrivateProfileString(L"Price", szBuffer, L"", szResult, 128, PRICE_FILE);
			  if(StrCmpW(szResult, L"") == 0)
			  {
				  wchar_t _szBuffer[128] = { 0 };
				  wsprintfW(_szBuffer, L"------------------%s ����� δ����", strKeHuName.c_str());
				  THROW_ERROR(_szBuffer);
			  }
			  tie_biao_fei = _wtof(szResult);
			  wsprintfW(szBuffer, L"%s_���ż���", strKeHuName.c_str());
			  mei_tuan_jia_shou = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_װж�ػ�", strKeHuName.c_str());
			  zhuang_xie_zhong_huo = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_װж�ݻ�", strKeHuName.c_str());
			  zhuang_xie_pao_huo = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
		}
		break;
	case 1:
		{
			  wsprintfW(szBuffer, L"%s_�ִ���", strKeHuName.c_str());
			  cang_chu_fei = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_���ż���", strKeHuName.c_str());
			  mei_tuan_jia_shou = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_�����", strKeHuName.c_str());
			  GetPrivateProfileString(L"Price", szBuffer, L"", szResult, 128, PRICE_FILE);
			  if(StrCmpW(szResult, L"") == 0)
			  {
				  wchar_t _szBuffer[128] = { 0 };
				  wsprintfW(_szBuffer, L"------------------%s ����� δ����", strKeHuName.c_str());
				  THROW_ERROR(_szBuffer);
			  }
			  tie_biao_fei = _wtof(szResult);
			  wsprintfW(szBuffer, L"%s_ж���˰���", strKeHuName.c_str());
			  xie_song_tui_bao_gan = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_װж�ػ�", strKeHuName.c_str());
			  zhuang_xie_zhong_huo = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_װж�ݻ�", strKeHuName.c_str());
			  zhuang_xie_pao_huo = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
		}
		break;
	case 2:
		{
			  wsprintfW(szBuffer, L"%s_�ִ���", strKeHuName.c_str());
			  cang_chu_fei = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_���������ɶ�", strKeHuName.c_str());
			  song_tui_tie_bao_gan_yi_dun = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_���ż���", strKeHuName.c_str());
			  mei_tuan_jia_shou = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_װж�ػ�", strKeHuName.c_str());
			  zhuang_xie_zhong_huo = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_װж�ݻ�", strKeHuName.c_str());
			  zhuang_xie_pao_huo = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
		}
		break;
	case 3:
		{
			  wsprintfW(szBuffer, L"%s_�ִ���", strKeHuName.c_str());
			  cang_chu_fei = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_�ͻ���һ��", strKeHuName.c_str());
			  song_huo_fei_yi_dun = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_�ͻ���һ��", strKeHuName.c_str());
			  song_huo_fei_yi_fang = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_�ͻ��ѱ���", strKeHuName.c_str());
			  song_huo_fei_bao_di = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_�˻���һ��", strKeHuName.c_str());
			  tui_huo_fei_yi_dun = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_�˻���һ��", strKeHuName.c_str());
			  tui_huo_fei_yi_fang = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_�����", strKeHuName.c_str());
			  GetPrivateProfileString(L"Price", szBuffer, L"", szResult, 128, PRICE_FILE);
			  if(StrCmpW(szResult, L"") == 0)
			  {
				  wchar_t _szBuffer[128] = { 0 };
				  wsprintfW(_szBuffer, L"------------------%s ����� δ����", strKeHuName.c_str());
				  THROW_ERROR(_szBuffer);
			  }
			  tie_biao_fei = _wtof(szResult);
			  wsprintfW(szBuffer, L"%s_���ż���", strKeHuName.c_str());
			  mei_tuan_jia_shou = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_װж�ػ�", strKeHuName.c_str());
			  zhuang_xie_zhong_huo = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_װж�ݻ�", strKeHuName.c_str());
			  zhuang_xie_pao_huo = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
		}
		break;
	case 4:
		{
			wsprintfW(szBuffer, L"%s_�ִ���", strKeHuName.c_str());
			cang_chu_fei = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			wsprintfW(szBuffer, L"%s_�ͻ���һ��", strKeHuName.c_str());
			song_huo_fei_yi_dun = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			wsprintfW(szBuffer, L"%s_�ͻ���һ��", strKeHuName.c_str());
			song_huo_fei_yi_fang = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			wsprintfW(szBuffer, L"%s_�ͻ��ѱ���", strKeHuName.c_str());
			song_huo_fei_bao_di = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			wsprintfW(szBuffer, L"%s_�˻��Ѱ���", strKeHuName.c_str());
			tui_huo_fei_bao_yue = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			wsprintfW(szBuffer, L"%s_�����", strKeHuName.c_str());
			GetPrivateProfileString(L"Price", szBuffer, L"", szResult, 128, PRICE_FILE);
			if(StrCmpW(szResult, L"") == 0)
			{
				wchar_t _szBuffer[128] = { 0 };
				wsprintfW(_szBuffer, L"------------------%s ����� δ����", strKeHuName.c_str());
				THROW_ERROR(_szBuffer);
			}
			tie_biao_fei = _wtof(szResult);
			wsprintfW(szBuffer, L"%s_���ż���", strKeHuName.c_str());
			mei_tuan_jia_shou = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			wsprintfW(szBuffer, L"%s_װж�ػ�", strKeHuName.c_str());
			zhuang_xie_zhong_huo = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			wsprintfW(szBuffer, L"%s_װж�ݻ�", strKeHuName.c_str());
			zhuang_xie_pao_huo = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
		}
		break;
	case 5:
		{
			  wsprintfW(szBuffer, L"%s_�ִ���", strKeHuName.c_str());
			  cang_chu_fei = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_������һ��", strKeHuName.c_str());
			  song_tui_tie_yi_jian =  GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_�ͻ��ѱ���", strKeHuName.c_str());
			  song_huo_fei_bao_di = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_�����", strKeHuName.c_str());
			  GetPrivateProfileString(L"Price", szBuffer, L"", szResult, 128, PRICE_FILE);
			  if(StrCmpW(szResult, L"") == 0)
			  {
				  wchar_t _szBuffer[128] = { 0 };
				  wsprintfW(_szBuffer, L"------------------%s ����� δ����", strKeHuName.c_str());
				  THROW_ERROR(_szBuffer);
			  }
			  tie_biao_fei = _wtof(szResult);
			 
			  wsprintfW(szBuffer, L"%s_���ż���", strKeHuName.c_str());
			  mei_tuan_jia_shou = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_װж�ػ�", strKeHuName.c_str());
			  zhuang_xie_zhong_huo = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_װж�ݻ�", strKeHuName.c_str());
			  zhuang_xie_pao_huo = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
		}
		break;
	case 6:
		{
			  wsprintfW(szBuffer, L"%s_�ִ���", strKeHuName.c_str());
			  cang_chu_fei = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_�ͻ���һ��", strKeHuName.c_str());
			  song_huo_fei_yi_dun = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_�ͻ���һ��", strKeHuName.c_str());
			  song_huo_fei_yi_fang = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_�ͻ��ѱ���", strKeHuName.c_str());
			  song_huo_fei_bao_di = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_�˻���һ��", strKeHuName.c_str());
			  tui_huo_fei_yi_dun = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_�˻���һ��", strKeHuName.c_str());
			  tui_huo_fei_yi_tuo = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);;
			  wsprintfW(szBuffer, L"%s_�˻��Ѱ��", strKeHuName.c_str());
			  tui_huo_fei_ban_tuo = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_�����", strKeHuName.c_str());
			  GetPrivateProfileString(L"Price", szBuffer, L"", szResult, 128, PRICE_FILE);
			  if(StrCmpW(szResult, L"") == 0)
			  {
				  wchar_t _szBuffer[128] = { 0 };
				  wsprintfW(_szBuffer, L"------------------%s ����� δ����", strKeHuName.c_str());
				  THROW_ERROR(_szBuffer);
			  }
			  tie_biao_fei = _wtof(szResult);
			  wsprintfW(szBuffer, L"%s_���ż���", strKeHuName.c_str());
			  mei_tuan_jia_shou = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_װж�ػ�", strKeHuName.c_str());
			  zhuang_xie_zhong_huo = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
			  wsprintfW(szBuffer, L"%s_װж�ݻ�", strKeHuName.c_str());
			  zhuang_xie_pao_huo = GetPrivateProfileInt(L"Price", szBuffer, 0, PRICE_FILE);
		}
		break;
	default:
		{
			wchar_t _szBuffer[128] = { 0 };
			wsprintfW(_szBuffer, L"------------------%s δ֪�շ�ģʽ=%d", strKeHuName.c_str(), shou_fei_mo_shi);
			THROW_ERROR(_szBuffer);
		}
		break;
	}
	return true;
}

bool CSheQuTuanGouDlg::_____MakeZhuangXieFei(BasicExcel& excel)
{
	int nRecordRowIndex = 0;
	BasicExcelWorksheet* _sheet = excel.GetWorksheet(L"װж����");
	_sheet->Cell(nRecordRowIndex, 0)->SetWString(L"ʱ��");
	_sheet->Cell(nRecordRowIndex, 1)->SetWString(L"����");
	_sheet->Cell(nRecordRowIndex, 2)->SetWString(L"��Ʒ��ϸ");
	_sheet->Cell(nRecordRowIndex, 3)->SetWString(L"����(kg)");
	_sheet->Cell(nRecordRowIndex, 4)->SetWString(L"���(m3)");
	_sheet->Cell(nRecordRowIndex, 5)->SetWString(L"װж��");
	nRecordRowIndex++;
	for(int i = 0; i<(int)m_vecRuKuInfo.size(); ++i)
	{
		if(m_vecRuKuInfo[i].size() > 0)
		{
			list<sRuKuBaseInfo>::iterator itB = m_vecRuKuInfo[i].begin();
			list<sRuKuBaseInfo>::iterator itE = m_vecRuKuInfo[i].end();
			while(itB != itE)
			{
				if(itB->lei_xing == L"�ͻ�����")
				{
					wchar_t _szBuffer[128] = { 0 };
					wsprintfW(_szBuffer, L"%d��%d��", m_nMonth, itB->day);
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
					_sheet->Cell(nRecordRowIndex, 1)->SetWString(L"�Ʋֵ���");
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
							wsprintfW(_szBuffer, L"------------------δ������շѷ�ʽ-װж ����=%d", shou_fei_mo_shi);
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
				if(itB->lei_xing == L"�ͻ�����")
				{
					wchar_t _szBuffer[128] = { 0 };
					wsprintfW(_szBuffer, L"%d��%d��", m_nMonth, itB->day);
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
					_sheet->Cell(nRecordRowIndex, 1)->SetWString(L"�Ʋֵ���");
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
							 wsprintfW(_szBuffer, L"------------------δ������շѷ�ʽ-װж ����=%d", shou_fei_mo_shi);
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
	he_ji = L"=SUM(װж����!F:F)+SUM(�ͻ�����!I:I)+SUM(�˻�����!G:G)+SUM(�ִ�����!C:C)+SUM(��ֵ����!C:C)";
	BasicExcel excel;
	excel.AddWorksheet(L"װж����");
	excel.AddWorksheet(L"�ͻ�����");
	excel.AddWorksheet(L"�˻�����");
	excel.AddWorksheet(L"��ֵ����");
	excel.AddWorksheet(L"�ִ�����");
	excel.AddWorksheet(L"�ϼ�");

	wchar_t _szBuffer[512] = { 0 };
	wsprintfW(_szBuffer, L"%s/%s_%d���˵�.xls", EXPORT_PATH, strKeHuName.c_str(), m_nMonth);
	::DeleteFileW(_szBuffer);
	_____MakeZhuangXieFei(excel);
	_____MakeSongHuoFei(excel);
	_____MakeTuiHuoFei(excel);
	_____MakeCangChuFei(excel);
	_____MakeZengZhiFei(excel);
	
	BasicExcelWorksheet* _sheet = excel.GetWorksheet(L"�ϼ�");
	_sheet->Cell(0,0)->SetWString(he_ji.c_str());
	string _file = CFuncCommon::WString2String(_szBuffer);
	excel.SaveAs(_file.c_str());

	return true;
}

bool CSheQuTuanGouDlg::_____MakeZengZhiFei(BasicExcel& excel)
{
	int nRecordRowIndex = 0;
	BasicExcelWorksheet* _sheet = excel.GetWorksheet(L"��ֵ����");
	_sheet->Cell(nRecordRowIndex, 0)->SetWString(L"����");
	_sheet->Cell(nRecordRowIndex, 1)->SetWString(L"����");
	_sheet->Cell(nRecordRowIndex, 2)->SetWString(L"����");
	nRecordRowIndex++;
	list<sZengZhiInfo>::iterator itB = m_listZengZhi.begin();
	list<sZengZhiInfo>::iterator itE = m_listZengZhi.end();
	while(itB != itE)
	{
		wchar_t _szBuffer[512] = { 0 };
		wsprintfW(_szBuffer, L"%d��%d��", m_nMonth, itB->day);
		_sheet->Cell(nRecordRowIndex, 0)->SetWString(_szBuffer);
		memset(_szBuffer, 0, sizeof(_szBuffer));
		bool first = true;
		double fy = 0;
		if(itB->da_ka_ci_shu > 0)
		{
			if(!first)
				StrCatW(_szBuffer, L"\t\n");
			wsprintfW(_szBuffer, L"%s����%d��", _szBuffer, itB->da_ka_ci_shu);
			first = false;
			fy += 20;

		}
		if(itB->dai_ru_ku_ci_shu > 0)
		{
			if(!first)
				StrCatW(_szBuffer, L"\t\n");
			wsprintfW(_szBuffer, L"%s�����%d��sku", _szBuffer, itB->dai_ru_ku_ci_shu);
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
			wsprintfW(_szBuffer, L"%s����%d��", _szBuffer, itB->tie_biao_shu);
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
	BasicExcelWorksheet* _sheet = excel.GetWorksheet(L"�ִ�����");
	_sheet->Cell(nRecordRowIndex, 0)->SetWString(L"����");
	_sheet->Cell(nRecordRowIndex, 1)->SetWString(L"����");
	_sheet->Cell(nRecordRowIndex, 2)->SetWString(L"����");
	nRecordRowIndex++;
	//�Ȱѳ��������µ����ݻ���
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
			wsprintfW(_szBuffer, L"%d��%d��", m_nMonth, i);
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
	BasicExcelWorksheet* _sheet = excel.GetWorksheet(L"�˻�����");
	_sheet->Cell(nRecordRowIndex, 0)->SetWString(L"ʱ��");
	_sheet->Cell(nRecordRowIndex, 1)->SetWString(L"ƽ̨");
	_sheet->Cell(nRecordRowIndex, 2)->SetWString(L"��Ʒ��ϸ");
	_sheet->Cell(nRecordRowIndex, 3)->SetWString(L"����(kg)");
	_sheet->Cell(nRecordRowIndex, 4)->SetWString(L"���(m3)");
	_sheet->Cell(nRecordRowIndex, 5)->SetWString(L"����");
	_sheet->Cell(nRecordRowIndex, 6)->SetWString(L"����");
	nRecordRowIndex++;
	for(int i = 0; i<(int)m_vecRuKuInfo.size(); ++i)
	{
		if(m_vecRuKuInfo[i].size() > 0)
		{
			list<sRuKuBaseInfo>::iterator itB = m_vecRuKuInfo[i].begin();
			list<sRuKuBaseInfo>::iterator itE = m_vecRuKuInfo[i].end();
			while(itB != itE)
			{
				if(itB->lei_xing == L"����˻�" || itB->lei_xing == L"�����˻�")
				{
					wchar_t _szBuffer[128] = { 0 };
					wsprintfW(_szBuffer, L"%d��%d��", m_nMonth, itB->day);
					_sheet->Cell(nRecordRowIndex, 0)->SetWString(_szBuffer);
					list<sRuKuDetailInfo>::iterator _itB = itB->detail_info.begin();
					list<sRuKuDetailInfo>::iterator _itE = itB->detail_info.end();
					wchar_t _szGoodsInfo[512] = { 0 };
					double zl = 0;//����
					double tj = 0;//���
					double bs = 0;//����
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
					if(itB->lei_xing == L"����˻�")
						_sheet->Cell(nRecordRowIndex, 1)->SetWString(L"������");
					if(itB->lei_xing == L"�����˻�")
						_sheet->Cell(nRecordRowIndex, 1)->SetWString(L"������ѡ");
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
							wsprintfW(_szBuffer, L"------------------δ������շѷ�ʽ-�˻� ����=%d", shou_fei_mo_shi);
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
		_sheet->Cell(nRecordRowIndex, 5)->SetWString(L"����");
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
	BasicExcelWorksheet* _sheet = excel.GetWorksheet(L"�ͻ�����");
	_sheet->Cell(nRecordRowIndex, 0)->SetWString(L"ʱ��");
	_sheet->Cell(nRecordRowIndex, 1)->SetWString(L"ƽ̨");
	_sheet->Cell(nRecordRowIndex, 2)->SetWString(L"��Ʒ��ϸ");
	_sheet->Cell(nRecordRowIndex, 3)->SetWString(L"����(kg)");
	_sheet->Cell(nRecordRowIndex, 4)->SetWString(L"���(m3)");
	_sheet->Cell(nRecordRowIndex, 5)->SetWString(L"����");
	_sheet->Cell(nRecordRowIndex, 6)->SetWString(L"������");
	_sheet->Cell(nRecordRowIndex, 7)->SetWString(L"��ע");
	_sheet->Cell(nRecordRowIndex, 8)->SetWString(L"����");
	nRecordRowIndex++;
	for(int i = 0; i<(int)m_vecChuKuInfo.size(); ++i)
	{
		if(m_vecChuKuInfo[i].size() > 0)
		{
			list<sChuKuBaseInfo>::iterator itB = m_vecChuKuInfo[i].begin();
			list<sChuKuBaseInfo>::iterator itE = m_vecChuKuInfo[i].end();
			while(itB != itE)
			{
				if(itB->lei_xing == L"����ͻ�" || itB->lei_xing == L"�����ͻ�" || itB->lei_xing == L"�����ͻ�")
				{
					wchar_t _szBuffer[128] = { 0 };
					wsprintfW(_szBuffer, L"%d��%d��", m_nMonth, itB->day);
					_sheet->Cell(nRecordRowIndex, 0)->SetWString(_szBuffer);
					list<sChuKuDetailInfo>::iterator _itB = itB->detail_info.begin();
					list<sChuKuDetailInfo>::iterator _itE = itB->detail_info.end();
					wchar_t _szGoodsInfo[512] = { 0 };
					double zl = 0;//����
					double tj = 0;//���
					double bs = 0;//����
					int tbs = 0;//������
					bool bh = false;//����
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
							if(beizhus[i] == L"����" || beizhus[i] == L"ҹ�䲹��")
							{
								bh = true;
							}
							else if(beizhus[i].find(L"��") != wstring::npos)
							{
								wstring szBS = beizhus[i].substr(0, beizhus[i].find(L"��"));
								double _bs = _wtof(szBS.c_str());
								bs = max(_bs, bs);
							}
						}
					}
					if(itB->lei_xing == L"����ͻ�")
						_sheet->Cell(nRecordRowIndex, 1)->SetWString(L"������");
					if(itB->lei_xing == L"�����ͻ�")
						_sheet->Cell(nRecordRowIndex, 1)->SetWString(L"������ѡ");
					if(itB->lei_xing == L"�����ͻ�")
						_sheet->Cell(nRecordRowIndex, 1)->SetWString(L"������ѡ");
					_sheet->Cell(nRecordRowIndex, 2)->SetWString(_szGoodsInfo);
					_sheet->Cell(nRecordRowIndex, 3)->SetDouble(zl);
					_sheet->Cell(nRecordRowIndex, 4)->SetDouble(tj);
					_sheet->Cell(nRecordRowIndex, 6)->SetInteger(tbs);
					if(bh)
						_sheet->Cell(nRecordRowIndex, 7)->SetWString(L"����");
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
							if(itB->lei_xing == L"�����ͻ�" || itB->lei_xing == L"�����ͻ�")
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
							if(itB->lei_xing == L"�����ͻ�" || itB->lei_xing == L"�����ͻ�")
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
							  if(itB->lei_xing == L"�����ͻ�" || itB->lei_xing == L"�����ͻ�")
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
							  if(itB->lei_xing == L"�����ͻ�" || itB->lei_xing == L"�����ͻ�")
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
							  if(itB->lei_xing == L"�����ͻ�" || itB->lei_xing == L"�����ͻ�")
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
							wsprintfW(_szBuffer, L"------------------δ������շѷ�ʽ-�ͻ� ����=%d", shou_fei_mo_shi);
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
		_0 = 0,	//��Ʒ��
		_1,		//���
		_2,		//��С��λ
		_3,		//���(��С��λ)
		_4,		//���(����)
		_5,		//�����ͷ(��С��λ)
		_6,		//������λ
		_7,		//������λ
		_8,		//����/��С��λ
		_9,		//���/��С��λ
		_10,	//������׼
		_M,
	};
	BasicExcelWorksheet* _sheet = dataExcel.GetWorksheet(L"���");
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


			if(strTitle == L"��Ʒ��")
				nIndex[_0] = c;
			else if(strTitle == L"���")
				nIndex[_1] = c;
			else if(strTitle == L"��С��λ")
				nIndex[_2] = c;
			else if(strTitle == L"���(��С��λ)")
				nIndex[_3] = c;
			else if(strTitle == L"���(����)")
				nIndex[_4] = c;
			else if(strTitle == L"�����ͷ(��С��λ)")
				nIndex[_5] = c;
			else if(strTitle == L"������λ" || strTitle == L"��������(kg)")
				nIndex[_6] = c;
			else if(strTitle == L"������λ" || (strTitle.find(L"�������(") != wstring::npos))
				nIndex[_7] = c;
			else if(strTitle == L"����/��С��λ")
				nIndex[_8] = c;
			else if(strTitle == L"���/��С��λ")
				nIndex[_9] = c;
			else if(strTitle == L"������׼" || strTitle == L"������׼(����)")
				nIndex[_10] = c;
		}
		for(int i = 0; i < _M; ++i)
		{
			if(nIndex[i] == -1)
			{
				THROW_ERROR(L"------------------����б���δ�ҵ�");
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
					wstring info = L"------------------[" + _data.chan_pin_ming + L"]" + L" ȱ���������������";
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
		THROW_ERROR(L"------------------û���ҵ�����ҳ");
	}
	return true;
}

bool CSheQuTuanGouDlg::LoadRuKu(BasicExcel& dataExcel)
{
	const wchar_t* _pStr = NULL;

	enum eT
	{
		_0 = 0,	//����
		_1,		//�������
		_2,		//��Ʒ����
		_3,		//�������
		_4,		//����
		_5,		//���
		_6,		//��ע
		_7,		//��ⵥλ
		_M,
	};
	BasicExcelWorksheet* _sheet = dataExcel.GetWorksheet(L"���");
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

			if(strTitle == L"����")
				nIndex[_0] = c;
			else if(strTitle == L"�������")
				nIndex[_1] = c;
			else if(strTitle == L"��Ʒ����")
				nIndex[_2] = c;
			else if(strTitle == L"�������")
				nIndex[_3] = c;
			else if(strTitle == L"����" || strTitle == L"�������(kg)")
				nIndex[_4] = c;
			else if(strTitle == L"���" || (strTitle.find(L"������(") != wstring::npos))
				nIndex[_5] = c;
			else if(strTitle == L"��ע")
				nIndex[_6] = c;
			else if(strTitle == L"��ⵥλ")
				nIndex[_7] = c;
		}
		for(int i = 0; i < _M; ++i)
		{
			if(nIndex[i] == -1)
			{
				THROW_ERROR(L"------------------����б���δ�ҵ�");
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
					if(lei_xing == L"����˻�" || lei_xing == L"�����˻�")
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
				if(pCurBaseInfo->lei_xing == L"����˻�" || pCurBaseInfo->lei_xing == L"�����˻�")
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
		THROW_ERROR(L"------------------û���ҵ�����ҳ");
	}
	return true;
}

bool CSheQuTuanGouDlg::LoadChuKu(BasicExcel& dataExcel)
{
	const wchar_t* _pStr = NULL;
	enum eT
	{
		_0 = 0,	//����
		_1,		//��������
		_2,		//��Ʒ����
		_3,		//��������
		_4,		//��������
		_5,		//���ⷽ��
		_6,		//������
		_7,		//��ע
		_8,		//���ⵥλ
		_M,
	};
	BasicExcelWorksheet* _sheet = dataExcel.GetWorksheet(L"����");
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


			if(strTitle == L"����")
				nIndex[_0] = c;
			else if(strTitle == L"��������")
				nIndex[_1] = c;
			else if(strTitle == L"��Ʒ����")
				nIndex[_2] = c;
			else if(strTitle == L"��������")
				nIndex[_3] = c;
			else if(strTitle == L"��������" || strTitle == L"��������(kg)")
				nIndex[_4] = c;
			else if(strTitle == L"���ⷽ��" || (strTitle.find(L"�������(") != wstring::npos))
				nIndex[_5] = c;
			else if(strTitle == L"������")
				nIndex[_6] = c;
			else if(strTitle == L"��ע")
				nIndex[_7] = c;
			else if(strTitle == L"���ⵥλ")
				nIndex[_8] = c;
		}
		for(int i = 0; i < _M; ++i)
		{
			if(nIndex[i] == -1)
			{
				THROW_ERROR(L"------------------�����б���δ�ҵ�");
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
		THROW_ERROR(L"------------------û���ҵ������ҳ");
	}
	return true;
}

bool CSheQuTuanGouDlg::LoadZengZhi(BasicExcel& dataExcel)
{
	enum eT
	{
		_0 = 0,	//����
		_1,		//����
		_2,		//���򿨴���
		_3,		//������SKU��
		_4,		//������
		_M,
	};
	const wchar_t* _pStr = NULL;
	BasicExcelWorksheet* _sheet = dataExcel.GetWorksheet(L"��ֵ����");
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

			if(strTitle == L"����")
				nIndex[_0] = c;
			else if(strTitle == L"����")
				nIndex[_1] = c;
			else if(strTitle == L"���򿨴���")
				nIndex[_2] = c;
			else if(strTitle == L"������SKU��")
				nIndex[_3] = c;
			else if(strTitle == L"������")
				nIndex[_4] = c;
		}
		for(int i = 0; i < _M; ++i)
		{
			if(nIndex[i] == -1)
			{
				THROW_ERROR(L"------------------��ֵ�����б���δ�ҵ�");
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
		THROW_ERROR(L"------------------û���ҵ���ֵ�����ҳ");
	}
	return true;
}

void CSheQuTuanGouDlg::OnBnClickedButtonMakeAllZD()
{
	if(m_bRun)
	{
		MessageBox(L"���������˵�,��Ҫ�ظ����");
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
