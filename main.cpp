#include <iostream>
#include <locale>
#include <windows.h>

#include "SchoolClass.h"
#include "School.h"
#include "MenagementConsole.h"
#include "VectorHuman.h"

int main()
{
	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//MenagementConsole mc = MenagementConsole();

	School school("Name School");
	VectorSchoolClasses* listClasses = school.getVectorSchoolClasses();
	listClasses->addClass('A', 9);
	SchoolClass* classA = listClasses->getSchoolClass('A', 9);
	classA->getVectorStudents()->addHuman(new Student("name", "surname", {10, 10, 10}, 'A', 9));

	cout << school.getCountStudents();

	//cin.get();
	//cin.get();

	return 0;
}