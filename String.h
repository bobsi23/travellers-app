#pragma once
#include "stringFunctions.h"
#include <fstream>
using std::istream;
using std::ostream;

class String {
	char* arr;

	bool isDigit(char symbol) const {
		return symbol >= '0' && symbol <= '9';
	}

public:
	String() {
		arr = new char[1];
		arr[0] = '\0';
	}

	String(const char* _arr) {
		arr = new char[strlen(_arr) + 1];
		copyString(arr, _arr);
	}

	String(const String& other) {

		arr = new char[strlen(other.arr) + 1];
		copyString(arr, other.arr);
	}

	String& operator=(const String& other) {
		if (this != &other) {
			delete[] arr;
			arr = new char[strlen(other.arr) + 1];
			copyString(arr, other.arr);
		}
		return *this;
	}

	~String() {
		delete[] arr;
	}

	bool operator==(const String& other) const {
		return equal(arr, other.arr);
	}

	bool isNumber() const {
		for (int i = 0; arr[i] != '\0'; ++i) {
			if (!isDigit(arr[i])) {
				return false;
			}
		}
		return true;
	}

	int asNumber() const {
		int number = 0;

		for (int i = 0; arr[i] != '\0'; ++i) {
			int nextDigit = arr[i] - '0';
			number = number * 10 + nextDigit;
		}

		return number;
	}

	const char* getArr() const {
		return arr;
	}
};

istream& operator>>(istream& in, String& str) {
	char temp[100];
	in >> temp;
	str = String(temp);
	return in;
}

ostream& operator<<(ostream& out, const String& str) {
	out << str.getArr();
	return out;
}
