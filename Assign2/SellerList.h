#ifndef SELLERLIST_H
#define SELLERLIST_H
#include <string>
#include "Seller.h"
using std::string;

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


class SellerList
   {
	   
	
   private:
   
   // Data members for the Seller class go here
	
	Seller SellerListArray[30];			// creates array objects of the Seller class.
	int numberOfSellers;				//counter for number of sellers.
   
   public:

   // Method prototypes for the Seller class
	
	SellerList();											//sellerList prototype
	SellerList(const string&);								//sellerList prototype with one argument
	void print() const;										//print prototype
	void sortSellers();										//sortSellers  prototype
	int searchForSeller(const char* searchName) const;		//searchForSeller prototype
	void processSalesData(const string& fileName);			//processSalesData prototype
	
   };

#endif










