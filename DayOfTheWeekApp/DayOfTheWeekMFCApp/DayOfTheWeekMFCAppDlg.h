
// DayOfTheWeekMFCAppDlg.h : header file
//

#pragma once


// CDayOfTheWeekMFCAppDlg dialog
class CDayOfTheWeekMFCAppDlg : public CDialog
{
// Construction
public:
	CDayOfTheWeekMFCAppDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DAYOFTHEWEEKMFCAPP_DIALOG };
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
	CString InputData;
	afx_msg void OnBnClickedButton1();
	CString E1;
	bool DataCheck = false;

	int DaysFromYearToYear(int Data1Day, int Data1Month, int Data1Year, int Data2Day, int Data2Month, int Data2Year);
	bool IsDayLaterThan(int Data1Day, int Data1Month, int Data1Year, int Data2Day, int Data2Month, int Data2Year);
	bool IsYearLeap(int year);
	int AmountOfDaysBetweenTwoDatas(int Data1Day, int Data1Month, int Data1Year, int Data2Day, int Data2Month, int Data2Year);
	void DayOfTheWeek(int DataDay, int DataMonth, int DataYear);
	virtual void OnOK();
};
