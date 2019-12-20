#pragma once

#include "SchoolClass.h"
#include "Teacher.h"

class School
{
private:
	vector<SchoolClass*> classes;
	vector<Teacher*> teachers;
	string title;

public:
	School(string title): title(title) {}

	void addClass(char letterClass, int numberClass) {
		if (!searchClass(letterClass, numberClass))
			classes.push_back(new SchoolClass(letterClass, numberClass));
	}

	void addTeacher(string name, string surname, Date birthday, Teacher::Specialty specialty) {
		if (!searchTeacher(name, surname))
			teachers.push_back(new Teacher(name, surname, birthday, specialty));
	}

	Teacher* getTeacher(string name, string surname) {
		if (searchTeacher(name, surname))
			for (Teacher* i : teachers)
				if (i->getName() == name && i->getSurname() == surname)
					return i;

		return NULL;
	}

	void deleteTeacher(string name, string surname) {
		if (searchTeacher(name, surname))
			for (int i = 0; i < teachers.size(); i++)
				if (teachers[i]->getName() == name && teachers[i]->getSurname() == surname) {
					Teacher* temp = teachers[i];
					teachers.erase(teachers.begin() + i);
					delete temp;
				}
	}

	bool searchTeacher(string name, string surname) {
		for (Teacher *i : teachers)
			if (i->getName() == name && i->getSurname() == surname)
				return true;

		return false;
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

	bool searchClass(char letterClass, int numberClass) {
		for (SchoolClass* i : classes)
			if (i->getLetterClass() == letterClass && i->getNumberClass() == numberClass)
				return true;

		return false;
	}

	string getTitleSchool() {
		return title;
	}

	int getCountStudents() {
		int count = 0;

		for (SchoolClass* i : classes)
			count += i->getCountStudents();

		return count;
	}

	int getCountTeachers() {
		return teachers.size();
	}
};