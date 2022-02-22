#include "Shape.hpp"

#include <iostream>
#include <iomanip>

Shape::Shape() : id(0)
{

}

int Shape::getId()
{
	id = count;
	count++;

	return id;
}

void Shape::printInformation()
{
	std::cout << "Id: " << id << std::endl;
	std::cout << "Area: " << std::fixed << std::setprecision(2) << 
		calculateArea() << std::endl;
	std::cout << "Perimeter: " << std::fixed << std::setprecision(2) << 
		calculatePerimeter() << std::endl;
	std::cout << std::endl;
}

int Shape::count = 1;