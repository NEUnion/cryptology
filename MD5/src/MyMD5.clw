; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMyMD5Dlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MyMD5.h"

ClassCount=4
Class1=CMyMD5App
Class2=CMyMD5Dlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CProcessingDlg
Resource3=IDD_MYMD5_DIALOG

[CLS:CMyMD5App]
Type=0
HeaderFile=MyMD5.h
ImplementationFile=MyMD5.cpp
Filter=N

[CLS:CMyMD5Dlg]
Type=0
HeaderFile=MyMD5Dlg.h
ImplementationFile=MyMD5Dlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_PROGRESS

[CLS:CAboutDlg]
Type=0
HeaderFile=MyMD5Dlg.h
ImplementationFile=MyMD5Dlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MYMD5_DIALOG]
Type=1
Class=CMyMD5Dlg
ControlCount=12
Control1=IDC_COMBO_TYPE,combobox,1344339971
Control2=IDC_EDIT_SOURCE,edit,1350631552
Control3=IDC_BTN_SELECT,button,1342242816
Control4=IDC_BTN_CALCULATION,button,1342242816
Control5=IDC_BTN_ABOUT,button,1342242816
Control6=IDOK,button,1342242816
Control7=IDC_EDIT_RESULT,edit,1350633600
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,button,1342177287
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_PROGRESS,msctls_progress32,1350565889

[CLS:CProcessingDlg]
Type=0
HeaderFile=ProcessingDlg.h
ImplementationFile=ProcessingDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CProcessingDlg
VirtualFilter=dWC

