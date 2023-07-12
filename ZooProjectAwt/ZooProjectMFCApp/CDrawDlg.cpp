
// CDrawDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "CDraw.h"
#include "CDrawDlg.h"
#include "afxdialogex.h"
#include "resource.h"
#include <Windows.h>
#include <stdlib.h>
#include <iostream>
#include "CNewDialogJeraf.h" //article about Jeraf
#include "CNewDialogHippo.h" //article about Hippo
#include "CNewDialogLion.h" //article about Lion
#include "CNewDialogZebra.h" //article about Zebra


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCDrawDlg dialog

HINSTANCE hInst;
HBITMAP hBitmap;
CWnd hPic;


CCDrawDlg::CCDrawDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CDRAW_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCDrawDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, ID_PICACTIVE, AnimalScreen);
	SetWindowTextW(L" ZooProjectAwt "); //main dialog window name
}

BEGIN_MESSAGE_MAP(CCDrawDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
//	ON_WM_MOUSEMOVE()
ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


// CCDrawDlg message handlers

BOOL CCDrawDlg::OnInitDialog()
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

void CCDrawDlg::OnPaint()
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
		
		CPaintDC dc(this);
		CBrush one(RGB(0, 0,0));

		//dc.Rectangle(27, 37, 322, 107); //жирафа
		//dc.Rectangle(27, 134, 322, 204); //зебра
		//dc.Rectangle(27, 231, 322, 301); //лев
		//dc.Rectangle(27, 328, 322, 396); //бегемот

		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCDrawDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCDrawDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	if ((27 <= mouse_positionX && mouse_positionX <= 322) && (37 <= mouse_positionY && mouse_positionY <= 107))//жирафа
	{
		CNewDialogJeraf nJeraf;
		nJeraf.DoModal(); //виклик планшетки з інформацією про жирафа
	}
	if ((27 <= mouse_positionX && mouse_positionX <= 322) && (134 <= mouse_positionY && mouse_positionY <= 204))//зебра 
	{
		CNewDialogZebra nZebra;
		nZebra.DoModal(); //виклик планшетки з інформацією про зебру
	}
	if ((27 <= mouse_positionX && mouse_positionX <= 322) && (231 <= mouse_positionY && mouse_positionY <= 301))//лев
	{
		CNewDialogLion nLion;
		nLion.DoModal(); //виклик планшетки з інформацією про лева
	}
	if ((27 <= mouse_positionX && mouse_positionX <= 322) && (328 <= mouse_positionY && mouse_positionY <= 396))//бегемот
	{
		CNewDialogHippo nHippo;
		nHippo.DoModal(); //виклик планшетки з інформацією бегемота
	}
	
	CDialog::OnLButtonDown(nFlags, point);
}




void CCDrawDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	
	mouse_positionX = 0;
	mouse_positionY = 0 ;

	mouse_positionX = point.x;
	mouse_positionY = point.y;

/*
	CString str;													//отладка
	str.Format(L"X = %d, Y = %d", mouse_positionX, mouse_positionY);
	SetWindowText(str); //выводит координаты мыши в названии окна

	*/

	if ((27 <= mouse_positionX && mouse_positionX <= 322) && (37 <= mouse_positionY && mouse_positionY <= 107)&&Jeraf_fg==false)
	{
		AnimalScreen.SetBitmap(::LoadBitmap(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDB_BITMAP5)));//жирафа
		Zebra_fg = false;
		Lion_fg = false; //система прапорців для усунення мерехтіння малюнків при переміщення курсора по кнопках
		Hippo_fg = false;
		Jeraf_fg = true;
	}

	 if ((27 <= mouse_positionX && mouse_positionX <= 322) && (134 <= mouse_positionY && mouse_positionY <= 204)&&Zebra_fg==false)
	{
		AnimalScreen.SetBitmap(::LoadBitmap(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDB_BITMAP8)));//зебра
		Zebra_fg = true;
		Lion_fg = false;
		Hippo_fg = false;
		Jeraf_fg == false;
	}

	 if ((27 <= mouse_positionX && mouse_positionX <= 322) && (231 <= mouse_positionY && mouse_positionY <= 301)&& Lion_fg == false)
	{
		AnimalScreen.SetBitmap(::LoadBitmap(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDB_BITMAP7)));//лев
		Zebra_fg = false;
		Lion_fg = true;
		Hippo_fg = false;
		Jeraf_fg == false;
	}

	if ((27 <= mouse_positionX && mouse_positionX <= 322) && (328 <= mouse_positionY&& mouse_positionY <= 396)&&Hippo_fg == false)
	{
		AnimalScreen.SetBitmap(::LoadBitmap(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDB_BITMAP6)));//бегемот
		Zebra_fg = false;
		Lion_fg = false;
		Hippo_fg = true;
		Jeraf_fg == false;
	}
	
	CDialog::OnMouseMove(nFlags, point);
}
