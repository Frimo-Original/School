#include <iostream>
#include <locale>
#include <windows.h>

#include "SchoolClass.h"
#include "School.h"

class MenagementConsole
{
private:
	School* school;

	static enum Actions {
		ADD_STUDENT,
		DELETE_STUDENT,
		ADD_TEACHER,
		DELETE_TEACHER,
		GET_COUNT_STUDENTS,
		GET_COUNT_TEACHERS,
		GET_TITLE_SCHOOL,
		PRINT_DATA_STUDENTS,
		PRINT_DATA_CLASS_STUDENTS,
		EXIT
	};

public:
	MenagementConsole()
	{
		string schoolTitle;

		do {
			cout << "������� �������� �����: ";
			cin >> schoolTitle;
		} while (schoolTitle.length() <= 0);

		school = new School(schoolTitle);

		int action;
		bool isExit = false;

		while (!isExit) {
			cout << "��������:" << endl;
			cout << "0 - �������� �������" << endl;
			cout << "1 - ������� �������" << endl;
			cout << "2 - �������� �������" << endl;
			cout << "3 - ������� �������" << endl;
			cout << "4 - �������� ���������� ��������" << endl;
			cout << "5 - �������� ���������� ��������" << endl;
			cout << "6 - ������� �������� �����" << endl;
			cout << "7 - ������� ������ ���� ��������" << endl;
			cout << "8 - ������� ������ ���� �������� ������" << endl;
			cout << "9 - �����" << endl;

			do {
				cout << "������� ����� ��������: ";
				cin >> action;
			} while (action < 0 || action > (int) Actions::EXIT);

			switch (action)
			{
			case Actions::ADD_STUDENT:
				addStudent();
				break;

			case Actions::DELETE_STUDENT:
				deleteStudent();
				break;

			case Actions::ADD_TEACHER:
				addTeacher();
				break;

			case Actions::DELETE_TEACHER:
				deleteTeacher();
				break;

			case Actions::GET_COUNT_STUDENTS:
				cout << "���������� �������� � �����: " << school->getCountStudents() << endl;
				break;

			case Actions::GET_COUNT_TEACHERS:
				cout << "���������� �������� � �����: " << school->getCountTeachers() << endl;
				break;

			case Actions::GET_TITLE_SCHOOL:
				cout << "�������� �����: " << school->getTitleSchool() << endl;
				break;

			case Actions::PRINT_DATA_STUDENTS:
				cout << "    ���     �������    ���� ��������    �����" << endl << endl;
				for (Student* i : school->getListStudents()) {
					cout << "    " << i->getName() << "    " << i->getSurname() << "    ";
					cout << i->getBirthday().getDay() << "." << i->getBirthday().getMonth() << "." << i->getBirthday().getYear() << "    ";
					cout << i->getNumberClass()<< " - " << i->getLetterClass() << endl;
				}

				cout << endl;
				break;

			case Actions::PRINT_DATA_CLASS_STUDENTS:
				printDataClassStudents();
				break;

			case Actions::EXIT:
				isExit = true;
				break;
			}
		}
	}

	void addStudent() {
		string name, surname;

		do {
			cout << "������� ��� �������: ";
			cin >> name;
			cout << "������� ������� �������: ";
			cin >> surname;
		} while (name.length() < 3 || surname.length() < 3);

		int day, month, year;

		cout << "������� ���� �������� (����� ������ - ����, ����� � ���): ";
		cin >> day >> month >> year;

		char letterClass;
		int numberClass;

		do {
			cout << "������� ����� ������ (���������� ������� �����): ";
			cin >> letterClass;
			cout << "������� ����� ������: ";
			cin >> numberClass;
		} while (letterClass < 'A' || letterClass > 'Z' || numberClass > 11 || numberClass < 1);

		if (!school->searchClass(letterClass, numberClass)) {
			school->addClass(letterClass, numberClass);
			school->getSchoolClass(letterClass, numberClass)->addStudent(name, surname, { day, month, year });
			cout << "�������!" << endl;
		}

		else {
			SchoolClass* schoolClass = school->getSchoolClass(letterClass, numberClass);

			if (!schoolClass->searchStudent(name, surname)) {
				schoolClass->addStudent(name, surname, { day, month, year });
				cout << "�������!" << endl;
			}

			else
				cout << "����� ������ ��� ��������� � �����!" << endl;
		}
	}

