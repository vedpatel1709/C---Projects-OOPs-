#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <stdexcept>
#include <string>
using namespace std;
namespace sdds {
	template <typename T>
	class Collection {
		string ident;
		T* thing{};
		size_t per{};
		void (*gesv)(const Collection<T>&, const T&) { nullptr };
	public:
		Collection(const string& name) {
			ident = name;
			thing = nullptr;
			per = 0;
			gesv = nullptr;
		}

		~Collection() {
			delete[] thing;
			thing = nullptr;
		}

		Collection(Collection&) = delete;
		Collection& operator=(Collection&) = delete;
		const string& name() const {
			return ident;
		}

		size_t size() const
		{
			return per;
		}

		void setObserver(void (*observer)(const Collection<T>&, const T&))
		{
			gesv = observer;
		}

		Collection<T>& operator+=(const T& item) {
			bool exists = false;
			for (size_t x = 0; x < per; ++x) {
				if (thing[x].title() == item.title()) {
					exists = true;
				}
			}
			if (!exists) {
				if (per == 0) {
					per++;
					thing = new T[per];
					thing[0] = item;
				}
				else {
					T* temp = new T[per];
					for (size_t x = 0; x < per; ++x) {
						temp[x] = thing[x];
					}
					delete[] thing;
					per++;
					thing = new T[per];
					for (size_t y = 0; y < per - 1; ++y) {
						thing[y] = temp[y];
					}
					delete[] temp;
					thing[per - 1] = item;
					if (gesv != nullptr) {
						gesv(*this, item);
					}
				}
			}
			return *this;
		}

		T& operator[](size_t idx) const {
			if (idx >= per || idx < 0) {
				string exception = { "Bad index [" + to_string(idx) + "]. " + "Collection has [" + to_string(per) + "] items." };
				throw out_of_range(exception);
			}
			else { return thing[idx]; }
		}

		T* operator[](string title) const {
			int xex = -1;
			for (size_t x = 0; x < per; x++) {
				if (thing[x].title() == title) {
					xex = x;
				}
			}
			if (xex == -1)
			{
				return nullptr;
			}
			else { return &thing[xex]; }
		}

		friend ostream& operator<<(ostream& os, Collection& source) {
			for (size_t x = 0; x < source.size(); ++x) {
				os << source.thing[x];
			}
			return os;
		}
	};
}
#endif