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
	word = malloc(sizeof(char *));
	if (word == NULL)
		return (NULL);
	copy = _strcopy(str);
	if (copy == NULL)
		return (NULL);
	token = strtok(copy, delim);
	while (token != NULL)
	{
		word = realloc(word, (j + 2) * sizeof(char *));
		if (word == NULL)
		{
			free(copy);
			free(token);
			_free_array(word);
			return (NULL);
		}
		word[j] = _strcopy(token);
		if (word[j] == NULL)
		{
			free(copy);
			free(token);
			_free_array(word);
			return (NULL);
		}
		j++;
		token = strtok(NULL, delim);
	}
	word[j] = NULL;
	free(copy);
	return (word);
}
