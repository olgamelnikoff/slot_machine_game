#ifndef RIGHTTRIANGLE_H
#define RIGHTTRIANGLE_H

#include "Triangle.h"

using std::vector;

/*Class RightTriangle is a derived class of the Triangle
base class.
*/
class RightTriangle : public Triangle
{
public:
	//default constructor that sets a default name and description of every Right Triangle
	RightTriangle(int b, string first = "Ladder", string second = "One right and two acute angles");

	//defaulted destructor (should be virtual)
	virtual ~RightTriangle() = default;

	//defaulted copy constructor
	RightTriangle(const RightTriangle&) = default;

	//defaulted assignment operator
	RightTriangle& operator = (const RightTriangle&) = default;

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
#endif /*RIGHTTRIANGLE_H*/

