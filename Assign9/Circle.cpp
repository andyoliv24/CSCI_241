/***********************************************************
CSCI 241 - Assignment 9 - Spring 2019

Progammer: Andy Olivares
Z-ID: z1860934
Date Due: 5/1/2019
contains the declaration of the Circle.h
************************************************************/


#include <iostream>
#include <string>
#include <cmath>
#include "Circle.h"

using namespace std;



//constructor

/***************************************************************
Calls circles constructor
Use: sets color, and radius
Parameters: 1. const string& color: used for color
* 			2. int radiusNum: used for radius
Returns: nothing
***************************************************************/
Circle::Circle(const string& color, int radiusNum) : Shape(color){
	radius = radiusNum;
}



//getArea

/***************************************************************
Calls getArea
Use: calculates the area of the circle
Parameters: none
Returns: area(double)
***************************************************************/
double Circle::getArea(){
   double area = (M_PI * pow(radius, 2));
   return area;
}


//print

/***************************************************************
Calls prints method
Use: prints circle's radius, area and color
Parameters: none
Returns: nothing
***************************************************************/
void Circle::print(){
	Shape::print();
	cout << " Circle, Radius " << radius << ", " << "area " << getArea() << endl;
}


