####################
#     MAKEFILE     #
####################

SHELL = /bin/sh
srcdir = .

#TODO: create and use variables

INC_PATH= %.h ./include
SRC_PATH=%.cpp ./source
CXXFLAGS = -Wall -g

main: main.o PixelDrawing.o Ulam.o
	gcc $(CXXFLAGS) -o main main.o PixelDrawing.o Ulam.o

main.o : main.cpp
	gcc -c main.cpp
PixelDrawing.o : PixelDrawing.cpp
	gcc -c PixelDrawing.cpp
Ulam.o : Ulam.cpp
	gcc -c Ulam.cpp
clean :
	rm -f main.o PixelDrawing.o Ulam.o