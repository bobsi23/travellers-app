#pragma once
#include <iostream>
#include "String.h"

using std::cin;
using std::cout;
using std::endl;

class User {

	String username, password, email;

public:
	User() {
		username = "\0";
		password = "\0";
		email = "\0";
	}

	User(const String& _username, const String& _password, const String& _email) {
		username = _username;
		password = _password;
		email=_email;
			
	}
	
	void printUsername() const {
		cout << "Name: " << username << endl;
		cout << "Email: " << email << endl;

	}
	
};