all: medtrack

medtrack: main.o patient.o
	gcc -o medtrack main.o patient.o

main.o: main.c patient.h
	gcc -c main.c

patient.o: patient.c patient.h
	gcc -c patient.c

clean:
	rm -f *.o medtrack
