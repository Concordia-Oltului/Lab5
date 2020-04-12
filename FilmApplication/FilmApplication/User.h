#pragma once
#include "FilmRepository.h"
#include <iostream>
#include <string>

using namespace std;

class User{
private:
	string name, filename;
	FilmRepository film_list;
public:
	User();

	User(string filename);

	User(string name, string filename);

	void add_list();

	void remove_list();

	void read_from_file();

	~User();
};

