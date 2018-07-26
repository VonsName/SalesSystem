#pragma once
#include "afxwin.h"



// CSaleDialog 窗体视图

class CSaleDialog : public CFormView
{
	DECLARE_DYNCREATE(CSaleDialog)

protected:
	CSaleDialog();           // 动态创建所使用的受保护的构造函数
	virtual ~CSaleDialog();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
//	CString productName;
	int price;
	int kucun;
	int num;
	CString sale_info;
public:
	virtual void OnInitialUpdate();
private:
	CComboBox productName;
public:
	afx_msg void OnCbnSelchangeCombo2();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
};


