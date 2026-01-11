#include <stdio.h>

int main() {
	char s[10];
	scanf("%s", s);

	int sum = 0;

	for (int i = 0; s[i] != '\0'; i++) {

		sum += s[i] - '0';
	}

	while (sum >= 10) {
		int tempSum = 0;

		while (sum != 0) {
			tempSum += sum % 10;
			sum /= 10;
		}

		sum = tempSum;
	}

	printf("%d\n", sum);
	return 0;
}