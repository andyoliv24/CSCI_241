#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <string>
#include "Shape.h"
/**
 *
 * Rectangle.h
 *
 * Author:    Andy Olivares
 * z-ID:      z1860934
 * Date:      5/1/2019
 * 
 * Contains the declaration for the Rectangle class.
 */

class Rectangle : public Shape
   {
   private:
		int height;			//holds height value
		int width;			//holds width value
   
   public:
		Rectangle(const std::string&, int, int);	//rectangle constructor
		virtual void print();						//print method (override)
		virtual double getArea();					//getArea (override)

   };

#endif
