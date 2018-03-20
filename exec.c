#include "shell.h"

/**
 * main - execve example
 *
 * Return: Always 0.
 */
int exec(char **s, char **env)
{
	if (access(s[0], F_OK) == 0)
	{
		if (execve(s[0], s, NULL) == -1)
		{
			perror("Error:");
			__exit(s);
		}
	}
	else
	{
		if (execve(_which(s[0], env), s, NULL) == -1)
		{
			perror("Error:");
			__exit(s);
		}
	}
	return (0);
}
