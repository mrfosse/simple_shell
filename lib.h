#ifndef LIB_H
#define LIB_H
#define N_ESSENTIALS(x, y)  (sizeof(x) / sizeof(y))

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * struct essential_t - struct to store pointers to builtin funtions.
 * @name: name of the command.
 * @s: pointer to command.
 */
typedef struct essential_t
{
	char *name;
	int (*s)();
} essential_t;

char *_readl(void);
char **_parsel(char *l);
int _exe(char **args);
int _run(char **args);

int new_exit(void);
int _help(void);
int _cd(char **args);

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

#endif
