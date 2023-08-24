#include "main.h"

/**
 * execmd - Execute a command
 * @argv: arr of arguments
 *
 * Return: 0
 */
void execmd(char **argv)
{
    char *cmd = NULL;
    char *ac_cmd = NULL;
    pid_t pid;
    int status;

    built_in_exit(argv);

    pid = fork();

    if (argv)
    {

        if(pid == -1)
        {
          perror("Error:");
          return;
        }

        if(pid == 0)
        {
          cmd = argv[0];
          ac_cmd = get_path(cmd);

            if(execve(ac_cmd, argv, environ) == -1)
            {
              perror("Error:");
            }

        }
        else
        {
          wait(&status);
        }
    }
}
