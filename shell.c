#include "main.h"

/**
 * main - entry point of my shell
 * @argc: number of argument
 * @argv: argument
 * @env: environnement of my programme
 *
 * Return: 0 on succes
 */

int main(int argc, char **argv, char **env)
{
	char *str = NULL;
	char **array;
	size_t n = 0;
	ssize_t nread;
	int i = argc, count;

	while (1)
	{
		if (isatty(0))
			write(1, "#cisfun$ ", _strlen("#cisfun$ "));
		nread = getline(&str, &n, stdin);
		if (nread == EOF)
			break;
		str = _strchrg(str, '\n');
		count = _word_count(str, ' ');
		i = _strlen(str);
		if (i <= 1)
		{
			continue;
		}
		array = _strtok(str, " ");
		if (array == NULL)
		{
			free(str);
			continue;
		}
		exeve(array, env, argv[0], count);
		_free_array(array);
		free(str);
	}
	return (0);
}
