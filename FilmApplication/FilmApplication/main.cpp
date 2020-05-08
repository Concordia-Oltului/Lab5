#include "Test.h"
#include <iostream>
#include "UserController.h"
#include "User.h"
#include "FilmController.h"
#include "FilmRepository.h"
#include "RepoBase.h"
#include "AppUI.h"
#include <string>

using namespace std;

int main()
{    
    runAllTests();
    cout << "All Tests Passed!\n";
    FilmRepository fr("db.csv", "film_index.html", true);
    User u("Patrocle", "user_db.csv", "user_index.html");
    FilmController fc(fr);
    UserController uc(u);
    AppUI a(fc,uc);
    a.menuGeneral();
    return 0;
}
