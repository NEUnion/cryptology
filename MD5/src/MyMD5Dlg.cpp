// MyMD5Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyMD5.h"
#include "MyMD5Dlg.h"

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
// CMyMD5Dlg dialog

CMyMD5Dlg::CMyMD5Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyMD5Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyMD5Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyMD5Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyMD5Dlg)
	DDX_Control(pDX, IDC_PROGRESS, m_Processing);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyMD5Dlg, CDialog)
	//{{AFX_MSG_MAP(CMyMD5Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_SELECT, OnBtnSelect)
	ON_BN_CLICKED(IDC_BTN_CALCULATION, OnBtnCalculation)
	ON_BN_CLICKED(IDC_BTN_ABOUT, OnBtnAbout)
	ON_CBN_SELCHANGE(IDC_COMBO_TYPE, OnSelchangeComboType)
	ON_MESSAGE(USER_PROCESSING, OnProcessing)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyMD5Dlg message handlers

BOOL CMyMD5Dlg::OnInitDialog()
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

	//设置图标
	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);

	//初始化将要计算MD5加密原信息的类型
	((CComboBox*)GetDlgItem(IDC_COMBO_TYPE))->AddString("字符串");
	((CComboBox*)GetDlgItem(IDC_COMBO_TYPE))->AddString("文件");
	((CComboBox*)GetDlgItem(IDC_COMBO_TYPE))->SetCurSel(0);

	//隐藏文件"浏览"按钮
	::ShowWindow(::GetDlgItem(m_hWnd,IDC_BTN_SELECT),SW_HIDE);

	//获取文件"浏览"按钮的位置
	::GetWindowRect(m_hWnd,&m_rtWnd);
	::GetWindowRect(::GetDlgItem(m_hWnd,IDC_BTN_SELECT),&m_rtBtn);
	::GetWindowRect(::GetDlgItem(m_hWnd,IDC_EDIT_SOURCE),&m_rtEdit);

	//抻拉原信息文件框的位置
	::MoveWindow(::GetDlgItem(m_hWnd,IDC_EDIT_SOURCE),
		m_rtEdit.left-3,
		m_rtEdit.top-GetSystemMetrics(SM_CYCAPTION)-3,
		(m_rtEdit.right-m_rtEdit.left)+(m_rtBtn.right-m_rtEdit.right),
		m_rtEdit.bottom-m_rtEdit.top,
		true);

	/*
	将本窗口句柄传递到MD5类中,以便使这个类可以保存存此句柄并根据此句柄
	向本窗口发送用户自定义消息,USER_PROCESSING消息用于显示计算MD5的进度
	*/
	md5.SetHwnd(m_hWnd);

	//隐藏CProcessCtrl控件
	((CProgressCtrl*)GetDlgItem(IDC_PROGRESS))->ShowWindow(SW_HIDE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMyMD5Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMyMD5Dlg::OnPaint() 
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

HCURSOR CMyMD5Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMyMD5Dlg::OnBtnSelect() 
{
	ZFileDialog fileDlg;
	deque<string> dqSelectFile=fileDlg.GetOpenFileName(FALSE,"所有文件 (*.*)\0*.*\0\0");
	if(dqSelectFile.size()!=0)
	{
		m_File=dqSelectFile[0];
		SetDlgItemText(IDC_EDIT_SOURCE,m_File.c_str());
	}		
}

void CMyMD5Dlg::OnBtnCalculation() 
{
	//取"计算"按钮文字,如果上面的文字为"停止",则停止当前信息的MD5计算
	CString strButton;
	GetDlgItemText(IDC_BTN_CALCULATION,strButton);
	if(strButton=="停止")
	{
		SetDlgItemText(IDC_EDIT_RESULT,"");
		md5.GetMD5OfFile_Terminate();
		SetDlgItemText(IDC_BTN_CALCULATION,"计算");
		((CProgressCtrl*)GetDlgItem(IDC_PROGRESS))->ShowWindow(SW_HIDE);
		return;
	}

	//清空结果文本框
	SetDlgItemText(IDC_EDIT_RESULT,"");

	//获取待计算MD5的原信息数据
	CString strInput;
	GetDlgItemText(IDC_EDIT_SOURCE,strInput);

	//如果原信息类型为字符串
	if(((CComboBox*)GetDlgItem(IDC_COMBO_TYPE))->GetCurSel()==0)
	{
		SetDlgItemText(IDC_EDIT_RESULT,
			md5.GetMD5OfString((LPSTR)(LPCTSTR)strInput,true).c_str());
	}
	//如果原信息类型为文件
	else if(((CComboBox*)GetDlgItem(IDC_COMBO_TYPE))->GetCurSel()==1)
	{
		//如果文件为空,显示选择文件对话框
		if(m_File.empty())
		{
			OnBtnSelect();
			return ;
		}
		//栓查文件是否存在
		else if( (_access((char*)(LPCTSTR)strInput, 0 )) == -1 )
		{
			AfxMessageBox("文件不存在!");
			return ;
		}
		else
		{
			//计算文件大小
			unsigned long FileSize=0xFFFFFFFF;
			WIN32_FIND_DATA  win32_find_data;
			HANDLE hFile;
			if((hFile=FindFirstFile((char*)(LPCTSTR)strInput,&win32_find_data))!=INVALID_HANDLE_VALUE)
			{
				FindClose(hFile);
				if(FileSize=win32_find_data.nFileSizeLow,FileSize==0xFFFFFFFF || FileSize==0)
					return ;
			}

			//文件大于等于10M,显示处理进度条
			if(FileSize>=10485760)
			{
				//显示处理进度条
				m_Processing.SetPos(0);
				((CProgressCtrl*)GetDlgItem(IDC_PROGRESS))->ShowWindow(SW_SHOW);

				//将"计算"按钮上的文字变成"停止"
				SetDlgItemText(IDC_BTN_CALCULATION,"停止");

				//开启一个线程用于计算MD5,以免造成假死现像
				hThread= CreateThread(NULL,0,
				(LPTHREAD_START_ROUTINE)m_thunk.CallBack(this,
				&CMyMD5Dlg::ProcessingThread,ZThunk::THISCALL),
				0,0,&dwThreadId);
			}
			//文件小于10M,直接进行MD5计算,不开启线程,因为计算时间很短
			else
			{
				SetDlgItemText(IDC_EDIT_RESULT,
				md5.GetMD5OfFile((LPSTR)(LPCTSTR)strInput,true).c_str());
			}
		}
	}
}

void CMyMD5Dlg::OnBtnAbout() 
{
	CAboutDlg dlg;
	dlg.DoModal();
}

//处理WM_RETURN(回车)和WM_VK_ESCAPE(取消)
BOOL CMyMD5Dlg::PreTranslateMessage(MSG* pMsg) 
{
	if(pMsg->message==WM_KEYDOWN)   
	{   
		switch(pMsg->wParam)   
		{   
		case VK_ESCAPE:   
			return   TRUE;
		case VK_RETURN:   
			return   TRUE;
		default:   
			break;   
		}   
	} 	
	return CDialog::PreTranslateMessage(pMsg);
}

//当原信息类型改变时,隐藏或显示"浏览"文件按钮
void CMyMD5Dlg::OnSelchangeComboType() 
{
	if(((CComboBox*)GetDlgItem(IDC_COMBO_TYPE))->GetCurSel()==1)
	{
		::EnableWindow(::GetDlgItem(m_hWnd,IDC_BTN_SELECT),TRUE);
		((CEdit*)GetDlgItem(IDC_EDIT_SOURCE))->SetReadOnly(true);
		::ShowWindow(::GetDlgItem(m_hWnd,IDC_BTN_SELECT),SW_SHOW);
		::MoveWindow(::GetDlgItem(m_hWnd,IDC_EDIT_SOURCE),
					m_rtEdit.left-3,
					m_rtEdit.top-GetSystemMetrics(SM_CYCAPTION)-3,
					m_rtEdit.right-m_rtEdit.left,
					m_rtEdit.bottom-m_rtEdit.top,
					true);
	}
	else
	{
		::EnableWindow(::GetDlgItem(m_hWnd,IDC_BTN_SELECT),FALSE);
		::ShowWindow(::GetDlgItem(m_hWnd,IDC_BTN_SELECT),SW_HIDE);
		((CEdit*)GetDlgItem(IDC_EDIT_SOURCE))->SetReadOnly(false);
		::MoveWindow(::GetDlgItem(m_hWnd,IDC_EDIT_SOURCE),
					m_rtEdit.left-3,
					m_rtEdit.top-GetSystemMetrics(SM_CYCAPTION)-3,
					(m_rtEdit.right-m_rtEdit.left)+(m_rtBtn.right-m_rtEdit.right),
					m_rtEdit.bottom-m_rtEdit.top,
					true);
	}
	m_File="";
	SetDlgItemText(IDC_EDIT_SOURCE,"");
	SetDlgItemText(IDC_EDIT_RESULT,"");
}

DWORD CMyMD5Dlg::ProcessingThread(LPVOID lpParameter)
{
	CString strInput;
	GetDlgItemText(IDC_EDIT_SOURCE,strInput);
	SetDlgItemText(IDC_EDIT_RESULT,
	md5.GetMD5OfFile((LPSTR)(LPCTSTR)strInput,true).c_str());
	return 1;
}

LRESULT CMyMD5Dlg::OnProcessing(WPARAM wParam, LPARAM lParam)
{
	m_Processing.SetPos((int)wParam);
	if((int)wParam==100)
	{
		//隐藏CProcessCtrl控件
		((CProgressCtrl*)GetDlgItem(IDC_PROGRESS))->ShowWindow(SW_HIDE);
		//将"停止"按钮上的文字变成"计算"
		SetDlgItemText(IDC_BTN_CALCULATION,"计算");
	}
	return 1;
}
