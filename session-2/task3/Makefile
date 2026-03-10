
main.o: main.c student.h structure.h
	gcc -c main.c

student.o: student.c student.h structure.h
	gcc -c student.c

student: student.o main.o
	gcc student.o main.o -o student

clean:
	rm student.o main.o student
	