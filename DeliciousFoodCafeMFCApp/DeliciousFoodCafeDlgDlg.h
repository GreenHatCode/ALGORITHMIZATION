
// DeliciousFoodCafeDlgDlg.h : header file
//

#pragma once


// CDeliciousFoodCafeDlgDlg dialog
class CDeliciousFoodCafeDlgDlg : public CDialog
{
// Construction
public:
	CDeliciousFoodCafeDlgDlg(CWnd* pParent = nullptr);	// standard constructor
	int mouse_positionX = 0;
	int mouse_positionY = 0;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DELICIOUSFOODCAFEDLG_DIALOG };
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

private:
	HPEN hPenOxy, hOldPen, pen;
	CRect rc;
	COLORREF cf;
	HFONT hold, hNew, hbk;
	HBRUSH m, oldm, brush;

public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	CStatic BigPicScreen;





};
