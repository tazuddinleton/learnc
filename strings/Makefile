
clean: 
	rm -f main

build:
	gcc -o main main.c text_buffer.c -Wall


run: clean build
	./main

clean-test:
	rm -rf text_buffer_test

build-test: 
	gcc -std=c11 ../munit/munit.c text_buffer.c text_buffer_test.c -Wall -g -Wextra -o text_buffer_test

run-test: clean-test build-test
	./text_buffer_test


