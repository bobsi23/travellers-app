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
    travellersApp.loadDataFromFiels();
    travellersApp.run();
    travellersApp.storeDataInFiels();
}
