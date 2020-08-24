#ifndef SELLER_H
#define SELLER_H

/**
 *
 * Seller.h
 *
 * Author:    Andy Olivares
 * z-ID:      z1860934
 * Date:      2/21/2019
 * 
 * Contains the declaration for the Seller class.
 */

class Seller
   {
   private:
   
   // Data members for the Seller class go here
   char name[31]; 									//array for names
   double sales_total;								// counter of person objects
   
   public:

   // Method prototypes for the Seller class

   Seller();						//default prototype
   Seller(const char*, double);		//seller prototype (with arguments)

   const char* getName() const;		// getName prototype
   double getSalesTotal() const;	// getSalesTotal prototype
   void setSalesTotal(double);		// setSalesTotal prototype
   void print() const;				// print prototype
   };

#endif






