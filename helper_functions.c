#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * _putchar - returns address
 * @c: the character address to return
 *
 * Return: the address to write to the screen
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_s - prints the string to the console
 * @list: list of variables
 *
 * Return: length of the string, s
 */
int print_s(va_list list)
{
	char *s;
	int counter = 0;

	s = va_arg(list, char *);
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*s != '\0')
	{
		write(1, &(*s), 1);
		++s;
		++counter;
	}
	return (counter);
}
/**
 * print_c - prints the character to the console
 * @list: list of arguments being passed
 *
 * Return: length of the character, 1
 */
int print_c(va_list list)
{
	char c;

	c = va_arg(list, int);
	if (c == '\0')
	{
		c = ' ';
		write(1, &c, 1);
	}
	else
		write(1, &c, 1);

	return (1);
}

/**
 * print_d - converts each number to a string, then prints
 * to the console
 * @list: list of arguments
 *
 * Return: length of the number
 */
int print_d(va_list list)
{
	int number, numlength, mul, length;
	unsigned int number_copy, number_copy2;

	number = va_arg(list, int);
	mul = 1;
	numlength = 1;
	/* edge cases for number */
	if (number < 0)
	{
		write(1, "-", 1);
		number_copy = -1 * number;
		number_copy2 = number_copy;
	}
	else if (number > 0)
	{
		number_copy = number;
		number_copy2 = number;
	}

	while (number_copy >= 10)
	{
		number_copy /= 10;
		mul *= 10;
		++numlength;
	}
	if (number < 0)
		length = numlength + 1;
	else
		length = numlength;
	while (numlength > 1)
	{
		if ((number_copy2 / mul) < 10)
			_putchar((number_copy2 / mul + '0'));
		else
			_putchar(((number_copy2 / mul) % 10) + '0');
		--numlength;
		mul /= 10;
	}
	_putchar(number_copy2 % 10 + '0');
	return (length);
}
/**
 * _strlen - returns the length of the string in the parameter
 * @list: list of arguments
 *
 * Return: length of a string
 */
int _strlen(va_list list)
{
	int counter, i;
	char *s;

	s = va_arg(list, char *);

	i = 0;
	counter = 0;
	while (s[i] != '\0')
		++counter;

	return (counter);

}
