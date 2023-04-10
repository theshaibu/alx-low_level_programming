#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0
 * at a given index.
 *
 * @n: pointer to an unsigned long int.
 * @index: index of the bit to clear.
 *
 * Return: 1 if it worked, -1 if an error occurred.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
    unsigned int bit_mask;

    if (index > 63)
        return (-1);

    bit_mask = 1 << index;

    if (*n & bit_mask)
        *n ^= bit_mask;

    return (1);
}

