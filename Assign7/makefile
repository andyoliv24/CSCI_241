#
# PROGRAM:  assign7
# AUTHOR:   Andy Olivares
# Z-ID:     z1860934
# DATE DUE: 4/18/2019
#
    
# Compiler variables
CCFLAGS = -Wall -std=c++11
    
# Rule to link object code files to create executable file
assign7: assign7.o
	g++ $(CCFLAGS) -o assign7 assign7.o
    
# Rule to compile source code file to object code
Queue.o: assign7.cpp Queue.h
	g++ $(CCFLAGS) -c assign7.cpp

    
# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign7
