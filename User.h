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
		friendsList = DynArray<String>();
		waitingFriends = DynArray<String>();
		journeyList = DynArray<Journey>();
	}

	User(const String& _username, const String& _password, const String& _email) {
		username = _username;
		password = _password;
		email = _email;
		friendsList = DynArray<String>();
		waitingFriends = DynArray<String>();
		journeyList = DynArray<Journey>();
	}
	

	String getUsername() const {
		return username;
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


	void addFriend(const String& friendUsername) {
		waitingFriends.removeElement(friendUsername);
		friendsList.addElement(friendUsername);
	}

	void addToWaiting(const String& otherUsername) {
		waitingFriends.addElement(otherUsername);
	}

	void addJourney(const Journey& newJourney) {
		journeyList.addElement(newJourney);
	}


	void removeFromWaiting(const String& otherUsername) {
		waitingFriends.removeElement(otherUsername);
	}


	void printUserInfo() const {
		cout << "Name: " << username << endl;
		cout << "Email: " << email << endl;
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

	void printJourneyList() {
		for (int i = 0; i < journeyList.getSize(); ++i) {
			journeyList[i].printJourney();
		}

	}

	
	void sentToOstream(ostream& out) const {
		out << username << " " << password << " " << email << endl;
	}
};


ostream& operator<<(ostream& out, const User& user) {
	user.sentToOstream(out);
	return out;
}