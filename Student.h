#pragma once

#include "Human.h"
#include "InfoClass.h"

class Student : public Human, public InfoClass {
public:
	Student(string name, string surname, Date birthday, char letterClass, int numberClass) :
		Human(name, surname, birthday),
		InfoClass(letterClass, numberClass) { }
};