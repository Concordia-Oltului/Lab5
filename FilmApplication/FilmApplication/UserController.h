#pragma once
#include "User.h"
class UserController{
private:
	User user;
public:
	UserController();

	void operator=(UserController& other);

	void add_list();

	void remove_list();

	void print_all();

	~UserController();
};

