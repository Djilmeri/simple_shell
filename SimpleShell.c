#include "shell.h"
/**
 * main - main argument functions
 *@ca: count of arguments
 *@arg: arguments
 *@evt: environment
 *Return: _exit = 0.
 */
int main(int ca, char **arg)
{
	char *line_cmd = NULL, **command_line = NULL;
	int stat = 0;

	(void)ca;

	while (1)
	{
		line_cmd = getRead_line();
		if (line_cmd == NULL) /*ctr + D*/
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
					
					return (stat);
					
					}
					free(line_cmd);
		command_line = token_line(line_cmd);
		if (command_line == NULL)
		continue;

		stat = _Execute_line(command_line, arg);
	}
}
