

#include "logger.h"
#include <stdarg.h>
#include <stdio.h>
#include <time.h>

/*Very simple logger implementation, to use with my csv parser project.*/

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
void print_message(char *msg, ...) {
	va_list ap;
	va_start(ap, msg);
	char *p, *sval;
	int ival;
	double dval;

	for (p = msg; *p; p++) {
		if (*p != '%') {
			putchar(*p);
			continue;
		}
		switch (*++p) {
		case 'd':
			ival = va_arg(ap, int);
			putchar(ival);
			break;

		case 'f':
			dval = va_arg(ap, int);
			putchar(dval);
			break;
		case 's':
			for (sval = va_arg(ap, char *); *sval; sval++)
				putchar(*sval);
			break;
		default:
			break;
		}
	}
	va_end(ap);
}

/*Allows user to set up current log level*/
void set_current_log_level(LOG_LEVEL level) { current_log_level = level; };

void log_trace(char *msg, ...) {
	if (current_log_level == LOG_LEVEL_TRACE) {
		char *log_level = "[TRACE] ";
		print_prefix(log_level);
		va_list ap;
		va_start(ap, msg);
		print_message(msg, ap);
		va_end(ap);
	}
}

void log_debug(char *msg, ...) {
	if (current_log_level <= LOG_LEVEL_DEBUG) {
		char *log_level = "[DBG] ";
		print_prefix(log_level);
		va_list ap;
		va_start(ap, msg);
		print_message(msg, ap);
		va_end(ap);
	}
}
void log_info(char *msg, ...) {

	if (current_log_level <= LOG_LEVEL_INFO) {
		char *log_level = "[INF] ";
		print_prefix(log_level);
		va_list ap;
		va_start(ap, msg);
		print_message(msg, ap);
		va_end(ap);
	}
}

void log_warn(char *msg, ...) {
	if (current_log_level <= LOG_LEVEL_WARNING) {
		char *log_level = "[WARN] ";
		print_prefix(log_level);
		va_list ap;
		va_start(ap, msg);
		print_message(msg, ap);
		va_end(ap);
	}
}
void log_error(char *msg, ...) {
	if (current_log_level <= LOG_LEVEL_ERROR) {
		char *log_level = "[ERR] ";
		print_prefix(log_level);
		va_list ap;
		va_start(ap, msg);
		print_message(msg, ap);
		va_end(ap);
	}
}
void log_fatal(char *msg, ...) {
	if (current_log_level <= LOG_LEVEL_FATAL) {
		char *log_level = "[FATAL] ";
		print_prefix(log_level);
		va_list ap;
		va_start(ap, msg);
		print_message(msg, ap);
		va_end(ap);
	}
}
