// DialogLogin.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SaleSystems.h"
#include "DialogLogin.h"
#include "afxdialogex.h"
#include "InfoFile.h"


// CDialogLogin �Ի���

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


// CDialogLogin ��Ϣ�������

//��½button
void CDialogLogin::OnBnClickedButton1()
{
	UpdateData(TRUE);
	if (username.IsEmpty()||password.IsEmpty())
	{
		MessageBox(TEXT("�û����������벻��Ϊ��"));
		return;
	}
	CInfoFile file;
	CString name, pwd;
	file.ReadLogin(name, pwd);
	if (name==username)
	{
		if (pwd==password)
		{
			CDialog::OnOK();//�رնԻ���
		}
		else {
			MessageBox(TEXT("�������"));
		}
	}
	else {
		MessageBox(TEXT("�û�������"));
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
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CDialogLogin::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���

	//CDialogEx::OnOK();
}


void CDialogLogin::OnClose()
{

	//CDialogEx::OnClose();ֻ�رյ�ǰ�Ի���
	exit(0);
}
