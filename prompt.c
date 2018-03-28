#include "shell.h"

/**
 * ctrl_c - ignore Ctrl-C input and prints prompt again
 * @n: takes in int from signal
 */
void ctrl_c(int n)
{
	(void)n;
	write(STDOUT_FILENO, "\n$ ", 3);
}

/**
 * built_in - handles builtins (exit, env, cd)
 * @token: user's typed command
 * @env: environmental variable
 * @num: take in nth user command typed to write error message
 * Return: 1 if acted on builtin, 0 if not
 */
int built_in(char **token, list_t *env, int num)
{
	int i = 0;

	/* if user types "exit", free cmd tokens, and exit */
	if (_strcmp(token[0], "exit") == 0)
	{
		__exit(token, env, num);
		i = 1;
	}
	/* if user types "env", print, free cmd tokens, and reprompt */
	else if (_strcmp(token[0], "env") == 0)
	{
		_env(token, env);
		i = 1;
	}
	/* if user types "cd" , it will change directory */
	else if (_strcmp(token[0], "cd") == 0)
	{
		_cd(token, env, num);
		i = 1;
	}
	/* if user types "setenv", create or modify linked list node */
	else if (_strcmp(token[0], "setenv") == 0)
	{
		_setenv(&env, token);
		i = 1;
	}
	/* if user types "setenv", remove linked list node */
	else if (_strcmp(token[0], "unsetenv") == 0)
	{
		_unsetenv(&env, token);
		i = 1;
	}
	return (i);
}

/**
 * ignore_space - return string without spaces in front
 * @str: string
 * Return: new string
 */
char *ignore_space(char *str)
{
	while (*str == ' ')
		str++;
	return (str);
}

/**
 * ctrl_D - exits program if Ctrl-D was pressed
 * @i: characters read via getline
 * @command: user's typed in command
 * @env: environmental variable linked list
 */
void ctrl_D(int i, char *command, list_t *env)
{
	if (i == 0) /* handles Ctrl+D */
	{
		free(command); /* exit with newline if in shell */
		free_linked_list(env);
		if (isatty(STDIN_FILENO))/* ctrl+d prints newline */
			write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}
}

/**
 * prompt - repeatedly prompts user and executes user's cmds if applicable
 * @en: envrionmental variables
 * Return: 0 on success
 */
int prompt(char **en)
{
	list_t *env;
	size_t i = 0, n = 0;
	int status = 0, command_line_no = 0;
	char *command, *n_command, **token;

	env = env_linked_list(en);
	do {
		command_line_no++;
		if (isatty(STDIN_FILENO)) /* reprompt if in interactive shell */
			write(STDOUT_FILENO, "$ ", 2);
		else
			non_interactive(env);
		signal(SIGINT, ctrl_c); /* makes ctrl+c not work */
		command = NULL; i = 0; /* reset vars each time loop runs */
		i = _getline(&command); /* read user's cmd in stdin */
		ctrl_D(i, command, env); /* exits shell if ctrl-D */
		n_command = command;
		command = ignore_space(command);
		n = 0;
		while (command[n] != '\n') /* replace _getline's \n with \0 */
			n++;
		command[n] = '\0';
		if (command[0] == '\0') /* reprompt if user hits enter only */
		{
			free(n_command); continue;
		}
		token = NULL; token = _strtok(command, " "); /*token user cmd*/
		if (n_command != NULL)
			free(n_command);
		if (built_in(token, env, command_line_no)) /*checks for built*/
			continue;
		if (fork() == 0) /* create child process to execute cmd */
			_execve(token, env, command_line_no);
		else /* parent waits till child finishes & frees cmd tokens */
		{
			wait(&status);
			free_double_ptr(token);
		}
	} while (1); /* keep on repeating till user exits shell */
	return (0);
}
