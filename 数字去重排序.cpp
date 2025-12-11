#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int appeared[1001] = {0};
	int x;

	for (int i = 0; i < n; i++) {

		scanf("%d", &x);
		appeared[x] = 1;
	}

	int first = 1;

	for (int i = 0; i <= 1000; i++) {

		if (appeared[i]) {
			if (!first)
				printf(" ");
			printf("%d", i);
			first = 0;
		}
	}

	printf("\n");
	return 0;
}
