#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <string>
#include "Shape.h"
/**
 *
 * Triangle.h
 *
 * Author:    Andy Olivares
 * z-ID:      z1860934
 * Date:      5/1/2019
 * 
 * Contains the declaration for the Triangle class.
 */

class Triangle : public Shape
   {
   private:
		int height;		//holds height value
		int base;		//holds base value
   
   public:
		Triangle(const std::string&, int, int);		//Triangle constructor
		virtual void print();						//print method (override)
		virtual double getArea();					//getArea method (override)

   };

#endif
