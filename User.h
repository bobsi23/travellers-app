#pragma once
#include <iostream>
#include "String.h"
using std::cin;
using std::cout;
using std::endl;

class User {
	String username;
	String password;
	String email;

public:
	User() {
		username = "";
		password = "";
		email = "";
	}

	User(const String& _username, const String& _password, const String& _email) {
		username = _username;
		password = _password;
		email = _email;
	}
	
	void printUsername() const {
		cout << "Name: " << username << endl;
		cout << "Email: " << email << endl;
	}
};