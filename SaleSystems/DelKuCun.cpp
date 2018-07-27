// DelKuCun.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SaleSystems.h"
#include "DelKuCun.h"
#include "InfoFile.h"


// CDelKuCun

IMPLEMENT_DYNCREATE(CDelKuCun, CFormView)

CDelKuCun::CDelKuCun()
	: CFormView(IDD_DIALOG6)
	, price(0)
	, num(0)
	, oldnum(0)
{

}

CDelKuCun::~CDelKuCun()
{
}

void CDelKuCun::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combo);
	DDX_Text(pDX, IDC_EDIT1, price);
	DDX_Text(pDX, IDC_EDIT2, num);
	DDX_Text(pDX, IDC_EDIT3, oldnum);
}

BEGIN_MESSAGE_MAP(CDelKuCun, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDelKuCun::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDelKuCun::OnBnClickedButton2)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CDelKuCun::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// CDelKuCun ���

#ifdef _DEBUG
void CDelKuCun::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CDelKuCun::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CDelKuCun ��Ϣ�������

//ɾ�����
void CDelKuCun::OnBnClickedButton1()
{
	UpdateData(TRUE);
	int index=m_combo.GetCurSel();
	CString pname;
	m_combo.GetLBText(index, pname);
	CInfoFile file;
	file.ReadDocline();
	for (list<msg>::iterator  it= file.ls.begin(); it!=file.ls.end(); it++)
	{
		if (CString(it->name.c_str())==pname)
		{
			if (it->num==0)
			{
				MessageBox(TEXT("���Ϊ0"));
				return;
			}
			if (num<=it->num)
			{
				it->num -= num;
				m_combo.SetCurSel(0);
				OnCbnSelchangeCombo1();
				num = 0;
				break;
			}
			else {
				MessageBox(TEXT("������Ϣ����"));
				return;
			}
		}
	}
	file.WirteDocline();
	UpdateData(FALSE);
	MessageBox(TEXT("ɾ���ɹ�"));
}


//ȡ��ɾ��
void CDelKuCun::OnBnClickedButton2()
{
	num = 0;
	UpdateData(FALSE);
}

//��ʼ������
void CDelKuCun::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	CInfoFile file;
	file.ReadDocline();
	for (list<msg>:: iterator  it= file.ls.begin(); it != file.ls.end(); it++)
	{
		m_combo.AddString(CString(it->name.c_str()));
	}
	m_combo.SetCurSel(0);
	OnCbnSelchangeCombo1();
	UpdateData(FALSE);
}

//������ı��¼�
void CDelKuCun::OnCbnSelchangeCombo1()
{
	CInfoFile file;
	file.ReadDocline();
	int index=m_combo.GetCurSel();
	CString pname;
	m_combo.GetLBText(index, pname);
	for (list<msg>:: iterator  it= file.ls.begin(); it !=file.ls.end(); it++)
	{
		if (pname==CString(it->name.c_str()))
		{
			price = it->price;
			oldnum = it->num;
			break;
		}
	}
	UpdateData(FALSE);
}
