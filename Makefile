# Makefile

TARGET  = exp

CC 		= gcc
CFLAGS  = -g -Wall
LDFLAGS = -g
LDLIBS  = -lm
INCLUDES= 

$(TARGET):


clean:
	rm -f a.out *.o $(TARGET)
