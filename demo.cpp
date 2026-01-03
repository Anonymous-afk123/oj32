#include <stdio.h>
#include <stdlib.h>

void demo();

int main() {


	demo();

	return 0;
}

void demo() {
	int *dynamic_arr = (int *)malloc(5 * sizeof(int));

	if (dynamic_arr == NULL) {
		perror("lose");
		exit(EXIT_FAILURE);
	}

	for (size_t i = 0; i < 5; i++) {

		dynamic_arr[i] = (i + 1) * 10;
	}

	for (size_t i = 0; i < 5; i++) {

		printf("%d ", dynamic_arr[i]);
	}

	free(dynamic_arr);
}