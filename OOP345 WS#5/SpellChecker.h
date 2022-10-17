#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H
#include <string>
using namespace std;
const int MAXIMUM = 6;
namespace sdds {
	class SpellChecker {
		string words[MAXIMUM];
		string d_satisfactoryWords[MAXIMUM];
		int ABN[MAXIMUM]{ 0 };
	public:
		SpellChecker(const char* filename);
		void operator()(string& text);
		void showStatistics(ostream& out);
	};
}
#endif