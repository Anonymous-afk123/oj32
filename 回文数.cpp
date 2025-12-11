#include <stdio.h>

int main(void) {
	int n, original, sum = 0, reversed = 0;
	scanf("%d", &n);
	original = n;

	if (n < 0 || n >= 1000000000) {
		return 0;
	}

	while (n != 0) {
		int digit = n % 10;
		sum += digit;
		reversed = reversed * 10 + digit;
		n /= 10;
	}

	if (original == reversed) {
		printf("%d", sum);
	} else {
		printf("no");
	}

	return 0;
}
