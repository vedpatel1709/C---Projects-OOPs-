/*
* Name: Patel Ved Rajendrakumar
* Section: OOP244 NAA
* Email:vrpatel33@myseneca.ca
* student ID: 149409203
*/
/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/
#ifndef SDDS_CITY_H
#define SDDS_CITY_H
namespace sdds{
	const int POPULATION = 20000;
	class City {
	private:
		char m_cityName[31];
		int m_population;
	public:
		City();
		City(const char* name, int population);
		//City(const char* name, int population);
		void setEmpty();
		void setCityName(const char* name);
		void setPopulation(int population);
		void addPopulation(int population);
		bool isEmpty()const;
		int getPeople()const;
		void display()const;
      };
}
#endif