#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main() {
	FILE *file_stream = NULL;
	char buffer[256];

	errno_t err = fopen_s(&file_stream, "C:\\Users\\Administrator\\Desktop\\hello.txt", "w");

	if (err != 0 || file_stream == NULL) {
		perror("Error opening file");
		return EXIT_FAILURE;
	}

	fputc('H', file_stream);
	fputc('\n', file_stream);
	fputs("This is a fucking line.\n", file_stream);
	fprintf(file_stream, "Numbers: %d\n", 10);
	fclose(file_stream);
	return 0;
}