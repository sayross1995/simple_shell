#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

#define PROMPT "#cisfun$ "
#define MAX_INPUT_LENGTH 1024

int main(void)
{
	char *input = NULL; /* Use getline for input */
	size_t n = 0;
	char *token;
	ssize_t nread;

	while (1)
	{
		write(STDOUT_FILENO, PROMPT, sizeof(PROMPT) - 1);

		/* Read input from user using getline */
		nread = getline(&input, &n, stdin);

		if (nread == -1)
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
		else if (nread == 1)
		{
			/* Handle end of file (Ctrl+D) */
			write(STDOUT_FILENO, "\n", 1);
			break;
		}

		/* Remove the newline character at the end of the input */
		input[nread - 1] = '\0';

		/* Tokenize the input */
		token = strtok(input, " "); /* Split by space */

		if (token != NULL)
		{
			/* Handle built-in command: exit */
			if (strcmp(token, "exit") == 0)
			{
				free(input); /* Free allocated memory before exit */
				exit(EXIT_SUCCESS);
			}

			/* Fork and execute the command */
			pid_t pid = fork();

			if (pid == -1)
				perror("fork");
			else if (pid == 0)
			{
				/* Child process */
				if (execve(token, &token, NULL) == -1)
				{
					perror("execve");
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				/* Parent process */
				waitpid(pid, NULL, 0); /* Wait for child to finish */
			}
		}
	}

	free(input); /* Free allocated memory before exiting */
	return (0);
}

