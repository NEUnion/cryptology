// MyMD5.h : main header file for the MYMD5 application
//

#if !defined(AFX_MYMD5_H__ECD1F9A7_3308_4311_8B3A_946D983C1823__INCLUDED_)
#define AFX_MYMD5_H__ECD1F9A7_3308_4311_8B3A_946D983C1823__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyMD5App:
// See MyMD5.cpp for the implementation of this class
//

class CMyMD5App : public CWinApp
{
public:
	CMyMD5App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyMD5App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMyMD5App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYMD5_H__ECD1F9A7_3308_4311_8B3A_946D983C1823__INCLUDED_)
