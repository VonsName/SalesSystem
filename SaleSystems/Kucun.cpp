// Kucun.cpp : 实现文件
//

#include "stdafx.h"
#include "SaleSystems.h"
#include "Kucun.h"
#include "InfoFile.h"


// CKucun

IMPLEMENT_DYNCREATE(CKucun, CFormView)

CKucun::CKucun()
	: CFormView(IDD_DIALOG4)
{

}

CKucun::~CKucun()
{
}

void CKucun::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}

BEGIN_MESSAGE_MAP(CKucun, CFormView)
END_MESSAGE_MAP()


// CKucun 诊断

#ifdef _DEBUG
void CKucun::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CKucun::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CKucun 消息处理程序


void CKucun::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	m_list.SetExtendedStyle(m_list.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	CString filed[] = { _T("商品id"),_T("商品名称") ,_T("商品价格") ,_T("库存数量") };
	for ( int  i = 0; i < filed->GetLength(); i++)
	{
		m_list.InsertColumn(i, filed[i], LVCFMT_CENTER, 90);
	}
	CInfoFile file;
	file.ReadDocline();
	int i = 0;
	CString str;
	for (list<msg> ::iterator  it= file.ls.begin(); it != file.ls.end() ;it++)
	{
		str.Format(_T("%d"), it->id);
		m_list.InsertItem(i, str);
		int col = 1;
		m_list.SetItemText(i, col++, CString(it->name.c_str()));
		str.Format(_T("%d"), it->price);
		m_list.SetItemText(i, col++, str);
		str.Format(_T("%d"), it->num);
		m_list.SetItemText(i, col++, str);
		i++;
	}
	UpdateData(FALSE);
}
