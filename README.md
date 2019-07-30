## 0x11. C - printf

This project is for replicate the C standard library printf() function

What you should learn from this project:

- Applying variadic functions
- The complexities of printf function
- How to use git in a team setting
- Hoe to work in a team


Printf function with  the printing features of characters (c), strings (s), % (%), octales (0), hexadecimals ( x and X). We also did a 
binary function (b)

We create a mini function printf like that of the C language, we document with the book the secrets of printf.
We use the putchar function of the syscall writer function. and we work with data structures,
with a structure called from the holberton.h


- All codes will be compiled this way: gcc -Wall -Werror -Wextra -pedantic *.c


file   |   Description
--|--
holberton.h | A file for call to prototypes and structurs
_putchar.c | A file for call to syscall (writer)  putchar print  in _printf
_printf.c | A file  for call base structur from holberton.h
binary.c | A file for print binary numbers
hexa.c | A file for print hexa numbers
man_3_printf | A file man type for printf function
octales.c | A file for print octals numbers
rot13.c | A file for print encripted numbers in rot13
unsig_num.c | A file for print unsigned numbers
rev_string.c | A file for print string in reverse

## Prototype
``` int _printf(const char *format, ...);```

## Usage
* Prints a string to the standard output, according to a given format
* ALl files were created and compiled on Ubuntu 14.04.4 LTS USING  GCC 4.8.4 with the command ```gcc -Wall -Werror -Wextra -Pedantic *.c```
All files were linted for syntax and style with [Betty][https://github.com/holbertonschool/Betty)
* Returns the number of characteres in the output string on succes, -1 otherwise
* Call it this way: ```_printf("format string", arguments...)```where format string``` can contain conversion specifiers and flags, alog with regular characteres






Special thanks to  peers cohort 9:
* @JuanSGalvisH
* @luischaparroc
* @alzheimeer
* @edward0rtiz
* @Dr2d4





### Authors
* **Karen Herrera** - @karena_herrera
* **Carlos ALvarez** - @charlyhackr