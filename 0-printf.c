
#include "holberton.h"
/**
 * _printf - prints the format to the console
 * @format: string being passed to the function
 *
 * Return: length of the format
 */
int _printf(const char *format, ...)
{
	int i, j, buff_length, length;
	va_list list;
	string_flags s_flags[] = {
		{"c", print_c},
		{"s", print_s},
		{"d", print_d},
		{"i", print_d},
		{"r", print_r},
		{NULL, NULL}
	};

	va_start(list, format);
	i = 0;
	buff_length = 0;
	while (format && format[i] != '\0')
	{
		/* look for special character flag */
		if (format[i] == '%')
		{
			++i;
			j = 0;
			length = 0;
			while (s_flags[j].f != NULL)
			{
				while (format[i] == ' ')
					++i;

				/* if character after % is a string or character */
				if (format[i] == *(s_flags[j].s))
				{
					length = s_flags[j].f(list);
					buff_length += length;
					break;
				}

				if (format[i] == '%')
				{
					write(1, &format[i], 1);
					++buff_length;
					break;
				}
				++j;
			}
		}
		/* print normal character from format */
		else
		{
			write(1, &format[i], 1);
			buff_length += 1;
		}
		++i;
	}
	va_end(list);
	return (buff_length);
}
