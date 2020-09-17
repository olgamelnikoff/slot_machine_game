#ifndef RHOMBUS_H
#define RHOMBUS_H

#include <string>
#include "Shape.h"

using std::vector;

//Class Rhombus is a derived class of Shape.
class Rhombus : public Shape
{
public:
	//default constructor
	Rhombus(int d, string name = "Diamond", string description = "Parallelogram with equal sides");

	//defaulted destructor (should be virtual)
	virtual ~Rhombus() = default;

	//defaulted copy constructor
	Rhombus(const Rhombus&) = default;

	//defaulted assignment operator
	Rhombus& operator = (const Rhombus&) = default;

	//Method to return the height of the bounding box;
	//it overrides the pure function in the Shape class
	virtual int getHeight() const override;
	
	//Method to return the width of the bounding box;
	//it overrides the pure function in the Shape class
	virtual int getWidth() const override;

	//Method to return the screen area of the rhombus;
	//it overrides the pure function in the Shape class
	virtual int screenArea() const override;

	//Method to return the screen perimeter of the rhombus;
	//it overrides the pure function in the Shape class
	virtual int screenPerimeter() const override;

	//Method to return the geometric area of the rhombus;
	//it overrides the pure function in the Shape class
	virtual double area() const override;

	//Method to return the geometric perimeter of the rhombus;
	//it overrides the pure function in the Shape class
	virtual double perimeter() const override;

	//Method that draws the rhombus;
	//it overrides the pure function in the Shape class
	virtual Grid draw(char fChar = '*', char bChar = ' ') const override;

private:

	//an attribute required to construct a Rhombus
	int d;
};

#endif /*RHOMBUS_H*/