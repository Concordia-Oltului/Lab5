#pragma once
#include "User.h"
class UserController{
private:
	User user;
public:
	UserController();

	void add_list();

	void remove_list();

	~UserController();
};

