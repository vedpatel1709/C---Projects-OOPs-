// Name: Patel Ved Rajendrakumar
// Seneca Student ID: 149409203
// Seneca email: vrpatel33@myseneca.ca
// Date of completion: 07/27/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

#include "CustomerOrder.h"
#include "Station.h"
#include "Utilities.h"

using namespace std;
namespace sdds
{
	size_t CustomerOrder::m_widthField = 0;

	CustomerOrder::CustomerOrder()
	{
		m_name = { "" };
		m_product = { "" };
		m_cntItem = { 0 };
		m_lstItem = { nullptr };
		m_widthField = { 0 };
	}

	CustomerOrder::CustomerOrder(const std::string& Str)
	{
		Utilities util;
		size_t NextPtn = 0;
		bool index = true;
		m_cntItem = 0;

		m_name = util.extractToken(Str, NextPtn, index);
		m_product = util.extractToken(Str, NextPtn, index);

		size_t Ptn = NextPtn;

		while (index)
		{
			util.extractToken(Str, NextPtn, index);
			m_cntItem++;
		}

		m_lstItem = new Item * [m_cntItem];
		index = true;

		for (size_t i = 0; i < m_cntItem; i++)
		{
			m_lstItem[i] = new Item(util.extractToken(Str, Ptn, index));
		}

		if (util.getFieldWidth() > m_widthField)
		{
			m_widthField = util.getFieldWidth();
		}
	}

	CustomerOrder::CustomerOrder(const CustomerOrder& CO)
	{
		throw "!ERROR";
	}

	CustomerOrder::CustomerOrder(CustomerOrder&& CO) noexcept
	{
		*this = std::move(CO);
	}

	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& CO) noexcept
	{
		if (this != &CO)
		{
			for (unsigned int z = 0; z < m_cntItem; ++z) delete m_lstItem[z];
			delete[] m_lstItem;
			m_name = CO.m_name;
			m_product = CO.m_product;
			m_cntItem = CO.m_cntItem;
			m_lstItem = CO.m_lstItem;
			CO.m_cntItem = 0;
			CO.m_lstItem = nullptr;
		}
		return *this;
	}

	CustomerOrder::~CustomerOrder()
	{
		if (m_lstItem)
			for (unsigned int i = 0; i < m_cntItem; i++) delete m_lstItem[i];

		delete[] m_lstItem;
		m_lstItem = nullptr;
	}

	bool CustomerOrder::isOrderFilled() const
	{
		bool index = true;
		for (unsigned int z = 0; z < m_cntItem; z++)
		{
			if (!m_lstItem[z]->m_isFilled) index = false;
		}
		return index;
	}

	bool CustomerOrder::isItemFilled(const std::string& itemName) const
	{
		bool Index = true;
		for (size_t i = 0; i < m_cntItem && Index; i++)
		{
			if (m_lstItem[i]->m_itemName == itemName)
			{
				Index = m_lstItem[i]->m_isFilled;
			}
		}
		return Index;
	}

	void CustomerOrder::fillItem(Station& station, ostream& os)
	{
		for (size_t i = 0; i < m_cntItem; i++)
		{
			if (!(m_lstItem[i]->m_isFilled) && m_lstItem[i]->m_itemName == station.getItemName())
			{
				if (station.getQuantity() > 0)
				{
					m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
					m_lstItem[i]->m_isFilled = true;
					station.updateQuantity();
					os << setw(11) << right;
					os << "Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
					break;
				}
				else
				{
					os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
				}
			}
		}
	}

	void CustomerOrder::display(std::ostream& os) const
	{
		os << m_name << " - " << m_product << std::endl;
		for (unsigned int i = 0; i < m_cntItem; i++)
		{
			os << "[" << setw(6) << setfill('0') << right << m_lstItem[i]->m_serialNumber << "] " << setfill(' ');
			os << setw(m_widthField) << left << m_lstItem[i]->m_itemName << " - ";
			os <<	(m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED") << std::endl;
		}
	}
};	// namespace sdds