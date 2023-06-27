#include "main.h"

/**
 * _print_integer - Print Numbers
 * @num: Number
 * @base:base
 * @uppercase:uppercase
 * @flags:flags
 * @l_modifier:modifier
 * @width:width
 * Return: number of char printed
 */
void _print_integer(unsigned int num, int base, int uppercase, flags_t *flags, int l_modifier, int width)
{

	if (l_modifier == 'l')
	{
		long int l_num = (long int)num;
		_print_formatted_integer(l_num, base, uppercase, flags,width);
	}
	else if (l_modifier == 'h')
	{
		short int h_num = (short int)num;
		_print_formatted_integer(h_num, base, uppercase, flags,width);
	}
	else
	{
		_print_formatted_integer(num, base, uppercase, flags,width);
	}
}

/**
 * _print_formatted_integer - Print Numbers
 * @num: Number
 * @base:base
 * @uppercase:uppercase
 * @flags:flags
 * @width:width
 * Return: number of char printed
 */
void _print_formatted_integer(unsigned long int num, int base, int uppercase, flags_t *flags, int width)
{
	char buffer[sizeof(unsigned long int) * 8 + 1];
	char digits[] = "0123456789abcdef";
	int index = sizeof(buffer) - 1;
	int n2 = num;
	int num_digits = sizeof(buffer) - index - 1;
	int padding = width - num_digits;
	
	if (flags->plus && n2 >= 0)
	{
		_putchar('+');
	}
	else if (flags->space && n2 >= 0)
	{
		_putchar(' ');
	}
	
	if (n2 == 0)
	{
		_putchar('0');
		return;
	}
	if (uppercase)
	{
		digits[10] = 'A';
	}
	buffer[index] = '\0';
	while (n2 > 0)
	{
		buffer[--index] = digits[n2 % base];
		n2 /= base;
	}
	while (padding > 0)
	{
		_putchar(' ');
		padding--;
	}
	while (buffer[index] != '\0')
	{
		_putchar(buffer[index]);
		index++;
	}
}
