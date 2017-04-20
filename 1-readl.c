#include "lib.h"

/**
 * _readl - reads the line.
 * Return: returns the line it read.
 */
char *_readl(void)
{
	int buf_s, buf_s2, count, c;
	char *buffer;

	buf_s = 1024;
	count = 0;
	buffer = malloc(buf_s * sizeof(char *));

	if (!buffer)
	{
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		c = getchar();
		if (c == EOF || c == '\n')
		{
			buffer[count] = '\0';
			return (buffer);
		}
		else
			buffer[count] = c;
		count++;
		if (count >= buf_s)
		{
			buf_s2 = buf_s + 1024;
			buffer = _realloc(buffer, buf_s, buf_s2);
			buf_s = buf_s2;
			if (!buffer)
			{
				fprintf(stderr, ">$: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}
