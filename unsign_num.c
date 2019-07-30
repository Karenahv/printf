#include "holberton.h"

/**
 * print_unsigned - Entry point
 *@va: the unsigned integer  to print
 * Return: no return
 */
int print_unsigned(va_list va)
{
	int i, len, r, l;
	long int  num, numt;
	unsigned int n = va_arg(va, unsigned int);

	len = 0;
	i = 0;
	r = 1;
	l = 1;
	num = n;
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
		numt = (n / l) % 10;
		_putchar(numt + '0');
		len++;
		l /= 10;
	}
	return (len);
}
