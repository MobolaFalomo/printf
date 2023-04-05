#include "main.h"

/**
 * print_int - prints a signed int
 * @vlist: variadic argument list
 *
 * Return: int representing number of chars printed
 */

int print_int(va_list vlist)
{
	int a, expo = 1, len = 0;
	unsigned int n;
	char pr;

	a = va_arg(vlist, int);

	if (a < 0)
	{
		pr = '-';
		len = len + write(1, &pr, 1);
		n = a * -1;
	}
	else
		n = a;
	while (n / expo > 9)
		expo *= 10;

	while (expo != 0)
	{
		pr = n / expo + '0';
		len = len + write(1, &pr, 1);
		n = n % expo;
		expo = expo / 10;
	}
	return (len);
}


/**
 * print_binary - prints an unsigned int in binary
 * @vlist: variadic argument list
 *
 * Return: int representing the number of chars printed
 */

int print_binary(va_list vlist)
{
	int expo = 1, len = 0;
	unsigned int n;
	char pr;

	n = va_arg(vlist, unsigned int);

	while (n / expo > 1)
		expo *= 2;

	while (expo != 0)
	{
		pr = n / expo + '0';
		len = len + write(1, &pr, 1);
		n = n % expo;
		expo = expo / 2;
	}
	return (len);
}
