

#include <stdarg.h>
#include <stdio.h>
#include <time.h>

void fmt_print(char *fmt, ...);

int main(int argc, char *argv[]) {
  fmt_print("int value: %d double value: %f string value: %s", 10, 2.4,
            "Hello World!");
  return 0;
}

void fmt_print(char *fmt, ...) {
  va_list ap;

  char *p, *sval;
  int ival;
  double dval;

  va_start(ap, fmt);

  time_t now = time(NULL);
  struct tm *t = localtime(&now);

  char *info = "[%d-%d-%d %d:%d %d] [INFO] ";
  printf(info, t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour,
         t->tm_min, t->tm_sec);
  // for (; *info; info++) {
  //   if (*info != '\0') {
  //     putchar(*info);
  //   }
  // }
  //
  for (p = fmt; *p; p++) {
    if (*p != '%') {
      putchar(*p);
      continue;
    }
    switch (*++p) {
    case 'd':
      ival = va_arg(ap, int);
      printf("%d", ival);
      break;
    case 'f':
      dval = va_arg(ap, double);
      printf("%f", dval);
      break;
    case 's':
      for (sval = va_arg(ap, char *); *sval; sval++)
        putchar(*sval);
      break;
    default:
      putchar(*p);
      break;
    }
  }

  printf(fmt, ap[0]);

  va_end(ap);
}
