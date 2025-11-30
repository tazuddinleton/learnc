

#include "csv_parser.h"
#include "logger.h"
#include <stdio.h>
int main(int argc, char *argv[]) {

	set_current_log_level(LOG_LEVEL_INFO);
	log_info("trying to read the data.csv\n");

	ParseResult *result = parse_csv("data.csv");

	for (int i = 0; i < result->length; i++) {
		printf("%s\n", result->data[i]);
	}

	return 0;
}
