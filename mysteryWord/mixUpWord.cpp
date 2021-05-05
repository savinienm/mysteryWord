#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "math.h"

using namespace std;

string mixUpWord(string word) {
	string mixUp;
	int letterPosition(0);

	while (word.size() > 0) {
		letterPosition = rand() % word.size();
		mixUp += word[letterPosition];
		word.erase(letterPosition, 1);
	}

	return mixUp;
}