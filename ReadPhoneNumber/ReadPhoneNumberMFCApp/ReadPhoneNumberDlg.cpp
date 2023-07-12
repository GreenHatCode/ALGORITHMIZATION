
// ReadPhoneNumberDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "ReadPhoneNumber.h"
#include "ReadPhoneNumberDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CReadPhoneNumberDlg dialog



CReadPhoneNumberDlg::CReadPhoneNumberDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_READPHONENUMBER_DIALOG, pParent)
	, INPUT(_T(""))
	, OUTPUT(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CReadPhoneNumberDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, INPUT);
	DDX_Text(pDX, IDC_EDIT2, OUTPUT);
	SetWindowTextW(L"Програма пошуку відсутніх цифр у номері телефону");
}

BEGIN_MESSAGE_MAP(CReadPhoneNumberDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CReadPhoneNumberDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CReadPhoneNumberDlg message handlers

BOOL CReadPhoneNumberDlg::OnInitDialog()
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

void CReadPhoneNumberDlg::OnPaint()
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
HCURSOR CReadPhoneNumberDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CReadPhoneNumberDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here

    UpdateData(true);
    input = INPUT;
    UpdateData(false);

    fg0 = false;
    fg1 = false;
    fg2 = false;
    fg3 = false;
    fg4 = false;
    fg5 = false;
    fg6 = false;
    fg7 = false;
    fg8 = false;
    fg9 = false;

    ms = "";

    if (input.GetLength() == 9)
    {
        for (int i = 0; i < input.GetLength(); i++)
        {
            if ((int)input[i] == 48)fg0 = true; //0
            if ((int)input[i] == 49)fg1 = true; //1
            if ((int)input[i] == 50)fg2 = true; //2
            if ((int)input[i] == 51)fg3 = true; //3
            if ((int)input[i] == 52)fg4 = true; //4
            if ((int)input[i] == 53)fg5 = true; //5
            if ((int)input[i] == 54)fg6 = true; //6
            if ((int)input[i] == 55)fg7 = true; //7
            if ((int)input[i] == 56)fg8 = true; //8
            if ((int)input[i] == 57)fg9 = true; //9
        }

        ms += "у номері немає ";

        if (fg0 == false)ms += "0,";
        if (fg1 == false)ms += "1,";
        if (fg2 == false)ms += "2,";
        if (fg3 == false)ms += "3,";
        if (fg4 == false)ms += "4,";
        if (fg5 == false)ms += "5,";
        if (fg6 == false)ms += "6,";
        if (fg7 == false)ms += "7,";
        if (fg8 == false)ms += "8,";
        if (fg9 == false)ms += "9,";

        ms.Delete((ms.GetLength() - 1), 1);
        ms += ".";

    }
    else
    {
        ms += "це не номер телефону";
    }

    UpdateData(true);
    OUTPUT = ms;
    UpdateData(false);


}