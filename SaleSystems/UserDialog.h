#pragma once



// CUserDialog ������ͼ

class CUserDialog : public CFormView
{
	DECLARE_DYNCREATE(CUserDialog)

protected:
	CUserDialog();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CUserDialog();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
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
	CString role;
	CString name;
	CString newPwd;
	CString surePwd;
};


