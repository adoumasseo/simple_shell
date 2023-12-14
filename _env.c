#include "main.h"

/**
 * _getenv - a fct that retrun a value of env variable
 * @name: env variables name
 * @env: the environnement
 * @tmp: a new allocated memory
 *
 * Return: string contains env value; NULL if not found
 */

char *_getenv(char *name, char **env, char **tmp)
{
	int i;
	char *pathname;

	for (i = 0; env[i] != NULL; i++)
	{
		*tmp = malloc(sizeof(char) * (_strlen(env[i]) + 1));
		_strcopy2(*tmp, env[i], _strlen(env[i]));
		(*tmp)[_strlen(env[i])] = '\0';
		pathname = strtok(*tmp, "=");

		if (_strcmp(name, pathname) == 0)
		{
			pathname = strtok(NULL, "=");
			return (pathname);
		}
		free(*tmp);
	}
	return (NULL);
}
/**
 * _search_file - search for a file in the path
 * @file_name: the file to search
 *
 * Return: 1 is file is and 0 else
 */

int _search_file(char *file_name, char **env)
{
	char *path, *token, *file_path, *_file_name_slash, *tmp;
	struct stat st;

	_file_name_slash = string_nconcat("/", file_name);
	if (_file_name_slash == NULL)
		return (0);
	path = _strcopy(_getenv("PATH", env, &tmp));
	/*printf("%s", path);*/
	if (path == NULL)
		return (0);
	token = strtok(path, ":");
	while (token != NULL)
	{
		file_path = string_nconcat(token, _file_name_slash);
		if (file_path == NULL)
			return (0);
		if (stat(file_path, &st) == 0)
		{
			free(file_path);
			free(_file_name_slash);
			free(path);
			return (1);
		}
		token = strtok(NULL, ":");
	}
	free(file_path);
	free(_file_name_slash);
	free(path);
	return (0);
}
