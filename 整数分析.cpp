#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	if (n == 0) {
		printf("1 0 0\n");
		return 0;
	}

	int num = n;        // 保存原始数字
	int digits = 0;
	int max_digit = 0;
	int min_digit = 9;

	while (num > 0) {
		int d = num % 10;   // 取最后一位

		if (d > max_digit)
			max_digit = d;

		if (d < min_digit)
			min_digit = d;
		digits++;
		num /= 10;          // 去掉最后一位
	}

	printf("%d %d %d\n", digits, max_digit, min_digit);

	return 0;
}
