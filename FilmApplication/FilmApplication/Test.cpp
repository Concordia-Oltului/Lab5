#include "Film.h"
#include "RepoBase.h"
#include "FilmRepository.h"
#include "FilmController.h"
#include "UserController.h"
#include "User.h"
#include "Test.h"
#include <iostream>
#include <cassert>
#include <exception>
#include <string>


using namespace std;

void test_film_class() {
	Film f1, f2("abcd", "comedy", 1920, 30, "https://google.com/"), f3(f2);
	f1 = f3;
	assert(f1.get_title().compare("abcd") == 0);
	assert(f1.get_type().compare("comedy") == 0);
	assert(f1.get_release_year() == 1920);
	assert(f1.get_likes_number() == 30);
	assert(f1.get_trailer().compare("https://google.com/") == 0);

	f1.set_title("efgh");
	f1.set_type("anime");
	f1.set_release_year(1930);
	f1.set_likes_number(12);
	f1.set_trailer("https://github.com/");
	assert(f1.get_title().compare("efgh") == 0);
	assert(f1.get_type().compare("anime") == 0);
	assert(f1.get_release_year() == 1930);
	assert(f1.get_likes_number() == 12);
	assert(f1.get_trailer().compare("https://github.com/") == 0);
	string str = f1.convert_to_print();
	assert(str.compare("efgh anime 1930 12 https://github.com/") == 0);

	assert(f2.get_title().compare("abcd") == 0);
	assert(f2.get_type().compare("comedy") == 0);
	assert(f2.get_release_year() == 1920);
	assert(f2.get_likes_number() == 30);
	assert(f2.get_trailer().compare("https://google.com/") == 0);

	assert(f3.get_title().compare("abcd") == 0);
	assert(f3.get_type().compare("comedy") == 0);
	assert(f3.get_release_year() == 1920);
	assert(f3.get_likes_number() == 30);
	assert(f3.get_trailer().compare("https://google.com/") == 0);
}

void test_film_repo() {
	FilmRepository fr("test_repo.csv", "test_repo.html", true),fr1;
	try	{
		fr1.add("abcd", "comedy", 1920, 30, "https://google.com/");
		//assert(false);
	}
	catch (exception&)	{
		assert(true);
	}
	fr.add("abcd", "comedy", 1920, 30, "https://google.com/");
	assert(fr.get_index("abcd") != -1);
	assert(fr.get_index("abcdef") == -1);

	FilmRepository fr2("test_repo.csv", "test_repo.html", true);
	assert(fr2.get_index("abcd") != -1);
	try {
		fr1.remove("abcd");
		//assert(false);
	}
	catch (exception&) {
		assert(true);
	}
	fr.remove("abcd");

	FilmRepository fr3("test_repo.csv", "test_repo.html", true);
	assert(fr3.get_index("abcd") == -1);

	fr.add("aa", "aaa", 1111, 11, "https://google.com/");
	assert(fr.filter_genre("aaa").size() == 1);
	assert(fr.filter_genre("aba").size() == 0);
	fr.remove("aa");

	FilmRepository fr4("test_repo.csv");
	assert(fr4.get_index("abcd") == -1);
	Film f1("qwer", "comedy", 1920, 30, "https://google.com/");
	try {
		fr1.add(f1);
		//assert(false);
	}
	catch (exception&) {
		assert(true);
	}
	fr.add(f1);
	fr.remove("qwer");
	assert(fr.remove("asfafsas") == false);
	vector<Film> film_list = fr4.get_all_films();
	assert(film_list.size() == fr4.size());

	fr4.set_title(0,"efgh");
	fr4.set_type(0, "anime");
	fr4.set_release_year(0, 1930);
	fr4.set_likes_number(0, 12);
	fr4.set_trailer(0, "https://github.com/");
	assert(fr4.get_title(0).compare("efgh") == 0);
	assert(fr4.get_type(0).compare("anime") == 0);
	assert(fr4.get_release_year(0) == 1930);
	assert(fr4.get_likes_number(0) == 12);
	assert(fr4.get_trailer(0).compare("https://github.com/") == 0);
	fr4.set_HTMLName("test_repo.html");

	RepoBase a;
	a.add_film_to_file(f1);
	a.read_from_file();
	a.write_all_to_file();
	a.write_all_to_file_html();
}

void test_User_class() {
	User u1, u2("test_user.csv"), u3("test_user.csv", "test_user.html");
	assert(u1.get_list_size() == 0);
	assert(u2.get_list_size() == 6);
	assert(u3.get_list_size() == 6);
	
	u3.remove_list("abcd");
	assert(u2.get_list_size() == 6);
	assert(u3.get_list_size() == 5);
	FilmRepository fr1("test_user.csv");
	assert(fr1.get_index("abcd") == -1);
	Film f1("abcd", "comedy", 1920, 30, "https://google.com/");

	u3.add_list(f1);
	assert(u3.get_list_size() == 6);
	FilmRepository fr2("test_user.csv");
	assert(fr2.get_index("abcd") != -1);

	u2.like_film("nume de film1");
	FilmRepository fr3("test_user.csv");
	assert(fr3.get_likes_number(0) == 131);
	fr3.set_likes_number(0, 130);
	fr3.write_all_to_file();

	vector<Film> film_list = u2.get_all_list();
	assert(film_list.size() == u2.get_list_size());
}

void test_film_controller() {
	FilmRepository fr("test_repo.csv", "test_repo.html", true);
	FilmController fc(fr);
	fc.set_HTML_false();
	fc.set_HTML_true();

	fc.add("efgh", "animation", 1920, 30, "https://github.com/");
	assert(fc.update_type("zxcv", "qwerty") == false);
	assert(fc.update_type("efgh", "qwerty") == true);
	assert(fc.update_year("zxcv", 2) == false);
	assert(fc.update_year("efgh", 2) == true);
	assert(fc.update_likes("zxcv", 2) == false);
	assert(fc.update_likes("efgh", 2) == true);
	assert(fc.update_trailer("zxcv", "www") == false);
	assert(fc.update_trailer("efgh", "www") == true);
	assert(fc.update_title("zxcv", "qwerty") == false);
	assert(fc.update_title("efgh", "qwerty") == true);

	fc.like_film("qwerty");
	
	assert(fc.in_list("qwerty") == true);
	assert(fc.in_list("efgh") == false);

	vector<Film> film_list = fc.get_all();
	assert(film_list.at(film_list.size() - 1).get_title().compare("qwerty") == 0);
	assert(film_list.at(film_list.size() - 1).get_likes_number() == 3);

	fc.remove("qwerty");

	fc.add("aa", "aaa", 1111, 11, "https://google.com/");
	assert(fc.get_filtered("aaa").size() == 1);
	assert(fc.get_filtered("aba").size() == 0);
	fc.remove("aa");

}

void test_user_controller() {
	User u("test_user.csv", "test_user.html");
	UserController uc(u);

	Film f1("abcd", "comedy", 1920, 30, "https://google.com/");
	uc.add_film(f1);
	uc.set_HTML_false();
	uc.set_HTML_true();
	assert(uc.remove_list("rara") == false);
	uc.like_film("abcd");
	assert(uc.remove_list("abcd") == true);
}

void runAllTests() {
	test_film_class();
	test_film_repo();
	test_User_class();
	test_film_controller();
	test_user_controller();
}