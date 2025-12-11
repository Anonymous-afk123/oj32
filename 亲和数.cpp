#include <stdio.h>
#include <math.h>

// 计算整数 a 的真约数之和，并统计真约数个数
int factor(int a, int *count) {
	int sum = 1;       // 1 是所有正整数的真约数
	*count = 1;        // 初始化真约数个数

	int sqrt_a = (int)sqrt(a);

	for (int i = 2; i <= sqrt_a; i++) {

		if (a % i == 0) {
			sum += i;
			(*count)++;
			int other = a / i;

			if (other != i) { // 避免完全平方重复计数
				sum += other;
				(*count)++;
			}
		}
	}

	return sum;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	// 输入范围检查
	if (n <= 1 || m <= 1 || n > 10000 || m > 10000) {
		printf("Invalid input\n");
		return 0;
	}

	int count_n = 0, count_m = 0;

	int sum_n = factor(n, &count_n);
	int sum_m = factor(m, &count_m);

	// 判断亲和数（允许 n = m，也就是允许完全数）
	if (sum_n == m && sum_m == n) {
		printf("yes %d %d\n", count_n, count_m);
	} else {
		printf("no %d %d\n", count_n, count_m);
	}

	return 0;
}
