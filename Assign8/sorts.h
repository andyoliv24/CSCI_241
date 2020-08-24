#ifndef SORTS_H
#define SORTS_H

/**
 *
 * Sorts.h
 *
 * Author:    Andy Olivares
 * z-ID:      z1860934
 * Date:      4/25/2019
 * 
 * Contains sorts methods and functions for assign8.cpp
 */

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <cstddef>
#include <vector>
#include <iomanip>

using std::ostream;
using namespace std;



template <class T>
void buildList(vector<T>& set, const char* path){
	T item;				//this stores input from txt file
	ifstream inFile;	//creates a stream input
	
	//opens file
	inFile.open(path);
	
	//checks for errors while opening file
	if (!inFile){
      cerr << "Error - unable to open input file " << path << endl;
      exit(1);
    }
    
     inFile>>item;
    
    //stores input while there is input in txt file
    while(inFile){
		set.push_back(item);
		inFile>>item;
	}
	
	//closes file
	inFile.close();

}

 //printList

/***************************************************************
Calls printList
Use: stores input into vectors
Parameters: 1.const vector<T>& set: used to store input
* 			2.int itemWidth: set width
* 			3.int numPerLine: sets number of words/numbers per line
Returns: nothing
***************************************************************/
template <class T>
void printList(const vector<T>& set, int itemWidth, int numPerLine){
	int count = 0;
	
	for(size_t i=0; i<set.size(); i++){ 
    
		cout << setw(itemWidth) << set[i] ;
		count ++;
		if(count == numPerLine){
			cout << endl;
			count = 0;
		}
	}
}



 //lessThan

/***************************************************************
Calls lessThan
Use: returns the smallest vector
Parameters: 1.const T& item1: used to compare with item2
* 			2.const T& item2: used to compare with item1
Returns: true/false
***************************************************************/
template <class T>
bool lessThan(const T& item1, const T& item2){
	return (item1 < item2);
}



 //greatjerThan

/***************************************************************
Calls lessThan
Use: returns the greathest vector
Parameters: 1.const T& item1: used to compare with item2
* 			2.const T& item2: used to compare with item1
Returns: true/false
***************************************************************/
template <class T>
bool greaterThan(const T& item1, const T& item2){
	return (item1 > item2);
}


#endif
