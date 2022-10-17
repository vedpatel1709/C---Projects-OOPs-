#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include "SpellChecker.h"

namespace sdds {

	SpellChecker::SpellChecker(const char* filename) {
		ifstream file(filename);
		if (!file) {
			throw "Bad file name!";
		}
		else {
			string temprea;
			size_t x = 0;
			while (file && x < MAXIMUM) {
				getline(file, words[x], ' ');
				words[x].erase(0, words[x].find_first_not_of(' '));
				words[x].erase(words[x].find_last_not_of(' ') + 1);
				getline(file, d_satisfactoryWords[x], '\n');
				d_satisfactoryWords[x].erase(0, d_satisfactoryWords[x].find_first_not_of(' '));
				d_satisfactoryWords[x].erase(d_satisfactoryWords[x].find_last_not_of(' ') + 1);
				x++;
			}
			file.close();
		}
	}
	void SpellChecker::operator()(string& text) {
		for (int x = 0; x < MAXIMUM; x++) {
			while (text.find(words[x]) != string::npos) {
				text.replace(text.find(words[x]), words[x].size(), d_satisfactoryWords[x]);
				++ABN[x];
			}
		}
	}
	void SpellChecker::showStatistics(ostream& out) {
		cout << "Spellchecker Statistics" << endl;
		for (int x = 0; x < MAXIMUM; x++) {
			out << setw(15) << right << words[x] << ": " << ABN[x] << " replacements" << endl;
		}
	}
}