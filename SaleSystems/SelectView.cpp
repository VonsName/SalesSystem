// SelectView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SaleSystems.h"
#include "SelectView.h"
#include "InfoFile.h"
#include "MainFrm.h"


// CSelectView

IMPLEMENT_DYNCREATE(CSelectView, CTreeView)

CSelectView::CSelectView()
{

}

CSelectView::~CSelectView()
{
}

BEGIN_MESSAGE_MAP(CSelectView, CTreeView)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, &CSelectView::OnTvnSelchanged)
END_MESSAGE_MAP()


// CSelectView ���

#ifdef _DEBUG
void CSelectView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CSelectView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// CSelectView ��Ϣ�������


void CSelectView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();

	//��ʼ����״ͼ
	ctrl = &GetTreeCtrl();

	//׼��ͼƬ
	HICON icon = AfxGetApp()->LoadIconW(IDI_ICON1);

	imgList.Create(30, 30, ILC_COLOR32, 1, 1);
	imgList.Add(icon);

	//����ͼƬ����
	ctrl->SetImageList(&imgList,TVSIL_NORMAL);

	ctrl->InsertItem(TEXT("������Ϣ"), 0, 0, nullptr);
	ctrl->InsertItem(TEXT("���۹���"), 0, 0, nullptr);
	ctrl->InsertItem(TEXT("�����Ϣ"), 0, 0, nullptr);
	ctrl->InsertItem(TEXT("�����Ϣ"), 0, 0, nullptr);
	ctrl->InsertItem(TEXT("�����Ϣ"), 0, 0, nullptr);


}

//�ؼ�ѡ��ı��¼�
void CSelectView::OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	*pResult = 0;
	//��ȡ��ǰ��ѡ����
	HTREEITEM item= ctrl->GetSelectedItem();
	//ͨ��ѡ�е���
	CString str = ctrl->GetItemText(item);
	
	//�����Զ������Ϣ ��CMainFrame
	if (str==TEXT("������Ϣ"))
	{
		/**
		 * ��һ��������ʾҪ���ĸ����ڷ�����Ϣ
			�ڶ���������ʾҪ����ʲô������Ϣ
			�� �ı�ʾ��Ϣ����
		 */
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_A, (WPARAM)NM_A, (LPARAM)0);
	}
	else if (TEXT("���۹���"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_B, (WPARAM)NM_B, (LPARAM)0);
	}
	else if (TEXT("�����Ϣ")) {
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_C, (WPARAM)NM_C, (LPARAM)0);
	}
	else if (TEXT("������")) {
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_D, (WPARAM)NM_D, (LPARAM)0);
	}else if (TEXT("���ɾ��"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_E, (WPARAM)NM_E, (LPARAM)0);
	}
	
	CInfoFile file;
	CString u_name;
	
}
