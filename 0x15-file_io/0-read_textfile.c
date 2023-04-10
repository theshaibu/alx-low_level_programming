#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

ssize_t read_textfile(const char *filename, size_t letters)
{
    if (filename == NULL) {
        return 0;
    }

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return 0;
    }

    char *buffer = (char*)malloc(sizeof(char) * (letters + 1));
    if (buffer == NULL) {
        fclose(fp);
        return 0;
    }

    ssize_t bytes_read = fread(buffer, sizeof(char), letters, fp);
    buffer[bytes_read] = '\0';

    if (bytes_read <= 0 || fwrite(buffer, sizeof(char), bytes_read, stdout) != bytes_read) {
        free(buffer);
        fclose(fp);
        return 0;
    }

    free(buffer);
    fclose(fp);
    return bytes_read;
}

