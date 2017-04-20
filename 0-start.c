#include "lib.h"

/**
 * main - loop to take user commands.
 * @argc: argument count.
 * @argv: arguments.
 * Return: returns zero.
 */
int main(int argc, char **argv)
{
	char *l;
	char **args;
	int check;
	(void) argc, (void) argv;

	do {
		printf("hsh>$ ");
		l = _readl();
		args = _parsel(l);
		check = _exe(args);
		free(l);
		free(args);
	} while (check);
	return (0);
}
