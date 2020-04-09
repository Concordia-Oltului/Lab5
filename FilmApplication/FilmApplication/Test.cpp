#include "Test.h"
#include <iostream>
#include <cassert>
#include <string>
#include "Film.h"


using namespace std;


void test_film_class() {
	Film f1, f2("abcd", "comedy", 1920, 30, "https://google.com/"), f3(f2);
	f1 = f3;
	assert(f1.get_title().compare("abcd") == 0);
	assert(f1.get_type().compare("comedy") == 0);
	assert(f1.get_release_year() == 1920);
	assert(f1.get_likes_number() == 30);
	assert(f1.get_trailer().compare("https://google.com/") == 0);

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

void runAllTests() {
	test_film_class();
}