
// NumberOfDaysBetweenDatesMFCAppDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "NumberOfDaysBetweenDatesMFCApp.h"
#include "NumberOfDaysBetweenDatesMFCAppDlg.h"
#include "afxdialogex.h"
#include "DayMomthYear.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;

// CNumberOfDaysBetweenDatesMFCAppDlg dialog



CNumberOfDaysBetweenDatesMFCAppDlg::CNumberOfDaysBetweenDatesMFCAppDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_NUMBEROFDAYSBETWEENDATESMFCAPP_DIALOG, pParent)
	, Data1(_T(""))
	, Data2(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNumberOfDaysBetweenDatesMFCAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, Data1);
	DDX_Text(pDX, IDC_E1, E1);
	DDX_Text(pDX, IDC_EDIT2, Data2);
}

BEGIN_MESSAGE_MAP(CNumberOfDaysBetweenDatesMFCAppDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CNumberOfDaysBetweenDatesMFCAppDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CNumberOfDaysBetweenDatesMFCAppDlg message handlers

BOOL CNumberOfDaysBetweenDatesMFCAppDlg::OnInitDialog()
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

void CNumberOfDaysBetweenDatesMFCAppDlg::OnPaint()
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
HCURSOR CNumberOfDaysBetweenDatesMFCAppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CNumberOfDaysBetweenDatesMFCAppDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here

	CString data1, data2;
	CString Ams, Bms, Cms;
	UpdateData(true);
	data1 = Data1;
	data2 = Data2;
	UpdateData(false);

	//converting CString to integer 
	int k = 0;
	for (int i = 0; i < data1.GetLength(); i++)
	{
		if ((data1[i] == '/') && (k == 0))k++, i++;
		else if ((data1[i] == '/') && (k == 1))k++, i++;
		if (k == 0)Ams += data1[i];
		if (k == 1)Bms += data1[i];
		if (k == 2)Cms += data1[i];
	}
	int a = _ttoi(Ams);
	int b = _ttoi(Bms);
	int c = _ttoi(Cms);

	if ((0 < a) && (a < 32) && (0 < b) && (b < 13) && (1582 < c)&&(c < 5000))
	{
		DATACHECK1 = true;
		DayMomthYear NewDataMember1(a, b, c);
	}
	else DATACHECK1 = false;

	k = 0;
	Ams = "";
	Bms = "";
	Cms = "";
	for (int i = 0; i < data2.GetLength(); i++)
	{
		if ((data2[i] == '/') && (k == 0))k++, i++;
		else if ((data2[i] == '/') && (k == 1))k++, i++;
		if (k == 0)Ams += data2[i];
		if (k == 1)Bms += data2[i];
		if (k == 2)Cms += data2[i];
	}
	int a1 = _ttoi(Ams);
	int b1 = _ttoi(Bms);
	int c1 = _ttoi(Cms);

	if ((0 < a1) && (a1 < 32) && (0 < b1) && (b1 < 13) && (1582 < c1)&&(c1 < 5000))
	{
		DATACHECK2 = true;

	}
	else DATACHECK2 = false;

	if (DATACHECK1&&DATACHECK2)
	{
		CString ms, t;
		DayMomthYear NewDataMember1(a, b, c);
		DayMomthYear NewDataMember2(a1, b1, c1);
		int res = DaysFromYearToYear(NewDataMember1.day, NewDataMember1.month, NewDataMember1.year,
			NewDataMember2.day, NewDataMember2.month, NewDataMember2.year) - NewDataMember1.DaysFromStartOfYearToDay()
			+ NewDataMember2.DaysFromStartOfYearToDay();

		ms = "Кількість днів між введеними датами: \n\t";
		t.Format(L"%2i", res);
		ms += t;

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

	DATACHECK1 = false;
	DATACHECK2 = false;
	Ams = "";
	Bms = "";
	Cms = "";

}

int CNumberOfDaysBetweenDatesMFCAppDlg::DaysFromYearToYear(int Data1Day, int Data1Month, int Data1Year, int Data2Day, int Data2Month, int Data2Year)
{
	int result = 0;
	if (IsDayLaterThan(Data1Day, Data1Month, Data1Year, Data2Day, Data2Month, Data2Year))
	{
		for (int i = Data1Year; i < Data2Year; i++)
		{
			if (IsYearLeap(i))result += 366;
			else result += 365;
		}
	}
	else
	{
		for (int i = Data2Year; i < Data1Year; i++)
		{
			if (IsYearLeap(i))result += 366;
			else result += 365;
		}
	}

	return result;
}

bool CNumberOfDaysBetweenDatesMFCAppDlg::IsDayLaterThan(int Data1Day, int Data1Month, int Data1Year, int Data2Day, int Data2Month, int Data2Year)
{
	return ((Data2Year > Data1Year) || ((Data2Year == Data2Year) && (Data2Month > Data1Month)) || ((Data2Month == Data1Month) && (Data2Day > Data1Day)));
}

bool CNumberOfDaysBetweenDatesMFCAppDlg::IsYearLeap(int year)
{
	return ((year % 400 == 0) || (year % 100 != 0) && (year % 4 == 0));
}
