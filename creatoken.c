#include "main.h"
char **creatoken(char *buf)
{
        char *token = NULL, **parameters = NULL;
        int i;

        parameters = malloc(1024);
        if (!parameters)
                return (NULL);
        token = strtok(buf, " \n\t");
        for (i = 0; token && token[0]; i++)
        {
                parameters[i] = strdup(token);
                token = strtok(NULL, " \n\t");
        }
        parameters[i] = NULL;
        free(buf);
        return (parameters);
}
