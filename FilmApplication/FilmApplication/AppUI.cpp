#include "AppUI.h"
#include <iostream>

using namespace std;

AppUI::AppUI(FilmController film, UserController user){
	film_controller = film;
	user_controller = user;
}

int AppUI::get_user_option(){
	/*
	Get user option from keyboard
	Input:
		-
	Output:
		int
	@author: Stefan
	*/
	int option;
	cout << "Enter your option:";
	cin >> option;
	return option;
}

void AppUI::createAdminMenu(){
	/*
	Prints menu for admin
	@author: Stefan
	*/
	cout << "Admin menu:" << endl;
	cout << "1. Add new film" << endl;
	cout << "2. Remove a film" << endl;
	cout << "3. Update a film" << endl;
	cout << "4. Show all film" << endl;
	cout << "0. Back" << endl;
}

void AppUI::createUserMenu(){
	/*
	Prints menu for admin
	@author: Stefan
	*/
	cout << "User Menu:" << endl;
	cout << "1. Add new film" << endl; // /\/\/\/\\/\/\ punei tu ce nume vrei /\/\/\/\/\/\/\/\/
	cout << "2. Remove a film watched" << endl;
	cout << "3. Print all films" << endl;
	cout << "0. Back" << endl;
}

void AppUI::createUserTypeMenu(){
	/*
	Prints menu for selecting user type
	@author: Stefan
	*/
	cout << "General Menu:" << endl;
	cout << "1. User Menu" << endl;
	cout << "2. Admin Menu" << endl;
	cout << "0. Exit" << endl;
}

void AppUI::createAdminUpdateMenu(){
	/*
	Prints update menu for update option from admin menu
	@author: Stefan
	*/
	cout << "Update Menu:" << endl;
	cout << "1. Update title" << endl;
	cout << "2. Update type" << endl;
	cout << "3. Update released year" << endl;
	cout << "4. Update likes number" << endl;
	cout << "5. Update trailer" << endl;
	cout << "0. Back" << endl;
}

void AppUI::adminMenu(int choice) {
	/*
	Make changes for option choice
	Input:
		choice (int) - user choice
	@author: Stefan
	*/
	if (choice == 1) { // add new film to list
		string title, type, trailer;
		int year, likes;
		getline(cin,title); // s-a citit inainte un numar
		cout << "Enter film title: ";
		getline(cin, title);
		cout << "Enter film type: ";
		getline(cin, type);
		cout << "Enter film released year: ";
		cin >> year;
		cout << "Enter film likes number: ";
		cin >> likes;
		getline(cin, trailer); // s-a citit inainte un numar
		cout << "Enter film trailer: ";
		getline(cin, trailer);
		film_controller.add(title, type, year, likes, trailer);
	}
	if (choice == 2) { // remove a film from list
		string title;
		getline(cin, title); // s-a citit inainte un numar
		cout << "Enter film title:";
		getline(cin, title);
		bool check = true;
		check = film_controller.remove(title);
		if (check == false) {
			cout << "Film is not in our list!" << endl;
		}
	}
	if (choice == 3) { // update a film from list
		string title;
		getline(cin, title); // s-a citit inainte un numar
		cout << "Enter film title:";
		getline(cin, title);

		if (film_controller.in_list(title) == true) {

			createAdminUpdateMenu();

			int update_choice = get_user_option();

			if (update_choice == 1) {
				string new_title;
				getline(cin, new_title); // s-a citit un numar inainte 
				cout << "Enter new title: ";
				getline(cin, new_title);
				film_controller.update_title(title, new_title);
			}
			if (update_choice == 2) {
				string type;
				getline(cin, type); // s-a citit un numar inainte 
				cout << "Enter new type: ";
				getline(cin, type);
				film_controller.update_type(title, type);
			}
			if (update_choice == 3) {
				int year;
				cout << "Enter new released year: ";
				cin >> year;
				film_controller.update_year(title, year);
			}
			if (update_choice == 4) {
				int likes;
				cout << "Enter new likes number: ";
				cin >> likes;
				film_controller.update_likes(title, likes);
			}
			if (update_choice == 5) {
				string trailer;
				getline(cin, trailer); // s-a citit un numar inainte 
				cout << "Enter new trailer: ";
				getline(cin, trailer);
				film_controller.update_trailer(title, trailer);
			}
		}
		else{
			cout << "Film is not in our list!" << endl;
		}
	}
	if (choice == 4) { // prints all films from list
		film_controller.print_films_admin();
	}
}

void AppUI::userMenu(int choice){
	/*
	Make changes for option choice
	Input:
		choice (int) - user choice
	*/
	if (choice == 2) { // remove watched film 
		// @author: Stefan
		string title;
		getline(cin, title); // s-a citit numar inainte
		cout << "Enter the title of the film you have watched: ";
		getline(cin, title);
		if (user_controller.remove_list(title) == true) {
			cout << "Did you like the film? 1. Yes 2. No";
			if (get_user_option() == 1) {
				user_controller.like_film(title);
				film_controller.like_film(title);
			}
		}
	}
	if (choice == 3) { // prints all films in console
		// @author: Stefan
		user_controller.print_all();
	}
}

void AppUI::userGeneral(){
	/*
	Build user menu
	@author: Stefan
	*/
	createUserMenu();
	int choice = get_user_option();
	while (choice)
	{
		userMenu(choice);
		createUserMenu();
		choice = get_user_option();
	}
}

void AppUI::adminGeneral(){
	/*
	Build admin menu
	@author: Stefan
	*/
	createAdminMenu();
	int choice = get_user_option();
	while (choice)
	{
		adminMenu(choice);
		createAdminMenu();
		choice = get_user_option();
	}
}

void AppUI::menuGeneral(){ 
	/*
	Build General menu
	@author: Stefan
	*/
	createUserTypeMenu();
	int choice = get_user_option();
	while (choice != 0) {
		if (choice == 1)
			userGeneral();
		if (choice == 2)
			adminGeneral();
		createUserTypeMenu();
		choice = get_user_option();
	}
}



AppUI::~AppUI() {}
