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
			MonthName = "Сiчень";
			break;
		case 2:
			MonthName = "Лютий";
			break;
		case 3:
			MonthName = "Березень";
			break;
		case 4:
			MonthName = "Квiтень";
			break;
		case 5:
			MonthName = "Травень";
			break;
		case 6:
			MonthName = "Червень";
			break;
		case 7:
			MonthName = "Липень";
			break;
		case 8:
			MonthName = "Серпень";
			break;
		case 9:
			MonthName = "Вересень";
			break;
		case 10:
			MonthName = "Жовтень";
			break;
		case 11:
			MonthName = "Листопад";
			break;
		case 12:
			MonthName = "Грудень";
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

