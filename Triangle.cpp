#include "Triangle.h"

/*Constructor setting the initial values
of the triangle's base and hight;
the Shape base class constructor is used 
to set the shape's name and description;*/
Triangle::Triangle(double b, double h, string name, string description) : Shape{name, description}
{
	base = b;
	height = h;
}

//Method to return the height of the triangle' bounding box;
int Triangle::getHeight() const { return height;}

//Method to return the width of the triangle's bounding box;
int Triangle::getWidth() const { return base; }

//Method to return the geometric area of the triangle using a triangle-specific formula
double Triangle::area() const { return (height * base) / 2; }