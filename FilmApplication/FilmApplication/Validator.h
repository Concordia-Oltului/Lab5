#pragma once
#include <string>
#include "MyException.h"
#include <iostream>

using namespace std;

class Validator {
	public:
		bool validateGenre(string alpha) {
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
				if (!(isalpha(alpha[i])) && !(isblank(alpha[i]))) {
					MyException e("Invalid genre input\n");
					throw e;
				}
			}
			return true;
		}

		bool validateTitle(string title) {
			/*
			checks if string 'title' has any invalid characters
			valid characters: alphanumeric characters, space character, punctuation characters
			Input:
				title (string) - title input string
			Output:
				throws exception if input invalid
				returns true otherwise
			@author: Victor
			*/
			for (int i = 0; i < title.size(); i++) {
				if (!isprint(title[i])) {
					MyException e("Invalid title input\n");
					throw e;
				}
			}
			return true;
		}

		bool validateLink(string link) {
			/*
			checks if string 'link' is a valid link
			valid links: secure HTTPS links
			Input:
				link (string) - trailer link input string
			Output:
				throws exception if input invalid
				returns true otherwise
			@author: Victor
			*/
			string test = "https://";
			for (int i = 0; i < test.size(); i++) {
				if (test[i] != link[i]) {
					MyException e("Invalid trailer link\n");
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
