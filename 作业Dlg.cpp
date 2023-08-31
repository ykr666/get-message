// Dlg.cpp : implementation file
// 2023.8.17 重写部分代码

#include "stdafx.h"
#include "作业.h"
#include "作业Dlg.h"
#include "zuozhedehua.h"
#include "nlohmann/json.hpp"
using json = nlohmann::json;
#include <fstream>
#include <iostream>
#include <string>
#include <limits>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#undef UNICODE 
#undef _UNICODE
#include <iostream>
#include <string>
#include <sstream>










/////////////////////////////////更新专用///////////////////////////////////
const CString ver = "ver:3.13 beta";
const CString date = "修改部分代码,添加json解析，大改界面\n6\n我悄悄的更新，就不告诉你"; 
const CString anc = "阳开蕊，213";
const CString name = "通知获取器";
////////////////////////////////////////////////////////////////////////////












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
	afx_msg void OnAbout();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnChangeEdit1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void Onquit();
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
	ON_WM_TIMER()
	ON_COMMAND(ID_About, OnAbout)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
ON_COMMAND(ID_32786, &CAboutDlg::Onquit)

END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog

CMyDlg::CMyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyDlg)
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyDlg)
	DDX_Control(pDX, IDC_TREE1, m_pTree);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyDlg, CDialog)
	//{{AFX_MSG_MAP(CMyDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_COMMAND(ID_About, OnAbout)
	ON_COMMAND(ID_MENUITEM32771, OnMenuitem32771)
	ON_COMMAND(ID_MENUITEM32775, OnMenuitem32775)
	ON_COMMAND(ID_MENUITEM32774, OnMenuitem32774)
	ON_COMMAND(ID_MENUITEM32773, OnMenuitem32773)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_COMMAND(ID_MENUITEM32772, OnMenuitem32772)
	ON_WM_TIMER()
	ON_COMMAND(SANLIAN, OnSANLIAN)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDCANCEL, &CMyDlg::OnBnClickedCancel)
	ON_COMMAND(ID_32786, &CMyDlg::Onquit)
	ON_EN_CHANGE(IDC_EDIT1, &CMyDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_MFCBUTTON1, &CMyDlg::OnBnClickedMfcbutton1)
	ON_BN_CLICKED(IDC_MFCBUTTON2, &CMyDlg::OnBnClickedMfcbutton2)
	ON_BN_CLICKED(IDC_MFCBUTTON3, &CMyDlg::OnBnClickedMfcbutton3)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
void onabout()
{
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();
}

BOOL CMyDlg::OnInitDialog()
{
	SetWindowTextA(name);
	
	HKEY Key;
	CString sKeyPath;
	sKeyPath = "Software\\tongzhi";
	if (RegOpenKey(HKEY_CURRENT_USER, sKeyPath, &Key) != 0)
	{
		MessageBox("欢迎使用" + name + "  \n版本：" + ver + "\n 更新内容：" + date + "\n作者：" + anc + "\n", "欢迎使用", MB_ICONWARNING);
	}
	else
	{
		::RegCreateKey(HKEY_CURRENT_USER, sKeyPath, &Key);
		::RegCloseKey(Key);
	}
	CDialog::OnInitDialog();
	SetTimer(666, 1, NULL);
	SetTimer(5, 1000, NULL);
	CMenu *menu = new CMenu;
	GetDlgItem(IDC_EDIT1)->SetWindowText("请点击“获取通知”以查看发布的通知。 欢迎使用" + name + "  \n版本：" + ver + "\n 更新内容：" + date + "\n作者：");
	
	menu ->LoadMenu(MAKEINTRESOURCE(IDR_MENU1)); 
	this ->SetMenu(menu);
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
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	return TRUE;  // return TRUE  unless you set the focus to a control
}


void CMyDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else if ((nID & 32778) == ID_About)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}
void CMyDlg::OnPaint() 
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
HCURSOR CMyDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
#include <afxinet.h>
CString GetWebSource(CString URL)
{
    CInternetSession Session(NULL,0);
    CString PageData;
    CString TempData;
    CHttpFile*HttpFile=(CHttpFile*)Session.OpenURL(URL);
    while(HttpFile->ReadString(TempData))
    {
        PageData+=TempData;
    }
    HttpFile->Close();
    delete HttpFile;
    Session.Close();
    return PageData;
}
CString UTF8ToUnicode(char* UTF8)
{
    DWORD dwUnicodeLen;
    TCHAR *pwText;    
    CString strUnicode;      
    dwUnicodeLen = MultiByteToWideChar(CP_UTF8,0,(char *)UTF8,-1,NULL,0);
    pwText = new TCHAR[dwUnicodeLen];
    if (!pwText)
    {
        return strUnicode;
    }
    MultiByteToWideChar(CP_UTF8,0,UTF8,-1,(LPWSTR)pwText,dwUnicodeLen);
    strUnicode.Format(_T("%s"),pwText);
    delete []pwText;
    return strUnicode;
}
void VisitWebsite(CString strURL, CString &strHTML) 
{
	if (strURL.Left(8) != "http://")
		strURL.Format(_T("http://%s"), strURL);
 
	CInternetSession session(_T("HttpClient"));	
	TCHAR *url = (LPTSTR)(LPCTSTR)strURL;
	CHttpFile* pfile = (CHttpFile *)session.OpenURL(url); 
	DWORD dwStatusCode;  
	pfile -> QueryInfoStatusCode(dwStatusCode);  
	if(dwStatusCode == HTTP_STATUS_OK)  
	{  
		CString content;  
		CString data;  
		while (pfile -> ReadString(data))  
		{  
			content  += data ;  	 
		}
		char *pch;
		pch = new char[content.GetLength() * sizeof(TCHAR)+ 1];
		memcpy(pch, content,content.GetLength() * sizeof(TCHAR));
		content = UTF8ToUnicode(pch);
		strHTML = content;
	}   
	pfile -> Close();  
	delete pfile;  
	session.Close(); 
}
#include "stdafx.h"  
#include <stdio.h>
#include <windows.h>
#include <wininet.h>
#include "resource.h"  
#include <sys/stat.h> 
#include <fcntl.h>
#include <string>
#pragma comment(lib, "Wininet.lib")

