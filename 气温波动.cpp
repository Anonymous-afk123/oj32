#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	int temp[30];  // 最多30天

	for (int i = 0; i < n; i++) {

		scanf("%d", &temp[i]);
	}

	int max_diff = 0;  // 最大波动

	for (int i = 1; i < n; i++) {

		int diff = temp[i] - temp[i - 1];

		if (diff < 0)
			diff = -diff;  // 取绝对值

		if (diff > max_diff) {
			max_diff = diff;  // 更新最大波动
		}
	}

	printf("%d\n", max_diff);
	return 0;
}
