#include "main.h"
#include <string.h>
/**
 *_strcmp - function that compares strings
 *@s1: char
 *@s2: char
 *Return: diference between s1 and s2
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] - s2[i] == 0)
		i++;
	return (s1[i] - s2[i]);
}
