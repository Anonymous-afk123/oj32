#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
	int W = 10;  // 背包容量
	int weight[] = {2, 3, 4, 5, 9};  // 物品重量
	int value[] = {3, 4, 5, 8, 10};  // 物品价值
	int n = 5;  // 物品数量

	// 创建dp表
	int dp[n + 1][W + 1];

	// 初始化
	for (int i = 0; i <= n; i++) {

		for (int j = 0; j <= W; j++) {

			if (i == 0 || j == 0) {
				dp[i][j] = 0;  // 没有物品或容量为0时，价值为0
			} else if (weight[i - 1] <= j) {
				// 能放下：比较放和不放哪种更优
				dp[i][j] = MAX(dp[i - 1][j],
				               dp[i - 1][j - weight[i - 1]] + value[i - 1]);
			} else {
				// 放不下：只能选择不放
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	printf("最大价值: %d\n", dp[n][W]);

	// 可选：打印dp表查看过程
	printf("\nDP表:\n");

	for (int i = 0; i <= n; i++) {

		for (int j = 0; j <= W; j++) {

			printf("%2d ", dp[i][j]);
		}

		printf("\n");
	}

	return 0;
}