#include "main.h"

/**
 * _printf - Printf function
 * @format: format.
 * Return: number of characters printed.
 */

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0, len = 0;
	char *str;

	if (!format)
		return (-1);

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;

			if (*format == 'c')
			{
				write(1, format, 1);
				count++;
			}
			if (*format == 's')
			{
				str = va_arg(args, char *);
				while (*str != '\0')
				{
					len++
				}
				write(1, str, len);
				count += len;
			}
			if (*format == '%')
			{
				write(1, format, 2);
				count += 2;
			}

		}
	}
	va_end(args);
	return (count);
}
/**
 * print_buffer - Prints the buffer contenent
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 *void print_buffer(char buffer[], int *buff_ind)
 *{
 *	if (*buff_ind > 0)
 *		write(1, &buffer[0], *buff_ind);
 *
 *	*buff_ind = 0;
 *}
 */
