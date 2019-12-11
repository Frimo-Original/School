#pragma once

class School {
private:
	deque<SchoolClass> classes;
	
public:
	void addStudent(Student student)
	{
		bool isSearch = false;

		for (SchoolClass i : classes)
			if (i.getLetterClass() == student.getLetterClass() && i.getNumberClass() == student.getNumberClass()) {
				i.addStudent(student);
				isSearch = true;
				break;
			}

		if (!isSearch) {
			createNewSchoolClass(student.getLetterClass(), student.getNumberClass());
			addStudent(student);
		}
	}

	void deleteStudent(string name, string surname) {
		for (SchoolClass i : classes)
			if (i.searchStudent(name, surname))
				i.deleteStudent(name, surname);
	}

	bool searchStudent(string name, string surname) {
		for (SchoolClass i : classes)
			if (i.searchStudent(name, surname))
				return true;

		return false;
	}

private:
	void createNewSchoolClass(char letterClass, int numberClass) {
		classes.push_back(SchoolClass(letterClass, numberClass));
	}
};