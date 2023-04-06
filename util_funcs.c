#include "main.h"


/**
 * getX - get hex of unsigned int argument
 * @n: number to print as hex
 *
 * Return: char pointer to hex of number n
 */

char *getX(unsigned int n)
{
	char pr, *buffer = malloc(sizeof(char) * 3);
	unsigned int ind = 0;

	buffer[0] = n / 16;
	buffer[1] = n % 16;
	buffer[2] = '\0';

	for (ind = 0; buffer[ind] != '\0'; ind++)
	{
		if (buffer[ind] > 9)
		{
			switch (buffer[ind] - 9)
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
			pr = buffer[ind] + '0';
		buffer[ind] = pr;
	}

	return (buffer);
}
