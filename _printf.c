#include "holberton.h"

/**
 * t_char - print a character
 *@va:character
 *
 * Return: no return
 */
int t_char(va_list va)
{
	int c;

	c = va_arg(va, int);
	_putchar(c);
	return (1);
}
/**
 * t_string - print a string
 *@va: pointer to string
 *
 * Return: no return
 */
int t_string(va_list va)
{
	int i;
	char n[] = "(null)";
	char *s = va_arg(va, char *);

	if (s == NULL)
	{
		for (i = 0; n[i] != '\0'; i++)
		{
			_putchar(n[i]);
		}
	} else
	{
		for (i = 0; s[i] != '\0'; i++)
			_putchar(s[i]);
	}
	return (i);
}
/**
 * print_number - Entry point
 *@va: the integer to print
 * Return: no return
 */
int print_number(va_list va)
{

	char l;
	int r, len;
	char d;
	int n = va_arg(va, int);

	len = 0;
	if (n < 0)
	{
		_putchar('-');
		l = ('0' - (n % 10));
		n /= -10;
		len++;
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
		len++;
	}

	while (r > 0)
	{
		d = ((r % 10) + '0');
		_putchar (d);
		r /= 10;
	}
	_putchar(l);
	return (len + 1);
}

/**
 * _printf - print output according to a format
 *@format: first argument
 *
 * Return: the number of characters printed(excluding the null byte)
 */
int _printf(const char *format, ...)
{
	int i, j, len, count;
	va_list valist;
	types difftypes[] = {{'c', t_char}, {'s', t_string}, {'d', print_number},
			     {'i', print_number}, {'b', binary}};

	i = 0;
	len = 0;
	if (format == NULL || (format[0] == '%' && format[1] == 0))
		return (-1);
	va_start(valist, format);
	while (format != NULL && format[i])
	{
		if (format[i] != '%')
			len += _putchar(format[i]);
		else
		{
			i++;
			if (format[i] == '%')
				len += _putchar('%');
			j = 0;
			count = 0;
			while (j < 6)
			{
				if (format[i] == difftypes[j].t)
				{
					len += difftypes[j].f(valist);
					count = 1;
					break; }
				j++; }
			if (!count && format[i] != '%')
			{
				len++;
				_putchar('%');
				_putchar(format[i]); }}
		i++; }
	va_end(valist);
	return (len);
}
