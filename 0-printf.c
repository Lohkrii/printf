#include "holberton.h"

/**
 * write - substitute for printf
 * @n: length of string
 * Return: number of chars printed
 */

int _printf(const char *format, ...)
{
	int n;

	write(1, *format, n)
	return (n);
}
