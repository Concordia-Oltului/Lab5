#pragma once
#include "FilmController.h"
#include "UserController.h"

class AppUI
{
private:
	FilmController film_controller;
	//UserController user_controller;
public:
	AppUI(FilmController);

	int get_user_option();

	void createAdminMenu();

	void createAdminUpdateMenu();

	void adminMenu(int choice);

	void adminGeneral();

	~AppUI();
};

