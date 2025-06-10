#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/**
 * struct format - Struct for format specifiers
 * @spec: The specifier character
 * @func: The function to handle the specifier
 */
typedef struct format
{
	char spec;
	int (*func)(va_list);
} format_t;

int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);

#endif /* MAIN_H */
