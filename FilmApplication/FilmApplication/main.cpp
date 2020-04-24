#include "Test.h"
#include <iostream>
#include "UserController.h"
#include "User.h"
#include "FilmController.h"
#include "AppUI.h"

using namespace std;

int main()
{
    runAllTests();
    cout << "All Tests Passed!\n";
    FilmRepository fr("test_repo.txt");
    User u("test_user.txt");
    //Film f1("abcd", "comedy", 1920, 30, "https://google.com/");
    //fr.add(f1);
    FilmController fc(fr);
    UserController uc(u);
    AppUI a(fc,uc);
    a.menuGeneral();

    return 0;
}
