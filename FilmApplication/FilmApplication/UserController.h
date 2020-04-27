#pragma once
#include "User.h"
class UserController{
private:
	User user;
public:
	UserController();

	UserController(User u);

	void operator=(UserController& other);

	bool remove_list(string title);

	void like_film(string title);

	void print_all();

	void add_film(Film film);

	~UserController();
};

