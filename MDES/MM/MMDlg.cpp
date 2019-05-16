// MMDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MM.h"
#include "MMDlg.h"
#include "DES.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMMDlg dialog

CMMDlg::CMMDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMMDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMMDlg)
	m_edit3 = _T("");
	m_edit2 = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMMDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMMDlg)
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	DDX_Text(pDX, IDC_EDIT3, m_edit3);
	DDX_Text(pDX, IDC_EDIT2, m_edit2);
	DDV_MaxChars(pDX, m_edit2, 8);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMMDlg, CDialog)
	//{{AFX_MSG_MAP(CMMDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMMDlg message handlers

BOOL CMMDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	m_edit1.SetWindowText("Host1234");
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMMDlg::OnPaint() 
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
HCURSOR CMMDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMMDlg::OnOK() 
{
	char skey[32];
    char inbuff[32],oubuff[32];
	
	UpdateData(TRUE);
	memcpy(skey,m_edit2,8);
	memcpy(inbuff,"Host1234",8);

	CString strTmp,str;

	DES jm;
	jm.Des_Go(oubuff, inbuff, sizeof(inbuff), skey,sizeof(skey), ENCRYPT);
		
	for(int i=0;i<32;i++)
	  str+=oubuff[i];
	
	m_edit3=str;
	if("`ý¦øäÓ..E¦ºå~..E¦ºå~..E¦ºå\0"==str)
		MessageBox("OK");
	UpdateData(0);
}

void CMMDlg::OnCancel() 
{
	CDialog::OnCancel();
}
