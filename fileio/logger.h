

#ifndef LOGGER_H
#define LOGGER_H

typedef enum {
  LOG_LEVEL_TRACE = 0,
  LOG_LEVEL_DEBUG,
  LOG_LEVEL_INFO,
  LOG_LEVEL_WARNING,
  LOG_LEVEL_ERROR,
  LOG_LEVEL_FATAL
} LOG_LEVEL;

void set_current_log_level(LOG_LEVEL level);
void log_debug(char *fmt, ...);
void log_trace(char *fmt, ...);
void log_warn(char *fmt, ...);
void log_info(char *fmt, ...);
void log_error(char *fmt, ...);
void log_fatal(char *fmt, ...);

#endif
