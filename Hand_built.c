#include "shell.h"
/**
 * _is_built - Function for execute command existe
 * @command: The user's command
 * Return: retur int result
 */
int _is_built(char *command)
{
	char *built[] = {
		"exit", "env", "setev", "cd", NULL
	};
	int i;

	for (i = 0; built[i]; i++)
	{
		if (string_cmpr(command, built[i]) == 0)
			return (1);
	}
	return (0);
}
/**
 * hand_built - Test the user's command
 * @command: The user's command
 * @arg: argument
 * @stat: status
 * @idx: index of command
 * Return: void
 */
void hand_built(char **command, char **arg, int *stat, int idx)
{
if (string_cmpr(command[0], "exit") == 0)
exit_shell(command, arg, stat, idx);
else if (string_cmpr(command[0], "env") == 0)
print_ev(command, stat);
}
/**
 * exit_shell - exit the shell and restarte again
 * @command:The user's command
 * @arg:Argumment
 * @stat:status
 * @index:The index of command
 * Return: Void
 */
void exit_shell(char **command, char **arg, int *stat, int idx)
{
	int exit_val = (*stat);
	char *index, msg[] = ": exit: Illegal number: ";

	if  (command[1])
	{
		if (positive_nbr(command[1]))
		{
			exit_val = at_oi(command[1]);
		}
		else
		{
			index = _it_oa(idx);
			write(STDERR_FILENO, arg[0], string_line(arg[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, index, string_line(index));
			write(STDERR_FILENO, msg, string_line(msg));
			write(STDERR_FILENO, command[1], string_line(command[1]));
			write(STDERR_FILENO, "\n", 1);
			free(index);
			array_string(command);
			(*stat) = 2;
			return;
		}
	}
		array_string(command);
		exit(exit_val);
}
/**
 * print_ev - Printer an envernement
 * @command: The user's command
 * @stat: status
 * Return: void
 */
void print_ev(char **command, int *stat)
{
int i;

for (i = 0; environ[i]; i++)
{
write(STDOUT_FILENO, environ[i], string_line(environ[i]));
write(STDOUT_FILENO, "\n", 1);
}
array_string(command);
(*stat) = 0;
}
