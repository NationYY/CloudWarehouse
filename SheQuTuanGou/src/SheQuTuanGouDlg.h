
// �����Ź��˵�����Dlg.h : ͷ�ļ�
//

#pragma once
#include "typedefine.h"
#include "afxwin.h"
#include "thread_safe_queue.h"
#include "afxcmn.h"

// CSheQuTuanGouDlg �Ի���
class CSheQuTuanGouDlg : public CDialogEx
{
// ����
public:
	CSheQuTuanGouDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��
	void SetHScroll();
	void _LogicThread();
	void AddLog(std::wstring strLog);
	bool MakeZD(std::wstring strKeHuName);
	bool LoadKuCun(BasicExcel& dataExcel);
	bool LoadRuKu(BasicExcel& dataExcel);
	bool LoadChuKu(BasicExcel& dataExcel);
	bool LoadZengZhi(BasicExcel& dataExcel);
	bool MakeData(std::wstring strKeHuName);
	bool LoadPrice(std::wstring strKeHuName);
	bool _____MakeZhuangXieFei(BasicExcel& excel);
	bool _____MakeSongHuoFei(BasicExcel& excel);
	bool _____MakeTuiHuoFei(BasicExcel& excel);
	bool _____MakeCangChuFei(BasicExcel& excel);
	bool _____MakeZengZhiFei(BasicExcel& excel);
	double GetTuiHuoFei(double bs, int tui_huo_yi_tuo, int tui_huo_ban_tuo);
// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	boost::thread m_logicThread;
	CListBox m_ctrlListLog;
	wofstream m_logFile;
	thread_safe_queue<std::wstring> m_queueLog;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	bool m_bExit;
	bool m_bRun;
	CListBox m_listCtrlAllKeHu;
	std::vector<std::string> m_vecFiles;
	CEdit m_editName;
	afx_msg void OnLbnDblclkListNames();
	CComboBox m_combMonth;
	list<wstring> m_listMakeSJNames;
	afx_msg void OnBnClickedButtonMakeSelZD();
	int m_nRuKuDataCnt;
	int m_nChuKuDataCnt;
	int m_nKunCunCnt;
	double m_dMeiTuanZL;
	int m_nMeiTuanMaxDay;
	wstring m_strCurKeHu;
	map<wstring, sGoodsBaseInfo> m_mapGoodsBaseInfo;
	vector< list<sRuKuBaseInfo> > m_vecRuKuInfo;
	vector< list<sChuKuBaseInfo> > m_vecChuKuInfo;
	list<sZengZhiInfo> m_listZengZhi;
	int m_nMonth;
	double m_dZhuangXieFeiHeJi;
	double m_dSongHuoFeiHeJi;
	double m_dTuiHuoFeiHeJi;
	double m_dCangChuFeiHeJi;
	double m_dZengZhiFeiHeJi;
	map<wstring, int> m_mapAfterRuKu;
	map<wstring, int> m_mapAfterChuKu;
	afx_msg void OnBnClickedButtonMakeAllZD();
	std::set<std::wstring> m_setNoBeiZhu;
	std::set<std::wstring> m_noDataChanPinMing;
};
