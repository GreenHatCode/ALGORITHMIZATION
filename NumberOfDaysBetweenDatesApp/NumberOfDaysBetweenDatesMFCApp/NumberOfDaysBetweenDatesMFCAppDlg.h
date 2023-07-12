
// NumberOfDaysBetweenDatesMFCAppDlg.h : header file
//

#pragma once


// CNumberOfDaysBetweenDatesMFCAppDlg dialog
class CNumberOfDaysBetweenDatesMFCAppDlg : public CDialog
{
// Construction
public:
	CNumberOfDaysBetweenDatesMFCAppDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NUMBEROFDAYSBETWEENDATESMFCAPP_DIALOG };
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
	CString Data1;
	CString E1;
	afx_msg void OnBnClickedButton1();
	bool DATACHECK1 = false;
	bool DATACHECK2 = false;
	int DaysFromYearToYear(int Data1Day, int Data1Month, int Data1Year, int Data2Day, int Data2Month, int Data2Year);
	bool IsDayLaterThan(int Data1Day, int Data1Month, int Data1Year, int Data2Day, int Data2Month, int Data2Year);
	bool IsYearLeap(int year);

	CString Data2;
};
