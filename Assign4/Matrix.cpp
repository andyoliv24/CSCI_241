/**
 *
 * CSCI 241 Assignment 4
 *
 * Author: Andy Olivares
 * z-ID: z1860934
 * Date: 3/19/2019
 *
 * This program tests the functionality of the Complex class.
 */

#include <iostream>
#include "Matrix.h"

using std::cout;
using std::endl;

int main()
   {
   int array1[2][2] = {{5, 7}, {3, 2}};				
   int array2[2][2] = {{2, 3}, {1, 4}};

   // Test identity matrix constructor

   cout << "1. Testing identity matrix constructor\n\n";

   const Matrix m1;

   cout << "m1 = " << m1 << endl << endl;

   // Test array initialization constructor

   cout << "2. Testing array initialization constructor\n\n";
   
   Matrix m2(array1);
   cout << "m2 = " << m2 << endl;

   const Matrix m3(array2);
   cout << "m3 = " << m3 << endl << endl;

   // Test determinant

   cout << "3. Testing determinant\n\n";

   cout << "det" << m2 << " = " << m2.determinant() << endl;
   cout << "det" << m3 << " = " << m3.determinant() << endl << endl;



   // Test matrix addition

   cout << "4. Testing matrix addition\n\n";

   cout << m2 << " + " << m3 << " = " << m2 + m3 << endl;
   cout << m3 << " + " << m2 << " = " << m3 + m2 << endl << endl;


   // Test scalar multiplication

   cout << "5. Testing scalar multiplication\n\n";

   cout << m2 << " * 2 = " << m2 * 2 << endl;
   cout << "4 * " << m2 << " = " << 4 * m2 << endl << endl;

   //Test matrix multiplication

   cout << "6. Testing matrix multiplication\n\n";

   cout << m2 << " * " << m3 << " = " << m2 * m3 << endl;
   cout << m3 << " * " << m2 << " = " << m3 * m2 << endl;
   cout << m3 << " * " << m1 << " = " << m3 * m1 << endl;
   cout << m1 << " * " << m3 << " = " << m1 * m3 << endl << endl;

   cout << "det(m2 * m3) and det(m2) * det(m3) are ";
   cout << (((m2 * m3).determinant() == m2.determinant() * m3.determinant()) ? 
     "equal\n\n" : "not equal\n\n");

   // Test relational operators

   cout << "7. Testing relational operators\n\n";

   const Matrix m4(array1);

   cout << m2 << " and " << m4;
   cout << ((m2 == m4) ? " are equal\n" : " are not equal\n");

   cout << m2 << " and " << m3;
   cout << ((m2 != m3) ? " are not equal\n" : " are equal\n");

   return 0;
   }
   
   
   
//default constructor

/***************************************************************
Calls Matrix default constructor
Use: sets 1 on the main diagonals and all others are 0
Parameters: none
Returns: nothing
***************************************************************/
Matrix::Matrix(){
	
	matrixArray[0][0] = 1;
	matrixArray[0][1] = 0;
	matrixArray[1][0] = 0;
	matrixArray[1][1] = 1;
}


//constructor with one parameter

/***************************************************************
Calls Matrix constructor with one parameter
Use: sets values on matrix using newMatrix array
Parameters: 1.newMatrix: has values to pass into matrix array
Returns: nothing
***************************************************************/
Matrix::Matrix(int newMatrix[2][2]){
		for(int i =0; i<2; i++){										//loos through the 2d array and gets values from newMatrix array to be stored
			for(int j=0; j<2; j++){
				matrixArray[i][j] = newMatrix[i][j];	
			}
		}
	
}

//methods
/***************************************************************
Calls determinant method
Use: calculates the determinant.
Parameters: none
Returns: total (matrix object)
***************************************************************/
int Matrix::determinant() const{
	
	int total = matrixArray[0][0] * matrixArray[1][1] - matrixArray[0][1] * matrixArray[1][0]; 
	
	return total;
}


