#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	int grid[101][101] = {0};
	int TotalArea = 0;

	for (int i = 0; i < n; i++) {

		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		// j遍历x坐标，k遍历y坐标
		for (int j = x1; j < x2; j++) {

			for (int k = y1; k < y2; k++) {

				// 注意：这里应该是 grid[j][k]，不是 grid[i][j]
				if (grid[j][k] == 0) {
					grid[j][k] = 1;
					TotalArea++;
				}
			}
		}
	}

	printf("%d\n", TotalArea);
	return 0;
}