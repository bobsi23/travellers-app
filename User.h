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
	DynArray<String> friendsList;
	DynArray<String> waitingFriends;

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
	
	String getUsername() const {
		return username;
	}

	void printUsername() const {
		cout << "Name: " << username << endl;
		cout << "Email: " << email << endl;
	}

	bool hasUsernameAndPassword(const String& _username, const String& _password) const {
		return username == _username && password == _password;
	}

	bool hasFriend(const String& friendUsername) const {
		for (int i = 0; i < friendsList.getSize(); ++i) {
			if (friendsList[i] == friendUsername) {
				return true;
			}
		}
		return false;
	}

	void addToWaiting(const String& otherUsername) {
		waitingFriends.addElement(otherUsername);
	}

	void addFriend(const String& friendUsername) {
		friendsList.addElement(friendUsername);
	}
};