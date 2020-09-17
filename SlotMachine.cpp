#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <initializer_list>
#include "SlotMachine.h"
#include "Rectangle.h"
#include "Rhombus.h"
#include "RightTriangle.h"
#include "AcuteTriangle.h"

using std::cout;
using std::cin;
using std::endl;

/*
A method that determines the algorithm of the game
and allows the user to play the game
*/

void SlotMachine::run()
{
	//Welcome message
	std::cout << "Welcome to 3-Reel Lucky Slot Machine Game!" << endl;
	cout << "Each reel will randomly display one of four shapes, each in 25 sizes." << endl;
	cout << "To win 3 x bet, get 2 similar shapes AND 2 shapes with equal Scr Areas" << endl;
	cout << "To win 2 x bet, get 3 similar shapes" << endl;
	cout << "To win 1 x bet, get (Middle) Scr Area > (Left + Right) Scr Areas" << endl;
	cout << "To win or lose nothing, get same Left and Right shapes" << endl;
	cout << "Otherwise, you lose your bet." << endl;
	cout << "You start with 10 free slot tokens!" << endl;

	//Setting the number of current tokens to 10
	int current_tokens = 10;

	//While player's current tokens > 0:
	while (current_tokens > 0)
	{
		//Prompt the user for a bet and read it;
		cout << "How much would you like to bet (enter 0 to quit)?" << endl;
		int t;
		string badData;
		string errorMessage = "Please enter an integer that does not exceed the number of your tokens or enter 0 to quit";
		cin >> t;

		//If the user's input is incorrect or the entered number exceeds the number of tokens,
		//display an error message and prompt the user to enter the bet again
		while (!cin || t > current_tokens)
		{
			if (!cin)
			{
				cin.clear();
				getline(cin, badData);
			}

			cout << errorMessage << endl;
			cin >> t;
		}
		getline(cin, badData);

		//If the user enters "0", the program terminates
		if (t == 0)
		{
			cout << "Game Over." << endl;
			exit(EXIT_FAILURE);
		}

		make_shapes(); //generate three random shapes;
		display(); //display the three reels
		
		//Case 1: 3 x bet
		if (two_similar_shapes() && two_equal_screen_areas())
		{
			t *= 3;
			cout << "Jackpot! 2 Similar Shapes AND 2 Equal Screen Areas" << endl;
			cout << "Congratulations! You win 3 times your bet: " << t << endl;
			current_tokens += t;
		}

		//Case 2: 2 x bet
		else if (three_similar_shapes())
		{
			t *= 2;
			cout << "Three similar shapes" << endl;
			cout << "Congratulations! You win 2 times your bet: " << t << endl;
			current_tokens += t;

		}

		//Case 3: 1 x bet
		else if (middle_exceeds_sum_of_left_and_right())
		{
			cout << "Middle > Left + Right, in Screen Areas" << endl;
			cout << "Congratulations! You win your bet: " << t << endl;
			current_tokens += t;
		}

		//Case 4: 0 x bet
		else if (left_and_right_similar())
		{
			t = 0;
			cout << "Lucky this time!" << endl;
			cout << "You don't win, you don't lose, you are safe!" << endl;
			current_tokens += t;
		}

		//Case 5: -1 x bet
		else
		{
			cout << "Oh No!" << endl;
			cout << "You lose your bet" << endl;
			current_tokens -= t;
		}
		cout << "You now have " << current_tokens << " tokens." << endl;
	}

	//If the tokens number becomes 0, display an appropriate message and terminate the program
	cout << "You now have 0 tokens" << endl;
	cout << "You just ran out of tokens. Better luck next time!" << endl;
	cout << "Game Over." << endl;

}

/*
A method that generates three random shapes using make_shape(k) method
*/
void SlotMachine::make_shapes()
{
	for (int k = 0; k < 3; ++k)
	{
		make_shape(k);
	}
}

