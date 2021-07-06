
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
}

BEGIN_MESSAGE_MAP(CSheQuTuanGouDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
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
	for(int i=0; i<m_vecFiles.size(); ++i)
	{
		if(m_vecFiles[i].at(0) == 'G')
		{
			std::string temp1 = m_vecFiles[i].substr(0, m_vecFiles[i].size()-4);
			std::wstring temp2 = CFuncCommon::String2WString(temp1.c_str());
			m_listCtrlAllKeHu.AddString(temp2.c_str());
		}
	}
	m_logicThread = boost::thread(boost::bind(&CSheQuTuanGouDlg::_LogicThread, this));
	SetTimer(0, 1, NULL);
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
			
		}
	__break_logic:
		m_bRun = false;
		boost::this_thread::sleep(boost::posix_time::milliseconds(10));
	}
}