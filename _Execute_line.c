#include "shell.h"
/**
 * _Execute_line - Function for execute the commend of users
 * @command_line: commend line for the users
 * @arg: command and valuer path
 * Return: status
 */
int _Execute_line(char **command_line, char **arg)
{
	pid_t ch;
	int stat;

	ch = fork();
	if (ch == 0)
	{
		if (execve(command_line[0], command_line, environ) == -1)
		{
			perror(arg[0]);
			array_string(command_line);
			exit(0);
		}
	}
	else
	{
		waitpid(ch, &stat, 0);
		array_string(command_line);
	}
	return (WEXITSTATUS(stat));
}
