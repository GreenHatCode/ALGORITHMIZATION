#pragma once
#include <afxwin.h>
class DayMomthYear :
	public CDialog
{
public:
	DayMomthYear(int x, int y, int z) : day(x), month(y), year(z)
	{
	}

	bool IsYearLeap();
	int DaysInMonth();
	CString GetMonthName();

	~DayMomthYear();
private:
	const int day, month, year;
};