/***************************************************************
Calls operator+ method
Use: calculates the sum of array on the left operand and right operand.
Parameters: 1. const Matrix& rhs: used as matrix object reference.
Returns: sumOperator(matrix object)
***************************************************************/
Matrix Matrix::operator+(const Matrix& rhs)const{
	Matrix sumOperator = *this;
		for(int i =0; i<2; i++){										//loops through array to sum array by another array
			for(int j=0; j<2; j++){

			sumOperator.matrixArray[i][j] = sumOperator.matrixArray[i][j] + rhs.matrixArray[i][j];
					
			}
		}	
	return sumOperator;
}



/***************************************************************
Calls operator* method
Use: it multiplies an array by an integer.
Parameters: 1. rhs int: number to be multiply by array.
Returns: result (matrix object)
***************************************************************/
Matrix Matrix::operator*(int rhs)const{
	Matrix result = *this;			
		for(int i =0; i<2; i++){										//loops through array to multiply array by an integer
			for(int j=0; j<2; j++){
			result.matrixArray[i][j] *=  rhs;		
			}
		}
	
	return result;
}


/***************************************************************
Calls operator* method with one argument
Use: mutiplies an array by another array.
Parameters: 1. const Matrix& rhs: used as a matrix a reference.
Returns: resultMultiply(matrix object)
***************************************************************/
Matrix Matrix::operator*(const Matrix& rhs)const{
	Matrix resultMultiply;

	resultMultiply.matrixArray[0][0] = (this->matrixArray[0][0] * rhs.matrixArray[0][0]) + (this->matrixArray[0][1] * rhs.matrixArray[1][0]);
	resultMultiply.matrixArray[0][1] = (this->matrixArray[0][0] * rhs.matrixArray[0][1]) + (this->matrixArray[0][1] * rhs.matrixArray[1][1]);
	resultMultiply.matrixArray[1][0] = (this->matrixArray[1][0] * rhs.matrixArray[0][0]) + (this->matrixArray[1][1] * rhs.matrixArray[1][0]);
	resultMultiply.matrixArray[1][1] = (this->matrixArray[1][0] * rhs.matrixArray[0][1]) + (this->matrixArray[1][1] * rhs.matrixArray[1][1]);

	return resultMultiply;
}

/***************************************************************
Calls operator== method
Use: compares if two arrays are the same
Parameters: 1. const Matrix& rhs used as a matrix reference
Returns: false or true
***************************************************************/
bool Matrix::operator==(const Matrix& rhs)const{
	for(int i =0; i<2; i++){											//loops through array and checks if both arrays have the same values
		for(int j=0; j<2; j++){
				if(this->matrixArray[i][j]==rhs.matrixArray[i][j]){
					return true;
					}
			}
		}
	return false;
}


/***************************************************************
Calls operator!= method
Use: compares if two arrays are not the same
Parameters: 1. const Matrix& rhs used as a matrix reference
Returns: false or true
***************************************************************/
bool Matrix::operator!=(const Matrix& rhs)const{
	for(int i =0; i<2; i++){											//loops through array and checks if both arrays don't have the same values
		for(int j=0; j<2; j++){
				if(this->matrixArray[i][j]==rhs.matrixArray[i][j]){
					return false;
					}
			}
		}
	return true;
}




// functions

/***************************************************************
Calls operator* function
Use: overloads * operator.
Parameters: 1. int lhs: used as left operand.
* 2. const Matrix& rhs used as a matrix reference.
Returns: resultOp
***************************************************************/
Matrix operator*(int lhs, const Matrix& rhs){
		Matrix resultOp;
	
		for(int i =0; i<2; i++){										//loops through arrays, resultOp stores the result of rhs.matrixArrayy multiplied by lhs.
			for(int j=0; j<2; j++){
			resultOp.matrixArray[i][j] = rhs.matrixArray[i][j] * lhs;		
			}
		}
	
	
	return resultOp;
}

	
/***************************************************************
Calls operator<< function
Use: overloads << operator
Parameters: 1. ostream& lhs: used as left operand.
* 2.const Matrix& rhs: used as a matrix reference
Returns: lhs
***************************************************************/	
ostream& operator<<(ostream& lhs, const Matrix& rhs){
		lhs <<  "[[" << rhs.matrixArray[0][0] << ","
		<< rhs.matrixArray[0][1] <<  "]," << "["
		<< rhs.matrixArray[1][0] << "," << rhs.matrixArray[1][1]
		<< "]]"; 
	
	return lhs;
}














