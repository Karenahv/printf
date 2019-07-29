#include <stdarg.h>
#include <stdio.h>
#include "holberton.h"
#define BUFFERSIZE 1024

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

	if (s == NULL)
	{
		for (i = 0; n[i] != '\0'; i++)
			_putchar(n[i]);
		return;
	}
	for (j = 0; s[j] != '\0'; j++)
		_putchar(s[j]);
}
/**
 * print_number - Entry point
 *@n: the integer to print
 * Return: no return
 */
void print_number(va_list va)
{

	char l;
	int r;
	char d;
	int n = va_arg(va, int);

	if (n < 0)
	{
		_putchar('-');
		l = ('0' - (n % 10));
		n /= -10;
	} else
	{
		l = ((n % 10) + '0');
		n /= 10;
	}
	r = 0;
	while (n > 0)
	{
		r = r * 10 + (n % 10);
		n /= 10;
	}

	while (r > 0)
	{
		d = ((r % 10) + '0');
		_putchar (d);
		r /= 10;
	}
	_putchar(l);
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
		{'d', print_number},
		{'i', print_number},
		{'b', binary},
	};

	i = 0;
	if (format == NULL)
		return (-1);

	va_start(valist, format);
	len = _strlen((char *)format);
	while (format != NULL && format[i])
	{
		if (format[i] != '%')
			_putchar(format[i]);
		else
		{
			i++;
			if(format[i] == '%')
				_putchar(format[i]);
			j = 0;
			while (j < 6)
			{
				if (format[i] == difftypes[j].t)
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
	return (len);
}
