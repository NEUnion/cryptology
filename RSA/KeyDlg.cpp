// KeyDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RSAWANG.h"
#include "KeyDlg.h"

#include "rsawangdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CKeyDlg dialog


CKeyDlg::CKeyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CKeyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CKeyDlg)
	m_strInputEncryptKey = _T("");
	m_strModeR = _T("");
	//}}AFX_DATA_INIT
}


void CKeyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CKeyDlg)
	DDX_Text(pDX, IDC_INPUTENCRYPTKEY, m_strInputEncryptKey);
	DDX_Text(pDX, IDC_INPUTMODER, m_strModeR);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CKeyDlg, CDialog)
	//{{AFX_MSG_MAP(CKeyDlg)
	ON_BN_CLICKED(IDC_ENCRYPTKEY, OnEncryptkey)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKeyDlg message handlers

void CKeyDlg::OnEncryptkey() 
{
	// TODO: Add your control notification handler code here

	//CRSAWANGDlg dlg;
	UpdateData(TRUE);
	//dlg.m_strInputPublicKey=m_strInputEncryptKey;
	CDialog::OnOK();
	
}
