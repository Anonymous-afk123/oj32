#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int N;
	scanf("%d", &N);

	int num[N];

	for (int i = 0; i < N; i++) {

		scanf("%d", &num[i]);
	}

	for (int i = 0; i < N; i++) {

		for ( int j = 0; j < N - 1 - i; j ++) {

			int swap = 0;

			if (num[j] % 2 == 0 && num[j + 1] % 2 != 0) {
				swap = 1;
			} else if (num[j] % 2 == num[j + 1] % 2 && num[j] > num[j + 1]) {
				swap = 1;
			}

			if (swap) {
				int temp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < N; i++) {


		printf("%d", num[i]);

		if (i != N - 1)
			printf(" ");
	}

	printf("\n");

	return 0;
}