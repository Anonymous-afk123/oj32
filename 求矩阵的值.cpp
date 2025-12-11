#include <stdio.h>

int main() {
	int M, N;
	scanf("%d %d", &M, &N);

	int matrix[50][50];

	// 读取矩阵
	for (int i = 0; i < M; i++) {

		for (int j = 0; j < N; j++) {

			scanf("%d", &matrix[i][j]);
		}
	}

	// 1. 找最大值和最小值及其位置
	int max_val = matrix[0][0], min_val = matrix[0][0];
	int max_row = 1, max_col = 1, min_row = 1, min_col = 1;

	for (int i = 0; i < M; i++) {

		for (int j = 0; j < N; j++) {

			// 找最大值（只保留第一个）
			if (matrix[i][j] > max_val) {
				max_val = matrix[i][j];
				max_row = i + 1;
				max_col = j + 1;
			}

			// 找最小值（只保留第一个）
			if (matrix[i][j] < min_val) {
				min_val = matrix[i][j];
				min_row = i + 1;
				min_col = j + 1;
			}
		}
	}

	// 2. 找局部极大值
	int local_max_count = 0;
	int local_max_values[2500];  // 最多M*N个，但实际不会超过这么多
	int local_max_rows[2500];
	int local_max_cols[2500];

	// 只检查非边界元素
	for (int i = 1; i < M - 1; i++) {

		for (int j = 1; j < N - 1; j++) {

			int current = matrix[i][j];

			// 检查是否大于上下左右四个元素
			if (current > matrix[i - 1][j] && // 上
			        current > matrix[i + 1][j] && // 下
			        current > matrix[i][j - 1] && // 左
			        current > matrix[i][j + 1]) { // 右

				local_max_values[local_max_count] = current;
				local_max_rows[local_max_count] = i + 1;  // 行号从1开始
				local_max_cols[local_max_count] = j + 1;  // 列号从1开始
				local_max_count++;
			}
		}
	}

	// 3. 输出结果
	// 输出最大值
	printf("Max %d %d %d\n", max_val, max_row, max_col);

	// 输出最小值
	printf("Min %d %d %d\n", min_val, min_row, min_col);

	// 输出局部极大值
	printf("Local Max\n");

	if (local_max_count == 0) {
		printf("None %d %d\n", M, N);
	} else {
		for (int i = 0; i < local_max_count; i++) {

			printf("%d %d %d\n", local_max_values[i], local_max_rows[i], local_max_cols[i]);
		}
	}

	return 0;
}