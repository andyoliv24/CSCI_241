#ifndef QUEUE_H
#define QUEUE_H

/**
 *
 * Queue.h
 *
 * Author:    Andy Olivares
 * z-ID:      z1860934
 * Date:      4/18/2019
 * 
 * Contains the declaration for the Queue class.
 */
 
#include <iostream>
#include <stdexcept>
#include <cstddef>

using std::ostream;
using namespace std;
 
 
template <class T>
class Queue;

template <class T>
std::ostream& operator<<(std::ostream&, const Queue<T>&);

template <class T>	//node struct
struct Node
   {
   T data;
   Node<T>* next;

   Node(const T& = T(), Node<T>* next = nullptr);
   };
 
 
template <class T>
Node<T>::Node(const T& data, Node* next)
   {
   this->data = data;	//data
   this->next = next;	// points to the next node in the linked list 
   }
   
   
template <class T>
class Queue{
	friend ostream& operator<< <>(std::ostream&, const Queue<T>&);	//overloading << operator stand alone function
	
	private:
	T* qArray;								//variable to hold data
	Node<T>* qFront;						//holds front value of array
	Node<T>* qBack;							//holds back value of array
	size_t qSize;							//keeps track of size array
	
	public:
	Queue();								//constructor
	~Queue();								//destructor
	Queue(const Queue<T>&);					//copy constructor
	Queue& operator=(const Queue<T>&);		//copy assignment operator
	size_t size()const;						//size method
	void clear();							//clear method
	bool empty()const;						//empty method
	const T& front()const;					//front method
	const T& back()const;					//back method
	void push(const T&);					//push method
	void pop();								//pop method
	void copyList(const Queue<T>&);			//copy list method
	
	
};



 //Default Constructor

/***************************************************************
Calls Queue default constructor
Use: sets qFront to nullptr, qback to nullptr and qSize to a 0.
Parameters: none
Returns: nothing
***************************************************************/

template<class T>
Queue<T>::Queue(){
	qFront= nullptr;
	qBack = nullptr;
	qSize = 0;
}


 //Destructor

/***************************************************************
Calls Queue destructor
Use: calls clear
Parameters: none
Returns: nothing
***************************************************************/
template<class T>
Queue<T>::~Queue(){
	clear();
}


 //Copy constructor

/***************************************************************
Calls copy constructor
Use: sets qFront and qBack to nullptr, qSize to 0;
Parameters: 1.const Queue<T> other: used to store an array
Returns: nothing
***************************************************************/
template<class T>
Queue<T>::Queue(const Queue<T>& other){   
   
   // Set the new Queue object to empty
   qFront = qBack = nullptr;
   qSize = 0;

   // Copy the other Queue's linked list
   copyList(other);
}


 //copy assigment operator

/***************************************************************
Calls operator =
Use: calls clear and copylist to assignment an array to another array
Parameters: 1.const Queue<T>& other: used to assign values
Returns: *this
***************************************************************/
template<class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other){
   if (this != &other)
      {
      // Make the left Queue object empty
      clear();

      // Copy the other Queue's linked list
      copyList(other);
      }

   return *this;
}



 //clear

/***************************************************************
Calls clear method
Use: sets qFront to nullptr, qback to nullptr and qSize to a 0.
Parameters: none
Returns: nothing
***************************************************************/
template<class T>
void Queue<T>::clear(){
	qSize= 0;
	qFront = nullptr;
	qBack = nullptr;
}


 //size

/***************************************************************
Calls size method
Use: returns qSize
Parameters: none
Returns: qSize
***************************************************************/
template<class T>
size_t Queue<T>::size()const{
	return qSize;
}

 //empty

/***************************************************************
Calls empty
Use: returns false or true
Parameters: none
Returns: bool
***************************************************************/
template<class T>
bool Queue<T>::empty()const{
	return(qSize==0);
}


 //back

/***************************************************************
Calls back
Use: Returns rear item of the queue.
Parameters: none
Returns: a Queue T object
***************************************************************/
template<class T>
const T& Queue<T>::back()const{
	//checks for underflow
	if(qSize == 0)
		throw underflow_error("Queue underflow on back()");
	return qBack->data;
}



//front

/***************************************************************
Calls front
Use: Returns front item of the queue.
Parameters: none
Returns: a Queue T object
***************************************************************/
template<class T>
const T& Queue<T>::front()const{
	//checks for underflow
	if(qSize == 0)
		throw underflow_error("Queue underflow on front()");
	return qFront->data;
}



// push 
/***************************************************************
Calls push
Use: Insert new item at rear of queue.
Parameters: 1. const T& val: used to be pushed into rear of queue
Returns: nothing
***************************************************************/
template<class T>
void Queue<T>::push(const T& val){

   Node<T>* newNode = new Node<T>(val);
	//checks if qArray is empty
   if (qSize == 0)
      qFront = newNode;
   else
      qBack->next = newNode;

   qBack = newNode;
   ++qSize;
}


// pop 
/***************************************************************
Calls pop
Use: Removes front item from queue.
Parameters: none
Returns: nothing
***************************************************************/
template<class T>
void Queue<T>::pop(){
	if(qSize == 0)
		throw underflow_error("Queue underflow on pop()");
	// Remove first node in list
	Node<T>* delNode = qFront;
	qFront = qFront->next;

	// If queue is now empty, make sure both pointers are nullptr
	if (qFront == nullptr)
	   qBack = nullptr;

	delete delNode;
	--qSize;
}


// copy List 
/***************************************************************
Calls copy list
Use: Copies the linked list from other to this object.
Parameters: 1. const Queue<T> other: used to be copied into another array
Returns: nothing
***************************************************************/
template <class T>
void Queue<T>::copyList(const Queue<T>& other){
   Node<T>* ptr;

   for (ptr = other.qFront; ptr != nullptr; ptr = ptr->next)
      push(ptr->data);
}


// operator <<
/***************************************************************
stand alone function operator <<
Use: overloaded to print T arrays
Parameters: 1. ostream& lhs, 2. const Queue<T>& rhs: both used to print an array of T
Returns: lhs
***************************************************************/

template <class T>
ostream& operator<<(std::ostream& lhs, const Queue<T>& rhs){
	
	Node<T>* ptr;

	for (ptr = rhs.qFront; ptr != nullptr; ptr = ptr->next)
	   lhs << ptr->data << ' ';

	return lhs;
   }





#endif
