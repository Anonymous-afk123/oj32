#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int num[n];

	for (int i = 0; i < n; i++) {

		scanf("%d", &num[i]);
	}

	for (int i = 0; i < n - 1; i++) {

		for (int j = 0; j < n - i - 1; j++) {

			if (num[j] > num[j + 1]) {
				int temp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp;
			}
		}
	}

	int i = 0;

	while (i < n) {
		int current = num[i];
		int cnt = 0;

		// 统计当前数字出现的次数
		while (i < n && num[i] == current) {
			cnt++;
			i++;
		}

		printf("%d:%d\n", current, cnt);
	}

	return 0;
}