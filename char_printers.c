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
	unsigned int i = 0;
	int printed = 0;
	char *str = va_arg(vlist, char *);

	if (str == NULL)
		str = "(null)";

	while (str[i] != '\0')
	{
		if (str[i] > 31 && str[i] < 127)
		{
			printed += buff_handler(str[i], buffer, buffind);
			if (str[i] == 92)
			{
				if (str[i + 1] == 'x')
				{
					buff_handler(str[i], buffer, buffind);
					i++;
				}
			}
		} else
			printed += getX(str[i], buffer, buffind);

		i++;
	}

	return (printed);
}
