#include <fstream>
#include "FilmRepository.h"


FilmRepository::FilmRepository(){
	/*
	Create a empty repository and with no file name;
	@author: Stefan
	*/
	Repo = {};
	FileName = "";
}

FilmRepository::FilmRepository(string filename) {
	/*
	Create a repository and add all films from filename in it
	Input:
		filename(string) - name of the file from where take films
	@author: Stefan
	*/
	FileName = filename;
	read_from_file();
}

FilmRepository FilmRepository::operator=(FilmRepository& other)
{
	FileName = other.FileName;
	Repo = other.Repo;
	return *this;
}

void FilmRepository::add(string title, string type, int year, int likes, string trailer) {
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
	if (FileName.compare("") == 0) { // if filename is not setted throw an exception
		exception file_not_set;
		throw file_not_set;
	}
	Film new_film(title, type, year, likes, trailer); // create a new film
	Repo.push_back(new_film); // add film to repo
	add_film_to_file(new_film); // add film to file to be saved
}

void FilmRepository::add(Film new_film){
	/*
	Adds a new element to repository
	Input:
		new_film(Film) - Film to be added in list
	@author: Stefan
	*/
	if (FileName.compare("") == 0) { // if filename is not setted throw an exception
		exception file_not_set;
		throw file_not_set;
	}
	Repo.push_back(new_film); // add film to repo
	add_film_to_file(new_film); // add film to file to be saved
}

int FilmRepository::get_index(string title) {
	/*
	Search for a film in repository and return it's index in repository or -1 if film is not in repo
	Input:
		title (string) -  name of the searched film
	Output:
		int
	@author: Stefan
	*/
	for (int i = 0; i < Repo.size(); i++) {
		if (Repo.at(i).get_title().compare(title) == 0)
			return i;
	}
	return -1;
}

bool FilmRepository::remove(string title) {
	/*
	Removes the film with title title from repository and return true and if film is not in repository returns false
	Input:
		title (string) - name of the filme to be removed
	Output:
		bool
	@author: Stefan
	*/
	if (FileName.compare("") == 0) { // if filename is not setted throw an exception
		exception file_not_set;
		throw file_not_set;
	}
	int index = get_index(title); // search for film in repository
	if (index == -1) //  if film is not in repository return false
		return false;
	Repo.erase(Repo.begin() + index); // deletes element form repository
	write_all_to_file(); // rewrite all films to file
	return true;
}

void FilmRepository::read_from_file() {
	/*
	Reads all films from file and add them to repository
	@author: Stefan
	*/
	string title, type, trailer, year, likes; // will contain film's data from file
	int year_int, likes_int; // to convert year and likes number to a number
	ifstream fin(FileName); 
	while (!fin.eof())
	{
		getline(fin,title,';'); // reading title
		getline(fin,type,';'); // reading type
		getline(fin,year,';'); // reading year number as string
		getline(fin,likes,';'); // reading likes number as string
		getline(fin,trailer,';'); // reading trailer link
		fin.get(); // to skip last \n from each line

		year_int = stoi(year); // convert year to int 
		likes_int = stoi(likes); // convert likes number to int

		Film new_film(title, type, year_int, likes_int, trailer); // create a new film
		Repo.push_back(new_film); // adds films to repository
	}
	fin.close();
}

void FilmRepository::add_film_to_file(Film film) {
	/*
	Adds a film's data converted to string to file
	Input:
		film (Film)
	@author: Stefan
	*/
	fstream file;
	file.open(FileName, ios::app); // open file in append mode
	string str; // will contain name film's data as string
	if(Repo.size() == 0) // if is first element from repo it will not add \n in front of data
		str = film.convert_to_string();
	else
		str = "\n" + film.convert_to_string();
	file << str; // add str to file
	file.close();
}

void FilmRepository::write_all_to_file() {
	/*
	Write all elements from repository to file
	@author: Stefan
	*/
	fstream file;
	file.open(FileName, ios::out); // opens file in write mode
	for (int i = 0; i < Repo.size(); i++) {
		string str;
		if (i == 0) // if is first element from repo it will not add \n in front of data
			str = Repo.at(i).convert_to_string();
		else
			str = "\n" + Repo.at(i).convert_to_string();
		file << str; // add str to file
	}
	file.close();
}

vector<Film> FilmRepository::get_all_films() {
	/*
	Returns vector of all elements from repository
	Output:
		vector<Film>
	@author: Stefan
	*/
	return Repo;
}

FilmRepository::~FilmRepository() {}