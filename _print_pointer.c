#include "main.h"
/**
 * _print_pointer - Print Numbers
 * @ptr: pointer
 * @flags:flags
 * @l_modifier:modifier
 * @width:width
 */
void _print_pointer(void *ptr, flags_t *flags, int l_modifier,int width )
{
    unsigned long value = (unsigned long)ptr;
    _print_integer(value, 16, 0,flags, l_modifier,width);
}
