#include <stdarg.h>
#include <stdio.h>
#include "holberton.h"

/**
 * hexa_special - print a
 *@c:unsigned integer input
 *
 * Return: no return
 */
int hexa_special(unsigned int c)
{
	int  i, j, temp;
	int arr[100];

	i = 0;
	temp = 0;
	if (c == 0)
	{
		_putchar('0');
		return (1);
	}
	while (c != 0)
	{
		temp = c % 16;
		if (temp < 10)
			arr[i] = 48 + temp;
		else
			arr[i] = 55 + temp;
		c = c / 16;
		i++;
	}
	for (j = i - 1; j >= 0; j--)
		_putchar(arr[j]);
	return (i);
}
