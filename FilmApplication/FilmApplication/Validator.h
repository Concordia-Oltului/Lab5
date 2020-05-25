#pragma once
#include <string>
#include <exception>
#include <iostream>

using namespace std;

class Validator {
	public:
		bool validateAlpha(string alpha) {
			/*
			checks if string 'alpha' has any invalid characters
			valid characters: alphabetic characters, space character
			Input:
				alpha (string) - input string
			Output:
				throws exception if input invalid
				returns true otherwise
			@author: Victor
			*/
			for (int i = 0; i < alpha.size(); i++) {
				if (!(isalpha(alpha[i])) && !(isspace(alpha[i]))) {
					cout << "Invalid alphabetic input\nInvalid characters in string " << alpha;
					exception e; throw e;
				}
			}
			return true;
		}

		bool validateInteger(int integer) {
			/*
			
			*/
			
		}
};
