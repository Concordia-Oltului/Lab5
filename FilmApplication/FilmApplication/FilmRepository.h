#pragma once
#include "Film.h";
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class FilmRepository{
private:
	string FileName;
	vector<Film> Repo;
public:
	FilmRepository();

	FilmRepository(string filename);

	void set_fileName(string new_name) { FileName = new_name; }

	string get_title(int index) { return Repo[index].get_title(); }
	string get_type(int index) { return Repo[index].get_type(); }
	string get_trailer(int index) { return Repo[index].get_trailer(); }
	int get_release_year(int index) { return Repo[index].get_release_year(); }
	int get_likes_number(int index) { return Repo[index].get_likes_number(); }

	void set_title(int index, string new_title) { Repo[index].set_title(new_title); }
	void set_type(int index, string new_type) { Repo[index].set_type(new_type); }
	void set_trailer(int index, string new_trailer) { Repo[index].set_trailer(new_trailer); }
	void set_release_year(int index, int new_year) { Repo[index].set_release_year(new_year); }
	void set_likes_number(int index, int new_likes) { Repo[index].set_likes_number(new_likes); }

	void add(string title, string type, int year, int likes, string trailer);

	bool remove(string title);

	int get_index(string film);

	void read_from_file();

	void add_film_to_file(Film film);

	void write_all_to_file();

	vector<Film> get_all_films();

	~FilmRepository();
};

