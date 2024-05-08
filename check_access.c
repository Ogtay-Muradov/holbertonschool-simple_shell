#include "main.h"
char *check_access(char *paths[], char *command)
{
	char *fullPath = NULL;
	int i = 0, fullPathSize = 0;

	if (!paths || !command)
		return (NULL);

	for (i = 0; paths[i]; i++)
	{
		if (fullPath)
			free(fullPath);
		fullPathSize = strlen(paths[i]) + strlen(command) + 2;
		fullPath = malloc(fullPathSize);
		if (!fullPath)
			return (NULL);
		strcpy(fullPath, paths[i]);
		strcat(fullPath, "/");
		strcat(fullPath, command);
		if (access(fullPath, F_OK) == 0)
			return (fullPath);
	}
	free(fullPath);
	return (NULL);
}
