#include "main.h"

/**
 * print_char - prints a character
 *
 * @vlist: va_list of args
 * @buffer: pointer to local buffer
 * @buffind: pointer to next available location in buffer
 *
 * Return: int representing number of characters printed
 * -1 if unsuccessful
 */

int print_char(va_list vlist, char buffer[], unsigned int *buffind)
{
	char ch = va_arg(vlist, int);

	buff_handler(ch, buffer, buffind);

	return (1);
}


/**
 * print_str - prints a string
 *
 * @vlist: va_list of args
 * @buffer: pointer to local buffer
 * @buffind: pointer to next available location in buffer
 *
 * Return: int representing number of characters printed
 * -1 if unsuccessful
 */

int print_str(va_list vlist, char buffer[], unsigned int *buffind)
{
	int ind, count = 0;
	char *buf = va_arg(vlist, char *);

	if (buf == NULL)
		buf = "(null)";

	for (ind = 0; buf[ind] != '\0'; ind++)
	{
		buff_handler(buf[ind], buffer, buffind);
		count++;
	}
	return (count);
}


/**
 * print_cent - print percent sign
 *
 * @vlist: va_list of args
 * @buffer: pointer to local buffer
 * @buffind: pointer to next available location in buffer
 *
 * Return: int representing numbeer of characters printed
 */

int print_cent(va_list vlist, char buffer[], unsigned int *buffind)
{
	char buf = '%';
	(void)(vlist);

	buff_handler(buf, buffer, buffind);

	return (1);
}


/**
 * print_Str - print string with representation for non printable characters
 *
 * @vlist: va_list of args
 * @buffer: pointer to local buffer
 * @buffind: pointer to next available location in buffer
 *
 * Return: int representing numbeer of characters printed
 */

int print_Str(va_list vlist, char buffer[], unsigned int *buffind)
{
	int count = 0;
	unsigned int ind, indhex;
	char *hex, *buf = va_arg(vlist, char *);

	if (buf == NULL)
		buf = "(null)";

	for (ind = 0; buf[ind] != '\0'; ind++)
	{
		if (buf[ind] < 32 || buf[ind] >= 127)
		{
			hex = getX(buf[ind]);
			if (hex == NULL)
			{
				return (-1);
				free(hex);
			}

			buff_handler('\\', buffer, buffind);
			buff_handler('x', buffer, buffind);
			for (indhex = 0; hex[indhex] != '\0'; indhex++)
				buff_handler(hex[indhex], buffer, buffind);

			free(hex);
			count += 3;
		} else
			count += buff_handler(buf[ind], buffer, buffind);
	}
	return (count);
}
