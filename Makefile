###
### @file - Makefile
### @author - Kevin hillkev <hillkev@oregonstate.edu>
### @description - Makefile for Project 1, compiles files that have been changed
### with command 'make' and cleans object files with command 'make clean'.

#
# Valgrind Options
#
VOPT = --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes

project1: main.o inputValidateMenu.o menu.o Ant.o
	g++ main.o inputValidateMenu.o menu.o Ant.o -o project1

main.o: main.cpp
	g++ -c main.cpp

inputValidateMenu.o: inputValidateMenu.cpp inputValidateMenu.hpp
	g++ -c inputValidateMenu.cpp

menu.o: menu.cpp menu.hpp
	g++ -c menu.cpp

Ant.o: Ant.cpp Ant.hpp
	g++ -c Ant.cpp

zip:
	zip Project1_Hill_Kevin.zip Ant.cpp menuDisplay.cpp menu.cpp inputValidateMenu.cpp Ant.hpp menuDisplay.hpp menu.hpp inputValidateMenu.hpp main.cpp Makefile

valgrind:
	valgrind $(VOPT) ./project1

clean:
	rm -rf *o ./project1
