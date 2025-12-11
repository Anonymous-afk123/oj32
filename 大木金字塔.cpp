#include <stdio.h>
#include <ctype.h>

int main() {
	printf("Please enter an uppercase letter: ");
	char ch;
	scanf(" %c", &ch);

	if (!isupper(ch)) {
		printf("Not an uppercase letter!\n");
		return 0;
	}

	int rows = ch - 'A' + 1;

	for (int i = 0; i < rows; i++) {

		char letter = 'A';

		for (int s = 0; s < rows - i - 1; s++)

			printf(" ");

		for (int j = 0; j <= i; j++)

			printf("%c", letter++);
		letter -= 2;

		for (int j = 0; j < i; j++) {

			printf("%c", letter--);
		}

		printf("\n");
	}

	return 0;
}