#include <stdarg.h>
#include <stdio.h>
#include "holberton.h"

/**
 * t_char - print a character
 *@va:character
 *
 * Return: no return
 */
void t_char(va_list va)
{
	int c;

	c = va_arg(va, int);
	_putchar(c);
}
/**
 * t_string - print a string
 *@va: pointer to string
 *
 * Return: no return
 */
void t_string(va_list va)
{
	int j, i;
	char n[] = "(null)";
	char *s = va_arg(va, char *);
	j = 0;
	if (s == NULL)
	{
		for (i = 0; n[i] != '0'; i++)
			_putchar(n[i]);
		return;
	}
	for (j = 0; s[j] != '\0'; j++)
		_putchar(s[j]);
}
/**
 * _printf - print output according to a format
 *@format: first argument
 *
 * Return: the number of characters printed(excluding the null byte)
 */
int _printf(const char *format, ...)
{
	int i, j, len;
	va_list valist;
	types difftypes[] = {
		{'c', t_char},
		{'s', t_string},
	};

	i = 0;
	va_start(valist, format);
	len = _strlen((char *)format);
	while (format != NULL && format[i])
	{
		if (format[i] != '%' && format[i - 1] != '%')
			_putchar(format[i]);
		else
		{
			j = 0;
			while (j < 2)
			{
				if (format[i + 1] == difftypes[j].t)
				{
					difftypes[j].f(valist);
					break;
				}
				j++;
			}
		}
		i++;
	}
	va_end(valist);
	return(len);
}
