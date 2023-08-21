#include "shell.h"

/**
 * _eputs - print input string
 * @str: string to print
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
	int i = 0;
	if (!str)
		return;
	while (str[i])
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - write char c to stderr
 * @c: Character to print
 *
 * Return: On success 1.
 * On error, -1 returned, errno set.
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];
	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd - write char c to given fd
 * @c: Character to print
 * @fd: Filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 returned, errno set.
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];
	
	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putsfd - print input string
 * @str: String to print
 * @fd: Filedescriptor to write to
 *
 * Return: Number of chars put
 */
int _putsfd(char *str, int fd)
{
	int i = 0;
	
	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}

