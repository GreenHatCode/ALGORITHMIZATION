#include <iostream>
#include <string>

using namespace std;

bool DATACHECK = false;

class DayMomthYear
{
public:
	DayMomthYear(int x, int y, int z) : day(x), month(y), year(z)
	{
	}

	bool IsYearLeap()
	{
		return ((year % 400 == 0) || (year % 100 != 0) && (year % 4 == 0));
	};

	int DaysInMonth()
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

	string GetMonthName()
	{
		string MonthName;
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

private: 
	const int day, month, year;
};

int main()
{
	setlocale(LC_ALL, ".1251");
	int a, b, c;
	while (!DATACHECK)
	{
		cout << "\tEnter your data:\n";
		cout << "\tDay: ";
		cin >> a;
		cout << "\tMonth: ";
		cin >> b;
		cout << "\tYear: ";
		cin >> c;

		if ((0 < a) && (a < 32) && (0 < b) && (b < 13) && (1582 < c < 5000))
		{
			DATACHECK = true;
			cout << "\tYour data is correct\n";
		}
		else
		{
			DATACHECK = false;
			cout << "\tYour data is incorrect\n";
		}
	}

	DayMomthYear NewDataMember(a, b, c);

	if (NewDataMember.IsYearLeap())
	{
		cout << "\n\tYour year is leap" << endl;
	}
	else
	{
		cout << "\n\tYour year is not leap" << endl;
	}


}