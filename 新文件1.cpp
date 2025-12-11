#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	scanf("%d", &n);

	int *group = (int *)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {

		scanf("%d", &group[i]);
	}

	int min_diff = 1000000;

	for (int i = 0; i < n; i++) {

		for (int j = i + 1; j < n; j++) {

			int diff = abs(group[i] - group[j]);

			if (diff < min_diff) {
				min_diff = diff;
			}
		}
	}

	printf("%d", min_diff);
	return 0;
}