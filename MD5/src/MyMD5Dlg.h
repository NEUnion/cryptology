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

	string m_File;					// �û�������ļ�
	RECT m_rtWnd,m_rtBtn,m_rtEdit;	// ����RECT,�����ťRECT,ԭ��Ϣ�ı���RECT

	ZThunk m_thunk;					// �˶������ڽ��ص�������װ�����Ա����
    DWORD dwThreadId;				// �߳�ID
    HANDLE hThread;					// �߳̾��
	// �̻߳ص�����(��ȫ��װ�ɴ���ĳ�Ա����)
	DWORD ProcessingThread(LPVOID lpParameter); 

	ZMD5Ex md5;						// MD5�������
	
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYMD5DLG_H__96A9078B_99B3_4932_84C2_A6847B6AAB79__INCLUDED_)
