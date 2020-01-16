#pragma once

#include <vector>

#include "Student.h"
#include "VectorHuman.h"

class SchoolClass : public InfoClass, public VectorHuman<Student>
{
public:
	SchoolClass(char letterClass, int numberClass) : InfoClass(letterClass, numberClass) {}

	void addHuman(Student* object) {
		if (object->getLetterClass() == getLetterClass() && object->getNumberClass() == getNumberClass())
			VectorHuman::addHuman(object);
	}
};