#include "shell.h"

/**
 * main - entry point for the shell program
 * @ac: Argument count 
 * @av: Argument vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av)
{
	info_t info[] = { INFO_INIT };
	int fd = 2;

/* Inline assembly to modify the file descriptor value */
	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fd)
		: "r" (fd));

/* Check if there is a command-line argument */
	if (ac == 2)
	{
/* Open the file specified in the command-line argument */
		fd = open(av[1], O_RDONLY);
/* Handle errors during file opening */
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0: Can't open ");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
/* Update the read file descriptor in the info structure */
		info->readfd = fd;
	}
/* Populate the environment list and read command history */
	populate_env_list(info);
	read_history(info);
/* Execute the shell logic */
	hsh(info, av);

	return (EXIT_SUCCESS);
}

