#pragma once
#include<istream>
using namespace std;
enum litGenre { Undefined,Comedy, Drama, Epic, Erotic, Nonsense, Lyric, Mythopoeia, Romance, Satire, Tragedy, Tragicomedy };
class Author;
class Book {
private:
	char* name;
	litGenre genre;
	unsigned numberOfPages;

	const Author* author;
public:
	Book();
	Book(const char*, const unsigned&,const litGenre&, const Author*);
	Book(const Book&);
	Book& operator=(const Book&);

	void setAuthor(const Author*);
	void setName(const char*);
	void setNumberOfPages(const unsigned&);
	void setGenre(const litGenre&);

	const Author* getAuthor() const;
	const char* getName() const;
	unsigned getNumberOfPages() const;
	litGenre getGenre() const;
	bool operator==(const Book&) const;
	bool operator<(const Book& b) const;
	bool operator>(const  Book& b) const;
	bool operator<=(const  Book& b) const;
	bool operator>=(const  Book& b) const;
	bool operator!=(const  Book& b) const;
	operator bool() const;
	bool operator!() const;
	void print() const;
	friend ostream& operator<<(ostream&, const Book&);
	~Book();
};
