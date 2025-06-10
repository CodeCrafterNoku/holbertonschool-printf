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

int _putchar(char c); /* Added for _putchar */
int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_int(va_list args);
int (*get_print_func(char spec))(va_list);

#endif /* MAIN_H */
