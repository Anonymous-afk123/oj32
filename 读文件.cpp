#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main() {
	FILE *file_stream = NULL;
	char buffer[256];

	errno_t err = fopen_s(&file_stream, "C:\\Users\\Administrator\\Desktop\\hello.txt", "r");


	if (err != 0 || file_stream == NULL) {
		perror("Error opening file");
		return EXIT_FAILURE;
	}

	while (fgets(buffer, sizeof(buffer), file_stream) != NULL) {
		printf("%s", buffer);
	}

	memset(buffer, 0, sizeof(buffer));
	printf("\n");
	rewind(file_stream);
	int ch;

	while ((ch = fgetc(file_stream)) != EOF) {
		putchar(ch);
	}

	if (fclose(file_stream) != 0) {
		perror("Error closing file");
		return EXIT_FAILURE;
	}

	return 0;
}