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
			cout << "Введите название школы: ";
			cin >> schoolTitle;
		} while (schoolTitle.length() <= 0);

		school = new School(schoolTitle);

		int action;
		bool isExit = false;

		while (!isExit) {
			cout << "Действия:" << endl;
			cout << "0 - добавить ученика" << endl;
			cout << "1 - удалить ученика" << endl;
			cout << "2 - добавить учителя" << endl;
			cout << "3 - удалить учителя" << endl;
			cout << "4 - получить количество учеников" << endl;
			cout << "5 - получить количество учителей" << endl;
			cout << "6 - вывести название школы" << endl;
			cout << "7 - вывести данные всех учеников" << endl;
			cout << "8 - вывести данные всех учеников класса" << endl;
			cout << "9 - выход" << endl;

			do {
				cout << "Введите номер действия: ";
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
				cout << "Количество учеников в школе: " << school->getCountStudents() << endl;
				break;

			case Actions::GET_COUNT_TEACHERS:
				cout << "Количество учителей в школе: " << school->getCountTeachers() << endl;
				break;

			case Actions::GET_TITLE_SCHOOL:
				cout << "Название школы: " << school->getTitleSchool() << endl;
				break;

			case Actions::PRINT_DATA_STUDENTS:
				cout << "    Имя     Фамилия    Дата рождения    Класс" << endl << endl;
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
			cout << "Введите имя ученика: ";
			cin >> name;
			cout << "Введите фамилию ученика: ";
			cin >> surname;
		} while (name.length() < 3 || surname.length() < 3);

		int day, month, year;

		cout << "Введите дату рождения (через пробел - день, месяц и год): ";
		cin >> day >> month >> year;

		char letterClass;
		int numberClass;

		do {
			cout << "Введите букву класса (английская большая буква): ";
			cin >> letterClass;
			cout << "Введите номер класса: ";
			cin >> numberClass;
		} while (letterClass < 'A' || letterClass > 'Z' || numberClass > 11 || numberClass < 1);

		if (!school->searchClass(letterClass, numberClass)) {
			school->addClass(letterClass, numberClass);
			school->getSchoolClass(letterClass, numberClass)->addStudent(name, surname, { day, month, year });
			cout << "Успешно!" << endl;
		}

		else {
			SchoolClass* schoolClass = school->getSchoolClass(letterClass, numberClass);

			if (!schoolClass->searchStudent(name, surname)) {
				schoolClass->addStudent(name, surname, { day, month, year });
				cout << "Успешно!" << endl;
			}

			else
				cout << "Такой ученик уже обучается в школе!" << endl;
		}
	}

	void deleteStudent()
	{
		string name, surname;
		char letterClass;
		int numberClass;

		do {
			cout << "Введите имя ученика: ";
			cin >> name;
			cout << "Введите фамилию ученика: ";
			cin >> surname;
			cout << "Введите букву класса где он обучается (английская большая буква): ";
			cin >> letterClass;
			cout << "Введите номер класса где он обучается: ";
			cin >> numberClass;
		} while (name.length() < 3 || surname.length() < 3 || letterClass < 'A' ||
			letterClass > 'Z' || numberClass > 11 || numberClass < 1);

		if (school->searchClass(letterClass, numberClass)) {
			SchoolClass* temp = school->getSchoolClass(letterClass, numberClass);

			if (temp->searchStudent(name, surname)) {
				temp->deleteStudent(name, surname);
				cout << "Ученик уален!" << endl;
			}

			else
				cout << "Такого ученика не существует!" << endl;
		}

		else
			cout << "Такого класса с этим учеником не существует!" << endl;
	}

	void addTeacher()
	{
		string name, surname;

		do {
			cout << "Введите имя учителя: ";
			cin >> name;
			cout << "Введите фамилию учителя: ";
			cin >> surname;
		} while (name.length() < 3 || surname.length() < 3);

		int day, month, year;

		cout << "Введите дату рождения (через пробел - день, месяц и год): ";
		cin >> day >> month >> year;

		cout << "Существующие специальности:" << endl;
		cout << "0 - математика" << endl;
		cout << "1 - физика" << endl;
		cout << "2 - биология" << endl;
		cout << "3 - информатика" << endl;

		int specialty;

		do {
			cout << "Введите специальность учителя: ";
			cin >> specialty;
		} while (specialty > 3 || specialty < 0);

		if (!school->searchTeacher(name, surname)) {
			school->addTeacher(name, surname, { day, month, year }, (Teacher::Specialty) specialty);
			cout << "Учитель добавлен!" << endl;
		}

		else
			cout << "Такой учитель уже существует!" << endl;
	}

	void deleteTeacher()
	{
		string name, surname;

		do {
			cout << "Введите имя учителя: ";
			cin >> name;
			cout << "Введите фамилию учителя: ";
			cin >> surname;
		} while (name.length() < 3 || surname.length() < 3);

		if (school->searchTeacher(name, surname)) {
			school->deleteTeacher(name, surname);
			cout << "Учитель удален!" << endl;
		}

		else
			cout << "Такого учителя не существует!" << endl;
	}

	void printDataClassStudents()
	{
		char letterClass;
		int numberClass;

		do {
			cout << "Введите букву класса (английская большая буква): ";
			cin >> letterClass;
			cout << "Введите номер класса: ";
			cin >> numberClass;
		} while (letterClass < 'A' || letterClass > 'Z' || numberClass > 11 || numberClass < 1);

		SchoolClass* schoolClass = school->getSchoolClass(letterClass, numberClass);

		if (schoolClass != NULL) {
			cout << "    Имя     Фамилия    Дата рождения    Класс " << numberClass << " - " << letterClass << endl << endl;

			for (Student* i : schoolClass->getStudents()) {
				cout << "    " << i->getName() << "    " << i->getSurname() << "    ";
				cout << i->getBirthday().getDay() << "." << i->getBirthday().getMonth() << "." << i->getBirthday().getYear() << "    " << endl;
			}

			cout << endl;
		}

		else
			cout << "Такого класса нет!" << endl;
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