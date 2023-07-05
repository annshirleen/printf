#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

#define BUFFER_SIZE 1024
/**
 * struct flags - struct containing flags
 * @plus: flag for the '+' character
 * @space: flag for the ' ' character
 * @hash: flag for the '#' character
 */

typedef struct flags
{
	int plus;
	int space;
	int hash;
} flags_t;

int _putchar(char c);
int _printf(const char *format, ...);
int _print_str(va_list args);
int _print_cent(void);
int _print_chr(va_list args);
int _strlen(char *s);
int _strlenc(const char *s);
int _print_dec(va_list args);
int _print_int(va_list args);
int _print_binary(va_list args);
int _print_unsigned(va_list args);
int _print_oct(va_list args);
int _print_hex(va_list args);
int _print_HEX(va_list args);
int _print_excl_str(va_list args);
int _print_HEX_aux(unsigned int num);
int _print_ptr(va_list args);
int _print_hex_excl(unsigned long int num);
int _print_str_rev(va_list args);
int _print_rot13(va_list args);

#endif
