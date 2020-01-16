#pragma once

#include "SchoolClass.h"
#include "Teacher.h"
#include "VectorHuman.h"
#include "VectorSchoolClasses.h"

class School
{
private:
	VectorSchoolClasses* classes = new VectorSchoolClasses();
	VectorHuman<Teacher>* teachers = new VectorHuman<Teacher>();
	string title;

public:
	School(string title) : title(title) {}

	string getTitleSchool() {
		return title;
	}

	VectorHuman<Teacher>* getVectorTeachers() {
		return teachers;
	}

	VectorSchoolClasses* getVectorSchoolClasses() {
		return classes;
	}

	int getCountStudents() {
		int count = 0;

		for (SchoolClass* i : classes->getvectorSchoolClass())
			count += i->getCountHumans();

		return count;
	}

	vector<Student*> getListStudents()
	{
		vector<Student*> students;

		for (SchoolClass* i : classes->getvectorSchoolClass())
			for (Student* j : i->getvectorStudents())
				students.push_back(j);

		return students;
	}

	~School() {
		delete classes;
		delete teachers;
	}
};