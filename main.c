#include "main.h"
#include <stdio.h>

/**
 * main - Entry point
 * Return: Always 0
 */
int main(void)
{
    int len1, len2;
    
    len1 = _printf("Hello, %s!\n", "world");
    len2 = printf("Hello, %s!\n", "world");
    
    printf("My _printf returned: %d\n", len1);
    printf("Standard printf returned: %d\n", len2);
    
    _printf("Character: %c\n", 'A');
    _printf("String: %s\n", "This is a string");
    _printf("Percent sign: %%\n");
    
    return (0);
}
