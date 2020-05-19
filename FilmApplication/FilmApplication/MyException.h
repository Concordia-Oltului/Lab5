#pragma once
#include <string>

using namespace std;

class MyException {
private:
	string err;
public:
	MyException(string);

	string what();

	~MyException();
};

