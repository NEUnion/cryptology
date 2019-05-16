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

	//����ͼ��
	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);

	//��ʼ����Ҫ����MD5����ԭ��Ϣ������
	((CComboBox*)GetDlgItem(IDC_COMBO_TYPE))->AddString("�ַ���");
	((CComboBox*)GetDlgItem(IDC_COMBO_TYPE))->AddString("�ļ�");
	((CComboBox*)GetDlgItem(IDC_COMBO_TYPE))->SetCurSel(0);

	//�����ļ�"���"��ť
	::ShowWindow(::GetDlgItem(m_hWnd,IDC_BTN_SELECT),SW_HIDE);

	//��ȡ�ļ�"���"��ť��λ��
	::GetWindowRect(m_hWnd,&m_rtWnd);
	::GetWindowRect(::GetDlgItem(m_hWnd,IDC_BTN_SELECT),&m_rtBtn);
	::GetWindowRect(::GetDlgItem(m_hWnd,IDC_EDIT_SOURCE),&m_rtEdit);

	//����ԭ��Ϣ�ļ����λ��
	::MoveWindow(::GetDlgItem(m_hWnd,IDC_EDIT_SOURCE),
		m_rtEdit.left-3,
		m_rtEdit.top-GetSystemMetrics(SM_CYCAPTION)-3,
		(m_rtEdit.right-m_rtEdit.left)+(m_rtBtn.right-m_rtEdit.right),
		m_rtEdit.bottom-m_rtEdit.top,
		true);

	/*
	�������ھ�����ݵ�MD5����,�Ա�ʹ�������Ա����˾�������ݴ˾��
	�򱾴��ڷ����û��Զ�����Ϣ,USER_PROCESSING��Ϣ������ʾ����MD5�Ľ���
	*/
	md5.SetHwnd(m_hWnd);

	//����CProcessCtrl�ؼ�
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
	deque<string> dqSelectFile=fileDlg.GetOpenFileName(FALSE,"�����ļ� (*.*)\0*.*\0\0");
	if(dqSelectFile.size()!=0)
	{
		m_File=dqSelectFile[0];
		SetDlgItemText(IDC_EDIT_SOURCE,m_File.c_str());
	}		
}

void CMyMD5Dlg::OnBtnCalculation() 
{
	//ȡ"����"��ť����,������������Ϊ"ֹͣ",��ֹͣ��ǰ��Ϣ��MD5����
	CString strButton;
	GetDlgItemText(IDC_BTN_CALCULATION,strButton);
	if(strButton=="ֹͣ")
	{
		SetDlgItemText(IDC_EDIT_RESULT,"");
		md5.GetMD5OfFile_Terminate();
		SetDlgItemText(IDC_BTN_CALCULATION,"����");
		((CProgressCtrl*)GetDlgItem(IDC_PROGRESS))->ShowWindow(SW_HIDE);
		return;
	}

	//��ս���ı���
	SetDlgItemText(IDC_EDIT_RESULT,"");

	//��ȡ������MD5��ԭ��Ϣ����
	CString strInput;
	GetDlgItemText(IDC_EDIT_SOURCE,strInput);

	//���ԭ��Ϣ����Ϊ�ַ���
	if(((CComboBox*)GetDlgItem(IDC_COMBO_TYPE))->GetCurSel()==0)
	{
		SetDlgItemText(IDC_EDIT_RESULT,
			md5.GetMD5OfString((LPSTR)(LPCTSTR)strInput,true).c_str());
	}
	//���ԭ��Ϣ����Ϊ�ļ�
	else if(((CComboBox*)GetDlgItem(IDC_COMBO_TYPE))->GetCurSel()==1)
	{
		//����ļ�Ϊ��,��ʾѡ���ļ��Ի���
		if(m_File.empty())
		{
			OnBtnSelect();
			return ;
		}
		//˨���ļ��Ƿ����
		else if( (_access((char*)(LPCTSTR)strInput, 0 )) == -1 )
		{
			AfxMessageBox("�ļ�������!");
			return ;
		}
		else
		{
			//�����ļ���С
			unsigned long FileSize=0xFFFFFFFF;
			WIN32_FIND_DATA  win32_find_data;
			HANDLE hFile;
			if((hFile=FindFirstFile((char*)(LPCTSTR)strInput,&win32_find_data))!=INVALID_HANDLE_VALUE)
			{
				FindClose(hFile);
				if(FileSize=win32_find_data.nFileSizeLow,FileSize==0xFFFFFFFF || FileSize==0)
					return ;
			}

			//�ļ����ڵ���10M,��ʾ���������
			if(FileSize>=10485760)
			{
				//��ʾ���������
				m_Processing.SetPos(0);
				((CProgressCtrl*)GetDlgItem(IDC_PROGRESS))->ShowWindow(SW_SHOW);

				//��"����"��ť�ϵ����ֱ��"ֹͣ"
				SetDlgItemText(IDC_BTN_CALCULATION,"ֹͣ");

				//����һ���߳����ڼ���MD5,������ɼ�������
				hThread= CreateThread(NULL,0,
				(LPTHREAD_START_ROUTINE)m_thunk.CallBack(this,
				&CMyMD5Dlg::ProcessingThread,ZThunk::THISCALL),
				0,0,&dwThreadId);
			}
			//�ļ�С��10M,ֱ�ӽ���MD5����,�������߳�,��Ϊ����ʱ��ܶ�
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

//����WM_RETURN(�س�)��WM_VK_ESCAPE(ȡ��)
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

//��ԭ��Ϣ���͸ı�ʱ,���ػ���ʾ"���"�ļ���ť
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
		//����CProcessCtrl�ؼ�
		((CProgressCtrl*)GetDlgItem(IDC_PROGRESS))->ShowWindow(SW_HIDE);
		//��"ֹͣ"��ť�ϵ����ֱ��"����"
		SetDlgItemText(IDC_BTN_CALCULATION,"����");
	}
	return 1;
}
