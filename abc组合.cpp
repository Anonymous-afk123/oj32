#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	for (int a = 1; a <= 9; a++) {

		for (int b = 0; b <= 9; b++) {

			for (int c = 1; c <= 9; c++) {

				if (a * 101 + b * 20 + c * 101 == n) {
					printf("%d %d %d\n", a, b, c);

				}
			}
		}
	}

	return 0;
}