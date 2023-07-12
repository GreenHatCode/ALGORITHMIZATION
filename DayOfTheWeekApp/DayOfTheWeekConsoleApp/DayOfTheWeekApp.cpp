#include <iostream>
#include <string>

int DaysFromYearToYear(int Data1Day, int Data1Month, int Data1Year, int Data2Day, int Data2Month, int Data2Year);
bool IsDayLaterThan(int Data1Day, int Data1Month, int Data1Year, int Data2Day, int Data2Month, int Data2Year);
bool IsYearLeap(int year);
int AmountOfDaysBetweenTwoDatas(int Data1Day, int Data1Month, int Data1Year, int Data2Day, int Data2Month, int Data2Year);
void DayOfTheWeek(int DataDay, int DataMonth, int DataYear);

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
};

int main()
{
	setlocale(LC_ALL, ".1251");
	int day, month, year;
	while (!DATACHECK)
	{
		cout << "\tEnter data:\n";
		cout << "\tDay: ";
		cin >> day;
		cout << "\tMonth: ";
		cin >> month;
		cout << "\tYear: ";
		cin >> year;

		if ((0 < day) && (day < 32) && (0 < month) && (month < 13) && (1582 < year < 5000))
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

	DayOfTheWeek(day, month, year);

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
	return ((Data2Year > Data1Year) || ((Data2Year == Data2Year) && (Data2Month > Data1Month)) || ((Data2Month == Data1Month) && (Data2Day > Data1Day)));
}

bool IsYearLeap(int year)
{
	return ((year % 400 == 0) || (year % 100 != 0) && (year % 4 == 0));
}

int AmountOfDaysBetweenTwoDatas(int Data1Day, int Data1Month, int Data1Year, int Data2Day, int Data2Month, int Data2Year)
{
	int res = 0;
	DayMomthYear NewDataMember1(Data1Day, Data1Month, Data1Year);
	DayMomthYear NewDataMember2(Data2Day, Data2Month, Data2Year);
	res = DaysFromYearToYear(NewDataMember1.day, NewDataMember1.month, NewDataMember1.year,
		NewDataMember2.day, NewDataMember2.month, NewDataMember2.year) - NewDataMember1.DaysFromStartOfYearToDay()
		+ NewDataMember2.DaysFromStartOfYearToDay();

	return res;
}

void DayOfTheWeek(int DataDay, int DataMonth, int DataYear)
{
	string DayName;
	const int StartDay = 31;
	const int StartMonth = 12;
	const int StartYear = 1989;
	int k = 0;

	if (IsDayLaterThan(StartDay, StartMonth, StartYear, DataDay, DataMonth, DataYear) )
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

	cout << "\n\tYour data is " << DayName << "\n\n" << endl;
}
