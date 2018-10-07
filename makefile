#MAKEFILE

SHELL = /bin/sh
dir = .

#TODO: create and use variables

INC_PATH= %.h $(dir)/include
SRC_PATH=%.cpp $(dir)/source
CXXFLAGS = -Wall -g

main: main.o PixelDrawing.o Ulam.o
	g++ $(CXXFLAGS) -o main main.o PixelDrawing.o Ulam.o

main.o : main.cpp
	g++ -c main.cpp
PixelDrawing.o : PixelDrawing.cpp
	g++ -c PixelDrawing.cpp
Ulam.o : Ulam.cpp
	g++ -c Ulam.cpp
bitmap_test.o : bitmap_image.h
	g++ -c bitmap_image.h

clean :
	rm -f main.o PixelDrawing.o Ulam.o