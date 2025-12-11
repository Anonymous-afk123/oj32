#include <stdio.h>
#include <math.h>

int main() {
	int n, x;
	float y, sum = 0;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {

		x = 2 * i - 1;
		y = pow(-1, i + 1) * i / x;
		sum += y;
	}

	printf("%.3f", sum);
	return 0;


}