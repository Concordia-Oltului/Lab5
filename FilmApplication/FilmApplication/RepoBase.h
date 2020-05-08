#pragma once
#include "Film.h"
#include <vector>

using namespace std;

class RepoBase
{
public:

	virtual void read_from_file() {}

	virtual void add_film_to_file(Film film) {}

	virtual void write_all_to_file() {}

	virtual void write_all_to_file_html() {}

};

