#include "RightTriangle.h"

/*Constructor setting the initial values
of the triangle's attributes:
the Triangle base class constructor is used
to set the base and hight; the Triangle class 
uses the Shape base class constructor 
to set the Shape's name and description;*/

RightTriangle::RightTriangle(int b, string name, string description) :
	Triangle(b, b, name, description) {}

//Method to return the geo perimeter of the triangle using a specific formula
double RightTriangle::perimeter() const { return (2 + sqrt(2)) * getWidth(); }

//Method to return the screen area of the triangle using a specific formula
int RightTriangle::screenArea() const { return (getWidth() * (getWidth() + 1) / 2); }

//Method to return the screen perimeter of the triangle using a specific formula
int RightTriangle::screenPerimeter() const { return 3 * (getWidth() - 1); }

/*
A method that returns an image of the right triangle
@param the foreground character to be used; the background character to be used
@return the textual image of the right triangle on a 
2-dimensional grid that represents the triangle's bounding box
and is aligned with the x and y axes of the right triangle 
*/
Grid RightTriangle::draw(char f, char b) const
{
	//create a vector of vectors of chars
	Grid grid;

	//outer loop: looping through the triangle's height (that equals to width)
	for (int x = 1; x <= getWidth(); ++x)
	{
		//create a temporary vector that 
		//consists of characters and is 
		//a building block of the main vector  
		vector <char> temp;

		//inner loop: looping through the triangle's width
		for (int y = 1; y <= getWidth(); ++y)
		{
			//add a foreground character if y <=x;
			//add a background character if otherwise
			temp.push_back(y <=x ? f : b);
		}

		//add the temporary vector to the main vector
		grid.push_back(temp);
	}
	return grid;
}