/*
A method that generates a random shape of a random size
@param an integer pointing to the shape number in the reel line (0, 1 or 2)
*/
void SlotMachine::make_shape(int k)
{
	//generate a random number out of 4 (0, 1, 2 or 3);
	//each number will correspond to a particular shape
	int n = rand() % 4;
	
	//generate a random size of the shape out of 25 (from 1 to 25)
	int w = rand() % 25 + 1;

	//assign a particular shape to each possible random number
	if (n == 0)
	{
		reel[k].reset(new Rhombus(w));
	}

	else if (n == 1)
	{
		reel[k].reset(new AcuteTriangle(w));
	}

	else if (n == 2)
	{
		reel[k].reset(new RightTriangle(w));
	}

	else 
	{
		//generate a random height of the rectangle (from 1 to 25)
		int h = rand() % 25 + 1;
		reel[k].reset(new Rectangle(w, h));
	}
}

/*
A method that prints the three reels side-by-side horizontally
and displays information about them as text below the graphical representation
*/
void SlotMachine::display()
{
	//Create a grid of the first reel
	Grid box_0 = reel[0]->draw();
	
	//Create a grid of the second reel
	Grid box_1 = reel[1]->draw();
	
	//Create a grid of the third reel
	Grid box_2 = reel[2]->draw();
	
	//Create the main grid
	Grid mainGrid;

	//Find the main grid height using the following formula:
	//maximum hight out of the three shapes + 2;
	//max() function is used
	int mainGridHeight = std::max({ reel[0]->getHeight(), reel[1]->getHeight(), reel[2]->getHeight() }) + 2;
	
	//Find the main grid width using the following formula:
	//sum of widths of all the three shapes + 10;
	int mainGridWidth = reel[0]->getWidth() + reel[1]->getWidth() + reel[2]->getWidth() + 10;

	//In the drawing of the three reels printed side by side, 
	//there are 2 internal "pluses" and 6 margins in total,
	//according to the Assignment

	//Finding position of each of them based on the drawings on pages 19 and 21:
	int first_internal_plus = reel[0]->getWidth() + 3;
	int second_internal_plus = reel[0]->getWidth() + reel[1]->getWidth() + 6;
	int margin_one = 1;
	int margin_two = first_internal_plus - 1;
	int margin_three = first_internal_plus + 1;
	int margin_four = second_internal_plus - 1;
	int margin_five = second_internal_plus + 1;
	int margin_six = mainGridWidth - 2;

	//Filling out the main grid:

	//outer loop: looping through the main grid height
	for (int i = 0; i < mainGridHeight; i++)
	{
		//create a temporary vector that 
		//consists of characters and is 
		//a building block of the main vector
		vector<char> temp;

		//inner loop: looping through the main grid width
		for (int j = 0; j < mainGridWidth; j++)
		{
			//if i = 0 (top line of main grid) 
			//or i = mainGridHeight - 1 (bottom line of main grid):
			if (i == 0 || i == mainGridHeight - 1)
			{	
				//if j corresponds to 0, first internal plus, 
				//second internal plus or  mainGridHeight - 1,
				//'+' should be printed
				if (j == 0 || j == first_internal_plus || j == second_internal_plus || j == mainGridWidth - 1)
				{
					temp.push_back('+');
				}

				//otherwise, '-' should be printed 
				else
				{
					temp.push_back('-');
				}
			}
			//external and internal pluses of the top and bottom line
			//are connected by vertical lines using '|'
			//that denotes reel external and internal borders
			else if (j == 0 || j == first_internal_plus || j == second_internal_plus || j == mainGridWidth - 1)
			{
				temp.push_back('|');
			}

			//margins are padded with blank spaces 
			else if (j == margin_one || j == margin_two || j == margin_three || j == margin_four || j == margin_five || j == margin_six)
			{
				temp.push_back(' ');
			}

			//All except borders and margins
			//can be filled with any symbol
			//(we have "prepped" the grids
			//for filling them with particular shapes.
			else 
			{
				temp.push_back('^');
			}
		}
		//add the temporary vector to the main vector
		mainGrid.push_back(temp);
	}

	//Find the offsets for each reel (the offsets are borders + margins)
	int first_reel_offset = margin_one + 1;
	int second_reel_offset = margin_three + 1;
	int third_reel_offset = margin_five + 1;

	//Inserting the shape of the first reel (box_0)
	//into the main grid
	for (int i = 0; i < reel[0]->getHeight(); i++)
	{
		for (int j = 0; j < reel[0]->getWidth(); j++)
		{
			mainGrid[i + 1][j + first_reel_offset] = box_0[i][j];
		}
	}

	//Inserting the shape of the second reel (box_1)
	//into the main grid
	for (int i = 0; i < reel[1]->getHeight(); i++)
	{
		for (int j = 0; j < reel[1]->getWidth(); j++)
		{
			mainGrid[i + 1][j + second_reel_offset] = box_1[i][j];
		}
	}

	//Inserting the shape of the third reel (box_2)
	//into the main grid
	for (int i = 0; i < reel[2]->getHeight(); i++)
	{
		for (int j = 0; j < reel[2]->getWidth(); j++)
		{
			mainGrid[i + 1][j + third_reel_offset] = box_2[i][j];
		}
	}

	//Printing out the main grid
	//represented by three shapes
	//positioned side by side horizontally
	std::cout << mainGrid << endl;

	//Printing out information about each reel
	//(its shape and dimensions)
	std::cout << "(" << reel[0]->getName() << ", " << reel[0]->getHeight() << ", " << reel[0]->getWidth() << ") ";
	std::cout << "(" << reel[1]->getName() << ", " << reel[1]->getHeight() << ", " << reel[1]->getWidth() << ") ";
	std::cout << "(" << reel[2]->getName() << ", " << reel[2]->getHeight() << ", " << reel[2]->getWidth() << ") " << endl;
}