	void deleteStudent()
	{
		string name, surname;
		char letterClass;
		int numberClass;

		do {
			cout << "������� ��� �������: ";
			cin >> name;
			cout << "������� ������� �������: ";
			cin >> surname;
			cout << "������� ����� ������ ��� �� ��������� (���������� ������� �����): ";
			cin >> letterClass;
			cout << "������� ����� ������ ��� �� ���������: ";
			cin >> numberClass;
		} while (name.length() < 3 || surname.length() < 3 || letterClass < 'A' ||
			letterClass > 'Z' || numberClass > 11 || numberClass < 1);

		if (school->searchClass(letterClass, numberClass)) {
			SchoolClass* temp = school->getSchoolClass(letterClass, numberClass);

			if (temp->searchStudent(name, surname)) {
				temp->deleteStudent(name, surname);
				cout << "������ �����!" << endl;
			}

			else
				cout << "������ ������� �� ����������!" << endl;
		}

		else
			cout << "������ ������ � ���� �������� �� ����������!" << endl;
	}

	void addTeacher()
	{
		string name, surname;

		do {
			cout << "������� ��� �������: ";
			cin >> name;
			cout << "������� ������� �������: ";
			cin >> surname;
		} while (name.length() < 3 || surname.length() < 3);

		int day, month, year;

		cout << "������� ���� �������� (����� ������ - ����, ����� � ���): ";
		cin >> day >> month >> year;

		cout << "������������ �������������:" << endl;
		cout << "0 - ����������" << endl;
		cout << "1 - ������" << endl;
		cout << "2 - ��������" << endl;
		cout << "3 - �����������" << endl;

		int specialty;

		do {
			cout << "������� ������������� �������: ";
			cin >> specialty;
		} while (specialty > 3 || specialty < 0);

		if (!school->searchTeacher(name, surname)) {
			school->addTeacher(name, surname, { day, month, year }, (Teacher::Specialty) specialty);
			cout << "������� ��������!" << endl;
		}

		else
			cout << "����� ������� ��� ����������!" << endl;
	}

	void deleteTeacher()
	{
		string name, surname;

		do {
			cout << "������� ��� �������: ";
			cin >> name;
			cout << "������� ������� �������: ";
			cin >> surname;
		} while (name.length() < 3 || surname.length() < 3);

		if (school->searchTeacher(name, surname)) {
			school->deleteTeacher(name, surname);
			cout << "������� ������!" << endl;
		}

		else
			cout << "������ ������� �� ����������!" << endl;
	}

	void printDataClassStudents()
	{
		char letterClass;
		int numberClass;

		do {
			cout << "������� ����� ������ (���������� ������� �����): ";
			cin >> letterClass;
			cout << "������� ����� ������: ";
			cin >> numberClass;
		} while (letterClass < 'A' || letterClass > 'Z' || numberClass > 11 || numberClass < 1);

		SchoolClass* schoolClass = school->getSchoolClass(letterClass, numberClass);

		if (schoolClass != NULL) {
			cout << "    ���     �������    ���� ��������    ����� " << numberClass << " - " << letterClass << endl << endl;

			for (Student* i : schoolClass->getStudents()) {
				cout << "    " << i->getName() << "    " << i->getSurname() << "    ";
				cout << i->getBirthday().getDay() << "." << i->getBirthday().getMonth() << "." << i->getBirthday().getYear() << "    " << endl;
			}

			cout << endl;
		}

		else
			cout << "������ ������ ���!" << endl;
	}

	~MenagementConsole() {
		delete school;
	}
};

int main()
{
	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	MenagementConsole mc = MenagementConsole();

	cin.get();
	cin.get();

	return 0;
}