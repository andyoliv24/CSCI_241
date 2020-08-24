#
# PROGRAM:  assign9
# AUTHOR:   Andy Olivares
# Z-ID:     z1860934
# DATE DUE: 5/1/2019
#

# Compiler variables
CCFLAGS = -Wall -std=c++11


# Rule to link object code files to create executable file
assign9: assign9.o Shape.o Circle.o Rectangle.o Triangle.o
	g++ $(CCFLAGS) -o assign9 assign9.o Shape.o Circle.o Rectangle.o Triangle.o


assign9.o: assign9.cpp Shape.h Circle.h
	g++ -c assign9.cpp
	
	
Shape.o: Shape.cpp Shape.h
	g++ -c Shape.cpp
	
	
Circle.o: Circle.cpp Circle.h
	g++ -c Circle.cpp
	
Rectangle.o: Rectangle.cpp Rectangle.h
	g++ -c Rectangle.cpp
	
Triangle.o: Triangle.cpp Triangle.h
	g++ -c Triangle.cpp
	



# Pseudo-target to remove object code and executable files
clean:
	- rm *.o assign9
