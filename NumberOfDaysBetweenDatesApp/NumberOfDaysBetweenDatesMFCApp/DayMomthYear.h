#pragma once
#include <afxwin.h>
#include "NumberOfDaysBetweenDatesMFCAppDlg.h"
class DayMomthYear :
	public CDialog
{
public:
	DayMomthYear(int x, int y, int z) : day(x), month(y), year(z)
	{
	}

	bool IsYearLeap()
	{
		return ((year % 400 == 0) || (year % 100 != 0) && (year % 4 == 0));
	};

	int DaysInMonth(int month)
	{
		int DaysInMonth = 0;
		if ((month == 4) || (month == 6) || (month == 9) || (month == 11))DaysInMonth = 30;
		else if (month == 2)
		{
			if (IsYearLeap())DaysInMonth = 29;
			else DaysInMonth = 28;
		}
		else DaysInMonth = 31;
		return DaysInMonth;
	};

	CString GetMonthName()
	{
		CString MonthName;
		switch (month)
		{
		case 1:
			MonthName = "�i����";
			break;
		case 2:
			MonthName = "�����";
			break;
		case 3:
			MonthName = "��������";
			break;
		case 4:
			MonthName = "��i����";
			break;
		case 5:
			MonthName = "�������";
			break;
		case 6:
			MonthName = "�������";
			break;
		case 7:
			MonthName = "������";
			break;
		case 8:
			MonthName = "�������";
			break;
		case 9:
			MonthName = "��������";
			break;
		case 10:
			MonthName = "�������";
			break;
		case 11:
			MonthName = "��������";
			break;
		case 12:
			MonthName = "�������";
			break;
		}
		return MonthName;
	}

	int  DaysFromStartOfYearToDay()
	{
		int res = 0;
		for (int i = 1; i < month; i++)
		{
			res += DaysInMonth(i);
		}
		res += day;
		return res;
	}

	const int day, month, year;
	~DayMomthYear();
};

