
#File Name: makefile
#Description: Makefile for the Lab0 for ECEN 5033
#Author: Nitik Gupta

DEPS = main.o util.o mergesort.o
CC = g++
LD = -g -fopenmp

all: mysort

mysort: ${DEPS}
	g++ -o mysort -fopenmp -g main.cpp util.cpp mergesort.cpp 

clean :
	rm mysort *.o