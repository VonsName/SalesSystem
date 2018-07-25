// DialogLogin.cpp : 实现文件
//

#include "stdafx.h"
#include "SaleSystems.h"
#include "DialogLogin.h"
#include "afxdialogex.h"
#include "InfoFile.h"


// CDialogLogin 对话框

IMPLEMENT_DYNAMIC(CDialogLogin, CDialogEx)

CDialogLogin::CDialogLogin(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, username(_T(""))
	, password(_T(""))
{

}

CDialogLogin::~CDialogLogin()
{
}

void CDialogLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, username);
	DDX_Text(pDX, IDC_EDIT2, password);
}


BEGIN_MESSAGE_MAP(CDialogLogin, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDialogLogin::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDialogLogin::OnBnClickedButton2)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CDialogLogin 消息处理程序

//登陆button
void CDialogLogin::OnBnClickedButton1()
{
	UpdateData(TRUE);
	if (username.IsEmpty()||password.IsEmpty())
	{
		MessageBox(TEXT("用户名或者密码不能为空"));
		return;
	}
	CInfoFile file;
	CString name, pwd;
	file.ReadLogin(name, pwd);
	if (name==username)
	{
		if (pwd==password)
		{
			CDialog::OnOK();//关闭对话框
		}
		else {
			MessageBox(TEXT("密码错误"));
		}
	}
	else {
		MessageBox(TEXT("用户名错误"));
	}

}


void CDialogLogin::OnBnClickedButton2()
{
	exit(0);
}


BOOL CDialogLogin::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CInfoFile file;
	CString name;
	CString pwd;
	file.ReadLogin(name, pwd);
	username = name;
	password = pwd;
	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDialogLogin::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	//CDialogEx::OnOK();
}


void CDialogLogin::OnClose()
{

	//CDialogEx::OnClose();只关闭当前对话框
	exit(0);
}
