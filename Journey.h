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

		// Read comment
		
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
};
