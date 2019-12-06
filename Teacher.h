
#include "Human.h"

class Teacher : public Human {
public:
	static enum Specialty {
		MATHS,
		PHYSICS,
		BIOLOGY,
		COMPUTER_SCIENCE
	};

private:
	Specialty specialty;

public:
	Teacher(string name, string surname, Date birthday, Specialty specialty) : Human(name, surname, birthday),
		specialty(specialty) {
	}

	string getSpecialty()
	{
		switch (specialty)
		{
		case MATHS:
			return "Maths";
		case BIOLOGY:
			return "Biology";
		case PHYSICS:
			return "Physics";
		case COMPUTER_SCIENCE:
			return "Computer science";
		}
	}
};