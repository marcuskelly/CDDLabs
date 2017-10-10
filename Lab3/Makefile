#Mark Kelly C00198041 02/10/2017

EXE = myMutex
CC = g++
CFLAGS = -std=c++11 -pthread -I.

#This rule says that each .o file depends on a .cpp file of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

All: MyMutex.o Semaphore.o
	$(CC) $(CFLAGS) MyMutex.cpp Semaphore.cpp -o $(EXE) $(DEBUGFLAGS)

DEBUG: DEBUGFLAGS = -g -O0
DEBUG: ALL

#this is customary and just deletes all .o files
CLEAN:
	rm *.o
