# Makefile

TARGET  = exp

CC 		= gcc
CXX		= gxx
CFLAGS  = -g -Wall
CXXFLAGS= 
LDFLAGS = -g
LDLIBS  =
INCLUDES= 

$(TARGET):

clean:
	rm -f a.out *.o $(TARGET)
