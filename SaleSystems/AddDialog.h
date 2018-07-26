#pragma once
#include "afxwin.h"



// CAddDialog 窗体视图

class CAddDialog : public CFormView
{
	DECLARE_DYNCREATE(CAddDialog)

protected:
	CAddDialog();           // 动态创建所使用的受保护的构造函数
	virtual ~CAddDialog();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
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
	CComboBox m_combo;
	int price1;
	int num1;
	CString m_name;
	int price2;
	int num2;
public:
	virtual void OnInitialUpdate();
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
};


