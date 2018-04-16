OBJ	=  main.o
FLAG	=  -I/home/tw2507/cuth/build/Eigen -L/home/tw2507/gsl-build/lib -lgsl -lgslcblas -lblas -lm -I/home/tw2507/gsl-build/include -std=c++11

STARTFIT: $(OBJ)
	g++ -o STARTFIT $(OBJ) $(FLAG)

main.o: main.c fit_adv.h lvm_fit.h fit_candidate_func.h
	g++ -c main.c $(FLAG)

.PHONY: clean
 
clean:
	rm main.o STARTFIT

