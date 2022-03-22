#include <ostream>
#include <iostream>
#include "ImaginaryNumber.hpp"


ImaginaryNumber::ImaginaryNumber() : m_real(0), m_imaginary(0)
{

}

ImaginaryNumber::ImaginaryNumber(double real, double imaginary) : 
	m_real(real), m_imaginary(imaginary)
{

}

ImaginaryNumber::ImaginaryNumber(ImaginaryNumber const& num)
{
    m_real = num.m_real;
    m_imaginary = num.m_imaginary;
}

ImaginaryNumber& ImaginaryNumber::operator+=(ImaginaryNumber const& rhs)
{
    
    this->m_real = this->m_real + rhs.m_real;

    this->m_imaginary = this->m_imaginary + rhs.m_imaginary;

    return *this;
}

ImaginaryNumber& ImaginaryNumber::operator-=(ImaginaryNumber const& rhs)
{
    this->m_real = this->m_real - rhs.m_real;

    this->m_imaginary = this->m_imaginary - rhs.m_imaginary;

    return *this;
}

ImaginaryNumber& ImaginaryNumber::operator*=(ImaginaryNumber const& rhs)
{
    double realCopy = this->m_real;

    this->m_real = (this->m_real * rhs.m_real) - (this->m_imaginary * rhs.m_imaginary);

    this->m_imaginary = (this->m_imaginary * rhs.m_real) + (realCopy * rhs.m_imaginary);

    return *this;
}

ImaginaryNumber& ImaginaryNumber::operator/=(ImaginaryNumber const& rhs)
{
    if (rhs.m_real == 0 && rhs.m_imaginary == 0)
    {
        this->m_real = 0;
        this->m_imaginary = 0;
        return *this;
    }

    double realCopy = this->m_real;

    this->m_real = ((this->m_real * rhs.m_real) + (this->m_imaginary * rhs.m_imaginary)) /
        ((rhs.m_real * rhs.m_real) + (rhs.m_imaginary * rhs.m_imaginary));


    this->m_imaginary = ((this->m_imaginary * rhs.m_real) - (realCopy * rhs.m_imaginary)) /
        ((rhs.m_real * rhs.m_real) + (rhs.m_imaginary * rhs.m_imaginary));

    return *this;
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