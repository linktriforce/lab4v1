#include <iostream>
#include <iomanip> // for setw and setfill
#include "date.h"

using std::cin;
using std::cout;
using std::endl;
using std::setfill;
using std::setw;

int main()
{
	// Check input and output of dates. Uncomment the following when you
	// have added operator>> and operator<<.
#if 0
	bool cont = true;
	while (cont)
	{
		cout << "Type a date: ";
		Date aDate;
		cin >> aDate;
		if (cin.eof())
		{
			// TODO: Never reached in this example? Can it be achived with user input?
			// Set flag as in cin.good?
			cont = false;
		}
		else if (!cin.good())
		{
			cout << "Wrong input format. e.g '2012-10-01" << endl;
			// restore stream state and ignore the rest of the line
			cin.clear();
			cin.ignore(10000, '\n');
		}
		else
		{
			cout << "Output: " << aDate << endl;
		}
	}
#else
	// Check 'next' by creating an object describing today's date, then
	// printing dates more than a month ahead
	cout << "--- Today and more than a month ahead:" << endl;
	Date d1;
	cout << d1;
	cout << endl;
	for (int i = 1; i <= 35; ++i)
	{
		d1.next();
		cout << d1;
		cout << endl;
	}

	// Check so 'next' functions correctly from one year to the next
	cout << "--- New Year's Eve and the next day:" << endl;
	Date d2(2013, 12, 31);
	cout << d2;
	cout << endl;
	d2.next();
	cout << d2;
	cout << endl;
#endif
}
