/**
 *
 * CSCI 241 Assignment 1
 *
 * Author:  Andy Olivares
 * z-ID:    z1860934
 * Date:    2/11/2019
 *
 * This program tests functions for manipulating C strings.
 * 
 * INPUT:     Most input is from variables, only one input is from the keyboard.
 * 
 * 
 * OUTPUT:    word copied, letters replaced, case (upper/lower) changed on letters,
 * 			  reversed words, input from user.
 * 
 */
 
#include <iostream>
#include <cstring>
#include <cctype>
#include <stdio.h>
#include <string.h>
#include <algorithm> 

using std::cin;
using std::cout;
using std::endl;

// Add your function prototypes here
char* copy(char* destination, const char* source, size_t num); 											/* copy function prototype */
char* replaceCopy(char* destination, const char* source, char target, char replace, size_t num); 		/* Replace copy function prototype */
char* caseChangeCopy(char* destination, const char* source, size_t num); 								/* case change copy function prototype */
char* reverseCopy(char* destination, const char* source, size_t num); 									/* Reverse copy function prototype */
void read(char* destination, int num); 																	/* Read function prototype */

int main()
{
   const int WORDSIZE = 15;  																	/* variable that determines the size of the array word*/
   char words[][WORDSIZE] = {"sprightful", "reason to row", "New York", "Bolton", "Frida", ""}; /*array that holds words in it*/
   char word[WORDSIZE];																			/*empty array to later be filled*/


   // Test the copy function
   cout << "Copy \"sprightful\", should see \"sprightful\".\n";
   copy(word, words[0], sizeof(word) - 1);
   cout << word << endl << endl;
   
   memset(&word[0], 0, sizeof(word)); //clears strncpy buffer

   // Test the limit on the copy function
   cout << "Copy \"Supercalifragilisticexpialidocious\", should see \"Super\".\n";
   copy(word, "Supercalifragilisticexpialidocious", 5);
   cout << word << endl << endl;
   
   
    memset(&word[0], 0, sizeof(word)); //clears strncpy buffer
  
  
  // Test the replaceCopy function
   cout << "Replace 'r' in \"reason to row\" with 's', should see \"season to sow\".\n";
   replaceCopy(word, words[1], 'r', 's', sizeof(word) - 1);
   cout << word << endl << endl;
   
   memset(&word[0], 0, sizeof(word)); //clears strncpy buffer
   
   // Test the limit on the replaceCopy function
   cout << "Replace 's' in \"Supercalifragilistic\" with 'd', should see \"duper\".\n";
   replaceCopy(word, "Supercalifragilistic", 'S', 'd', 5);
   cout << word << endl << endl;

   memset(&word[0], 0, sizeof(word)); //clears strncpy buffer

   // Test the caseChangeCopy function
   cout << "Case change \"New York\", should see \"nEW yORK\".\n";
   caseChangeCopy(word, words[2], sizeof(word) - 1);
   cout << word << endl << endl;
   
   memset(&word[0], 0, sizeof(word)); //clears strncpy buffer
   
   // Test the limit on the caseChangeCopy function
   cout << "Case change \"Supercalifragilistic\", should see \"sUPER\".\n";
   caseChangeCopy(word, "Supercalifragilistic", 5);
   cout << word << endl << endl;  
  
   memset(&word[0], 0, sizeof(word)); //clears strncpy buffer
  
   // Test the reverseCopy function
   cout << "Reverse \"Bolton\", should see \"notloB\"\n";
   reverseCopy(word, words[3], sizeof(word) - 1);
   cout << word << endl << endl;
   
   memset(&word[0], 0, sizeof(word)); //clears strncpy buffer
   
   // Test the limit on the reverseCopy function
   cout << "Reverse \"cytogeneticists\", should see \"tsicitenegotyc\"\n";
   reverseCopy(word, "cytogeneticists", sizeof(word) - 1);
   cout << word << endl << endl;
   
   memset(&word[0], 0, sizeof(word)); //clears strncpy buffer
   
   cout << "Reverse \"Frida\", change case, and replace 'D' with 'Z', should see \"AZIRf\".\n";
   replaceCopy(caseChangeCopy(reverseCopy(word, words[4], sizeof(word) - 1), word, sizeof(word) - 1), word, 'D', 'Z', sizeof(word) - 1);
   cout << word << endl << endl;  
   
   memset(&word[0], 0, sizeof(word)); //clears strncpy buffer

   cout << "Enter your entire name: ";
   read(words[5], sizeof(words[5]));
   cout << words[5] << endl << endl;  
   
   memset(&word[0], 0, sizeof(word)); //clears strncpy buffer

   cout << "Reverse your name and change case.\n";
   cout << caseChangeCopy(reverseCopy(word, words[5], sizeof(word) - 1), word, sizeof(word) - 1) << endl;

   return 0;
   }




