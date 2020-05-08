#include "UserController.h"

UserController::UserController() {
	//creating a new user with no attributes
	User user_fake;
	user = user_fake;
}

UserController::UserController(User u) { 
	user = u;
}

void UserController::operator=(UserController& other) {
	user = other.user;
}

void UserController::set_HTML_true(){
	user.set_HTML_true();
}

void UserController::set_HTML_false(){
	user.set_HTML_false();
}

bool UserController::remove_list(string title) {
	/*
	Removes the film with title title from user's film list and return true and if film is not in list returns false
	Input:
		title (string) - name of the filme to be removed
	Output:
		bool
	@author: Stefan
	*/
	return user.remove_list(title);
}

void UserController::like_film(string title) {
	/*
	Increase likes number of the film given by paramter
	Input:
		title (string) - title of the film
	@author: Stefan
	*/
	user.like_film(title);
}

void UserController::print_all() {
	/*
	Prints all films from user list
	@author: Stefan
	*/
	vector<Film> list=user.get_all_list();
	cout << "Title\tType\tRelease Year\tLikes Number\tTrailer" << endl;
	for (int i = 0; i < list.size(); i++) {
		cout << list.at(i).convert_to_print() << endl;
	}
}

void UserController::add_film(Film film) {
	/*
	Adds Film object film to the user's watchlist
	Input:
		film (Film) - film we are adding
	@author: Victor
	*/
	user.add_list(film);
}

UserController::~UserController(){}
