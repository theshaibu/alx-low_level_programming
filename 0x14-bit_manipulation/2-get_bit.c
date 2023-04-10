#include "main.h"

/**
 * get_bit - Returns the value of a bit at a given index
 *
 * @n: unsigned long int input
 * @index: index of the bit
 *
 * Return: Value of the bit at index or -1 if an error occurred
 */
int get_bit(unsigned long int n, unsigned int index)
{
    unsigned int i;

    if (index > 63)  /* Check if index is larger than max index */
        return (-1);

    for (i = 0; i <= 63; n >>= 1, i++)
    {
        if (index == i)
        {
            return (n & 1);  /* Mask the last bit and return it */
        }
    }

    return (-1);  /* If the loop finished, an error occurred */
}

