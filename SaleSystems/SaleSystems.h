
// SaleSystems.h : SaleSystems Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CSaleSystemsApp:
// �йش����ʵ�֣������ SaleSystems.cpp
//

class CSaleSystemsApp : public CWinApp
{
public:
	CSaleSystemsApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSaleSystemsApp theApp;
