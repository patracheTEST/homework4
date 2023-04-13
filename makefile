main : main.o matrix_utils.o matrix_calc.o
	gcc -o ./build/main main.o ./utils/matrix_utils.o ./calc/matrix_calc.o

main.o : main.c
	gcc -c -o main.o main.c

matrix_utils.o : ./utils/matrix_utils.c
	gcc -c -o ./utils/matrix_utils.o ./utils/matrix_utils.c

matrix_calc.o : ./calc/matrix_calc.c
	gcc -c -o ./calc/matrix_calc.o ./calc/matrix_calc.c

clean : 
	rm *.o ./build/main **/*.o