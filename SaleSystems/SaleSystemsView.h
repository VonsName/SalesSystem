
// SaleSystemsView.h : CSaleSystemsView ��Ľӿ�
//

#pragma once


class CSaleSystemsView : public CView
{
protected: // �������л�����
	CSaleSystemsView();
	DECLARE_DYNCREATE(CSaleSystemsView)

// ����
public:
	CSaleSystemsDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CSaleSystemsView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // SaleSystemsView.cpp �еĵ��԰汾
inline CSaleSystemsDoc* CSaleSystemsView::GetDocument() const
   { return reinterpret_cast<CSaleSystemsDoc*>(m_pDocument); }
#endif

