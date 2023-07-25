#include "main.h"
/**
 * print_from_to - prints char addresses
 * @start: start address
 * @stop: end address
 * @except: except address
 * Return: count bytes printed
*/
int print_from_to(char *start, char *stop, char *except)
{
	int sum = 0;

	while (start <= stop)
	{
		if (start != except)
			sum += _putchar(*start);
		start++;
	}
	return (sum);
}

/**
* print_rev - prints string in reverse
* @ap: string
* @params: the parameters struct.
* Return: count bytes printed.
*/
int print_rev(va_list ap, params_t *params)
{
	int len, sum = 0;
	char *str = va_arg(ap, char *);
	(void)params;

	if (str)
	{
		for (len = 0; *str; str++)
			len++;
		str--;
		for (; len > 0; len--, str--)
			sum += _putchar(*str);
	}
	return (sum);
}


/**
 * print_rot13 - prints string in rot13
 * @ap: string
 * @params: the parameters struct.
 * Return: number bytes printed
 */

int print_rot13(va_list ap, params_t *params)
{
	int i, index;
	int count = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM	nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(ap, char *);
	(void)params;

	if (a == NULL)
		return (count);
	i = 0;
	index = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z')
				|| (a[i] >= 'a' && a[i] <= 'z'))
		{
			index = a[i] - 'A';
			count += _putchar(arr[index]);
		}
		else
			count += _putchar(a[i]);
		i++;
	}
	return (count);
}
