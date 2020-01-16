#pragma once

#include <vector>

template <typename T>
class VectorHuman {
protected:
	vector<T*> humans;

public:
	void addHuman(T* object) {
		if (!searchHuman(object->getName(), object->getSurname()))
			humans.push_back(object);
	}

	void deleteHuman(string name, string surname) {
		for (int i = humans.begin(); i < humans.size(); i++)
			if (humans[i]->getName() == name && humans[i]->getSurname() == surname) {
				T* temp = this[i];
				humans.erase(humans.begin() + i);
			}
	}

	T* getHuman(string name, string surname) {
		for (T* i : humans)
			if (i->getName() == name && i->getSurname() == surname)
				return i;
		return NULL;
	}

	int getCountHumans() {
		return humans.size();
	}

	vector<T*> getvectorStudents() {
		vector<T*> temp;

		for (T* i : humans)
			temp.push_back(i);

		return temp;
	}

	bool searchHuman(string name, string surname) {
		for (T* i : humans)
			if (i->getName() == name && i->getSurname() == surname)
				return true;
		return false;
	}
};