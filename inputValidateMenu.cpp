/******************************************************************************
** Program name: Project1
** Author: Kevin Hill
** Date:  04/12/2019
** Description: This function outputs the choices for a given program
**              after the user selects a valid choice it is returned to main.
******************************************************************************/


#include "inputValidateMenu.hpp"
#include <iostream>
#include <sstream>


/************************************************
*             inputValidateMenu                 *
*This function takes in an integer lower and    *
*upper limit for menu options or otherwise.     *
*If an integer is                               *
*out of bounds an exception is thrown until the *
*user inputs a valid integer option, and is     *
*returned.                                      *
************************************************/
int inputValidateMenu(int lower_l, int upper_l)
{
  int choice_int;
  std::string choice_string;

  while(true) {

    std::getline(std::cin, choice_string); //get string input
    std::stringstream convert(choice_string); //turns the string into a stream

    //checks if is converted to integer and for minimum value and maximum value
    if(convert >> choice_int && !(convert >> choice_string) && choice_int >= lower_l && choice_int <= upper_l) {
      return choice_int;
    }
    else{
      std::cout <<"Please enter an integer that is given in the range of options!"<<" Try again.\n";

    }
    std::cin.clear(); //just in case an error occurs.
  }

}

/************************************************
*             inputValidateMenu                 *
*This overloaded function takes in an integer   *
*lower limit a range of values. If an integer is *
*out of bounds an exception is thrown until the *
*user inputs a valid integer option, and is     *
*returned.                                      *
************************************************/
int inputValidateMenu(int lower_l)
{
  int choice_int;
  std::string choice_string;

  while(true) {

    std::getline(std::cin, choice_string); //get string input
    std::stringstream convert(choice_string); //turns the string into a stream

    //checks if is converted to integer and for minimum value
    if(convert >> choice_int && !(convert >> choice_string) && choice_int >= lower_l) {
      return choice_int;
    }
    else{
      std::cout <<"Input must be greater than or equal to " << lower_l <<" and an integer"<< ". Try again.\n";

    }
    std::cin.clear(); //just in case an error occurs.
  }

}