//Five helping methods to compute tokens, depending on the display result

/*
A method that determines if two symbols are similar in shape
@return true if they are similar; false if they are not similar
*/
bool SlotMachine::two_similar_shapes()
{
	if (reel[0]->getName() == reel[1]->getName()
		|| reel[1]->getName() == reel[2]->getName() ||
		reel[0]->getName() == reel[2]->getName())
	{
		return true;
	}
	return false;
}

/*
A method that determines if any two symbols have the same screen areas
@return true if the screen areas of any two symbols are the same; 
false if otherwise
*/
bool SlotMachine::two_equal_screen_areas()
{
	if (reel[0]->screenArea() == reel[1]->screenArea()
		|| reel[1]->screenArea() == reel[2]->screenArea() ||
		reel[0]->screenArea() == reel[2]->screenArea())
	{
		return true;
	}
	return false;
}

/*
A method that determines if all the three symbols are similar in shape
@return true if all the three are similar; false if they are not similar
*/
bool SlotMachine::three_similar_shapes()
{
	if (reel[0]->getName() == reel[1]->getName() && 
		reel[1]->getName() == reel[2]->getName())
	{
		return true;
	}
	return false;
}

/*
A method that determines if the screen area of the middle symbol
exceeds the sum of screen areas of the left and right symbols
@return true if this is the case; false if otherwise
*/
bool SlotMachine::middle_exceeds_sum_of_left_and_right()
{
	if (reel[1]->screenArea() > (reel[0]->screenArea() + reel[2]->screenArea()))
	{
		return true;
	}
	return false;
}

/*
A method that determines if the left and right symbols are similar in shape
@return true if they are similar; false if they are not similar
*/
bool SlotMachine::left_and_right_similar()
{
	if (reel[0]->getName() == reel[2]->getName())
	{
		return true;
	}
	return false;
}