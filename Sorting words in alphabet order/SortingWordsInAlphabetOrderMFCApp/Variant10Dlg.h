
// Variant10Dlg.h : header file
//

#pragma once


// CVariant10Dlg dialog
class CVariant10Dlg : public CDialog
{
// Construction
public:
	CVariant10Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_VARIANT10_DIALOG };
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
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CString OUTPUT;

	CString input_string, ms, t;
	CString alphabet_string, in_order_string;
	int word_counter = 0;
	char alphabet[5];
	char words[90][10];
	char word_buffer[1][10];
	char letter_arr[33];
	bool fg = false;
	
	afx_msg void OnMenuClear();
};
