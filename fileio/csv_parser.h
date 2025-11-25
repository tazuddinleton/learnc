#ifndef CSV_PARSER_H
#define CSV_PARSER_H

#define MAX_READ_BUFFER 64

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int length;
  char **data;
} ParseResult;

ParseResult *ParseResult_new();

void ParseResult_add_line(char *line, ParseResult *result);

ParseResult *parse_csv(char *path);

#endif // !CSV_PARSER_H __CSV_PARSER_H
