#pragma once
#include<iostream>
#include<fstream>
#include "User.h"
#include "DynArray.h"
using std::cin;
using std::ifstream;
using std::ofstream;

class TravellersApp {
	DynArray<User> users;
	User* currentUser;		// Ако е nullptr, няма вписан потребител
							// Ако има вписан потребител, сочи него

	bool isLogged() const {
		return currentUser != nullptr;
	}

public:
	TravellersApp() {
		users = DynArray<User>();
		currentUser = nullptr;
	}
	
	void registration() {
		if (isLogged()) {
			cout << "A user has already logged. Please logout and retry" << endl;
		}
		else {
			String username;
			String password;
			String email;
			cout << "Please enter username, password, email:" << endl;
			cin >> username >> password >> email;

			for (int i = 0; i < users.getSize(); ++i) {
				if (users[i].getUsername() == username) {
					cout << "Username not available" << endl;
					return;
				}
			}

			User newUser(username, password, email);
			users.addElement(newUser);
		}
	}

	void login() {
		if (isLogged()) {
			cout << "A user has already logged. Please logout and retry" << endl;
		}
		else {
			String username;
			String password;
			cout << "Enter username and password:" << endl;
			cin >> username >> password;
			for (int i = 0; i < users.getSize(); ++i) {
				if (users[i].hasUsernameAndPassword(username, password)) {
					currentUser = &(users[i]);
					cout << "Login was successful" << endl;
					return;
				}
			}
			cout << "Unsuccessful login" << endl;
		}
	}

	void logout() {
		currentUser = nullptr;
	}
	
	void friendRequestSend() {
		if (isLogged()) {	
			String friendUsername;
			cin >> friendUsername;

			for (int i = 0; i < users.getSize(); ++i) {
				if (users[i].getUsername() == friendUsername) {
					if (currentUser->hasFriend(friendUsername)) {
						cout << "You're already friends" << endl;
					}
					else if (currentUser->hasWaitingFriend(friendUsername)) {
						cout << "You're already in the waiting list of this user" << endl;
					}
					else if (users[i].hasWaitingFriend(currentUser->getUsername() )) {
						cout << "Friend request has already been sent" << endl;
					}
					else {
						cout << "Adding you to waiting list of friend..." << endl;
						users[i].addToWaiting(currentUser->getUsername());
					}
					return;
				}
			}
			cout << "User not found" << endl;
		}
		else {
			cout << "User not logged in" << endl;
		}
	}

	void friendAccept() {
		if (isLogged()) {
			String friendUsername;
			cin >> friendUsername;

			for (int i = 0; i < users.getSize(); ++i) {
				if (users[i].getUsername() == friendUsername) {
					if (currentUser->hasFriend(friendUsername)) {
						cout << "You're already friends" << endl;
					}
					else if (currentUser->hasWaitingFriend(friendUsername)) {
						//това е така защото трябва да отразим промяната и в двата листа
						currentUser->addFriend(friendUsername); 
						users[i].addFriend(currentUser->getUsername());
					}
					else {
						cout << "There is no friend request from this user. You cannot become friends yet" << endl;
					}
					return;
				}
			}
			cout << "User not found" << endl;
		}
		else {
			cout << "User not logged in" << endl;
		}
	}
	
	void friendDecline() {
		if (isLogged()) {
			String friendUsername;
			cin >> friendUsername;

			for (int i = 0; i < users.getSize(); ++i) {
				if (users[i].getUsername() == friendUsername) {
					if (currentUser->hasFriend(friendUsername)) {
						cout << "You're already friends. You cannot decline this request" << endl;
					}
					else if (currentUser->hasWaitingFriend(friendUsername)) {
						currentUser->removeFromWaiting(friendUsername);
					}
					else {
						cout << "There is no friend request from this user" << endl;
					}
					return;
				}
			}
			cout << "User not found" << endl;
		}
		else {
			cout << "User not logged in" << endl;
		}
	}

