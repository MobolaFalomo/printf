#include "main.h"


/**
 * getX - get hex of unsigned int argument
 *
 * @n: number to print as hex
 * @buffer: buffer handling
 * @buffind: empty buffer location
 *
 * Return: char pointer to hex of number n
 */

int getX(char ascii_code, char buffer[], unsigned int *buffind)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buff_handler('\\', buffer, buffind);
	buff_handler('x', buffer, buffind);

	buff_handler(map_to[ascii_code / 16], buffer, buffind);
	buff_handler(map_to[ascii_code % 16], buffer, buffind);

	return (3);
}
