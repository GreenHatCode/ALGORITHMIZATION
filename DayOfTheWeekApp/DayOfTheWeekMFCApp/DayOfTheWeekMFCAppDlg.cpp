
// DayOfTheWeekMFCAppDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "DayOfTheWeekMFCApp.h"
#include "DayOfTheWeekMFCAppDlg.h"
#include "DayMonthYear.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDayOfTheWeekMFCAppDlg dialog



CDayOfTheWeekMFCAppDlg::CDayOfTheWeekMFCAppDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DAYOFTHEWEEKMFCAPP_DIALOG, pParent)
	, InputData(_T(""))
	, E1(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDayOfTheWeekMFCAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, InputData);
	DDX_Text(pDX, IDC_E1, E1);
}

BEGIN_MESSAGE_MAP(CDayOfTheWeekMFCAppDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CDayOfTheWeekMFCAppDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CDayOfTheWeekMFCAppDlg message handlers

BOOL CDayOfTheWeekMFCAppDlg::OnInitDialog()
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

void CDayOfTheWeekMFCAppDlg::OnPaint()
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
HCURSOR CDayOfTheWeekMFCAppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDayOfTheWeekMFCAppDlg::OnBnClickedButton1()
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
	int day = _ttoi(Ams);
	int month = _ttoi(Bms);
	int year = _ttoi(Cms);

	if ((0 < day) && (day < 32) && (0 < month) && (month < 13) && (1582 < year < 5000))
	{
		DataCheck = true;
	}
	else
	{
		DataCheck = false;
	}

	if (DataCheck)
	{
		DayOfTheWeek(day, month, year);
	}
	else
	{
		UpdateData(true);
		E1 = "Incorrect input data \n Example of input data: 15/4/3000 ";
		UpdateData(false);
	}

	DataCheck = false;
}

int CDayOfTheWeekMFCAppDlg::DaysFromYearToYear(int Data1Day, int Data1Month, int Data1Year, int Data2Day, int Data2Month, int Data2Year)
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

bool CDayOfTheWeekMFCAppDlg::IsDayLaterThan(int Data1Day, int Data1Month, int Data1Year, int Data2Day, int Data2Month, int Data2Year)
{
	return ((Data2Year > Data1Year) || ((Data2Year == Data2Year) && (Data2Month > Data1Month)) || ((Data2Month == Data1Month) && (Data2Day > Data1Day)));
}

bool CDayOfTheWeekMFCAppDlg::IsYearLeap(int year)
{
	return ((year % 400 == 0) || (year % 100 != 0) && (year % 4 == 0));
}

int CDayOfTheWeekMFCAppDlg::AmountOfDaysBetweenTwoDatas(int Data1Day, int Data1Month, int Data1Year, int Data2Day, int Data2Month, int Data2Year)
{
	int res = 0;
	DayMonthYear NewDataMember1(Data1Day, Data1Month, Data1Year);
	DayMonthYear NewDataMember2(Data2Day, Data2Month, Data2Year);
	res = DaysFromYearToYear(NewDataMember1.day, NewDataMember1.month, NewDataMember1.year,
		NewDataMember2.day, NewDataMember2.month, NewDataMember2.year) - NewDataMember1.DaysFromStartOfYearToDay()
		+ NewDataMember2.DaysFromStartOfYearToDay();

	return res;
}

void CDayOfTheWeekMFCAppDlg::DayOfTheWeek(int DataDay, int DataMonth, int DataYear)
{
	CString DayName, ms;
	const int StartDay = 31;
	const int StartMonth = 12;
	const int StartYear = 1989;
	int k = 0;

	if (IsDayLaterThan(StartDay, StartMonth, StartYear, DataDay, DataMonth, DataYear))
	{
		k = AmountOfDaysBetweenTwoDatas(StartDay, StartMonth, StartYear, DataDay, DataMonth, DataYear) % 7;
	}
	else
	{
		k = (7 - AmountOfDaysBetweenTwoDatas(StartDay, StartMonth, StartYear, DataDay, DataMonth, DataYear) % 7) % 7;
	}

	switch (k)
	{
	case 0:
		DayName = "Sunday";
		break;
	case 1:
		DayName = "Monday";
		break;
	case 2:
		DayName = "Tuesday";
		break;
	case 3:
		DayName = "Wednesday";
		break;
	case 4:
		DayName = "Thursday";
		break;
	case 5:
		DayName = "Friday";
		break;
	case 6:
		DayName = "Saturday";
		break;
	}

	ms = "Â³äïîâ³äü: ";
	ms += "  Your day is ";
	ms += DayName;
	ms += ".";

	UpdateData(true);
	E1 = ms;
	UpdateData(false);
	ms.Empty();
}


void CDayOfTheWeekMFCAppDlg::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	//CDialog::OnOK();
}
