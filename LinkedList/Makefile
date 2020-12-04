CXX=g++
CXXFLAGS=-I.
#CXXFLAGS=-c -Wall

#HEADERS=$(shell ls *.hpp)
SOURCES=$(shell ls *.cpp)

DEBUGFLAG=-g

OBJS=$(SOURCES:.cpp=.o)

#$@ says to put the output of the compilation in the file named on the left side of the :
#$< is the first item in the dependencies list

%.o: %.cpp $(HEADERS) # Left side shows rule to generate .o files, Right: Lists the dependencies for %.o
	$(CXX) -c -o $@ $< $(CXXFLAGS) # Shows how to make %.o files

ll: $(OBJS) # Obj dependencies for ll
	$(CXX) -o $@ $(OBJS) # How to make ll

clean: 
	rm -rf $(OBJS)