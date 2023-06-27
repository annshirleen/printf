#include "main.h"

void _print_string(const char *str)
{
	char buffer[BUFFER_SIZE];
	char *buffer_ptr = buffer;
	int count = 0;
	
	while (*str != '\0')
	{
		if (*str < 32 || *str >= 127)
		{
			*buffer_ptr = '\\';
			buffer_ptr++;
			*buffer_ptr = 'x';
			buffer_ptr++;
			*buffer_ptr = (*str >> 4) < 10 ? (*str >> 4) + '0' : (*str >> 4) + 'A' - 10;
			buffer_ptr++;
			*buffer_ptr = (*str & 0x0F) < 10 ? (*str & 0x0F) + '0' : (*str & 0x0F) + 'A' - 10;
			buffer_ptr++;
			count += 4;
		}
		else
		{
			*buffer_ptr = *str;
			buffer_ptr++;
			count++;
		}
		str++;
		if (count >= BUFFER_SIZE - 1)
		{
			write(STDOUT_FILENO, buffer, BUFFER_SIZE);
			buffer_ptr = buffer;
			count = 0;
		}
	}
	if (count > 0)
	{
		write(STDOUT_FILENO, buffer, count);
	}
}
