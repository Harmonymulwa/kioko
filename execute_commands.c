#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "main.h"

/**
 * handle_builtin - Handle Builtin Commands
 * @cmd: Parsed Command
 * @ex_status: status of last Execute
 * Return: 0 on success, -1 on failure.
 */
int handle_builtin(char **cmd, int ex_status)
{
	 bul_t bil[] = {
		{"cd",      change_dir},
		{"env",     print_env},
		{"help",    print_help},
		{"echo",    echo_call},
		{"history", print_history},
		{NULL, NULL}
	};
	int i = 0;

	while ((bil + i)->command)
	{
		if (_strcmp(cmd[0], (bil + i)->command) == 0)
		{
			return ((bil + i)->fun(cmd, ex_status));
		}
		i++;
	}
	return (-1);
}
/**
 * check_cmd - execute Simple Shell Command (Fork,Wait,execute)
 *
 * @cmd:Parsed Command
 * @input: User Input
 * @c:Shell Execution Time Case of Command Not Found
 * @argv:Program Name
 * Return: 1 Case Command Null -1 Wrong Command 0 Command executed
 */
int check_cmd(char **cmd, char *input, int c, char **argv)
{
	int status;
	pid_t pid;

	if (*cmd == NULL)
	{
		return (-1);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}

	if (pid == 0)
	{
		if (_strncmp(*cmd, "./", 2) != 0 && _strncmp(*cmd, "/", 1) != 0)
		{
			path_cmd(cmd);
		}

		if (execve(*cmd, cmd, environ) == -1)
		{
			print_error(cmd[0], c, argv);
			free(input);
			free(cmd);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	wait(&status);
	return (0);
}
/**
 * signal_to_handel - Handle ctrl-C
 * @sig:Captured Signal
 * Return: Void
 */
void signal_to_handel(int sig)
{
	if (sig == SIGINT)
	{
		PRINT("\n$ ");
	}
}
