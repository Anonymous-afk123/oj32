#include <stdio.h>
#include <math.h>

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 2; i <= n / 2; i++) {

		int flag1 = 1;  // 假设 i 是素数
		int flag2 = 1;  // 假设 n - i 是素数

		// 检查 i 是否是素数
		for (int j = 2; j <= sqrt(i); j++) {

			if (i % j == 0) {
				flag1 = 0; // 不是素数
				break;
			}
		}

		// 检查 n - i 是否是素数
		int k = n - i;

		for (int j = 2; j <= sqrt(k); j++) {

			if (k % j == 0) {
				flag2 = 0;
				break;
			}
		}

		// 如果两边都是素数
		if (flag1 && flag2) {
			printf("%d %d\n", i, n - i);
			break; // 只要最小那一组就够
		}
	}

	return 0;
}