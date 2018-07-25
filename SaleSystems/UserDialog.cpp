// UserDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "SaleSystems.h"
#include "UserDialog.h"


// CUserDialog

IMPLEMENT_DYNCREATE(CUserDialog, CFormView)

CUserDialog::CUserDialog()
	: CFormView(IDD_DIALOG2)
	, role(_T(""))
	, name(_T(""))
	, newPwd(_T(""))
	, surePwd(_T(""))
{

}

CUserDialog::~CUserDialog()
{
}

void CUserDialog::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT3, role);
	DDX_Text(pDX, IDC_EDIT4, name);
	DDX_Text(pDX, IDC_BUTTON2, newPwd);
	DDX_Text(pDX, IDC_EDIT2, surePwd);
}

BEGIN_MESSAGE_MAP(CUserDialog, CFormView)
END_MESSAGE_MAP()


// CUserDialog 诊断

#ifdef _DEBUG
void CUserDialog::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CUserDialog::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CUserDialog 消息处理程序
