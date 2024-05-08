#include "main.h"

void free_p(char **p)
{
	int i;

	for (i = 0; p[i]; i++)
		free(p[i]);
	free(p);
}
