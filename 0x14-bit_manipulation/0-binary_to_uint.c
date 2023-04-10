/**
 * binary_to_uint - converts a binary number to an unsigned int.
 * @binary: string containing binary number
 *
 * Return: unsigned int of converted binary number or 0 if fails.
 */
unsigned int binary_to_uint(const char *binary)
{
	unsigned int uint = 0, base_two = 1;
	int length = 0;

	if (!binary)
		return (0);

	while (binary[length] != '\0')
		length++;

	for (length--, base_two = 1; length >= 0; length--, base_two *= 2)
	{
		if (binary[length] != '0' && binary[length] != '1')
		{
			return (0);
		}

		if (binary[length] & 1)
		{
			uint += base_two;
		}
	}

	return (uint);
}

