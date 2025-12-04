#include <iostream>

using namespace std;

bool isLeapYear(int year);

int main() {
	int year;

	while (true) {
		cout << "Enter a year or Q to quit: ";
		cin >> year;

		if (cin.fail()) {
			return 0;
		}

		if (year < 1582) {
			cout << "Year must be 1582 or later." << endl;
			continue;
		}

		if (isLeapYear(year)) {
			cout << year << " is a leap year." << endl;
		}
		else {
			cout << year << " is not a leap year." << endl;
		}
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