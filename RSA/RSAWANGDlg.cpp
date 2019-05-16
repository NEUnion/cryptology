// RSAWANGDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RSAWANG.h"
#include "RSAWANGDlg.h"

#include "KeyDlg.h"
#include "DecryptKeyDlg.h"

#include "RsaA.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRSAWANGDlg dialog

CRSAWANGDlg::CRSAWANGDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRSAWANGDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRSAWANGDlg)
	m_strDecryptString = _T("");
	m_strSourceString = _T("");
	m_strR = _T("");
	m_strPublicKey = _T("");
	m_strPrivateKey = _T("");
	m_strEncryptString = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRSAWANGDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRSAWANGDlg)
	DDX_Text(pDX, IDC_DECRYPTSTRING, m_strDecryptString);
	DDX_Text(pDX, IDC_SOURCESTRING, m_strSourceString);
	DDX_Text(pDX, IDC_R, m_strR);
	DDX_Text(pDX, IDC_PRIVATEKEY, m_strPublicKey);
	DDX_Text(pDX, IDC_PUBLICKEY, m_strPrivateKey);
	DDX_Text(pDX, IDC_ENCRYPTSTRING, m_strEncryptString);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CRSAWANGDlg, CDialog)
	//{{AFX_MSG_MAP(CRSAWANGDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ENCRYPT, OnEncrypt)
	ON_BN_CLICKED(IDC_DECRYPT, OnDecrypt)
	//ON_BN_CLICKED(IDC_GENKEY, OnGenkey)
	ON_BN_CLICKED(IDC_GENERATEKEY, OnGeneratekey)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRSAWANGDlg message handlers

BOOL CRSAWANGDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CRSAWANGDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CRSAWANGDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CRSAWANGDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


void CRSAWANGDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void CRSAWANGDlg::OnEncrypt() 
{
	
	//int RsaEncrypt(CString& source,const char* key,const char* R,CStringArray& result);//加密
	//void LoadKeysFromFile(CString& r,CString& sk,CString& pk);

    UpdateData(TRUE);
	CKeyDlg dlg;
	dlg.DoModal();
	m_strInputPublicKey=dlg.m_strInputEncryptKey;
	m_strInputR=dlg.m_strModeR;
	CRsaA rsa;	
	//下面的语句中需要进一步细化m_strR,以便可以直接调用加密函数
	rsa.RsaEncrypt(m_strSourceString,m_strInputPublicKey,m_strInputR,m_strEncryptStringArray);

	//处理加密后的字符串
	int index=0;
	CString strTempEncrypt;
	index=m_strEncryptStringArray.GetSize();
	for(int i=0;i<index;i++)
	{
		strTempEncrypt=m_strEncryptStringArray.GetAt(i);
	}
	m_strEncryptString=strTempEncrypt;

	UpdateData(FALSE);

}

void CRSAWANGDlg::OnDecrypt() 
{
	
	//CString RsaDecrypt(CStringArray& source,const char* sk,const char* R);//解密

	CDecryptKeyDlg dlg;
	dlg.DoModal();
	m_strInputPrivateKey=dlg.m_strInputDecryptKey;
	m_strInputModeR1=dlg.m_strInputModeR1;
	CRsaA rsa;
	UpdateData(TRUE);
	m_strDecryptString=rsa.RsaDecrypt(m_strEncryptStringArray,m_strInputPrivateKey,m_strInputModeR1);
	UpdateData(FALSE);
}

void CRSAWANGDlg::OnGeneratekey() 
{
	//void GenKeys(CString& pk,CString& sk,CString& R); //提供给服务器使用的秘钥产生函数

	CRsaA rsa;
	rsa.GenKeys(m_strPublicKey,m_strPrivateKey,m_strR);
	UpdateData(FALSE);
	
}
