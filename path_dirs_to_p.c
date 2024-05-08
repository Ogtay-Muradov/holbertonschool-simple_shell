#include "main.h"

char **path_dirs_to_p(void)
{
	char *pathDirs, *token, **paths, *aux;
	int i;
	pathDirs = strdup(getenv("PATH"));
  if (pathDirs == NULL)
  {
    free(pathDirs);
  }
	paths = malloc(1024);
	if (!paths)
		return (NULL);
	token = strdup(pathDirs);
	strtok(token, ":");
	aux = token;
	for (i = 0; aux; i++)
	{
		paths[i] = strdup(aux);
		aux = strtok(NULL, ":");
	}
  pathDirs = NULL;
	free(token);
	paths[i] = NULL;
	return (paths);
}
