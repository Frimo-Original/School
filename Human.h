#pragma once

#include <string>

#include "Date.h"

using namespace std;

class Human {
private:
	string name;
	string surname;
	Date birthday;

public:
	Human(string name, string surname, Date birthday) : name(name), surname(surname), birthday(birthday) {}

	string getName() {
		return name;
	}

	string getSurname() {
		return surname;
	}

	Date getBirthday() {
		return birthday;
	}
};