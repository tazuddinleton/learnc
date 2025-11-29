

#include "csv_parser.h"
#include "logger.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * [ ] Read the file line by line and print it
 * [ ] Split a line by comma
 *
 * */

ParseResult *parse_csv(char *path) {
	if (path == NULL) {
		log_error("provide a valid path");
		exit(EXIT_FAILURE);
	}

	log_info("openning the file '%s'\n", path);

	FILE *f = fopen(path, "r");

	if (!f) {
		perror("cannot open data.csv\n");
		exit(EXIT_FAILURE);
	}

	ParseResult *parse_result = ParseResult_new();

	ParseResult_add_line("hello", parse_result);
	ParseResult_add_line("world", parse_result);
	ParseResult_add_line("!", parse_result);

	log_info("returning parse result\n");

	return parse_result;
}

ParseResult *ParseResult_new() {
	log_info("initializing parse result object\n");
	ParseResult *result = malloc(sizeof(ParseResult));
	result->data = malloc(sizeof(char **));
	result->length = 0;

	log_info("allocated\n");
	return result;
}

void ParseResult_add_line(char *line, ParseResult *result) {
	log_info("adding a line to ParseResult\n");
	int index = result->length;
	result->data[index] = line;
	result->length++;
	log_info("added line.\n");
}

char *get_line(char buff[MAX_READ_BUFFER]) {

	char *line;
	int idx = 0;
	while (buff[idx] != '\n' || idx < strlen(buff)) {
		idx++;
	}

	return line;
}
