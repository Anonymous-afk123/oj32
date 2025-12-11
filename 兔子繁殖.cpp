#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	if (n <= 2) {
		printf("1\n");
		return 0;
	}

	long long a = 1, b = 1, c;

	for (int i = 3; i <= n; i++) {

		c = a + b;
		a = b;
		b = c;
	}

	printf("%lld\n", b);
	return 0;
}