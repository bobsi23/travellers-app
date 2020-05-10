#include <iostream>
#include "DynArray.h"
#include "String.h"
#include "User.h"
#include "TravellersApp.h"
using namespace std;

int main() {
    TravellersApp travellersApp;
    travellersApp.loadDataFromFiles();
    travellersApp.run();
    travellersApp.storeDataInFiles();
}
