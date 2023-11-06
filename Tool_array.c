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
		array[i] = '\0';
		}
		free(array);
		array = NULL;
}
