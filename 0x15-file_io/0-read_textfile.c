#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to
 * the POSIX standard output.
 *
 * @filename: The name of the file to read.
 * @letters: The maximum number of letters to read and print.
 *
 * Return: The actual number of letters read and printed,
 * or 0 if there was an error.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;

	char *buffer;

	ssize_t b_read, b_written;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);

	if (fd == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);

	if (buffer == NULL)
	{
		return (0);
	}
	b_read = read(fd, buffer, letters);
	b_written = write(STDOUT_FILENO, buffer, b_read);

	close(fd);
	free(buffer);
	return (b_written);
}

