#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

/**
 * append_text_to_file - appends the provided text to the end of a file
 * @filename: the name of the file to append to
 * @text_content: the text to append to the file
 *
 * Return: 1 on success, -1 on failure (if the file does not exist or if the
 * write fails)
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	int num_letters;
	int bytes_written;

	if (!filename)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);

	if (fd == -1)
		return (-1);

	if (text_content)
	{
		for (num_letters = 0; text_content[num_letters]; num_letters++)
			;

		bytes_written = write(fd, text_content, num_letters);

		if (bytes_written == -1)
			return (-1);
	}

	close(fd);

	return (1);
}

