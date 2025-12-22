#include <stdio.h>

int main() {
	char str[101];

	if (scanf("%s", str) == EOF)
		return 0;

	char *p = str;

	while (*p != '\0') {
		printf("%c", *p);

		if (*(p + 1) != '\0') {
			printf(" ");
		}

		p++;
	}

	printf("\n");
	return 0;
}