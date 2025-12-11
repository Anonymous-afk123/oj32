#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);



	// 从最小的质数2开始分解
	for (int i = 2; i <= n; i++) {

		// 当i是n的因子时，不断除以i
		while (n % i == 0) {
			printf("%d", i);
			n /= i;

			// 如果n还没有被完全分解，输出乘号
			if (n != 1) {
				printf("*");
			}
		}
	}

	return 0;
}