/***********************************************************
CSCI 241 - Assignment 2 - Spring 2019

Progammer: Andy Olivares
Z-ID: z1860934
Date Due: 2/21/2019

Purpose: Develop functions for the seller class.
************************************************************/ 



#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iomanip>
#include "Seller.h"

using std::cerr;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;


// Seller constructors

/***************************************************************
Calls Seller default constructor
Use: sets "" for name and 0 for sales_total if nothing is passed
Parameters: none
Returns: nothing
***************************************************************/

Seller::Seller(){	
	strcpy(name, "");
	sales_total = 0;
	}
	
	
/***************************************************************
Calls Seller constructor with parameters
Use: sets name with newName value and sets sales_total with newSalestotal value
Parameters:  1. newName: holds value for name
		     2. newSalesTotal:  holds value for sales_total
Returns: nothing
***************************************************************/
	
Seller::Seller(const char* newName, double newSalesTotal){
	strcpy(name, newName);
	sales_total = newSalesTotal;
	
	}

/***************************************************************
calls getter for name
Use: it is used to return the name of the seller
Parameters: none
Returns: char (name)
***************************************************************/

const char* Seller::getName() const{
	return name;
	}


/***************************************************************
calls getter for sales_total
Use: it is used to return the total of sales of the seller
Parameters: none
Returns: double(sales_total)
***************************************************************/

double Seller::getSalesTotal() const{
	return sales_total;
	}


/***************************************************************
Calls setter
Use: it is used to set a value for sales total
Parameters: 1. newSalesTotal: has the new value for sales_total
Returns: nothing
***************************************************************/
	
void Seller::setSalesTotal(double newSalesTotal){
	sales_total = newSalesTotal;
	}
	
	
	
/***************************************************************
Calls Print method
Use: prints the value of name and sales total in a line
Parameters: none
Returns: nothing
***************************************************************/
	
void Seller::print() const{
	   cout << std::setw(30)<< name << std::setw(9) << sales_total << endl;
	
	}	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