	void friendsList() const {
		if (isLogged()) {
			currentUser->printFriendsList();
		}
		else {
			cout << "You're currently not logged in" << endl;
		}
	}

	void waitingList() const {
		if (isLogged()) {
			currentUser->printWaitingList();
		}
		else {
			cout << "You're currently not logged in" << endl;
		}
	}

	void journeyList() const {
		if (isLogged()) {
			currentUser->printJourneyList();
		}
		else {
			cout << "User not logged in" << endl;
		}
	}

	void addJourney() {
		if (isLogged()) {
			Journey journey;
			journey.readJourney();
			currentUser->addJourney(journey);
		}
		else {
			cout << "User not logged in" << endl;
		}
	}

	void help() const {
		
	}

	/*
		List of commands (by far):

		help
		registration
		login
		logout
		friend_request
		friend_accept
		friend_decline
		add_journey
	*/
	void run() {
		cout << "Welcome!" << endl;
		cout << "Enter 'help', if you want to see what you can do in this app" << endl;
		cout << "Enter 'quit', if you want to quit" << endl;

		String command;

		while (1) {
			cin >> command;

			if (command == "registration") {
				registration();
			}
			else if (command == "login") {
				login();
			}
			else if (command == "logout") {
				logout();
			}
			else if (command == "friend_request_send") {
				friendRequestSend();
			}
			else if (command == "friend_accept") {
				friendAccept();
			}
			else if (command == "friend_decline") {
				friendDecline();
			}
			else if (command == "friends_list") {
				friendsList();
			}
			else if (command == "waiting_list") {
				waitingList();
			}
			else if (command == "journey_list") {
				journeyList();
			}
			else if (command == "add_journey") {
				addJourney();
			}
			// ...
			else if (command == "help") {
				help();
			}
			else if (command == "quit") {
				break;
			}
			else {
				cout << "There is no command: " << command << endl;
			}
			cout << endl;
		}
	}

	void loadDataFromFiles() {
		ifstream in;
		in.open("users.db");

		if(in.good()){
			String username;
			String password;
			String email;

			while (!in.eof()) {
				in >> username >> password >> email;
				User user(username, password, email);
				users.addElement(user);
			}
			users.removeLastElement();
			in.close();
			
			for (int i = 0; i < users.getSize(); ++i) {
				String fileName = users[i].getUsername() + ".db";
				in.open(fileName.getArr());

				if (in.good()) {
					int numberOfFriends;
					in >> numberOfFriends;
					for (int j = 0; j < numberOfFriends; ++j) {
						String friendUsername;
						in >> friendUsername;
						users[i].addFriend(friendUsername);
					}

					int waitingFriends;
					in >> waitingFriends;
					for (int k = 0; k < waitingFriends; ++k) {
						String waitingFriend;
						in >> waitingFriend;
						users[i].addToWaiting(waitingFriend);
					}

					int numberOfJourneys;
					in >> numberOfJourneys;
					for (int p = 0; p < numberOfJourneys; ++p) {
						Journey journey;
						in >> journey;
						users[i].addJourney(journey);
					}
				}

				in.close();
			}
		}
	}

	void storeDataInFiles() const {
		ofstream out;
		out.open("users.db");

		for (int i = 0; i < users.getSize(); ++i) {
			out << users[i];
		}

		out.close();

		for (int i = 0; i < users.getSize(); ++i) {
			String fileName = users[i].getUsername() + ".db";

			out.open(fileName.getArr());

			out << users[i].getNumberOfFriends() << endl;
			for (int j = 0; j < users[i].getNumberOfFriends(); ++j) {
				out << users[i].getFriend(j) << endl;
			}

			out << users[i].getNumberOfWaitingFriends() << endl;
			for (int k = 0; k < users[i].getNumberOfWaitingFriends(); ++k) {
				out << users[i].getWaitingFriend(k) << endl;
			}

			out << users[i].getNumberOfJourneys() << endl;
			for (int p = 0; p < users[i].getNumberOfJourneys(); ++p) {
				out << users[i].getJourney(p);
			}

			out.close();
		}
	}
};