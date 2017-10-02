#Mark Kelly C00198041 02/10/2017

EXE = sigexe
CC = g++
CFLAGS = -std=c++11 -pthread

CFILES = signal.cpp Semaphore.cpp
HFILES = Semaphore.h

All: $(CFILES) $(HFILES)
	$(CC) $(CFLAGS) *.cpp -o sigexe

#this is customary and just deletes all .o files
CLEAN:
	rm *.o
