#pragma once
#include <string>

using namespace std;

class Film
{
private:
	string Title, Type, Trailer;
	int ReleaseYear, LikesNumber;
public:

	Film();

	Film(string title, string type, int year, int likes, string trailer);

	Film(const Film& other);

	Film operator=(const Film& other);

	string get_title();
	string get_type();
	string get_trailer();
	int get_release_year();
	int get_likes_number();

	void set_title(string);
	void set_type(string);
	void set_trailer(string);
	void set_release_year(int);
	void set_likes_number(int);

	string convert_to_string();

	string convert_to_print();

	~Film();

};

