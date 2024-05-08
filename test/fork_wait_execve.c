#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#define CHAR_BUFFER 1024

char **line_devider(char *buffer)
{
    char **arr;
    char *token;
    int i = 0;
    
    arr = malloc(strlen(buffer) * sizeof(char *));
    if (arr == NULL)
        return (NULL);
        
    token = strtok(buffer," \n");
    while (token)
    {
        arr[i] = strdup(token);
        if (arr[i] == NULL)
        {
            perror("ERROR");
            exit(1);
        }
        i++;
        token = strtok(NULL," \n");
        
    }
    arr[i] = NULL;
    return (arr);
}


int main(void)
{
        char *buffer = NULL;
        size_t len = 1024, read;
        pid_t pid;
        char **arr;
        int i;
        while (1)
        {
                printf("$ ");
                read = getline(&buffer, &len, stdin);
                if (read == -1)
                        break;
                        
                arr = line_devider(buffer);
                pid = fork();
                if (pid == 0)
                {
                        execve(arr[0],arr, NULL);
                        perror("ERROR");
                        exit(1);
                }
		else
		{
			wait(NULL);
		}
                if (pid == -1)
                    perror("ERROR");
                    
                for (i = 0; arr[i] != NULL; i++)
                {
                    free(arr[i]);
                }
                free(arr);
        }
        free(buffer);
        return (0);
}

