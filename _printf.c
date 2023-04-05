#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: character string composed of zero or more directives.
 *
 * Return: the number of characters printed, excluding the terminating null
 */

int _printf(const char *format, ...)
{
	int i, j;
	int count = 0;
	va_list lst;
	convs ids[] = {
		{'c', print_char},
		{'s', print_str},
		{'i', print_int},
		{'d', print_int},
		{'%', print_cent},
		{'\0', NULL}
	};

	va_start(lst, format);
	for (i = 0; format[i]; i++)
		if (format[i] == '%')
		{
			i++;
			for (; format[i] != '\0'; i++)
			{
				for (j = 0; ids[j].id != '\0'; j++)
					if (format[i] == ids[j].id)
					{
						count += ids[j].func(lst);
						break;
					}
				if (ids[j].id)
					break;
			}
			if (format[i] == '\0')
				return (-1);
		}
		else
		{
			write(1, &format[i], 1);
			count += 1;
		}

	va_end(lst);
	return (count);
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

int conv_handler(va_list vlist, const char *format, unsigned int *ind)
{
	convs convert[] = {
		{'c', print_char}, {'s', print_str}, {'%', print_cent},
		{'d', print_int}, {'i', print_int}, {'\0', 0}
	};
	int c, prints = -1;

	(*ind)++;
	if (format[*ind] == '\0')
		return (-1);

	for (c = 0; convert[c].id != '\0'; c++)
	{
		if (format[*ind] == convert[c].id)
		{
			prints = convert[c].func(vlist);
			break;
		}
	}

	if (!convert[c].id)
	{
		write(1, &format[*ind], 1);
		prints *= -1;
	}
	return (prints);
}
