#include <iostream>
#include<typeinfo>
#include<cmath>
#include <sstream>
#include <iomanip>
#include "Shape.h"

using std::string;
using std::to_string;
using std::vector;
using std::ostream;
using std::ostringstream;
using std::fixed;
using std::setprecision;
using std::cout;
using std::endl;

/*Initializing the nextID static variable to 1
//(first ID of the first Shape object)*/
int Shape::nextID{ 1 };

/*Constructor setting the initial values 
of the shape's name and description;
the nextID of the previous Shape becomes
the current Shape ID (except for the first Shape object 
where its ID is 1; then nextID static variable is incremented*/

Shape::Shape(string n, string d) : name{ n }, description{ d } 
{
	id = nextID; 
	nextID++;
}

//Three accessor (getter) methods, one for each attribute:
int Shape::getId() const
{
	return id;
}

string Shape::getName() const
{
	return name;
}

string Shape::getDescription() const
{
	return description;
}

//Two setter methods for each attribute, except for the ID:
void Shape::setName(string newName)
{
	name = newName;
}

void Shape::setDescription(string newDescription)
{
	description = newDescription;
}

/*
Generates a string representation of the shape;
the "append" function of the "string" class is used
to append different pieces of information about the current 
Shape object to its String representation

@return Returns a string representation of the Shape 
that contains relevant information
*/

string Shape::toString() const
{
	string info;
	info.append("Shape Information\n");
	info.append("-----------------\n");
	info.append("id: ");

	//If an integer / double has to be appended to the string,
	//"to_string" method is used to convert it 
	//to string first
	info.append(to_string(getId()));
	info.append("\n");
	info.append("Shape name: ");
	info.append(getName());
	info.append("\n");
	info.append("Description: ");
	info.append(getDescription());
	info.append("\n");
	info.append("B. box width: ");
	info.append(to_string(getWidth()));
	info.append("\n");
	info.append("B. box height: ");
	info.append(to_string(getHeight()));
	info.append("\n");
	info.append("Scr area: ");
	info.append(to_string(screenArea()));
	info.append("\n");
	info.append("Geo area: ");

	/*To output exactly 2 decimal places in double "Geo area",
	an "ostringstream" object sout is used*/
	ostringstream sout;

	//setting precision to 2 decimal places in Geo area
	sout << fixed << setprecision(2) << area();

	//Getting the string content of "sout" and appending it to the main string
	info.append(sout.str());
	info.append("\n");
	info.append("Scr perimeter: ");
	info.append(to_string(screenPerimeter()));
	info.append("\n");
	info.append("Geo perimeter: ");

	/*To output exactly 2 decimal places in double "Geo perimeter",
	the same "ostringstream" object sout is used*/

	//First, the previous content of sout is removed
	sout.str("");
	sout.clear();

	//setting precision to 2 decimal places in Geo perimeter
	sout << fixed << setprecision(2) << perimeter();

	//Getting the string content of "sout" and appending it to the main string
	info.append(sout.str());
	info.append("\n");
	info.append("Static type: ");

	//Gets the name of the static type of the pointer "this" at runtime
	info.append(typeid(this).name());
	info.append("\n");
	info.append("Dynamic type: ");

	//Gets the name of the dynamic type of the pointer "this" at runtime
	info.append(typeid(*this).name());;
	info.append("\n");

	return info;
}

/*
Insertion operator overload
to perform output of Shape objects;
the output is equivalent to using "toString" method

@param the output stream, the shape to be output
@return the stream that outputs information about the Shape object
*/
ostream& operator<< (ostream& ostr, const Shape& newShape)
{
	ostr << newShape.toString() << endl;
	return ostr;
}

/*
Insertion operator overload
to perform drawing of an image of the Shape
using a Grid object;

@param the output stream, the grid to be output

@return the stream that "draws" the Shape object
on a two-dimensional grid
*/
ostream& operator << (ostream& out, Grid newGrid)
{

	for (int i = 0; i < newGrid.size(); ++i)
	{
		for (int j = 0; j < newGrid[i].size(); ++j)
		{
			out << newGrid[i][j];
		}
		out << endl;
	}
	return out;
}