#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"

/**
 * ex_it - shell with  a status
 * @cmd: parsed command
 * @input: user input
 * @argv: argument vector
 * @count: command count
 * Return: Void
 */
void  ex_it(char **cmd, char *input, char **argv, int count)
{
	int status, i = 0;

	if (cmd[1] == NULL)
	{
		free(input);
		free(cmd);
		exit(0);
	}
	while (cmd[1][i])
	{
		if (_isalpha(cmd[1][i++]) != 0)
		{
			custom_error(argv, count, cmd);
			break;
		}
		else
		{
			status = _atoi(cmd[1]);
			free(input);
			free(cmd);
			exit(status);
		}
	}
}

/**
 * change_dir - change directory
 * @cmd: command
 * @er: exit status of the last command executed.
 * Return: 0 on success, 1 on failure.
 */
int change_dir(char **cmd, __attribute__((unused))int er)
{
	int value = -1;
	char cwd[PATH_MAX];

	if (cmd[1] == NULL || _strcmp(cmd[1], ".") == 0)
		value = chdir(getenv("HOME"));
	else if (_strcmp(cmd[1], "-") == 0)
	{
		value = chdir(getenv("OLDPWD"));
	}
	else
		value = chdir(cmd[1]);

	if (value == -1)
	{
		perror("hsh");
		return (-1);
	}
	else
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	return (0);
}
/**
 * print_env - display environment variables
 * @cmd:Parsed Command
 * @x:status of Last command executed
 * Return:Always 0
 */
int print_env(__attribute__((unused))char **cmd, __attribute__((unused))int x)
{
size_t i;
	int len;

	for (i = 0; environ[i] != NULL; i++)
	{
		len = _strlen(environ[i]);
		write(1, environ[i], len);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}
/**
 * print_help - Displaying Help For Builtin
 * @cmd:Parsed Command
 * @er: status of the last command executed
 * Return: 0 on success, on -1 failure.
 */
int print_help(char **cmd, __attribute__((unused))int er)
{
	int fd, fw, rd = 1;
	char c;

	fd = open(cmd[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		return (0);
	}
	while (rd > 0)
	{
		rd = read(fd, &c, 1);
		fw = write(STDOUT_FILENO, &c, rd);
		if (fw < 0)
		{
			return (-1);
		}
	}
	_putchar('\n');
	return (0);
}
/**
 * echo_call - execute echo command
 * @st: status of the last command executed
 * @cmd: Parsed Command
 * Return: 0 or 1
 */
int echo_call(char **cmd, int st)
{
	char *path;
	unsigned int  pid = getppid();

	if (_strncmp(cmd[1], "$?", 2) == 0)
	{
		print_int(st);
		PRINT("\n");
	}
	else if (_strncmp(cmd[1], "$$", 2) == 0)
	{
		print_pos_number(pid);
		PRINT("\n");

	}
	else if (_strncmp(cmd[1], "$PATH", 5) == 0)
	{
		path = _getenv("PATH");
		PRINT(path);
		PRINT("\n");
		free(path);

	}
	else
		return (print_echo(cmd));

	return (1);
}
