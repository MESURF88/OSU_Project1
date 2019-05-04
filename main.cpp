/******************************************************************************
** Program name: Project1
** Author: Kevin Hill
** Date:  04/12/2019
** Description: Main method file for Ant class. Used for looping menu call and
**  re-initializing ant private variables. It is repeated until user quits the
**  program. Outputs are printed to the console.
******************************************************************************/
#include "Ant.hpp"
#include "menu.hpp"
#include <ctime>
#include <iostream>


int main()
{
	int option_picked = 0;


	option_picked = menu();

	//Loop Ant class until user quits the menu.
	while (option_picked == 1)
	{
	  Ant automaton;
		option_picked = menu();
 }

	return 0;
}
