#include "shell.h"
/**
 * getRead_line - Print for the users type
 * Return: For return a line of string input for users
 */
char *getRead_line(void)
{
	char *line_cmd = NULL;
	size_t l_user = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	if (getline(&line_cmd, &l_user, stdin) == -1)
	{
		free(line_cmd);
		line_cmd = NULL;
		return (NULL);
	}
	return (line_cmd);
}
