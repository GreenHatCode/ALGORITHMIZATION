
// DefinitionOfLeapYearsMFCAppDlg.h : header file
//

#pragma once


// CDefinitionOfLeapYearsMFCAppDlg dialog
class CDefinitionOfLeapYearsMFCAppDlg : public CDialog
{
// Construction
public:
	CDefinitionOfLeapYearsMFCAppDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DEFINITIONOFLEAPYEARSMFCAPP_DIALOG };
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

private:
	bool DataCheck = false;
	virtual void OnOK();
};
