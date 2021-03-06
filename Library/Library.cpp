// Library.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include"Person.h"
#include"Book.h"
#include"Author.h"
#include"BooksContainer.h"
#include"Set.h"
#include"Community.h"
using namespace std;
bool sort(const Book& book1, const Book& book2) {
	if (book1.getAuthor() > book2.getAuthor()) return true;
	return false;
}
int main()
{
	Author a1("John", "Lithuanian", 100, BooksContainer(), BooksContainer());
	BooksContainer books;
	unsigned t = 100;
	books.insert(Book("Nemili-Nedragi", (unsigned)10, (litGenre)5, nullptr));
	books.insert(Book("Electra", (unsigned)1000, (litGenre)3, &a1));
	books.insert(Book("Electra", (unsigned)1000, (litGenre)3, &a1));
	Author rado = Author("Radomir Kolev", "Bulgarian", 100, BooksContainer(), BooksContainer());
	books.insert(Book("Hamlet", (unsigned)1000, (litGenre)1, &rado));
	books.sort(sort);
	cout << "Books By Author test\n";
	books.booksByAuthor(a1).print();
	a1.writeBook(books[1]);
	a1.writeBook(books[2]);
	a1.readBook(books[0]);
	a1.print();
	cout << "/author\n";
	Person p1;
	p1 = Person("Temp","Scandinavian",25);
	Person p2 = p1;
	p2 = p2;
	p2.print();
	p1.print();
	Reader r1;
	r1.print();

	a1.readBook(books[0]);
	a1.writeBook(Book());
	cout << "Author test:\n";
	a1.print();
	Book b("Antigone", (unsigned)1,Drama, &a1);
	cout << b;
	cout << "Community test, light\n";
	Community com;
	com.insert(a1);
	com.insert(r1);
	com.print();
	cout<<endl<<com.getReadingRank();
	//system("Pause");
    return 0;
}

