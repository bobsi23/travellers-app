#pragma once
#include <iostream>
#include "String.h"
#include "DynArray.h"
#include "Journey.h"
using std::cin;
using std::cout;
using std::endl;

class User {
	String username;
	String password;
	String email;
	DynArray<String> friendsList;
	DynArray<String> waitingFriends;
	DynArray<Journey> journeyList;

public:
	User() {
		username = "";
		password = "";
		email = "";
		friendsList = {};
		waitingFriends = {};
	}

	User(const String& _username, const String& _password, const String& _email) {
		username = _username;
		password = _password;
		email = _email;
		friendsList = {};
		waitingFriends = {};
	}
	
	String getUsername() const {
		return username;
	}

	void printUserInfo() const {
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

	bool hasWaitingFriend(const String& otherUsername) const {
		for (int i = 0; i < waitingFriends.getSize(); ++i) {
			if(waitingFriends[i] == otherUsername){
				return true;
			}
		}
		return false;
	}

	void addToWaiting(const String& otherUsername) {
		waitingFriends.addElement(otherUsername);
	}

	void addFriend(const String& friendUsername) {
		waitingFriends.removeElement(friendUsername);
		friendsList.addElement(friendUsername);
	}

	void removeFromWaiting(const String& otherUsername) {
		waitingFriends.removeElement(otherUsername);
	}

	void printFriendsList() const {
		for (int i = 0; i < friendsList.getSize(); ++i) {
			cout << friendsList[i] << endl;
		}
	}

	void printWaitingList() const {
		for (int i = 0; i < waitingFriends.getSize(); ++i) {
			cout << waitingFriends[i] << endl;
		}
	}

	void addJourney(const Journey& newJourney) {
		journeyList.addElement(newJourney);
	}
};