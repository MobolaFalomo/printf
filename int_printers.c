#include "main.h"

/**
 * print_int - prints a signed int
 *
 * @vlist: variadic argument list
 * @buffer: pointer to local buffer
 * @buffind: pointer to next available location in buffer
 *
 * Return: int representing number of chars printed
 */

int print_int(va_list vlist, char buffer[], unsigned int *buffind)
{
	int a, expo = 1, len = 0;
	unsigned int n;
	char pr;

	a = va_arg(vlist, int);

	if (a < 0)
	{
		pr = '-';
		len += buff_handler(pr, buffer, buffind);
		n = a * -1;
	}
	else
		n = a;
	while (n / expo > 9)
		expo *= 10;

	while (expo != 0)
	{
		pr = n / expo + '0';
		len = len + buff_handler(pr, buffer, buffind);
		n = n % expo;
		expo = expo / 10;
	}
	return (len);
}


/**
 * print_binary - prints an unsigned int in binary
 *
 * @vlist: variadic argument list
 * @buffer: pointer to local buffer
 * @buffind: pointer to next available location in buffer
 *
 * Return: int representing the number of chars printed
 */

int print_binary(va_list vlist, char buffer[], unsigned int *buffind)
{
	int len = 0;
	unsigned int n, expo = 1;
	char pr;

	n = va_arg(vlist, unsigned int);

	while (n / expo > 1)
		expo *= 2;

	while (expo != 0)
	{
		pr = n / expo + '0';
		len = len + buff_handler(pr, buffer, buffind);
		n = n % expo;
		expo = expo / 2;
	}
	return (len);
}
