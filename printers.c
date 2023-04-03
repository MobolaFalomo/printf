#include "main.h"

/**
 * print_char - prints a character
 * @vlist: va_list of args
 *
 * Return: int representing number of characters printed
 * -1 if unsuccessful
 */

int print_char(va_list vlist, char buffer[], unsigned int *buffind)
{
	char ch = va_arg(vlist, int);
	unsigned int len = 0;

	if (ch != '\0')
	{
		buffer[(*buffind)++] = ch;
		len += 1;

		if (*buffind == BUF)
			print_buf(buffer, buffind);
	}

	return (len);
}


/**
 * print_str - prints a string
 * @vlist: va_list of args
 *
 * Return: int representing number of characters printed
 * -1 if unsuccessful
 */

int print_str(va_list vlist, char buffer[], unsigned int *buffind)
{
	char *buf;
	unsigned int len;

	buf = va_arg(vlist, char *);
	if (buf == NULL)
		return (-1);

	for (len = 0; buf[len] != '\0'; len++)
	{
		buffer[(*buffind)++] = buf[len];

		if (*buffind == BUF)
			print_buf(buffer, buffind);
	}

	return (len);
}


/**
 * print_cent - print percent sign
 * @vlist: va_list of args
 *
 * Return: int representing numbeer of characters printed
 */

int print_cent(va_list vlist, char buffer[], unsigned int *buffind)
{
	char buf;
	(void)(vlist);

	buf = '%';

	buffer[(*buffind)++] = buf;

	if (*buffind == BUF)
		print_buf(buffer, buffind);

	return (1);
}
