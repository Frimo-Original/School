#pragma once

#include <vector>
#include "Student.h"

class SchoolClass : public InfoClass
{
private:
	vector<Student*> students;

public:
	SchoolClass(char letterClass, int numberClass) : InfoClass(letterClass, numberClass) {}

	void addStudent(string name, string surname, Date birthday)
	{
		if (!searchStudent(name, surname))
			students.push_back(new Student(name, surname, birthday, getLetterClass(), getNumberClass()));
	}

	void deleteStudent(string name, string surname)
	{
		if (searchStudent(name, surname))
			for (int i = 0; i < students.size(); i++)
				if (students[i]->getName() == name && students[i]->getSurname() == surname) {
					Student* temp = students[i];
					students.erase(students.begin() + i);
					delete temp;
				}
	}

	bool searchStudent(string name, string surname)
	{
		for (Student* i : students)
			if (i->getName() == name && i->getSurname() == surname)
				return true;

		return false;
	}

	Student* getStudent(string name, string surname)
	{
		if (searchStudent(name, surname))
			for (Student* i : students)
				if (i->getName() == name && i->getSurname() == surname)
					return i;
		
		return NULL;
	}

	int getCountStudents() {
		return students.size();
	}
};