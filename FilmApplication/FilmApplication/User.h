#pragma once
#include "FilmRepository.h"
#include <iostream>
#include <string>

using namespace std;

class User{
private:
	string name;
	FilmRepository film_list;
public:
	User();

	void add_list();

	void remove_list();

	~User();
};

