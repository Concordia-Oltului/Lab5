#include "Film.h"

using namespace std;

Film::Film() {
	//@author: Stefan
	Title = "";
	Type = "";
	ReleaseYear = -1;
	LikesNumber = -1;
	Trailer = "";
}

Film::Film(string title, string type, int year, int likes, string trailer) {
	/*
	Creating a new object of type Film
	Input:
		title (string) - film's title
		type (string) - film's type
		year (int) - film's release year
		likes (int) - film's number of likes
		trailer (string) - link to film's trailer
	@author: Stefan
	*/
	Title = title;
	Type = type;
	ReleaseYear = year;
	LikesNumber = likes;
	Trailer = trailer;
}

Film::Film(const Film& other){
	/*
	Creating a copy of the object other
	Input:
		other (Film) - sourceo bject
	@author: Stefan
	*/
	Title = other.Title;
	Type = other.Type;
	ReleaseYear = other.ReleaseYear;
	LikesNumber = other.LikesNumber;
	Trailer = other.Trailer;
}

Film Film::operator=(const Film& other){
	/*
	Creating a copy of the object other by using = operator
	Input:
		other (Film) - sourceo bject
	Output:
		Film
	@author: Stefan
	*/
	Title = other.Title;
	Type = other.Type;
	ReleaseYear = other.ReleaseYear;
	LikesNumber = other.LikesNumber;
	Trailer = other.Trailer;
	return *this;
}

// Getters for films attributes
// @author: Stefan
string Film::get_title() { return Title; }
string Film::get_type() { return Type; }
string Film::get_trailer() { return Trailer; }
int Film::get_release_year() { return ReleaseYear; }
int Film::get_likes_number() { return LikesNumber; }

// Setters for films attributes
// @author: Stefan
void Film::set_title(string new_title) { Title = new_title; }
void Film::set_type(string new_type) { Type = new_type; }
void Film::set_trailer(string new_trailer) { Trailer = new_trailer; }
void Film::set_release_year(int new_year) { ReleaseYear = new_year; }
void Film::set_likes_number(int new_likes) { LikesNumber = new_likes; }

string Film::convert_to_string() {
	// Convert film to string for adding to file
	// @author: Stefan
	string str = "";
	str += Title + "," + Type + "," + to_string(ReleaseYear) + "," + to_string(LikesNumber) + "," + Trailer + ",";
	return str;
}

string Film::convert_to_html(){
	// Convert film to string for adding to HTML file
	// @author: Stefan
	string str = "<tr>";
	string string_trailer = "<a href=\"" + Trailer + "\">Link</a>";
	str = str + "<td>" + Title + "</td>\n<td>" + Type + "</td>\n<td>" + to_string(ReleaseYear) + "</td>\n<td>" + to_string(LikesNumber) + "</td>\n<td>" + string_trailer + "</td></tr>";
	return str;
}

string Film::convert_to_print() {
	// Convert film to string to be printed in console
	// @author: Stefan
	string str = "";
	str += Title + " " + Type + " " + to_string(ReleaseYear) + " " + to_string(LikesNumber) + " " + Trailer;
	return str;
}

Film::~Film() {};
