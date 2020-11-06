
#File Name: makefile
#Description: Makefile for the Lab0 for ECEN 5033
#Author: Nitik Gupta

DEPS = main.o util.o mergesort.o
CC = g++
LD = -g -fopenmp

all: mysort

mysort: ${DEPS}
	${CC} ${DEPS} ${LD} -o $@  

*.o: *.cpp *.h
	${CC} ${LD} -c *.cpp

clean :
	rm mysort *.o