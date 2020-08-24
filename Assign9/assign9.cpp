/**
 *
 * CSCI 241 Assignment 9
 *
 * Author: Andy Olivares
 * z-ID: z1860934
 * Date: 5/1/2019
 *
 * This program tests the functionality of the shape class.
 */  

#include <iostream>
#include <vector>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

using std::cout;
using std::endl;
using namespace std;

int main(){


   //Create vector shape
   vector <Shape *> shape;

   //Initialize vector with Shapes
   shape.push_back(new Circle("green", 10));
   shape.push_back(new Rectangle("red", 8, 6));
   shape.push_back(new Triangle("yellow", 8, 4));
   shape.push_back(new Triangle("black", 4, 10));
   shape.push_back(new Circle("orange", 5));
   shape.push_back(new Rectangle("blue", 3, 7));
   
	//for loop to get output from shape vector
	for(size_t i = 0; i<=shape.size()-1; i++){
		shape[i]->print();
	}
	
	
	cout << "Printing only circles..." << endl;
	

	//prints only circles
   for (unsigned int i = 0; i < shape.size(); i++){
		Circle *circlePtr = dynamic_cast<Circle *> (shape[i]);
		//checks if pointer is 0
		if (circlePtr != 0){
			circlePtr->print();
		}
	}
  

return 0;
}
