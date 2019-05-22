#include"stdafx.h"
#include "Author.h"
#include<cstring>
#include<iostream>

Author::Author() : Reader(),writtenBooks()
{
}

Author::Author(const char *name, const char *nationality, const int & age, const BooksContainer & readBooks, const BooksContainer & writtenBooks)
	: Reader(name,nationality,age,readBooks)
{
	this->writtenBooks = writtenBooks;
}

Author::Author(const Author & a) : Reader(a)
{
	this->writtenBooks = a.writtenBooks;
}

BooksContainer Author::getWrittenBooks() const
{
	return this->writtenBooks;
}

void Author::print() const
{
	Reader::print();
	cout << "Books Written:\n";
	for (int i = 0; i < writtenBooks.getSize(); i++) {
		if (&writtenBooks[i]) cout << writtenBooks[i].getName() << ";";
	}
	cout << endl;
}

void Author::writeBook(const Book & b)
{
	this->writtenBooks.insert(b);
}

bool Author::operator==(const Author &a) const
{
	if (!strcmp(this->getName(), a.getName()))
		if (!strcmp(this->getNationality(), a.getNationality()))
			if(this->getAge()==a.getAge())
			return true;
	return false;
}

int Author::getWritingRank()
{
	int rank = 0;
	for (int i = 0; i < writtenBooks.getSize(); i++)
		rank += writtenBooks[i].getNumberOfPages();
	return rank / 100;
}

