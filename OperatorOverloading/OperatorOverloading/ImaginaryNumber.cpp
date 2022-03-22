#include <ostream>
#include "ImaginaryNumber.hpp"


ImaginaryNumber::ImaginaryNumber() : m_real(0), m_imaginary(0)
{

}

ImaginaryNumber::ImaginaryNumber(double real, double imaginary) : 
	m_real(real), m_imaginary(imaginary)
{

}

ImaginaryNumber& ImaginaryNumber::operator=(const ImaginaryNumber& rhs)
{
    this->m_real = rhs.m_real;
    this->m_imaginary = rhs.m_imaginary;

    return *this;
}

double ImaginaryNumber::getReal()
{
    return m_real;
}

double ImaginaryNumber::getImaginary()
{
    return m_imaginary;
}