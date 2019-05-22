#include"stdafx.h"
#include "Book.h"
#include"Author.h"
#include <cstring>
#include <iostream>
Book::Book() : name(nullptr),numberOfPages(0), author(nullptr)
{
	this->setName("Book");
}

Book::Book(const char *name, const unsigned & numOfPages,const litGenre& litGenre, const Author * author ) : name(nullptr)
{
	this->genre = litGenre;
	this->author = author;
	setName(name);
	setNumberOfPages(numOfPages);
}

Book::Book(const Book & b) : Book(b.name,b.numberOfPages,b.genre,b.author)
{
}

Book & Book::operator=(const Book & b)
{
	if (this != &b) {
		this->setName(b.name);
		this->genre = b.genre;
		this->author = b.author;
		this->numberOfPages = b.numberOfPages;
	}
	return *this;
}


void Book::setAuthor(const Author * author)
{
	this->author = author;
}

void Book::setName(const char *name)
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

void Book::setNumberOfPages(const unsigned & numOfPages)
{
	this->numberOfPages = numOfPages;
}

void Book::setGenre(const litGenre & genre)
{
	this->genre = genre;
}

const Author * Book::getAuthor() const
{
	return this->author;
}

const char * Book::getName() const
{
	return this->name;
}

unsigned Book::getNumberOfPages() const
{
	return this->numberOfPages;
}

litGenre Book::getGenre() const
{
	return this->genre;
}

bool Book::operator==(const Book &b) const
{
	if (!strcmp(this->name, b.name))
		if (this->numberOfPages == b.numberOfPages)
			if (this->author == b.author)
				return true;
	return false;
}

void Book::print() const
{
	cout << "Book name:" << name << "\nPages:" << numberOfPages << "\nGenre:";
	switch (genre) {
	case Comedy:
		cout << "Comedy\n";
		break;
	case Drama:
		cout << "Drama\n";
		break;
	case Epic:
		cout << "Epic\n";
		break;
	case Erotic:
		cout << "Erotic\n";
		break;
	case Nonsense:
		cout << "Nonsense\n";
	case Lyric:
		cout << "Lyric\n";
		break;
	case Mythopoeia:
		cout << "Mythopoeia\n";
		break;
	case Romance:
		cout << "Romance\n";
		break;
	case Satire:
		cout << "Satire\n";
		break;
	case Tragedy:
		cout << "Tragedy\n";
		break;
	case Tragicomedy:
		cout << "Tragicomedy\n";
		break;
	default:
		cout << "Undefined\n";
		break;
	}
	cout << "Author:" << (author ? author->getName() : "Unknown");
	cout << endl;
}

Book::~Book()
{
	delete[] this->name;
}

ostream & operator<<(ostream & out, const Book & b)
{
	out << "Book name:" << b.name << "\nPages:"<< b.numberOfPages<<"\nGenre:";
	switch (b.genre) {
	case Comedy:
		out << "Comedy\n";
		break;
	case Drama:
		out << "Drama\n";
		break;
	case Epic:
		out << "Epic\n";
		break;
	case Erotic:
		out << "Erotic\n";
		break;
	case Nonsense:
		out << "Nonsense\n";
	case Lyric:
		out << "Lyric\n";
		break;
	case Mythopoeia:
		out << "Mythopoeia\n";
		break;
	case Romance:
		out << "Romance\n";
		break;
	case Satire:
		out << "Satire\n";
		break;
	case Tragedy:
		out << "Tragedy\n";
		break;
	case Tragicomedy:
		out << "Tragicomedy\n";
		break;
	default:
		out << "Undefined\n";
		break;
	}
	out << "Author:" << (b.author?b.author->getName():"Unknown");
	out << endl;
	return out;
}

bool Book::operator<(const Book & b) const
{
	return !(*this >= b);
}

bool Book::operator>(const Book & b) const
{
	return !(*this <= b);
}

bool Book::operator<=(const Book & b) const
{
	int numberReference = (-1)*strcmp(this->name, b.name) + (*this->author <= *b.author) + (this->genre <= b.genre);
	return numberReference >= 0;
}

bool Book::operator>=(const Book & b) const
{
	int numberReference = strcmp(this->name, b.name) +  (*this->author >= *b.author) + (this->genre >= b.genre);
	return numberReference >= 0;
}

bool Book::operator!=(const Book & b) const
{
	return !(*this == b);
}

Book::operator bool() const
{
	if (this == nullptr) return false;
	else {
		return this->name != "" || this->author != nullptr || this->genre != 0 ;
	}
}
bool Book::operator!() const
{
	if (this == nullptr) return true;
	else return this->name == ""&&this->author == 0 && this->genre == 0;
}
