#include "main.h"


int cp(int from_fd, int to_fd, char **argv);

/**
 * main - Copies the content of a file to another file.
 * @argc: The number of arguments.
 * @argv: An array of pointers to the arguments.
 *
 * Return: If successful - 0.
 * Otherwise - The status code.
 */

int main(int argc, char **argv)
{
	int from_fd, to_fd;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	from_fd = open(argv[1], O_RDONLY);
	if (from_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	to_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC,
				 S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (to_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close(from_fd);
		exit(99);
	}
	cp(from_fd, to_fd, argv);
	if (close(from_fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", from_fd);
		close(to_fd);
		exit(100);
	}
	if (close(to_fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", to_fd);
		close(from_fd);
		exit(100);
	}

	return (0);
}

/**
 * cp - Copies the content of a from_fd to to_fd.
 * @from_fd: open file
 * @to_fd: open file
 * @argv: An array of pointers to the arguments.
 * Return: Return: If successful - 0.
 * Otherwise - The status code.
 */
int cp(int from_fd, int to_fd, char **argv)
{
	int b_read, b_written;
	char buffer[1024];

	while ((b_read = read(from_fd, buffer, 1024)) > 0)
	{
		b_written = write(to_fd, buffer, b_read);
		if (b_written == -1 || b_written != b_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			close(from_fd);
			close(to_fd);
			exit(99);
		}
	}
	if (b_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		close(from_fd);
		close(to_fd);
		exit(98);
	}

	return (0);
}

