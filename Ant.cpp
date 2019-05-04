/******************************************************************************
** Program name: Project1
** Author: Kevin Hill
** Date:  04/12/2019
** Description: Implementation file for Ant class. Sets and gets Ant
** objects. Has functions that return the number ant location. Moves ant
** according to Langston's ant rules. Has functions that request input, prints
** board, moves ant, checks path, turns ant and deallocates array.
******************************************************************************/

#include "Ant.hpp"
#include "inputValidateMenu.hpp"
#include <iostream>
#include <cstdlib>//For random numbers.
#include <iomanip>//For better-spaced printing layout.


//Default Constructor.
Ant::Ant()
{
  //set all user entered variables to zero.
  //set ant position to zero and orientation to up
  state = 0;
  steps = 0;
  ANTUP = 0;
  ANTRIGHT = 1;
  ANTDOWN = 2;
  ANTLEFT = 3;
  orient = ANTUP;
  ant_x = 0;
  ant_y = 0;

  //Call for user inputs in order to build array
  requestInputs();
  //Initialize dynamically allocated 2d array of board
  board = new char*[col_max];
	for (int x=0; x<col_max; x++)
	{
		board[x] = new char[row_max];
  }

  //fill board with white spaces
  for (int i=0; i<col_max; i++)
  {
    for (int j=0; j<row_max; j++)
    {
      board[i][j] = ' ';
    }
  }

  //Initialize the ant location on the board
  board[getAntY()][getAntX()] = '*';
  startAnt();
}

//Destructor, deallocates array
Ant::~Ant()
{
for (int q=0; q<col_max; q++)
	{
		delete[] board[q];
	}
	delete[] board;
}


/************************************************
*             requestInputs                     *
*This function asks the user to initialize the  *
*parameters of the class. These include, board  *
*dimensions, ant location, steps. Function also *
*validates input so nothing is out of bounds.   *
************************************************/
void Ant::requestInputs()
{
  //set option for ant location to 0.
  loc_option = 0;
  std::cout<<"Enter a number for the size of the board in the x direction (minumum 2):"<<std::endl;
  col_max = inputValidateMenu(2);
  std::cout<<"Enter a number for the size of the board in the y direction (minimum 2):"<<std::endl;
  row_max = inputValidateMenu(2);
  std::cout<<"Enter a number for the amount of steps the ant takes (minumum 1):"<<std::endl;
  steps = inputValidateMenu(1);
  std::cout<<"Choose where to place the Ant. Choose either random or specific."<<std::endl;
  std::cout<<"1. Specified position within range of board."<<std::endl;
  std::cout<<"2. Random location."<<std::endl;
  loc_option = inputValidateMenu(1,2);
  //Specify ant location
  if (loc_option == 1)
  {
    std::cout<<"Choose x position for Ant within bounds of board. From 0 to "<<col_max-1<<"."<<std::endl;
    ant_x = inputValidateMenu(0,col_max-1);
    std::cout<<"Choose y position for Ant within bounds of board. From 0 to "<<row_max-1<<"."<<std::endl;
    ant_y = inputValidateMenu(0,row_max-1);
  }
  //If random selected then random position will be used for the ant within bounds.
  else
  {
    srand(time(0));
    setAntX(rand()%col_max);
  	setAntY(rand()%row_max);
  }
}

/************************************************ *
*             setAntX                             *
*Set an integer as x location on the grid for ant *
**************************************************/
void Ant::setAntX(int x)
{
  ant_x=x;
}

/************************************************ *
*             setAntY                             *
*Set an integer as y location on the grid for ant *
**************************************************/
void Ant::setAntY(int y)
{
  ant_y=y;
}

//Accessor functions.

/************************************************
*             getAntX                           *
*Returns ant's x location on the grid           *
************************************************/
int Ant::getAntX()
{
  return ant_x;
}

/************************************************
*             getAntY                           *
*Returns ant's y location on the grid           *
************************************************/
int Ant::getAntY()
{
  return ant_y;
}

