
clean: 
	rm -f main csvp

build:
	gcc -o csvp main.c csv_parser.c logger.c -Wall


run-dummydata: clean build
	./csvp data.csv -l debug

run-findata: clean build
	./csvp fin_survey.csv -l trace

run: clean build
	./csvp


