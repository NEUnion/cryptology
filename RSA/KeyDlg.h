#if !defined(AFX_KEYDLG_H__0B3414D3_2C3E_4CB1_9383_087031E2ACF9__INCLUDED_)
#define AFX_KEYDLG_H__0B3414D3_2C3E_4CB1_9383_087031E2ACF9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// KeyDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CKeyDlg dialog

class CKeyDlg : public CDialog
{
// Construction
public:
	CKeyDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CKeyDlg)
	enum { IDD = IDD_DIALOG1 };
	CString	m_strInputEncryptKey;
	CString	m_strModeR;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKeyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CKeyDlg)
	afx_msg void OnEncryptkey();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KEYDLG_H__0B3414D3_2C3E_4CB1_9383_087031E2ACF9__INCLUDED_)
