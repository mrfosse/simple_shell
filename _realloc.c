#include "lib.h"
/**
 * _realloc - alloctes mem using malloc
 * @ptr: pointer to mem.
 * @old_size: old size.
 * @new_size: will be the new size.
 * Return: returns the new string.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *string, *temp;
	unsigned int count;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		temp = malloc(new_size);
		if (temp == NULL)
			return (NULL);
		return (temp);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	string = malloc(new_size);
	if (string == NULL)
		return (NULL);

	temp = ptr;
	for (count = 0; count < old_size; count++)
		string[count] = temp[count];

	free(ptr);
	return (string);
}
