; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDecryptKeyDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "RSAWANG.h"

ClassCount=5
Class1=CRSAWANGApp
Class2=CRSAWANGDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_RSAWANG_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_DIALOG1
Class4=CKeyDlg
Resource4=IDD_ABOUTBOX
Class5=CDecryptKeyDlg
Resource5=IDD_DIALOG2

[CLS:CRSAWANGApp]
Type=0
HeaderFile=RSAWANG.h
ImplementationFile=RSAWANG.cpp
Filter=N

[CLS:CRSAWANGDlg]
Type=0
HeaderFile=RSAWANGDlg.h
ImplementationFile=RSAWANGDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_ENCRYPTSTRING

[CLS:CAboutDlg]
Type=0
HeaderFile=RSAWANGDlg.h
ImplementationFile=RSAWANGDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_RSAWANG_DIALOG]
Type=1
Class=CRSAWANGDlg
ControlCount=18
Control1=IDC_ENCRYPT,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_SOURCESTRING,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_ENCRYPTSTRING,edit,1350633600
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_DECRYPTSTRING,edit,1350633600
Control9=IDC_DECRYPT,button,1342242816
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_PUBLICKEY,edit,1350633600
Control14=IDC_PRIVATEKEY,edit,1350633600
Control15=IDC_STATIC,static,1342308352
Control16=IDC_GENERATEKEY,button,1342242816
Control17=IDC_R,edit,1350633600
Control18=IDC_STATIC,static,1342308352

[DLG:IDD_DIALOG1]
Type=1
Class=CKeyDlg
ControlCount=5
Control1=IDC_ENCRYPTKEY,button,1342242817
Control2=IDC_INPUTENCRYPTKEY,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_INPUTMODER,edit,1350631552

[CLS:CKeyDlg]
Type=0
HeaderFile=KeyDlg.h
ImplementationFile=KeyDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_EDIT1

[DLG:IDD_DIALOG2]
Type=1
Class=CDecryptKeyDlg
ControlCount=5
Control1=IDC_DECRYPTKEY,button,1342242817
Control2=IDC_STATIC,static,1342308352
Control3=IDC_INPUTDECRYPTKEY,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_INPUTMODER1,edit,1350631552

[CLS:CDecryptKeyDlg]
Type=0
HeaderFile=DecryptKeyDlg.h
ImplementationFile=DecryptKeyDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CDecryptKeyDlg

