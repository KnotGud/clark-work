pa5: src/main.c build/maxval.o build/readFile.o
	gcc -o pa5 ./src/main.c ./build/maxval.o ./build/readFile.o
build/maxval.o: src/knapsack/knapsack.h src/knapsack/maxval.c
	gcc -o ./build/maxval.o ./src/knapsack/maxval.c -c
build/readFile.o: src/knapsack/knapsack.h src/knapsack/readFile.c
	gcc -o ./build/readFile.o ./src/knapsack/readFile.c -c
debug: src/main.c src/knapsack/knapsack.h src/knapsack/readFile.c src/knapsack/maxval.c
	gcc -o debug src/main.c src/knapsack/maxval.c src/knapsack/readFile.c -g
clean: pa5 ./build
	rm pa5 ./build/*.o
clean-debug: debug
	rm debug
