// Name: Patel Ved Rajendrakumar
// Seneca Student ID: 149409203
// Seneca email: vrpatel33@myseneca.ca
// Date of completion: 07/27/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>

#include "LineManager.h"
#include "Utilities.h"
#include "Workstation.h"

using namespace std;
using namespace sdds;

LineManager::LineManager() : m_cntCustomerOrder{0}, m_firstStation{nullptr} {}

LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stn)
{
	ifstream file_str(file);
	string Str;
	bool Index = true;
	size_t count = 0;

	m_cntCustomerOrder = g_pending.size();

	while (getline(file_str, Str))
	{
		size_t pos = Str.find('|');
		for (size_t i = 0; i < stn.size(); i++)
		{
			if (Str.substr(0, pos) == stn.at(i)->getItemName())
			{
				if (pos != SIZE_MAX)
				{
					for (size_t j = 0; j < stn.size(); j++)
					{
						if (Str.substr(pos + 1) == stn.at(j)->getItemName())
						{
							stn.at(i)->setNextStation(stn.at(j));
							m_activeLine.push_back(std::move(stn.at(i)));
						}
					}
				}
				else
				{
					m_activeLine.push_back(std::move(stn.at(i)));
				}
			}
		}

		for (size_t k = 0; k < m_activeLine.size(); k++)
		{
			for (size_t l = 0; l < m_activeLine.size(); l++)
			{
				if (m_activeLine.at(l)->getNextStation() != nullptr)
				{
					if (m_activeLine.at(k)->getItemName() ==
						m_activeLine.at(l)->getNextStation()->getItemName())
					{
						Index = false;
					}
				}
			}

			if (Index)
			{
				m_firstStation = m_activeLine.at(k);
			}

			Index = true;
		}

		count++;
	}
}

void LineManager::reorderStations()
{
	vector<Workstation*> stn;
	Workstation* stnPtr = nullptr;

	unsigned int count = 0;
	while (count < m_activeLine.size())
	{
		for (unsigned int i = 0; i < m_activeLine.size(); i++)
		{
			if (m_activeLine[i]->getNextStation() == stnPtr)
			{
				stn.push_back(m_activeLine[i]);
				stnPtr = m_activeLine[i];
				count++;
				break;
			}
		}
	}
	reverse(stn.begin(), stn.end());
	m_firstStation = stn[0];
	m_activeLine = stn;
}

bool LineManager::run(std::ostream& os)
{
	static int count = 0;
	count++;
	os << "Line Manager Iteration: " << count << endl;

	if (!g_pending.empty())
	{
		(*m_firstStation) += move(g_pending.front());
		g_pending.pop_front();
	}

	for (unsigned int i = 0; i < m_activeLine.size(); i++)
	{
		m_activeLine[i]->fill(os);
	}

	for (unsigned int i = 0; i < m_activeLine.size(); i++)
	{
		m_activeLine[i]->attemptToMoveOrder();
	}

	bool isEmpty = true;
	for (unsigned int i = 0; i < m_activeLine.size(); i++)
	{
		if (!m_activeLine[i]->empty())
		{
			isEmpty = false;
			break;
		}
	}

	return isEmpty;
}

void LineManager::display(std::ostream& os) const
{
	std::for_each(m_activeLine.begin(), m_activeLine.end(), [&os](const Workstation* ws)
		{
			ws->display(os);
		});
}