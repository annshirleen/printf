#include "main.h"

void _print_pointer(void *ptr, flags_t *flags, int l_modifier,int width )
{
    unsigned long value = (unsigned long)ptr;
    _print_integer(value, 16, 0,flags, l_modifier,width);
}
