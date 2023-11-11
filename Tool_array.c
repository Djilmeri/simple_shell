#include "shell.h"
/**
 * array_string - function of array
 * @array: array string
 * Return: Alwayse 0.
 */
void array_string(char **array)
{
	int i;

	if (array == NULL)
	return;
	for (i = 0; array[i]; i++)
	{
		free(array[i]);
		array[i] = NULL;
		}
		free(array);
		array = NULL;
}
/**
 * print_ero - fuction of write errors
 * @name: The name of command
 * @command: User's command
 * @index: The number of command
 * Retur: Void
 */
void print_ero(char *name, char *command, int index)
{
	char *idx, msg[] = ": not found";

	idx = _it_oa(index);

	write(STDERR_FILENO, name, string_line(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, idx, string_line(idx));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, string_line(command));
	write(STDERR_FILENO, msg, string_line(msg));

	free(idx);
}
/**
 * _it_oa - function of convert int varibal to char varibal
 * @n: The n val
 * Return: char
 */
char *_it_oa(int n)
{
	char buf[20];
	int i = 0;

	if (n == 0)
		buf[i++] = '0';
	else
	{
		while (n > 0)
		{
			buf[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	buf[i] = '\0';
	inverse_string(buf, i);
	return (string_dupl(buf));
}
/**
 * inverse_string - The function for reverse the string
 * @string: The user's string
 * @car: direction of string
 * Return: void
 */
void inverse_string(char *string, int car)
{
	char tp;
	int star = 0;
	int end_car = car - 1;

	while (star < end_car)
	{
		tp = string[star];
		string[star] = string[end_car];
		string[end_car] = tp;
		star++;
		end_car--;
	}
}
