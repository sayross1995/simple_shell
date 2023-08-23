#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#define PROMPT "#cisfun$ "

int main(void)
{
	char *input = NULL; /* Use getline for input */
	size_t n = 0;
	char *token;
	ssize_t nread;

	while (1)
	{
		write(STDOUT_FILENO, PROMPT, sizeof(PROMPT) - 1);
		nread = getline(&input, &n, stdin);
		if (nread == -1)
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
		else if (nread == 1)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}
		input[nread - 1] = '\0';
		token = strtok(input, " "); /* Split by space */
		if (token != NULL)
		{
			if (strcmp(token, "exit") == 0)
			{
				free(input); /* Free allocated memory before exit */
				exit(EXIT_SUCCESS);
			}
		}
	}
	free(input); /* Free allocated memory before exiting */
	return (0);
}

