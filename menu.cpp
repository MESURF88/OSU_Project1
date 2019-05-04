/******************************************************************************
** Program name: Project1
** Author: Kevin Hill
** Date:  04/12/2019
** Description: This function outputs the choices for a given program
**              after the user selects a choice it is returned to main.
******************************************************************************/

#include "inputValidateMenu.hpp"
#include "menu.hpp"
#include <iostream>


/************************************************
*             menu                              *
*This function returns a menu choice selected   *
*from the prompts.                              *
************************************************/
int menu()
{
  //Initialize valid option variable to out of range.
  int valid_option=0;
  std::cout<<"Welcome to the menu. "<<"\n"<<std::endl;
  std::cout<<"1. Start Langston's Ant Simulation."<<"\n"<<std::endl;
  std::cout<<"2. Quit."<<"\n"<<std::endl;
  std::cout<<"Enter the following number to continue with the chosen option: "<<std::endl;

  valid_option = inputValidateMenu(1,2);

  //Checks option choice and reutrns value.
  switch(valid_option){
    case 1:
      return 1;
      break;
    case 2:
      return 0;
      break;
  }


}
