
// SaleSystemsView.cpp : CSaleSystemsView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "SaleSystems.h"
#endif

#include "SaleSystemsDoc.h"
#include "SaleSystemsView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSaleSystemsView

IMPLEMENT_DYNCREATE(CSaleSystemsView, CView)

BEGIN_MESSAGE_MAP(CSaleSystemsView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CSaleSystemsView ����/����

CSaleSystemsView::CSaleSystemsView()
{
	// TODO: �ڴ˴���ӹ������

}

CSaleSystemsView::~CSaleSystemsView()
{
}

BOOL CSaleSystemsView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CSaleSystemsView ����

void CSaleSystemsView::OnDraw(CDC* /*pDC*/)
{
	CSaleSystemsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CSaleSystemsView ��ӡ

BOOL CSaleSystemsView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CSaleSystemsView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CSaleSystemsView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CSaleSystemsView ���

#ifdef _DEBUG
void CSaleSystemsView::AssertValid() const
{
	CView::AssertValid();
}

void CSaleSystemsView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSaleSystemsDoc* CSaleSystemsView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSaleSystemsDoc)));
	return (CSaleSystemsDoc*)m_pDocument;
}
#endif //_DEBUG


// CSaleSystemsView ��Ϣ�������
