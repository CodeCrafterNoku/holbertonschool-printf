#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * print_char - Prints a character
 * @args: List of arguments
 * Return: Number of characters printed (1)
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	return (write(1, &c, 1));
}

/**
 * print_string - Prints a string
 * @args: List of arguments
 * Return: Number of characters printed
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int i = 0;

	if (str == NULL)
		str = "(null)";

	while (str[i])
		i++;

	return (write(1, str, i));
}

/**
 * print_percent - Prints a percent sign
 * @args: List of arguments (unused)
 * Return: Number of characters printed (1)
 */
int print_percent(va_list args)
{
	(void)args;
	return (write(1, "%", 1));
}

/**
 * _printf - Produces output according to a format
 * @format: Character string containing the format
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0, j;
	int (*func)(va_list);

	format_t formats[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'\0', NULL}
	};

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (-1);

			func = NULL;
			for (j = 0; formats[j].spec != '\0'; j++)
			{
				if (format[i] == formats[j].spec)
				{
					func = formats[j].func;
					break;
				}
			}

			if (func != NULL)
				count += func(args);
			else
			{
				count += write(1, &format[i - 1], 1);
				count += write(1, &format[i], 1);
			}
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}

	va_end(args);
	return (count);
}
