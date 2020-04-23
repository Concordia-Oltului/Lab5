#include "User.h"
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

User::User(string name, string filename){
	/*
	Create a empty User with a specific name and add all films from filename in film list
	@author: Stefan
	*/
	FileName = filename;
	Name = name; 
	FilmList.set_fileName(FileName);
	FilmList.read_from_file();
}

User User::operator=(User& other){
	Name = other.Name;
	FileName = other.FileName;
	FilmList = other.FilmList;
	return *this;
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
	int index = FilmList.get_index(title);
	if (index != -1)
		FilmList.set_likes_number(index, FilmList.get_likes_number(index) + 1);
	FilmList.write_all_to_file();
}

User::~User() {}
