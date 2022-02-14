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

void PiggyBank::deposit(double money)
{
	if (money < 0)
	{
		std::cout << "Cannot deposit negative" << std::endl;
		exit(1);
	}

	if (m_state == false)
	{
		std::cout << "Cannot deposit money into broken bank" << std::endl;
		exit(1);
	}

	m_balance += money;
}

void PiggyBank::withdraw(double money)
{
	if (money < 0)
	{
		std::cout << "Cannot withdraw negative" << std::endl;
		exit(1);
	}

	if (m_state == false)
	{
		std::cout << "Cannot withdraw money into broken bank" << std::endl;
		exit(1);
	}

	if (money > m_balance)
	{
		std::cout << "Cannot withdraw more money than is available" << std::endl;
		exit(1);
	}

	m_balance -= money;
}

void PiggyBank::smash()
{
	m_state = false;

	if (m_balance > 0)
	{
		std::cout << "NOOO!!! You lost $" << std::fixed << std::setprecision(2) 
			<< m_balance << std::endl;
	}
}