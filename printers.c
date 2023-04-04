#include "main.h"

/**
 * print_char - prints a character
 * @vlist: va_list of args
 *
 * Return: int representing number of characters printed
 * -1 if unsuccessful
 */

int print_char(va_list vlist)
{
	char ch = va_arg(vlist, int);

	if (ch)
	{
		write(1, &ch, 1);
		return (1);
	}

	return (0);
}


/**
 * print_str - prints a string
 * @vlist: va_list of args
 *
 * Return: int representing number of characters printed
 * -1 if unsuccessful
 */

int print_str(va_list vlist)
{
	char *buf;
	int len;

	buf = va_arg(vlist, char *);
	if (buf == NULL)
		buf = "(null)";

	for (len = 0; buf[len] != '\0'; len++)
		write(1, &buf[len], 1);

	return (len);
}


/**
 * print_cent - print percent sign
 * @vlist: va_list of args
 *
 * Return: int representing numbeer of characters printed
 */

int print_cent(va_list vlist)
{
	char buf;
	(void)(vlist);

	buf = '%';

	write(1, &buf, 1);

	return (1);
}
