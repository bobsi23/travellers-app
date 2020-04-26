#pragma once
#include<iostream>
#include "User.h"
#include "DynArray.h"
using std::cin;

class TravellersApp {
	DynArray<User> users;
	User* currentUser;

public:
	TravellersApp() {
		users = DynArray<User>();
		currentUser = nullptr;
	}

	void registration() {
		String username;
		String password;
		String email;
		cin >> username >> password >> email;

		User newUser(username, password, email);
		users.addElement(newUser);
	}

	void login() {

	}

	void logout() {

	}
}