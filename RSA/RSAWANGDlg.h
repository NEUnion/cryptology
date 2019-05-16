// RSAWANGDlg.h : header file
//

#if !defined(AFX_RSAWANGDLG_H__146DD329_C054_408D_B4C9_8CE9783336DA__INCLUDED_)
#define AFX_RSAWANGDLG_H__146DD329_C054_408D_B4C9_8CE9783336DA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CRSAWANGDlg dialog

class CRSAWANGDlg : public CDialog
{
// Construction
public:
	CRSAWANGDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CRSAWANGDlg)
	enum { IDD = IDD_RSAWANG_DIALOG };
	CString	m_strDecryptString;
	CString	m_strSourceString;
	CString	m_strR;
	CString	m_strPublicKey;
	CString	m_strPrivateKey;
	CStringArray m_strEncryptStringArray;
	CString	m_strEncryptString;

	CString m_strInputPublicKey;
	CString m_strInputPrivateKey;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRSAWANGDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRSAWANGDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnCancel();
	afx_msg void OnEncrypt();
	afx_msg void OnDecrypt();
	afx_msg void OnGenkey();
	//afx_msg void OnGenkey();
	afx_msg void OnGeneratekey();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	CString m_strInputModeR1;
	CString m_strInputR;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RSAWANGDLG_H__146DD329_C054_408D_B4C9_8CE9783336DA__INCLUDED_)
