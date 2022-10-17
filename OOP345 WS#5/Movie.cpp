#include <sstream>
#include <iomanip>
#include "Movie.h"
using namespace std;
namespace sdds {
	const string& Movie::title() const {
		return head;
	}

	Movie::Movie(const string& strMovie) {
		if (!strMovie.empty()) {
			stringstream line(strMovie);
			string temp{};
			getline(line, head, ',');
			head.erase(0, head.find_first_not_of(' '));
			head.erase(head.find_last_not_of(' ') + 1);
			getline(line, temp, ',');
			century = stoi(temp);
			getline(line, ord, '\n');
			ord.erase(0, ord.find_first_not_of(' '));
			ord.erase(ord.find_last_not_of(' ') + 1);
		}
		else { *this = Movie(); }
	}
	ostream& operator<<(ostream& os, const Movie& source) {
		os << setw(40) << right << source.head << " | ";
		os << setw(4) << source.century << " | ";
		os << left << source.ord << endl;
		return os;
	}
}