
// DefinitionOfLeapYearsMFCAppDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "DefinitionOfLeapYearsMFCApp.h"
#include "DefinitionOfLeapYearsMFCAppDlg.h"
#include "DayMomthYear.h"
#include "afxdialogex.h"
#include <iostream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDefinitionOfLeapYearsMFCAppDlg dialog



CDefinitionOfLeapYearsMFCAppDlg::CDefinitionOfLeapYearsMFCAppDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DEFINITIONOFLEAPYEARSMFCAPP_DIALOG, pParent)
	, InputData(_T(""))
	, E1(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDefinitionOfLeapYearsMFCAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, InputData);
	DDX_Text(pDX, IDC_E1, E1);
}

BEGIN_MESSAGE_MAP(CDefinitionOfLeapYearsMFCAppDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CDefinitionOfLeapYearsMFCAppDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CDefinitionOfLeapYearsMFCAppDlg message handlers

BOOL CDefinitionOfLeapYearsMFCAppDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	setlocale(LC_ALL, ".1251");

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDefinitionOfLeapYearsMFCAppDlg::OnPaint()
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
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDefinitionOfLeapYearsMFCAppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CDefinitionOfLeapYearsMFCAppDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CString inputdata;
	CString Ams, Bms, Cms;
	UpdateData(true);
	inputdata = InputData;
	UpdateData(false);

	//converting CString to integer 
	int k = 0;
	for (int i = 0; i < inputdata.GetLength(); i++)
	{
		if ((inputdata[i] == '/') && (k == 0))k++, i++;
		else if ((inputdata[i] == '/') && (k == 1))k++, i++;
		if (k == 0)Ams += inputdata[i];
		if (k == 1)Bms += inputdata[i];
		if (k == 2)Cms += inputdata[i];
	}
	int a = _ttoi(Ams);
	int b = _ttoi(Bms);
	int c = _ttoi(Cms);

	if ((0 < a) && (a < 32) && (0 < b) && (b < 13) && (1582 < c < 5000))
	{
		DataCheck = true;
	}
	else
	{
		DataCheck = false;
	}

	if (DataCheck)
	{
		DayMomthYear NewDataMember(a, b, c);
		CString ms, t;
		t.Format(L"%2i", NewDataMember.DaysInMonth());

		ms = "–езультат:\n";
		ms += "днiв у мiс€цi ";
		ms += t;
		ms += "\n";
		ms += "назва мiс€ц€: ";
		ms += NewDataMember.GetMonthName();
		ms += "\n";
		if (NewDataMember.IsYearLeap())ms += "рiк високосний";
		else ms += "рiк не високосний";

		UpdateData(true);
		E1 = ms;
		UpdateData(false);

	}
	else
	{
		UpdateData(true);
		E1 = "Incorrect input data \n Example of input data: 15/4/3000 ";
		UpdateData(false);
	}
}


void CDefinitionOfLeapYearsMFCAppDlg::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	//CDialog::OnOK();
}
