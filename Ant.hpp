
/******************************************************************************
** Program name: Project1
** Author: Kevin Hill
** Date:  04/12/2019
** Description: Class Specification file for Ant. Declares functions,
**    constructors and variables.
******************************************************************************/

#ifndef ANT_HPP
#define ANT_HPP

//Defines the interface of the Ant Class.
class Ant
{
private:
  //Declare private variables for ant
  int state;
  int orient;
  int ANTUP;
  int ANTRIGHT;
  int ANTDOWN;
  int ANTLEFT;
  int loc_option;
  int steps;
  int col_max;
  int row_max;
  int ant_x;
  int ant_y;
  //Declare dynamic board array.
  char **board;
  //Member functions
  void requestInputs();
  void startAnt();
  void moveAnt();
  void checkPath();
  void antRight();
  void antLeft();
  //Mutators
  void setAntY(int y);
  void setAntX(int x);
public:
  //Constructors.
  Ant();
  //Destructor
  ~Ant();
  //Member functions.
  void printBoard();
  //Accessors/Mutators
  int getAntX();
  int getAntY();


};
#endif
