#include <stdio.h>
#include <string.h>

int main() {
	int n;
	scanf("%d", &n);
	char num[20];
	sprintf(num, "%d", n);

	if (n <= 0 || n >= 1000000000) {
		return 0;
	}

	int len = strlen(num);

	for (int i = 0; i < len - 1; i++) {

		for (int j = 0; j < len - 1 - i; j++) {

			if (num[j] < num[j + 1]) {
				char tmp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = tmp;
			}
		}
	}

	for (int i = 0; i < len; i++) {

		printf("%d ", num[i] - '0');
	}

	return 0;
}