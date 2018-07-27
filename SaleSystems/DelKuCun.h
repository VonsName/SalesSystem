#pragma once
#include "afxwin.h"



// CDelKuCun 窗体视图

class CDelKuCun : public CFormView
{
	DECLARE_DYNCREATE(CDelKuCun)

protected:
	CDelKuCun();           // 动态创建所使用的受保护的构造函数
	virtual ~CDelKuCun();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG6 };
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
	int price;
	int num;
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	virtual void OnInitialUpdate();
	afx_msg void OnCbnSelchangeCombo1();
private:
	int oldnum;
};


