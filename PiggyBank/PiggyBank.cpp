#include <iostream>
#include <iomanip>
#include "PiggyBank.hpp"

PiggyBank::PiggyBank() : m_balance(0), m_state(true)
{

}

PiggyBank::PiggyBank(double balance) : m_balance(balance), m_state(true)
{
	
}

PiggyBank::~PiggyBank()
{
	if (m_state == true) 
	{
		std::cout << "Piggy bank had $" << std::fixed << std::setprecision(2) 
			<< m_balance << " upon deconstruction." << std::endl;
	}
}

double PiggyBank::countSavings() const
{
	return m_balance;
}