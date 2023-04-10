#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int.
 * @binary: pointer to binary string.
 *
 * Return: the converted unsigned int or 0 if there is an error.
 */
unsigned int binary_to_uint(const char *binary)
{
	unsigned int result = 0;
	int len, base_two;

	if (!binary)
		return (0);

	for (len = 0; binary[len] != '\0'; len++)
		;

	for (len--, base_two = 1; len >= 0; len--, base_two *= 2)
	{
		if (binary[len] != '0' && binary[len] != '1')
			return (0);

		if (binary[len] & 1)
			result += base_two;
	}

	return (result);
}

/**
 * print_binary - prints the binary representation of a number.
 * @n: unsigned long int.
 *
 * Return: no return.
 */
void print_binary(unsigned long int n)
{
	if (n >> 0)
	{
		if (n >> 1)
			print_binary(n >> 1);
		_putchar((n & 1) + '0');
	}
	else
	{
		_putchar('0');
	}
}

