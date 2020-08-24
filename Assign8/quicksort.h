#ifndef QUICKSORT_H
#define QUICKSORT_H

/**
 *
 * quicksort.h
 *
 * Author:    Andy Olivares
 * z-ID:      z1860934
 * Date:      4/25/2019
 * 
 * Contains quicksort methods and functions for assign8.cpp
 */

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <cstddef>
#include <vector>
#include <iomanip>

using std::ostream;
using namespace std;


 //partition

/***************************************************************
Calls partition
Use: This function selects a pivot element and then partitions the vector around the pivot
Parameters: 1.vector<T>& set: vector to be partitioned
* 			2.int start: lowest value
* 			3.int end: highest value
* 			4. bool (*compare)(const T& const T&): function pointer to compare betwee start and end
Returns: pivotIndex
***************************************************************/
template <class T>
int partition(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&)){

   int pivotIndex, mid;
   T pivotValue;
   
   mid = (start + end) / 2;
   
   //Swap elements start and mid of the vector
   swap (set[start], set[mid]);

   pivotIndex = start;
   pivotValue = set[start];
 
	 for (int scan = start + 1; scan <= end; scan++){
			if (compare(set[scan], pivotValue)){
				++pivotIndex;
				//Swap elements pivotIndex and scan of the vector
				swap (set[pivotIndex], set[scan]);
		   }
	}
	//Swap elements start and pivotIndex of the vector
	swap(set[start], set[pivotIndex]);

	return pivotIndex; 
}

 //quicksort

/***************************************************************
Calls quicksort
Use: This function performs the recursive calls to implement the quick sort algorithm
Parameters: 1.vector<T>& set: vector to be partitioned
* 			2.int start: lowest value
* 			3.int end: highest value
* 			4. bool (*compare)(const T& const T&): function pointer to compare betwee start and end
Returns: nothing
***************************************************************/
template <class T>
void quickSort(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&)){

	int pivotPoint;

	if (start < end)
     {
      pivotPoint = partition(set, start, end, compare);     // Get the pivot point
      quickSort(set, start, pivotPoint - 1, compare);       // Sort first sublist
      quickSort(set, pivotPoint + 1, end, compare);         // Sort second sublist
     }

}


// quicksort

/***************************************************************
Calls quicksort
Use: calls quicksort
Parameters: 1.vector<T>& set: vector to be partitioned
* 			2.int start: lowest value
* 			3.int end: highest value
* 			4. bool (*compare)(const T& const T&): function pointer to compare betwee start and end
Returns: nothing
***************************************************************/
template <class T>
void quickSort(vector<T>& set, bool (*compare)(const T&, const T&)){
	quickSort(set, 0, set.size()-1, compare);
	
}







#endif
