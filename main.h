#include <stdarg.h>

int _printf(const char *format, ...);

char *stringify(int n);

int formatter(const char *format, va_list args);