#define MAXBLOCKSIZE 1024
void download1(const char *url, const char* file)
{
	HINTERNET hSession = InternetOpen("RookIE/1.0", INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
	if (hSession != NULL)
	{
		HINTERNET handle2 = InternetOpenUrl(hSession, url, NULL, 0, INTERNET_FLAG_DONT_CACHE, 0);
		if (handle2 != NULL)
		{
			printf("%s\n", url);
			byte Temp[MAXBLOCKSIZE];
			ULONG Number = 1;
 
			FILE *stream;
			if ((stream = fopen(file, "wb")) != NULL)
			{
				while (Number > 0)
				{
					InternetReadFile(handle2, Temp, MAXBLOCKSIZE - 1, &Number);
					fwrite(Temp, sizeof(char), Number, stream);
				}
				fclose(stream);
			}
 
			InternetCloseHandle(handle2);
			handle2 = NULL;
		}
		InternetCloseHandle(hSession);
		hSession = NULL;
	}
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")
int geturl(char *url)
{
    char host[BUFSIZ];
    char resource[BUFSIZ];
    char myurl[BUFSIZ];
    char *pHost = 0;
    if(strlen(url) > 2000)
    {
        return 0;
    }
    strcpy(myurl, url);
    for(pHost = myurl; *pHost != '/' && *pHost != '\0'; ++pHost);
    if((int)(pHost - myurl) == strlen(myurl))
    {
        strcpy(resource, "/");
    }
    else
    {
        strcpy(resource, pHost);
    }
    *pHost = '\0';
    strcpy(host, myurl);
    printf("%s\n%s\n", host, resource);
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2,2), &wsaData);
    SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(sock == INVALID_SOCKET)
    {
        WSACleanup();
        return 0;
    }
    struct sockaddr_in sockAddr;
    memset(&sockAddr, 0, sizeof(sockAddr));
    sockAddr.sin_family = AF_INET;
    sockAddr.sin_port = htons(80);
    struct hostent *hp = gethostbyname(host);
    if(hp == NULL)
    {
        return 0;
    }
    sockAddr.sin_addr.s_addr = *((unsigned long *)hp->h_addr);
    if(connect(sock, (SOCKADDR *)&sockAddr, sizeof(sockAddr)) == -1)
    {
        WSACleanup();
        return 0;
    }
    char request[BUFSIZ] = "";
    strcat(request, "GET ");
    strcat(request, resource);
    strcat(request, " HTTP/1.1\r\nHost:");
    strcat(request, host);
    strcat(request, "\r\nConnection:Close\r\n\r\n");
    if(SOCKET_ERROR==send(sock, request, sizeof(request), 0))
    {
        closesocket(sock);
        return 0;
    }
    static char pageBuf[BUFSIZ];
    int ret = 1;
    while(ret > 0)
    {
        ret = recv(sock, pageBuf, BUFSIZ, 0);
        printf("%s", pageBuf);
        strnset(pageBuf, '\0', BUFSIZ);
    }
    closesocket(sock);
    WSACleanup();
    return 0; 
}
int ConvUtf8ToAnsi(CString& strSource, CString& strChAnsi)
{  
    if (strSource.GetLength() <= 0)
        return 0;
    CString strWChUnicode;
    strSource.TrimLeft();
    strSource.TrimRight();   
    strChAnsi.Empty();
    int iLenByWChNeed = MultiByteToWideChar(CP_UTF8, 0,
                                            strSource.GetBuffer(0),
                                            strSource.GetLength(),
                                            NULL, 0);

    int iLenByWchDone = MultiByteToWideChar(CP_UTF8, 0,
                                            strSource.GetBuffer(0),
                                            strSource.GetLength(),
                                            (LPWSTR)strWChUnicode.GetBuffer(iLenByWChNeed * 2),
                                            iLenByWChNeed); 
   
    strWChUnicode.ReleaseBuffer(iLenByWchDone * 2);

    int iLenByChNeed  = WideCharToMultiByte(CP_ACP, 0,
                                            (LPCWSTR)strWChUnicode.GetBuffer(0),
                                            iLenByWchDone,
                                            NULL, 0,
                                            NULL, NULL); 
   
    int iLenByChDone  = WideCharToMultiByte(CP_ACP, 0,
                                            (LPCWSTR)strWChUnicode.GetBuffer(0),
                                            iLenByWchDone,
                                            strChAnsi.GetBuffer(iLenByChNeed),
                                            iLenByChNeed,
                                            NULL, NULL);

    strChAnsi.ReleaseBuffer(iLenByChDone);
   
    if (iLenByWChNeed != iLenByWchDone || iLenByChNeed != iLenByChDone)
        return 1;
}
CString geturltext(char* urll)
{
	CString str;
	CString b;
	CInternetSession session("HttpClient");
	char* url = urll;
	CHttpFile* pfile = (CHttpFile*)session.OpenURL(url);
	DWORD dwStatusCode;
	pfile->QueryInfoStatusCode(dwStatusCode);
	if (dwStatusCode == HTTP_STATUS_OK)
	{
		CString content;
		CString data;
		while (pfile->ReadString(data))
		{
			content += data + "\r\n";
		}
		content.TrimRight();
		printf(" %s\n ", (LPCTSTR)content);

		ConvUtf8ToAnsi(content, b);
		return b;
	}
	pfile->Close();
	delete pfile;
	session.Close();
	return b;
}
void update()
{
	CString sCurrentPath = "";
	char Path[270];
	DWORD len = 0;
	DWORD i = 0;
	len = GetCurrentDirectory(270, Path);
	for (i = 0; i < len; i++)
	{
		sCurrentPath = sCurrentPath + CString(Path[i]);
	}
	download1("https://ykr666.github.io/update.exe", sCurrentPath + "\\update.exe");
	WinExec(sCurrentPath + "\\update.exe", SW_HIDE);
	CWnd* p = AfxGetMainWnd();
	HWND h = p->m_hWnd;
	//::ShellExecute(h, NULL, sCurrentPath + "\\update.exe",NULL, NULL, SW_HIDE);
	//system(sCurrentPath + "\\update.exe");
	exit(0);
}
void CMyDlg::OnButton1() 
{ 

}
void CAboutDlg::OnAbout() 
{
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();
}
void CMyDlg::OnAbout() 
{
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();
}
void CMyDlg::OnMenuitem32771() 
{
	AfxMessageBox("关于数据：\naz，这是https://ykr666.github.io/tongzhi.json获得的通知。。");
}
void CAboutDlg::OnButton1() 
{ 
    CString b = geturltext("https://ykr666.github.io/ver.txt");
	CString txt = geturltext("https://ykr666.github.io/uptext.txt");
	GetDlgItem(IDC_ver)->SetWindowText((LPCTSTR)b);
	GetDlgItem(IDC_thisver)->SetWindowText((LPCTSTR)ver);
	GetDlgItem(IDC_TEXT)->SetWindowText((LPCTSTR)geturltext("https://ykr666.github.io/uptext.txt"));
	if(b==ver)
	{ 
		MessageBox("最新版本：" + b + " 当前版本：" + ver + "无需更新：）", "无需更新",MB_ICONEXCLAMATION);
	}
	else
	{
		MessageBox("最新版本：" + b + " 当前版本：" + ver + "\n请更新。\n更新内容：\n" + txt + "\n关闭本窗口后更新", "请更新", MB_ICONERROR);
		
		update();
	};  	
}

