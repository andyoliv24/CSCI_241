/**
 *
 * CSCI 241 Assignment 5
 *
 * Author: Andy Olivares
 * z-ID: z1860934
 * Date: 3/28/2019
 *
 * This program tests the functionality of the VectorN class.
 */  

#include <iostream>
#include <stdexcept>
#include "VectorN.h"

using std::cout;
using std::endl;
using std::out_of_range;


int main()
   {
   int test = 1;

   cout << "\nTest " << test++ << ": Default constructor and printing\n" << endl;

   const VectorN v1;

   cout << "v1: " << v1 << endl;

   cout << "\nTest " << test++ << ": Array constructor and printing\n" << endl;

   double ar2[] = {1.0, 2.0, 3.0};

   const VectorN v2(ar2, 3);

   cout << "v2: " << v2 << endl;

   cout << "\nTest " << test++ << ": Clear and size\n" << endl;
   VectorN v3(ar2, 3);
  
   cout << "The size of v3: " << v3 << " is " << v3.size() << endl;

   v3.clear();

   cout << "After clearing, the size of v3: " << v3 << " is ";
   cout << v3.size() << endl;

   cout << "\nTest " << test++ << ": Subscripting\n" << endl;

   double ar3[] = {-1.0, -3.0, -5.0, 7.0};
   const VectorN v4(ar3, 4);

   cout << "v4: " << v4 << endl;
   cout << "v4[0]: " << v4[0] << "  v4[1]: " << v4[1] << endl;
   cout << "v4[2]: " << v4[2] << "  v4[3]: " << v4[3] << endl;
  
   VectorN v5(ar3, 4);
   v5[0] = 17;  v5[1] = 3;  v5[2] = 0;  v5[3] = -9;
   cout << "v5: " << v5 << endl;
 
   cout << "\nTest " << test++ << ": Copy constructor\n" << endl;
  
   const VectorN v6(ar2, 3);
   const VectorN v7 = v6;

   cout << "v6: " << v6 << " size: " << v6.size() << endl;
   cout << "v7: " << v7 << " size: " << v7.size() << endl;

   VectorN v8(ar3, 4);
   VectorN v9 = v8;

   cout << "v8: " << v8 << " size: " << v8.size() << endl;
   cout << "v9: " << v9 << " size: " << v9.size() << endl;

   v8[1] = 300.0;
   cout << "Changing..." << endl;
   cout << "v8: " << v8 << " size: " << v8.size() << endl;
   cout << "v9: " << v9 << " size: " << v9.size() << endl;

   cout << "\nTest " << test++ << ": Assignment operator\n" << endl;
   VectorN v10(ar3, 4);
   VectorN v11;

   cout << "v10: " << v10 << endl;
   cout << "v11: " << v11 << endl;

   v11 = v10;

   v10[0] = 0.0;

   cout << "v10: " << v10 << endl;
   cout << "v11: " << v11 << endl;

   cout << endl;

   // Chained assignment
   VectorN v12, v13;

   cout << "v11: " << v11 << endl;
   cout << "v12: " << v12 << endl;
   cout << "v13: " << v13 << endl;

   v13 = v12 = v11;

   cout << "v11: " << v11 << endl;
   cout << "v12: " << v12 << endl;
   cout << "v13: " << v13 << endl;

   cout << endl;

   // Assignment to self

   v13 = v13;

   VectorN v14(ar2, 3);

   cout << "v13: " << v13 << endl;
 
  
   cout << "\nTest " << test++ << ": Addition and subtraction\n" << endl;

   double ar4[] = {-2.0, 3.0, -1.0};
   double ar5[] = {0, 1, 2, -3};

   const VectorN v15(ar2, 3), v16(ar4, 3);
   const VectorN v17(ar5, 4);

   cout << "v13: " << v13 << endl;
   cout << "v15: " << v15 << endl;
   cout << "v16: " << v16 << endl;
   cout << "v17: " << v17 << endl;

   cout << endl;
   cout << "v15 + v16 is " << v15 + v16 << endl;
   cout << "v13 + v17 is " << v13 + v17 << endl;
   cout << "v15 + v13 is " << v15 + v13 << endl;
   cout << "v17 + v16 is " << v17 + v16 << endl;

   cout << endl;
   cout << "v15 - v16 is " << v15 - v16 << endl;
   cout << "v13 - v17 is " << v13 - v17 << endl;
   cout << "v15 - v13 is " << v15 - v13 << endl;
   cout << "v17 - v16 is " << v17 - v16 << endl;
 
   cout << "\nTest " << test++ << ": Vector multiplication\n" << endl;

   cout << "The scalar product of " << v15 << " and " << v16 << " is ";
   cout << v15 * v16 << endl;

   cout << "The scalar product of " << v13 << " and " << v17 << " is ";
   cout << v13 * v17 << endl;

   cout << "The scalar product of " << v13 << " and " << v15 << " is ";
   cout << v13 * v15 << endl;

   cout << "The scalar product of " << v16 << " and " << v17 << " is ";
   cout << v16 * v17 << endl;

   cout << "\nTest " << test++ << ": Scalar multiplication\n" << endl;

   double k = 2.345;

   cout << v17 << " * " << k << " = " << v17 * k << endl;
   cout << k << " * " << v17 << " = " << k * v17 << endl;
 
   cout << "\nTest " << test++ << ": Equality\n" << endl;

   double ar6[] = {1, 2, 2};
   double ar7[] = {1, 2, -2};
   double ar8[] = {1, 2, 2, 0};
   double ar9[] = {1, 2, -2, 0};

   const VectorN v18(ar6, 3), v19(ar7, 3);
   const VectorN v20(ar8, 4), v21(ar9, 4);

   cout << v18 << " and " << v18 << " are ";

   if (v18 == v18)
      cout << "equal" << endl;
   else
      cout << "not equal" << endl;
  
   cout << v18 << " and " << v19 << " are ";

   if (v18 == v19)
      cout << "equal" << endl;
   else
      cout << "not equal" << endl;
  
   cout << v18 << " and " << v20 << " are ";

   if (v18 == v20)
      cout << "equal" << endl;
   else
      cout << "not equal" << endl;
  
   cout << v21 << " and " << v19 << " are ";

   if (v21 == v19)
      cout << "equal" << endl;
   else
      cout << "not equal" << endl;



 /*extra credit*/

   cout << "\nTest " << test++ << ": Read-write form of at() method\n" << endl;

   VectorN v22(ar9, 4);
   const VectorN v23(ar9, 4);
   
   try
      {
      v22.at(0) = 9.1;
      v22.at(1) = 3.97;
      v22.at(-1) = -7.43;
      }
   catch (out_of_range orex)
      {
      cout << "Caught "<< orex.what() << endl;
      }

   cout << "v22: " << v22 << endl;

   cout << "\nTest " << test++ << ": Read-only form of at() method\n" << endl;
      
   try
      {
      cout << "v23: (";
      for (unsigned i = 0; i <= v23.size(); i++)
         cout << v23.at(i) << ", ";
      cout << ")\n\n";
      }
   catch (out_of_range orex)
      {
      cout << endl << "Caught "<< orex.what() << endl;
      }

   return 0;
 }
 
 
 
 
 
 //default constructor

