

#include "csv_parser.h"
#include "logger.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * [x] Read the file line by line and print it
 * [] Split a line by comma and create list of columns
 *
 * */
char *get_line(FILE *f);

ParseResult *parse_csv(char *path) {
	if (path == NULL) {
		log_error("provide a valid path");
		exit(EXIT_FAILURE);
	}

	log_info("openning the file '%s'\n", path);

	FILE *f = fopen(path, "r");

	if (!f) {
		log_error("cannot open %s\n", path);
		exit(EXIT_FAILURE);
	}

	ParseResult *parse_result = ParseResult_new();

	char *line;
	while ((line = get_line(f)) != NULL) {
		log_info("got a line, adding it to result : %s\n", line);
		/* Todo: Split the line by comma and build list of columns */
		ParseResult_add_line(line, parse_result);
	}

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

char *get_line(FILE *f) {
	size_t buff_size = 64;
	log_debug("buff_size: %lu\n", buff_size);

	char *buff = malloc(sizeof(char *) * buff_size);
	int ch, rc /*rc keeps track number of time realloc occured*/, idx = 0;

	while ((ch = fgetc(f)) != EOF) {
		if (ch == '\n') {
			log_debug("a line is found, returning to calleer: %s\n", buff);
			return buff;
		}

		/* Check if buffer is filled up and need a reallocation */
		if (idx == buff_size - 1) {
			log_debug(
				"buffer full, reallocating by doubling the current size %lu\n",
				buff_size);
			rc++;
			buff_size = 2 * buff_size;
			char *new_buff = realloc(buff, buff_size);
			if (new_buff == NULL) {
				log_error("reallocation failed, returning whatever is in "
						  "current buffer");
				return buff;
			}
			buff = new_buff;
		}
		buff[idx] = (char)ch;
		idx++;
	}

	log_debug("the buffer: %s\n", buff);

	log_debug("buff_size: %lu\n", buff_size);
	log_debug("total read: %d\n", idx);
	log_debug("total reallocation: %d\n", rc);
	return NULL;
}
