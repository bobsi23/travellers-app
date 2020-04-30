#pragma once
#include<iostream>
#include "User.h"
#include "DynArray.h"
using std::cin;

class TravellersApp {
	DynArray<User> users;
	User* currentUser;		// ��� � nullptr, ���� ������ ����������
							// ��� ��� ������ ����������, ���� ����
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
			if (users[i].getUsername() == username) {
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
	
	void friend_request_send() {
		if (currentUser == nullptr) {
			cout << "User not logged in" << endl;
		}
		else {
			String friendUsername;
			cin >> friendUsername;
			
			for (int i = 0; i < users.getSize(); ++i) {
				if (users[i].getUsername() == friendUsername) {
					if (currentUser->hasFriend(friendUsername)) {
						cout << "You're already friends" << endl;
					}
					else {
						currentUser->addFriend(friendUsername);
					}
					return;
				}
			}
			cout << "User not found" << endl;
		}
	}

	void help() {
		
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

			if (command == "registartion") {
				registration();
			}
			else if (command == "login") {
				login();
			}
			else if (command == "logout") {
				logout();
			}
			else if (command == "friend_request_send") {
				friend_request_send();
			}
			else if (command == "friend_accept") {

			}
			else if (command == "friend_decline") {

			}
			// ...
			else if (command == "help") {
				help();
			}
			else if (command == "quit") {
				break;
			}
			
		}
	}

	void loadDataFromFiels() {

	}

	void storeDataInFiels() {

	}
};