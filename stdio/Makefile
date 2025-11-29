
clean: 
	rm -f main

build:
	gcc -o main main.c -Wall


run: clean build
	./main

clean-main2: 
	rm -f main2

build-lower:
	gcc -o lower main2.c -Wall

build-upper:
	gcc -o upper main2.c -Wall


run-main2: clean-main2 build-main2
	./main2


