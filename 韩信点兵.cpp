#include <stdio.h>


int main() {
	int num(int n);
	int n;
	scanf("%d", &n);
	printf("%d", num(n));
	return 0;
}

int num(int n) {
	int sum = 0;

	for (int i = 9; i < n; i++) {

		if (i % 3 == 2 && i % 5 == 3 && i % 7 == 2) {

			sum ++;
		}
	}

	return sum;
}