#pragma once
#include "afxcmn.h"



// CKucun ������ͼ

class CKucun : public CFormView
{
	DECLARE_DYNCREATE(CKucun)

protected:
	CKucun();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CKucun();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_list;
public:
	virtual void OnInitialUpdate();
};


