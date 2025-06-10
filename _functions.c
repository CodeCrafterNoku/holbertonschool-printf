#include "main.h"
#include <unistd.h> /* For write */

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_int - Prints an integer
 * @args: List of arguments
 * Return: Number of characters printed
 */
int print_int(va_list args)
{
	int n = va_arg(args, int);
	int count = 0;
	unsigned int num; /* Use unsigned for operations to avoid overflow with INT_MIN */
	int divisor = 1;

	if (n < 0)
	{
		count += _putchar('-');
		num = -n; /* Convert to positive unsigned */
	}
	else
	{
		num = n;
	}

	/* Handle the 0 case specifically */
	if (num == 0)
	{
		count += _putchar('0');
		return (count);
	}

	/* Calculate the correct divisor for the most significant digit */
	while (num / divisor > 9)
	{
		divisor *= 10;
	}

	while (divisor >= 1)
	{
		count += _putchar(((num / divisor) % 10) + '0');
		divisor /= 10;
	}

	return (count);
}
