
// StorageBillDlg.cpp : ʵ���ļ�
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
#define TOTAL_FILE_PATH L"./ϵͳ����/"+m_strYM+L"/���۳��ⵥ.xls"
#define DETAIL_FILE_PATH L"./ϵͳ����/"+m_strYM+L"/���۳�����ϸ.xls"
#define SF_FILE_PATH L"./ϵͳ����/"+m_strYM+L"/˳���˵�.xls"
#define IN_STORAGE_PATH L"./ϵͳ����/"+m_strYM+L"/�����ϸ��.xls"


const wchar_t* g_arrWorksheetName[] ={L"˳���������충��", L"˳���Ʋ�δ������", L"˳��۸��쳣"};
int g_arrRecordRowIndex[] ={0, 0, 0};
const wchar_t* g_arrHuoZhuName[] ={L"ħ�ϿƼ�N", L"����ҫ��", L"����ʳ��"};


//ħ�ϿƼ�˳��۸�
double g_moHeKeJiSFPrice[4][2] ={{13, 3.5}, {15, 5}, {19, 5}, {27, 8}};
//����ҫ��˳��۸�
double g_yongChuangYaoHuiSFPrice[4][2] ={{11, 2.6}, {12, 4.5}, {16, 4.5}, {22, 7}};

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg: public CDialogEx
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

CAboutDlg::CAboutDlg(): CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CStorageBillDlg �Ի���



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
	ON_LBN_DBLCLK(IDC_LIST3, &CStorageBillDlg::OnLbnDblclkLogList)
END_MESSAGE_MAP()


// CStorageBillDlg ��Ϣ�������

BOOL CStorageBillDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
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

		
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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
			AddLog(L"�˵��������");
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CStorageBillDlg::OnPaint()
{
	if(IsIconic())
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
		MessageBox(L"δ��д�˵�����");
		return;
	}
	m_bRun = true;
	m_strYM = strYM.GetBuffer();
	AddLog(L"��ʼ�����˵���Ϣ");
}

void CStorageBillDlg::AddLog(std::wstring strLog)
{
	m_queueLog.push(strLog);
}

void CStorageBillDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	wstring strLog;
	if(m_queueLog.pop(strLog))
	{
		m_ctrlListLog.InsertString(0, strLog.c_str());
		SetHScroll();
		if(strLog == L"�˵��������")
			MessageBox(L"�˵��������");
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
		for(size_t c = 0; c < maxCols; ++c)
		{
			BasicExcelCell* cell = totalSheet->Cell(0, c);
			std::wstring strTitle = cell->GetWString();
			if(strTitle == L"����")
				nHuoZhu = c;
			else if(strTitle == L"�ռ���")
				nShouJianRen = c;
			else if(strTitle == L"������˾")
				nWuLiuGongSi = c;
			else if(strTitle == L"��������")
				nWuLiuDanHao = c;
			else if(strTitle == L"�ռ��˵�ַ")
				nShouJianRenDiZhi = c;
			else if(strTitle == L"ʵ������")
				nZhongLiang = c;
			else if(strTitle == L"����ʱ��")
				nFaHuoShijian = c;
			else if(strTitle == L"ԭʼ����")
				nYuanShiDanHao = c;
		}
		if(nHuoZhu == -1 || nShouJianRen == -1 || nWuLiuGongSi == -1 || nWuLiuDanHao == -1 || nShouJianRenDiZhi == -1 || nZhongLiang == -1 || nFaHuoShijian == -1 || nYuanShiDanHao == -1)
		{
			THROW_ERROR(L"���۳��ⵥ �б���δ�ҵ�");
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
			SHEET_CELL(totalSheet, r, nYuanShiDanHao, _data.strYuanShiDanHao);
			double dTemp = totalSheet->Cell(r, nZhongLiang)->GetDouble();
			if(dTemp > 0.001)
				dTemp += 0.05;
			if(_data.strWuLiuGongSi == L"˳������")
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
		int nShengShiQu = -1;
		for(size_t c = 0; c < maxCols; ++c)
		{
			BasicExcelCell* cell = detailSheet->Cell(0, c);
			std::wstring strTitle = cell->GetWString();
			if(strTitle == L"��Ʒ����")
				nHuoPinMingCheng = c;
			else if(strTitle == L"��Ʒ������")
				nHuoPinZongShuLiang = c;
			else if(strTitle == L"��Ʒ����")
				nHuoPinShuLiang = c;
			else if(strTitle == L"�������")
				nWuLiuDanHao = c;
			else if(strTitle == L"ʡ")
				nSheng = c;
			else if(strTitle == L"ʡ����")
				nShengShiQu = c;
			
		}
		if(nHuoPinMingCheng == -1 || nHuoPinZongShuLiang == -1 || nHuoPinShuLiang == -1 || nWuLiuDanHao == -1 || nSheng == -1 || nShengShiQu == -1)
		{
			THROW_ERROR(L"���۳�����ϸ �б���δ�ҵ�");
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
				wsprintfW(szBuffer, L"���۳�����ϸ δ�ҵ�����%s", strWuLiuDanHao.c_str());
				THROW_ERROR(szBuffer);
			}
			double dZSL = detailSheet->Cell(r, nHuoPinZongShuLiang)->GetDouble();
			it->second->strHuoPinZongShuLiang = CFuncCommon::Double2WString(dZSL+DOUBLE_PRECISION, 0);
			SHEET_CELL(detailSheet, r, nSheng, it->second->strSheng);
			if(it->second->strSheng == L"")
			{
				wstring strShengShiQu = L"";
				SHEET_CELL(detailSheet, r, nShengShiQu, strShengShiQu);
				if(strShengShiQu.find(L"������ʡ") != wstring::npos)
				{
					it->second->strSheng = L"����׳��������";		
				}
				else if(strShengShiQu.find(L"������ʡ") != wstring::npos)
				{
					it->second->strSheng = L"���Ļ���������";		
				}
				else
				{
					wchar_t szBuffer[128] = { 0 };
					wsprintfW(szBuffer, L"���۳�����ϸ δʶ��ʡ���� %s", strShengShiQu.c_str());
					THROW_ERROR(szBuffer);
				}
			}
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
		THROW_ERROR(L"�����ϸ�� ����ʧ��");
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
			if(strTitle == L"����")
				nHuoZhu = c;
			else if(strTitle == L"���ԭ��")
				nRuKuYuanYin = c;
			else if(strTitle == L"�̼ұ���")
				nShangJiaBianMa = c;
			else if(strTitle == L"��Ʒ���")
				nHuoPingBianMa = c;
			else if(strTitle == L"��Ʒ����")
				nHuoPinMingCheng = c;
			else if(strTitle == L"����")
				nShuLiang = c;
		}
		if(nHuoZhu == -1 || nRuKuYuanYin == -1 || nShangJiaBianMa == -1 || nHuoPingBianMa == -1 || nHuoPinMingCheng == -1 || nShuLiang == -1)
		{
			THROW_ERROR(L"�����ϸ�� �б���δ�ҵ�");
		}
		for(size_t r = 1; r < maxRows; ++r)
		{
			sInStorageInfo info;
			const wchar_t* _pStr = NULL;
			SHEET_CELL(inStorageSheet, r, nHuoZhu, info.strHuoZhu);
			std::wstring strRuKuYuanYin;
			SHEET_CELL(inStorageSheet, r, nRuKuYuanYin, strRuKuYuanYin);
			if(strRuKuYuanYin != L"�������" && strRuKuYuanYin != L"�ɹ����")
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
		wstring fileName = folderPath + L"/" + g_arrHuoZhuName[i] + L"_" + m_strYM + L"���˵�.xls";
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
		if(i == nHuoZhuCnt && itB->first != L"��������")
		{
			CString szText;
			szText.Format(L"����δ����Ļ���:%s �Ƿ����?", itB->first.c_str());
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
		recordSheet->Cell(g_arrRecordRowIndex[0], 0)->SetWString(L"����");
		recordSheet->Cell(g_arrRecordRowIndex[0], 1)->SetWString(L"˳������");
		recordSheet->Cell(g_arrRecordRowIndex[0], 2)->SetWString(L"�Ʋ�����");
		recordSheet->Cell(g_arrRecordRowIndex[0], 3)->SetWString(L"�ƲּƷ�����");
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
		sheet->Cell(0, 0)->SetWString(L"�ռ���");
		sheet->Cell(0, 1)->SetWString(L"�ռ��˵�ַ");
		sheet->Cell(0, 2)->SetWString(L"ʡ");
		sheet->Cell(0, 3)->SetWString(L"������˾");
		sheet->Cell(0, 4)->SetWString(L"��������");
		sheet->Cell(0, 5)->SetWString(L"ԭʼ����");
		sheet->Cell(0, 6)->SetWString(L"����");
		sheet->Cell(0, 7)->SetWString(L"����ʱ��");
		sheet->Cell(0, 8)->SetWString(L"��Ʒ������");
		sheet->Cell(0, 9)->SetWString(L"��Ʒ��ϸ");
		sheet->Cell(0, 10)->SetWString(L"�Ʒ�����");
		sheet->Cell(0, 11)->SetWString(L"������");
		sheet->Cell(0, 12)->SetWString(L"�Ĳķ�");
		sheet->Cell(0, 13)->SetWString(L"������");
		sheet->Cell(0, 14)->SetWString(L"��ֵ����");
		sheet->Cell(0, 15)->SetWString(L"��ע");
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
			sheet->Cell(nRecordRowIndex, 5)->SetWString(itB->strYuanShiDanHao.c_str());
			sheet->Cell(nRecordRowIndex, 6)->SetWString(itB->strZhongLiang.c_str());
			sheet->Cell(nRecordRowIndex, 7)->SetWString(itB->strFaHuoShijian.c_str());
			sheet->Cell(nRecordRowIndex, 8)->SetWString(itB->strHuoPinZongShuLiang.c_str());
			sheet->Cell(nRecordRowIndex, 9)->SetWString(itB->strHuoPinMingXi.c_str());
			//������
			sheet->Cell(nRecordRowIndex, 10)->SetWString(L"0");
			sheet->Cell(nRecordRowIndex, 11)->SetWString(L"0");
			sheet->Cell(nRecordRowIndex, 12)->SetWString(L"0");
			sheet->Cell(nRecordRowIndex, 13)->SetWString(L"0");
			sheet->Cell(nRecordRowIndex, 14)->SetWString(L"0");
			nRecordRowIndex++;
			itB++;
		}
	}
	nRecordRowIndex = 1;
	sheet = excel.GetWorksheet("Sheet2");
	if(sheet)
	{
		sheet->Cell(0, 0)->SetWString(L"�̼ұ���");
		sheet->Cell(0, 1)->SetWString(L"��Ʒ���");
		sheet->Cell(0, 2)->SetWString(L"��Ʒ����");
		sheet->Cell(0, 3)->SetWString(L"�������");
		sheet->Cell(0, 4)->SetWString(L"������");

		std::map<std::wstring, sInStorageInfo>::iterator itB = mapInStorageInfo.begin();
		std::map<std::wstring, sInStorageInfo>::iterator itE = mapInStorageInfo.end();
		while(itB != itE)
		{
			itB->second.nRow = nRecordRowIndex;
			sheet->Cell(nRecordRowIndex, 0)->SetWString(itB->second.strShangJiaBianMa.c_str());
			sheet->Cell(nRecordRowIndex, 1)->SetWString(itB->second.strHuoPinBianMa.c_str());
			sheet->Cell(nRecordRowIndex, 2)->SetWString(itB->second.strHuoPinMingCheng.c_str());
			sheet->Cell(nRecordRowIndex, 3)->SetInteger(itB->second.nCnt);
			//������
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
	if(!CreateExcel(excel, m_mapAllSalesInfo[L"ħ�ϿƼ�N"], m_mapInStorageInfo[L"ħ�ϿƼ�N"]))
		return false;
	wstring fileName = L"./Export_" + m_strYM + L"/" + L"ħ�ϿƼ�N_" + m_strYM + L"���˵�.xls";
	string _file = CFuncCommon::WString2String(fileName.c_str());
	CompareWithSFData(L"ħ�ϿƼ�N", m_mapAllSalesInfo[L"ħ�ϿƼ�N"]);
	//������ط���
	//����TH-043�͵���TH-042���𵥼۸�
	{
		BasicExcelWorksheet* sheet = excel.GetWorksheet("Sheet1");
		if(sheet)
		{
			std::list<sSalesInfo>& listSales = m_mapAllSalesInfo[L"ħ�ϿƼ�N"];
			std::list<sSalesInfo>::iterator itB = listSales.begin();
			std::list<sSalesInfo>::iterator itE = listSales.end();
			while(itB != itE)
			{
				//sheet->Cell(0, 10)->SetWString(L"�Ʒ�����");
				//sheet->Cell(0, 11)->SetWString(L"�����");
				//sheet->Cell(0, 12)->SetWString(L"�Ĳķ�");
				//sheet->Cell(0, 13)->SetWString(L"������");
				//sheet->Cell(0, 14)->SetWString(L"��ֵ����");
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
	if(!CreateExcel(excel, m_mapAllSalesInfo[L"����ҫ��"], m_mapInStorageInfo[L"����ҫ��N"]))
		return false;
	wstring fileName = L"./Export_" + m_strYM + L"/" + L"����ҫ��_" + m_strYM + L"���˵�.xls";
	string _file = CFuncCommon::WString2String(fileName.c_str());
	CompareWithSFData(L"����ҫ��", m_mapAllSalesInfo[L"����ҫ��"]);

	//������ط���
	{
		BasicExcelWorksheet* sheet = excel.GetWorksheet("Sheet1");
		if(sheet)
		{
			std::list<sSalesInfo>& listSales = m_mapAllSalesInfo[L"����ҫ��"];
			std::list<sSalesInfo>::iterator itB = listSales.begin();
			std::list<sSalesInfo>::iterator itE = listSales.end();
			while(itB != itE)
			{
				//sheet->Cell(0, 11)->SetWString(L"������");
				//sheet->Cell(0, 12)->SetWString(L"�Ĳķ�");
				//sheet->Cell(0, 13)->SetWString(L"������");
				//sheet->Cell(0, 14)->SetWString(L"��ֵ����");
				//sheet->Cell(0, 15)->SetWString(L"��ע");
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
					sheet->Cell(itB->nRow, 10)->SetWString(szWeight);
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
					sheet->Cell(itB->nRow, 10)->SetWString(szWeight);
				}
				//����������
				{
					if(itB->strWuLiuGongSi == L"˳������")
					{
						double money = GetSFPrice(nWeight, itB->strSheng, g_yongChuangYaoHuiSFPrice);
						std::map<std::wstring, sSFAuthData>::iterator itSF = m_mapSFAuthData.find(itB->strWuLiuDanHao);
						if(itSF != m_mapSFAuthData.end())
						{
							if(itSF->second.backPay != L"")
							{
								double backPay = _wtof(itSF->second.backPay.c_str());
								money += backPay;
								strBeiZhu = strBeiZhu + L"ת���˻�";
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
						sheet->Cell(itB->nRow, 11)->SetWString(CFuncCommon::Double2WString(money+DOUBLE_PRECISION, 1).c_str());


					}
					else if(itB->strWuLiuGongSi == L"��������")
						sheet->Cell(itB->nRow, 11)->SetWString(L"3.5");
					else if(itB->strWuLiuGongSi == L"��������(�ֲ�)")
					{

					}
					else
					{
						wchar_t szOut[120] ={0};
						_swprintf(szOut, L"[δ֪��������ʽ] ����=%s ����=%s ������˾=%s", itB->strHuoZhu.c_str(), itB->strWuLiuDanHao.c_str(), itB->strWuLiuGongSi.c_str());
						AddLog(szOut);
					}
				}
				sheet->Cell(itB->nRow, 13)->SetWString(L"1.1");
				//������ֵ����
				{
					//�Ƽ������
					if(itB->strYuanShiDanHao.size() >= 2)
					{
						wchar_t char1 = itB->strYuanShiDanHao.at(0);
						wchar_t char2 = itB->strYuanShiDanHao.at(1);
						if(char1 == L'S' && char2 == L'O')
							sheet->Cell(itB->nRow, 14)->SetWString(L"0.3");
					}
				}
				sheet->Cell(itB->nRow, 15)->SetWString(strBeiZhu.c_str());
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
	if(!CreateExcel(excel, m_mapAllSalesInfo[L"����ʳ��"], m_mapInStorageInfo[L"����ʳ��"]))
		return false;
	wstring fileName = L"./Export_" + m_strYM + L"/" + L"����ʳ��_" + m_strYM + L"���˵�.xls";
	string _file = CFuncCommon::WString2String(fileName.c_str());
	excel.SaveAs(_file.c_str());
	CompareWithSFData(L"����ʳ��", m_mapAllSalesInfo[L"����ʳ��"]);
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
		int colNeedPay = -1;
		bool bFix = false;
		for(size_t c = 0; c < maxCols; ++c)
		{
			BasicExcelCell* cell = sfSheet->Cell(0, c);
			std::wstring strTitle = cell->GetWString();
			if(strTitle == L"�˵�����")
				colNumber = c;
			else if(strTitle == L"�Ʒ�����")
				colWeight = c;
			else if(strTitle == L"��ֵ����")
				colVAServices = c;
			else if(strTitle == L"Ӧ�����")
				colNeedPay = c;
			else if(strTitle == L"���˽��")
			{
				bFix = true;
				m_sfHandleCol = c;
			}
		}
		if(!bFix)
			sfSheet->Cell(0, maxCols)->SetWString(L"���˽��");
		for(size_t r = 1; r < maxRows; ++r)
		{
			sSFAuthData _data;
			const wchar_t* _pStr = NULL;
			SHEET_CELL(sfSheet, r, colNumber, _data.number);
			SHEET_CELL(sfSheet, r, colWeight, _data.weight);
			SHEET_CELL(sfSheet, r, colVAServices, _data.vaServices);
			SHEET_CELL(sfSheet, r, colNeedPay, _data.needPay);
			_data.row = r;
			if(_data.vaServices == L"����")
			{
				sfSheet->Cell(r, m_sfHandleCol)->SetWString(L"1");
				continue;
			}
			if(_data.vaServices == L"ת���˻�")
			{
				std::map<std::wstring, sSFAuthData>::iterator it = m_mapSFAuthData.find(_data.number);
				if(it != m_mapSFAuthData.end())
				{
					it->second.backPay = _data.needPay;
				}
				else
				{
					wchar_t szBuffer[128] = { 0 };
					wsprintfW(szBuffer, L"˳��ת���˻� δ�ҵ���Ӧ���� %s", _data.number.c_str());
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
		THROW_ERROR(L"��ȡ˳���˵�ʧ��");
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


double CStorageBillDlg::GetSFPrice(int nWeight, wstring strSheng, double price[][2])
{
	double* _price = NULL;
	if(strSheng == L"�Ĵ�ʡ" || strSheng == L"����")
		_price = price[0];
	else if(strSheng == L"����ʡ" || strSheng == L"����ʡ" || strSheng == L"����ʡ" || strSheng == L"����ʡ")
		_price = price[1];
	else if(strSheng == L"����ʡ" || strSheng == L"����" || strSheng == L"����ʡ" || strSheng == L"����ʡ" || strSheng == L"�㶫ʡ" || strSheng == L"����׳��������" || strSheng == L"����ʡ" || strSheng == L"�ӱ�ʡ" || strSheng == L"����ʡ" || strSheng == L"����ʡ" || strSheng == L"����ʡ" || strSheng == L"����ʡ" || strSheng == L"���Ļ���������" || strSheng == L"�ຣʡ" || strSheng == L"ɽ��ʡ" || strSheng == L"ɽ��ʡ" || strSheng == L"�Ϻ�" || strSheng == L"���" || strSheng == L"�㽭ʡ")
		_price = price[2];
	else if(strSheng == L"������ʡ" || strSheng == L"����ʡ" || strSheng == L"����ʡ" || strSheng == L"���ɹ�������" || strSheng == L"�½�ά���������" || strSheng == L"����������")
		_price = price[3];
	else
	{
		wchar_t szBuffer[128] ={0};
		wsprintfW(szBuffer, L"δ֪ʡ�� %s", strSheng.c_str());
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