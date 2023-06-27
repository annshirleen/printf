#include "main.h"

void _print_binary(unsigned int num)
{
	int bits[sizeof(unsigned int) * 8];
	int index = 0;
	int i;

	if (num == 0)
	{
		_putchar('0');
		return;
	}
	while (num > 0)
	{
		bits[index++] = num % 2;
		num /= 2;
	}
	for (i = index - 1; i >= 0; i--)
	{
		_putchar(bits[i] + '0');
	}
}
