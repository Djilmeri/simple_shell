#include "shell.h"
/**
 * _Execute_line - Function for execute the commend of users
 * @command_line: commend line for the users
 * @arg: command and valuer path
 * @index: Index for commend
 * Return: status
 */
int _Execute_line(char **command_line, char **arg, int index)
{
	char *full_command;
	pid_t ch;
	int stat;

	full_command = _Get_Path(command_line[0]);
	if (!full_command)
	{
		print_ero(arg[0], command_line[0], index);
		array_string(command_line);
		return (127);
	}
	ch = fork();
	if (ch == 0)
	{
		if (execve(full_command, command_line, environ) == -1)
		{
			free(full_command);
			full_command = NULL;
			array_string(command_line);
		}
	}
	else
	{
		waitpid(ch, &stat, 0);
		array_string(command_line);
		free(full_command);
		full_command = NULL;
	}
	return (WEXITSTATUS(stat));
}
