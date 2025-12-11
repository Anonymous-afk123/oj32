#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n) {
	if (n < 2)
		return false;

	if (n == 2)
		return true;

	if (n % 2 == 0)
		return false;

	for (int i = 3; i * i <= n; i += 2) {

		if (n % i == 0)
			return false;
	}

	return true;
}


int main() {
	int a, b;
	scanf("%d %d", &a, &b);

	// 确保a <= b
	if (a > b) {
		int temp = a;
		a = b;
		b = temp;
	}

	int count = 0;    // 当前质数计数
	int num = 2;      // 当前检查的数
	int sum = 0;      // 总和

	// 遍历所有数，找到质数
	while (count < b) {
		if (isPrime(num)) {
			count++;  // 找到第count个质数

			// 如果当前质数序号在[a,b]范围内，累加到总和
			if (count >= a) {
				sum += num;
			}
		}

		num++;
	}

	printf("%d\n", sum);
	return 0;
}