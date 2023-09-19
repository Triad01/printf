#include "main.h"
#include <stdio.h>


/**
 * print_binary - Print an unsigned int as binary
 * @n: The unsigned int to print
 *
 * Return: The number of characters printed
 */
int print_binary(unsigned int n)
{
	int count = 0;
	int binary[32];
	int i = 0;

	if (n == 0)
	{
		write(1, "0", 1);
		return 1;
	}

	while (n > 0)
	{
		binary[i] = n % 2;
		n /= 2;
		i++;
	}

	for (i--; i >= 0; i--)
	{
		char c = binary[i] + '0';
		write(1, &c, 1);
		count++;
	}

	return count;
}
