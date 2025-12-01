
clean: 
	rm -f main csvp

build:
	gcc -o csvp main.c csv_parser.c logger.c -Wall


rundata: clean build
	./csvp data.csv -l error

run: clean build
	./csvp


