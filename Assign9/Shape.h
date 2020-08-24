#ifndef SHAPE_H
#define SHAPE_H

#include <string>

/**
 *
 * Shape.h
 *
 * Author:    Andy Olivares
 * z-ID:      z1860934
 * Date:      5/1/2019
 * 
 * Contains the methods for the Shape class.
 */

class Shape
   {
   private:
		//holds color of shape
		std::string color;
   
   public:
		Shape(const std::string&);		//constructor
		virtual ~Shape() {};			//virtual destructor
		virtual void print()  = 0;		//virtual print method
		virtual double getArea() = 0;	//pure virtual getArea method

   };

#endif

