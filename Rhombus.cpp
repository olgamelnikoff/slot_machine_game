#include <math.h>
#include "Rhombus.h"

/*Constructor setting the initial values
of the rhombus's attributes:
d is set using the following formula:
d equals h if h is odd and h + 1 if h is even;
the Shape base class constructor is used
to set the Shape's name and description;*/

Rhombus::Rhombus(int h, string name, string description) : Shape (name, description)
{
	if (h % 2 == 0) {
		d = h + 1;
	}
	else
	{
		d = h;
	}
}

//Method to return the height of the rhombus's bounding box;
int Rhombus::getHeight() const { return d; }

//Method to return the width of the rhombus's bounding box;
int Rhombus::getWidth() const { return d; }

//Method to return the screen area of the rhombus using a specific formula
int Rhombus::screenArea() const
{
	int n = d / 2;
	return (2 * n * (n + 1) + 1);
}

//Method to return the screen perimeter of the rhombus using a specific formula
int Rhombus::screenPerimeter() const { return 2 * (d - 1); }

//Method to return the geo area of the rhombus using a specific formula
double Rhombus::area() const { return ((double) (d * d)) / 2; }

//Method to return the geo perimeter of the rhombus using a specific formula
double Rhombus::perimeter() const { return (2 * sqrt(2)) * d; }

/*
A method that returns an image of the rhombus
@param the foreground character to be used; the background character to be used
@return the textual image of the rhombus on a
2-dimensional grid that represents the rhombus's bounding box
and is aligned with the x and y axes of the rhombus
*/
Grid Rhombus::draw(char f, char b) const
{
	//create a vector of vectors of chars
	Grid grid;

	//half of rhombus's height
	int half = d / 2;

	//count represents the number of foreground 
	//characters in this particular grid line
	//it is initalized as 0;
	int count = 0;

	//outer loop: looping through the rhombus's height
	for (int x = 0; x < getHeight(); ++x)
	{
		//create a temporary vector that 
		//consists of characters and is 
		//a building block of the main vector
		vector<char> temp;

		//inner loop: looping through the rhombus's width 
		for (int y = 0; y < getWidth(); ++y)
		{
			//add a foreground character if y >= (half - count) && y <= (half + count)
			//add a background character if otherwise
			temp.push_back((y >= (half - count)) && (y <= (half + count)) ? f : b);
		}

		//if x is less than half (we are in the top part of rhombus), 
		//then we increase the count of the foreground characters
		if (x < half) { count++; }

		//if x is equal to or more than half (we are in the bottom part of rhombus),
		//then we decrease the count of the foreground characters
		else { count-- ; }

		//add the temporary vector to the main vector
		grid.push_back(temp);
	}
	return grid;
}