// Add your function definitions here


/****************************************************************

   FUNCTION:   copy(char* destination, const char* source, size_t num); 

   ARGUMENTS:  destination: empty array, source: array that holds values, num: length of destination

   RETURNS:    a pointer(destination)

   NOTES:      This function copies whatever value is specified in source and copies it to destination
****************************************************************/
char* copy(char* destination, const char* source, size_t num){
	strncpy(destination, source, num);
	return destination;
	}
	
	
	
/****************************************************************

   FUNCTION:   char* replaceCopy(char* destination, const char* source, char target, char replace, size_t num); 

   ARGUMENTS:  destination: empty array, source: array that holds values, num: length of destination

   RETURNS:    a pointer(destination)

   NOTES:      This function replaces the value target with replace parameter
****************************************************************/
char* replaceCopy(char* destination, const char* source, char target, char replace, size_t num){
	strncpy(destination, source, num); 
		for(int i = 0; destination[i] != '\0'; i++){ 				//loops through the destination array/string
			if(destination[i]== target){    						//if destination[i] matches the target it get replaced with the replace value.
				destination[i] = replace;
			}
		}
	return destination;
}



/****************************************************************

   FUNCTION:   char* caseChangeCopy(char* destination, const char* source, size_t num); 

   ARGUMENTS:  destination: empty array, source: array that holds values, num: length of destination

   RETURNS:    a pointer(destination)

   NOTES:      This function changes upper to lower and lower to upper (letters)
****************************************************************/
char* caseChangeCopy(char* destination, const char* source, size_t num){
	strncpy(destination, source, num);
	
		for(int i = 0; destination[i] != '\0'; i++){  				//loops through the destination array/string
			
			if(isupper(destination[i])){							//checks if letter is upper case, if so it lowers it
					destination[i] = tolower(destination[i]);
					
			}else{													// checks if letter is lower case, if so it uppers it
					destination[i] = toupper(destination[i]);
				 }
		
		}	
	 return destination;
}
	
	


/****************************************************************

   FUNCTION:   char* reverseCopy(char* destination, const char* source, size_t num);  

   ARGUMENTS:  destination: empty array, source: array that holds values, num: length of destination

   RETURNS:    a pointer(destination)

   NOTES:      This function reverses a word.
****************************************************************/
char* reverseCopy(char* destination, const char* source, size_t num){
	strncpy(destination, source, num);
	for (int i = strlen(destination) - 1; i >= 0; i--){ 		// loops through the array backwards and replaces destination[i] on each loop so it reverses the word
		destination[i] = source[strlen(destination)-i-1];
	 }
	
	return destination;
}
	

	
/****************************************************************

   FUNCTION:   void read(char* destination, int num);   

   ARGUMENTS:  destination: empty array, source: array that holds values, num: length of destination

   RETURNS:    nothing.

   NOTES:      Takes input from user but no longer that num's length.
****************************************************************/
void read(char* destination, int num){
	cin.getline(destination,num);			//gets input from user (by parameter num limits characters to be input)
}

