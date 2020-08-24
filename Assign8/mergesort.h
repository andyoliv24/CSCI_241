#ifndef MERGESORT_H
#define MERGESORT_H


/**
 *
 * quicksort.h
 *
 * Author:    Andy Olivares
 * z-ID:      z1860934
 * Date:      4/25/2019
 * 
 * Contains mergesort methods and functions for assign8.cpp
 */

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <cstddef>
#include <vector>
#include <iomanip>

using std::ostream;
using namespace std;



 //merge

/***************************************************************
Calls partition
Use: This function merges two sorted subvectors.
Parameters: 1.vector<T>& set: vector to be partitioned
* 			2.int start: lowest value
* 			3.int end: highest value
* 			4. bool (*compare)(const T& const T&): function pointer to compare betwee start and end
Returns: nothing
***************************************************************/
template <class T>
void merge(vector<T>& set, int start, int mid, int end, bool (*compare)(const T&, const T&)){


   // Create temporary vector to hold merged subvectors
   vector<T> temp(end - start + 1);

   int i = start;    // Subscript for start of left sorted subvector
   int j = mid + 1;  // Subscript for start of right sorted subvector
   int k = 0;        // Subscript for start of merged vector

   // While not at the end of either subvector
   while (i <= mid && j <= end){
      if (compare(set[i], set[j])){
         temp[k] = set[i];			//Copy element i of set into element k of temp
         i= i+1;					//Add one to i
         k= k+1;					//Add one to k
      }
      else{
         temp[k]=set[j];			//Copy element j of set into element k of temp
         j=j+1;						//Add one to j 
         k = k+1;					//Add one to k
      }
   }

   // Copy over any remaining elements of left subvector
	while (i <= mid){
      temp[k]=set[i];				//Copy element i of set into element k of temp
      i = i+1;						//Add one to i
      k = k+1;						//Add one to k 
	}

   // Copy over any remaining elements of right subvector
	while (j <= end){
		temp[k]=set[j];// Copy element j of set into element k of temp
		j= j+1;//Add one to j 
		k = k+1;//Add one to k
    }

   // Copy merged elements back into original vector
	for (i = 0, j = start; j <= end; ++i, ++j){
		set[j]=temp[i];//Copy element i of temp into element j of set
	}
}



 //mergeSort

/***************************************************************
Calls partition
Use: This recursive function divides a vector into two subvectors, sorts them, and then merges the two sorted subvectors.
Parameters: 1.vector<T>& set: vector to be partitioned
* 			2.int start: lowest value
* 			3.int end: highest value
* 			4. bool (*compare)(const T& const T&): function pointer to compare betwee start and end
Returns: nothing
***************************************************************/
template <class T>
void mergeSort(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&)){

	int mid;
   
	if (start < end){
      mid = (start + end) / 2;
      
      // Divide and conquer
      
      mergeSort(set, start, mid, compare);
      mergeSort(set, mid+1, end, compare);
      
      // Combine
      merge(set, start, mid, end, compare);
	}

}


 //mergeSort

/***************************************************************
Calls mergeSort
Use: calls mergeSort
Parameters: 1.vector<T>& set: vector to be partitioned
* 			2.int start: lowest value
* 			3.int end: highest value
* 			4. bool (*compare)(const T& const T&): function pointer to compare betwee start and end
Returns: nothing
***************************************************************/
template <class T>
void mergeSort(vector<T>& set, bool (*compare)(const T&, const T&)){
	mergeSort(set, 0, set.size()-1, compare);
}





#endif
