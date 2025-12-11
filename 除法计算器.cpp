#include <stdio.h>

int main() {
	int m, n, q, r;
	scanf("%d %d %d %d", &m, &n, &q, &r);

	if (q * n + r == m) {

		printf("yes");
	} else {

		q = m / n;
		r = m % n;
		printf("%d %d", q, r);
	}

	return 0;
}