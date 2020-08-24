#ifndef VECTORN_H
#define VECTORN_H

/**
 *
 * vectorN.h
 *
 * Author:    Andy Olivares
 * z-ID:      z1860934
 * Date:      3/28/2019
 * 
 * Contains the declaration for the Seller class.
 */

#include <cstddef>
#include <iostream>
using std::ostream;


class VectorN
   {
	   
	 //Friend function prototypes for overloading operators
    friend ostream& operator<<(ostream&, const VectorN&);
   	friend VectorN operator*(const double&, const VectorN&);
   	
   	
	//private data members
   private:
    double* vArray; 			/*pointer to a double(vector array pointer)*/
	size_t vCapacity;			/* keep track of the number of elements in the vector array*/
   
   
   
   //public data members
   public:
	VectorN();									/*default vector constructor*/
	VectorN(const double values[], size_t n);	/*vector constructor with 2 args*/
	VectorN(const VectorN& other);				/*vector constructor with 1 arg*/
	~VectorN();									/*vector destructor*/
	VectorN& operator=(const VectorN& other);	/*operator = overloading*/
	void clear();								/*clear prototype method*/
	size_t size() const;						/*size prototype method*/
	VectorN operator+(const VectorN&)const;		/*operator + overloading*/
	VectorN operator-(const VectorN&)const;		/*operator - overloading*/
	double operator*(const VectorN&) const;		/*operator * overloading*/
    VectorN operator*(const double&) const;		/*operator * overloading with 1 const double*/
	double operator[](int) const;				/*operator [] overloading when const*/
	double& operator[](int);					/*operator [] overloading*/
	bool operator==(const VectorN&) const;		/*operator == overloading*/
	double at(int)const;					/*at prototype method when const*/
	double& at(int);						/*at protoytpe method*/
   };



#endif
