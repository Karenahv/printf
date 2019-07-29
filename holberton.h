#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

/**
* struct types_arguments - Struct op
*
* @t: The operator
* @f: The function associated
*/
typedef struct types_arguments
{
	char t;
	int (*f)(va_list va);
} types;
int _putchar(char c);
int _strlen(char *s);
int print_number(va_list va);
int binary(va_list va);
int _printf(const char *format, ...);

#endif
