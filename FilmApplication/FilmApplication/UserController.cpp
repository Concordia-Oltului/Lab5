#include "UserController.h"

UserController::UserController(){}

UserController::UserController(User u){
	user = u;
}

void UserController::operator=(UserController& other){
	user = other.user;
}

void UserController::add_list(){
}

bool UserController::remove_list(string title){
	return user.remove_list(title);
}

void UserController::like_film(string title){
	user.like_film(title);
}

void UserController::print_all(){
	vector<Film> list=user.get_all_list();
	cout << "Title\tType\tRelease Year\tLikes Number\tTrailer" << endl;
	for (int i = 0; i < list.size(); i++) {
		cout << list.at(i).convert_to_print() << endl;
	}
}

UserController::~UserController(){}
