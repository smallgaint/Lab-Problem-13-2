#include <iostream>

using namespace std;

bool isLeapYear(int year);
int daysInMonth(int month, int year);

int main() {
	int monthInput;
	int year;
	string month;

	while (true) {
		cout << "Enter a month and year or Q to quit: ";
		cin >> monthInput >> year;

		if (cin.fail()) {
			return 0;
		}

		switch (monthInput) {
			case 1:
				month = "January";
				break;
			case 2:
				month = "February";
				break;
			case 3:
				month = "March";
				break;
			case 4:
				month = "April";
				break;
			case 5:
				month = "May";
				break;
			case 6:
				month = "June";
				break;
			case 7:
				month = "July";
				break;
			case 8:
				month = "August";
				break;
			case 9:
				month = "September";
				break;
			case 10:
				month = "October";
				break;
			case 11:
				month = "November";
				break;
			case 12:
				month = "December";
				break;
			default:
				cout << "Invalid month." << endl;
				continue;
		}

		if (year < 1582) {
			cout << "Year must be 1582 or later." << endl;
			continue;
		}

		cout << month << " " << year << " has " << daysInMonth(monthInput, year) << " days." << endl;
	}


}

bool isLeapYear(int year) {
	if (year % 4 != 0) {
		return false;
	}
	else if (year % 100 != 0) {
		return true;
	}
	else if (year % 400 != 0) {
		return false;
	}
	else {
		return true;
	}
}

int daysInMonth(int month, int year) {
	if (month == 2) {
		return isLeapYear(year) ? 29 : 28;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11) {
		return 30;
	}
	else {
		return 31;
	}
}