#include "main.h"
#include <stdio.h>

/**
 * check_file_errors - checks if files can be opened and handles errors.
 * @src_fd: source file descriptor.
 * @dest_fd: destination file descriptor.
 * @argv: arguments vector.
 *
 * Return: no return.
 */
void check_file_errors(int src_fd, int dest_fd, char *argv[])
{
	if (src_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (dest_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}

/**
 * main - entry point.
 * @argc: number of arguments.
 * @argv: arguments vector.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int src_fd, dest_fd, err_close;
	ssize_t num_chars, num_written;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}

	src_fd = open(argv[1], O_RDONLY);
	dest_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	check_file_errors(src_fd, dest_fd, argv);

	num_chars = 1024;
	while (num_chars == 1024)
	{
		num_chars = read(src_fd, buffer, 1024);
		if (num_chars == -1)
			check_file_errors(-1, 0, argv);
		num_written = write(dest_fd, buffer, num_chars);
		if (num_written == -1)
			check_file_errors(0, -1, argv);
	}

	err_close = close(src_fd);
	if (err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", src_fd);
		exit(100);
	}

	err_close = close(dest_fd);
	if (err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", dest_fd);
		exit(100);
	}
	return (0);
}

