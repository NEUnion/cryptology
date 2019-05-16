#if !defined(AFX_DECRYPTKEYDLG_H__6880A940_ACBE_45A9_AB45_263F3E2A0607__INCLUDED_)
#define AFX_DECRYPTKEYDLG_H__6880A940_ACBE_45A9_AB45_263F3E2A0607__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DecryptKeyDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDecryptKeyDlg dialog

class CDecryptKeyDlg : public CDialog
{
// Construction
public:
	CDecryptKeyDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDecryptKeyDlg)
	enum { IDD = IDD_DIALOG2 };
	CString	m_strInputDecryptKey;
	CString	m_strInputModeR1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDecryptKeyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDecryptKeyDlg)
	afx_msg void OnDecryptkey();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DECRYPTKEYDLG_H__6880A940_ACBE_45A9_AB45_263F3E2A0607__INCLUDED_)