/***************************************************************
Calls VectorN default constructor
Use: sets 1 on the main diagonals and all others are 0
Parameters: none
Returns: nothing
***************************************************************/
 VectorN::VectorN(){
	 vCapacity = 0;
	 vArray = nullptr;
}

//constructor with two parameter

/***************************************************************
Calls VectorN constructor with 2 parameters
Use: sets the vector capacity to n, if vector capacity is 0 it is set
to nullptr.
Copies the elements of the array values into vector array
Parameters: 1.const double values[]: this holds values to be copied 
			  into vector array
			2.n is used as the capacity of the array.
Returns: nothing
***************************************************************/
 VectorN::VectorN(const double values[], size_t n){
	 vCapacity = n;
	 /*checks if vcapacity is equal to 0*/
	 if(vCapacity ==0){
		 vArray = nullptr;
		}
	 else{
			vArray = new double[n];
		}
	 /*copies values array contents into vArray*/
	for (size_t i = 0; i<vCapacity; i++){
		vArray[i] = values[i];
		}
}


//constructor with one parameter (copy constructor)
/***************************************************************
Calls VectorN constructor with 1 parameter
Use: sets the vector capacity for new object to the vector capacity of other
if vector capacity is 0 then the vector array pointer for the new object is
set to nullptr
Copies contents of the new vector array of other into the vector array of
the new object
Parameters: 1.const VectorN& other: used to get values for the vector array
Returns: nothing
***************************************************************/
VectorN::VectorN(const VectorN& other){
	 vCapacity = other.vCapacity;
	 /*checks if vCapacity is 0*/
	if(vCapacity == 0){
		vArray = nullptr;
	} 
	else{
		vArray = new double[vCapacity];
		}
		
	for (size_t i = 0; i<vCapacity; i++){
	/*if other.vCapacity is 0 then for loop will stop*/
		if(other.vCapacity ==0){
		break;
		}
		vArray[i] = other.vArray[i];
	}
		
}

