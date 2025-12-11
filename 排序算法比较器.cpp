#include <stdio.h>

int compare(int x, int y);

int main() {
	int a[100] = {0};
	int n, i, j, k;
	scanf("%d", &n);

	for (i = 0; i < n; i++) {

		scanf("%d", &a[i]);
	}

	for (i = 0; i < n; i++) {

		for (k = i, j = i + 1; j < n; j++) {

			if (compare(a[j], a[k]) > 0)
				k = j;
		}

		if (k != i) {
			int t = a[i];
			a[i] = a[k];
			a[k] = t;
		}
	}

	for (i = 0; i < n; i++) {

		printf("%d ", a[i]);
	}

	return 0;
}

int compare(int x, int y) {
	int x_even = (x % 2 == 0);
	int y_even = (y % 2 == 0);

	if (x_even && !y_even)
		return 1;

	if (!x_even && y_even)
		return -1;
	return x - y;
}