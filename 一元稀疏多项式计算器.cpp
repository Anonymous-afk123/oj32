#include <stdio.h>

typedef struct {
	int coef;
	int exp;
} Term;

int main() {
	int n, m, t;

	if (scanf("%d %d %d", &n, &m, &t) != 3)
		return 0;

	Term poly1[1005], poly2[1005], result[2010];

	for (int i = 0; i < n; i++) {

		scanf("%d %d", &poly1[i].coef, &poly1[i].exp);
	}

	for (int i = 0; i < m; i++) {

		scanf("%d %d", &poly2[i].coef, &poly2[i].exp);

		if (t == 1)
			poly2[i].coef = -poly2[i].coef;
	}

	int i = 0, j = 0, k = 0;

	while (i < n && j < m) {
		if (poly1[i].exp == poly2[j].exp) {
			int new_coef = poly1[i].coef + poly2[j].coef; // 修复了这里的非法空格

			if (new_coef != 0) {
				result[k].coef = new_coef;
				result[k].exp = poly1[i].exp;
				k++;
			}

			i++;
			j++;
		} else if (poly1[i].exp < poly2[j].exp) {
			result[k++] = poly1[i++];
		} else {
			result[k++] = poly2[j++];
		}
	}

	while (i < n)
		result[k++] = poly1[i++];

	while (j < m)
		result[k++] = poly2[j++];

	if (k == 0) {
		printf("0\n");
		return 0;
	}

	int first = 1;

	for (int p = 0; p < k; p++) {

		int c = result[p].coef;
		int e = result[p].exp;

		// 1. 处理符号 (+ 或 -)
		if (c > 0 && !first)
			printf("+");

		if (c < 0)
			printf("-"); // 负数直接打印负号

		// 2. 处理系数绝对值
		int abs_c = (c > 0) ? c : -c;

		// 规则：指数不为0且绝对值为1时，不打印数字部分
		if (!(e != 0 && abs_c == 1)) {
			printf("%d", abs_c);
		}

		// 3. 处理变量 x 和 指数
		if (e != 0) {
			printf("x");

			if (e != 1) {
				printf("^%d", e);
			}
		}

		first = 0;
	}

	printf("\n");

	return 0;
}