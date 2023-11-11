#include "shell.h"
/**
 * token_line -get token of string
 * @line_cmd: command of user
 * Return: For a pointer
 */
char **token_line(char *line_cmd)
{
	char *token = NULL, *t = NULL;
	char **command_line = NULL;
	int compt = 0, i = 0;

	if (!line_cmd)
		return (NULL);
	t = strdup(line_cmd);
	token = strtok(t, DELIM);
	if (token == NULL)
	{
		free(line_cmd);
		line_cmd = NULL;
		free(t);
		t = NULL;
		return (NULL);
	}
	while (token)
	{
		compt++;
		token = strtok(NULL, DELIM);
	}
	free(t);
	t = NULL;
	command_line = malloc(sizeof(char *) * (compt + 1));
	if (!command_line)
	{
		free(line_cmd);
		line_cmd = NULL;
		return (NULL);
	}
	token = strtok(line_cmd, DELIM);
	while (token)
	{
		command_line[i] = token;
		token = strtok(NULL, DELIM);
		i++;
	}
	free(line_cmd);
	line_cmd = NULL;
	command_line[i] = NULL;
	return (command_line);
}
