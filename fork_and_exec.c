#include "main.h"

void fork_and_exec(char *command, char **parameters)
{
	extern char **environ;
	pid_t id;
	int status;

	id = fork();
	if (id == 0)
		execve(command, parameters, environ);
	else
		wait(&status);
	return;
}
