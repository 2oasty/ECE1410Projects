#include "Rectangle.hpp"

#include <iostream>

Rectangle::Rectangle() : Shape(), id(getId()), m_width(0), m_height(0)
{

}

Rectangle::Rectangle(int width, int height) : Shape(), id(getId()), m_width(width), m_height(height)
{

}

double Rectangle::calculateArea()
{
	double area = 0;
	area = m_width * m_height;

	return area;
}

double Rectangle::calculatePerimeter()
{
	double perimeter = 0;
	perimeter = 2 * (m_width + m_height);

	return perimeter;
}
