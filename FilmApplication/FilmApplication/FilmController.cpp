#include "FilmController.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

FilmController::FilmController() {
	FilmRepository repo_fake;
	repo = repo_fake;
}

FilmController::FilmController(FilmRepository source_repo) {
	repo = source_repo;
}

FilmController FilmController::operator=(FilmController& other)
{
	repo = other.repo;
	return *this;
}

void FilmController::add(string title, string type, int year, int likes, string trailer) {
	/*
	Adds a new element to repository
	Input:
		title (string) - name of the new film
		type (string) - type of the new film
		year (int) - release year of the new film
		likes (int) - likes number of the new film
		trailer (string) - trailer of the new film
	@author: Stefan
	*/
	repo.add(title, type, year, likes, trailer);
}

bool FilmController::remove(string title) {
	/*
	Removes the film with title title from repository and return true and if film is not in repository returns false
	Input:
		title (string) - name of the filme to be removed
	Output:
		bool
	@author: Stefan
	*/
	return repo.remove(title);
}

bool FilmController::update_title(string old_title, string new_title) {
	/*
	Update title of the film with the title old_title and return true if film exist and false if not
	Input:
		old_title (string) - old title of the film
		new_title (string) - new title of the film
	Output:
		bool
	@author: Stefan
	*/
	int index = repo.get_index(old_title);
	if (index != -1) {
		repo.set_title(index, new_title);
		return true;
	}
	return false;
}	

bool FilmController::update_type(string title, string type) {
	/*
	Update type of the film with the title title and return true if film exist and false if not
	Input:
		title (string) - title of the film
		type (string) - new type of the film
	Output:
		bool
	@author: Stefan
	*/
	int index = repo.get_index(title);
	if (index != -1) {
		repo.set_type(index, type);
		return true;
	}
	return false;
}

bool FilmController::update_year(string title, int year) {
	/*
	Update release year of the film with the title title and return true if film exist and false if not
	Input:
		title (string) - title of the film
		year (int) - new released year of the film
	Output:
		bool
	@author: Stefan
	*/
	int index = repo.get_index(title);
	if (index != -1) {
		repo.set_release_year(index, year);
		return true;
	}
	return false;
}

bool FilmController::update_likes(string title, int likes) {
	/*
	Update likes number of the film with the title title and return true if film exist and false if not
	Input:
		title (string) - title of the film
		likes (int) - new likes number of the film
	Output:
		bool
	@author: Stefan
	*/
	int index = repo.get_index(title);
	if (index != -1) {
		repo.set_likes_number(index, likes);
		return true;
	}
	return false;
}

bool FilmController::update_trailer(string title, string trailer) {
	/*
	Update trailer of the film with the title title and return true if film exist and false if not
	Input:
		title (string) - title of the film
		trailer (string) - new type of the film
	Output:
		bool
	@author: Stefan
	*/
	int index = repo.get_index(title);
	if (index != -1) {
		repo.set_trailer(index, trailer);
		return true;
	}
	return false;
}

void FilmController::print_films_admin(){
	/*
	Prints in console all elements from repository
	@author: Stefan
	*/
	vector<Film> films = repo.get_all_films();
	cout << "Title\tType\tRelease Year\tLikes Number\tTrailer" << endl;
	for (int i = 0; i < films.size(); i++) {
		cout << films.at(i).get_title() << "\t" << films.at(i).get_type() << "\t" << films.at(i).get_release_year() << "\t" << films.at(i).get_likes_number() << "\t" << films.at(i).get_trailer() << endl;
	}
}

bool FilmController::in_list(string title){
	/*
	Returns true if is a film in list with title title and false if not
	Input:
		title (string) - title of the film
	Output:
		bool
	@author: Stefan
	*/
	if (repo.get_index(title) == -1)
		return false;
	return true;
}

void FilmController::like_film(string title) {
	/*
	Increase likes number of the film given by paramter
	Input:
		title (string) - title of the film
	@author: Stefan
	*/
	int index = repo.get_index(title);
	if (index != -1)
		repo.set_likes_number(index, repo.get_likes_number(index) + 1);
	repo.write_all_to_file();
}

vector<Film> FilmController::get_filtered(string genre) {
	/*
	Returns a list of filtered Film objects from the repository
	Input:
		genre (string) - genre to filter by
	Output:
		vector<Film>
	@author: Victor
	*/
	return repo.filter_genre(genre);
}

vector<Film> FilmController::get_all() {
	/*
	Returns all elements in the repository
	Output:
		vector<Film>
	@author: Victor
	*/
	return repo.get_all_films();
}

FilmController::~FilmController() {}