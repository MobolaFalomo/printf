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

	write(1, &ch, 1);

	return (1);
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
	int ind, count = 0;

	buf = va_arg(vlist, char *);
	if (buf == NULL)
		buf = "(null)";

	for (ind = 0; buf[ind] != '\0'; ind++)
	{
		write(1, &buf[ind], 1);
		count++;
	}
	return (count);
}


/**
 * print_cent - print percent sign
 * @vlist: va_list of args
 *
 * Return: int representing numbeer of characters printed
 */

int print_cent(va_list vlist)
{
	char *buf;
	(void)(vlist);

	buf = "%%";

	write(1, buf, 1);

	return (1);
}
