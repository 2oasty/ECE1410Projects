#ifndef SHAPE_HPP
#define SHAPE_HPP

class Shape
{
public:

	//Default Constructor
	Shape();

	//Returns copy of id
	int getId();

	//Prints id, area, and perimeter of shape
	void printInformation();

	//Calculates area of shape; pure virtual
	virtual double calculateArea() = 0;

	//Calculates perimeter of shape; pure virtual
	virtual double calculatePerimeter() = 0;

private:
	int id;
	static int count;

};

#endif