#include "User.h"
#include "Validator.h"
#include <fstream>

User::User(){
	/*
	Create a empty User and with no file name;
	@author: Stefan
	*/
	FileName = "";
	Name = "Unamed User";
}

User::User(string filename){
	/*
	Create a empty User and add all films from filename in film list
	@author: Stefan
	*/
	FileName = filename;
	Name = "Unamed User";
	FilmList.set_fileName(FileName);
	FilmList.read_from_file();
}

User::User(string filename, string filenameHTML){
	/*
	Create a empty User and add all films from filename in film list
	@author: Stefan
	*/
	FileName = filename;
	FilmList.set_fileName(filename);
	FilmList.set_HTMLName(filenameHTML);
	FilmList.read_from_file();
}

User::User(string name, string filename, string filenameHTML){
	/*
	Create a empty User with a specific name and add all films from filename in film list
	@author: Stefan
	*/
	FileName = filename;
	Name = name;
	FilmList.set_fileName(FileName);
	FilmList.set_HTMLName(filenameHTML);
	FilmList.read_from_file();
}

User User::operator=(User& other){
	/*
	Copies attributes from object other to this object
	Input:
		other (User) - source User
	Output:
		User
	@author: Stefan
	*/
	Name = other.Name;
	FileName = other.FileName;
	FilmList = other.FilmList;
	return *this;
}

void User::set_HTML_true(){
	/*
	Seteaza html pe true, deoarece se va folosi fisierul html daca acesta este setat
	@author: Stefan
	*/
	FilmList.set_HTML_true();
}

void User::set_HTML_false(){
	/*
	Seteaza html pe false, deoarece nu se va folosi fisierul html 
	@author: Stefan
	*/
	FilmList.set_HTML_false();
}

void User::add_list(Film film){
	/*
	Adds a new film to user's film list
	Input:
		film(Film) - Film to be added in list
	@author: Stefan
	*/

	FilmList.add(film);
}

bool User::remove_list(string title){
	/*
	Removes the film with title title from user's film list and return true and if film is not in list returns false
	Input:
		title (string) - name of the filme to be removed
	Output:
		bool
	@author: Stefan
	*/
	return FilmList.remove(title);
}

void User::like_film(string title){
	/*
	Increase likes number of the film given by paramter
	Input:
		title (string) - title of the film
	@author: Stefan
	*/
	int index = FilmList.get_index(title);
	if (index != -1)
		FilmList.set_likes_number(index, FilmList.get_likes_number(index) + 1);
	FilmList.write_all_to_file();
}

User::~User() {}
