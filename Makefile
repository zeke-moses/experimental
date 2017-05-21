# Makefile

TARGET  = exp

CC 		= gcc
CXX		= g++
CFLAGS  = -g -Wall
CXXFLAGS= -g -Wall
LDFLAGS = -g
LDLIBS  = -lm -lpthread
INCLUDES= 

$(TARGET): exp-structs.h


clean:
	rm -f a.out *.o $(TARGET)
