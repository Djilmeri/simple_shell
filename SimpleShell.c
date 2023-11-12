#include "shell.h"
/**
 * main - main argument functions
 *@ca: count of arguments
 *@arg: arguments
 *Return: _exit = 0.
 */
int main(int ca, char **arg)
{
	char *line_cmd = NULL, **command_line = NULL;
	int stat = 0, idx = 0;

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
		idx++;
		command_line = token_line(line_cmd);
		if (!command_line)
		continue;

		if (_is_built(command_line[0]))
			hand_built(command_line, arg, &stat, idx);
		else
		stat = _Execute_line(command_line, arg, idx);
	}
}
