

#include <stdio.h>
#include <time.h>

void log_msg(char *msg, ...) {}

int main(int argc, char *argv[]) {

  time_t now = time(NULL);
  struct tm *t = localtime(&now);

  printf("current time (YY-MM-DD HH:mm:ss): %d-%d-%d %d:%d:%d\n",
         t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min,
         t->tm_sec);

  return 0;
}
