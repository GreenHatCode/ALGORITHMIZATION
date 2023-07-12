
// DeliciousFoodCafeDlgDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "DeliciousFoodCafeDlg.h"
#include "DeliciousFoodCafeDlgDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDeliciousFoodCafeDlgDlg dialog



CDeliciousFoodCafeDlgDlg::CDeliciousFoodCafeDlgDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DELICIOUSFOODCAFEDLG_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDeliciousFoodCafeDlgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PIC, BigPicScreen);
}

BEGIN_MESSAGE_MAP(CDeliciousFoodCafeDlgDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CDeliciousFoodCafeDlgDlg message handlers

BOOL CDeliciousFoodCafeDlgDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDeliciousFoodCafeDlgDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CClientDC dc(this);
		GetClientRect(&rc);
		/*int x1, y1, x2, y2;

		x1 = 674;
		y1 = 339;
		x2 = x1 + 90;
		y2 = y1 + 92;*/

		dc.FillSolidRect(&rc, RGB(255, 255, 255)); // заливка планшета одним цветом

		//dc.Rectangle(x1, y1, x2, y2);
		//dc.MoveTo(x1, y1);
		//dc.LineTo(x2, y1);
		///dc.LineTo(x2, y2);
		//dc.LineTo(x1, y2);
		//dc.LineTo(x1, y1);


		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDeliciousFoodCafeDlgDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDeliciousFoodCafeDlgDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	GetClientRect(&rc);
	int x1, y1, x2, y2;

	cf = RGB(179, 53, 166);
	hPenOxy = CreatePen(PS_SOLID, 3, cf);
	hOldPen = (HPEN)SelectObject(dc, hPenOxy);

	mouse_positionX = 0;
	mouse_positionY = 0;

	mouse_positionX = point.x;
	mouse_positionY = point.y;

	if ((562 <= mouse_positionX && mouse_positionX <= 652) && (25 <= mouse_positionY && mouse_positionY <= 117))
	{
		x1 = 562;
		y1 = 25;
		x2 = x1 + 90;
		y2 = y1 + 92;

		dc.MoveTo(x1, y1);
		dc.LineTo(x2, y1);
		dc.LineTo(x2, y2);
		dc.LineTo(x1, y2);
		dc.LineTo(x1, y1);
	}
	if ((562 <= mouse_positionX && mouse_positionX <= 652) && (129 <= mouse_positionY && mouse_positionY <= 221))
	{
		x1 = 562;
		y1 = 129;
		x2 = x1 + 90;
		y2 = y1 + 92;

		dc.MoveTo(x1, y1);
		dc.LineTo(x2, y1);
		dc.LineTo(x2, y2);
		dc.LineTo(x1, y2);
		dc.LineTo(x1, y1);
	}
	if ((562 <= mouse_positionX && mouse_positionX <= 652) && (234 <= mouse_positionY && mouse_positionY <= 326))
	{
		x1 = 562;
		y1 = 234;
		x2 = x1 + 90;
		y2 = y1 + 92;

		dc.MoveTo(x1, y1);
		dc.LineTo(x2, y1);
		dc.LineTo(x2, y2);
		dc.LineTo(x1, y2);
		dc.LineTo(x1, y1);
	}
	if ((562 <= mouse_positionX && mouse_positionX <= 652) && (339 <= mouse_positionY && mouse_positionY <= 431))
	{
		x1 = 562;
		y1 = 339;
		x2 = x1 + 90;
		y2 = y1 + 92;

		dc.MoveTo(x1, y1);
		dc.LineTo(x2, y1);
		dc.LineTo(x2, y2);
		dc.LineTo(x1, y2);
		dc.LineTo(x1, y1);
	}
	if ((674 <= mouse_positionX && mouse_positionX <= 764) && (24 <= mouse_positionY && mouse_positionY <= 116))
	{
		x1 = 674;
		y1 = 24;
		x2 = x1 + 90;
		y2 = y1 + 92;

		dc.MoveTo(x1, y1);
		dc.LineTo(x2, y1);
		dc.LineTo(x2, y2);
		dc.LineTo(x1, y2);
		dc.LineTo(x1, y1);
	}
	if ((674 <= mouse_positionX && mouse_positionX <= 764) && (129 <= mouse_positionY && mouse_positionY <= 221))
	{
		x1 = 674;
		y1 = 129;
		x2 = x1 + 90;
		y2 = y1 + 92;

		dc.MoveTo(x1, y1);
		dc.LineTo(x2, y1);
		dc.LineTo(x2, y2);
		dc.LineTo(x1, y2);
		dc.LineTo(x1, y1);
	}
	if ((674 <= mouse_positionX && mouse_positionX <= 764) && (234 <= mouse_positionY && mouse_positionY <= 326))
	{
		x1 = 674;
		y1 = 234;
		x2 = x1 + 90;
		y2 = y1 + 92;

		dc.MoveTo(x1, y1);
		dc.LineTo(x2, y1);
		dc.LineTo(x2, y2);
		dc.LineTo(x1, y2);
		dc.LineTo(x1, y1);
	}
	if ((674 <= mouse_positionX && mouse_positionX <= 764) && (339 <= mouse_positionY && mouse_positionY <= 431))
	{
		x1 = 674;
		y1 = 339;
		x2 = x1 + 90;
		y2 = y1 + 92;

		dc.MoveTo(x1, y1);
		dc.LineTo(x2, y1);
		dc.LineTo(x2, y2);
		dc.LineTo(x1, y2);
		dc.LineTo(x1, y1);
	}


	if (!((562 <= mouse_positionX && mouse_positionX <= 652) && (25 <= mouse_positionY && mouse_positionY <= 117)))
	{
		x1 = 562;
		y1 = 25;
		x2 = x1 + 90;
		y2 = y1 + 92;

		cf = RGB(255, 255, 255);
		hPenOxy = CreatePen(PS_SOLID, 3, cf);
		hOldPen = (HPEN)SelectObject(dc, hPenOxy);

		dc.MoveTo(x1, y1);
		dc.LineTo(x2, y1);
		dc.LineTo(x2, y2);
		dc.LineTo(x1, y2);
		dc.LineTo(x1, y1);
	}
	if (!((562 <= mouse_positionX && mouse_positionX <= 652) && (129 <= mouse_positionY && mouse_positionY <= 221)))
	{
		x1 = 562;
		y1 = 129;
		x2 = x1 + 90;
		y2 = y1 + 92;

		cf = RGB(255, 255, 255);
		hPenOxy = CreatePen(PS_SOLID, 3, cf);
		hOldPen = (HPEN)SelectObject(dc, hPenOxy);

		dc.MoveTo(x1, y1);
		dc.LineTo(x2, y1);
		dc.LineTo(x2, y2);
		dc.LineTo(x1, y2);
		dc.LineTo(x1, y1);
	}
	if (!((562 <= mouse_positionX && mouse_positionX <= 652) && (234 <= mouse_positionY && mouse_positionY <= 326)))
	{
		x1 = 562;
		y1 = 234;
		x2 = x1 + 90;
		y2 = y1 + 92;

		cf = RGB(255, 255, 255);
		hPenOxy = CreatePen(PS_SOLID, 3, cf);
		hOldPen = (HPEN)SelectObject(dc, hPenOxy);

		dc.MoveTo(x1, y1);
		dc.LineTo(x2, y1);
		dc.LineTo(x2, y2);
		dc.LineTo(x1, y2);
		dc.LineTo(x1, y1);
	}
	if (!((562 <= mouse_positionX && mouse_positionX <= 652) && (339 <= mouse_positionY && mouse_positionY <= 431)))
	{
		x1 = 562;
		y1 = 339;
		x2 = x1 + 90;
		y2 = y1 + 92;

		cf = RGB(255, 255, 255);
		hPenOxy = CreatePen(PS_SOLID, 3, cf);
		hOldPen = (HPEN)SelectObject(dc, hPenOxy);

		dc.MoveTo(x1, y1);
		dc.LineTo(x2, y1);
		dc.LineTo(x2, y2);
		dc.LineTo(x1, y2);
		dc.LineTo(x1, y1);
	}
	if (!((674 <= mouse_positionX && mouse_positionX <= 764) && (24 <= mouse_positionY && mouse_positionY <= 116)))
	{
		x1 = 674;
		y1 = 24;
		x2 = x1 + 90;
		y2 = y1 + 92;

		cf = RGB(255, 255, 255);
		hPenOxy = CreatePen(PS_SOLID, 3, cf);
		hOldPen = (HPEN)SelectObject(dc, hPenOxy);

		dc.MoveTo(x1, y1);
		dc.LineTo(x2, y1);
		dc.LineTo(x2, y2);
		dc.LineTo(x1, y2);
		dc.LineTo(x1, y1);
	}
	if (!((674 <= mouse_positionX && mouse_positionX <= 764) && (129 <= mouse_positionY && mouse_positionY <= 221)))
	{
		x1 = 674;
		y1 = 129;
		x2 = x1 + 90;
		y2 = y1 + 92;

		cf = RGB(255, 255, 255);
		hPenOxy = CreatePen(PS_SOLID, 3, cf);
		hOldPen = (HPEN)SelectObject(dc, hPenOxy);

		dc.MoveTo(x1, y1);
		dc.LineTo(x2, y1);
		dc.LineTo(x2, y2);
		dc.LineTo(x1, y2);
		dc.LineTo(x1, y1);
	}
	if (!((674 <= mouse_positionX && mouse_positionX <= 764) && (234 <= mouse_positionY && mouse_positionY <= 326)))
	{
		x1 = 674;
		y1 = 234;
		x2 = x1 + 90;
		y2 = y1 + 92;

		cf = RGB(255, 255, 255);
		hPenOxy = CreatePen(PS_SOLID, 3, cf);
		hOldPen = (HPEN)SelectObject(dc, hPenOxy);

		dc.MoveTo(x1, y1);
		dc.LineTo(x2, y1);
		dc.LineTo(x2, y2);
		dc.LineTo(x1, y2);
		dc.LineTo(x1, y1);
	}
	if (!((674 <= mouse_positionX && mouse_positionX <= 764) && (339 <= mouse_positionY && mouse_positionY <= 431)))
	{
		x1 = 674;
		y1 = 339;
		x2 = x1 + 90;
		y2 = y1 + 92;

		cf = RGB(255, 255, 255);
		hPenOxy = CreatePen(PS_SOLID, 3, cf);
		hOldPen = (HPEN)SelectObject(dc, hPenOxy);

		dc.MoveTo(x1, y1);
		dc.LineTo(x2, y1);
		dc.LineTo(x2, y2);
		dc.LineTo(x1, y2);
		dc.LineTo(x1, y1);
	}

	CDialog::OnMouseMove(nFlags, point);
}


void CDeliciousFoodCafeDlgDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	GetClientRect(&rc);
	CString md;

	hNew = CreateFont(54, 0, 0, 10, FW_NORMAL, 10, 0, 0,
		ANSI_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE,
		L"Times New Roman");
	hold = (HFONT)SelectObject(dc, hNew);

	cf = RGB(123, 63, 214);
	SetTextColor(dc, cf);

	cf = RGB(255, 255, 255);
	hPenOxy = CreatePen(PS_SOLID, 3, cf);
	hOldPen = (HPEN)SelectObject(dc, hPenOxy);

	mouse_positionX = 0;
	mouse_positionY = 0;

	mouse_positionX = point.x;
	mouse_positionY = point.y;

	if ((562 <= mouse_positionX && mouse_positionX <= 652) && (25 <= mouse_positionY && mouse_positionY <= 117))
	{
		BigPicScreen.SetBitmap(::LoadBitmap(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDB_BITMAP1)));
		dc.Rectangle(40, 20, 500, 80);
		md = "Coffe";
		const CString ms = md;
		dc.TextOutW(40, 20, ms);
	}
	if ((562 <= mouse_positionX && mouse_positionX <= 652) && (129 <= mouse_positionY && mouse_positionY <= 221))
	{
		BigPicScreen.SetBitmap(::LoadBitmap(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDB_BITMAP3)));
		dc.Rectangle(40, 20, 500, 80);
		md = "Chocolate Chips Muffin";
		const CString ms = md;
		dc.TextOutW(40, 20, ms);
	}
	if ((562 <= mouse_positionX && mouse_positionX <= 652) && (234 <= mouse_positionY && mouse_positionY <= 326))
	{
		BigPicScreen.SetBitmap(::LoadBitmap(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDB_BITMAP5)));
		dc.Rectangle(40, 20, 500, 80);
		md = "Toasted Breads";
		const CString ms = md;
		dc.TextOutW(40, 20, ms);
	}
	if ((562 <= mouse_positionX && mouse_positionX <= 652) && (339 <= mouse_positionY && mouse_positionY <= 431))
	{
		BigPicScreen.SetBitmap(::LoadBitmap(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDB_BITMAP7)));
		dc.Rectangle(40, 20, 500, 80);
		md = "Tea";
		const CString ms = md;
		dc.TextOutW(40, 20, ms);
	}
	if ((674 <= mouse_positionX && mouse_positionX <= 764) && (24 <= mouse_positionY && mouse_positionY <= 116))
	{
		BigPicScreen.SetBitmap(::LoadBitmap(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDB_BITMAP15)));
		dc.Rectangle(40, 20, 500, 80);
		md = "Big Breakfast";
		const CString ms = md;
		dc.TextOutW(40, 20, ms);
	}
	if ((674 <= mouse_positionX && mouse_positionX <= 764) && (129 <= mouse_positionY && mouse_positionY <= 221))
	{
		BigPicScreen.SetBitmap(::LoadBitmap(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDB_BITMAP13)));
		dc.Rectangle(40, 20, 500, 80);
		md = "Muesli";
		const CString ms = md;
		dc.TextOutW(40, 20, ms);
	}
	if ((674 <= mouse_positionX && mouse_positionX <= 764) && (234 <= mouse_positionY && mouse_positionY <= 326))
	{
		BigPicScreen.SetBitmap(::LoadBitmap(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDB_BITMAP11)));
		dc.Rectangle(40, 20, 500, 80);
		md = "Waffles";
		const CString ms = md;
		dc.TextOutW(40, 20, ms);
	}
	if ((674 <= mouse_positionX && mouse_positionX <= 764) && (339 <= mouse_positionY && mouse_positionY <= 431))
	{
		BigPicScreen.SetBitmap(::LoadBitmap(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDB_BITMAP9)));
		dc.Rectangle(40, 20, 500, 80);
		md = "Egg Benedict"; 
		const CString ms = md;
		dc.TextOutW(40, 20, ms);
	}



	CDialog::OnLButtonDown(nFlags, point);
}
