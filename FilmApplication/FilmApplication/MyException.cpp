#include "MyException.h"

MyException::MyException(string e) {
	err = e;
}

string MyException::what() {
	return "Exception: " + err;
}

MyException::~MyException(){}