// MyMD5Dlg.h : header file
//

#if !defined(AFX_MYMD5DLG_H__96A9078B_99B3_4932_84C2_A6847B6AAB79__INCLUDED_)
#define AFX_MYMD5DLG_H__96A9078B_99B3_4932_84C2_A6847B6AAB79__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMyMD5Dlg dialog

#include <io.h>
#include "ZFileDialog.h"
#include "ZThunk.h"
#include "ZMD5Ex.h"

class CMyMD5Dlg : public CDialog
{
// Construction
public:
	CMyMD5Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMyMD5Dlg)
	enum { IDD = IDD_MYMD5_DIALOG };
	CProgressCtrl	m_Processing;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyMD5Dlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMyMD5Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnSelect();
	afx_msg void OnBtnCalculation();
	afx_msg void OnBtnAbout();
	afx_msg void OnSelchangeComboType();
	afx_msg LRESULT OnProcessing(WPARAM wParam, LPARAM lParam);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

private:

	string m_File;					// 用户浏览的文件
	RECT m_rtWnd,m_rtBtn,m_rtEdit;	// 窗口RECT,浏览按钮RECT,原信息文本框RECT

	ZThunk m_thunk;					// 此对像用于将回调函数封装成类成员函数
    DWORD dwThreadId;				// 线程ID
    HANDLE hThread;					// 线程句柄
	// 线程回调函数(完全封装成此类的成员函数)
	DWORD ProcessingThread(LPVOID lpParameter); 

	ZMD5Ex md5;						// MD5计算对像
	
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYMD5DLG_H__96A9078B_99B3_4932_84C2_A6847B6AAB79__INCLUDED_)
