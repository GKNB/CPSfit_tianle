OBJ	=  main.o
FLAG	=  -I/home/tw2507/cuth/build/Eigen -lm -std=c++11

STARTFIT: $(OBJ)
	g++ -o STARTFIT $(OBJ) $(FLAG)

main.o: main.c fit_adv.h
	g++ -c main.c $(FLAG)

.PHONY: clean
 
clean:
	rm main.o STARTFIT

