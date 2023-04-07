#include "main.h"


/**
 * getX - get hex of unsigned int argument
 * @n: number to print as hex
 *
 * Return: char pointer to hex of number n
 */

char *getX(unsigned int n)
{
	char *buffer = malloc(sizeof(char) * 3), *hex = "0123456789ABCDEF";
	unsigned int ind = 0, indhex;

	if (buffer == NULL)
	{
		free(buffer);
		return (0);
	}
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
