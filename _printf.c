#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: character string composed of zero or more directives.
 *
 * Return: the number of characters printed, excluding the terminating null
 */

int _printf(const char *format, ...)
{
	va_list vlist;
	int prints, printed = 0;
	unsigned int x = 0, ind = 0;
	char buffer[BUF];

	if (!format)
		return (-1);
	va_start(vlist, format);
	while (format && format[x] != '\0')
	{

		if (format[x] != '%')
		{
			buff_handler(format[x], buffer, &ind);
			printed += 1;
		} else
		{
			/**
			 *flags = get_flags(format, &x);
			 *width = get_width(format, &x);
			 *precision = get_precision(format, &x);
			 *size = get_size(format, &x);
			*/
			prints = conv_handler(vlist, format, &x, buffer, &ind);
			if (prints == -1)
			{
				va_end(vlist);
				return (-1);
			}
			printed += prints;
		}
		x++;
	}
	va_end(vlist);

	if (ind)
		write(1, buffer, ind);
	return (printed);
}


/**
 * buff_handler - call write for an array of chars
 *
 * @ch: char to add to buffer
 * @buffer: array of chars to be printed
 * @ind: pointer to int representing the number of bytes to be printed
 *
 * Return: void
 */

int buff_handler(char ch, char buffer[], unsigned int *ind)
{
	buffer[(*ind)++] = ch;
	if (*ind == BUF)
	{
		write(1, buffer, *ind);
		*ind = 0;
	}

	return (1);
}


/**
 * conv_handler - handles conversion specifiers
 *
 * @vlist: va_list
 * @format: string to be formatted
 * @ind: location of conversion specifier
 * @buffer: pointer to local buffer
 * @buffind: pointer to next available location in buffer
 *
 * Return: number of printed characters
 * -1 if unsuccessful
 */

int conv_handler(va_list vlist, const char *format, unsigned int *ind
		 , char buffer[], unsigned int *buffind)
{
	convs convert[] = {
		{'c', print_char}, {'s', print_str}, {'%', print_cent},
		{'d', print_int}, {'i', print_int}, {'b', print_binary},
		{'o', print_octal}, {'u', print_dec}, {'x', print_x},
		{'X', print_X}, {'S', print_Str}, {'\0', 0}
	};
	int c, prints;
	(*ind)++;

	if (format[*ind] == '\0')
		return (-1);

	for (c = 0; convert[c].ch != '\0'; c++)
	{
		if (format[*ind] == convert[c].ch)
		{
			prints = convert[c].func(vlist, buffer, buffind);
			break;
		}
	}

	if (!convert[c].ch)
	{
		prints = print_cent(vlist, buffer, buffind);
		buff_handler(format[*ind], buffer, buffind);
		prints += 1;
	}

	return (prints);
}
