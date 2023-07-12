#pragma once
#include <afxwin.h>
class DayMonthYear :
	public CDialog
{
public:
	DayMonthYear(int x, int y, int z) : day(x), month(y), year(z)
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
	~DayMonthYear();
};

