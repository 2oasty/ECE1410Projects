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
	ImaginaryNumber& operator+=(ImaginaryNumber const& rhs);

	//Overload +
	friend ImaginaryNumber operator+(ImaginaryNumber lhs, ImaginaryNumber const& rhs)
	{
		lhs += rhs;
		return lhs;
	}

	//Overload -=
	ImaginaryNumber& operator-=(ImaginaryNumber const& rhs);


	//Overload -
	friend ImaginaryNumber operator-(ImaginaryNumber lhs, ImaginaryNumber const& rhs)
	{
		lhs -= rhs;
		return lhs;
	}

	//Overload *=
	ImaginaryNumber& operator*=(ImaginaryNumber const& rhs);

	//Overload *
	friend ImaginaryNumber operator*(ImaginaryNumber lhs, ImaginaryNumber const& rhs)
	{
		lhs *= rhs;
		return lhs;
	}

	//Overload /=
	ImaginaryNumber& operator/=(ImaginaryNumber const& rhs);


	//Overload /
	friend ImaginaryNumber operator/(ImaginaryNumber lhs, ImaginaryNumber const& rhs)
	{
		lhs /= rhs;
		return lhs;
	}

	//Overload =

	//Overload <
	friend bool operator< (ImaginaryNumber const& lhs, ImaginaryNumber const& rhs)
	{
		return lhs.m_real == rhs.m_real;
	}

	//Overload <=
	friend bool operator<=(ImaginaryNumber const& lhs, ImaginaryNumber const& rhs)
	{ 
		return lhs.m_real == rhs.m_real;
	}

	//Overload >
	friend bool operator> (ImaginaryNumber const& lhs, ImaginaryNumber const& rhs)
	{ 
		return lhs.m_real == rhs.m_real;
	}

	//Overload >=
	friend bool operator>=(ImaginaryNumber const& lhs, ImaginaryNumber const& rhs)
	{ 
		return lhs.m_real == rhs.m_real;
	}

	//Overload ==
	friend bool operator==(ImaginaryNumber const& lhs, ImaginaryNumber const& rhs)
	{
		return lhs.m_real == rhs.m_real;
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