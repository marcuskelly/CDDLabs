#Mark Kelly C00198041 02/10/2017

EXE = sigexe
CC = g++
CFLAGS = -std=c++11 -pthread -I.

#This rule says that each .o file depends on a .cpp file of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

All: signal.o Semaphore.o
	$(CC) $(CFLAGS) signal.cpp Semaphore.cpp -o $(EXE)

#this is customary and just deletes all .o files
CLEAN:
	rm *.o
