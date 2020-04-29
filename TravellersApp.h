#pragma once
#include<iostream>
#include "User.h"
#include "DynArray.h"
using std::cin;

class TravellersApp {
	DynArray<User> users;
	User* currentUser;		// Ако е nullptr, няма вписан потребител
							// Ако има вписан потребител, сочи него
public:
	TravellersApp() {
		users = DynArray<User>();
		currentUser = nullptr;
	}

	void registration() {
		String username;
		String password;
		String email;
		cout << "Please enter username, password, email:" << endl;
		cin >> username >> password >> email;

		for (int i = 0; i < users.getSize(); ++i) {
			if (users[i].getUsername()==username) {
				cout << "Username not available" << endl;
				return;
			}
		}

		User newUser(username, password, email);
		users.addElement(newUser);
	}

	void login() {
		if (currentUser == nullptr) {
			String username;
			String password;
			cout << "Enter username and password:" << endl;
			cin >> username >> password;
			for (int i = 0; i < users.getSize(); ++i) {
				if (users[i].hasUsernameAndPassword(username, password)) {
					currentUser = &users[i];
					cout << "Login was successful" << endl;
					return;
				}
			}
			cout << "Unsuccessful login" << endl;
		}
		else {
			cout << "A user has already logged. Please logout and retry" << endl;
		}
	}

	void logout() {
		currentUser = nullptr;
	}
}