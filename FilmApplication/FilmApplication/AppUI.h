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



	~AppUI();
};

