#include <fstream>
#include "FilmRepository.h"


FilmRepository::FilmRepository(){
	Repo = {};
	FileName = "";
}

FilmRepository::FilmRepository(string filename) {
	FileName = filename;
	read_from_file();
}

void FilmRepository::add(string title, string type, int year, int likes, string trailer) {
	Film new_film(title, type, year, likes, trailer);
	Repo.push_back(new_film);
	add_film_to_file(new_film);
}

int FilmRepository::get_index(string title) {
	for (int i = 0; i < Repo.size(); i++) {
		if (Repo.at(i).get_title().compare(title) == 0)
			return i;
	}
	return -1;
}

bool FilmRepository::remove(string title) {
	int index = get_index(title);
	if (index == -1)
		return false;
	Repo.erase(Repo.begin() + index);
	write_all_to_file();
	return true;
}

void FilmRepository::read_from_file() {
	string line;
	string title, type, trailer, year, likes;
	int year_int, likes_int;
	ifstream fin(FileName);
	while (!fin.eof())
	{
		getline(fin,title,';');
		getline(fin,type,';');
		getline(fin,year,';');
		getline(fin,likes,';');
		getline(fin,trailer,';');
		fin.get();

		year_int = stoi(year);
		likes_int = stoi(likes);

		Film new_film(title, type, year_int, likes_int, trailer);
		Repo.push_back(new_film);
	}
	fin.close();
}

void FilmRepository::add_film_to_file(Film film) {
	fstream file;
	file.open(FileName, ios::app);
	string str;
	if(Repo.size() == 0)
		str = film.convert_to_string();
	else
		str = "\n" + film.convert_to_string();
	file << str;
	file.close();
}

void FilmRepository::write_all_to_file() {
	fstream file;
	file.open(FileName, ios::out);
	for (int i = 0; i < Repo.size(); i++) {
		string str;
		if (i == 0)
			str = Repo.at(i).convert_to_string();
		else
			str = "\n" + Repo.at(i).convert_to_string();
		file << str;
	}
	file.close();
}

vector<Film> FilmRepository::get_all_films() {
	return Repo;
}

FilmRepository::~FilmRepository() {}