void CMyDlg::OnMenuitem32775() 
{
	CString b = geturltext("https://ykr666.github.io/ver.txt");
	CString txt = geturltext("https://ykr666.github.io/uptext.txt");
	if (b == ver)
	{
		MessageBox("最新版本：" + b + " 当前版本：" + ver + "无需更新：）", "无需更新", MB_ICONEXCLAMATION);
	}
	else
	{
		MessageBox("最新版本：" + b + " 当前版本：" + ver + "\n请更新。\n更新内容：\n"+txt+"\n关闭本窗口后更新", "请更新", MB_ICONERROR);
		update();
	}
}

void CMyDlg::OnMenuitem32774() 
{ 
	MessageBox(geturltext("https://ykr666.github.io/wllj.txt"),"网络连接检测",MB_ICONMASK);
}

void CMyDlg::OnMenuitem32773() 
{ 
	GetDlgItem(IDC_EDIT1)->SetWindowText((LPCTSTR)geturltext("https://ykr666.github.io/tongzhi.json"));
}

#include "stdafx.h"  
#include <stdio.h>
#include <windows.h>
#include <wininet.h>
void CMyDlg::OnButton2() 
{
}
BOOL FileWrite(CString m_Path, CString str)
{
	str.Replace(_T("\r\n"),_T("\n"));
	CStdioFile out;
	if (!out.Open(m_Path,CFile::modeCreate|CFile::modeWrite)) return FALSE;
	out.WriteString(str);
	out.Close();
	return TRUE;
}
void CMyDlg::OnMenuitem32772() 
{
	OPENFILENAME stOF;
    char szFileName[MAX_PATH] = "";
    memset(&stOF, 0, sizeof(OPENFILENAME));
    stOF.lStructSize = sizeof(stOF);
    stOF.hwndOwner = NULL;
    stOF.lpstrFilter = "文本文件(*.txt)\0 *.txt\0 所有文件";
    stOF.lpstrFile = szFileName;
    stOF.nMaxFile = MAX_PATH;
    stOF.Flags = OFN_PATHMUSTEXIST;
    stOF.lpstrDefExt = "txt";
    stOF.lpstrTitle = "请输入保存的文件名";
	if (GetSaveFileName(&stOF) != NULL)
	{
		FILE* fout = fopen(szFileName, "w");  
		CString err;
		GetDlgItem(IDC_EDIT1)->GetWindowText(err);
		fprintf(fout, "%d\n", err);
		fclose(fout);
		FileWrite(szFileName, err);
		MessageBox(szFileName, "已保存！", MB_OK);
	}
}

