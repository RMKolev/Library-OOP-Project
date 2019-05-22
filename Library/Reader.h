#pragma once
#include"Person.h"
#include"BooksContainer.h"
#include"ReadingRankable.h"
class Reader :public Person, public ReadingRankable {
private:
	BooksContainer readBooks;
public:
	Reader();
	Reader(const char*, const char*, const int&, const BooksContainer&);
	Reader(const Reader&);
	void readBook(const Book&);
	int getReadBooksCount() const;
	virtual void print() const;
	bool operator==(const Reader&) const;
	virtual int getReadingRank();
};