pa3: src/main.c build/ll.o build/stack_ll.o build/queue_ll.o
	gcc -o pa3 src/main.c build/main.o build/stack_ll.o build/queue_ll.o
clean:
	rm pa3 pa3_debug build/*
debug: src/main.c src/main.h src/ll.c src/queue_ll.c src/stack_ll.c 
	gcc -o pa3_debug src/main.c src/ll.c src/queue_ll.c src/stack_ll.c -g
build/ll.o: src/main.h src/ll.c
	gcc -o build/main.o src/ll.c -c
build/stack_ll.o: src/main.h src/stack_ll.c
	gcc -o build/stack_ll.o src/stack_ll.c -c
build/queue_ll.o: src/main.h src/queue_ll.c
	gcc -o build/queue_ll.o src/queue_ll.c -c

