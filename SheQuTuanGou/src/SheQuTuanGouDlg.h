
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
};
