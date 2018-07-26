// AddDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "SaleSystems.h"
#include "AddDialog.h"
#include "InfoFile.h"


// CAddDialog

IMPLEMENT_DYNCREATE(CAddDialog, CFormView)

CAddDialog::CAddDialog()
	: CFormView(IDD_DIALOG5)
	, price1(0)
	, num1(0)
	, m_name(_T(""))
	, price2(0)
	, num2(0)
{

}

CAddDialog::~CAddDialog()
{
}

void CAddDialog::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combo);
	DDX_Text(pDX, IDC_EDIT1, price1);
	DDX_Text(pDX, IDC_EDIT2, num1);
	DDX_Text(pDX, IDC_EDIT3, m_name);
	DDX_Text(pDX, IDC_EDIT5, price2);
	DDX_Text(pDX, IDC_EDIT6, num2);
}

BEGIN_MESSAGE_MAP(CAddDialog, CFormView)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CAddDialog::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON3, &CAddDialog::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CAddDialog::OnBnClickedButton4)
END_MESSAGE_MAP()


// CAddDialog 诊断

#ifdef _DEBUG
void CAddDialog::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CAddDialog::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CAddDialog 消息处理程序


void CAddDialog::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	CInfoFile file;
	file.ReadDocline();
	for (list<msg> ::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		m_combo.AddString(CString(it->name.c_str()));
	}
	m_combo.SetCurSel(0);
	UpdateData(FALSE);
	OnCbnSelchangeCombo1();
}


//下拉框改变事件
void CAddDialog::OnCbnSelchangeCombo1()
{
	int index = m_combo.GetCurSel();
	CString pname;
	m_combo.GetLBText(index, pname);
	CInfoFile file;
	file.ReadDocline();
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		if (CString(it->name.c_str()) == pname)
		{
			price1 = it->price;
			UpdateData(FALSE);
			break;
		}
	}
}

//添加商品
void CAddDialog::OnBnClickedButton3()
{
	UpdateData(TRUE);
	if (num1<=0)
	{
		MessageBox(TEXT("数量不能为0"));
		return;
	}
	int index = m_combo.GetCurSel();
	CString pname;
	m_combo.GetLBText(index, pname);
	CInfoFile file;
	file.ReadDocline();
	for (list<msg> ::iterator it= file.ls.begin(); it != file.ls.end(); it++)
	{
		if (pname==CString(it->name.c_str()))
		{
			it->num += num1;
			break;
		}
	}
	file.WirteDocline();
	num1 = 0;
	MessageBox(TEXT("操作成功"));
	UpdateData(FALSE);
}


void CAddDialog::OnBnClickedButton4()
{
	num1 = 0;
	UpdateData(FALSE);
	m_combo.SetCurSel(0);
	OnCbnSelchangeCombo1();
}
