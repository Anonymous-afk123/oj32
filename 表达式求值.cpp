#include <stdio.h>
#include <stdlib.h>

int main() {
	char a[20], b[20], c[20];
	int x, y, res = 0;
	char op;

	// 读取三个部分
	scanf("%s %s %s", a, b, c);

	// 判断哪一个是运算符
	if (a[0] == '+' || a[0] == '-' || a[0] == '*' || a[0] == '/' || a[0] == '%') {
		op = a[0];
		x = atoi(b);
		y = atoi(c);
	} else if (b[0] == '+' || b[0] == '-' || b[0] == '*' || b[0] == '/' || b[0] == '%') {
		op = b[0];
		x = atoi(a);
		y = atoi(c);
	} else { // c是运算符
		op = c[0];
		x = atoi(a);
		y = atoi(b);
	}

	// 计算
	switch (op) {
		case '+':
			res = x + y;
			break;

		case '-':
			res = x - y;
			break;

		case '*':
			res = x * y;
			break;

		case '/':
			res = x / y;
			break;

		case '%':
			res = x % y;
			break;
	}

	printf("%d\n", res);
	return 0;
}
