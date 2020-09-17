#ifndef ACUTETRIANGLE_H
#define ACUTETRIANGLE_H
#include "Triangle.h"
#include<string>

using std::vector;

/*
Class AcuteTriangle is a derived class of the Triangle
base class.
*/
class AcuteTriangle : public Triangle
{

public:
	//default constructor that sets a default name and description of every Acute Triangle
	AcuteTriangle(int b, string first = "Wedge", string second = "All acute angles");

	//defaulted destructor (should be virtual)
	virtual ~AcuteTriangle() = default;

	//defaulted copy constructor
	AcuteTriangle(const AcuteTriangle&) = default;

	//defaulted assignment operator
	AcuteTriangle& operator = (const AcuteTriangle&) = default;

	//Method to return the geo perimeter of the triangle;
	//it overrides the pure function in the Shape class
	virtual double perimeter() const override;

	//Method to return the screen area of the triangle;
	//it overrides the pure function in the Shape class
	virtual int screenArea() const override;

	//Method to return the screen perimeter of the triangle;
	//it overrides the pure function in the Shape class
	virtual int screenPerimeter() const override;

	//Method that draws the right triangle
	//it overrides the pure function in the Shape class
	virtual Grid draw(char fChar = '*', char bChar = ' ') const override;
};

#endif /*ACUTETRIANGLE_H*/

