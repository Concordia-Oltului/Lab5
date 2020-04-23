#pragma once
#include "FilmRepository.h"

class FilmController{
private:
	FilmRepository repo;
public:
	FilmController();

	FilmController(FilmRepository source_repo);

	FilmController operator=(FilmController& other);

	void add(string title, string type, int year, int likes, string trailer);

	bool remove(string title);

	bool update_title(string old_title, string new_title);

	bool update_type(string title, string type);

	bool update_year(string title, int year);

	bool update_likes(string title, int likes);

	bool update_trailer(string title, string trailer);

	void print_films_admin();

	void like_film(string title);

	bool in_list(string title);

	~FilmController();

};

