main : main.o matrix_utils.o
	gcc -o ./build/main main.o ./utils/matrix_utils.o

main.o : main.c
	gcc -c -o main.o main.c

matrix_utils.o : ./utils/matrix_utils.c
	gcc -c -o ./utils/matrix_utils.o ./utils/matrix_utils.c

clean : 
	rm *.o ./build/main **/*.o