//destructor
/***************************************************************
Use: calls clear method
Parameters: none
Returns: nothing
***************************************************************/
VectorN::~VectorN(){
	clear();
}



//operator = method
/***************************************************************
Use: it assigns one vectorN object to another
Parameters: 1. const VectorN& other used to copy elements to vArray
Returns: *this
***************************************************************/
VectorN& VectorN::operator=(const VectorN& other){
	/*checks if this and &other have the same address*/
	if(this != &other){
		delete[] vArray;
		vCapacity = other.vCapacity;
		if(vCapacity > 0)
			vArray = new double[vCapacity];
		else
			vArray = nullptr;
		/*copies content of other to vArray*/
		for(size_t i =0; i<vCapacity; i++){
			vArray[i] = other.vArray[i];
			}
		}
			
	return *this;
}

//clear method
/***************************************************************
Use: sets the instance back to a vector of zero elements
Parameters: none
Returns: nothing
***************************************************************/
void VectorN::clear(){
	vArray = nullptr;
	vCapacity = 0;
}


//size method
/***************************************************************
Use: returns the size of the vector
Parameters: none
Returns: vCapacity
***************************************************************/
size_t VectorN::size()const{
	return vCapacity;
}



//operator + method overloaded
/***************************************************************
Use: sums two vectorNs
Parameters: 1.const VectorN& vect: to be added by another VectorN
Returns: VectorN
***************************************************************/
VectorN VectorN::operator+(const VectorN& vect)const{
	int n=0;	/*will hold lowest vCapacity*/
	
	/*checks if this->vCapacity is less than vect.vCapacity if so n is set to this->vCapacity*/
	if(this->vCapacity < vect.vCapacity){
		n=this->vCapacity;
	}
	/*sets n to vect.vCapacity since it holds a lower vCapacity*/
	else{
		n= vect.vCapacity;
	}
	double* vector = new double[n];
	/*adds both vectorNs*/
	for(int i=0; i<n; i++){
		vector[i]=vArray[i]+vect[i];
		}
	return VectorN(vector, n);
}


//operator - method overloaded
/***************************************************************
Use: subtraction of two vectorNs
Parameters: 1.const VectorN& vect: to be subtracted by another VectorN
Returns: VectorN
***************************************************************/
VectorN VectorN::operator-(const VectorN& vect)const{
	int n=0;	/*will hold lowest vCapacity*/
	
	/*checks if this->vCapacity is less than vect.vCapacity if so n is set to this->vCapacity*/
	if(this->vCapacity < vect.vCapacity){
		n=this->vCapacity;
	}
	/*sets n to vect.vCapacity since it holds a lower vCapacity*/
	else{
		n= vect.vCapacity;
	}
	double* vector = new double[n];
	/*substracts both vectorNs*/
	for(int i=0; i<n; i++){
		vector[i]=vArray[i]-vect[i];
		}
	return VectorN(vector, n);
}


	
//operator * method overloaded (first form (scalar product))
/***************************************************************
Use: Multiplication of two vectorNs
Parameters: 1.const VectorN& vect: to be multiplied by another VectorN
Returns: VectorN
***************************************************************/
double VectorN::operator*(const VectorN& vect) const{
	int n=0;			/*will hold lowest vCapacity*/
	double vector = 0;  /*will hold the result of multiplying both vectorNs*/
	
	/*checks if this->vCapacity is less than vect.vCapacity if so n is set to this->vCapacity*/
	if(this->vCapacity < vect.vCapacity){
		n=this->vCapacity;
	}
	/*sets n to vect.vCapacity since it holds a lower vCapacity*/
	else{
		n= vect.vCapacity;
	}
	/*Multiplies both vectorNs*/
	for(int i=0; i<n; i++){
		vector+=vArray[i]*vect[i];
		}
	return vector;
}

