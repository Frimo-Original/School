#include <iostream>
#include <string>
#include <list>

#include "Student.h"
#include "Teacher.h"

using namespace std;

int main()
{
	Student student = Student("name", "surname", Date(10, 5, 19), 'A', 9);
	Student student2 = Student("name2", "surname2", Date(10, 5, 19), 'A', 9);
	Student student3 = Student("name2", "surname2", Date(10, 5, 19), 'A', 9);

	list<Student> students;

	students.push_back(student);
	students.push_back(student2);
	students.push_back(student3);

	cout << students.size();

	cin.get();
	return 0;
}