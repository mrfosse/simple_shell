#include "lib.h"

/**
 * _exe - launches programs.
 * @args: arguments.
 * Return: returns 1 unless exit.
 */
int _exe(char **args)
{
	int count, n;
	essential_t essentials[] = {
		{"exit", new_exit},
		{"help", _help},
		{"cd", _cd}
	};

	if (args[0] == NULL)
		return (1);
	n = N_ESSENTIALS(essentials, essentials[0]);
	for (count = 0; count < n; count++)
	{
		if (strcmp(args[0], essentials[count].name) == 0)
			return (essentials[count].s(args));
	}
	return (_run(args));
}
