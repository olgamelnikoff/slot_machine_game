#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

using std::vector;

//Class Rectangle is a derived class of Shape.
class Rectangle : public Shape
{
public:
	
	//default constructor
	Rectangle(double w, double h, string name = "Rectangle", string description = "Four right angles");

	//defaulted destructor (should be virtual)
	virtual ~Rectangle() = default;

	//defaulted copy constructor
	Rectangle(const Rectangle&) = default;

	//defaulted assignment operator
	Rectangle& operator = (const Rectangle&) = default;

	//Method to return the height of the bounding box;
	//it overrides the pure function in the Shape class
	virtual int getHeight() const override;

	//Method to return the width of the bounding box;
	//it overrides the pure function in the Shape class
	virtual int getWidth() const override;

	//Method to return the screen area of the rectangle;
	//it overrides the pure function in the Shape class
	virtual int screenArea() const override;

	//Method to return the screen perimeter of the rectangle;
	//it overrides the pure function in the Shape class
	virtual int screenPerimeter() const override;

	//Method to return the geographical area of the rectangle;
	//it overrides the pure function in the Shape class
	virtual double area() const override;

	//Method to return the geographical perimeter of the rectangle;
	//it overrides the pure function in the Shape class
	virtual double perimeter() const override;

	//Method that draws the rectangle;
	//it overrides the pure function in the Shape class
	virtual Grid draw(char fChar = '*', char bChar = ' ') const override;

//attributes required to construct a Rectangle (height and width)
private:
	double width;
	double height;
};

#endif /*RECTANGLE_H*/
