#include "stdafx.h"
#include "Person.h"
#include<iostream>
#include<cstring>
Person::Person() : Person("John", "American",18)
{
}
Person::Person(const char *name, const char * nationality, const int & age) :
	name(nullptr), nationality(nullptr)
{
	setName(name);
	setNationality(nationality);
	setAge(age);
}

Person::Person(const Person & p) :
	Person(p.name,p.nationality,p.age)
{
}

const char * Person::getName() const
{
	return this->name;
}

const char * Person::getNationality() const
{
	return this->nationality;
}

int Person::getAge() const
{
	return this->age;
}

void Person::setName(const char * name)
{
		delete[] this->name;
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
}

void Person::setNationality(const char *nationality)
{

		delete[] this->nationality;
		this->nationality = new char[strlen(nationality) + 1];
		strcpy_s(this->nationality, strlen(nationality) + 1, nationality);
}

void Person::setAge(const int & age)
{
	if (age > 0) this->age = age;
}

Person & Person::operator=(const Person & p)
{
	if (this != &p) {
		setName(p.name);
		setNationality(p.nationality);
		setAge(p.age);
	}
	return *this;
}

void Person::print() const
{
	std::cout << "Person\n";
	std::cout << "Name:" << this->name << "\nAge:" << this->age << "\nNationality:" << this->nationality<<"\n";
}

Person::~Person()
{
	delete[] this->name;
	delete[] this->nationality;
}

bool Person::operator==(const Person & p) const
{
	if (!strcmp(this->name, p.name))
		if (!strcmp(this->nationality, p.nationality))
			if (this->age == p.age)
				return true;
	return false;
}

Person::operator bool() const
{
	return (bool)this->name;
}
bool Person::operator>(const Person & p) const
{
	return !(*this <= p);
}

bool Person::operator<=(const Person & p) const
{
	int numberReference = (-1)*strcmp(this->name, p.name) + (-1)*strcmp(this->nationality, p.nationality);
	return numberReference >= 0;
}

bool Person::operator>=(const Person & p) const
{
	int numberReference = strcmp(this->name, p.name) + strcmp(this->nationality, p.nationality);
	return numberReference >= 0;
}

bool Person::operator!=(const Person & p) const
{
	return !(*this == p);
}
bool Person::operator!() const
{
	if (this == nullptr) return 1;
	return (strlen(this->name) == 0 && strlen(this->nationality) == 0);
}
bool Person::operator<(const Person & p) const
{
	return !(*this >= p);
}