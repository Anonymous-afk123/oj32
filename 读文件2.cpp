#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void read_config_safe(const char *filename);

int main() {

	const char *filename = "C:\\Users\\Administrator\\Desktop\\hello.log";

	read_config_safe(filename);

	return 0;
}

void read_config_safe(const char *filename) {
	FILE *file_ptr = NULL;
	errno_t err = fopen_s(&file_ptr, filename, "r");

	if (err != 0 || file_ptr == NULL) {
		char error_msg[256];

		strerror_s(error_msg, sizeof(error_msg), errno);

		fprintf(stderr, "FAILED TO OPEN: %s", error_msg);
		exit(EXIT_FAILURE);
	}

	char buffer[256];

	while (fgets(buffer, sizeof(buffer), file_ptr) != NULL) {
		printf("%s", buffer);
	}

	fclose(file_ptr);
}