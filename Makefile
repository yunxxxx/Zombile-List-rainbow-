OBJS=main.o bo_linkedList.o
DEBUG=-g
CC=g++
CFLAGS=-Wall -c $(DEBUG)
LFLAGS=-Wall $(DEBUG)
EXE=zombie

&(EXE): $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(EXE)

bo_linkedList.o: bo_linkedList.h bo_linkedList.cpp
		 $(CC) $(CFLAGS) bo_linkedList.cpp

bo_yuan_assn6.o: bo_linkedList.h main.cpp
		 $(CC) $(CFLAGS) main.cpp

clean:
	rm *~ *.o $(EXE) -v
