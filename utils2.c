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
 * @count: Number of word in the user input
 *
 * Return: 0 or -1
 */
void exeve(char **array, char **env, char *argv, int count)
{
	struct stat st;
	pid_t child_pid;
	pid_t err_exeve;
	char *str = ": No such file or directory\n";
	int status;

	if (stat(array[0], &st) == 0 && count == 1)
	{
		child_pid = fork();
		if (child_pid == 0)
		{
			err_exeve = execve(array[0], array, env);
			if (err_exeve == -1)
				perror("execve");
		}
		else
		{
			 wait(&status);
		}
	}
	else
	{
		write(1, argv, _strlen(argv));
		write(1, str, _strlen(str));
	}
}
