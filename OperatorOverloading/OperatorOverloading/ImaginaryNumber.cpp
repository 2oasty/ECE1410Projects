#include <iostream>
#include <ostream>
#include "ImaginaryNumber.hpp"


ImaginaryNumber::ImaginaryNumber() : m_real(0), m_imaginary(0)
{

}

ImaginaryNumber::ImaginaryNumber(double real, double imaginary) : 
	m_real(real), m_imaginary(imaginary)
{

}

ImaginaryNumber& ImaginaryNumber::operator+=(ImaginaryNumber const& rhs) 
{
    this->m_real += rhs.m_real;
    return *this;
}

ImaginaryNumber& ImaginaryNumber::operator-=(ImaginaryNumber const& rhs)
{
    this->m_real -= rhs.m_real;
    return *this;
}

ImaginaryNumber& ImaginaryNumber::operator*=(ImaginaryNumber const& rhs)
{
    this->m_real *= rhs.m_real;
    return *this;
}

ImaginaryNumber& ImaginaryNumber::operator/=(ImaginaryNumber const& rhs)
{
    this->m_real /= rhs.m_real;
    return *this;
}

double ImaginaryNumber::getReal()
{
    return 0;
}

double ImaginaryNumber::getImaginary()
{
    return 0;
}