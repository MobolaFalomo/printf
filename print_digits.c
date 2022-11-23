#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

char *stringify(int n);
int formatter(const char *format, va_list args);

/**
 * _printf - outputs formatted text to terminal
 * @format: format string
 *
 * Return: int
 *
 */

int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	formatter(format, args);

	va_end(args);
	return (0);
}

/**
 * stringify - turn numbers to string
 * @n: number to be turned
 *
 * Return: int
 *
 */

char *stringify(int n)
{
	int digit, misc, power = 0;
	char *s;
	char m = '-';

	if (n < 0)
	{
		write(1, &m, 1);
		n *= -1;
	}

	misc = n;
	while ((misc / 10) >= 10)
	{
		power++;
		misc /= 10;
	}

	s = malloc(sizeof(char) * (power + 2));
	if (s == NULL)
	{
		free(s);
		_printf("Malloc Error\n");
		return (NULL);
	}

	misc = 0;
        while (n)
	{
		digit = n % 10;
		s[misc++] = digit + 48;
		n /= 10;
	}
	s[misc] = '\0';

	return (s);
}

/**
 * formatter - format specifier for _printf
 *
 * @format: string to print
 * @args: list of args to _printf
 *
 * Return: 0 if successful
 *
 */

int formatter(const char *format, va_list args)
{
	int c, state = 0;
	char *s;

	while (*format)
	{
		if (state == 0)
		{
			if (*format == '%')
			{
				state = 1;
			}
			else
				write(1, format, 1);
		}
		else
		{
			switch (*format)
			{
			case 'i':
			{
				c = va_arg(args, int);
				s = stringify(c);
				break;
			}
			case 'd':
			{
				c = va_arg(args, int);
				s = stringify(c);
				break;
			}
			default:
			{
				c = *format;
				write(1, &c, 1);
			}
			}

			while (*s)
			{
				write(1, s, 1);
				s++;
			}
			state = 0;
		}

		format++;
	}
	return (0);
}
