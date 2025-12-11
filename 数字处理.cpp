#include <stdio.h>

int digitalRoot(int n) {
	if (n < 10) {
		return n;
	}

	int sum = 0;

	while (n > 0) {
		sum += n % 10;
		n /= 10;
	}

	return digitalRoot(sum);
}

int main() {
	int n;
	scanf("%d", &n);

	if (n <= 0 || n > 1000000000) {
		return 1; // 输入错误返回非零值
	}

	printf("%d\n", digitalRoot(n));
	return 0;
}