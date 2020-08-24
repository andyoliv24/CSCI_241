#
# PROGRAM:  assign4
# AUTHOR:   Andy Olivars
# Z-ID:     z1860934
# DATE DUE: 3/19/2019
#
    
# Compiler variables
CCFLAGS = -Wall -std=c++11
    
# Rule to link object code files to create executable file
Matrix: Matrix.o
	g++ $(CCFLAGS) -o Matrix Matrix.o
    
# Rule to compile source code file to object code
Matrix.o: Matrix.cpp Matrix.h
	g++ $(CCFLAGS) -c Matrix.cpp

    
# Pseudo-target to remove object code and executable files
clean:
	-rm *.o Matrix
