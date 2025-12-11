#include <stdio.h>
void printFactorial(int n);

int main() {
	int n;
	scanf("%d", &n);
	printFactorial(n);
	return 0;
}

void printFactorial(int n) {
	if (n < 0 || n > 1000) {
		printf("Invalid input\n");
		return;
	}

	// 1. 创建足够大的数组来存储大数字（每位存0-9）
	int result[3000] = {0};
	result[0] = 1;  // 从1开始
	int length = 1; // 当前结果有1位数字

	// 2. 计算阶乘：1 × 2 × 3 × ... × n
	for (int i = 2; i <= n; i++) {

		int carry = 0;  // 进位

		// 3. 用当前数字 i 乘以结果的每一位
		for (int j = 0; j < length; j++) {

			int product = result[j] * i + carry;
			result[j] = product % 10;  // 保留个位
			carry = product / 10;      // 进位部分
		}

		// 4. 处理最后的进位
		while (carry > 0) {
			result[length] = carry % 10;
			carry /= 10;
			length++;
		}
	}

	// 5. 倒序输出（高位在前）
	for (int i = length - 1; i >= 0; i--) {

		printf("%d", result[i]);
	}

	printf("\n");
}