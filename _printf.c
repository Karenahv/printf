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
	int i, j;
	char n[] = "(null)";
	char *s = va_arg(va, char *);

	if (s == NULL)
	{
		for (i = 0; n[i] != '\0'; i++)
			_putchar(n[i]);
		return (6);
	}
	for (j = 0; s[j] != '\0'; j++)
		_putchar(s[j]);
	return (j);
}
/**
 * print_number - Entry point
 *@va: the integer to print
 * Return: no return
 */
int print_number(va_list va)
{
	int i, len, r, l;
	unsigned int abs, num, numt;
	int n = va_arg(va, int);

	len = 0;
	i = 0;
	r = 1;
	l = 1;
	if (n < 0)
	{
		_putchar('-');
		len++;
		abs = -n;
	} else
	{
		abs = n;
	}

	num = abs;
	while (num > 0)
	{
		num /= 10;
		i++;
	}

	while (r < i)
	{
		l *= 10;
		r++;
	}
	while (l >= 1)
	{
		numt = (abs / l) % 10;
		_putchar(numt + '0');
		len++;
		l /= 10;
	}
	return (len);
}

/**
 * _printf - print output according to a format
 *@format: first argument
 *
 * Return: the number of characters printed(excluding the null byte)
 */
int _printf(const char *format, ...)
{
	int i = 0, j, len = 0, count;
	va_list valist;
	types difftypes[] = {{'c', t_char}, {'s', t_string}, {'d', print_number},
			     {'i', print_number}, {'b', binary}, {'u', print_unsigned},
			     {'x', hexa}, {'X', hexa_upper}, {'o', octal}, {'R', print_rot},
			     {'r', print_rev}, {'S', stringhexa}};

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
			while (j < 12)
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
				len++;
				_putchar('%');
				_putchar(format[i]); }}
		i++; }
	va_end(valist);
	return (len);
}
