#include "lib.h"

/**
 * new_exit - exits the shell.
 * Return: returns 0.
 */
int new_exit(void)
{
	return (0);
}
/**
 * _help - displays the essential commands.
 * Return: returns 1.
 */
int _help(void)
{
	int count, n;
	essential_t essentials[] = {
		{"exit", new_exit},
		{"help", _help},
		{"cd", _cd}
	};
	n = N_ESSENTIALS(essentials, essentials[0]);
	printf("Available commands are:\n");
	for (count = 0; count < n; count++)
		printf("%s\n", essentials[count].name);

	return (1);
}
/**
 * _cd - change directory.
 * @args: list of arguments
 * Return: returns 1.
 */
int _cd(char **args)
{
	char buf[4096];

	if (args[1] == NULL)
		fprintf(stderr, ">$: expected argument to \"cd\"\n");
	else
	{
		if (chdir(args[1]) == 0)
		{
			if (getcwd(buf, 4096) == NULL)
				perror("unable to print dir");
			else
				printf("%s\n", buf);
		}
		else
			perror("cd error");
	}
	return (1);
}
