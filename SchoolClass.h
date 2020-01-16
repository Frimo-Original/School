#pragma once

#include <vector>

#include "Student.h"
#include "VectorHuman.h"

class SchoolClass : public InfoClass, public VectorHuman<Student>
{
private:
	VectorHuman<Student>* students = new VectorHuman<Student>();

public:
	SchoolClass(char letterClass, int numberClass) : InfoClass(letterClass, numberClass) {}

	VectorHuman<Student>* getVectorStudents() {
		return students;
	}

	~SchoolClass() {
		delete students;
	}
	/*void addHuman(Student* student) : addHuman(student) {

	}*/

	/**/
};