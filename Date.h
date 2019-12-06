#pragma once

class Date
{
private:
	int day;
	int month;
	int year;

public:
	Date(int day, int month, int year) : day(day), month(month), year(year) { }

	int getDay() {
		return day;
	}

	int getMonth() {
		return month;
	}

	int getYear() {
		return year;
	}
};