// ��ҵDlg.h : header file
//

#if !defined(AFX_DLG_H__3A0D36D9_6809_4B1E_8A8C_BE54037C83F5__INCLUDED_)
#define AFX_DLG_H__3A0D36D9_6809_4B1E_8A8C_BE54037C83F5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog

class CMyDlg : public CDialog
{
// Construction
public:
	CMyDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMyDlg)
	enum { IDD = IDD_MY_DIALOG };
	CTreeCtrl	m_pTree;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMyDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
//	afx_msg void OnChangeEdit1();
	afx_msg void OnButton1();
	afx_msg void OnAbout();
	afx_msg void OnMenuitem32771();
	afx_msg void OnMenuitem32775();
	afx_msg void OnMenuitem32774();
	afx_msg void OnMenuitem32773();
	afx_msg void OnButton2();
	afx_msg void OnMenuitem32772();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnSANLIAN();
//	afx_msg void OnClickTree1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
//	void OnTimer();
	afx_msg void OnBnClickedCancel();
	afx_msg void Onquit();
//	afx_msg void OnTvnSelchangedTree1(NMHDR* pNMHDR, LRESULT* pResult);
//	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedMfcbutton1();
	afx_msg void OnBnClickedMfcbutton2();
	afx_msg void OnBnClickedMfcbutton3();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_H__3A0D36D9_6809_4B1E_8A8C_BE54037C83F5__INCLUDED_)
