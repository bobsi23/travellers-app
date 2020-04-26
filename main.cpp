#include <iostream>
#include "DynArray.h"
#include "String.h"
#include "User.h"
#include "TravellersApp.h"
using namespace std;

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

int main()
{
    TravellersApp travellersApp;
    
    cout << "Welcome!" << endl;
    cout << "Enter 'help', if you want to see what you can do in this app" << endl;

    String command;
    while (1) {
        cin >> command;

        if (command == "registartion") {
            travellersApp.registration();
        }
        else if (command == "login") {

        }
        else if (command == "logout") {

        }
    }
}
