#include <stdarg.h>
#include <stdio.h>
#include "holberton.h"

/**
 * binary - print a binary number
 *@va:unsigned integer input
 *
 * Return: no return
 */
int binary(va_list va)
{
	unsigned int c;
	int  i, j;
	int arr[100];

	c = va_arg(va, int);
	i = 0;
	if (c == 0)
		_putchar('0');
	while (c > 0)
	{
		arr[i] = c % 2;
		c = c / 2;
		i++;
	}
	for (j = i - 1; j >= 0; j--)
		_putchar(arr[j] + '0');
	return (i);
}
