#include "main.h"
/**
 * _strcopy - a fct that a string
 * @str: the string end terminated
 *
 * Return: the new char
 */

char *_strcopy(char *str)
{
	int i = 0, j = 0;
	char *copy;

	while (str[i])
		i++;
	copy = malloc(sizeof(char) * (i + 1));
	if (copy == NULL)
	{
		printf("_strcopy 1\n");
		return (NULL);
	}
	while (str[j])
	{
		copy[j] = str[j];
		j++;
	}
	copy[j] = '\0';
	return (copy);
}
