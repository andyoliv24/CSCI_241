#
# PROGRAM:  assign6
# AUTHOR:   Andy Olivares
# Z-ID:     z1860934
# DATE DUE: 4/11/2019
#
    
# Compiler variables
CCFLAGS = -Wall -std=c++11
    
# Rule to link object code files to create executable file
assign6: assign6.o
	g++ $(CCFLAGS) -o assign6 assign6.o
    
# Rule to compile source code file to object code
VertorN.o: assign6.cpp Stack.h
	g++ $(CCFLAGS) -c assign6.cpp

    
# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign6
