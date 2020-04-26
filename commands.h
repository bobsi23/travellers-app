#pragma once
#include<iostream>
#include "User.h"
#include "DynArray.h"
using std::cin;


void registration(DynArray<User>& users) {
	String username;
	String password;
	String email;
	cin >> username >> password >> email;

	User newUser(username, password, email);
	users.addElement(newUser);
	
}