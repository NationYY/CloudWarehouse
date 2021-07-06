
// 社团团购账单工具Dlg.h : 头文件
//

#pragma once
#include "typedefine.h"
#include "afxwin.h"
#include "thread_safe_queue.h"
#include "afxcmn.h"

// CSheQuTuanGouDlg 对话框
class CSheQuTuanGouDlg : public CDialogEx
{
// 构造
public:
	CSheQuTuanGouDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
	void SetHScroll();
	void _LogicThread();
	void AddLog(std::wstring strLog);
// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
