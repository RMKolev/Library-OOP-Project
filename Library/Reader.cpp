#include "stdafx.h"
#include "Reader.h"
#include<iostream>
Reader::Reader() : Person(), readBooks()
{
}

Reader::Reader(const char * name, const char * nationality, const int & age, const BooksContainer & readBooks) :
	Person(name,nationality,age)
{
	this->readBooks = readBooks;
}

Reader::Reader(const Reader & r) : Person(r)
{
	this->readBooks = r.readBooks;
	
}

void Reader::readBook(const Book & b)
{
	this->readBooks.insert(b);
}

int Reader::getReadBooksCount() const
{
	return this->readBooks.getSize();
}

void Reader::print() const
{
	Person::print();
	cout << "Read books:";
	for (int i = 0; i < this->readBooks.getSize(); i++) {
		std::cout << (this->readBooks[i].getName()) << " ";
	}
	cout << endl;
}

bool Reader::operator==(const Reader & r) const
{
	if (Person::operator==(r))
		if (this->readBooks == r.readBooks)
			return true;
	return false;
}

int Reader::getReadingRank()
{
	int rank = 0;
	for (int i = 0; i < readBooks.getSize(); i++)
		rank += readBooks[i].getNumberOfPages();
	return rank / 100;
}
