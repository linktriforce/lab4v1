#include <ctime> // time and localtime
#include "date.h"

int Date::daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date()
{
	time_t timer = time(0);			 // time in seconds since 1970-01-01
	tm *locTime = localtime(&timer); // broken-down time
	year = 1900 + locTime->tm_year;
	month = 1 + locTime->tm_mon;
	day = locTime->tm_mday;
}

Date::Date(int y, int m, int d) : year(y), month(m), day(d) {}

int Date::getYear() const
{
	return year;
}

int Date::getMonth() const
{
	return month;
}

int Date::getDay() const
{
	return day;
}

bool Date::validDate(int y, int m, int d)
{
	if (y <= 0 || y > 9999 || m < 1 || m > 12 || d < 1)
		return false;

	return d <= daysPerMonth[m - 1];
}

void Date::next()
{
	if (day == daysPerMonth[month - 1])
	{
		day = 1;
		if (month == 12)
		{
			month = 1;
			year++;
		}
	}
	else
		day++;
}
