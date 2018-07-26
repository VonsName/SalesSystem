// SaleDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "SaleSystems.h"
#include "SaleDialog.h"
#include "InfoFile.h"


// CSaleDialog

IMPLEMENT_DYNCREATE(CSaleDialog, CFormView)

CSaleDialog::CSaleDialog()
	: CFormView(IDD_DIALOG3)
	, price(0)
	, kucun(0)
	, num(0)
	, sale_info(_T(""))
{

}

CSaleDialog::~CSaleDialog()
{
}

void CSaleDialog::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//  DDX_CBString(pDX, IDC_COMBO2, productName);
	DDX_Text(pDX, IDC_EDIT2, price);
	DDX_Text(pDX, IDC_EDIT5, kucun);
	DDX_Text(pDX, IDC_EDIT6, num);
	DDX_Text(pDX, IDC_EDIT3, sale_info);
	DDX_Control(pDX, IDC_COMBO2, productName);
}

BEGIN_MESSAGE_MAP(CSaleDialog, CFormView)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CSaleDialog::OnCbnSelchangeCombo2)
	ON_BN_CLICKED(IDC_BUTTON4, &CSaleDialog::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CSaleDialog::OnBnClickedButton5)
END_MESSAGE_MAP()


// CSaleDialog 诊断

#ifdef _DEBUG
void CSaleDialog::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CSaleDialog::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CSaleDialog 消息处理程序


void CSaleDialog::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	CInfoFile file;
	file.ReadDocline();
	for (list<msg> ::iterator it=file.ls.begin();it!=file.ls.end();it++)
	{
		productName.AddString(CString(it->name.c_str()));
	}
	productName.SetCurSel(0);
	OnCbnSelchangeCombo2();
	UpdateData(FALSE);
}


//下拉框改变事件
void CSaleDialog::OnCbnSelchangeCombo2()
{
	int index=productName.GetCurSel();
	CString pname;
	productName.GetLBText(index, pname);
	CInfoFile file;
	file.ReadDocline();
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		if (CString(it->name.c_str())==pname)
		{
			price = it->price;
			kucun = it->num;
			UpdateData(FALSE);
			break;
		}
	}
}

//购买
void CSaleDialog::OnBnClickedButton4()
{
	UpdateData(TRUE);
	if (num!=0)
	{
		if (num>kucun)
		{
			MessageBox(TEXT("购买数量不能大于库存"));
		}
		else
		{
			int index = productName.GetCurSel();
			CString pname;
			productName.GetLBText(index, pname);
			CInfoFile file;
			file.ReadDocline();
			for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
			{
				if (CString(it->name.c_str()) == pname)
				{
					it->num -= num;
					kucun = it->num;
					UpdateData(FALSE);
					CString str;
					str.Format(_T("商品:%s  单价:%d  个数:%d  总价:%d"), pname, it->price, num, num*price);
					sale_info = str;
					MessageBox(TEXT("购买成功"));
					break;
				}
			}
			file.WirteDocline();
			num = 0;
			UpdateData(FALSE);
		}
	}
	else
	{
		MessageBox(TEXT("购买数量不能为0"));
	}
	UpdateData(FALSE);
}

//取消
void CSaleDialog::OnBnClickedButton5()
{
	num = 0;
	UpdateData(FALSE);
	productName.SetCurSel(0);
	OnCbnSelchangeCombo2();
}
