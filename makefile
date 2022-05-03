# -*- MakeFile -*-

bin: matrix_threads.c
	gcc $< -o $@ -lpthread

run:
	./bin

clean:
	rm bin
