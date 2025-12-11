#include <stdio.h>

int main() {
	int a, b;
	char c;
	scanf("%d%c%d", &a, &c, &b);

	switch (c) {
		case '+':
			printf("%d%c%d=%d\n", a, c, b, a + b);
			break;

		case '-':
			printf("%d%c%d=%d\n", a, c, b, a - b);
			break;

		case '*':
			printf("%d%c%d=%d\n", a, c, b, a * b);
			break;

		case '/':
			printf("%d%c%d=%d\n", a, c, b, a / b);
			break;

		case '%':
			printf("%d%c%d=%d\n", a, c, b, a % b);
			break;
	}

	return 0;
}