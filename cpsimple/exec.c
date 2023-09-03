#include "main.h"
/**
 * error_non_inter - write error in non-interactive mode
 * @cmdname: commande name
 * @pgmname: programme name
 *
 * Return: nothing
 */
void error_non_inter(char *cmdname, char *pgmname)
{
	write(1, pgmname, _strlen(pgmname));
	write(1, ": 1: ", 5);
	write(1, cmdname, _strlen(cmdname));
	write(1, ": not found\n", 12);
	exit(EXIT_FAILURE);
}
/**
 * exec - executes a command
 * @cmd: command to execute
 * @progname: name of programme
 * @envp: environment
 *
 * Return: -1 (fail), 0 (success)
 **/

int exec(char **cmd, char *progname, char **envp)
{
	char *pathcomm = NULL;
	pid_t pid = 1;
	int status;

	if (!_strchr(cmd[0], '/'))
	{
		pathcomm = _which(cmd[0], progname, envp);
		if (!pathcomm)
			return (-1);
	}
	else
		pathcomm = _strdup(cmd[0]);
	if (pid != 0)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("Error");
		}
		wait(&status);
	}
	if (!pid)
	{
		if (execve(pathcomm, cmd, envp) == -1)
		{
			if (!isatty(STDIN_FILENO))
				error_non_inter(cmd[0], progname);
			else
				perror(cmd[0]);
			free(pathcomm);
			exit(2);
		}
		free(pathcomm);
	}
	free(pathcomm);
	return (0);
}
