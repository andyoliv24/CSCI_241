#
# PROGRAM:  assign1
# AUTHOR:   Andy Olivares
# Z-ID:     z1860934
# DATE DUE: 2/11/2019
#
    
# Compiler variables
CCFLAGS = -Wall -std=c++11
    
# Rule to link object code files to create executable file
assign1: assign1.o
	g++ $(CCFLAGS) -o assign1 assign1.o
    
# Rule to compile source code file to object code
assign1.o: assign1.cpp
	g++ $(CCFLAGS) -c assign1.cpp
    
# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign1
