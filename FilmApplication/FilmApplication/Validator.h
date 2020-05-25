#pragma once
#include <string>
#include "MyException.h"
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
					MyException e("Invalid alphabetic input\n");
					throw e;
				}
			}
			return true;
		}

		bool validateYear(int Year) {
			/*
			checks if integer 'Year' qualifies as a year format
			invalid cases: 'Year' is below 0 or greater than current year
			Input:
				Year (integer) - input release year
			Output:
				throws exception if input invalid
				returns true otherwise
			@author: Victor
			*/
			if (Year < 0 || Year > 2020) {
				MyException e("Invalid year input\n");
				throw e;
			}
			return true;
		}

		bool validateLikes(int Likes) {
			/*
			checks if integer 'Likes' has a valid value
			invalid cases: 'Likes' below 0
			Input:
				Likes (integer) - input likes number
			Output:
				throws exception if input invalid
				returns true otherwise
			@author: Victor
			*/
			if (Likes < 0) {
				MyException e("Invalid likes input\n");
				throw e;
			}
			return true;
		}
};
