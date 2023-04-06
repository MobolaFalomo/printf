#include "main.h"

/**
 * print_octal - print octal of unsigned int argument
 *
 * @vlist: variadic list of arguments
 * @buffer: pointer to local buffer
 * @buffind: pointer to next available location in buffer
 *
 * Return: int representing number of chars printed
 */

int print_octal(va_list vlist, char buffer[], unsigned int *buffind)
{
	int len = 0;
	unsigned int n, expo = 1;
	char pr;

	n = va_arg(vlist, unsigned int);

	while (n / expo > 7)
		expo *= 8;

	while (expo != 0)
	{
		pr = n / expo + '0';
		len = len + buff_handler(pr, buffer, buffind);
		n = n % expo;
		expo = expo / 8;
	}
	return (len);
}


/**
 * print_dec - print dec of unsigned int argument
 *
 * @vlist: variadic list of arguments
 * @buffer: pointer to local buffer
 * @buffind: pointer to next available location in buffer
 *
 * Return: int representing number of chars printed
 */

int print_dec(va_list vlist, char buffer[], unsigned int *buffind)
{
	int len = 0;
	unsigned int n, expo = 1;
	char pr;

	n = va_arg(vlist, unsigned int);

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
 * print_x - print hex of unsigned int argument
 *
 * @vlist: variadic list of arguments
 * @buffer: pointer to local buffer
 * @buffind: pointer to next available location in buffer
 *
 * Return: int representing number of chars printed
 */

int print_x(va_list vlist, char buffer[], unsigned int *buffind)
{
	int len = 0;
	char pr;
	unsigned int expo = 1, buf, n = va_arg(vlist, unsigned int);

	while (n / expo > 15)
		expo *= 16;

	for (; expo != 0; expo /= 16)
	{
		buf = n / expo;
		if (buf > 9)
		{
			switch (buf - 9)
			{
			case 1:
				pr = 'a';
				break;
			case 2:
				pr = 'b';
				break;
			case 3:
				pr = 'c';
				break;
			case 4:
				pr = 'd';
				break;
			case 5:
				pr = 'e';
				break;
			case 6:
				pr = 'f';
				break;
			}
		} else
			pr = buf + '0';
		len = len + buff_handler(pr, buffer, buffind);
		n = n % expo;
	}
	return (len);
}


/**
 * print_X - print hex of unsigned int argument
 *
 * @vlist: variadic list of arguments
 * @buffer: pointer to local buffer
 * @buffind: pointer to next available location in buffer
 *
 * Return: int representing number of chars printed
 */

int print_X(va_list vlist, char buffer[], unsigned int *buffind)
{
	int len = 0;
	char pr;
	unsigned int expo = 1, buf, n = va_arg(vlist, unsigned int);

	while (n / expo > 15)
		expo *= 16;

	for (; expo != 0; expo /= 16)
	{
		buf = n / expo;
		if (buf > 9)
		{
			switch (buf - 9)
			{
			case 1:
				pr = 'A';
				break;
			case 2:
				pr = 'B';
				break;
			case 3:
				pr = 'C';
				break;
			case 4:
				pr = 'D';
				break;
			case 5:
				pr = 'E';
				break;
			case 6:
				pr = 'F';
				break;
			}
		} else
			pr = buf + '0';
		len = len + buff_handler(pr, buffer, buffind);
		n = n % expo;
	}
	return (len);
}
