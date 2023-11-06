#include "shell.h"
/**
 * string_cat - copy string to an other string
 *@dst: char
 *@sc: char
*Return: dst
*/
char *string_cat(char *dst, char *sc)
{
	char *d = dst;
	
	while (*d)
	{d++;
	}
	while (*sc)
	{
		*d = *sc;
		d++;
		sc++;
	}
	*d = *sc;
	return (dst);
}
/**
 * string_cpy - copies the string pointed
 * @dst: destimation
 * @sc: source of the copy
 * Return: char
 */
char *string_cpy(char *dst, char *sc)
{
	int i = 0;

	while (sc[i])
	{	
		dst[i] = sc[i];
		i++;
	}
	dst[i] = sc[i];
	return (dst);
}
/**
 * string_line - opies the string pointed
 * @p: A pointer
 * Return: char pionter
 */
int string_line(char *p)
{
	int l;

	l = 0;
	while (p[l])
	l++;
	return (l);
}
/**
 * string_cmpr - The values of a string
 * @str_1: The first character
 * @str_2: The scecond character
 * Return: on return The final compare
 */
int string_cmpr(char *str_1,char *str_2)
{
int comp;

	while (*str_1)
	{
		if (*str_1 != *str_2)
			break;
		str_1++;
		str_2++;
		comp = (int)*str_1 - (int)*str_2;
	}
	return (comp);
}
/**
 * string_dupl - Uaplice copy of string
 * @str: string
 * Return: copy of string
 */
char *string_dupl(const char *str)
{
	char *p;
	int i = 0, l = 0;

	if (!str)
		return (NULL);
	while (*str != '\0')
	{
		l++;
		str++;
	}
	str = str - l;
	p = malloc(sizeof(char) * (l + 1));
	if (!p)
		return (NULL);
	while (i <= l)
	{
		p[i] = str[i];
		return (p);
		i++;
	}
	return (p);
}
