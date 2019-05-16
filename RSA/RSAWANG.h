// RSAWANG.h : main header file for the RSAWANG application
//

#if !defined(AFX_RSAWANG_H__589B70F2_B3FE_459F_9B5E_A5F192A1064A__INCLUDED_)
#define AFX_RSAWANG_H__589B70F2_B3FE_459F_9B5E_A5F192A1064A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRSAWANGApp:
// See RSAWANG.cpp for the implementation of this class
//

class CRSAWANGApp : public CWinApp
{
public:
	CRSAWANGApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRSAWANGApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRSAWANGApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RSAWANG_H__589B70F2_B3FE_459F_9B5E_A5F192A1064A__INCLUDED_)
