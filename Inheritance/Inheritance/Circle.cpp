#include "Circle.hpp"

#include <iostream>

Circle::Circle() : Shape(), m_radius(0), id(getId())
{

}

Circle::Circle(int radius) : Shape(), id(getId()), m_radius(radius)
{

}

double Circle::calculateArea()
{
	double area = 0;
	area = 3.14 * (m_radius * m_radius);

	return area;
}

double Circle::calculatePerimeter()
{
	double perimeter = 0;
	perimeter = 2 * 3.14 * m_radius;

	return perimeter;
}