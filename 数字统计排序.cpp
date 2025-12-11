#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	int count[1001] = {0};

	for (int i = 0; i < n; i++) {

		int x;
		scanf("%d", &x);
		count[x]++;
	}

	int max_count = 0;

	for (int i = 0; i <= 1000; i++) {

		if (count[i] > max_count)
			max_count = count[i];
	}

	for (int k = max_count; k > 0; k--) {

		for (int i = 0; i <= 1000; i++) {

			if (count[i] == k) {
				printf("%d %d\n", i, count[i]);
			}
		}
	}

	return 0;
}
