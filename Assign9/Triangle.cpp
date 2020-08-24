/***********************************************************
CSCI 241 - Assignment 9 - Spring 2019

Progammer: Andy Olivares
Z-ID: z1860934
Date Due: 5/1/2019
contains the declaration of the triangle.h
************************************************************/

#include <iostream>
#include <string>
#include <cmath>
#include "Triangle.h"

using namespace std;


//constructor

/***************************************************************
Calls triangle constructor
Use: sets color, height, base
Parameters: 1. const string& color: used for color
* 			2. int height: used for heigth
* 			3. int base: used for base
Returns: nothing
***************************************************************/
Triangle::Triangle(const string& color, int height, int base) : Shape(color){
	this->height = height;
	this->base = base;
}



//getArea

/***************************************************************
Calls getArea
Use: calculates the area of the triangle
Parameters: none
Returns: area(double)
***************************************************************/
double Triangle::getArea(){
   double area = (base * height)/2;
   return area;
}



//print

/***************************************************************
Calls prints method
Use: prints triangles color, height, base, area
Parameters: none
Returns: nothing
***************************************************************/
void Triangle::print(){
	Shape::print();
	cout << " Triangle, height " << height << "," << " base " << base << " area " << getArea() << endl;
}
