

#include "logger.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <time.h>

#define RESET "\x1b[0m"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"

/*Very simple logger implementation, to use with my csv parser project.*/
/**
 *

#define WHITE "\x1b[37m"
*/

char *color[] = {};

/*Indicates current log level, default is LOG_LEVEL_INFO*/
LOG_LEVEL current_log_level = LOG_LEVEL_INFO;

void print_prefix(char *log_level) {
	time_t now = time(NULL);
	struct tm *t = localtime(&now);

	char *info = "[%d-%d-%d %d:%d %d] %s ";
	printf(info, t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour,
		   t->tm_min, t->tm_sec, log_level);
}

/*Prints messages with format specifier and variable arguments*/
void print_message(char *msg, va_list ap) { vprintf(msg, ap); }

/*Allows user to set up current log level*/
void set_current_log_level(LOG_LEVEL level) { current_log_level = level; };

void log_trace(char *msg, ...) {
	if (current_log_level == LOG_LEVEL_TRACE) {
		char *log_level = CYAN "[TRACE] " RESET;
		print_prefix(log_level);
		va_list ap;
		va_start(ap, msg);
		print_message(msg, ap);
		va_end(ap);
	}
}

void log_debug(char *msg, ...) {
	if (current_log_level <= LOG_LEVEL_DEBUG) {
		char *log_level = CYAN "[DBG] " RESET;
		print_prefix(log_level);
		va_list ap;
		va_start(ap, msg);
		print_message(msg, ap);
		va_end(ap);
	}
}
void log_info(char *msg, ...) {

	if (current_log_level <= LOG_LEVEL_INFO) {
		char *log_level = GREEN "[INF] " RESET;
		print_prefix(log_level);
		va_list ap;
		va_start(ap, msg);
		print_message(msg, ap);
		va_end(ap);
	}
}

void log_warn(char *msg, ...) {
	if (current_log_level <= LOG_LEVEL_WARNING) {
		char *log_level = YELLOW "[WARN] " RESET;
		print_prefix(log_level);
		va_list ap;
		va_start(ap, msg);
		print_message(msg, ap);
		va_end(ap);
	}
}
void log_error(char *msg, ...) {
	if (current_log_level <= LOG_LEVEL_ERROR) {
		char *log_level = RED "[ERR] " RESET;
		print_prefix(log_level);
		va_list ap;
		va_start(ap, msg);
		print_message(msg, ap);
		va_end(ap);
	}
}
void log_fatal(char *msg, ...) {
	if (current_log_level <= LOG_LEVEL_FATAL) {
		char *log_level = MAGENTA "[FATAL] " RESET;
		print_prefix(log_level);
		va_list ap;
		va_start(ap, msg);
		print_message(msg, ap);
		va_end(ap);
	}
}
