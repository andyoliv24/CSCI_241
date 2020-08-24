#ifndef MATRIX_H
#define MATRIX_H

/**
 *
 * Matrix.h
 *
 * Author:    Andy Olivares
 * z-ID:      z1860934
 * Date:      3/19/2019
 * 
 * Contains the declaration for the Matrix class.
 */

#include <fstream>
using std::ostream;

class Matrix{
	   //Friend function prototypes for overloading operators
		friend ostream& operator <<(ostream&, const Matrix&);
		friend Matrix operator*(int, const Matrix&);
private:
 
	int matrixArray[2][2]; //2d array
	
public:

//constructors
	Matrix();			//constructor with no paramaters
	Matrix(int[2][2]);  //constructor with one parameter
	
	
	
//overloading 
	Matrix operator+(const Matrix&)const;	//prototype for + overloading
	Matrix operator*(int)const;				//prototype for * overloading with int parameter
	Matrix operator*(const Matrix&)const;	//prototype for * overloading with matrix object as parameter
	bool operator==(const Matrix&)const;	//prototype for == overloading with matrix object as parameter
	bool operator!=(const Matrix&)const;	//prototype for != overloading with matrix object as parameter
	
	
	int determinant() const;				//prototype for determinant method
};

#endif
