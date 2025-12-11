# include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int sales[100];

	for (int i = 0; i < n; i++) {

		scanf("%d", &sales[i]);
	}

	int count = 0;

	for (int i = 1; i < n - 1; i++) {

		int PrevTrend = sales[i] - sales[i - 1];
		int CurrTrend = sales[i + 1] - sales[i];

		if (PrevTrend > 0 ^ CurrTrend > 0) {
			count += 1;
		}
	}

	printf("%d", count);
	return 0;
}
