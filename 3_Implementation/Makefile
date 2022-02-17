CC = gcc
CFLAGS = -g -w -Wall

main: main.o name.o
	$(CC) $(CFLAGS) -o main main.o name.o

test_unit: test_unit.o name.o
	$(CC) $(CFLAGS) -o test_unit test_unit.o name.o

name.o: banking.h name.c
	$(CC) $(CFLAGS) -c name.c

clean:
	rmm -f core *.o main