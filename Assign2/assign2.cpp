/***********************************************************
CSCI 241 - Assignment 2 - Spring 2019

Progammer: Andy Olivares
Z-ID: z1860934
Date Due: 2/21/2019

Purpose: Main function, to run and show all the sellers and their total of sales
************************************************************/ 


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iomanip>
#include "SellerList.h"

using std::cerr;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

/***************************************************************
executes all the logic from the other files developed (seller.h, seller.cpp, sellerList.cpp, sellerList.h)
Use: will show names and total of sales
Parameters: none
Returns: 0
***************************************************************/
int main()
   {
	SellerList sellerList1("sellerData");
	sellerList1.print();
	sellerList1.processSalesData("sales.txt");
	sellerList1.print();

   return 0;
   }
