/*
Name= Patel Ved Rajendrakumar
Student_ID=149409203
Section=OOP244 NAA
Workshop 8 part 1
Date: 18th november,2021
*/
/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_LABEL_SHAPE_H
#define SDDS_LABEL_SHAPE_H
#include "baseShape.h"
namespace sdds
{
	class labelShape : public baseShape
	{
		char* m_label{ nullptr };
	protected:
		const char* label() const;
	public:
		labelShape() {};
		labelShape(const char* label);
		~labelShape();
		labelShape(const labelShape& label) = delete;
		void operator=(const labelShape& label) = delete;
		void readShape(std::istream& istr);

	};
};
#endif

