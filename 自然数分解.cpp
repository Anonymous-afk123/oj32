# include <stdio.h>

int main() {
	int n, cube;
	scanf("%d", &n);
	cube = n * n * n;
	int num1 = (n - 1) * n + 1;
	int num2 = (1 + n) * n - 1;

	for (int i = num1; i <= num2; i += 2) {

		printf("%d\ ", i);
	}

	return 0;
}
