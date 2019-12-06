#pragma once

#include <list>

#include "Student.h"

using namespace std;

class SchoolClass : public InfoClass {
private:
	list<Student> students;

public:
	SchoolClass(char letterClass, int numberClass) : InfoClass(letterClass, numberClass) {}
};