/************************************************
*             printBoard                        *
*This function prints the current grid.         *
************************************************/
void Ant::printBoard()
{
  for (int i=0; i<col_max; i++)
  {
    for (int j=0; j<row_max; j++)
    {
      std::cout<<board[i][j];
      std::cout<<std::setw(3);
    }
    std::cout<<"\n"<<std::endl;
  }
}

/************************************************
*             moveAnt                           *
*This function moves the ant based on if it is  *
*the first time running the loop. It also calls *
*turn right or left based on the state of cell  *
*the ant is looking at (direction).             *
************************************************/
void Ant::moveAnt()
{
  //move ant up initially, unless edge case
  if (steps == 0 && getAntY()-1>=0){
    board[getAntY()][getAntX()] = '#';
    board[getAntY()-1][getAntX()] = '*';
    setAntY(getAntY()-1);
  }
  else{
    if (state == 0){
      board[getAntY()][getAntX()] = '#';
      antRight();
    }
    else if (state == 1){
      board[getAntY()][getAntX()] = ' ';
      antLeft();
    }
  }
}

/************************************************
*             antRight                          *
*This function changes the direction of the ant *
*to the right. Then checkPath is called to      *
*determine if movement is valid or there are    *
*edge cases.                                    *
************************************************/
void Ant::antRight(){
  if (orient == ANTLEFT){
    orient = ANTUP;
  }
  else{
    orient = orient + 1;
  }
  checkPath();
}

/************************************************
*             antLeft                           *
*This function changes the direction of the ant *
*to the left. Then checkPath is called to       *
*determine if movement is valid or there are    *
*edge cases.                                    *
************************************************/
void Ant::antLeft(){
  if (orient == ANTUP){
    orient = ANTLEFT;
  }
  else{
    orient = orient - 1;
  }
  checkPath();
}

/************************************************
*             checkPath                         *
*This function looks for edge cases based on the*
*the orientation of the ant. If so the ant turns*
*right. No edge case then the ant moves forward *
*The cell it leaves changed from black to white *
*or vice versa.
************************************************/
void Ant::checkPath(){
    if (orient == ANTUP){
      //If edge case turn right
      if (getAntY()-1<0){
        antRight();
        board[getAntY()][getAntX()]='*';//reset ant to current location.
      }
      else{
        //set state based on cell in front of ant.
        if (board[getAntY()-1][getAntX()]==' '){
          state = 0;
        }
        else{
          state = 1;
        }
        board[getAntY()-1][getAntX()]='*';//move ant
        setAntY(getAntY()-1);
      }
    }
    else if (orient == ANTRIGHT){
      if (getAntX()+1>col_max-1){
        //If edge case turn right
        antRight();
        board[getAntY()][getAntX()]='*';//reset ant to current location.
      }
      else{
        //set state based on cell in front of ant.
        if (board[getAntY()][getAntX()+1]==' '){
          state = 0;
        }
        else{
          state = 1;
        }
        board[getAntY()][getAntX()+1]='*';//move ant
        setAntX(getAntX()+1);
      }
    }
    else if (orient == ANTDOWN){
      if (getAntY()+1>row_max-1){
        //If edge case turn right
        antRight();
        board[getAntY()][getAntX()]='*';//reset ant to current location.
      }
      else{
        //set state based on cell in front of ant.
        if (board[getAntY()+1][getAntX()]==' '){
          state = 0;
        }
        else{
          state = 1;
        }
        board[getAntY()+1][getAntX()]='*';//move ant
        setAntY(getAntY()+1);
      }
    }
    else if (orient == ANTLEFT){
      //If edge case turn right
      if (getAntX()-1<0){
        antRight();
        board[getAntY()][getAntX()]='*';//reset ant to current location.
      }
      else{
        //set state based on cell in front of ant.
        if (board[getAntY()][getAntX()-1]==' '){
          state = 0;
        }
        else{
          state = 1;
        }
        board[getAntY()][getAntX()-1]='*';//move ant
        setAntX(getAntX()-1);
      }
    }

}

/************************************************
*             startAnt                          *
*This function loops the print board function   *
*for the amount of specified steps and moves the*
*ant each loop.                                 *
************************************************/
void Ant::startAnt()
{
  printBoard();
  for (int i=0; i<steps; i++){
    moveAnt();
    printBoard();
  }

}
