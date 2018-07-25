
// MainFrm.cpp : CMainFrame ���ʵ��
//

#include "stdafx.h"
#include "SaleSystems.h"
#include "SelectView.h"
#include "DisplayView.h"
#include "UserDialog.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_MESSAGE(NM_A, OnMyChange)
	ON_MESSAGE(NM_B, OnMyChange)
	ON_MESSAGE(NM_C, OnMyChange)
	ON_MESSAGE(NM_D, OnMyChange)
	ON_MESSAGE(NM_E, OnMyChange)

END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // ״̬��ָʾ��
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	// TODO: �ڴ���ӳ�Ա��ʼ������
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("δ�ܴ���������\n");
		return -1;      // δ�ܴ���
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("δ�ܴ���״̬��\n");
		return -1;      // δ�ܴ���
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));
	//����ͼ�꣬IDI_ICON_WINΪͼ����ԴID����ΪWINAPI����
	SetClassLong(m_hWnd, GCL_HICON, (LONG)AfxGetApp()->LoadIconW(IDI_ICON2));
	//���ñ���
	SetTitle(TEXT("2018/7/24"));
	//���ô��ڴ�С
	MoveWindow(0, 0, 800, 600);
	//���þ�����ʾ
	CenterWindow();

	// TODO: �������Ҫ��ͣ������������ɾ��������
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return TRUE;
}

// CMainFrame ���

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame ��Ϣ�������

//��̬��ִ���
BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: �ڴ����ר�ô����/����û���

	//return CFrameWnd::OnCreateClient(lpcs, pContext);
	//��ֳ�һ������
	spliter.CreateStatic(this, 1, 2);
	//���Ҳ������
	spliter.CreateView(0, 0, RUNTIME_CLASS(CSelectView),CSize(200,500),pContext);
	spliter.CreateView(0, 1, RUNTIME_CLASS(CDisplayView), CSize(600, 500), pContext);
	return TRUE;
}

//�Զ�����Ϣ����
LRESULT CMainFrame::OnMyChange(WPARAM wparm, LPARAM lparam)
{
	CCreateContext context;
	if (wparm==NM_A)
	{
		//���ؽ���
		context.m_pNewViewClass = RUNTIME_CLASS(CUserDialog);
		context.m_pCurrentFrame = this;
		context.m_pLastView = (CFormView *)spliter.GetPane(0, 1);
		spliter.DeleteView(0, 1);
		spliter.CreateView(0, 1, RUNTIME_CLASS(CUserDialog), CSize(600, 600), &context);
		CUserDialog *pNewView = (CUserDialog *)spliter.GetPane(0, 1);
		spliter.RecalcLayout();
		pNewView->OnInitialUpdate();
		spliter.SetActivePane(0, 1);

	}else if (wparm == NM_B)
	{
	}else if (wparm == NM_C)
	{
	}else if (wparm == NM_D)
	{
	}else if (wparm == NM_E)
	{
	}
	return 0;
}
