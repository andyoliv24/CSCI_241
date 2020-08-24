/***********************************************************
CSCI 241 - Assignment 9 - Spring 2019

Progammer: Andy Olivares
Z-ID: z1860934
Date Due: 5/1/2019
contains the declaration of the shape.h
************************************************************/




#include <iostream>
#include <string>
#include "Shape.h"




//shape constructor

/***************************************************************
Calls shape constructor
Use: calls shape constructor
Parameters: 1. Const String& color used to be set for color member
Returns: nothing
***************************************************************/
Shape::Shape(const std::string& color):color(color){
}


//print

/***************************************************************
Calls prints method
Use: prints color
Parameters: none
Returns: nothing
***************************************************************/
void Shape::print(){
	std::cout << color;
}

