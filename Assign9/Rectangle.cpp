/***********************************************************
CSCI 241 - Assignment 9 - Spring 2019

Progammer: Andy Olivares
Z-ID: z1860934
Date Due: 5/1/2019
contains the declaration of the rectangle.h
************************************************************/

#include <iostream>
#include <string>
#include <cmath>
#include "Rectangle.h"

using namespace std;


//constructor

/***************************************************************
Calls rectangle constructor
Use: sets color, height, width
Parameters: 1. const string& color: used for color
* 			2. int height: used for heigth
* 			3. int width: used for width
Returns: nothing
***************************************************************/
Rectangle::Rectangle(const string& color, int height, int width) : Shape(color){
	this->height = height;
	this->width = width;
}

//getArea

/***************************************************************
Calls getArea
Use: calculates the area of the rectangle
Parameters: none
Returns: area(double)
***************************************************************/
double Rectangle::getArea(){
   double area = height * width;
   return area;
}

//print

/***************************************************************
Calls prints method
Use: prints rectangles color, height, width, area
Parameters: none
Returns: nothing
***************************************************************/
void Rectangle::print(){
	Shape::print();
	cout << " Rectangle, height " << height << "," << " width " << width << " area " << getArea() << endl;
}
