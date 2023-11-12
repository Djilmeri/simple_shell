#include "shell.h"
/**
 * positive_nbr - testing a positive number
 * @string_nbr: The string number
 * Return: it resulte
 */
int positive_nbr(char *string_nbr)
{
	int i;

	if (!string_nbr)
		return (0);
	for (i = 0; string_nbr[0]; i++)
	{
		if (string_nbr[0] < '0' || string_nbr[0] > '9')
			return (0);
	}
	return (1);
}
/**
 * at_oi - fuctio for atio  nbr
 * @string_nbr: string number
 * Return: return number int
 */
int at_oi(char *string_nbr)
{
	int i, nbr = 0;

	for (i = 0; string_nbr[i]; i++)
	{
		nbr *= 10;
		nbr += (string_nbr[i] - '0');
	}
	return (nbr);
}
