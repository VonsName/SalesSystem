// SelectView.cpp : 实现文件
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


// CSelectView 诊断

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


// CSelectView 消息处理程序


void CSelectView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();

	//初始化树状图
	ctrl = &GetTreeCtrl();

	//准备图片
	HICON icon = AfxGetApp()->LoadIconW(IDI_ICON1);

	imgList.Create(30, 30, ILC_COLOR32, 1, 1);
	imgList.Add(icon);

	//设置图片集合
	ctrl->SetImageList(&imgList,TVSIL_NORMAL);

	ctrl->InsertItem(TEXT("个人信息"), 0, 0, nullptr);
	ctrl->InsertItem(TEXT("销售管理"), 0, 0, nullptr);
	ctrl->InsertItem(TEXT("库存信息"), 0, 0, nullptr);
	ctrl->InsertItem(TEXT("库存信息"), 0, 0, nullptr);
	ctrl->InsertItem(TEXT("库存信息"), 0, 0, nullptr);


}

//控件选项改变事件
void CSelectView::OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	*pResult = 0;
	//获取当前的选中项
	HTREEITEM item= ctrl->GetSelectedItem();
	//通过选中的项
	CString str = ctrl->GetItemText(item);
	
	//发送自定义的消息 到CMainFrame
	if (str==TEXT("个人信息"))
	{
		/**
		 * 第一个参数表示要给哪个窗口发送消息
			第二个参数表示要发送什么样的消息
			三 四表示消息类型
		 */
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_A, (WPARAM)NM_A, (LPARAM)0);
	}
	else if (TEXT("销售管理"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_B, (WPARAM)NM_B, (LPARAM)0);
	}
	else if (TEXT("库存信息")) {
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_C, (WPARAM)NM_C, (LPARAM)0);
	}
	else if (TEXT("库存添加")) {
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_D, (WPARAM)NM_D, (LPARAM)0);
	}else if (TEXT("库存删除"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_E, (WPARAM)NM_E, (LPARAM)0);
	}
	
	CInfoFile file;
	CString u_name;
	
}
