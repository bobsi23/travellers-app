#pragma once
#include "User.h"

template <typename T>
class DynArray {
	T* arr;
	int size;
	int capacity;

	void copyFrom(const DynArray<T>& other) {
		size = other.size;
		capacity = other.capacity;
		arr = new T[capacity];

		for (int i = 0; i < size; ++i) {
			arr[i] = other.arr[i];
		}
	}

public:
	DynArray() {
		size = 0;
		capacity = 16;
		arr = new T[capacity];
	}

	DynArray(const DynArray<T>& other) {
		copyFrom(other);
	}

	DynArray<T>& operator=(const DynArray<T>& other) {
		if (this != &other) {
			delete[] arr;
			copyFrom(other);
		}
		return *this;
	}

	~DynArray() {
		delete[] arr;
	}

	void addElement(const T& newElement) {
		if (capacity == size) {
			capacity = capacity * 2;
			T* helper = new T[capacity];

			for (int i = 0; i < size; ++i) {
				helper[i] = arr[i];
			}
			
			delete[] arr;
			arr = helper;	
		}
		arr[size] = newElement;
		++size;
	}

	int getSize() const {
		return size;
	}

	T operator[] (int i) const {
		return arr[i];
	}
};
