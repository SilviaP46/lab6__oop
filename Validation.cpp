#include "Validation.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;


bool Validation::check_string(string s)
{
	for (int i = 0; i < s.length(); i++)
		if (isdigit(s[i]) == true)
			return false;

	return true;
}

bool Validation::check_number(int n) {
	if (n < 0)
		return false;
	return true;
}
