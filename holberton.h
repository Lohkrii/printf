#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int _putchar(char c);

int _printf(const char *format, ...);

int _strlen(va_list list);

int print_s(va_list list);

int print_c(va_list list);

int print_d(va_list list);

int print_r(va_list list);

typedef struct string_flags
{
	char *s;
	int (*f)(va_list list);
} string_flags;

#endif /* _HOLBERTON_H_ */
