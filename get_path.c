#include "main.h"

/**
 * get_path - Get the full path
 * @cmd: The command to search for
 *
 * Return: The full path
 */
char *get_path(char *cmd)
{
    char *path;
    char *path_copy;
    char *file_path;
    char *token;
    int len_cmd, len_dir;
    struct stat st;

    path = getenv("PATH");

    if (path)
    {
        path_copy = strdup(path);

        len_cmd = strlen(cmd);

        token = strtok(path_copy, ":");

        while (token != NULL)
        {
            len_dir = strlen(token);
            file_path = malloc(sizeof(char) * (len_dir + len_cmd + 2));

            if (!file_path)
            {
                free(path_copy);
                return (NULL);
            }

            strcpy(file_path, token);
            strcat(file_path, "/");
            strcat(file_path, cmd);

            if (stat(file_path, &st) == 0)
            {
                free(path_copy);
                return (file_path);
            }
            else
            {
                free(file_path);
                token = strtok(NULL, ":");
            }
        }

        free(path_copy);
    }

    return (NULL);
}
