

#include <stdarg.h>
#include <stdio.h>

void fmt_print(char *fmt, ...);

int main() {
	size_t size = 1234;
	fmt_print(
		"int value: %d double value: %f string value: %s  size_t value: %zu\n",
		10, 2.4, "Hello World!", size);
	return 0;
}

void fmt_print(char *fmt, ...) {
	va_list ap;

	va_start(ap, fmt);
	vprintf(fmt, ap);

	// for (p = fmt; *p; p++) {
	// 	if (*p != '%') {
	// 		putchar(*p);
	// 		continue;
	// 	}
	// 	switch (*++p) {
	// 	case 'd':
	// 		ival = va_arg(ap, int);
	// 		printf("%d", ival);
	// 		break;
	// 	case 'f':
	// 		dval = va_arg(ap, double);
	// 		printf("%f", dval);
	// 		break;
	// 	case 's':
	// 		for (sval = va_arg(ap, char *); *sval; sval++)
	// 			putchar(*sval);
	// 		break;
	// 	default:
	// 		putchar(*p);
	// 		break;
	// 	}
	// }
	//
	va_end(ap);
}
