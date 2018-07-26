// UserDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SaleSystems.h"
#include "UserDialog.h"
#include "InfoFile.h"


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
	ON_BN_CLICKED(IDC_BUTTON1, &CUserDialog::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CUserDialog::OnBnClickedButton3)
END_MESSAGE_MAP()


// CUserDialog ���

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


// CUserDialog ��Ϣ�������


void CUserDialog::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	CInfoFile file;
	role = "����Ա";
	CString username;
	CString password;
	file.ReadLogin(username, password);
	name = username;
	UpdateData(FALSE);
}


//�޸�����ȷ��
void CUserDialog::OnBnClickedButton1()
{
	UpdateData(TRUE);
	CInfoFile file;
	CString name;
	CString pwd;
	file.ReadLogin(name, pwd);
	if (newPwd.IsEmpty()||surePwd.IsEmpty())
	{
		MessageBox(TEXT("�������ݲ���Ϊ��"));
		return;
	}
	if (newPwd==pwd)
	{
		MessageBox(TEXT("������������벻����ͬ"));
		return;
	}
	if (newPwd!=surePwd)
	{
		MessageBox(TEXT("�������벻һ��"));
		return;
	}
	CStringA tmppwd;
	tmppwd = newPwd;
	CStringA tmpname;
	tmpname = name;
	file.WritePwd(tmpname.GetBuffer(), tmppwd.GetBuffer());
	MessageBox(TEXT("�޸ĳɹ�"));
	newPwd.Empty();
	surePwd.Empty();
	UpdateData(FALSE);
}


//ȡ���޸�����
void CUserDialog::OnBnClickedButton3()
{
	UpdateData(TRUE);
	newPwd.Empty();
	surePwd.Empty();
	UpdateData(FALSE);
}
