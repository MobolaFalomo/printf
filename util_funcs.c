#include "main.h"


/**
 * getX - get hex of unsigned int argument
 * @n: number to print as hex
 *
 * Return: char pointer to hex of number n
 */

char *getX(int n)
{
	char *buffer, *hex = "0123456789ABCDEF";
	unsigned int ind = 0, indhex;

	buffer = malloc(sizeof(char) * 5);
	if (buffer == NULL)
	{
		free(buffer);
		return (0);
	}

	if (n < 0)
		n = n * -1;

	buffer[0] = '\\';
	buffer[1] = 'x';
	buffer[2] = n / 16;
	buffer[3] = n % 16;
	buffer[4] = '\0';

	for (ind = 2; ind < 4; ind++)
	{
		indhex = buffer[ind];
		buffer[ind] = hex[indhex];

	}

	return (buffer);
}
