
// StorageBillDlg.h : 头文件
//

#pragma once
#include "typedefine.h"
#include "afxwin.h"
#include "thread_safe_queue.h"
#include "BasicExcel.hpp"
using namespace YCompoundFiles;
using namespace YExcel;
// CStorageBillDlg 对话框
class CStorageBillDlg : public CDialogEx
{
// 构造
public:
	CStorageBillDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_STORAGEBILL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


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
	afx_msg void OnBnClickedCreateBill();
private:
	void _LogicThread();
	bool ParseALLData();
	bool CreateHuoZhuFile();
	bool Handle_MoHeKeJi();
	bool Handle_YongChuangYaoHui();
	bool Handle_MiYaShiQi();
	bool LoadSFData();
	bool CompareWithSFData(std::wstring strHuoZhu, std::list<sSalesInfo>& listInfo);
	bool CreateExcel(BasicExcel& excel, std::list<sSalesInfo>& listSalesInfo, std::map<std::wstring, sInStorageInfo>& mapInStorageInfo);
	void AddLog(std::wstring strLog);
	void SetHScroll();
private:
	boost::thread m_logicThread;
	bool m_bExit;
	bool m_bRun;
	thread_safe_queue<std::wstring> m_queueLog;
	std::map< std::wstring, std::list<sSalesInfo> > m_mapAllSalesInfo;
	std::map< std::wstring, sSalesInfo* > m_mapTempSalesInfo;
	std::map<std::wstring, sSFAuthData> m_mapSFAuthData;
	std::map< std::wstring, std::set<std::wstring> > m_mapYCNeedSFHandle;
	std::map< std::wstring, std::map<std::wstring, sInStorageInfo> > m_mapInStorageInfo;
	BasicExcel m_sfExcel;
	BasicExcel m_recordExcel;
	size_t m_sfHandleCol;
	std::wstring m_strYM;
public:
	CListBox m_ctrlListLog;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CEdit m_editYM;
};
