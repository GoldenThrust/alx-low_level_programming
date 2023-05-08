#include "main.h"

/**
 * create_file - Creates a new file or overwrites
 * the contents of an existing file.
 *
 * @filename: The name of the file to create or overwrite.
 * @text_content: The text to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	size_t text_len, b_written;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);

	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		text_len = 0;

		while (text_content[text_len] != '\0')
			text_len++;

		b_written = write(fd, text_content, text_len);

		if (b_written == (size_t)-1)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}


