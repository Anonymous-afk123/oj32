#include <stdio.h>

int main() {
	int m, n;
	scanf("%d %d", &m, &n);

	// 计算鸡的数量
	int chicken = (4 * m - n) / 2;
	// 计算兔子的数量
	int rabbit = m - chicken;

	printf("%d %d\n", chicken, rabbit);

	return 0;
}