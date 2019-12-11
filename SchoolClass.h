#pragma once

#include <deque>

#include "Student.h"

using namespace std;

class SchoolClass : public InfoClass {
private:
	deque<Student> students;

public:
	SchoolClass(char letterClass, int numberClass) : InfoClass(letterClass, numberClass) {}

	void addStudent(Student student) {
		if (!searchStudent(student.getName(), student.getSurname()))
			students.push_back(student);
	}

	void deleteStudent(string name, string surname)
	{
		for (int i = 0; i < students.size(); i++)
			if (students[i].getName() == name && students[i].getSurname() == surname) {
				students.erase(students.begin() + i);
				break;
			}
	}

	bool searchStudent(string name, string surname) {
		for (Student i : students)
			if (i.getName() == name && i.getSurname() == surname)
				return true;

		return false;
	}

	Student getStudent(string name, string surname) {
		for (Student i : students)
			if (i.getName() == name && i.getSurname() == surname)
				return i;
	}
};