#pragma once
#include"Set.h"
#include"Book.h"
class BooksContainer : public Set<Book> {
public:
	void sort(bool(*compareBooks)(const Book& book1, const Book& book2));
	BooksContainer booksByAuthor(const Author& author);
	BooksContainer& operator=(const BooksContainer&);
	bool operator==(const BooksContainer&) const;

	friend ostream& operator<<(ostream&, const BooksContainer&);
};