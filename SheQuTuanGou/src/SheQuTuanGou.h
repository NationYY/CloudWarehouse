
// �����Ź��˵�����.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CSheQuTuanGouApp: 
// �йش����ʵ�֣������ �����Ź��˵�����.cpp
//

class CSheQuTuanGouApp : public CWinApp
{
public:
	CSheQuTuanGouApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CSheQuTuanGouApp theApp;