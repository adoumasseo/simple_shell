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
	int i = argc;

	while (1)
	{
		if (isatty(0))
			write(1, "#cisfun$ ", _strlen("#cisfun$ "));
		nread = getline(&str, &n, stdin);
		if (nread == EOF)
			break;
		str = _strchrg(str, '\n');
		_str_chg_into(str);
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
		if (_strcmp(array[0], "exit") == 0)
		{
			write(1, array[0], _strlen(array[0]));
			write(1, "\n", 1);
			free(str);
			_free_array(array);
			_exit(0);
		}
		exeve(array, env, argv[0]);
		_free_array(array);
	}
	free(str);
	return (0);
}
