#include <iostream>

using namespace std;

bool isLeapYear(int year);
int daysInMonth(int month, int year);
int dayOfWeek(int month, int day, int year);

int main() {
	int monthInput;
	int year;
	int day;
	string month, dayOftheWeek;

	while (true) {
		cout << "Enter a month and year or Q to quit: ";
		cin >> monthInput >> day >> year;

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

		if (day < 1 || day > daysInMonth(monthInput, year)) {
			cout << "Invalid day for " << month << " " << year << "." << endl;
			continue;
		}

		int dow = dayOfWeek(monthInput, day, year);
		switch (dow) {
			case 0:
				dayOftheWeek = "Saturday";
				break;
			case 1:
				dayOftheWeek = "Sunday";
				break;
			case 2:
				dayOftheWeek = "Monday";
				break;
			case 3:
				dayOftheWeek = "Tuesday";
				break;
			case 4:
				dayOftheWeek = "Wednesday";
				break;
			case 5:
				dayOftheWeek = "Thursday";
				break;
			case 6:
				dayOftheWeek = "Friday";
				break;
		}

		cout << dayOftheWeek << ", " << month << " " << day << ", " << year << endl;
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

int dayOfWeek(int month, int day, int year) {
	int h, q, m, Y;
	q = day;
	if (month == 1 || month == 2) {
		m = month + 12;
		Y = year - 1;
	}
	else {
		m = month;
		Y = year;
	}
	h = (q + (26 * (m + 1)) / 10 + Y + (Y / 4) + 6 * (Y / 100) + (Y / 400)) % 7;
	return h;
}