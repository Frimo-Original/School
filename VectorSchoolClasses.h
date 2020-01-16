#pragma once

#include <vector>
#include "Student.h"
#include "SchoolClass.h"

class VectorSchoolClasses
{
private:
	vector<SchoolClass*> classes;

public:
	void addClass(char letterClass, int numberClass) {
		if (!searchClass(letterClass, numberClass))
			classes.push_back(new SchoolClass(letterClass, numberClass));
	}

	void deleteClass(char letterClass, int numberClass) {
		if (searchClass(letterClass, numberClass))
			for (int i = 0; i < classes.size(); i++)
				if (classes[i]->getLetterClass() == letterClass && classes[i]->getNumberClass() == numberClass) {
					SchoolClass* temp = classes[i];
					classes.erase(classes.begin() + i);
					delete temp;
				}
	}

	SchoolClass* getSchoolClass(char letterClass, int numberClass) {
		if (searchClass(letterClass, numberClass))
			for (SchoolClass* i : classes)
				if (i->getLetterClass() == letterClass && i->getNumberClass() == numberClass)
					return i;

		return NULL;
	}

	vector<SchoolClass*> getvectorSchoolClass() {
		vector<SchoolClass*> temp;

		for (SchoolClass* i : classes)
			temp.push_back(i);

		return temp;
	}

	bool searchClass(char letterClass, int numberClass) {
		for (SchoolClass* i : classes)
			if (i->getLetterClass() == letterClass && i->getNumberClass() == numberClass)
				return true;

		return false;
	}
};