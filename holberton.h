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
int print_unsigned(va_list va);
int hexa(va_list va);
int hexa_upper(va_list va);
int octal(va_list va);
int print_rot(va_list va);
char *malloc_str(char *str);
char *rot13(char *p);
int print_rev(va_list va);
int hexa_special(unsigned int c);
int stringhexa(va_list va);
int pointer(va_list va);
int hexa_pointer(unsigned long int c);
int _printf(const char *format, ...);

#endif
