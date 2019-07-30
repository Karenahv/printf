#include "holberton.h"

/**
*print_rot - Print a string in rot13
*@va: va_list arguments
*Return: string
*/

int print_rot(va_list va)
{

	char *s;
	int i;
	char n[] = "(null)";

	s = rot13(malloc_str(va_arg(va, char *)));
	if (s == NULL)
	{
		for (i = 0; n[i] != '\0'; i++)
			_putchar(n[i]);
		return (6);
	}
	for (i = 0; s[i] != '\0'; i++)
		_putchar(s[i]);
	free(s);
	return (i);
}

/**
*malloc_str - create a new space in memory to copy the string
*@str: string
*Return: string
*/

char *malloc_str(char *str)
{
	char *copy;
	unsigned int j, i;

	if (str ==  NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		;
	copy = malloc((i + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	for (j = 0; j <= i; j++)
		copy[j] = str[j];
	return (copy);
}

/**
 *rot13 - String to rot13
 *@p: pointer the string we want to convert in rot13
 *Return: string
 */
char *rot13(char *p)
{
	int j;
	int i;
	char a1[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"};
	char a2[] = {"NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm"};

	for (j = 0; p[j] != '\0'; j++)
	{
		for (i = 0; a1[i] != '\0'; i++)
		{
			if (p[j] == a1[i])
			{
				p[j] = a2[i];
				break;
			}
		}
	}
	return (p);
}
