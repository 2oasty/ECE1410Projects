#ifndef IMAGINARYNUMBER_HPP
#define IMAGINARYNUMBER_HPP

class ImaginaryNumber
{
public:
	
	//Default Constructor
	ImaginaryNumber();

	//Parameter Constructor
	ImaginaryNumber(double real, double imaginary);

	//Copy Constructor (For Linux)
	

	//Overload <<
	friend std::ostream& operator<<(std::ostream& os, ImaginaryNumber const& num)
	{
		if (num.m_real == 0 && num.m_imaginary == 0)
		{
			os << "0";
		}
		else if (num.m_real == 0)
		{
			os << num.m_imaginary << "j";
		}
		else if (num.m_imaginary == 0)
		{
			os << num.m_real;
		}
		else
		{
			os << num.m_real << " + " << num.m_imaginary << "j";
		}

		return os;
	}

	//Overload +=
	friend ImaginaryNumber& ImaginaryNumber::operator+=(ImaginaryNumber lhs, ImaginaryNumber const& rhs)
	{
		lhs.m_real = lhs.m_real + rhs.m_real;

		double realCopy = lhs.m_real;

		lhs.m_imaginary = lhs.m_imaginary + rhs.m_imaginary;

		lhs.m_real = realCopy;

		return lhs;
	}

	//Overload +
	friend ImaginaryNumber operator+(ImaginaryNumber lhs, ImaginaryNumber const& rhs)
	{
		return lhs+= rhs;
	}

	//Overload -=
	friend ImaginaryNumber& operator-=(ImaginaryNumber lhs, ImaginaryNumber const& rhs)
	{
		lhs.m_real = lhs.m_real - rhs.m_real;

		double realCopy = lhs.m_real;

		lhs.m_imaginary = lhs.m_imaginary - rhs.m_imaginary;

		lhs.m_real = realCopy;

		return lhs;
	}

	//Overload -
	friend ImaginaryNumber operator-(ImaginaryNumber lhs, ImaginaryNumber const& rhs)
	{
		return lhs -= rhs;
	}

	//Overload *=
	friend ImaginaryNumber& operator*=(ImaginaryNumber lhs, ImaginaryNumber const& rhs)
	{
		double realCopy = lhs.m_real;
		
		lhs.m_real = (lhs.m_real * rhs.m_real) - (lhs.m_imaginary * rhs.m_imaginary);

		lhs.m_imaginary = (lhs.m_imaginary * rhs.m_real) + (realCopy * rhs.m_imaginary);

		return lhs;
	}

	//Overload *
	friend ImaginaryNumber operator*(ImaginaryNumber lhs, ImaginaryNumber const& rhs)
	{
		return lhs *= rhs;
	}

	//Overload /=
	friend ImaginaryNumber& operator/=(ImaginaryNumber lhs, ImaginaryNumber const& rhs)
	{
		if (rhs.m_real == 0 && rhs.m_imaginary == 0)
		{
			lhs.m_real = 0;
		    lhs.m_imaginary = 0;
		    return lhs;
		}
		
		double realCopy = lhs.m_real;

		lhs.m_real = ((lhs.m_real * rhs.m_real) + (lhs.m_imaginary * rhs.m_imaginary)) /
		    ((rhs.m_real * rhs.m_real) + (rhs.m_imaginary * rhs.m_imaginary));

		
		lhs.m_imaginary = ((lhs.m_imaginary * rhs.m_real) - (realCopy * rhs.m_imaginary)) /
		    ((rhs.m_real * rhs.m_real) + (rhs.m_imaginary * rhs.m_imaginary));
		
		return lhs;
	}

	//Overload /
	friend ImaginaryNumber operator/(ImaginaryNumber lhs, ImaginaryNumber const& rhs)
	{
		return lhs /= rhs;
	}

	//Overload =
	ImaginaryNumber& operator=(const ImaginaryNumber& rhs);

	//Overload <
	friend bool operator< (ImaginaryNumber const& lhs, ImaginaryNumber const& rhs)
	{
		return ((lhs.m_real * lhs.m_real) + (lhs.m_imaginary * lhs.m_imaginary)) <
			((rhs.m_real * rhs.m_real) + (rhs.m_imaginary * rhs.m_imaginary));
	}

	//Overload <=
	friend bool operator<=(ImaginaryNumber const& lhs, ImaginaryNumber const& rhs)
	{ 
		return ((lhs.m_real * lhs.m_real) + (lhs.m_imaginary * lhs.m_imaginary)) <=
			((rhs.m_real * rhs.m_real) + (rhs.m_imaginary * rhs.m_imaginary));
	}

	//Overload >
	friend bool operator> (ImaginaryNumber const& lhs, ImaginaryNumber const& rhs)
	{ 
		return ((lhs.m_real * lhs.m_real) + (lhs.m_imaginary * lhs.m_imaginary)) >
			((rhs.m_real * rhs.m_real) + (rhs.m_imaginary * rhs.m_imaginary));
	}

	//Overload >=
	friend bool operator>=(ImaginaryNumber const& lhs, ImaginaryNumber const& rhs)
	{ 
		return ((lhs.m_real * lhs.m_real) + (lhs.m_imaginary * lhs.m_imaginary)) >=
			((rhs.m_real * rhs.m_real) + (rhs.m_imaginary * rhs.m_imaginary));
	}

	//Overload ==
	friend bool operator==(ImaginaryNumber const& lhs, ImaginaryNumber const& rhs)
	{
		return ((lhs.m_real * lhs.m_real) + (lhs.m_imaginary * lhs.m_imaginary)) ==
			((rhs.m_real * rhs.m_real) + (rhs.m_imaginary * rhs.m_imaginary));
	}

	//Gets real portion of imaginary number
	double getReal();

	//Gets imaginary portion of imaginary number
	double getImaginary();

private:
	double m_real;
	double m_imaginary;
};


#endif