#include "stdafx.h"
#include "BooksContainer.h"

void BooksContainer::sort(bool(*compareBooks)(const Book &book1, const Book &book2))
{
	for (int i = 0; i < getSize() - 1; i++) {
		for (int j = i + 1; j < getSize(); j++) {
			if (compareBooks((*this)[i],(*this)[j])) {
				Book temp = (*this)[i];
				(*this)[i] = (*this)[j];
				(*this)[j] = temp;
			}
		}
	}
}

BooksContainer BooksContainer::booksByAuthor(const Author & author)
{
	BooksContainer result;
	for (int i = 0; i < getSize(); i++)
		if ((*this)[i].getAuthor() == &author)
			result.insert((*this)[i]);
	return result;
}

BooksContainer & BooksContainer::operator=(const BooksContainer & bc)
{
	if (this != &bc) {
		this->empty();
		for (int i = 0; i < bc.getSize(); i++) {
			this->insert(bc[i]);
		}
	}
	return *this;
}


bool BooksContainer::operator==(const BooksContainer & bc) const
{
	if (this->getSize() == bc.getSize()) {
		for (int i = 0; i < this->getSize(); i++) {
			if (!((*this)[i] == bc[i]))return false;
		}
		return true;
	}
	return false;
}

ostream & operator<<(ostream & out, const BooksContainer & bc)
{
	for (int i = 0; i < bc.getSize(); i++) {
		 out << bc[i];
	}
	return out;
}
