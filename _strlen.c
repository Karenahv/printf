#include "holberton.h"

/**
 * _strnlen - print an integer
 *@s:string
 *
 * Return: the length of a string
 */

int _strlen(char *s)
{

	int len;

	len = 0;
	while (*s != '\0')
	{
		len++;
		s++;
	}
	return(len - 1);
}
