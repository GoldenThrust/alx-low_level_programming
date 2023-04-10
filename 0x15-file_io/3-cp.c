#include "main.h"

#define BUFFER_SIZE 1024

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
    int from_fd, to_fd, bytes_read, bytes_written;

    char buffer[BUFFER_SIZE];

    if (argc != 3)
    {
        dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
        return (EXIT_FAILURE);
    }

    from_fd = open(argv[1], O_RDONLY);

    if (from_fd == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        return (EXIT_FAILURE);
    }

    to_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);

    if (to_fd == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
        close(from_fd);
        return (EXIT_FAILURE);
    }

    while ((bytes_read = read(from_fd, buffer, BUFFER_SIZE)) > 0)
    {
        bytes_written = write(to_fd, buffer, bytes_read);

        if (bytes_written == -1 || bytes_written != bytes_read)
        {
            dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
            close(from_fd);
            close(to_fd);
            return (EXIT_FAILURE);
        }
    }

    if (bytes_read == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        close(from_fd);
        close(to_fd);
        return (EXIT_FAILURE);
    }

    if (close(from_fd) == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", from_fd);
        close(to_fd);
        return (EXIT_FAILURE);
    }

    if (close(to_fd) == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", to_fd);
        return (EXIT_FAILURE);
    }

    return (EXIT_SUCCESS);
}

