; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMyDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "作业.h"

ClassCount=4
Class1=CMyApp
Class2=CMyDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_MY_DIALOG
Resource4=IDD_ZUOZHEDEHUA_DIALOG
Class4=zuozhedehua
Resource5=IDR_MENU1

[CLS:CMyApp]
Type=0
HeaderFile=作业.h
ImplementationFile=作业.cpp
Filter=N

[CLS:CMyDlg]
Type=0
HeaderFile=作业Dlg.h
ImplementationFile=作业Dlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_BUTTON1

[CLS:CAboutDlg]
Type=0
HeaderFile=作业Dlg.h
ImplementationFile=作业Dlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=SANLIAN

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=12
Control1=IDC_STATIC,static,1342177283
Control2=IDC_TAB1,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_BUTTON1,button,1342242816
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_ver,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_thisver,static,1342308352
Control11=IDC_BUTTON2,button,1342242816
Control12=IDC_TEXT,static,1342308352

[DLG:IDD_MY_DIALOG]
Type=1
Class=CMyDlg
ControlCount=11
Control1=IDCANCEL,button,1073807360
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT1,edit,1353779396
Control4=IDC_BUTTON1,button,1073807360
Control5=IDC_BUTTON2,button,1073807360
Control6=IDC_TREE1,SysTreeView32,1351682055
Control7=IDC_TAB1,SysTabControl32,1342177280
Control8=IDC_MFCVSLISTBOX2,MfcVSListBox,1342242816
Control9=IDC_MFCBUTTON1,MfcButton,1342242816
Control10=IDC_MFCBUTTON2,MfcButton,1342373889
Control11=IDC_MFCBUTTON3,MfcButton,1342373889

[MNU:IDR_MENU1]
Type=1
Class=CAboutDlg
Command1=ID_32781
Command2=ID_32782
Command3=ID_MENUITEM32772
Command4=ID_32784
Command5=ID_32785
Command6=ID_32786
Command7=ID_MENUITEM32773
Command8=ID_MENUITEM32774
Command9=ID_MENUITEM32775
Command10=ID_About
Command11=SANLIAN
CommandCount=11

[DLG:IDD_ZUOZHEDEHUA_DIALOG]
Type=1
Class=zuozhedehua
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDC_EDIT1,edit,1350633604

[CLS:zuozhedehua]
Type=0
HeaderFile=zuozhedehua.h
ImplementationFile=zuozhedehua.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

