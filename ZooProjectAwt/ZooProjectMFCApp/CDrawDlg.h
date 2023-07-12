
// CDrawDlg.h : header file
//

#pragma once


// CCDrawDlg dialog
class CCDrawDlg : public CDialog
{
// Construction
public:
	CCDrawDlg(CWnd* pParent = nullptr);	// standard constructor
	int mouse_positionX=0;
	int mouse_positionY=0;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CDRAW_DIALOG };
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
	CStatic AnimalScreen;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
private:
	bool Jeraf_fg=false,
		 Zebra_fg=false,
		 Lion_fg=false,
		 Hippo_fg=false;
};
