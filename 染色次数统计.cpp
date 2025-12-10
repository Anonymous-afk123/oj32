#include <stdio.h>
void paint(int, int (*)[4], int *);

int main() {
	int n, l[100][4]; //矩形个数。矩形范围
	int result[300]; //降序   染色次数，相同染色次数的单元格数目
	int i;
	scanf("%d", &n);

	for (i = 0; i < n; i++) {

		scanf("%d%d%d%d", &l[i][0], &l[i][1], &l[i][2], &l[i][3]);
	}

	paint(n, l, result);

	for (i = 0; i <= result[0]; i++) {

		printf("%d %d\n", result[i * 2], result[i * 2 + 1]);
	}

	return 0;
}

void paint(int n, int (*l)[4], int *result) {
	int mat[100][100] = {0};  // 初始化画布
	int max_count = 0;

	// 1. 涂色
	for (int i = 0; i < n; i++) {

		for (int x = l[i][0]; x < l[i][2]; x++) {

			for (int y = l[i][1]; y < l[i][3]; y++) {

				mat[x][y]++;

				if (mat[x][y] > max_count)
					max_count = mat[x][y];  // 更新最大染色次数
			}
		}
	}

	// 2. 初始化 result 数组
	for (int i = 0; i <= max_count; i++) {

		result[i * 2] = max_count - i;   // 染色次数（降序）
		result[i * 2 + 1] = 0;          // 对应的单元格数量
	}

	// 3. 统计每个次数的单元格数量
	for (int x = 0; x < 100; x++) {

		for (int y = 0; y < 100; y++) {

			int c = mat[x][y];
			result[(max_count - c) * 2 + 1]++;  // 位置映射
		}
	}

	// 4. result[0] 存放有多少组
	result[0] = max_count;  // 主函数用 result[0] 控制循环
}