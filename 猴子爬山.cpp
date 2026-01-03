#include <stdio.h>

int main() {
	int n;

	if (scanf("%d", &n) != 1)
		return 0;

	if (n == 1 || n == 2) {
		printf("1\n");
		return 0;
	}

	if (n == 3) {
		printf("2\n");
		return 0;
	}

	long long f[101];

	f[1] = 1;
	f[2] = 1;
	f[3] = 2;

	for (int i = 4; i <= n; i++) {

		f[i] = f[i - 1] + f[i - 3];
	}

	printf("%lld\n", f[n]);

	return 0;
}