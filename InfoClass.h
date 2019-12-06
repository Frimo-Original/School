#pragma once

class InfoClass {
private:
	char letterClass;
	int numberClass;

public:
	InfoClass(char letterClass, int numberClass) : letterClass(letterClass), numberClass(numberClass) {}

	char getLetterClass() {
		return letterClass;
	}

	int getNumberClass() {
		return numberClass;
	}
};