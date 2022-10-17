#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <string>
#include "SpellChecker.h"
using namespace std;
namespace sdds {
	class Movie {
		string head{};
		size_t century{};
		string ord{};
	public:
		Movie() = default;
		const string& title() const;
		Movie(const string& strMovie);
		template <typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(head);
			spellChecker(ord);
		}
		friend ostream& operator<<(ostream& os, const Movie& source);
	};
}
#endif