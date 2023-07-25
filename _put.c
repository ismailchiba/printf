#include "main.h"
/**
 * _puts - printf a string
 * @str: the string
 *
 * Return: void
 */
int _puts(char *str)
{
	char *start = str;/*the beginning of the string*/

	while (*str)
		_putchar(*str++);
	return (str - start);/*the lenght of the string*/
}
/**
 * _putchar - writes the character c
 * @c: the character to print
 *
 * Return: On success 1,on error -1
 */
int _putchar(int c)
{
	static int i;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || i >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
