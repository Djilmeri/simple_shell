#include "shell.h"
/**
 * _Get_Env - function to get env
 * @var_env: Environement
 * Return: char
 */
char *_Get_Env(char *var_env)
{
	char *tp, *ky, *val, *env;
	int i;

	for (i = 0; environ[i]; i++)
	{
		tp = string_dupl(environ[i]);
		ky = strtok(tp, "=");
		if (string_cmpr(ky, var_env) == 0)
		{
			val = strtok(NULL, "\n");
			env = string_dupl(val);
			free(tp);
			return (env);
		}
		free(tp);
		tp = NULL;
	}
	return (NULL);
}
