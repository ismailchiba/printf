#include "main.h"

/**
 * _printf - prints anything
 * @format: the format string
 *
 * Return: number of bytes printed
 */
int _printf(const char *format, ...)
{
	int count = 0;/*counter count number of characters printe*/
	va_list args;
	char *c, *start;
	params_t params = PARAMS_INIT;/*init by zero al elements*/

	va_start(args, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (c = (char *)format; *c; c++)
	{
		init_params(&params, args);
		if (*c != '%')
		{
			count += _putchar(*c);
			continue;
		}
		start = c;
		c++;
		while (get_flags(c, &params))/*check flags*/
		{
			c++;/*next char*/
		}
		c = get_width(c, &params, args);
		c = get_precision(c, &params, args);
		if (get_modifier(c, &params))
			c++;
		if (!get_specifier(c, &params))
			count += printf_from_to(start, c,
			params.l_modifier || params.h_modifier ? c - 1 : 0);
		else
			count += get_print_func(c, args, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(args);
	return (count);
}
