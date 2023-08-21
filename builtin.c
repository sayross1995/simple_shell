#include "shell.h"

/**
 * exit_shell - shell exit
 * @info: Holds args. Maintains prototype.
 * Return: exit status (0) if info.argv[0] not "exit"
 */
int exit_shell(info_t *info)
{
	int chk;
	if (info->argv[1]) /* If exit arg present */
	{
		chk = _erratoi(info->argv[1]);
		if (chk == -1)
		{
			info->status = 2;
			print_err(info, "Invalid number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * change_dir - modify current dir
 * @info: Holds args. Maintains prototype.
 * Return: Always 0
 */
int change_dir(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chd_ret;
	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure message here<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			chd_ret = chdir(dir = _getenv(info, "PWD=") ?: "/");
		else
			chd_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chd_ret = chdir(dir = _getenv(info, "OLDPWD=") ?: "/");
	}
	else
		chd_ret = chdir(info->argv[1]);
	if (chd_ret == -1)
	{
		print_err(info, "Unable to cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * show_help - display help
 * @info: Holds args. Maintains prototype.
 * Return: Always 0
 */
int show_help(info_t *info)
{
	char **arg_array;
	arg_array = info->argv;
	_puts("Help call functional. Function not yet implemented.\n");
	if (0)
		_puts(*arg_array); /* Temp workaround for unused var warning */
	return (0);
}

