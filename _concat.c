#include "main.h"

/**
 * string_nconcat - a function that concatenates two strings.
 * @s1: first string
 * @s2: second string to concat to first one
 *
 * Return: a pointer to the new concat string
 */

char *string_nconcat(char *s1, char *s2)
{
	unsigned int k, l1 = 0, l2 = 0, i, j = 0;
	char *p;

	while (s1[l1])
		l1++;
	while (s2[l2])
		l2++;
	k = l1 + l2 + 1;
	p = malloc(sizeof(char) * k);
	if (p == NULL)
		return (NULL);
	for (i = 0; i < k - 1; i++)
	{
		if (i < l1)
			*(p + i) = s1[i];
		else
		{
			*(p + i) = s2[j];
			j++;
		}
	}
	*(p + i) = '\0';
	return (p);
}
