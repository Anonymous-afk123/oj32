#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *decompress(char *src);

int main() {

	char src[100];
	scanf("%s", src);
	char *ps = decompress(src);
	puts(ps);

	return 0;
}

char *decompress(char *src) {
	static char new_src[1000];
	int i = 0;
	int digit = 0;

	while (src[i] != '\0') {


		if (isalpha(src[i]) && isdigit(src[i + 1])) {
			for (int j = 0; j < src[i + 1] - '0'; j++) {

				new_src[digit++] = src[i];
			}
		} else if (isalpha(src[i])) {
			new_src[digit++] = src[i];
		}

		i++;
	}

	new_src[digit] = '\0';
	return new_src;
}