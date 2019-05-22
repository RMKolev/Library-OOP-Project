#pragma once
#include<iostream>
#include"Reader.h"
#include"BooksContainer.h"
#include"WritingRankable.h"
using namespace std;
class Book;
class Author : public Reader{
private:
	BooksContainer writtenBooks;
public:
	Author();
	Author(const char*, const char*, const int&, const BooksContainer&, const BooksContainer&);
	Author(const Author&);

	BooksContainer getWrittenBooks() const;
	virtual void print() const;
	void writeBook(const Book&);
	bool operator==(const Author&) const;
	virtual int getWritingRank();
};