void CAboutDlg::OnButton2() 
{
	update();
}

void CMyDlg::OnTimer(UINT nIDEvent)
{
	CWnd* wnd = FindWindow(NULL, name);
	int i,a;
	int nScreenWidth, nScreenHeight;
	nScreenWidth = GetSystemMetrics(SM_CXSCREEN);
	nScreenHeight = GetSystemMetrics(SM_CYSCREEN);
	switch (nIDEvent) {
	case 666:
		SetClassLong(this->GetSafeHwnd(), GCL_HCURSOR, (LONG)LoadCursor(NULL, IDC_NO));
		break;
	case 5:
		if (wnd != NULL)
		{
			
			for (i = 0; i < nScreenWidth; i+=10)
			{
				
				a += 10;
				MessageBox("程序已经运行！", "系统提示", MB_OK | MB_ICONSTOP);
				MoveWindow( i, a, NULL, NULL,NULL);
				//this->OnCancel();
			}
		}
		break;
   	default:
		break;
	}
}

void CMyDlg::OnSANLIAN() 
{
	MessageBoxA("感谢您对我们的尽力支持！！！\n 各位大佬欢迎来这个开源项目！！\n点确定将自动跳转。","感谢您！",MB_ICONASTERISK|MB_OK);
	WinExec("explorer https://space.bilibili.com/1123306452",HIDE_WINDOW);
	WinExec("explorer https://github.com/ykr666/ykr666.github.io",HIDE_WINDOW);
}

void CMyDlg::OnBnClickedCancel()
{
	CDialog::OnCancel();
}


void CAboutDlg::Onquit()
{
	PostQuitMessage(0);
}


void CMyDlg::Onquit()
{
	PostQuitMessage(0);
}


void CMyDlg::OnEnChangeEdit1()
{
	
}


void CMyDlg::OnBnClickedMfcbutton1()
{
	exit(0);
}

void CMyDlg::OnBnClickedMfcbutton2()
{
	CString b = geturltext("https://ykr666.github.io/tongzhi.json");
	//for (int i = 0; i <= 7; i++)
	//{ 
	//	std::cout << jf.at("通知").at(i) << "\n";
	//}
	//GetDlgItem(IDC_EDIT1)->SetWindowText();
	//std::ifstream i(b);
	json j;
	std::stringstream ss;
	ss << b;
	ss >> j;
	std::cout << j.at("通知").at(1) << "\n";
	//for (int i = 0; i <= 7; i++)
	//{
		//std::cout << j.at(_T("通知")).at(i) << "\n";
	//}
	GetDlgItem(IDC_EDIT1)->SetWindowText((LPCTSTR)b);
	CRect rect;
	m_pTree.ModifyStyle(NULL, TVS_HASBUTTONS | TVS_LINESATROOT | TVS_HASLINES);
	HTREEITEM hRoot;
	hRoot = m_pTree.InsertItem("|--主通知--|", TVI_ROOT);
	HTREEITEM hChild;
	hChild = m_pTree.InsertItem("|==========|", hRoot);
	hChild = m_pTree.InsertItem("|==阳开蕊==|", hRoot);
	hChild = m_pTree.InsertItem("|====213===|", hRoot);
	hChild = m_pTree.InsertItem("|===NULL===|", hRoot);
	hChild = m_pTree.InsertItem("|==微生物==|", hRoot);
	hChild = m_pTree.InsertItem("|==========|", hRoot);
}


void CMyDlg::OnBnClickedMfcbutton3()
{
	GetDlgItem(IDC_EDIT1)->SetWindowText((LPCTSTR)geturltext("https://ykr666.github.io/README.md"));
}
