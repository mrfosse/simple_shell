#include "lib.h"
#define DELIM " \t\r\n\a"

/**
 * _parsel - takes the line and seperates it.
 * @l: sentence to be seperated.
 * Return: returns the array of segments.
 */
char **_parsel(char *l)
{
	int buf_s, buf_s2, count;
	char **tokens, *token;

	buf_s = 64;
	count = 0;
	tokens = malloc(buf_s * sizeof(char *));

	if (!tokens)
	{
		fprintf(stderr, ">$: allocation error at pasel\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(l, DELIM);
	while (token != NULL)
	{
		tokens[count] = token;
		count++;
		if (count >= buf_s)
		{
			buf_s2 = buf_s + 64;
			tokens = _realloc(tokens, buf_s, buf_s2);
			buf_s = buf_s2;
			if (!tokens)
			{
				fprintf(stderr, ">$: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, DELIM);
	}
	tokens[count] = NULL;
	return (tokens);
}
