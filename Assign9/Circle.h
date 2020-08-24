#ifndef CIRCLE_H
#define CIRCLE_H

#include <string>
#include "Shape.h"
/**
 *
 * Circle.h
 *
 * Author:    Andy Olivares
 * z-ID:      z1860934
 * Date:      5/1/2019
 * 
 * Contains the declaration for the Circle class.
 */

class Circle : public Shape
   {
   private:
		//holds radius value
		int radius;
   
   public:
		Circle(const std::string&, int);		//constructor
		virtual void print();					//print method (override)
		virtual double getArea();				//getArea (override)

   };

#endif
