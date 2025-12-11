#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
	char s[101];
	scanf("%s", s);
	int n = strlen(s);

	int numbers[100];
	int count = 0;

	for (int i = 0; i < n;) {

		if (isdigit(s[i]) == 0) {
			i++;
			continue;
		}

		int cnt = 0;

		while (isdigit(s[i]) == 1) {
			cnt = 10 * cnt + (s[i] - '0');
			i++;
		}

		numbers[count++] = cnt;

	}

	for (int i = 0; i < count - 1; i++) {

		for (int j = 0; j < count - i - 1; j++) {

			if (numbers[j] < numbers[j + 1]) {
				int temp = numbers[j];
				numbers[j] = numbers[j + 1];
				numbers[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < count; i++) {

		printf("%d", numbers[i]);

		if (i < count - 1) {
			printf(" ");
		} else {
			printf("\n");
		}
	}


	return 0;
}