#include <stdio.h>

int main(void) {
	int n;
	double height, IdealHeight;
	char sex;
	scanf("%d", &n);

	if (n > 10 || n <= 0) {
		return 0;
	} else {
		for (int i = 0; i < n; i++) {

			scanf(" %c %lf", &sex, &height);

			if (sex == 'M') {
				IdealHeight = height / 1.09;
				printf("%lf\n", IdealHeight);
			} else if (sex == 'F') {
				IdealHeight = height * 1.09;
				printf("%lf\n", IdealHeight);
			} else
				return 0;
		}
	}

	return 0;
}