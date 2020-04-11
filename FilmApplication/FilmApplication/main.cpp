#include "Test.h"
#include <iostream>
#include "UserController.h"
#include "FilmController.h"
#include "AppUI.h"

using namespace std;

int main()
{
    runAllTests();
    cout << "All Tests Passed!\n";
    FilmRepository fr("test_repo.txt");
    fr.add("abcd", "comedy", 1920, 30, "https://google.com/");
    FilmController fc(fr);
    AppUI a(fc);
    a.adminGeneral();

    return 0;
}
