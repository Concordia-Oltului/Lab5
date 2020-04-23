#pragma once
#include "User.h"
class UserController{
private:
	User user;
public:
	UserController();

	UserController(User u);

	void operator=(UserController& other);

	void add_list();

	bool remove_list(string title);

	void like_film(string title);

	void print_all();

	~UserController();
};

