
// ReadPhoneNumberDlg.h : header file
//

#pragma once


// CReadPhoneNumberDlg dialog
class CReadPhoneNumberDlg : public CDialog
{
// Construction
public:
	CReadPhoneNumberDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_READPHONENUMBER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString INPUT;
	CString OUTPUT;
	afx_msg void OnBnClickedButton1();

private:
	CString input, ms;
	int number_int;
	bool fg1, fg2, fg3, fg4, fg5, fg6, fg7, fg8, fg9, fg0;
};
