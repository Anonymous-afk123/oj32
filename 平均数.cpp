#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	long long sum = 0;
	int num;

	for (int i = 0; i < n; i++) {

		scanf("%d", &num);
		sum += num;
	}

	double average = (double)sum / n;
	printf("%.2f\n", average);

	return 0;
}