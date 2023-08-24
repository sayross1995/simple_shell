#include "main.h"

/**
 * main - Entry point of the simple shell program
 * @ac: The argument count
 * @argv: Array of arguments
 *
 * Return: Always 0
 */
int main(int ac, char **argv)
{
    char *line = NULL, *line_copy = NULL;
    size_t len = 0;
    ssize_t nread;
    const char *delim = " \n";
    int nbr_tokens = 0;
    char *token;
    int i;

    (void)ac;

    while (1)
    {
        printf("(simple_shell) $ ");
        nread = getline(&line, &len, stdin);

        if (nread == -1)
        {
            printf("Error: getline failed\n");
            return (-1);
        }

        line_copy = malloc(sizeof(char) * nread);
        if (line_copy == NULL)
        {
            printf("Error: malloc failed\n");
            return (-1);
        }

        strcpy(line_copy, line);
        token = strtok(line, delim);

        while (token != NULL)
        {
            nbr_tokens++;
            token = strtok(NULL, delim);
        }
        nbr_tokens++;

        argv = malloc(sizeof(char *) * nbr_tokens);

        token = strtok(line_copy, delim);

        for (i = 0; token != 0; i++)
        {
            argv[i] = malloc(sizeof(char) * strlen(token));
            strcpy(argv[i], token);

            token = strtok(NULL, delim);
        }
        argv[i] = NULL;
        execmd(argv);

    }

    free(line_copy);
    free(line);

    return (0);
}
