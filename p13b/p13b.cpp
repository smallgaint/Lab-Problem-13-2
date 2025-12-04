#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool isLeapYear(int year);
int daysInMonth(int month, int year);
int dayOfWeek(int month, int day, int year);

int main() {
	string monthInput;
	int year, month, dow;
	string calendar[] = { 
		"                   1  2  3  4  5  6  7 ",
		" 2  3  4  5  6  7  8  9 10 11 12 13 14 ",
		" 9 10 11 12 13 14 15 16 17 18 19 20 21 ",
		"16 17 18 19 20 21 22 23 24 25 26 27 28 ",
		"23 24 25 26 27 28 29 30 31             ",
		"30 31                                  " };
	string weekDays = "Su Mo Tu We Th Fr Sa";

	cout << "Enter a month and year or Q to quit: ";
	cin >> monthInput;
	if (monthInput == "Q" || monthInput == "q") {
		return 0;
	}
	cin >> year;


	if (monthInput == "January") {
		month = 1;
	}else if(monthInput == "February") {
		month = 2;
	}else if(monthInput == "March") {
		month = 3;
	}else if(monthInput == "April") {
		month = 4;
	}else if(monthInput == "May") {
		month = 5;
	}else if(monthInput == "June") {
		month = 6;
	}else if(monthInput == "July") {
		month = 7;
	}else if(monthInput == "August") {
		month = 8;
	}else if(monthInput == "September") {
		month = 9;
	}else if(monthInput == "October") {
		month = 10;
	}else if(monthInput == "November") {
		month = 11;
	}else if(monthInput == "December") {
		month = 12;
	}
	else {
		cout << "Invalid month name." << endl;
		return 1;
	}

	if (year < 1582) {
		cout << "Year must be 1582 or later." << endl;
		return 1;
	}

	dow = dayOfWeek(month, 1, year);
	cout << monthInput << " " << year << endl;
	cout << weekDays << endl;
	string days = to_string(daysInMonth(month, year));

	for (int i = 0; i < (dow > 1) ? 5: 6; i++) {
		string line = calendar[i].substr(21 - (dow) * 3, 21);
		if (line.find(days) < line.length()) {
			line = line.substr(0, line.find(days) + days.length());
			cout << line << endl;
			break;
		}
		cout << line << endl;
	}	

	cout << endl;
	string outFileName;
	cout << "Output file: ";
	cin >> outFileName;

	ofstream outFile(outFileName);
	outFile << monthInput << " " << year << endl;
	outFile << weekDays << endl;
	for (int i = 0; i < (dow > 1) ? 5 : 6; i++) {
		string line = calendar[i].substr(21 - (dow) * 3, 21);
		if (line.find(days) < line.length()) {
			line = line.substr(0, line.find(days) + days.length());
			outFile << line << endl;
			break;
		}
		outFile << line << endl;
	}
	outFile.close();
	return 0;
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