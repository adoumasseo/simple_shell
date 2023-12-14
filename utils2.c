#include "main.h"

/**
 * _free_array - a fct that free an *array
 * @array: the array to free
 *
 * Return: Nothing void type fct
 */

void _free_array(char **array)
{
	int i;

	for (i = 0; array[i] != NULL; i++)
		free(array[i]);
	free(array);
}
/**
 * exeve - a fct that execute a programme
 * @array: a two dimension array that contains the path programme and his arg
 * @env: environemnt
 * @argv: the shell executable name
 *
 * Return: void fonction
 */
void exeve(char **array, char **env, char *argv)
{
	struct stat st;
	pid_t child_pid, err_exeve;
	int status;

	if (stat(array[0], &st) == 0)
	{
		child_pid = fork();
		if (child_pid == 0)
		{
			err_exeve = execve(array[0], array, env);
			if (err_exeve == -1)
				perror("execve");
		}
		else
			 wait(&status);
	}
	else if (_search_file(array[0], env) == 1)
	{
		child_pid = fork();
		if (child_pid == 0)
		{
			err_exeve = execve(array[0], array, env);
			if (err_exeve == -1)
				perror("execve");
		}
	}
	else
	{
		write(1, argv, _strlen(argv));
		write(1, ": 1: ", _strlen(": 1: "));
		write(1, array[0], _strlen(array[0]));
		write(1, ": not found\n", _strlen(": not found\n"));
	}
}
