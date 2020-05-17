#pragma once
#include <iostream>
#include "String.h"
#include "DynArray.h"
using std::cin;
using std::cout;
using std::endl;

class Journey {
	String destination;
	String dateFrom;
	String dateTo;
	double grade;
	String comment;
	DynArray<String> photos;

public:
	void readJourney() {
		cout << "Enter your destination:" << endl;
		cin >> destination;
		cout << "Enter start date (YYYY-MM-DD):" << endl;
		cin >> dateFrom;
		cout << "Enter final date (YYYY-MM-DD):" << endl;
		cin >> dateTo;
		cout << "Enter your grade:" << endl;
		cin >> grade;
		
		cout << "Enter your comment (1 line, max 255 characters):" << endl;
		char commentArray[256];
		cin.ignore();						// Ignore one newline character
		cin.getline(commentArray, 255);
		comment = commentArray;
		
		cout << "How many photos do you want to upload?" << endl;
		int numberOfPhotos;
		cin >> numberOfPhotos;

		for (int i = 0; i < numberOfPhotos; ++i) {
			cout << "Upload a photo:" << endl;
			String photo;
			cin >> photo;
			photos.addElement(photo);
		}
	}

	void printJourney() const {
		cout << "Destionation: " << destination << endl;
		cout << "Start date: " << dateFrom << endl;
		cout << "Final date: " << dateTo << endl;
		cout << "Grade: " << grade << endl;
		cout << "Comment: " << endl << comment << endl;
		cout << "Photos: " << endl;
		for (int i = 0; i < photos.getSize(); ++i) {
			cout << photos[i] << endl;
		}
	}

	friend ostream& operator<<(ostream& out, const Journey& journey);
	friend istream& operator>>(istream& in, Journey& journey);
};

ostream& operator<<(ostream& out, const Journey& journey) {
	out << journey.destination << endl
		<< journey.dateFrom << endl
		<< journey.dateTo << endl
		<< journey.grade << endl
		<< journey.comment << endl
		<< "END_OF_COMMENT" << endl
		<< journey.photos.getSize() << endl;

	for (int i = 0; i < journey.photos.getSize(); ++i) {
		out << journey.photos[i] << endl;
	}
	return out;
}

istream& operator>>(istream& in, Journey& journey) {
	in >> journey.destination
		>> journey.dateFrom
		>> journey.dateTo
		>> journey.grade;
	
	String word;
	in >> word;

	while (word != "END_OF_COMMENT") {
		journey.comment = journey.comment + word + " ";
		in >> word;
	}

	int numberOfPhotos;
	in >> numberOfPhotos;
	for (int i = 0; i < numberOfPhotos; ++i) {
		String photo;
		in >> photo;
		journey.photos.addElement(photo);
	}

	return in;
}