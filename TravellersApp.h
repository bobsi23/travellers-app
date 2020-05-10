#pragma once
#include<iostream>
#include "User.h"
#include "DynArray.h"
using std::cin;

class TravellersApp {
	DynArray<User> users;
	User* currentUser;		// ��� � nullptr, ���� ������ ����������
							// ��� ��� ������ ����������, ���� ����

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
						//���� � ���� ������ ������ �� ������� ��������� � � ����� �����
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
		cout << "Enter 'quit', if you want to see what you can do in this app" << endl;

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

	}

	void storeDataInFiles() const {

	}
};