#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Shape.hpp"

class Rectangle : public Shape
{
public:

	//Default Constructor
	Rectangle();

	//Parameter Constructor
	Rectangle(int width, int height);

	//Calculate area override
	virtual double calculateArea() override;

	//Calculate perimeter override
	virtual double calculatePerimeter() override;

private:
	int m_width;
	int m_height;

};

#endif