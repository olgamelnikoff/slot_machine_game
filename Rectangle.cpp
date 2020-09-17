#include "Rectangle.h"

/*Constructor setting the initial values
of the rectangle's attributes (width and height);
the Shape base class constructor is used
to set the Shape's name and description;*/
Rectangle::Rectangle(double w, double h, string name, string description) : width{w}, height{h}, Shape (name, description) {} 

//Method to return the height of the rectangle's bounding box;
int Rectangle::getHeight() const
{
	return height;
}

//Method to return the width of the rectangle's bounding box;
int Rectangle::getWidth() const
{
	return width;
}

//Method to return the screen area of the rectangle;
int Rectangle::screenArea() const
{
	return height * width;
}

//Method to return the screen perimeter of the rectangle;
int  Rectangle::screenPerimeter() const
{
	return 2 * (height + width) - 4;
}

//Method to return the geometrical area of the rectangle;
double Rectangle::area() const
{
	return height * width;
}

//Method to return the geometrical perimeter of the rectangle;
double Rectangle::perimeter() const
{
	return 2 * (height + width);
}

/*
A method that returns an image of the rectangle
@param the foreground character to be used; the background character to be used
@return the textual image of the rectangle on a
2-dimensional grid that represents the rectangle's bounding box
and is aligned with the x and y axes of the rectangle
*/
Grid Rectangle::draw(char f, char b) const
{
	//create a vector of vectors of chars
	Grid grid;
	
	//outer loop: looping through the rectangle's height
	for (int x = 0; x < height; ++x)
	{
		//create a temporary vector that 
		//consists of characters and is 
		//a building block of the main vector
		vector<char> temp;

		//inner loop: looping through the rectangle's width
		for (int y = 0; y < width; ++y)
		{
			//since axes x and y of the rectangle
			//correspond to the height and width 
			//of the bounding box,
			//just print the foreground character
			//per each character of the bounding box
			temp.push_back(f);
			
		}
		//add the temporary vector to the main vector
		grid.push_back(temp);
	}
	return grid;
}