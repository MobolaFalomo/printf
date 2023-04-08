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

	buffer = malloc(sizeof(char) * 3);
	if (buffer == NULL)
	{
		free(buffer);
		return (0);
	}

	if (n < 0)
		n = n * -1;

	buffer[0] = n / 16;
	buffer[1] = n % 16;
	buffer[2] = '\0';
	for (ind = 0; ind < 2; ind++)
	{
		indhex = buffer[ind];
		buffer[ind] = hex[indhex];

	}

	return (buffer);
}
