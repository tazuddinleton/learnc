

#include "logger.h"
#include <stdio.h>

LOG_LEVEL current_log_level = LOG_LEVEL_INFO;

void set_current_log_level(LOG_LEVEL level) {
  printf("setting up current_log_level: %d\n", level);
  current_log_level = level;
};

void log_trace(char *msg) {
  if (current_log_level == LOG_LEVEL_TRACE) {
    printf("[TRACE] [time] %s\n", msg);
  }
}

void log_debug(char *msg) {
  if (current_log_level <= LOG_LEVEL_DEBUG) {
    printf("[DBG] [time] %s\n", msg);
  }
}
void log_info(char *msg) {
  if (current_log_level <= LOG_LEVEL_INFO) {
    printf("[INF] [time] %s\n", msg);
  }
}
void log_warn(char *msg) {
  if (current_log_level <= LOG_LEVEL_WARNING) {
    printf("[WARN] [time] %s\n", msg);
  }
}
void log_error(char *msg) {
  if (current_log_level <= LOG_LEVEL_ERROR) {
    printf("[ERR] [time] %s\n", msg);
  }
}
void log_fatal(char *msg) {
  if (current_log_level <= LOG_LEVEL_FATAL) {
    printf("[FATAL] [time] %s\n", msg);
  }
}
