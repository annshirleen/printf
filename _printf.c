#include "main.h"

/**
 * _printf -
 */

int _printf(const char *format, ...)
{
	flags_t flags = {0, 0, 0};
	va_list args;
	int count  = 0;
	int l_modifier = 0;
	int width = 0;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			while (*format == '+' || *format == ' ' || *format == '#')
		       	{
			       	switch (*format)
				{
				case '+':
					flags.plus = 1;
					break;
				case ' ':
					flags.space = 1;
					break;
				case '#':
					flags.hash = 1;
					break;
				}
				format++;
			}
			if (*format == 'l' || *format == 'h')
			{
				l_modifier = *format;
				format++;
			}
			switch (*format)
			{
				 case 'b':
					 {
						 unsigned int num = va_arg(args, unsigned int);
						 _print_binary(num);
						 count += sizeof(unsigned int) * 8;
					 }
					 break;
				case 'c':
					{
						int c = va_arg(args, int);

						_putchar(c);
						count++;
					}
					break;
				case 's':
					{
						const char *s = va_arg(args, const char *);

						while (*s != '\0')
						{
							_putchar(*s);
							s++;
							count++;
						}
					}
					break;
				case '%':
					_putchar('%');
					count++;
					break;
				case 'u':
					{
						unsigned int num = va_arg(args, unsigned int);
						_print_integer(num, 10, 0,&flags,l_modifier, width);
						count += sizeof(unsigned int) * 8;
					}
					break;
				case 'o':
					{
						unsigned int num = va_arg(args, unsigned int);
						_print_integer(num, 8, 0,&flags,l_modifier, width);
						count += sizeof(unsigned int) * 3;
					}
					break;
				case 'd':
					{
						unsigned int num = va_arg(args, unsigned int);
						_print_integer(num, 16, 0,&flags,l_modifier, width);
						count += sizeof(unsigned int) * 2;
					}
					break;
				case 'i':
					{
						unsigned int num = va_arg(args, unsigned int);
						_print_integer(num, 16, 1,&flags,l_modifier, width);
						count += sizeof(unsigned int) * 2;
					}
					break;
				case 'x':
					{
						unsigned int num = va_arg(args, unsigned int);
						_print_integer(num, 16, 0,&flags,l_modifier, width);
						count += sizeof(unsigned int) * 2;
					}
					break;
				case 'X':
					{
						unsigned int num = va_arg(args, unsigned int);
						_print_integer(num, 16, 1,&flags,l_modifier, width);
						count += sizeof(unsigned int) * 2; 
					}
					break;
				case 'S':
					{
						const char *str = va_arg(args, const char *);
						_print_string(str);
					}
					break;
				case 'p':
					{
						void *ptr = va_arg(args, void *);
						_print_pointer(ptr, &flags,l_modifier,width);
						count += sizeof(void *) * 2;
					}
					break;

			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);

}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
