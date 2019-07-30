#include "holberton.h"

/**
 * print_rev - Entry point
 * @s: pointer the string we want to reverse and print
 *
 * Return: no return
 */
int print_rev(va_list va)
{
	int i;
	char *s;
	char n[] = "(null)";


	s = va_arg(va, char *);
	i = 0;
	if (s == NULL)
	{
		for (i = 0; n[i] != '\0'; i++)
			_putchar(n[i]);
		return (6);
	}
	while (*(s + i) != '\0')
	{
		i++;
	}

	while (i > 0)
	{
		_putchar(*(s + i - 1));
		i--;

	}
	_putchar('\n');
	return (i);
}
