#include "main.h"

/**
 * _strlen - a fct that return size of a char *
 * @str: string null terminated
 *
 * Return: size of str
 */

int _strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

/**
 * _strchrg - a fct that transform \n into \0 if it's find in a char *
 * @str: string "end" terminated
 * @end: the char that end the string
 *
 * Return: new string
 */

char *_strchrg(char *str, char end)
{
	int i = 0;

	while (str[i] != end)
		i++;
	str[i] = '\0';
	return (str);
}

/**
 * _strchr - a fct that find first occurs of a char in string
 * @str: our string
 * @delim: our char
 *
 * Return: A pointer to first occurs or NULL
 */

char *_strchr(char *str, char delim)
{
	while (*str != '\0')
	{
		if (*str == delim)
			return (str);
	str++;
	}
	return (NULL);
}

/**
 * _word_count - a fct that count numberof word in a string
 * @str: our string
 * @delim: char to delim
 *
 * Return: Number of word
 */

int _word_count(char *str, char delim)
{
	int i = 0;

	while (*str)
	{
		if (*str == delim)
			i++;
		str++;
	}

	return (i + 1);
}
/**
 * _free_array_i - it's a custom version that frees j element from array
 * @array: The array
 * @j: j
 *
 * Return: Nothing is void
 */
void _free_array_i(char **array, int j)
{
	int i;

	for (i = 0; i < j; i++)
		free(array[i]);
	free(array);
}
