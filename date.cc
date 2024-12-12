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

std::istream &operator>>(std::istream &is, Date &date)
{
	int y = 0, m = 0, d = 0;
	char first_dash = '-';
	char second_dash = '-';

	if (is >> y >> first_dash >> m >> second_dash >> d &&
		date.validDate(y, m, d) && (first_dash == '-' && second_dash == '-'))
	{
		date = Date(y, m, d);
	}
	else
	{
		// format error. Sätter cin.good() till false.
		is.setstate(std::ios_base::failbit);
	}
	return is;
}

/*
 * Prints the date d in the format yyyy-mm-dd.
 */
std::ostream &operator<<(std::ostream &os, const Date &d)
{
	os << setw(4) << setfill('0') << d.getYear() << '-'
	   << setw(2) << setfill('0') << d.getMonth() << '-'
	   << setw(2) << setfill('0') << d.getDay();
	return os;
}

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
