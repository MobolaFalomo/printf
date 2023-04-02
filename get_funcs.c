#include "main.h"

/**
 * get_flags - get flags from conversion specification
 *
 * @format: string to be formatted
 * @ind: pointer to int specifying possible position of first flag
 *
 * Return: int representing flags present
 */

int get_flags(const char *format, unsigned int *ind)
{
	char strFlags[] = {'#', '0', '-', ' ', '+', '\0'};
	int bitFlags[] = {1, 2, 4, 8, 16}, flags;
	unsigned int x, i;

	i = *ind, flags = 00;
	while (!((format[i] > 48 && format[i] < 58)
		|| (format[i] > 64 && format[i] < 91)
		 || (format[i] > 96 && format[i] < 123)
		 || (format[i] == '.')))
	{
		for (x = 0; strFlags[x] != '\0'; x++)
		{
			if (format[i] == strFlags[x])
			{
				flags |= bitFlags[x];
				break;
			}
		}
		i++;
	}

	*ind = i;
	return (flags);
}


/**
 * get_width - get width from conversion specification
 *
 * @format: string to be formatted
 * @ind: pointer to int specifying possible position of width
 *
 * Return: int representing width
 */

int get_width(const char *format, unsigned int *ind)
{
	int width, tens;
	unsigned int x, len, lencopy;

	len = 0, x = *ind;
	while ((format[x] > 47 && format[x] < 58) && format[x] != '\0')
	{
		len++;
		x++;
	}
	lencopy = len - 1;
	for (tens = 1; lencopy > 0; lencopy--, tens *= 10)
		;

	width = 0, x = *ind;

	for (; len > 0; len--)
	{
		width += tens * (format[x] - 48);
		tens /= 10;
		x++;
	}

	*ind = x;
	return (width);
}


/**
 * get_precision - get precision from conversion specification
 *
 * @format: string to be formatted
 * @ind: pointer to int specifying possible position of precision number
 *
 * Return: int representing width
 */

int get_precision(const char *format, unsigned int *ind)
{
	unsigned int x, len, lencopy;
	int precision, tens;

	x = *ind, precision = 6;
	if (format[x] != 46)
		return (precision);

	precision = 0;

	len = 0, x++;
	/* Find how many digits there are in the number */
	while ((format[x] > 47 && format[x] < 58) && format[x] != '\0')
	{
		len++;
		x++;
	}
	/* Find exponent of 10 to match digits */
	lencopy = len - 1;
	for (tens = 1; lencopy > 0; lencopy--)
		tens *= 10;

	x = *ind;

	/* Get precision in int */
	for (; len > 0; len--)
	{
		precision += tens * (format[x] - 48);
		tens /= 10;
		x++;
	}

	*ind = x;
	return (precision);
}


/**
 * get_size - get size from conversion specifier
 *
 * @format: string to be formatted
 * @ind: pointer to possible position of size specifier
 *
 * Return: char representing size specifier
 */

char get_size(const char *format, unsigned int *ind)
{
	char size;

	(void)(format);
	(void)(ind);
	/* unsigned int x; */

	size = 0;
	return (size);
}
