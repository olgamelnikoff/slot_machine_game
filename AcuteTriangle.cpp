#include "AcuteTriangle.h"

/*Constructor setting the initial values
of the triangle's attributes:
the Triangle base class constructor is used
to set the base and hight using specific formulas
(base equals b if b is odd and b + 1 if b is even;
height equals (b + 1) / 2;
the Triangle class
uses the Shape base class constructor
to set the Shape's name and description;*/

AcuteTriangle::AcuteTriangle(int b, string name, string description) : 
	Triangle((b % 2 == 0 ? b + 1 : b), (b + 1) / 2, name, description) {}

//Method to return the geo perimeter of the triangle using a specific formula
double AcuteTriangle::perimeter() const 
{ return getWidth() + sqrt(getWidth() * getWidth() + 4 * getHeight() * getHeight()); }

//Method to return the screen area of the triangle using a specific formula
int AcuteTriangle::screenArea() const { return getHeight() * getHeight(); }

//Method to return the screen perimeter of the triangle using a specific formula
int AcuteTriangle::screenPerimeter() const { return 4 * (getHeight() - 1); }

/*
A method that returns an image of the acute triangle
@param the foreground character to be used; the background character to be used
@return the textual image of the acute triangle on a
2-dimensional grid that represents the triangle's bounding box
and is aligned with the x and y axes of the acute triangle
*/
Grid AcuteTriangle::draw(char f, char b) const
{
	//create a vector of vectors of chars
	Grid grid;
	
	//half of the acute triangle's width
	int half = getWidth() / 2;

	//count represents the number of foreground 
	//characters in this particular grid line
	//it is initalized as 0;
	int count = 0;

	//outer loop: looping through the triangle's height
	for (int x = 0; x < getHeight(); ++x)
	{
		//create a temporary vector that 
		//consists of characters and is 
		//a building block of the main vector
		vector<char> temp;

		//inner loop: looping through the triangle's width
		for (int y = 0; y < getWidth(); ++y)
		{
			//add a foreground character if y >= (half - count) && y <= (half + count)
			//add a background character if otherwise
			temp.push_back((y >= (half - count)) && y <= (half + count) ? f : b);
		}

		//when we draw the triangle line-by-line, 
		//the count increases by 1 each time.
		count++;

		//add the temporary vector to the main vector
		grid.push_back(temp);
	}

	return grid;
}
