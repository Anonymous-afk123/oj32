#include <stdio.h>

int main() {
	int m;
	int matrix[20][20];  // 最大20x20的矩阵
	int sums[50];        // 存储所有和值的数组

	// 读入m和矩阵
	scanf("%d", &m);

	for (int i = 0; i < m; i++) {

		for (int j = 0; j < m; j++) {

			scanf("%d", &matrix[i][j]);
		}
	}

	int count = 0;  // 记录当前有多少个和值

	// 1. 计算每一行的和
	for (int i = 0; i < m; i++) {

		int row_sum = 0;

		for (int j = 0; j < m; j++) {

			row_sum += matrix[i][j];
		}

		sums[count] = row_sum;
		count++;
	}

	// 2. 计算每一列的和
	for (int j = 0; j < m; j++) {

		int col_sum = 0;

		for (int i = 0; i < m; i++) {

			col_sum += matrix[i][j];
		}

		sums[count] = col_sum;
		count++;
	}

	// 3. 计算主对角线的和（从左上到右下）
	int main_diag = 0;

	for (int i = 0; i < m; i++) {

		main_diag += matrix[i][i];
	}

	sums[count] = main_diag;
	count++;

	// 4. 计算辅对角线的和（从右上到左下）
	int anti_diag = 0;

	for (int i = 0; i < m; i++) {

		anti_diag += matrix[i][m - 1 - i];
	}

	sums[count] = anti_diag;
	count++;

	// 冒泡排序：从大到小
	for (int i = 0; i < count - 1; i++) {

		for (int j = 0; j < count - 1 - i; j++) {

			if (sums[j] < sums[j + 1]) {
				// 交换
				int temp = sums[j];
				sums[j] = sums[j + 1];
				sums[j + 1] = temp;
			}
		}
	}

	// 输出结果
	for (int i = 0; i < count; i++) {

		printf("%d ", sums[i]);
	}

	printf("\n");

	return 0;
}