#include "../main.h"

int main()
{
	int n = 7653, c = 8972342;
	int count_n, count_c;


	count_n = _printf("%d\n", n);
	count_c = _printf("%d\n", c);


	_printf("Length of n: %d\n", count_n);
	_printf("Length of c: %d\n", count_c);

	return (0);
}
