#include <stdlib.h>
#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c) {
    return (write(1, &c, 1));
}

/**
 * print_pos_number - prints numbers
 * @n: Unsigned Integer
 * Return: Void
 */
void print_pos_number(unsigned int n)
{
	unsigned int x = n;

	if ((x / 10) > 0)
        print_pos_number(x / 10);

	_putchar(x % 10 + '0');
}
/**
 * print_int - Print Numbers
 * @n:Integer
 * Return: void
 */
void print_int(int n)
{
	unsigned int x = n;

	if (n < 0)
	{
		_putchar('-');
		x = -x;
	}
	if ((x / 10) > 0)
        print_pos_number(x / 10);

	_putchar(x % 10 + '0');
}

/**
 * print_error - Display Error Based on Command and How Many Time Shell Looped
 * @input:User Input
 * @counter:Simple Shell Count Loop
 * @argv:Program Name
 * Return: Void
 */
void print_error(char *input, int counter, char **argv)
{
    char *er;

    PRINT(argv[0]);
    PRINT(": ");
    er = _itoa(counter);
    PRINT(er);
    free(er);
    PRINT(": ");
    PRINT(input);
    PRINT(": not found\n");
}

/**
 *  custom_error - Print Custom Error
 * @argv: Program Name
 * @c: Error Count
 * @cmd: Command
 * Return: Void
 */
void custom_error(char **argv, int c, char **cmd)
{
    char *er = _itoa(c);

    PRINT(argv[0]);
    PRINT(": ");
    PRINT(er);
    PRINT(": ");
    PRINT(cmd[0]);
    PRINT(": Illegal number: ");
    PRINT(cmd[1]);
    PRINT("\n");
    free(er);
}
