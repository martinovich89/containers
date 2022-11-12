#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/types.h>
#include <strings.h>
#include <bsd/string.h>

// my_strlcat() functions copy and concatenate strings. my_strlcat() take the full size of the buffer and guarantee NUL terminated string.
//Note that a byte for the NUL should be included in size. Also note that my_strlcat() only operate on true “C” strings. This means that for strlcat() to work correctly, src must be NUL terminated.
// The strlcat() function appends the NUL-terminated string src to the en of dst.  It will append at most size - strlen(dst) - 1 bytes, NUL-terminating the result
size_t my_strlcat(char *dst, const char *src, size_t size) {
	size_t dst_len = strlen(dst);
	size_t src_len = strlen(src);
	size_t i;

	if (size <= dst_len) {
		return src_len + size;
	}

	for (i = 0; i < size - dst_len - 1; i++) {
		dst[dst_len + i] = src[i];
	}

	dst[dst_len + i] = '\0';

	return dst_len + src_len;
}

// a main that compares the real strlcat with my_strlcat in every way possible, using 1 different dst for both functions
int main(int argc, char *argv[]) {
	(void)argc;
	(void)argv;

	char dst[100] = "Hello";
	char src[100] = "World";
	char dst2[100] = "Hello";
	char src2[100] = "World";

	printf("dst: %s, src: %s\n", dst, src);
	printf("dst2: %s, src2: %s\n", dst2, src2);

	printf("strlcat: %lu\n", strlcat(dst, src, 100));
	printf("my_strlcat: %lu\n", my_strlcat(dst2, src2, 100));

	printf("dst: %s, src: %s\n", dst, src);
	printf("dst2: %s, src2: %s\n", dst2, src2);


	return 0;
}