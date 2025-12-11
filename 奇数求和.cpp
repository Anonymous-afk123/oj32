#include <stdio.h>

int main() {
	int num, sum = 0;

	// 循环读取整数，直到遇到0为止
	while (scanf("%d", &num) == 1 && num != 0) {
		// 如果是奇数，则加到总和中
		if (num % 2 != 0) {
			sum += num;
		}
	}

	printf("%d\n", sum);
	return 0;
}