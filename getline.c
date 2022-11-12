#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/types.h>
#include <strings.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

// my_getline() functions read an entire line from a file descriptor, storing the address of the buffer containing the text into *lineptr. The buffer is null-terminated and includes the newline character, if one was found.
// my_getline() function uses a static array of BUFFER_SIZE bytes to store the line. The array is NOT allocated.
// The my_getline() function returns the number of characters read, including the newline character, but not including the terminating null byte ('\0'), or -1 if an error occurred.
// my_getline() should be able to work with multiple file descriptors at the same time.
// my_getline() must not concatenate lines.
int my_getline(char **lineptr, int fd)
{
	static char buffer[1024][BUFFER_SIZE];
	static int buffer_index[1024];
	static int buffer_size[1024];
	int i;

	if (fd < 0 || fd > 1024 || lineptr == NULL)
		return -1;

	if (buffer_size[fd] == 0) {
		buffer_size[fd] = read(fd, buffer[fd], BUFFER_SIZE);
		if (buffer_size[fd] == -1)
			return -1;
		buffer_index[fd] = 0;
	}

	for (i = 0; i < buffer_size[fd]; i++) {
		if (buffer[fd][i] == '\n') {
			*lineptr = malloc(i + 1);
			memcpy(*lineptr, buffer[fd] + buffer_index[fd], i + 1);
			buffer_index[fd] += i + 1;
			return i + 1;
		}
	












	
}

// a main that tests my_getline() opening 2 different files and reading them alternatively 1 line at a time
int main(void)
{
	char *lineptr = NULL;
	int fd1 = open("test1.txt", O_RDONLY);
	int fd2 = open("test2.txt", O_RDONLY);
	int i = 0;

	if (fd1 == -1 || fd2 == -1) {
		return 1;
	}

	for (i = 0; i < 10; i++) {
		my_getline(&lineptr, fd1);
		printf("fd1: %s\n", lineptr);
		free(lineptr);
		lineptr = NULL;
		my_getline(&lineptr, fd2);
		printf("fd2: %s\n", lineptr);
		free(lineptr);
		lineptr = NULL;
	}

	close(fd1);
	close(fd2);

	return 0;
}