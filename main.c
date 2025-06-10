#include "main.h"
#include <stdio.h>

/**
 * main - Entry point
 * Return: Always 0
 */
int main(void)
{
	int len1, len2;

	_printf("Hello, %s!\n", "world");
	printf("Hello, %s!\n", "world");

	_printf("Character: %c\n", 'A');
	printf("Character: %c\n", 'A');

	_printf("String: %s\n", "This is a string");
	printf("String: %s\n", "This is a string");

	_printf("Percent sign: %%\n");
	printf("Percent sign: %%\n");

	len1 = _printf("Integer: %d\n", 12345);
	len2 = printf("Integer: %d\n", 12345);
	printf("My _printf returned: %d\n", len1);
	printf("Standard printf returned: %d\n", len2);

	len1 = _printf("Negative integer: %i\n", -987);
	len2 = printf("Negative integer: %i\n", -987);
	printf("My _printf returned: %d\n", len1);
	printf("Standard printf returned: %d\n", len2);

	len1 = _printf("Zero: %d\n", 0);
	len2 = printf("Zero: %d\n", 0);
	printf("My _printf returned: %d\n", len1);
	printf("Standard printf returned: %d\n", len2);

	return (0);
}
