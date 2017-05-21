# Makefile

TARGET  = exp

CC 		= gcc
CXX		= g++
CFLAGS  = -g -Wall
CXXFLAGS= -g -Wall
LDFLAGS = -g
LDLIBS  = -lm
INCLUDES= 

$(TARGET):


clean:
	rm -f a.out *.o $(TARGET)
