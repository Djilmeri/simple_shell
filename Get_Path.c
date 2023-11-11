#include "shell.h"
/**
 * _Get_Path - get variable PATH
 * @command: environement local
 * Return: value of Path
 */
char *_Get_Path(char *command)
{
	char *path_ev, *full_command, *dir;
	int i;
	struct stat state;

	for (i = 0; command[i]; i++)
	{
		if (command[i] == '/')
		{
			if (stat(command, &state) == 0)
				return (string_dupl(command));

			return (NULL);
		}
	}
	path_ev = _Get_Env("PATH");
	if (!path_ev)
		return (NULL);
	dir = strtok(path_ev, ":");
	while (dir)
	{
		full_command = malloc(string_line(dir) + string_line(command) + 2);
		if (full_command)
		{
			string_cpy(full_command, dir);
			string_cat(full_command, "/");
			string_cat(full_command, command);
			if (stat(full_command, &state) == 0)
			{
				free(path_ev);
				return (full_command);
			}
			free(full_command);
			full_command = NULL;
			dir = strtok(NULL, ":");
		}
	}
	free(path_ev);
	return (NULL);
}
