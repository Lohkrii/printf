#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * print_r - prints the string in reverse to the console
 * @list: list of variables
 *
 * Return: length of the string, counter
 */
int print_r(va_list list)
{
	char *s;
	int counter, length;

	s = va_arg(list, char *);
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}

	counter = 0;
	length = 0;
	for (counter = 0; s[counter] != '\0'; counter++)
		;
	for (counter = (counter - 1); counter >= 0; counter--)
	{
		write(1, &s[counter], 1);
		++length;
	}

	return (length);
}
