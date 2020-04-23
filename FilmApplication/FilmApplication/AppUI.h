#pragma once
#include "FilmController.h"
#include "UserController.h"

class AppUI
{
private:
	FilmController film_controller;
	UserController user_controller;
public:
	AppUI(FilmController, UserController);

	int get_user_option();

	void createAdminMenu();

	void createUserMenu();

	void createUserTypeMenu();

	void createAdminUpdateMenu();

	void adminMenu(int choice);

	void userMenu(int choice);

	void userGeneral();

	void adminGeneral();

	void menuGeneral();

	~AppUI();
};

