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

	User(string name, string filename, string filenameHTML);

	User operator=(User& other);

	void set_HTML_true();

	void set_HTML_false();

	int get_list_size() { return FilmList.size(); }

	void add_list(Film film);

	bool remove_list(string title);

	void like_film(string title);

	vector<Film> get_all_list() { return FilmList.get_all_films(); }

	~User();
};

