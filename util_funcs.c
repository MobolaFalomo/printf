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
	unsigned int ind = 0, indhex, abs;

	buffer = malloc(sizeof(char) * 3);
	if ((buffer == NULL) || (n > 255))
	{
		free(buffer);
		return (0);
	}

	if (n < 0)
		abs = n * -1;
	else
		abs = n;

	buffer[0] = abs / 16;
	buffer[1] = abs % 16;
	buffer[2] = '\0';
	for (ind = 0; ind < 2; ind++)
	{
		indhex = buffer[ind];
		buffer[ind] = hex[indhex];

	}

	return (buffer);
}
