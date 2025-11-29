

#include "logger.h"
#include <stdarg.h>
#include <stdio.h>
#include <time.h>

LOG_LEVEL current_log_level = LOG_LEVEL_INFO;

void print_prefix(char *log_level) {

  time_t now = time(NULL);
  struct tm *t = localtime(&now);

  char *info = "[%d-%d-%d %d:%d %d] %s ";
  printf(info, t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour,
         t->tm_min, t->tm_sec, log_level);
}

void print_message(char *fmt, ...) {

  va_list ap;
  va_start(ap, fmt);
  char *p, *sval;
  int ival;
  double dval;

  for (p = fmt; *p; p++) {
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

void set_current_log_level(LOG_LEVEL level) {
  printf("setting up current_log_level: %d\n", level);
  current_log_level = level;
};

void log_trace(char *msg, ...) {
  if (current_log_level == LOG_LEVEL_TRACE) {
    printf("[TRACE] [time] %s\n", msg);
  }
}

void log_debug(char *msg, ...) {
  if (current_log_level <= LOG_LEVEL_DEBUG) {
    printf("[DBG] [time] %s\n", msg);
  }
}
void log_info(char *fmt, ...) {

  if (current_log_level <= LOG_LEVEL_INFO) {
    char *log_level = "[INF] ";
    print_prefix(log_level);
    va_list ap;
    va_start(ap, fmt);
    print_message(fmt, ap);
    va_end(ap);
  }
}

void log_warn(char *msg, ...) {
  if (current_log_level <= LOG_LEVEL_WARNING) {
    printf("[WARN] [time] %s\n", msg);
  }
}
void log_error(char *msg, ...) {
  if (current_log_level <= LOG_LEVEL_ERROR) {
    printf("[ERR] [time] %s\n", msg);
  }
}
void log_fatal(char *msg, ...) {
  if (current_log_level <= LOG_LEVEL_FATAL) {
    printf("[FATAL] [time] %s\n", msg);
  }
}
