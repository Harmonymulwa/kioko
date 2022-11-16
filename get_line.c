
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
* _getline - Read The Input By User From Stdin
* Return: Input
*/
char *_getline()
{
int i, rd;
char c = 0;
char *buff = malloc(BUFF_SIZE);

	if (buff == NULL)
	{
		free(buff);
		return (NULL);
	}

	for (i = 0; c != EOF && c != '\n'; i++)
	{
		fflush(stdin);
		rd = read(STDIN_FILENO, &c, 1);
		if (rd == 0)
		{
			free(buff);
			exit(EXIT_SUCCESS);
		}
		buff[i] = c;
		if (buff[0] == '\n')
		{
			free(buff);
			return ("\0");
		}
		if (i >= BUFF_SIZE)
		{
			buff = _realloc(buff, BUFF_SIZE, BUFF_SIZE + 1);
			if (buff == NULL)
			{
				return (NULL);
			}
		}
	}
	buff[i] = '\0';
	handle_comments(buff);
	return (buff);
}

/**
 * handle_comments - remove everything after #
 * @buff: input;
 * Return:void
 */
void handle_comments(char *buff)
{
	int i;

		for (i = 0; buff[i] != '\0'; i++)
		{
			if (buff[i] == '#')
			{
			buff[i] = '\0';
			break;
			}
	}
}
