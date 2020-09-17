#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"
using std::vector;

/*Class Triangle is a derived class of Shape 
and a base class for AcuteTriangle and RightTriangle. 
It is abstract because most of the functions 
can only be implemented in its derived classes.
*/
class Triangle : public Shape
{

/*Two attributes common to any type of triangle */
private:
	double base;
	double height;

public:

	//default constructor
	Triangle(double b, double h, string first, string second);

	//defaulted destructor (should be virtual)
	virtual ~Triangle() = default;

	//defaulted copy constructor
	Triangle (const Triangle&) = default;

	//defaulted assignment operator
	Triangle& operator = (const Triangle&) = default;

	//Method to return the height of the triangle;
	//it overrides the pure function in the Shape class
	virtual int getHeight() const override;

	//Method to return the width of the triangle;
	//it overrides the pure function in the Shape class
	virtual int getWidth() const override;

	//Method to return the geometric area of the triangle;
	//it overrides the pure function in the Shape class
	virtual double area() const override;
};
#endif TRIANGLE_H

