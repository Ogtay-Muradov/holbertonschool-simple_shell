#include "main.h"

/*
* main - our simple shell program
* Return: 0 on success
*/
int main(void)
{
        char *buf = NULL, *IsValidPath = NULL;
        char **parameters = NULL, *newline = "\n", **paths = NULL;
        size_t bufSize = 0;
        int inputLen = 0;
        char *buf_aux;
  
        while (1)
        {
                if (isatty(0))
                        printf("$ ");
                inputLen = getline(&buf, &bufSize, stdin);
                if (inputLen == -1)
                {
                        if (buf)
                        {
                                free(buf), buf = NULL;
                        }
                        exit(0);
                }
                if (_strcmp(buf, "\n") == 0)
                {
                        free(buf),  buf = NULL;
                        continue;
                }
                buf_aux = _strdup(buf), strtok(buf_aux, newline);
                free(buf), buf = NULL;
                if (_strcmp(buf_aux, "exit") == 0 || inputLen == -1)
                {
                        free(buf_aux);
                        exit(0);
                }
                parameters = creatoken(buf_aux);
                if (!parameters || !parameters[0])
                {
                        free_p(parameters);
                        continue;
                }
                if (access(parameters[0], F_OK) == 0)
                {
                        fork_and_exec(parameters[0], parameters), free_p(parameters);
                        continue;
                }
                paths = path_dirs_to_p();
                if (!paths)
                {
                        _printf("Error: failed allocating memory\n");
                        free_p(parameters);
                        continue;
                }
                IsValidPath = check_access(paths, parameters[0]);
                if (!IsValidPath)
                {
                        free_p(parameters), free_p(paths);
                        continue;
                }
                fork_and_exec(IsValidPath, parameters);
                free_p(paths), free_p(parameters), free(IsValidPath);
        }
  return (0);
}
