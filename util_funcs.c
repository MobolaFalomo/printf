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
	unsigned int expo = 1, buf, ind = 0;

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
		buffer[ind++] = pr;
		n = n % expo;
	}
	buffer[ind] = '\0';
	return (buffer);
}
