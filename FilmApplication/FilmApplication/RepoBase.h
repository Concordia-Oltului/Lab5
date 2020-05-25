#pragma once
#include "Film.h"
#include <vector>

using namespace std;

class RepoBase
{
public:

	virtual void read_from_file() = 0;

	virtual void add_film_to_file(Film film) = 0;

	virtual void write_all_to_file() = 0;

	virtual void write_all_to_file_html() = 0;

};

