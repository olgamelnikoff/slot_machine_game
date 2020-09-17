#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <vector>
#include <iostream>

using std::string;

/*The grid objects are used to draw the Shape object;
a Grid is represented as a vector of vector of chars,
to implement the 2D requirement.*/

using Grid = std::vector<std::vector<char>>;

/*Base class Shape serves as a common interface
to specific shapes in the inheritance hierarchy.
The Shape class is abstract.
*/
class Shape
{

/*Three attributes common to any shape */
private:
	/*An ID number that is generated and assigned 
	when shape objects are first constructed; 
	the first ID is 1, the second is 2, etc.*/
	int id;

	/*Shape name, such as "Rectangle"*/
	string name;

	/*Shape description, such as "Four right angles"*/
	string description;

/*A helping static variable that sets the ID of next Shape 
by incrementing the current ID by 1; it helps to link 
different Shape objects to make sure their IDs are generated correctly*/
protected:
	static int nextID;

public:
	//default constructor
	Shape(string n = "Shape", string d = "Abstract 2D Geometric Shape");

	//defaulted copy constructor
	Shape(const Shape&) = default;

	//defaulted assignment operator
	Shape& operator = (const Shape&) = default;

	//default destructor (should be virtual)
	virtual ~Shape() = default;

	//Three accessor (getter) methods, one for each attribute:
	int getId() const;
	string getName() const;
	string getDescription() const;

	//Two setter methods for each attribute, except for the ID:
	void setName(string newName);
	void setDescription(string newDescription);

	//A method that generates and returns a string 
	//representation of the shape:
	string toString() const;

	/*Pure virtual (abstract) methods;
	they are abstract because 
	only concrete (derived) classes of Shape
	know how to calculate each feature below.*/
	
	//Method to calculate the Shape's area
	virtual double area() const = 0;

	//Method to calculate the Shape's perimeter
	virtual double perimeter() const = 0;

	//Method to calculate the Shape's screen area
	virtual int screenArea() const = 0;

	//Method to calculate the Shape's screen perimeter
	virtual int screenPerimeter() const = 0;

	/*A method that draws a textual image of the shape object 
	on a two dimensional grid using bounding box as a grid*/
	virtual Grid draw(char fChar = '*', char bChar = ' ') const = 0;

	//Method to return the height of the shape's bounding box
	virtual int getHeight() const = 0;

	//Method to return the width of the shape's bounding box
	virtual int getWidth() const = 0;
};

/*Insertion operator overload 
to perform output of the Shape and Grid objects*/
std::ostream& operator << (std::ostream&, const Shape&);
std::ostream& operator << (std::ostream& out, Grid newGrid);

#endif /*SHAPE_H*/