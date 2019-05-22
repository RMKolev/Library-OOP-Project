#pragma once
#include<fstream>
class Person {
private:
	char* name;
	char* nationality;
	int age;
public:
	Person();
	Person(const char*, const char*, const int&);
	Person(const Person&);
	
	const char* getName() const;
	const char* getNationality() const;
	int getAge() const;

	void setName(const char*);
	void setNationality(const char*);
	void setAge(const int&);
	Person& operator=(const Person&);

	bool operator<(const Person&) const;
	bool operator>(const Person&) const;
	bool operator<=(const Person&) const;
	bool operator>=(const Person&) const;
	bool operator!=(const Person&) const;
	bool operator==(const Person&) const;
	operator bool() const;
	bool operator!() const;

	virtual void print() const;

	virtual ~Person();
};