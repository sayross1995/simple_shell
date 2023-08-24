#include "main.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#define PROMPT "$ "
#define MAX_INPUT_LENGTH 1024/**
			      * checknr - check number readed
			      * @nread: number read
			      */
void checknr(int nread)
{
	if (nread == -1)
	{
		perror("getline");
		exit(EXIT_FAILURE);
	}
	else if (nread == 1)
	{
		write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}
}
/**
 * main - shell main function
 * Return: intger
 */
int main(void)
{
	char *input = NULL;
	size_t n = 0;
	char *token[] = {NULL, NULL};
	ssize_t nread;    while (1)
	{
		write(STDOUT_FILENO, PROMPT, sizeof(PROMPT) - 1);
		nread = getline(&input, &n, stdin);
		input[nread - 1] = '\0';
		checknr(nread);
		token[0] = strtok(input, " ");
		if (token[0] != NULL)
		{
			if (strcmp(token[0], "exit") == 0)
			{
				free(input);
				exit(EXIT_SUCCESS);
			}
			pid_t pid = fork();

			if (pid == -1)
				perror("fork");
			else if (pid == 0)
			{
				if (execve(token[0], token, NULL) == -1)
				{
					perror("execve");
				}
			}
			else
				waitpid(pid, NULL, 0);
		}
		if (input)
			free(input);
		input = NULL;
	}
	return (0);
}
