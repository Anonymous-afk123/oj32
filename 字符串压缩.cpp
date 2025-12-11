#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *compress(char *src);
int main() {

	char src[100];
	scanf("%s", src);
	char *ps = compress(src);
	puts(ps);
	return 0;
}

char *compress (char *src) {
	int len = strlen(src);

	if (len == 0)
		return src;

	char *result = src;
	int write = 0;
	int count = 1;

	for (int i = 1; i <= len; i++) {

		if (i < len && src[i] == src[i - 1]) {
			count++;
		} else {
			if (count < 3) {
				for (int j = 0; j < count; j++) {

					result[write++] = src[i - 1];
				}


			} else {
				result[write++] = src[i - 1];

				// Êý×Ö×ª×Ö·û´®
				char num_str[10];
				sprintf(num_str, "%d", count);

				for (int j = 0; num_str[j] != '\0'; j++) {

					result[write++] = num_str[j];
				}
			}

			count = 1;
		}


	}

	result[write] = '\0';
	return src;
}