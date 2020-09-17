#ifndef SLOTMACHINE_H
#define SLOTMACHINE_H

#include <array>
#include "Shape.h"

class SlotMachine
{
	std::array<std::unique_ptr<Shape>, 3> reel{}; //each array element is a pointer to a Shape object
	void make_shapes(); //generate three random shapes;
	void make_shape(int k); //generate random integers to assign different shapes and widths
	void display(); //display the three reels

	//five helping methods to compute tokens, depending on the display result
	bool two_similar_shapes();
	bool two_equal_screen_areas();
	bool three_similar_shapes();
	bool middle_exceeds_sum_of_left_and_right();
	bool left_and_right_similar();

public:
	SlotMachine() = default; //default constructor
	SlotMachine(const SlotMachine&) = delete; //copy constructor is removed
	SlotMachine(SlotMachine&&) = delete; //move constructor is removed
	SlotMachine& operator = (const SlotMachine&) = delete; //assignment operator is removed
	SlotMachine& operator = (const SlotMachine&&) = delete; // assignment operator is removed
	virtual ~SlotMachine() = default; //defaulted destructor
	void run(); //run the game

};
#endif /*SLOTMACHINE_H*/

