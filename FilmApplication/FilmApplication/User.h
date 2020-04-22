#pragma once
#include "FilmRepository.h"
#include <iostream>
#include <string>

using namespace std;

class User{
private:
	string Name, FileName;
	FilmRepository FilmList;
public:
	User();

	User(string filename);

	User(string name, string filename);

	User operator=(User& other);

	int get_list_size() { return FilmList.size(); }

	void add_list(Film film);

	bool remove_list(string title);

	vector<Film> get_all_list() { return FilmList.get_all_films(); }

	~User();
};

