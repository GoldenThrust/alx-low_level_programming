#include "main.h"

#define BUFFER_SIZE 1024

int open_file(const char *file_name, int flags, mode_t mode);
int copy_file(int from_fd, int to_fd);

/**
 * main - Copies the content of a file to another file.
 * @argc: The number of arguments.
 * @argv: An array of pointers to the arguments.
 *
 * Return: If successful - 0.
 *         Otherwise - The status code.
 */

int main(int argc, char **argv)
{
	int from_fd, to_fd;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
		exit(97);
	}

	from_fd = open_file(argv[1], O_RDONLY, 0);

	to_fd = open_file(argv[2], O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);

	copy_file(from_fd, to_fd);

	if (close(from_fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", from_fd);
		close(to_fd);
		exit(100);
	}
	if (close(to_fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", to_fd);
		exit(100);
	}
	return (0);
}

/**
 * open_file - Opens a file with the given name and flags.
 * @file_name: The name of the file to open.
 * @flags: The flags to use when opening the file.
 * @mode: The mode to use when creating the file.
 *
 * Return: The file descriptor of the opened file.
 *         Otherwise - The status code.
 */

int open_file(const char *file_name, int flags, mode_t mode)
{
	int fd;

	fd = open(file_name, flags, mode);

	if (fd == -1)
	{
		if (flags & O_RDONLY)
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_name);
		else if (flags & O_WRONLY)
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_name);
		exit(99);
	}

	return (fd);
}

/**
 * copy_file - Copies the content of one file descriptor to another.
 * @from_fd: The file descriptor to read from.
 * @to_fd: The file descriptor to write to.
 *
 * Return: If successful - 0.
 *         Otherwise - The status code.
 */

int copy_file(int from_fd, int to_fd)
{
	int bytes_read, bytes_written;
	char buffer[BUFFER_SIZE];

	while ((bytes_read = read(from_fd, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(to_fd, buffer, bytes_read);

		if (bytes_written == -1 || bytes_written != bytes_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %d\n", to_fd);
			exit(99);
		}
	}
	if (bytes_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %d\n", from_fd);
		exit(98);
	}

	return (0);
}

