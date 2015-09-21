.SUFFIXES: .cpp

CC = g++
CFLAGS = -g -I/usr/local/include -DPRINT -std=c++0x
LDIR =
LIBS =

OBJ = Contact.o Experiment.o Data.o SelectionSort.o MergeSort.o main.o

test: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDIR) $(LIBS)

.cpp.o:
	$(CC) $(CFLAGS) -c $?

clean:
	rm -f test $(OBJ) $(OBJ2)
