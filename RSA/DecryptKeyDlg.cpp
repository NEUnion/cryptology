// DecryptKeyDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RSAWANG.h"
#include "DecryptKeyDlg.h"

#include "rsawangdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDecryptKeyDlg dialog


CDecryptKeyDlg::CDecryptKeyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDecryptKeyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDecryptKeyDlg)
	m_strInputDecryptKey = _T("");
	m_strInputModeR1 = _T("");
	//}}AFX_DATA_INIT
}


void CDecryptKeyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDecryptKeyDlg)
	DDX_Text(pDX, IDC_INPUTDECRYPTKEY, m_strInputDecryptKey);
	DDX_Text(pDX, IDC_INPUTMODER1, m_strInputModeR1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDecryptKeyDlg, CDialog)
	//{{AFX_MSG_MAP(CDecryptKeyDlg)
	ON_BN_CLICKED(IDC_DECRYPTKEY, OnDecryptkey)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDecryptKeyDlg message handlers

void CDecryptKeyDlg::OnDecryptkey() 
{
	// TODO: Add your control notification handler code here
	//CRSAWANGDlg dlg;
	UpdateData(TRUE);
	//dlg.m_strInputPrivateKey=m_strInputDecryptKey;
	CDialog::OnOK();	
}
