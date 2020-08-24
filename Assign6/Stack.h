#ifndef STACK_H
#define STACK_H

/**
 *
 * Stack.h
 *
 * Author:    Andy Olivares
 * z-ID:      z1860934
 * Date:      4/11/2019
 * 
 * Contains Stack methods and functions for assign6.cpp
 */


#include <iostream>
#include <stdexcept>
#include <cstddef>
#include <iostream>

using std::ostream;

template <class T>
class Stack;

template <class T>
std::ostream& operator<<(std::ostream&, const Stack<T>&);

template <class T>
class Stack
{ 	
	//operator << overload
    friend ostream& operator<< <>(ostream&, const Stack<T>&);	

    private:
        T* stkArray;				// pointer to the T template
        size_t stkSize;				// holds the size
        size_t stkCapacity;			// holds the capacity

    public:
        Stack();									//constructor
        Stack(const Stack<T>& other);				//copy constructor
        ~Stack();									//destructor
        Stack& operator=(const Stack& other);		//copy assignment operator
        void clear();								//clear method
        size_t size() const;						//size method
        size_t capacity() const;					//capacity method
        bool empty() const;							//empty method
        const T& top() const;						//top method
        void push(const T&);						//push method
        void pop();									//pop method
        void reserve(size_t);						//reserve method
};


 //Default Constructor

/***************************************************************
Calls Stack default constructor
Use: sets stkSize to 0, stkCapacity to 0 and stkArray to a nullptr.
Parameters: none
Returns: nothing
***************************************************************/
template <class T>
Stack<T>::Stack(){
   stkSize = 0;
   stkCapacity = 0;
   stkArray = nullptr;
}


 //Destructor

/***************************************************************
Calls Stack destructor
Use: deletes stkArray.
Parameters: none
Returns: nothing
***************************************************************/
template <class T>
Stack<T>::~Stack(){
   delete[] stkArray;
}



//Copy Constructor

/***************************************************************
Calls Stack copy constructor
Use: copies a stack object to another.
Parameters: none
Returns: nothing
***************************************************************/
template <class T>
Stack<T>::Stack(const Stack<T>& other){
   stkCapacity = other.stkCapacity;
   stkSize = other.stkSize;

   if (stkCapacity == 0)
      stkArray = nullptr;
   else
      stkArray = new T[stkCapacity];
	//copies stkArray to other.stkArray
   for (size_t i = 0; i < stkSize; ++i)
      stkArray[i] = other.stkArray[i];
}


//Copy Assignment Operator

/***************************************************************
Calls Stack Copy Assignment Operator
Use: assigns a stack object to another
Parameters: none
Returns: nothing
***************************************************************/
template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other){
	/*checks if this and &other have the same address*/
	if(this != &other){
		delete[] stkArray;
		stkCapacity = other.stkCapacity;
		stkSize = other.stkSize;
		if(stkCapacity > 0)
			stkArray = new T[stkCapacity];
		else
			stkArray = nullptr;
		/*copies content of other to vArray*/
		for(size_t i =0; i<stkSize; i++){
			stkArray[i] = other.stkArray[i];
			}
		}
			
	return *this;
}



//Clear

/***************************************************************
Calls clear method
Use: sets stkSize to 0.
Parameters: none
Returns: nothing
***************************************************************/
template <class T>
void Stack<T>::clear(){
	stkSize = 0;
}
 

//size 

/***************************************************************
Calls size method
Use: returns stkSize.
Parameters: none
Returns: stkSize
***************************************************************/
template <class T>
size_t Stack<T>::size()const{
	return stkSize;
}



//Capacity

/***************************************************************
Calls capacity method
Use: returns stkCapacity.
Parameters: none
Returns: stkCapacity
***************************************************************/
template <class T>
size_t Stack<T>::capacity()const{
	return stkCapacity;
}


//empty

/***************************************************************
Calls empty method
Use: returns true if stkSize is 0 otherwise returns false
Parameters: none
Returns: false or true.
***************************************************************/
template <class T>
bool Stack<T>::empty()const{
	return(stkSize == 0);
}




//top

/***************************************************************
Calls top method
Use: returns the top element of stkArray
Parameters: none
Returns: stkArray
***************************************************************/
template <class T>
const T& Stack<T>::top() const{
   if (empty())
      throw std::underflow_error("Stack underflow on call to top()");

   return stkArray[stkSize - 1];
}



//push

/***************************************************************
Calls push method
Use: inserts a value into the stack
Parameters: 1. const T& val: value to be inserted into the stack
Returns: nothing
***************************************************************/
template <class T>
void Stack<T>::push(const T& val){
   // If stack is full, allocate additional storage
   if (stkSize == stkCapacity)
      {
      if (stkCapacity == 0)
         reserve(1);
      else
         reserve(stkCapacity * 2);
      }

   stkArray[stkSize] = val;
   ++stkSize;
}



//pop

/***************************************************************
Calls pop method
Use: decrements the stack size by 1
Parameters: none
Returns: nothing
***************************************************************/
template <class T>
void Stack<T>::pop(){
	--stkSize;
}



//reserve

/***************************************************************
Calls reserve method
Use: increases the size of the stack array.
Parameters: 1. size_t newCapacity: used to be the new capacity
Returns: nothing
***************************************************************/	
template <class T>
void Stack<T>::reserve(size_t newCapacity){
	//checks if newCapacity is less or equal to stkCapacity
	if(newCapacity <= stkCapacity)
	return;
	
	stkCapacity = newCapacity;
	T* tempArray = new T[newCapacity];
	
	if(stkCapacity == 0){
		tempArray = nullptr;
	}else{
		for(size_t i =0; i<stkSize; i++){
			tempArray[i] = stkArray[i];
		}
		stkCapacity = newCapacity;
		delete[] stkArray;
		stkArray = tempArray;
	}
}



// operator << overloading function

/***************************************************************
Use: overloads << operator to print stack objects
Parameters: 1. ostream& left: used as left side operand.
			2. const Stack <T>& rhs: used as right side operand
Returns: lhs
***************************************************************/
template <class T>
std::ostream& operator<<(std::ostream& lhs, const Stack<T>& rhs){
   for (size_t i = 0; i < rhs.stkSize; ++i)
      lhs << rhs.stkArray[i] << ' ';

   return lhs;
   }


#endif
