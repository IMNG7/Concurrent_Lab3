
#File Name: makefile
#Description: Makefile for the Lab0 for ECEN 5033
#Author: Nitik Gupta

DEPS = main.o util.o mergesort.o
CC = g++
LIBS = -fopenmp
CFLAGS = -g -O3

all: mysort

mysort: ${DEPS}
	g++ -o mysort -fopenmp -g main.cpp util.cpp mergesort.cpp 

main.o: main.cpp
	g++ -o main.o -fopenmp -g -c main.cpp

mergesort.o: mergesort.cpp mergesort.h
	g++ -o mergesort.o -fopenmp -g -c mergesort.cpp

util.o: util.cpp util.h
	g++ -o util.o -fopenmp -g -c util.cpp

clean :
	rm mysort *.o