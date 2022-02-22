#include "Shape.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"

#include <iostream>

int main()
{
	//Creates two circles
	Circle* c1 = new Circle(3);
	Circle* c2 = new Circle(10);

	//Creates two rectangles
	Rectangle* r1 = new Rectangle(2, 2);
	Rectangle* r2 = new Rectangle(3, 5);

	//Prints shape info
	c1->printInformation();
	c2->printInformation();
	r1->printInformation();
	r2->printInformation();
	
	//Cleans up
	delete c1;
	delete c2;
	delete r1;
	delete r2;

	return 0;
}