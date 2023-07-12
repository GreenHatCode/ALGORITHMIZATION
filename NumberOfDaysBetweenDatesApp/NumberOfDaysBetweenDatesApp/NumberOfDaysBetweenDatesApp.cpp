#include <iostream>
#include <string>

int DaysFromYearToYear(int Data1Day, int Data1Month, int Data1Year, int Data2Day, int Data2Month, int Data2Year);
bool IsDayLaterThan(int Data1Day, int Data1Month, int Data1Year, int Data2Day, int Data2Month, int Data2Year);
bool IsYearLeap(int year);

using namespace std;

bool DATACHECK = false;

class DayMomthYear
{
public:
	DayMomthYear(int x, int y, int z) : day(x), month(y), year(z)
	{
		DATACHECK = false;
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

	int  DaysFromStartOfYearToDay()
	{
		int res=0;
		for (int i = 1; i < month; i++)
		{
			res += DaysInMonth(i);
		}
		res += day;
		return res;
	}

	const int day, month, year;
};

int main()
{
	setlocale(LC_ALL, ".1251");
	int a, b, c;
	while (!DATACHECK)
	{
		cout << "\tEnter first data:\n";
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
	DayMomthYear NewDataMember1(a, b, c);

	while (!DATACHECK)
	{
		cout << "\tEnter second data:\n";
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
	DayMomthYear NewDataMember2(a, b, c);

	cout << "\tDays from data1 to data2: " << DaysFromYearToYear(NewDataMember1.day, NewDataMember1.month, NewDataMember1.year,
		NewDataMember2.day, NewDataMember2.month, NewDataMember2.year) - NewDataMember1.DaysFromStartOfYearToDay() 
		+ NewDataMember2.DaysFromStartOfYearToDay() << endl;

	return 0;
}

int DaysFromYearToYear(int Data1Day, int Data1Month, int Data1Year, int Data2Day, int Data2Month, int Data2Year)
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

bool IsDayLaterThan(int Data1Day, int Data1Month, int Data1Year, int Data2Day, int Data2Month, int Data2Year)
{
	//is data2 later than data1
	return ((Data2Year> Data1Year)||((Data2Year==Data2Year)&&(Data2Month>Data1Month))||((Data2Month==Data1Month)&&(Data2Day>Data1Day)));
}

bool IsYearLeap(int year)
{
	return ((year % 400 == 0) || (year % 100 != 0) && (year % 4 == 0));
}
