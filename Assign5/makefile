#
# PROGRAM:  assign5
# AUTHOR:   Andy Olivares
# Z-ID:     z1860934
# DATE DUE: 3/28/2019
#
    
# Compiler variables
CCFLAGS = -Wall -std=c++11
    
# Rule to link object code files to create executable file
VecortN: VectorN.o
	g++ $(CCFLAGS) -o VectorN VectorN.o
    
# Rule to compile source code file to object code
VertorN.o: VectorN.cpp VectorN.h
	g++ $(CCFLAGS) -c VectorN.cpp

    
# Pseudo-target to remove object code and executable files
clean:
	-rm *.o VectorN
