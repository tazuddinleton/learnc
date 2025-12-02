

#include "csv_parser.h"
#include "logger.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cmd_args {
	char *file_path;
	LOG_LEVEL loglevel;
} CmdArgs;

void print_usage() {

	printf("Usage: csvp <filepath> [-l loglevel]\n");
	printf("Options: \n");
	printf("	-l <level>	Set log level i.e. trace, debug, info, warn, "
		   "error, fatal");
}

/*Todo: Implement a robust cmd flag parser*/
CmdArgs *parse_cmd(int argc, char *argv[]) {
	if (argc < 2) {
		print_usage();
		return NULL;
	}

	if (strcmp(argv[2], "-l") == 0 && argc != 4) {
		printf("No argument was provided to -l\n\n");
		print_usage();
		return NULL;
	}

	CmdArgs *cmd_args = malloc(sizeof(CmdArgs));
	cmd_args->file_path = argv[1];

	if (argc == 4 && strcmp(argv[2], "-l") == 0) {

		char *flag = argv[3];

		if (strcmp(flag, "trace") == 0) {
			cmd_args->loglevel = LOG_LEVEL_TRACE;
		} else if (strcmp(flag, "debug") == 0) {
			cmd_args->loglevel = LOG_LEVEL_DEBUG;
		} else if (strcmp(flag, "info") == 0) {
			cmd_args->loglevel = LOG_LEVEL_INFO;
		} else if (strcmp(flag, "warn") == 0) {
			cmd_args->loglevel = LOG_LEVEL_WARNING;
		} else if (strcmp(flag, "error") == 0) {
			cmd_args->loglevel = LOG_LEVEL_ERROR;
		} else if (strcmp(flag, "error") == 0) {
			cmd_args->loglevel = LOG_LEVEL_FATAL;
		} else {
			printf("Unknown argument: %s\n\n", flag);
			print_usage();
			return NULL;
		}
	}
	return cmd_args;
}

int main(int argc, char *argv[]) {

	CmdArgs *cmd_args = parse_cmd(argc, argv);
	if (cmd_args == NULL) {
		return 1;
	}
	set_current_log_level(cmd_args->loglevel);

	ParseResult *result = parse_csv(cmd_args->file_path);

	for (int i = 0; i < result->length; i++) {
		printf("%s\n", result->data[i]);
	}

	return 0;
}
