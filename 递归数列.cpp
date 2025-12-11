#include <stdio.h>
double function(int n);

int main() {
	int n;
	scanf("%d", &n);
	printf("%f\n", function(n));
	return 0;
}

double function(int n) {
	if (n == 1) {
		return 1;
	} else {
		return 1 / (1 + function(n - 1));
	}
}