#include "main.h"

/**
 * _strtok - a fct that create an **array of word with string
 * @str: our string
 * @delim: the char to delim a word
 *
 * Return: the **array
 */

char **_strtok(char *str, char *delim)
{
	char *copy = NULL, *token = NULL;
	int i = 0, j = 0;
	char **word = NULL;

	while (str[i] != '\0' && _strchr(delim, str[i]) != NULL)
		i++;
	copy = _strcopy(str);
	if (copy == NULL)
		return (NULL);
	token = strtok(copy, delim);
	word = malloc((j + 2) * sizeof(char *));
	if (word == NULL)
	{
		free(copy);
		return (NULL);
	}
	word[j] = _strcopy(token);
	if (word[j] == NULL)
	{
		free(copy);
		_free_array_i(word, j);
		return (NULL);
	}
	j++;
	word[j] = NULL;
	free(copy);
	return (word);
}
