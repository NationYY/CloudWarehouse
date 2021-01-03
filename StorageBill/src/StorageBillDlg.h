
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
	bool LoadDuoDuoMaiCaiPrice();
	bool ParseDuoDuoMaiCaiALLData();
	bool ParseALLData();
	bool LoadXiaoShouChuKuDan(std::wstring wfileName, bool checkFail);
	bool LoadXiaoShouChuKuMingXi(std::wstring wfileName, bool checkFail);
	bool CreateHuoZhuFile();
	bool Handle_YongChuangYaoHui();
	bool Handle_YongChuangYaoHui_KunLunShan();
	bool Handle_MiYaShiQi();
	bool Handle_TaiFuShangMao();
	bool Handle_YiMaiKeJi();
	bool Handle_XinMaBang();
	bool Handle_QiYiJiangYuan();
	bool Handle_HaTeNengLiang();
	bool Handle_HanTaiLang();
	bool Handle_LaFengQing();
	bool Handle_ZhiShanDianShang();
	bool Handle_DuoDuoMaiCai();
	bool LoadSFData();
	bool LoadBSKDData();
	bool LoadZTKYData();
	bool IsZhengShu(std::wstring number);
	bool IsZero(std::wstring number);
	void FillKDWeight();
	bool CompareWithSFData(std::wstring strHuoZhu, std::list<sSalesInfo>& listInfo, bool bWait=false);
	bool CompareWithBSKDData(std::wstring strHuoZhu, std::list<sSalesInfo>& listInfo);
	bool CompareWithZTKYData(std::wstring strHuoZhu, std::list<sSalesInfo>& listInfo);
	bool CreateExcel(BasicExcel& excel, std::list<sSalesInfo>& listSalesInfo, std::map<std::wstring, sInStorageInfo>& mapInStorageInfo);
	double GetSFPrice(int nWeight, wstring strSheng, std::vector< std::list<sExpressPriceInfo> >& vecPrice, wstring danhao);
	double GetKDPrice(int nWeight, wstring strSheng, std::map< std::wstring, std::list<sExpressPriceInfo> >& mapPrice, wstring strKuDiType, wstring danhao);
	double GetKYPrice(int nWeight, wstring strSheng, wstring strShi, std::map< std::wstring, sLargeExpressPriceInfo >& mapPrice);
	void AddLog(std::wstring strLog);
	void SetHScroll();
	std::wstring GetLastDay(int year, int month);
private:
	boost::thread m_logicThread;
	bool m_bExit;
	bool m_bRun;
	bool m_bSF;
	bool m_bBSKD;
	bool m_bZYKY;
	bool m_bYG;
	bool m_bDuoDuoMaiCai;
	thread_safe_queue<std::wstring> m_queueLog;

	std::map< std::wstring, std::map< std::wstring, std::list<sDuoDuoMaiCaiChuKuInfo> > > m_mapDuoDuoMaiCaiChuKu;
	std::map< std::wstring, std::list<sDuoDuoMaiCaiRuKuInfo> > m_mapDuoDuoMaiCaiRuKu;
	std::map< std::wstring, std::map< std::wstring, std::list<sDuoDuoMaiCaiRuKuInfo> > > m_mapDuoDuoMaiCaiTuiHuo;
	std::map< std::wstring, std::list<sSalesInfo> > m_mapAllSalesInfo;
	std::map< std::wstring, sSalesInfo* > m_mapTempSalesInfo;
	std::map<std::wstring, sSFAuthData> m_mapSFAuthData;
	std::map<std::wstring, sBSKDAuthData> m_mapBSKDAuthData;
	std::map<std::wstring, sZTKYAuthData> m_mapZYKYAuthData;
	std::map< std::wstring, std::set<std::wstring> > m_mapYCNeedSFHandle;
	std::map< std::wstring, std::map<std::wstring, sInStorageInfo> > m_mapInStorageInfo;
	std::map< std::wstring, int > m_mapBaoJiaJinE;
	std::set<std::wstring> m_setSFZhongLiangYiChang;
	std::set<std::wstring> m_setSFOtherType;
	BasicExcel m_sfExcel;
	BasicExcel m_bskdExcel;
	BasicExcel m_ztkyExcel;
	BasicExcel m_recordExcel;
	size_t m_sfHandleCol;
	size_t m_bskdHandleCol;
	size_t m_ztkyHandleCol;
	std::wstring m_strYM;
public:
	CListBox m_ctrlListLog;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CEdit m_editYM;
	afx_msg void OnLbnDblclkLogList();
	CButton m_checkSF;
	CButton m_checkBSKD;
	wofstream m_logFile;
	CButton m_checkYGZD;
	bool m_bSFErrorPrice;
	CButton m_checkZTKY;
	CButton m_checkDuoDuoMaiCai;
};
