#include "main.h"
/**
 * _strcopy2 - a fct that duplicates a string
 * @nstr: the new string
 * @src: the second string
 * @n: size of src
 *
 * Return: Nothing it's void type fct
 */

void _strcopy2(char *nstr, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		nstr[i] = src[i];
	for (; i < n; i++)
		nstr[i] = '\0';
}

/**
 * _strcmp - a fct that compare two string
 * @str1: first string
 * @str2: second string
 *
 * Return: 0 if same
 */

int _strcmp(char *str1, char *str2)
{
	int l1 = _strlen(str1);
	int l2 = _strlen(str2);
	int i;

	for (i = 0; i < l1 && i < l2; i++)
	{
		if (str1[i] > str2[i])
			return (str1[i] - str2[i]);
		else if (str2[i] > str1[i])
			return (str2[i] - str1[i]);
	}
	return (0);
}
/**
 * _str_chg_into - a fct that chg \t of a string and other weird char into ' '
 * @str: our string
 *
 * Return: Nothing is void type functions
 */

void _str_chg_into(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '\t')
			str[i] = ' ';
	}
}
