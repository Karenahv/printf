#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <stdarg.h>

int _putchar(char c);
int _strlen(char *s);
int _printf(const char *format, ...);

/**
 * struct types_arguments - Struct op
 *
 * @t: The operator
 * @f: The function associated
 */
typedef struct types_arguments
{
	char t;
	void (*f)(va_list va);
} types;
#endif
