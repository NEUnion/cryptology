// MMDlg.h : header file
//

#if !defined(AFX_MMDLG_H__676363D5_292E_4E30_A928_35988BBC2FD9__INCLUDED_)
#define AFX_MMDLG_H__676363D5_292E_4E30_A928_35988BBC2FD9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMMDlg dialog

class CMMDlg : public CDialog
{
// Construction
public:
	CMMDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMMDlg)
	enum { IDD = IDD_MM_DIALOG };
	CEdit	m_edit1;
	CString	m_edit3;
	CString	m_edit2;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMMDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMMDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MMDLG_H__676363D5_292E_4E30_A928_35988BBC2FD9__INCLUDED_)
