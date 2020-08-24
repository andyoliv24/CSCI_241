/***********************************************************
CSCI 241 - Assignment 2 - Spring 2019

Progammer: Andy Olivares
Z-ID: z1860934
Date Due: 2/21/2019

Purpose: Develop functions for the sellerList class.
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
Calls SellerList default constructor
Use: sets number of sellers to 0 if nothing is passed.
Parameters: none
Returns: nothing
***************************************************************/

SellerList::SellerList(){
	numberOfSellers = 0;
	}
	
/***************************************************************
Calls SellerList constructor with a file passed in.
Use: to fill in the Seller Lists objects with information (name, and total of sales)
Parameters: 1. FileName: used to get information
Returns: nothing
***************************************************************/
	
SellerList::SellerList(const string& fileName){
	ifstream inFile;								//declares a stream variable
	inFile.open (fileName);							//opens file
	inFile.read((char*) this, sizeof(SellerList));	//reads file
	inFile.close();									//closes file
	sortSellers();									
	}
	
	
/***************************************************************
Calls print method
Use: prints out names and total of sales.
Parameters: none
Returns: nothing
***************************************************************/
	
void SellerList::print() const{
	
	cout << std::setw(37) << "Seller Listing" << endl;
	cout << std::setw(30) << "Name" << std::setw(9) << "Sales" << endl;
	for (int i=0; i<numberOfSellers; i++){			//loops thru the sellerListArray
			SellerListArray[i].print();	
			cout << endl;
	}
	
	}



/***************************************************************
Calls sort method
Use: sorts the name of sellers
Parameters: none
Returns: nothing
***************************************************************/

void SellerList::sortSellers(){
   int i, j;
   Seller temp;

   for (i = 1; i < numberOfSellers; i++){
      temp = SellerListArray[i];

      for (j = i; (j > 0) && (strcmp(SellerListArray[j-1].getName(), temp.getName()) > 0); j--){	//swaps positions.
         SellerListArray[j] = SellerListArray[j-1];
      }

      SellerListArray[j] = temp;

	}
}


/***************************************************************
Calls searchForSeller 
Use: prints out names and total of sales.
Parameters: 1. searchName: it is used to compare to seller's name.
Returns: -1 if sellers is not found
***************************************************************/

int SellerList::searchForSeller(const char* searchName) const{
   int low = 0;
   int high = numberOfSellers - 1;
   int mid;

   while (low <= high)
      {
		  mid = (low + high) / 2;

		  if (strcmp(searchName,SellerListArray[mid].getName()) == 0)   //evaluates for equality bewteen the string passed and sellers name.
			 return mid;
		  
		  if (strcmp(searchName,SellerListArray[mid].getName()) < 0)	//evaluates if the string pass is less than the name.
			 high = mid - 1;
		  
		  else
			 low = mid + 1;
		  	
      }

		 return -1;
	
	}
	
	
/***************************************************************
Calls print process sales data
Use: prints out names and total of sales.
Parameters: 1. fileName: to get the file which contains all the sellers information.
Returns: nothing
***************************************************************/
	
void SellerList::processSalesData(const string& fileName){
   ifstream inFile;
   char lastName[21];
   char firstName[11];
   double salesAmount;
   char name[31];

      // Open the input file and test for failure
   inFile.open(fileName);
	  if (!inFile)				//if there is no file, an error will be thrown
      {
      cerr << "Error - unable to open input file " << fileName << endl;
      exit(1);
      }
	  
	  inFile >> lastName;
	  cout << std::setw(37) << "Sales Transactions" << endl;
   while (inFile)						//while there is information
      {
      inFile>>firstName;				
      inFile>>salesAmount;				

      strcpy(name, lastName);			//concatenates lastname with firstname.
      strcat(name, ", ");
      strcat(name, firstName);
      
      int index = searchForSeller(name);		
      if (index == -1){						//if index is -1 it didnt' find the seller
         cout << std::setw(30) << "There was an error " << name << " does not exist "<< endl;
	 }
      else
         {
		 cout << endl;
		 cout << std::setw(30)<< name << " sold: " << salesAmount << endl;
         SellerListArray[index].setSalesTotal(SellerListArray[index].getSalesTotal() + salesAmount);    //adds salesAmout to total Sales of the seller.
         }
            
      inFile>>lastName;
      }   

   inFile.close();
	}
	
