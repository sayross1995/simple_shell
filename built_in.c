#include "main.h"

/**
 * built_in_exit - exit the shell
 * @argv: array of arguments
 *
 * Return: 0
*/

void built_in_exit(char **argv)
{
  if (strcmp(argv[0], "exit") == 0)
    exit(0);
}

/**
 * print_env - print the environment
 * @argv: array of arguments
 *
 * Return: 0
*/
void print_env(char **argv)
{
    int i = 0;

    if (strcmp(argv[0], "env") == 0)
    {
        while (environ[i] != NULL)
        {
            printf("%s\n", environ[i]);
            i++;
        }
    }
}

/**
 * empty_line - exit the shell
 * @argv: array of arguments
 *
 * Return: 0
*/
int empty_line(char **argv)
{
  if (strcmp(argv[0], "\n") == 0)
  {
    printf("Waiting for a command ...\n");
    return 0;
  }
  return 1;
}
