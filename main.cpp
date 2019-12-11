#include <iostream>
#include <string>
#include <deque>

#include "Student.h"
#include "Teacher.h"
#include "SchoolClass.h"
#include "School.h"

using namespace std;

int main()
{
	School school;

	Student student("name", "surname", Date(10, 5, 19), 'A', 9);
	Student student2("name2", "surname2", Date(10, 5, 19), 'B', 9);
	Student student3("name3", "surname3", Date(10, 5, 19), 'C', 9);

	school.addStudent(student);
	school.addStudent(student2);
	school.addStudent(student3);

	string searchName("name2"), searchSurname("surname2");

	cout << school.searchStudent(searchName, searchSurname) << endl;

	cin.get();
	return 0;
}