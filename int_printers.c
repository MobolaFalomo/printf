#include "main.h"

/**
 * print_int - prints a signed int
 * @vlist: variadic argument list
 *
 * Return: int representing number of chars printed
 */

int print_int(va_list vlist)
{
	int digits, tens = 1, num = va_arg(vlist, int), abs_num, chars;
	char ch = '-';

	if (num < 0)
		abs_num = num * -1;
	else
		abs_num = num;

	for (digits = 1; abs_num > 10; digits++, tens *= 10)
		abs_num /= 10;

	if (num < 0)
	{
		write(1, &ch, 1);
		chars = digits + 1;
		num *= -1;
	} else
		chars = digits;

	for (; digits > 0; digits--)
	{
		ch = (num / tens) + 48;
		num %= tens;
		tens /= 10;

		write(1, &ch, 1);
	}

	return (chars);
}
