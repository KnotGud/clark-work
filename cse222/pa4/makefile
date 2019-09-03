pa4: src/main.c build/queue.o build/bst.o
	gcc -o pa4 src/main.c build/queue.o build/bst.o
clean:
	rm pa4 build/*
build/queue.o: src/bst/queue.h src/bst/queue.c
	gcc -o build/queue.o src/bst/queue.c -c
build/bst.o: src/bst/bst.h src/bst/bst.c
	gcc -o build/bst.o src/bst/bst.c -c

