#pragma once
#include"stdafx.h"
#include<iostream>
#include<assert.h>
template <typename T>
class Set {
private:
	T * * objects;
	int size;
	int capacity;
	void resize(const int&);
public:
	Set<T>();
	Set<T>(const Set<T>&);
	Set<T>& operator=(const Set<T>&);
	virtual void print() const;
	bool isIn(const T&) const;
	void insert(const T&);
	void remove(const T&);
	void empty();
	T& operator[](const int&);
	const T& operator[](const int&) const;
	int getSize() const;
	virtual ~Set();

};
template<typename T>
void Set<T>::resize(const int& newCapacity){
	T** temp = objects;
	this->objects = new T*[newCapacity];
	for (int i = 0; i < size; i++) {
		this->objects[i] = temp[i];
	}
	this->capacity = newCapacity;
	delete[] temp;
};


template<typename T>
Set<T>& Set<T>::operator=(const Set<T>& other)
{
	if (this != &other) {
		for (int i = 0; i < size; i++) {
			delete this->objects[i];
		}
		delete[] this->objects;
		this->objects = new T*[other.capacity];
		for (int i = 0; i < other.size; i++) {
			this->objects[i] = new T(other.objects[i]);
		}
		this->size = other.size;
		this->capacity = other.capacity;
	}
	return *this;
}

template<typename T>
void Set<T>::print() const
{
	for (int i = 0; i < this->size; i++) {
		this->objects[i]->print();
	}
}

template<typename T>
bool Set<T>::isIn(const T & obj) const
{
	for (int i = 0; i < size; i++) {
		if (*objects[i] == obj) return true;
	}
	return false;
}

template<typename T>
void Set<T>::insert(const T & obj)
{
	if (!isIn(obj)) {
		if (size + 1 == capacity) resize(capacity*2);
		this->objects[size] = new T(obj);
		size++;
	}
}

template<typename T>
void Set<T>::remove(const T & obj)
{
	bool found = false;
	for (int i = 0; i < size; i++) {
		if (!found) {
			if (obj == *objects[i]) {
				delete objects[i];
				found = true;
			}
		}
		else
				objects[i - 1] = objects[i];
		}
	if(found)
		size--;
	if (size < capacity / 2) resize(this->capacity / 2);
}

template<typename T>
inline void Set<T>::empty()
{
	for (int i = 0; i < size; i++) {
		delete objects[i];
	}
	delete[] this->objects;
	this->objects = new T*[4];
	this->size = 0;
	this->capacity = 4;
}

template<typename T>
inline T& Set<T>::operator[](const int &index)
{
	assert(index >= 0 && index < size);
	return *(objects[index]);
}

template<typename T>
inline const T& Set<T>::operator[](const int & index) const
{
	assert(index >= 0 && index < size);
	return *(objects[index]);
}

template<typename T>
inline int Set<T>::getSize() const
{
	return this->size;
}

template<typename T>
Set<T>::~Set()
{
		for (int i = 0; i < size; i++) {
			delete objects[i];
		}
		delete[] objects;
}

template<typename T>
Set<T>::Set() : size(0),capacity(4)
{
	this->objects = new T*[4];
}

template<typename T>
Set<T>::Set(const Set<T>& other) : size(other.size), capacity(other.capacity)
{
	this->objects = new T*[other.capacity];
	for (int i = 0; i < other.size; i++) {
		this->objects[i] = new T(*other.objects[i]);
	}
}