//operator * method overloaded (when double mutiplied by a VectorN)
/***************************************************************
Use: Multiplication of a VectorN and a double
Parameters: 1.const VectorN& vect: to be multiplied by a double
			2.const double& d: to be multiplied by a VectorN
Returns: VectorN
***************************************************************/
VectorN operator*(const double& d, const VectorN& vect){
	int n= vect.size();
	double* vector = new double[n];
	/*Multiplies vectorN by a double*/
	for(int i=0; i<n; i++){
		vector[i]= d *vect[i];
		}
	return VectorN(vector, n);
}


//operator * method overloaded (when double is passed)
/***************************************************************
Use: Multiplication of a VectorN and a double
Parameters: 1.const double& d: to be multiplied by a VectorN
Returns: Vector
***************************************************************/
VectorN VectorN::operator*(const double& d) const{
	double* vector = new double[vCapacity]; /*holds value of mutlipliying double by vArray*/
	
	/*Multiplies vectorN by a double*/
	for(unsigned i=0; i<vCapacity; i++){
		vector[i]= d * vArray[i];
		}
	return VectorN(vector, vCapacity);
}



//operator [] method (read-only)
/***************************************************************
Use: provides accesor methods for the class
Parameters: 1.int sub: used as number of index of subscript
Returns: vArray[sub]
***************************************************************/
double VectorN::operator[](int sub) const{
	return vArray[sub];
}
	
	
//operator [] method (read-write)
/***************************************************************
Use: provides accesor methods for the class and write
Parameters: 1.int sub: used as number of index of subscript
Returns: vArray[sub]
***************************************************************/
double& VectorN::operator[](int sub){
	return vArray[sub];
}	
	


//operator == method
/***************************************************************
Use: compares to VectorNs
Parameters: 1.const VectorN& vect: used to be compared
Returns: true or false;
***************************************************************/
bool VectorN::operator==(const VectorN& vect) const{
	//checks if sizes of both vectorNs are not equal
	if(this->size()!= vect.size())
		return false;
	else
		/*loops through both vectorNs*/
		for(unsigned i =0 ; i<vCapacity; i++){
		/*checks for inequality*/
				if(vArray[i] != vect[i])
					return false;		
		}
	return true;
}
	

//at method const
/***************************************************************
Use: checks for errors in index of VectorN
Parameters: 1. unsigned sub (index if vectorN)
Returns: vArray[sub] or error
***************************************************************/
double VectorN::at(int sub)const{
	//return element element sub of array data member
	if(sub>= 0 && sub < (int) vCapacity){
		return vArray[sub];
	}
	else{
		out_of_range r("subscript out of range");
		throw out_of_range("subscript out of range");
	}	
}

//at method
/***************************************************************
Use: checks for errors in index of VectorN
Parameters: 1. unsigned sub (index if vectorN)
Returns: vArray[sub] or error
***************************************************************/
double& VectorN::at(int sub){
	/*checks if index is in boundaries of vectorN*/
	if(sub < 0 || sub >= (int) vCapacity)
		throw out_of_range("subscript out of range");
	return vArray[sub];
}



//operator << function
/***************************************************************
Use: overloads << operator to print out vectorNs
Parameters: 1. ostream& outp: used as cout
			2. const VectorN& vect: used to print out values
Returns: outp(ostream& object)
***************************************************************/
ostream& operator<<(ostream& outp, const VectorN& vect){
	outp << '(';
	/*checks if vCapacity is 0*/
	if(vect.vCapacity == 0){
		outp << "";
	}
	else{
		for(size_t i =0; i <vect.vCapacity; i++){
			outp << vect.vArray[i];
			if(i !=vect.vCapacity-1){
				outp << ", ";
				}
			}
	}
	outp << ')';
	return outp;
}
















