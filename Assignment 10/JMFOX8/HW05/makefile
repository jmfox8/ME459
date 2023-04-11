CC := gcc

all: task1 task2


task1: sort.c task1.c
	$(CC) sort.c task1.c -Wall -O3 -o task1

task2: mvmul.c task2.c
	$(CC) mvmul.c task2.c -Wall -O3 -o task2

clean:
	rm task2 task1
