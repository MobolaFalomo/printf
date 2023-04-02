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
	/* int precision, width, flags, size, */
	int prints, printed;
	unsigned int ind, x;
	char buffer[BUF];

	printed = ind = x = 0;
	va_start(vlist, format);
	while (format && format[x] != '\0')
	{

		if (format[x] != '%')
		{
			buffer[ind++] = format[x];

			if (ind == BUF - 1)
				print_buf(buffer, &ind);

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
			if (prints < 0)
				return (-1);
			printed += prints;
		}
		x++;
	}
	va_end(vlist);
	print_buf(buffer, &ind);

	return (printed);
}


/**
 * print_buf - call write for an array of chars
 *
 * @buffer: array of chars to be printed
 * @ind: pointer to int representing the number of bytes to be printed
 *
 * Return: void
 */

void print_buf(char buffer[], unsigned int *ind)
{
	if (*ind > 0)
		write(1, buffer, *ind);

	*ind = 0;
}


/**
 * conv_handler - handles conversion specifiers
 *
 * @vlist: va_list
 * @format: string to be formatted
 * @ind: location of conversion specifier
 *
 * Return: number of printed characters
 * -1 if unsuccessful
 */

int conv_handler(va_list vlist, const char *format, unsigned int *ind
		 , char buffer[], unsigned int *buffind)
{
	convs convert[] = {
		{'c', print_char}, {'s', print_str}, {'%', print_cent}
		, {'\0', 0}
	};
	int c, prints;

	(*ind)++;
	for (c = 0; convert[c].ch != '\0'; c++)
	{
		if (format[*ind] == convert[c].ch)
		{
			prints = convert[c].func(vlist, buffer, buffind);
			return (prints);
		}
	}
	return (-1);
}
