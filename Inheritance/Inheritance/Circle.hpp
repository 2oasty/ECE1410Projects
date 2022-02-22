#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "Shape.hpp"

class Circle : public Shape
{
public:

	//Default Constructor
	Circle();

	//Parameter Constructor
	Circle(int radius);

	//Calculate area override
	virtual double calculateArea() override final;

	//Calculate perimeter override
	virtual double calculatePerimeter() override final;

private:
	int id;
	int m_radius;

};


#endif