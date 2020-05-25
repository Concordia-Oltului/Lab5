#include "MyException.h"

MyException::MyException(string e) {
	err = e;
}

string MyException::what() {
	/*
	Returns what exception appeared
	Input:
		-
	Output:
		String
	@author: Stefan
	*/
	return "Exception: " + err;
}

MyException::~MyException(){}